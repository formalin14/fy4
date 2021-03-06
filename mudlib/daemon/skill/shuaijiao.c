 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "摔跤");
        set("usage/unarmed", 1);
        set("learn_bonus", 10);
        set("practice_bonus", 20);
        set("black_white_ness", 5);
        set("skill_class", "xinjiang");
        set("parry_msg", ({
        "$n就势一滚，双手一撑地，全身弹出$N的$w的攻击范围。\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
        }) );
        action = ({
        ([      "action":               
"$N双手前伸，似乎要抓住$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双手搭向$n，身体向后倾斜，似乎要将$n摔倒",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N冷不盯伸出左脚，企图将$n拌倒在地下",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右脚凌空，晃出一片腿影，霎那间向$n的$l一连踹出三脚",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N抱住$n的$l，将$n举过头顶，往地下狠狠一摔",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "瘀伤"
        ]),
        });
}        
