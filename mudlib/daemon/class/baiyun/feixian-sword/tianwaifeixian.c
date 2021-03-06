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
        
        extra = me->query_skill("feixian-sword",1);
		if(me->query("class") != "baiyun") extra /= 2;
        me->add_temp("apply/attack", extra*3);    
        me->add_temp("apply/damage", extra*3); 
        weapon=me->query_temp("weapon");
        
        msg = HIY  "$N使出飞仙剑法中的精髓－－［天外飞仙］\n手中的"+ weapon->name() + HIY"划出一道长虹，闪电般的击向$n！" NOR;
        msg += HIW "剑光闪动，好似满天繁星。\n" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);

        me->add_temp("apply/attack", -extra*3);
        me->add_temp("apply/damage", -extra*3);
        if ( me->query_busy()<2 ) me->start_busy(2);
        return 1;
}  
