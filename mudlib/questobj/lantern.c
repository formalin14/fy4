#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIR"太平灯笼"NOR, ({ "lantern"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "cloth");
                set("long", "这是郝生意请巧匠专做的太平灯笼，狼山虽说地远风急，但这灯笼却从不\n熄灭，端是精巧。 \n");
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
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
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
        tell_object(this_player(),"你掏出一个" + this_object()->name() + "点亮了灯芯。\n");
        environment(this_player())->light_notify(this_object(), 0);
        return 1;
}      
