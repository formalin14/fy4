 // -neon
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name(HIC"蓝色软甲"NOR, ({ "ruan jia", "cloth" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "一件蓝色的软甲。\n");
        set("material", "cloth");
        set("armor_prop/armor", 25);
        set("female_only", 1);
        set("value",4000);
    }
    ::init_cloth();
}     
