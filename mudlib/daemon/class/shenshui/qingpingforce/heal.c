 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if (me->query_skill("qingpingforce",1)<50)
                return notify_fail("你的清平内功等级不够高。\n"); 
        if( target != me ) return 
                notify_fail("你只能用内功疗自己的伤。\n");
                
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 100)
                return notify_fail("你的真气不够。\n"); 
        write( HIW "你运起[静心诀]，全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + "运起[静心诀]，坐下来运功疗伤，不久，吐出一口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);
        me->receive_curing("kee", 20 + (int)me->query_skill("qingpingforce",1)*2);
        me->receive_curing("gin", 10 + (int)me->query_skill("qingpingforce",1));
        me->receive_curing("sen", 10 + (int)me->query_skill("qingpingforce",1));
        me->add("force", -100);
        me->set("force_factor", 0); 
        return 1;
}    
