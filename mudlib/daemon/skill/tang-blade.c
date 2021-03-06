 // tang-blade.c
 
inherit SKILL; 
void setup(){ 
        set("name", "五瓣兰刀法"); 
        set("usage/blade", 1); 
        set("usage/parry", 1); 
        set("effective_level", 200); 
        set("practice_damage", 40); 
        set("learn_bonus", -100); 
        set("practice_bonus", -50); 
        set("black_white_ness", 30); 
        set("skill_class", "tangmen"); 
        set("parry_msg", ({ 
        "$n使出一招「长天一刀」，用手中的$v急削$N的五指。\n", 
                "$n左脚踏前一步，一招「青青花瓣」，手中的$v从侧面飘向$N之必救。\n", 
                "$n手中的$v一抖，挽出一片刀花，一招「悠悠兰心」，撒向$N的全身。\n", 
                "$n微退一步，手中的$v划出一条光弧，一招「以花会友」，将$N的全身围住。\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
                "$n使出一招「沉吟至今」，用手中的$v急砍$N。\n", 
                "$n左脚踏前踏，一招「一星望月」，手中的$v挥向$N之必救。\n", 
                "$n手中的$v一抖，一招「山高水远」，奔向$N。\n", 
                "$n手中的$v划出一招「归心一诗」，将$N的全身围住。\n", 
        }) ); 
 
        action = ({ 
                ([      "action":                
                "$N使一招「落瓣几分」，手中$w风似地向$n的$l斩去！", 
                        "damage":               70, 
                        "dodge":                70, 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":                
                "$N弯刀似月，$w随著一招「泪雨鲜花」由下而上撩往$n的$l", 
                        "damage":               40, 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":                
           "$N身形一转，一招「兰花片片飘浮」$w如朝露闪烁，斩向$n的$l", 
                        "damage":               20, 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":                
                "$N舞动$w，一招「去日苦多」往$n的$l斜斜砍出一刀", 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":                
                "$N手中$w一晃，一招「无视艳丽」迅捷无伦地劈向$n的$l", 
                        "damage":               70, 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":                
                "$N提气丹田，身型咋展，一招「花瓣飞扬」直劈$n$l", 
                        "damage":               30, 
                        "damage_type":  "割伤" 
                ]), 
                ([      "action":                
                "$N移步侧身，使一招「何回忖皴」霍霍斩向$n的$l", 
                        "damage":               50, 
                        "damage_type":  "割伤" 
                ]), 
        }); 
} 
int valid_learn(object me) 
{ 
    if((int)me->query("max_force") < 50 ){ 
            return notify_fail("你的内力不够，没有办法练五瓣兰刀法\n"); 
    } 
	if(me->query_skill("tangforce",1)*2<me->query_skill("tang-blade",1)){
			return notify_fail("你对唐诵的理解还不够！\n");
    }
    if((string)me->query_skill_mapped("force")!= "tangforce"){ 
            return notify_fail("五瓣兰刀法必须配合唐诵才能练。\n");  
        } 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
    return 1; 
} 
 
 
  
int practice_skill(object me)
{
       return notify_fail("「五瓣兰刀法」只能用学的。\n");
}        