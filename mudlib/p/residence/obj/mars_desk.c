 inherit ITEM;
void create()
{
    	set_name("衣橱", ({ "wardrobe" , "衣橱"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "个");
        set("long", "一个很大的衣橱，里面可以放置很多东西。\n");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }    
