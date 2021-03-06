 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
        if ( (string) me->query_skill_mapped("sword") != "feixian-sword")
        return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
        extra = me->query_skill("feixian-sword",1) / 10;
        extra += me->query_skill("feixian-steps",1) /10;
		if ( me->query("class") != "baiyun" ) extra = extra *3/4;
        me->add_temp("apply/attack", extra*5);    
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N倒踏［飞仙步法］，以迅雷不及掩耳之势使出［飞仙剑法］中的精髓－－天外飞仙！\n手中的"+ weapon->name() + HIR"划出一道长虹，闪电般的击向$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg =  HIW "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/4;i++)
        {
        msg = HIY "$N"+HIY"身形突转，御剑回飞！\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        me->add_temp("apply/attack", -extra*5);
        me->add_temp("apply/damage", -extra);
        if ( me->query_busy()<2 ) me->start_busy(2);
        return 1;
}      
