 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string dodskill,msg;
    int extra, count, n;
    int tmp,chance;
    extra = me->query_skill("shenji-blade",1);
    if ( extra < 50) return notify_fail("你的［神机刀法］还不够纯熟！\n");
    dodskill = (string) me->query_skill_mapped("dodge");
    if ( dodskill != "shenji-steps")
        return notify_fail("［计出连环］需要［神机步法］的配和！\n");
    tmp = me->query_skill("shenji-steps",1);
    if ( tmp < 50 )return notify_fail("你的［神机步法］还不够纯熟！\n");
	if (me->query("class") != "emei")
	{
		extra = extra /2;
		tmp = tmp /2;
	}

        chance=(extra+tmp)/2;
        
        chance=chance<160? 160-chance:0;
        
        
    if( !target ) target = offensive_target(me);
    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("［计出连环］只能对战斗中的对手使用。\n");
    me->add_temp("apply/attack",tmp);
    me->add_temp("apply/damage",extra/2);
    msg = HIR  "\n\n$N挥出神机刀法中的绝天灭地的一式－－－计－出－连－环－！！\n\n"NOR;
	count = 0;
//    if(chance<random(160))
//    {
        msg+=HIR"\n论战篇！\n$N手中$w直劈$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
//    }
    if(chance<random(160))
    {
        msg = HIY  "胜战篇！\n$N手中$w"+HIY"斜刺$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {    
        msg = HIW  "敌战篇！\n$N手中$w"+HIW"平削$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {        
		msg = HIG  "攻战篇！\n$N手中$w"+HIG"横砍$n！" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {    
        msg = HIM  "混战篇！\n$N手中$w"+HIM"狠剁$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {    
        msg = HIC  "并战篇！\n$N手中$w"+HIC"反撩$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
    if(chance<random(160))
    {       
        msg = HIB  "败战篇！\n$N手中$w"+HIB"划向$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		count++;
    }
//  if(chance<random(160))
//    {    
    msg = HIR  "决战篇！\n$N手中$w"+HIR"加紧，旋风般向$n"+HIR"杀去！" NOR;
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	count++;
//    }
    me->add_temp("apply/attack",-tmp);
    me->add_temp("apply/damage",-extra/2);
    if(count <= 5) n = 3;
    if(count > 5 && count < 8) n = 4;
    if(count == 8) n = 5;
    if(me->query("combat_exp")<=1600000 && n >= 4) n = 3;
    if(me->query_busy()<n) me->start_busy(n);
    return 1;
} 
