 // weishe.c
#include <ansi.h> 
inherit F_CLEAN_UP; 
int exert(object me, object target)
{
        object *ob,victim;
        string who,weapon;
        int cps, skill, myexp,tarexp; 
	
	weapon=target->query_temp("weapon");
	myexp = (int)me->query("combat_exp");
	tarexp = (int)target->query("combat_exp");
	cps = (int)target->query("cps");
	skill=(int)me->query_skill("bolomiduo",1);
	
	if( skill < 160 )
		return notify_fail("��������۶��ľ��ȼ�����������ʹ�����壡\n");
	if( me->query("class") != "lama")
		return notify_fail("�����塹ֻ�����ڵ��Ӳ���ʹ�ã�\n");
	if( me->is_fighting() )
                return notify_fail("ս���в���ʹ�á����塹��\n");
        if( me->query("weishe/timer")+300 > time())
        	return notify_fail("����ܺķ��������㻹����Ϣһ�°ɡ�\n");
	victim = present(who, environment(me)); 
        if( !victim || victim == me) return notify_fail("��������Ķ��������\n"); 
        if( !living(victim) || !objectp(victim))
                return notify_fail("��Ҫ����˭��\n"); 
        if( !me->is_fighting() && !target->is_fighting() &&
 		environment(me) == environment(target))
 	{
 		if(objectp(weapon)){
 			message_vision(HIR"$N����$n���һ�����������������е����������־��ܣ�������ʱ����\n"NOR,me,target);
 			if(myexp+random(myexp/2) < tarexp/2)
 				message_vision(HIC"$N��$n��Цһ�����������ĵ��С����Ҳ�����ң�\n"NOR,target,me);
 			else {
 				message_vision(WHT"$N��$n���������壬���������ķ��������е�������\n"NOR,target,me);
 				weapon->unequip();
 			}
 		me->set("weishe/timer",time());
 		}else return notify_fail("�Է�û��������������Ҫʹ�����壡\n");
	}
	me->start_busy(1);
        return 1;
}     
