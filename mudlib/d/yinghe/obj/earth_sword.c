 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(YEL"冥灵剑"NOR, ({ "earth sword", "sword" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "青色的剑身散发着逼人的杀气。\n");
                set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("yinghe_weapon", 1);
        }
        ::init_sword(90);
} 
