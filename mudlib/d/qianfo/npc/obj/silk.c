 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
    set_name(HIR"七"+HIY"彩"+HIG"丝缎带"NOR, ({ "silk", "rainbow silk" }) );
    set_weight(3000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
                set("unit", "条");
                set("long","这条七彩丝缎带在烛光下闪着七种光茫，一看就是不凡之品．\n");
                set("material", "cloth");
                set("realsilk",1);
                set("value",15000);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 5);
                set("armor_prop/spirituality",3);
    }
    ::init_waist();
}
