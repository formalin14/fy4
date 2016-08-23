 // hanshan-sword.c
 
#include <ansi.h> 
 
inherit SKILL; 
void setup() { 
        set("name", "寒山十八式"); 
        set("usage/sword", 1); 
        set("usage/parry", 1); 
        set("effective_level", 270); 
        set("practice_bonus", -50);
        set("practice_limit",100);
        set("learn_bonus", -300);
        set("black_white_ness", 5);
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
        "$n不退反进，气走周天，一招「"+NOR WHT"无边"+NOR"」，手中的$v狠狠磕开了$N的$w。\n", 
                "$n回剑自守，一招「"+NOR RED"鬼火"+NOR"」，架住了$N的$w。\n", 
                "$n一招「"+NOR MAG"乱舞"+NOR"」，手中的$v化作千百把，护住了全身。\n", 
                "$n手中的$v自上削下，几乎将$N的$w削成两段。\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$n使出一招「"+NOR YEL"万障"+NOR"」，在身前布起了一道铜墙铁壁，封住了$N的攻势。\n", 
                "$n一抖手中的$v，使出一招「"+NOR CYN"碧灵"+NOR"」，手中的$v护住了全身。\n", 
                "$n将$v往地上一刺，$v反弹起来，刚好直刺$N的双臂。\n", 
                "$n举剑静立，一股内力从剑梢透出，逼开了$N。\n", 
        }) );    
        action = ({ 
                ([      "name":                 "群魔乱舞", 
                        "action":               "$N使一招「"+HIW"白云"+NOR"」，手中$w狂风骤雨般地向$n的$l连攻数剑", 
                        "damage":               70, 
                        "force" :               200, 
                        "damage_type":  "刺伤" 
                ]), 
                ([      "name":                 "厉鬼缠身", 
                        "action":               "$N身形一转，一招「"+HIC"天悬"+NOR"」$w斩向$n的$l", 
                        "damage":               50, 
                        "force" :               100, 
                   "damage_type":  "刺伤" 
                ]), 
                ([      "name":                 "百鬼夜行", 
                        "action":               "$N舞动$w，一招「"+HIM"虹日"+NOR"」挟著闪闪剑光刺向$n的$l", 
                        "parry" :               -50, 
                        "damage":               150, 
                        "force" :               250, 
                        "damage_type":  "刺伤" 
                ]), 
                ([      "name":                 "饿鬼拦路", 
                        "action":               "$N手中$w一抖，使出「"+HIB"鬼魅"+NOR"」往$n的$l刺出一剑", 
                        "damage":               50, 
                        "force" :               150, 
                        "damage_type":  "刺伤" 
                ]), 
                ([      "name":                 "鬼影幢幢", 
                        "action":               "$N手中$w剑光暴长，一招「"+HIR"鬼影"+NOR"」往$n$l刺去", 
                        "dodge":                -30, 
                        "parry" :               -30, 
                        "damage":               90, 
                        "force" :               220, 
                        "damage_type":  "刺伤" 
                ]), 
                ([      "name":                 "秋坟鬼唱", 
                        "action":               "$N手中$w直指$n$l，一招「"+HIY"秋坟"+NOR"」发出逼人剑气刺去", 
                        "damage":               50, 
                        "damage_type":  "刺伤" 
                ]), 
        }); 
} 
 
int valid_learn(object me) 
{ 
        object ob; 
 
        if( (int)me->query_skill("sword",1) < 120 ) {
           return notify_fail("你对基本剑法的领悟不够深！\n"); 
        } 
        if(!::valid_learn(me)) { 
                return 0; 
        } 
        return 1; 
} 
 
int practice_skill(object me) 
{ 
 
        if((int)me->query("force") < 1000 ) { 
                return notify_fail("你的内力不够，没有办法练习寒山十八式。\n"); 
        } 
        if(!::practice_skill(me)) { 
                return 0; 
        } 
        me->add("force", -10); 
        write("你按著所学练了一遍寒山十八式。\n"); 
        return 1; 
} 
 
   
