#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(MAG"松牌"NOR, ({ "songpai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "stone");
            set("long", "西方神教孤松先生的信物。\n");
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
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}