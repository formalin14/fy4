 // counterattack.c
#include <ansi.h> 
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int cps;
        
        if(me->query("class") != "quest_npc")
		return notify_fail("�㲻��ʹ�á�"HIG"����ɵ�"NOR"����\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��"HIG"����ɵ�"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int) me->query_skill("moon-blade",1) <= 300)
                return notify_fail("���Բ��ħ�����������������ܷ�����"HIG"����ɵ�"NOR"����\n"); 
        message_vision(HIC"ͻȻ����ػ谵��$N���еĵ���û��������¹⣬Ѥ�õĹ�â�У�����������\n�������裬���������������ȴ���������еĶ���ԹԹ��\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(2)+1);
        me->start_busy(2);
        cps = (int)target->query("cps");
        if( random(cps) < 30 ) target->start_busy(1+random(1));
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        object weapon;
        int cps,myexp,tarexp,damgin,damsen,targin,tarsen;
        targin=target->query("max_gin");
        tarsen=target->query("max_sen");
        damgin = targin/2;
        damsen = targin/2;
        cps = (int)target->query("cps");
        myexp=me->query("combat_exp");
        weapon=target->query_temp("weapon");
        tarexp=target->query("combat_exp");
        
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
        	if ( (2*myexp+random(myexp/4)) >= tarexp ){
        		if(random(cps) < 30 && objectp(weapon)){
				message_vision(HIG "$N����ǰ�ľ����Ի󣬴����ķ������е�"NOR+weapon->query("name")+HIG"��\n"NOR,target);
				weapon->unequip();
				message_vision(HIG "ͻȻ֮�䣬��������������$N��âɢȥ�������¹�����һ���������$n��������\n"NOR,me,target);
                	} else if( !objectp(weapon) ){
                		message_vision(HIG "$N����ǰ�ľ����Ի󣬾�Ȼ�����˽����ٶȡ�\n"NOR,target);
				message_vision(HIG "ͻȻ֮�䣬��������������$N���еĹ�âɢȥ�������¹�����һ���������$n��������\n"NOR,me,target);
			} else {
				message_vision(HIG "ͻȻ֮�䣬��������������$N���еĹ�âɢȥ�������¹�����һ���������$n��������\n"NOR,me,target);
			}
			target->set_temp("last_damage_from",me);							
                	target->die();
                }
                else{
                	message_vision(HIR"$N��������ͻȻ����ãã���¹���$n�ĵ��澹���Լ����ʺ��������\n"NOR,target,me);
                	if(objectp(weapon)){
                		weapon->unequip();
                	        message_vision(HIR"ǧ��һ��֮����$N�������б��������ݼ��ˣ�$n�ĵ���������������ãã����������������������\n"NOR,target,me);
                	}
                	else message_vision(HIR"ǧ��һ��֮����$N���ݼ��ˣ�$n�ĵ���������������ãã����������������������\n"NOR,target,me);
                	target->receive_damage("sen",damsen,me);
                	target->receive_damage("gin",damgin,me); 
//                        target->receive_wound("gin",10 + random(celepower),me);
                        COMBAT_D->report_status(target);
                        COMBAT_D->win_lose_check(me,target,1);
                }                         
        }
        me->start_busy(2);        
        return ;
}     
