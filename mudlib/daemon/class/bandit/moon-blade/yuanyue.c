#include <ansi.h>
#include <combat.h> 
inherit SSERVER;
int perform(object me, object target)
{
		object weapon;
        int extra, agi,str,cor,kar,exp,tarexp; 
        extra = me->query_skill("moon-blade",1);
        if (me->query("class")!="bandit") extra = extra/5;
        if((int) extra < 150)
                return notify_fail("你的圆月魔刀还不够精纯，不能出［明月几时有］。\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［明月几时有］只能对战斗中的对手使用。\n");

        message_vision(RED"$N"+NOR RED"大喝一声，身形在$n"+NOR RED"面前一闪……\n"NOR,me,target);
        weapon=me->query_temp("weapon"); 
		agi = me->query("agi");
		str = me->query("str");
		cor = me->query("cor");
		kar = me->query("kar");
		exp = me->query("combat_exp");
		if (me->query("moonblade")== 5) exp = exp*5;
		tarexp = target->query("combat_exp");
        if (weapon->query("for_modao"))
                if( random(extra*extra)+ exp*2+random(exp/4)>tarexp*(3/5)+random(tarexp/2) )
                {
						message_vision(WHT"\n\n虽然$n"+NOR WHT"根本没有看清楚，但是可以感觉到。。。"+BLINK HIW"$N"+BLINK HIW"已然出刀！\n"NOR, me, target);
                        me->set_temp("kill_other",1);
                        me->start_busy(2);
                        target->set_temp("last_damage_from",me);
//                        weapon=me->query_temp("weapon");
                        target->remove_killer(me);
                        me->remove_killer(target);
//                        target->apply_condition("moon-blade",1);
						me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), 3+random(5));
                }
                else
                {
                message_vision(YEL"但$n"+NOR YEL"就地一滚，总算躲过了$N"+NOR YEL"这无形的一招！\n\n"NOR, me, target);
                if (me->query_busy()<3) me->start_busy(3);
                } 
		else
        {       
                me->add_temp("apply/damage",extra*2);
                me->add_temp("apply/attack",extra*5);
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
                me->add_temp("apply/damage",-extra*2);
				me->add_temp("apply/attack",-extra*5);
                if (me->query_busy()<3) me->start_busy(3);
        }
        return 1;
} 

void kill_him(object me, object target)
{
        string msg; 
        message_vision(HIC "\n$N"+HIC"忽然由顶至踵分为两片，向两边倒了下去！！\n" NOR , target);
//        target->set_temp("last_damage_from",me);
        target->die(); 
        me->delete_temp("kill_other"); 
        me->add("bellicosity",100); 
        return;
}
