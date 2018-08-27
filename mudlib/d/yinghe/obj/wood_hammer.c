 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIG"叠翠锤"NOR, ({ "wood blade", "blade" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "不知用何物造成的锤，锤身微微透着绿芒。\n");
                set("wield_msg", "$N背后抽出一把$n，掂掂分量握在手中。\n");
        set("unequip_msg", "$N放下手中的$n。\n");
                set("attribute", "wood");
                set("yinghe_weapon", 1);
        }
        ::init_blade(90);
}    
