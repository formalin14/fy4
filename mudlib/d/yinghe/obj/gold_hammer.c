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
        set_name(HIY"紫金锤"NOR, ({ "gold hammer", "hammer" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "阵阵幽寒从锤上透出。\n");
                set("wield_msg", "$N背后抽出一把$n，掂掂分量握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
                set("attribute", "gold");
                set("yinghe_weapon", 1);
        }
        ::init_hammer(90);
} 
