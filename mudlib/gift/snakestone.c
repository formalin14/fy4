#include <ansi.h>;
inherit "/std/item/jade"; 
void create()
{
        set_name(HIG"蛇王之魂"NOR, ({"snake stone", "stone"}));
    	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "块");
            set("long", "这是一块罕见的绿色石头，看上去似乎有些年代了，据说于蛇王的腹中\n修炼所成，含有剧毒。\n");
            set("value", 20000);
            set("inset", 1);
            set("level",8);
            set("附加/damage_type","gin");
            set("附加/damage",10);
                
        }
        ::init_item();
} 