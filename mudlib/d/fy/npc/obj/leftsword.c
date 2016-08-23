#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name( HIC "青锋剑" NOR, ({ "left-sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是把青锋剑有别于一般的青锋剑，剑身轻薄，护手左倾，看来适合左撇子使用。\n");
                set("value", 10500);
                set("material", "steel");
                set("wield_msg", "$N左手一翻，拔出$n交过右手。\n");
                set("unwield_msg", "$N将手中的$n插回身后。\n");
/*              set("no_drop",1);
                set("no_get",1);
                set("no_sell",1);*/
        }
        init_sword(105);
} 
