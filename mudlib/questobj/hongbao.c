#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "���" NOR, ({ "hongbao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ��СС�ĺ�����������ţ������ĳ����ơ�\n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

          }
    ::init_item();
} 
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("����������ʬ�������$N�Ļ��У�\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}

void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold;
        if(arg != "hongbao" && arg != "���") return 0;
        if(query("opened"))
                return notify_fail("���С������������ǿյģ�\n");
        gold = new("/obj/money/gold");
        gold->set_amount(30);
        gold->set("name","����Ҷ��");
        gold->set("base_unit","��");
        gold->move(this_player());
        set("opened",1);
        return notify_fail("���С������������ó����Ŵ���Ҷ�ӣ�\n");
}
