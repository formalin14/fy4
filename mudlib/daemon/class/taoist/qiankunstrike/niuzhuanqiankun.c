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
                return notify_fail("��ŤתǬ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        myexp=me->query("combat_exp");
        tarexp=target->query("combat_exp");
        mine = (int) me->query("force_factor");
        yours = (int) target->query("force_factor");
        msg= HIW"\n$NͻȻ���һ����Ť����ת����Ǭ������������\n\n"+HIY "$N��Ǭ����Ų�����еģ�ŤתǬ����ʹ����˫�Ƽд���$n����������$n��" NOR;
        me->add("force_factor",yours+mine);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if( random(myexp*2)>random(tarexp) )
        {
        	message_vision(HIR"$Nֻ�����Լ�����������ͻȻ��$n���Ƽ䷴�ɹ�����\n"NOR,target,me);
        	target->receive_damage("kee",level+random( (mine+yours)*3 ),me);
        }
        me->add("force_factor",-yours-mine);
        me->start_busy(2);
        return 1;
}   