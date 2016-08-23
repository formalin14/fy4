 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(MAG"砍林刀"NOR, ({ "lindao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("jungle",1);
                set("material", "iron");
                set("long", "这是一寻常的砍林刀，专门用来砍小树和灌木。\n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

                set("wield_msg", "$N抽出一把黑油油的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间。\n");
        }
        ::init_blade(5);
} 
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}
