 // tang-throwing.c
inherit SKILL; 
void setup(){ 
        set("name", "唐门暗器"); 
        set("usage/throwing", 1); 
        set("skill_class", "tangmen"); 
        set("effective_level", 180); 
        set("practice_bonus", -5); 
         
        action = ({ 
        ([      "action":                
"$N双手一晃，手中的$w如一条银蛇般飞向$n的$l", 
                "dodge":                -20, 
                "damage":               30, 
                "post_action":  "throw_weapon", 
                "damage_type":  "刺伤" 
        ]), 
        ([      "action":                
"$N右手一抖，$w发出刺耳的破空声直射$n的$l", 
                "dodge":                -40, 
                "damage":               30, 
                "post_action":  "throw_weapon", 
                "damage_type":  "刺伤" 
        ]), 
        ([      "action":                
"$N手指微动，$w斜斜的飞向$n的$l", 
                "dodge":                -40, 
                
                "post_action":  "throw_weapon", 
                "damage_type":  "刺伤" 
        ]), 
        ([      "action":                
"$N力发肩肘，右手一甩，手中的$w化作一道弧光射向$n的$l", 
                "dodge":                20, 
                "post_action":  "throw_weapon", 
                "damage":               40, 
                "damage_type":  "刺伤" 
        ]), 
        }); 
} 
int valid_learn(object me) 
{ 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
    if( (int)me->query("max_force") < 50 ){ 
        return notify_fail("你的内力不够，没有办法练唐门暗器。\n"); 
        } 
    return 1; 
} 
 
int practice_skill(object me) 
{ 
 
        if((int)me->query("force") < 3 ){ 
                return notify_fail("你的内力或气不够，没有办法练习暗器。\n"); 
    } 
    if(!::practice_skill(me)){ 
        return 0; 
    } 
    me->add("force", -3); 
        write("你按著所学练了一遍唐门暗器。\n"); 
    return 1; 
} 
 
