 inherit ITEM;
inherit F_FOOD; 
void create(){
        set_name("��Բ", ({"guiyuan", "gui yuan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һЩ��Բ�ɡ�\n");
                set("unit", "Щ");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 6);
        }
    ::init_item();
}  
