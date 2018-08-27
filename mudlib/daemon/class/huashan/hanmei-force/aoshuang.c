 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 40 )
                return notify_fail("你的真气不够。\n"); 
        write( HIW "你运起『傲霜诀』，开始运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + 
"运起『傲霜诀』，左掌上翻，右掌反腕相对，如绽开一朵寒梅。\n一层淡淡的白气从指掌间透出，" 
+ me->name()+ "的外伤开始慢慢愈合。\n" NOR, 
                environment(me), me); 
        me->receive_curing("kee", 20 + (int)me->query_skill("hanmei-force",1));
        me->add("force", -40);
        me->set("force_factor", 0); 
        return 1;
}
      
