 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
inherit __DIR__"yinghe_weapon";  
void create() {
        set_name(HIR"烈火荧锤"NOR, ({ "fire hammer", "hammer" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "这是上面有着烈火图纹的锤。\n");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
                set("attribute", "fire");
                set("yinghe_weapon", 1);
        }
        ::init_hammer(90);
}   
