 // cloudstaff.c
inherit SKILL; 
void setup() {
        set("name",                     "白云杖法");
        set("learn_bonus",              -100);
        set("practice_bonus",           -5);
        set("black_white_ness",         -10);
        set("effective_level",          200);
        set("usage/staff",                      1);
        set("usage/parry",                      1);
        set("practice_damage",          30);
        set("practice_limit",170);
        set("skill_class",                      "bonze");       
        set("parry_msg",                        ({
                        "结果$n用手中的$v格开了$N的$w。\n",
                        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
                        })
        ); 
        set("unarmed_parry_msg",        ({
                        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
                        })
        );
        action = ({
                        ([      "action":               
                                        "$N使一招「天光乍现」，手中$w扫向$n下盘！",
                                "damage":               40,
                                "dodge":                80,
                                "parry":                80,
                                "post_action":  "bash_weapon",
                                "damage_type":  "挫伤"
                        ]),
                        ([      "action":               
                                        "$N挥起$w，一招「雨後初晴」攻向$n$l！",
                                "damage":               40,
                                "dodge":                70,
                                "parry":                90,
                                "post_action":  "bash_weapon",
                                "damage_type":  "挫伤"
                        ]),
                        ([      "action":           
                                   "$N横过手中$w，使出「浮云写意」击向$n$l！",
                                "damage":               40,
                                "dodge":                50,
                                "parry":                70,
                                "post_action":  "bash_weapon",
                                "damage_type":  "挫伤"
                        ]),
                        ([      "action":               
                                        "$N使出一招「游龙穿云」，$w一挺撞向$n$l！",
                                "damage":               40,
                                "dodge":                50,
                                "parry":                80,
                                "post_action":  "bash_weapon",
                                "damage_type":  "挫伤"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        
        if((int)me->query("str") + (int)me->query("max_force") / 10 < 35) {
                return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
        }
        return 1;
}  
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 20) {
                return notify_fail("你的内力不够练白云杖法。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}
