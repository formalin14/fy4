 // celestrike.c
inherit SKILL; 
void setup() {
        set("name",                             "天邪掌法");
        set("learn_bonus",                      10);
        set("practice_bonus",           5);
        set("black_white_ness",         -10);
        set("effective_level",  100);
        set("usage/unarmed",            1);
        set("parry_msg",                        ({
                        "$n化掌为刀，一招「碧血五指挑」急切$N拿着$w的手。\n",
                        "$n双掌交错，使出一招「童子拜寿」，「啪」的一声将$N的$w夹在双掌之间。\n",
                        "$n略一转身，一招「兵出无名」拍向$N拿着$w的手。\n",
                        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
                })
        );
        set("unarmed_parry_msg",        ({
                        "$n步走七星，一招「反客为主」虚空拍出十三掌，逼得$N撤招自保。\n",
                        "$n化掌为指，一招「掌指双飞」反点$N的周身要穴。\n",
                        "$n施展出「掌指双飞」，轻描淡写的化解了$N的攻势。\n",
                })
        );
        
        action = ({
                        ([      "action":               
                        "$N使出一招「大天罗式」，右掌穿出击向$n的$l",
                                "dodge":                -30,
                                "parry":                10,
                                "force":                200,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N使出一招「大天罗式」，左掌化虚为实击向$n的$l",
                                "dodge":                -10,
                                "parry":                -30,
                                "force":                170,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N使出天邪掌法「小天罗式」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
                           "dodge":                -30,
                                "parry":                10,
                                "force":                150,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N双掌一错，使出「雪阳三连月」，对准$n的$l连续拍出三掌",
                                "dodge":                10,
                                "parry":                -30,
                                "force":                260,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N左掌画了个圈圈，右掌推出，一招「灵动五方鼓」击向$n$l",
                                "dodge":                -20,
                                "parry":                -30,
                                "force":                240,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N使出「风雷七星断」，身形散作七处同时向$n的$l出掌攻击",
                                "dodge":                -70,
                                "parry":                -10,
                                "force":                280,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N吐气扬声，一招「气撼九重天」双掌并力推出",
                                "parry":                -40,
                                "force":                320,
                                "damage_type":  "瘀伤"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)){
                return 0;
        }
        if((int)me->query_skill("celestial", 1) < 20 ) {
                return notify_fail("你的天邪神功火候不足，无法练天邪掌法。\n");
   }
        if((int)me->query("max_force") < 100 ) {
                return notify_fail("你的内力太弱，无法练天邪掌法。\n");
        }
        return 1;
} 
int practice_skill(object me) {
        if((int)me->query("force") < 5 ) {
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
}
