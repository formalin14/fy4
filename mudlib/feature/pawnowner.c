 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
// pawnowner.c
#define MAX_PAWN 9
#include <dbase.h>
#include <ansi.h>
string value_string(int value)
{
        if( value < 1 ) value = 1;
        else if( value < 100 )
                return chinese_number(value) + "��Ǯ";
        else
                return chinese_number(value/100) + "��"
                        + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
} 
void pay_player(object who, int amount) 
{
        object ob; 
        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
} 
int do_value(string arg)
{
        object ob;
        int value;
        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("��Ҫ��ʲ����Ʒ�����̹��ۣ�\n");
        if (ob->query("thief_obj"))
        {
                if (!random(3)) {
                        call_out("arresthim",3,this_player());
                        return notify_fail("��о��е㲻�Ծ���������˵��������\n");
                }
        }
        if( ob->query("money_id") )
                return notify_fail("���ǡ�Ǯ������û������\n"); 
        value = ob->query("value");
        if( !value || value < 4) printf("%s����ֵ����Ǯ��\n", ob->query("name"));
        else 
                printf("%s��ֵ%s��\n�����Ҫ�䵱(pawn)�������õ�%s��\n�������(sell)�������õ�%s��\n",
                        ob->query("name"), value_string(value),
                        value_string(value * 25 / 100), value_string(value * 80 / 100)); 
        return 1;
} 
int do_pawn(string arg)
{
        string outstring="";
        object ob;
        string term,*terms, *vterms, *fterms;
        string data, p_c;
        int value, pawn_count=0, i,j;
   int rvalue;
        mapping pawn,vpawn,fpawn;
        object me;
        me = this_player();
        pawn = me->query_pawn();
        vpawn = me->query_vpawn();
        fpawn = me->query_fpawn(); 
        if( !arg || !(ob = present(arg, this_player())) )
        {
        write("��Ŀǰ�䵱����Ʒ�У�\n");
        if( !mapp(pawn) ||   !sizeof(pawn) )
                write("\tû���κε䵱����Ʒ��\n");
        else {
                        terms = keys(pawn);
                        vterms = keys(vpawn);
                        for(i=0; i<sizeof(terms); i++)
                outstring =sprintf("%s%-3s��  %-15s  ������%s\n", outstring, terms[i], pawn[terms[i]],
                        value_string(vpawn[vterms[i]]));
        this_player()->start_more("", outstring, 0);
              }
        return 1;
        }
        if (ob->query("thief_obj"))
        {
                if (!random(3)) {
                        call_out("arresthim",3,this_player());
                        return notify_fail("��о��е㲻�Ծ���������˵��������\n");
                }
        }
        if( ob->query("money_id") )     return notify_fail("��Ҫ����Ǯ����\n");
        if (ob->query("no_pawn"))
        {
                return notify_fail("�㲻���Ե�����������\n");
        }
        
        value = ob->query("value");
        if( !(value/4) ) return notify_fail("������������ֵ�ܶ�Ǯ��\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                   vterms = keys(vpawn);
                        if(sizeof(vterms) > MAX_PAWN)
                        return notify_fail("���ѵ䵱̫����Ʒ�ˡ�\n");
                }
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ����ܵ䵱��Ʒ��\n");
// to make life more realistic
        if( ((int)this_object()->query("richness")) < (value*25/100))
                return notify_fail(sprintf("%s����Ǯ�Ѿ������ˣ�����\n",this_object()->name()));
        this_object()->add("richness",-(value*25/100));
        term = ob->query("name");
        data = base_name(ob)+ ".c";
        p_c = sprintf("%d",time()%10000);
        me->set_pawn(p_c, term);
        me->set_vpawn(p_c, value);
        me->set_fpawn(p_c, data); 
        me->save();
        message_vision("$N�����ϵ�" + ob->query("name") + "�ó����䵱��"
                + value_string(value * 25 / 100) + "��\n", this_player()); 
        pay_player(this_player(), value * 25 / 100 );
        ob->move(VOID_OB);
        destruct(ob);
        me->start_busy(1);
        return 1;
} 
int do_sell(string arg)
{
        object ob;
        int value,old;
        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("��Ҫ����ʲ����Ʒ��\n");
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ���������Ʒ��\n");
        if (ob->query("thief_obj"))
        {
                if (!random(3)) {
                        call_out("arresthim",3,this_player());
                        return notify_fail("��о��е㲻�Ծ���������˵��������\n");
                }
        }
   if( ob->query("money_id") )     return notify_fail("��Ҫ����Ǯ����\n");
        value = ob->query("value");
        
        if( value<4) {
                tell_object(this_player(), "������������ֵ�ܶ�Ǯ��\n");         
                //notify_fail("������������ֵ�ܶ�Ǯ��\n");
                 return 1;
        }
        if (ob->query("no_sell"))
        {
                tell_object(this_player(), "�㲻����������������\n");
                return 1; 
//              return notify_fail("�㲻����������������\n");
        }
// to make life more realistic
        if( ((int)this_object()->query("richness")) < (value*80/100))
                return notify_fail(sprintf("%s����Ǯ�Ѿ������ˣ�����\n",this_object()->name()));
        this_object()->add("richness",-(value*80/100));  
        message_vision("$N�����ϵ�" + ob->query("name") + "������\n",
                this_player());
        old = this_object()->query_with_slash("vendor_goods."+base_name(ob));
        this_object()->set_with_slash("vendor_goods."+base_name(ob), old+1);
        pay_player(this_player(), value  * 80 / 100);
        ob->move(VOID_OB);
        destruct(ob);
        this_player()->start_busy(1);
        return 1;
}
void pay_him(object who, int amount) 
{
        object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
        if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);  
        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
} 
int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin; 
        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me); 
        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value(); 
        if( total < amount ) return 0; 
        return total;
}
int do_redeem(string arg)
{
        string num;
        int amount;
        string ob_file;
        object ob;
        int obnum;
        object me;
        string term, *terms;
        mapping pawn,vpawn,fpawn;
        int afford;
        if( !arg || sscanf(arg, "%s", num)!=1 )
                return notify_fail("ָ���ʽ��redeem <��Ʒ���>\n");
        me = this_player();
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ���������Ʒ��\n");
        pawn = me->query_pawn();
        vpawn=me->query_vpawn();
        fpawn=me->query_fpawn();
        terms = keys(vpawn);
        amount = (int) vpawn[arg];
        if( !amount )
                return notify_fail("�������Ʒ�����\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                
                ob_file = fpawn[arg];
                ob = new(ob_file);
//                ob->set_amount(1);
// changed by karry 2002.5.13  �����������
                ob->query("base_unit")?((amount*100/75)/ob->query("base_value")<1?obnum=1:obnum=(amount*100/75)/ob->query("base_value")):obnum=1;
                ob->set_amount(obnum);
                if (ob->move(me)) {
                        me->delete_pawn(arg);
                        me->delete_vpawn(arg);
                        me->delete_fpawn(arg);
        // to make life more realistic
                        this_object()->add("richness",amount);
                        pay_him(me, afford-amount);
                        me->save();
                        message_vision("$N�����$n��\n", me, ob);
                        return 1;
                }
                else  {
                        destruct(ob);
                        return notify_fail("����û�취�������\n");
                }
                
        } else
                return notify_fail("���Ǯ������\n");
        me->start_busy(1); 
} 
void arresthim(object me)
{
        object bukuai1,bukuai2,*inv;
        object npc;
        npc = this_object();
        if (objectp(me) && present(me,environment(npc)))
        {
                message_vision("$NͻȻ��Ц���������ǶԲ�����λ"+RANK_D->query_respect(me)+"�ˣ����Ķ����ٲ���Ҫ��顣��\n\n", npc);
                bukuai1 = new("/d/fy/npc/bukuai");
                bukuai2 = new("/d/fy/npc/bukuai");
                bukuai1->move(environment(me));
                bukuai2->move(environment(me));
                message_vision(HIR"�������������������$N��Ц����������þ��ˣ���ү����һ�˰ɡ���\n\n"NOR, me);
                tell_object(me,"�����д������ɺ����̫�١�\n");
                message_vision("$n��$N��Ц����������������׷��С͵�Ѿ��ܾ��ˣ��ԹԸ������߰ɣ��� \n",me,bukuai1);
                message_vision("$n��$NѺ����Ρ� \n",me,bukuai1);
                destruct(bukuai1);
           destruct(bukuai2);
                me->set("vendetta/authority", 1);
                me->move("/d/jinan/laofang1");
                message_vision(HIY"$N���ѿ����еĶ�����һ���߽����η���\n"NOR,me);
                inv = all_inventory(me);
                for(int i=0; i<sizeof(inv); i++) 
                {
                        destruct(inv[i]);
                }
        }
        return;
}  