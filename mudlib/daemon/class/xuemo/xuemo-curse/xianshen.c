 // curse_xianshen.c
#include <ansi.h> 
inherit SSERVER;
int curse(object me, object target)
{
        int lvl,i;
        
/*        if(me->query("env/invisibility"))
                return notify_fail("你正在施展［隐身术］\n");  */

        message_vision(HIG "$N心中默念咒语......\n" NOR, me);
//        me->start_call_out( (: call_other, __FILE__, "take_effect", me :), 5);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 1);
 //       if( me->is_fighting() ) me->start_busy(3);
        return 1; 
}
 void remove_effect(object me)
{
        me->set("env/invisibility", 0);
        message_vision(HIG "空气中逐渐浮现出$N的身形......。\n" NOR, me);
        me->move(environment(me));
//        me->start_busy(1);
        tell_object(me,YEL"你隐身失效了。\n"NOR);
} 
 /* void take_effect (object me)
{
        me->set("env/invisibility", 1);
        tell_object(me,YEL"你成功隐身了。\n"NOR);
        
} */