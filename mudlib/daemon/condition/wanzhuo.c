 // wanzhuo.c  万灼毒
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        me->receive_wound("gin", 120);
        me->receive_damage("gin", 120);
        me->apply_condition("wanzhuo", duration - 1);
        if( duration < 1 )
                tell_object(me, HIG "你中的万灼毒终于发作光了！\n" NOR );
        else
                tell_object(me, HIR "你中的万灼毒发作了！\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}    
