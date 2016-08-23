#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "�´����" NOR, ({ "hong bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ��СС�ĺ�����������ţ���ϲ���ơ�\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, me,ob;
        int max_gin,max_kee,max_sen;
        int n;
        string msg;
        msg = "";
        me = this_player();
        max_gin = (int) me->query("max_gin");
        max_kee = (int) me->query("max_kee");
        max_sen = (int) me->query("max_sen");
        if(arg != "hong bao" && arg != "�´����") return 0;
        if(me->query("marks/open_hongbao"))
        	return notify_fail("���Ѿ��������ˣ�\n");
        if(query("opened"))
                return notify_fail("���С������������ǿյģ�\n");
                
        if (me->query("combat_exp")>3000000) n=24;
                else if (me->query("combat_exp")>2500000) n=25;
                        else n=26;
        max_gin = max_gin * n/20;
        max_kee = max_kee * n/20;
        max_sen = max_sen * n/20;
        me->set("max_gin", max_gin);
        me->set("max_kee", max_kee);
        me->set("max_sen", max_sen); 
        if( me->query("age") >= 12 && me->query("combat_exp")>= 400000 ){        
        	gold = new("/obj/money/gold");
        	gold->set_amount(200);
        	gold->set("name","ѹ��Ǯ");
        	gold->set("base_unit","��");
        	gold->move(this_player());
        	msg="���õ��˶��������ӵ�ѹ��Ǯ��";
        }
        
        me->add("combat_exp",20000);
        me->add("potential",20000);
        message_vision(HIR "\n$N���Ĵ򿪺�������۷��⣬һ����ϲ��\n\n" NOR,me);
        tell_object(me,HIC"\n��ϲ��ϲ���㱻�����ˣ�\n" + chinese_number(20000) + "��ʵս����\n" + chinese_number(20000) + "��Ǳ�ܡ�"+msg+"\n" NOR);
        message_vision(HIR"ֻ��$Nȫ�����·�����⣬�����й����������ע��$N���ڡ�\n"NOR,me);
        me->set("marks/open_hongbao",1);
        set("opened",1);
        return 1;
}
