#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG "Ǳ�ܽ���" NOR, ({ "pot bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ���ܽ������ص�Ǳ���ھ�����Ľ��ҡ���\n");
        

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
        object gold, me;
        me = this_player();
        if(arg != "pot bao" && arg != "Ǳ�ܽ���") return 0;
        if(query("opened"))
                return notify_fail("���С������������ǿյģ�\n");
        //gold = new("/obj/money/gold");
        //gold->set_amount(666);
        //gold->set("name","����Ҷ��");
        //gold->set("base_unit","��");
        //gold->move(this_player());
       // me->add("combat_exp",500000);
        me->add("potential",123456);
        //me->add("score",222);
        tell_object(me,"\n��ϲ��ϲ���㱻�����ˣ�\n" + chinese_number(123456) + "��Ǳ��\n" );
        set("opened",1);
        return 1;//notify_fail(HIR "\n�����Ĵ򿪺�������۷��⣬һ����ϲ��\n\n" NOR);
}
