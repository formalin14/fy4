 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name("小和尚雕塑", ({ "statue", "little monk", "monk statue"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",
                        "一个不知用什么材料做成的小和尚，手脚都能活动，只要你一按
他背后的机关，他就会走出一套步法。\n");
                set("value", 500000);
                set("material", "steel");
                set("skill", ([
                        "name":                 "puti-steps",   
                        "exp_required": 0,              
                        "sen_cost":             50,     
                        "difficulty":   50,     
                        "max_skill":    49              
                ]) );
        }
        ::init_item();
}    
