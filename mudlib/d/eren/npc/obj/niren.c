 inherit ITEM;
void create()
{
        set_name("小泥人" , ({ "small toy" , "toy"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个用泥捏成的小人。\n");
                set("value", 1000);
        }
        ::init_item();
}       
