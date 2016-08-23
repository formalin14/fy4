 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int mine,yours,myexp,tarexp;
        int level;
        
        level = me->query_skill("qiankunstrike",1);
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［扭转乾坤］只能对战斗中的对手使用。\n");
        myexp=me->query("combat_exp");
        tarexp=target->query("combat_exp");
        mine = (int) me->query("force_factor");
        yours = (int) target->query("force_factor");
        msg= HIW"\n$N突然冷喝一声：扭－－转－－乾－－坤！！！\n\n"+HIY "$N将乾坤大挪移掌中的［扭转乾坤］使出，双掌夹带着$n的内力击向$n！" NOR;
        me->add("force_factor",yours+mine);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if( random(myexp*2)>random(tarexp) )
        {
        	message_vision(HIR"$N只觉得自己发出的内力突然从$n的掌间反噬过来！\n"NOR,target,me);
        	target->receive_damage("kee",level+random( (mine+yours)*3 ),me);
        }
        me->add("force_factor",-yours-mine);
        me->start_busy(2);
        return 1;
}   