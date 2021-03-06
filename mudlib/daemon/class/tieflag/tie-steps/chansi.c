 // chansi.c
//written by kouga
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        string msg;
        skill = me->query_skill("tie-steps", 1);
        if(skill < 50) 
                return notify_fail("你的铁血十二势太差了！\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［缠丝势］只能对战斗中的对手使用。\n");
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        if( (int)me->query("force") < 100 )    
                return notify_fail("你的内力不够。\n");
        if( (int)target->query_temp("chansi") ) 
                return notify_fail("你已经在施展［缠丝势］了。\n");
        
        message_vision(HIR "$N"+HIR"轻身一跃，身形犹如陀螺般绕着$n"+HIR"滴溜溜地转个不停。\n" NOR, me,target);  
        if((int)target->query("combat_exp") < random((int)me->query("combat_exp")*skill/4))
        {
                if (userp(me))  me->add("force", -100);
                message_vision( HIR
                "$n"+HIR"的身形受$N"+HIR"的影响，变的生涩起来！\n" NOR, me,target);
                target->add_temp("apply/dodge", -skill);
                target->add_temp("apply/parry",-skill);       
                target->set_temp("chansi", 1);
                target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
-skill :), skill/5);
                me->start_busy(1);
        }
        else
        {
           msg = WHT"可惜$N"+WHT"看出了$n"+WHT"的身法，向$n"+WHT"迅然攻击！"NOR;
                COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
                me->start_busy(1);
        }
        return 1;
} 
void remove_effect(object target, int amount)
{
        target->add_temp("apply/dodge", - amount);
        target->add_temp("apply/parry",- amount);
        target->delete_temp("chansi");
        message_vision("$N终于摆脱了［缠丝势］的影响。\n",target);
}
      
