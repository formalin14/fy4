#include <ansi.h>;
inherit ITEM; 
void create()
{
        set_name(HIG"��ʯͷ"NOR, ({"green stone", "stone"}));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long", "����һ�麱������ɫʯͷ��\n");
                set("value", 20000);
                set("inset", 1);
                set("level",1);
        }
        ::init_item();
} 