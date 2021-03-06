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
                return chinese_number(value) + "文钱";
        else
                return chinese_number(value/100) + "两"
                        + (value%100? "又" + chinese_number(value%100) + "文钱": "");
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
                return notify_fail("你要拿什麽物品给当铺估价？\n");
        if (ob->query("thief_obj"))
        {
                if (!random(3)) {
                        call_out("arresthim",3,this_player());
                        return notify_fail("你感觉有点不对劲，但是又说不上来。\n");
                }
        }
        if( ob->query("money_id") )
                return notify_fail("这是「钱」，你没见过吗？\n"); 
        value = ob->query("value");
        if( !value || value < 4) printf("%s并不值几文钱。\n", ob->query("name"));
        else 
                printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
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
        write("你目前典当的物品有：\n");
        if( !mapp(pawn) ||   !sizeof(pawn) )
                write("\t没有任何典当的物品。\n");
        else {
                        terms = keys(pawn);
                        vterms = keys(vpawn);
                        for(i=0; i<sizeof(terms); i++)
                outstring =sprintf("%s%-3s：  %-15s  赎银：%s\n", outstring, terms[i], pawn[terms[i]],
                        value_string(vpawn[vterms[i]]));
        this_player()->start_more("", outstring, 0);
              }
        return 1;
        }
        if (ob->query("thief_obj"))
        {
                if (!random(3)) {
                        call_out("arresthim",3,this_player());
                        return notify_fail("你感觉有点不对劲，但是又说不上来。\n");
                }
        }
        if( ob->query("money_id") )     return notify_fail("你要当「钱」？\n");
        if (ob->query("no_pawn"))
        {
                return notify_fail("你不可以当这样东西。\n");
        }
        
        value = ob->query("value");
        if( !(value/4) ) return notify_fail("这样东西并不值很多钱。\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                   vterms = keys(vpawn);
                        if(sizeof(vterms) > MAX_PAWN)
                        return notify_fail("你已典当太多物品了。\n");
                }
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能典当物品。\n");
// to make life more realistic
        if( ((int)this_object()->query("richness")) < (value*25/100))
                return notify_fail(sprintf("%s的现钱已经不够了．．．\n",this_object()->name()));
        this_object()->add("richness",-(value*25/100));
        term = ob->query("name");
        data = base_name(ob)+ ".c";
        p_c = sprintf("%d",time()%10000);
        me->set_pawn(p_c, term);
        me->set_vpawn(p_c, value);
        me->set_fpawn(p_c, data); 
        me->save();
        message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
                + value_string(value * 25 / 100) + "。\n", this_player()); 
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
                return notify_fail("你要卖断什麽物品？\n");
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能卖物品。\n");
        if (ob->query("thief_obj"))
        {
                if (!random(3)) {
                        call_out("arresthim",3,this_player());
                        return notify_fail("你感觉有点不对劲，但是又说不上来。\n");
                }
        }
   if( ob->query("money_id") )     return notify_fail("你要卖「钱」？\n");
        value = ob->query("value");
        
        if( value<4) {
                tell_object(this_player(), "这样东西并不值很多钱。\n");         
                //notify_fail("这样东西并不值很多钱。\n");
                 return 1;
        }
        if (ob->query("no_sell"))
        {
                tell_object(this_player(), "你不可以卖这样东西。\n");
                return 1; 
//              return notify_fail("你不可以卖这样东西。\n");
        }
// to make life more realistic
        if( ((int)this_object()->query("richness")) < (value*80/100))
                return notify_fail(sprintf("%s的现钱已经不够了．．．\n",this_object()->name()));
        this_object()->add("richness",-(value*80/100));  
        message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
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
                return notify_fail("指令格式：redeem <物品标号>\n");
        me = this_player();
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能赎物品。\n");
        pawn = me->query_pawn();
        vpawn=me->query_vpawn();
        fpawn=me->query_fpawn();
        terms = keys(vpawn);
        amount = (int) vpawn[arg];
        if( !amount )
                return notify_fail("有这个物品标号吗？\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                
                ob_file = fpawn[arg];
                ob = new(ob_file);
//                ob->set_amount(1);
// changed by karry 2002.5.13  当多少赎多少
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
                        message_vision("$N赎回了$n。\n", me, ob);
                        return 1;
                }
                else  {
                        destruct(ob);
                        return notify_fail("现在没办法赎回来。\n");
                }
                
        } else
                return notify_fail("你的钱不够。\n");
        me->start_busy(1); 
} 
void arresthim(object me)
{
        object bukuai1,bukuai2,*inv;
        object npc;
        npc = this_object();
        if (objectp(me) && present(me,environment(npc)))
        {
                message_vision("$N突然冷笑道：“真是对不起这位"+RANK_D->query_respect(me)+"了，您的东西官差们要检查。”\n\n", npc);
                bukuai1 = new("/d/fy/npc/bukuai");
                bukuai2 = new("/d/fy/npc/bukuai");
                bukuai1->move(environment(me));
                bukuai2->move(environment(me));
                message_vision(HIR"暗中跳出来几个捕快对$N冷笑道：“等你好久了，跟爷们走一趟吧。”\n\n"NOR, me);
                tell_object(me,"你心中大呼不妙，可后悔已太迟。\n");
                message_vision("$n对$N冷笑道：“我们在这里追捕小偷已经很久了，乖乖跟我们走吧！” \n",me,bukuai1);
                message_vision("$n将$N押向大牢。 \n",me,bukuai1);
                destruct(bukuai1);
           destruct(bukuai2);
                me->set("vendetta/authority", 1);
                me->move("/d/jinan/laofang1");
                message_vision(HIY"$N被搜空所有的东西，一脚踢进了牢房！\n"NOR,me);
                inv = all_inventory(me);
                for(int i=0; i<sizeof(inv); i++) 
                {
                        destruct(inv[i]);
                }
        }
        return;
}  
