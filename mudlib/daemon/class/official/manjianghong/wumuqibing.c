 // ice
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target, int amount)
{
        int skill, cor, base, i;
        
        if(me->query("class") != "official")
                return  notify_fail("只有朝廷命官才能指挥［武穆奇兵］！\n");
		if( me->query("family/master_id") != "master yue" )
                return  notify_fail("只有岳少保的弟子才能指挥［武穆奇兵］！\n");
        if ( me->query_skill("manjianghong",1) < 120 )
			return notify_fail("你的『满江红心法』还不够纯熟！\n");
        if (me->query_skill("strategy",1)<200)
                return notify_fail ("你的[兵法]太差了。\n");
        if((int)me->query("timer/wumu") + 20 > time())
                return notify_fail(YEL"你刚刚布过［武穆奇兵］。\n"NOR);
        if( !me->is_fighting() )
                return notify_fail("只能在战斗中布［武穆奇兵］。\n");
        if( (int)me->query("force") < 200 )
                return notify_fail("你的内力不够。\n"); 
                
        if( !target || target==me ) target = offensive_target(me);
        
        skill = me->query_skill("strategy",1);
        me->add("force", -200);
        cor = me->query("cor");
		enemy = me->query_enemy(); 
        message_vision(                
                HIC"\n$N挥动令旗，只见 "+HIR"红 "+HIY"黄 "+HIB"蓝 "+HIW"白"+HIC"四旗色的岳家军布成奇阵，浩浩荡荡，气势磅礴！\n\n"NOR, me); 
		 
        if (userp(target)) base=(int)me->query("combat_exp");
                else base=(int)me->query("combat_exp")*cor/40;
        for (i = 0 ; i< sizeof(enemy); i++) {   
                if( enemy[i]&& enemy[i]->is_character()
                        && me->is_fighting(enemy[i]) )
                
                {       target = enemy[i];        
						if( random(target->query("combat_exp")) > base/2 ) {
							message_vision(CYN"$N"+NOR CYN"镇定自若，一举冲出"+NOR CYN"$n的阵势！\n"NOR, target, me);
						me->set("timer/wumu",time());
						return 1;
						}
						message_vision(HIR"$N"+HIR"被困阵中，左冲右杀无法突围，阵脚大乱！\n\n"NOR,target);
						message_vision(HIR"$N"+HIR"无法突围，累得精疲力尽。\n\n"NOR,target);
						target->receive_damage("gin", skill*cor/15+2*random(skill));
						target->receive_damage("kee", skill*cor/20+2*random(skill));
						target->set_temp("last_damage_from",me);
                        target->apply_condition("wumuqibing",random(3)+2);
						if (!target->is_busy()) target->start_busy(1);
						COMBAT_D->win_lose_check(me,target,1);
						me->set("timer/wumu",time());

				}
		}                                
		if (me->query_busy()<2) me->start_busy(2);
        return 1;
}      