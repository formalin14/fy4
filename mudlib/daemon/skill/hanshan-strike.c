 //hanshan-strike.c
inherit SKILL;
void setup() {
        set("name", "寒山掌法");
        set("usage/unarmed", 1);
        set("usage/parry",1);
        set("effective_level", 150);
        set("skill_class", "knight");
        set("learn_bonus", 10);
        set("practice_bonus", -10);
        set("parry_msg", ({
        "$n一招「孤松一线」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n右拳虚幌，左拳一招「反客为主」，逼得$N后退三步。\n",
        "$n以守为攻，一招「狮吼辉煌」，猛击$N握$w的手腕。\n",
        "$n一招「听涛」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n一招「瞒天过海」，逼得$N中途撤招。\n",
        "$n脚走阴阳，一招「釜底抽薪」，攻$N之必救。\n",
        "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
        "$n双拳齐出，使出一招「一箭双雕」，$N的功势入泥牛入海，消失得无影无踪。\n",
        }) );   
        action = ({
                ([      "action":               "$N使一招「古松藏月」，对准$n的$l「呼」地一拳",
                        "dodge":                60,
                        "parry":                40,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N扬起拳头，一招「傲雪寒山」便往$n的$l招呼过去",
                        "dodge":                70,
                        "parry":                30,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N左手虚晃，右拳「寒山听涛」往$n的$l击出",
                        "dodge":                80,
                        "parry":                30,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N步履一沉，左拳拉开，右拳使出「龙吟归天」击向$n$l",
                        "dodge":                90,
                   "parry":                30,
                        "damage_type":  "瘀伤"
                ]),
        });
} 
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 10) {
                return notify_fail("你的内力不够练习。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 200 ) return 0;
        badint = victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth")*2;
        if (victim->query_skill_mapped("iron-cloth") == "jin-gang"
           ||victim->query_skill_mapped("iron-cloth") == "spring-water"
                ||victim->query_skill_mapped("iron-cloth") == "xuanxinjue"
                ) {
                if(badint) {
                        victim->receive_wound("kee",badint);
                        switch(random(3)) {
                                case 0: return "$N的劲力竟如行军布阵，绕过气墙，“喀啦”一声击中$n的气门！\n";
                                case 1: return "$N劲力尽处竟再生劲力，两劲齐发，$n的$l发出“喀”地一声爆响！\n";
                                case 2: return "只听见$n的$l“喀”地一声 ．．．\n";
                                }
                }
        }
}