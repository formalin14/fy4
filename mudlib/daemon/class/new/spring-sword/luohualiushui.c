#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int third_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
        string msg;
        int extra;
        int bonus, exp_bonus;
        object weapon;
        extra = me->query_skill("spring-sword",1);
        weapon=me->query_temp("weapon");
//        if ( extra < 50) return notify_fail("你的春雨剑法还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［落花流水］只能对战斗中的对手使用。\n");
        

        msg = HIC  "\n$N"HIC"凝眸一笑，使出春雨剑法中的最後一招－－［落花流水］！！\n\n"+HIG"「落 花 有 意」\n$N"HIG"手中的"+ weapon->name()+  HIG"忽然变得柔情似水，随着剑光慢慢飞舞！\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIG  "「流 水 无 情」\n正当$n"HIG"缠绵在剑招之间，$N"HIG"长啸一声，回头又是一剑！\n" NOR;
        me->add_temp("apply/damage",extra*4);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*4);

		if(me->query("free_rain/ending") && extra > 50) {
			exp_bonus = me->query("combat_exp")/1000*extra/8000;    
			if(extra > 150) bonus = extra;
			if(extra > 180) bonus = extra*2;
			me->add_temp("apply/attack",extra*4);
			me->add_temp("apply/damage",extra*8+ bonus+exp_bonus);
			msg = HIM  "$N"HIM"将绵绵恨意化作剑招，闪动变幻的剑影如春风化雨般攻向$n！\n" NOR;
//			target->receive_wound("sen",extra*2);
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			me->add_temp("apply/attack",-extra*4);
			me->add_temp("apply/damage",-extra*8-bonus-exp_bonus);
			if (me->query_busy()<3) me->start_busy(3);
		}
		else {
//            message_vision(YEL"$N"NOR YEL"的剑式看起来似乎还未臻化境。\n"NOR, me);
			if (me->query_busy()<2) me->start_busy(2);
		}
        return 1;
 
}
