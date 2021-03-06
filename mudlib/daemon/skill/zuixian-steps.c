 // zuixian-steps.c
inherit SKILL; 
void setup() {
        set("name",                                     "醉仙望月步");
        set("usage/dodge",                      1);
        set("usage/move",                       1);
        set("effective_level",          150);
        set("skill_class",                      "yinshi");
        set("dodge_msg",                        ({
                        "但是$n身形飘忽，轻轻一纵，一招「醉仙望月」，轻而易举的避开这一击。\n",
                        "$n身随意转，一式「仙人敬酒」，往旁窜开数尺，躲了开去。\n",
                        "$n身形往上拔起，一招「把酒飞仙」，一个转折落在数尺之外。\n"
                        })
        );
}   
int practice_skill(object me)
{
        if( (int)me->query("force") < 5 ){
            return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        return 1;
}      
