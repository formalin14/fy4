 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        me->receive_wound("kee", 10);
    me->receive_wound("gin", 10);
    me->receive_wound("sen", 10);
        me->apply_condition("mushroom", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "你终于感觉到好的多了！\n" NOR );
        else
        tell_object(me, HIW "你胃里一阵绞痛，头上冒出豆大的汗珠！\n" NOR ); 
        message("vision", me->name() + "右手按住胃部，面色惨白，头上冒出豆大的汗滴！\n",  
                        environment(me), me);
        if( duration < 1 ) 
                return 0;
        return 1;
}     
