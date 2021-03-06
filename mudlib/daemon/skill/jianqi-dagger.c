 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h> 
void setup(){
    set("name", "红绸剑器");
        set("usage/dagger", 1);
        set("usage/parry",  1);
        set("effective_level", 200);
        set("learn_bonus", -100);
        set("practice_bonus", -5);
        set("practice_limit",50);
        set("black_white_ness", 20);
        set("skill_class","new");
        set("parry_msg", ({
                "$n飞快地将$v舞动起来，身边的一切随风而动，阻挡了$N的进攻。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n手中的$v发出阵阵剑气，剑气化作千千万万的绸带缠向$N。\n",
        }) );   
        
        
        action = ({
        ([  "action":       "$N右手一挥$w，一舞剑器动四方。$n如山色沮丧，就连天地亦为之久低昂",
                        "dodge":                100,
                        "damage":               200,
                        "damage_type":  "割伤"
                ]),
        ([  "action":       "$N剑锋突转，一招『羿射九日落』矫如群帝骖龙翔",
                        "dodge":                150,
                        "damage":               180,
                        "damage_type":  "割伤"
                ]),
        ([  "action":       "$N手中的$w突然使出『绛唇珠袖两寂寞』，真是来如雷霆收震怒，罢如江海凝清光，让
$n喘不过气来",
                        "dodge":                200,
                        "damage":               220,
                        "damage_type":  "割伤"
           ]),
        ([  "action":       "$N剑气一转，『金粟堆南木已拱，瞿塘石城草萧瑟』使出，只觉得玳弦急管曲复终，乐
极哀来月东出，姿态妙曼已极",
                        "dodge":                220,
                        "damage":               300,
                        "damage_type":  "割伤"
                ]),
        ([  "action":       "$N双手紧握$w，一招『风尘洞庭昏王室，足茧荒山转愁』向$n$l劈落",
                        "dodge":                300,
                        "damage":               100,
                        "damage_type":  "割伤"
                ]),
        });
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object my_weapon;
        int badint;
        my_weapon=me->query_temp("weapon");
        if(damage_bonus < 300 ) return 0;
        if(victim->query_skill_mapped("iron-cloth") == "xuanxinjue"
           ||victim->query_skill_mapped("iron-cloth") == "xisui"
                ||victim->query_skill_mapped("iron-cloth") == "spring-water"
                ) {
                badint = victim->query_skill("iron-cloth")*2+random(victim->query_skill("iron-cloth"));
                if(badint) {
                        victim->receive_wound("kee",badint,me);
                        switch(random(2)) {
                                case 0: return HIW"$N手中"+my_weapon->query("name")+"剑气大盛，一击破了$n的护体神功！\n"NOR;
                                case 1: return HIW"$n只觉周围一亮,$N的"+my_weapon->query("name")+"竟已到眼前．．．\n"NOR;
                        }
                }
        }
        return 0;
} 
int practice_skill(object me)
{
        if( (int)me->query("force") < 50 ){
            return notify_fail("你的内力不够。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
   return 1;
}    
