 // cloth.c
// 
#include <armor.h> 
inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(MAG"��ɫ������װ"NOR, ({ "magcloth" }) ); 
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���·����ڷ����߱ڣ�����͵�㡣\n");
                set("material", "cloth");
                set("value", 10000);
                set("armor_prop/armor", 3);
        }
        ::init_cloth();
}  
