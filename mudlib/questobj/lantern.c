#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIR"̫ƽ����"NOR, ({ "lantern"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("long", "���Ǻ��������ɽ�ר����̫ƽ��������ɽ��˵��Զ�缱���������ȴ�Ӳ�\nϨ�𣬶��Ǿ��ɡ� \n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

        }
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
        if(this_player()==environment())
        add_action("do_light", "use");
} 
int do_light(string arg)
{
        if( arg != "lantern" ) return 0;
        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "�����˵�о��\n");
        environment(this_player())->light_notify(this_object(), 0);
        return 1;
}      
