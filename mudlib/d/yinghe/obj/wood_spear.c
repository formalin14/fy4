 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIG"叠翠枪"NOR, ({ "wood spear", "spear" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 1);
                set("material", "iron");
                set("long", "不知用何物造成的枪，枪身微微透着绿芒。\n");
                set("wield_msg", "$N握紧手中的$n。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
                set("attribute", "wood");
                set("yinghe_weapon", 1);
        }
        ::init_spear(90);
}      
