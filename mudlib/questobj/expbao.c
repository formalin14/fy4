#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIM "�������" NOR, ({ "exp bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ����˲����������Ľ��ҡ�\n");
        

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
        if(arg != "exp bao" && arg != "�������") return 0;
        if(query("opened"))
                return notify_fail("���С������������ǿյģ�\n");
        //gold = new("/obj/money/gold");
        //gold->set_amount(666);
        //gold->set("name","����Ҷ��");
        //gold->set("base_unit","��");
        //gold->move(this_player());
        me->add("combat_exp",543210);
        //me->add("potential",3333);
        //me->add("score",222);
        tell_object(me,"\n��ϲ��ϲ���㱻�����ˣ�\n" + chinese_number(543210) + "��ʵս����\n" );
        set("opened",1);
        return 1;//notify_fail(HIR "\n�����Ĵ򿪺�������۷��⣬һ����ϲ��\n\n" NOR);
}
