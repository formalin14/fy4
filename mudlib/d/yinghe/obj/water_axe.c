 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit AXE;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIC"玄冰凝魄斧"NOR, ({ "ice axe", "axe" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "斧上透着阵阵寒气。\n");
                set("wield_msg", "$N从腰间抽出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间。\n");
                set("attribute", "water");
                set("yinghe_weapon", 1);
        }
        ::init_axe(90);
}    
