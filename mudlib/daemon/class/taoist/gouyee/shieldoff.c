 //mimicat@fy4
#include <ansi.h> 
int exert(object me, object target)
{
        int extra,ratio,delay;
        
        extra=me->query_skill("gouyee",1);
        if(extra<120)
                return notify_fail("你谷衣心法的等级不够高。\n");
        if(!me->query_temp("shield_force"))
                return notify_fail("你不在运功中。\n");
        
        if (me->is_fighting())
        {
                return notify_fail("在战斗中不可收回天罡真气。\n");
        }
                
        if(target&& me!=target)
                return notify_fail("取消天罡真气只能用在自己身上。\n");
        call_other(__DIR__"manashield.c","stop_effect",me);
        me->start_busy(3);
        me->set("mana",0);
        me->delete_temp("shield_force");
        me->delete_temp("till_death/shield_lock");
        message_vision(HIW"$N长吐了一口气,身边的紫气慢慢地消失了。\n"NOR,me);
        return 1;
}     
