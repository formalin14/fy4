 // silencer@fy
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        int ammount; 
        if(me->query("class")!="beggar")
        return notify_fail("只有丐帮弟子才能领悟回力的奥妙。\n"); 
        if( target && target!=me )
                return notify_fail("「回力诀」只能用在自己身上。\n"); 
        amount = 100;
        
        if( (int)me->query("force") < amount*3 )
                return notify_fail("你的内力不够。\n");
                
        me->add("force", -amount*3);
        message_vision(HIY "$N闭目凝神，运转了一周混沌心法中的「回力诀」...\n"NOR,me);
        
        if ( (int)me->query_skill("huntunforce",1)<150) 
                {
                if (me->query("food")<100) me->set("food",100);
                message_vision(HIY"$N只觉丹田升起一股暖流，腹中空空的感觉顿时无影无踪。\n" NOR,me);
                }
        else {
                if (me->query("food")<100) me->set("food",100);
                if (me->query("water")<100) me->set("water",100);
                message_vision(
                        HIY"$N只觉丹田升起一股暖流，腹中空空的感觉顿时无影无踪。\n" NOR,me);
                message_vision(
                        HIG"$N觉得口干舌燥的感觉也消失了。\n"NOR,me);
             }  
        me->start_busy(3);
        return 1;
}
  
