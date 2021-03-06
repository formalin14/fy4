 // taiji.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "太极拳");
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        set("effective_level", 200);
        set("learn_bonus", 10);
        set("practice_bonus", -100);
        set("black_white_ness", 30);
        set("skill_class", "wudang");
        set("parry_msg", ({
            "$n一招「提手上势」，圆弧形击$N的面门，逼得$N中途撤回手中的$w。\n",
            "$n脚走太极，一招「搂膝勾步」，逼得$N后退三步。\n",
            "$n以守为攻，一招「进步搬拦锤」，猛击$N握$w的手腕。\n",
            "$n一招「如封似闭」，双掌不断圆转，引得$N不由自主地转了一圈。\n",
        }) ); 
        set("unarmed_parry_msg", ({
            "$n一招「十字手」，逼得$N中途撤招。\n",
            "$n脚走阴阳、以静制动，一招「抱虎归山」，把$N带出好远。\n",
            "$n左掌阴、右掌阳，使出太极拳的「起手式」，轻而易举地将$N封于尺外。\n",
            "$n双掌齐出，使出太极拳最后一式「单鞭和太极」，$N的攻势如泥牛入海，消失得无影无踪。\n",
        }) );   
        action = ({
            ([ "action":
            "$N双手圆转，使出一招「揽凤尾」，对准$n的$l击出",
             "dodge":30,
             "parry":150,
             "force":300,
             "damage_type":"瘀伤"
                ]),
            ([ "action":
            "$N左掌虚晃，右掌画了一个圆弧，一招「单鞭」便往$n的$l招呼过去",
             "dodge":20,
             "parry":120,
             "force":300,
             "damage_type":"瘀伤"
                ]),
            (["action": 
       "$N一招「白鹤亮翅」，双掌成圆弧形提起，圆转着向$n的$l击出",
             "dodge":20,
             "parry":120,
             "force":300,
             "damage_type":"瘀伤"
                ]),
            ([ "action":
            "$N左掌阳、右掌阴，使出一招「手挥琵琶」，双掌慢慢向$n的$l合拢",
             "dodge":20,
             "parry":120,
             "force":300,
             "damage_type":"瘀伤"
                ]),
        });
}
int valid_learn(object me)
{
        object ob;
        if( (int)me->query_skill("changelaw",1)*2 < (int)(me->query_skill("taiji",1))){
                return notify_fail("你对易经的了解还不够高深，无法学习太极拳。\n");
                }
        if(!::valid_learn(me)){
                return 0;
        }
        if ((int)me->query("max_force") < 500) {
                return notify_fail("你的内力不够。\n");
        }
        
        return 1;       
        
        
    return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 15 ) {
                return notify_fail("你的内力不够，不能练太极拳。\n");
        }
   if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -15);
        return 1;
        if ((int)me->query_skill("taiji",1) > 160) {
                return notify_fail("这套拳法到这儿后只能用学的。\n");
        }
}  
/*void skill_improved(object me)
{
    int s;
    s = me->query_skill("taiji", 1);
    if (s== 160 && me->query("class")=="wudang") {
       tell_object(me,HIW "你忽然觉得，如果你自己能再继续钻研一番的话，\n"NOR);
       tell_object(me,HIW "能够让太极拳的功效更上一层楼！\n"NOR);
       }
    if (s== 165 && me->query("class")=="wudang") {
       tell_object(me,HIW "你对太极拳的领悟已是登峰造极！！！\n"NOR);
       }
} */    
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 300 ) return 0;
        badint = victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth")*2;
        if (victim->query_skill_mapped("iron-cloth") == "xuanxinjue"
           ||victim->query_skill_mapped("iron-cloth") == "jin-gang"
                ||victim->query_skill_mapped("iron-cloth") == "spring-water"
                ) {
                if(badint) {
                        victim->receive_wound("kee",badint);
                        switch(random(3)) {
                                case 0: return "$N拳势绵绵不绝，劲力集中一点，竟突破了$n的气墙！\n";
                                case 1: return "$N拳劲遭遇气墙後突然消失，却又在$n的$l前突然出现，紧接着只听见“喀”地一声爆响！\n";
                                case 2: return "只听见$n的$l“喀”地一声 ．．．\n";
                                }
                }
        }
}  