 //mimicat@fy4
inherit SKILL; 
void setup() {
        set("name",                                     "一指禅");
        set("effective_level",          210);
        set("learn_bonus",                      -400);
        set("practice_bonus",           -1000);
        set("black_white_ness",         15);
        set("skill_class",                      "shaolin");
        set("usage/unarmed",            1);
        set("usage/parry",              1);
        
        set("parry_msg",                        ({
                        "然而$n轮指虚点，锐利的指风将$N逼退。\n",
                        "$n身子一晃之间，已抢到$N对面，虚托一掌，一指点向$N肋下迫得$N闪身后退 。\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "然而$n轮指虚点，锐利的指风将$N逼退。\n",
                        "$n身子一晃之间，已抢到$N对面，虚托一掌，一指点向$N肋下迫得$N闪身后退 。\n",
                        })
        );
        action = ({
                        ([      "action":               
                        "$N斜挥食指，急点两下，隐隐然有一股内力发出击向$n$l ",
                                "dodge":                90,
                                "parry":                150,
                                "force":                100,
                                "damage_type":  "刺伤",
                                "weapon":               "气劲",
                        ]),
                        ([      "action":               
                        "$N一指点出，大开大阖，气派宏伟，以石破天惊、风雨大至之势刺向$n$l ",
                                "dodge":                140,
                                "parry":                210,
                                "force":                190,
                                "damage_type":  "刺伤",
                                "weapon":               "气劲",
                        ]),
                        ([      "action":               
                   "只见$N弓步前冲，右手乘势单指直点，激起的气流发出“嗤嗤”的响声 ",
                                "dodge":                230,
                                "parry":                170,
                                "force":                220,
                                "damage_type":  "刺伤",
                                "weapon":               "气劲",
                        ]),
                        ([      "action":               
                        "$N伸指向前一捺，一股凌厉的指力射将过去，点向$n$l ",
                                "dodge":                380,
                                "parry":                360,
                                "force":                390,
                                "damage_type":  "刺伤",
                                "weapon":               "气劲",
                        ]),
        });
} 
int valid_learn(object me) {
        
        if( (int)!me->query("once_xman") && (int)me->query_skill("zen",1)-50 < (int)me->query_skill("yizhichan",1))
                return notify_fail("你的禅道修为不够，无法领悟更高深的一指禅。\n");
        if(!::valid_learn(me)) {
                return 0;
        }
        if((string)me->query("class") != "shaolin" ) {
                return notify_fail("一指禅是只有少林高僧才能练的武功。\n");
        }
        if((int)me->query("max_force") < 350) {
                return notify_fail("你的内力不够！\n");
        }
        return 1;
}  
int practice_skill(object me) {
        return notify_fail("一指禅只能学的。\n");
}    
