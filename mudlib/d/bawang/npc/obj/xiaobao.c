 // dumpling.c
inherit ITEM;
inherit F_FOOD; 
void create()
{
        set_name("小笼包", ({ "xiao bao" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一笼香喷喷、热腾腾的小包子。\n");
                set("unit", "笼");
                set("value", 90);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
        ::init_item();
}       
