 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "无坎真阴");
        set("usage/force", 1);
        set("skill_class", "ninja");
        set("learn_bonus", 0);
        set("practice_bonus", -110);
        set("black_white_ness", -20);
}
int practice_skill(object me)
{
        return notify_fail("无坎真阴只能用学的，或是从运用(exert)中增加熟练度。\n");
}  
void skill_improved(object me)
{
        int s,diff;
        
        s = me->query_skill("ghosty-force", 1);
        diff = (s-100)/10;
        if((int)me->query("age_modify") > -diff && diff > 0) {
        tell_object(me, HIG "由於无坎真阴的驻颜奇效，你显得更发年轻了！\n" NOR);
                me->set("age_modify",-diff);
                me->update_age();
        }
/*      if(random(diff) > 10 && me->query("gender") == "男性") {
                tell_object(me,"你感觉到下体一热，眼前一黑！\n");
                me->set("gender","女性");
                me->unconcious();
        }
*/
} 
int valid_learn(object me)
{
        object ob;
        
        if(!::valid_learn(me)) {
           return 0;
        }
        if (!me->query("tianfeng/done_quest"))
                return notify_fail("天枫十四郎未答应转授你这门武功。\n");
        if (!(int)me->query("tianfeng/ghosty-force")){
                return notify_fail("天枫十四郎未答应教你这门武功。\n");
        }
        return 1;
} 
