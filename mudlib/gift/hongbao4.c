#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "���ֺ��" NOR, ({ "hong bao" }) );
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
        me = this_player();
        if(arg != "hong bao" && arg != "���ֺ��") return 0;
        if(me->query("marks/opend"))
        	return notify_fail("���Ѿ���������ˡ�\n");
        if(query("opened"))
                return notify_fail("���С������������ǿյģ�\n");
        gold = new("/obj/money/gold");
        gold->set_amount(666);
        gold->set("name","����Ҷ��");
        gold->set("base_unit","��");
        gold->move(this_player());
        me->set("combat_exp",750000);
        me->add("potential",140000);
        me->add("score",2005);
        me->set("int",30);
        message_vision(HIR "\n$N���Ĵ򿪺�������۷��⣬һ����ϲ��\n\n" NOR,me);
        tell_object(me,HIC"\n��ϲ��ϲ���㱻�����ˣ�\n" + chinese_number(750000) + "��ʵս����\n" + chinese_number(140000) + "��Ǳ��\n" + chinese_number(2005)+"���ۺ�����,������ʮ�����ƽ�\n"NOR);
        set("opened",1);
        me->set("marks/opend",1);
        me->save();
        return 1;
}
