 inherit ITEM;
void create()
{
        set_name("阶石", ({ "jieshi", "阶石","stair","stone" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "黑黝黝的阶石\n");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }   
