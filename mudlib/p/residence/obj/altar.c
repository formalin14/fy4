 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("祭坛", ({ "祭坛" , "altar"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一处祭祀古代神灵的祭坛，你似乎可以对着它许愿（wish)。\n");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }      
