#include <weapon.h>
#include <ansi.h>
inherit BLADE; 
void create()
{
        set_name(HIG"弯刀"NOR, ({ "duoblade" ,"blade"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "碧绿的刀鞘上镶嵌着三课价值连城的珍珠。");
                set("value", 200000);
                set("material", "steel"); 
        set("wield_msg", "$N从腰间抽出一把碧绿的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        }
        ::init_blade(110);
}   
