#include <ansi.h>;
inherit "/std/item/jade"; 
void create()
{
        set_name(HIG"����֮��"NOR, ({"snake stone", "stone"}));
    	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long", "����һ�麱������ɫʯͷ������ȥ�ƺ���Щ����ˣ���˵�������ĸ���\n�������ɣ����о綾��\n");
            set("value", 20000);
            set("inset", 1);
            set("level",8);
            set("����/damage_type","gin");
            set("����/damage",10);
                
        }
        ::init_item();
} 