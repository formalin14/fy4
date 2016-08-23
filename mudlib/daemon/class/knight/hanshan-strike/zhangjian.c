#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,bonus, exp_bonus;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［掌剑］只能对战斗中的对手使用。\n");
        extra = me->query_skill("hanshan-strike",1) ;
        if( extra < 90) return notify_fail("你的［寒山掌法］还不够熟练！\n");
        
        bonus=extra/3;
        
        exp_bonus= me->query("combat_exp")/1000*extra/5000;
        if (exp_bonus>extra) exp_bonus=extra;
        
        bonus = bonus + exp_bonus;
        
        
        
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        msg = HIM  "$N双掌互相交错，突一纵身，双手化掌为剑疾向$n"NOR+HIM"削去！" NOR;
        COMBAT_D->do_attack(me,target,  TYPE_PERFORM,msg);
        msg = HIY  "$N一侧身，一肘撞向$n"NOR+HIY"的面门！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if (extra>110) {
        msg = HIW  "$N又一反身，双掌急向$n"NOR+HIW"砍去！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (extra>150) {
        msg = HIR  "$N左手横胸，右手忽一亮掌，蓄力已久的［掌剑］破空向$n"NOR+HIR"刺去！" NOR;
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -bonus);
   me->add_temp("apply/damage", -bonus);
        }
        me->add_temp("apply/attack", -bonus);
        me->add_temp("apply/damage", -bonus);
        if (extra>130) {
                if (me->query_busy()<3) me->start_busy(3);
                }
                else {
                        if (me->query_busy()<2) me->start_busy(2);
                        }
        return 1;
}      
