 // jade
#include <ansi.h>
#include <armor.h> 
inherit NECK; 
void create()
{
        set_name(HIC"玉佩"NOR, ({"jade", "yu pei"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个晶莹剔透的玉佩。\n");
                set("unit", "个");
                set("value", 50000);
                set("armor_prop/armor", 2);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一快$n套在颈上。\n");
                set("unwield_msg", "$N轻轻地把$n从颈上除了下来。\n");
        }
        ::init_neck();
}   
