#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("落云箭", ({ "giant arrow", "arrow" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个巨型的箭头。\n");
                set("value", 1000);
        set("material", "metal");
    }
        ::init_item();
}      
