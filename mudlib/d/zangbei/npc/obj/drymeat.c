 inherit ITEM;
inherit F_FOOD; 
void create()
{
        set_name("��ţ��", ({" dry meat","meat" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ɵ���ţ���⡣\n");
                set("unit", "��");
                set("value", 15);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
        ::init_item();
}    
