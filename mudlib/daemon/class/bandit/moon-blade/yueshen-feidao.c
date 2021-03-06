 // counterattack.c
#include <ansi.h> 
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int cps;
        
        if(me->query("class") != "quest_npc")
		return notify_fail("你不能使用『"HIG"月神飞刀"NOR"』。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『"HIG"月神飞刀"NOR"』只能对战斗中的对手使用。\n");
        if((int) me->query_skill("moon-blade",1) <= 300)
                return notify_fail("你的圆月魔刀还不够精纯，不能发出『"HIG"月神飞刀"NOR"』。\n"); 
        message_vision(HIC"突然间天地昏暗，$N手中的刀锋幻花出淡淡月光，绚烂的光芒中，美丽的月神\n翩翩起舞，美妙的舞姿让人忘却了世间所有的恩恩怨怨。\n"NOR,me,target);
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
				message_vision(HIG "$N被眼前的景象迷惑，呆呆的放下手中的"NOR+weapon->query("name")+HIG"。\n"NOR,target);
				weapon->unequip();
				message_vision(HIG "突然之间，美丽的月神随着$N光芒散去，漫漫月光凝成一道刀锋刺入$n喉咙！！\n"NOR,me,target);
                	} else if( !objectp(weapon) ){
                		message_vision(HIG "$N被眼前的景象迷惑，竟然放慢了进攻速度。\n"NOR,target);
				message_vision(HIG "突然之间，美丽的月神随着$N手中的光芒散去，漫漫月光凝成一道刀锋刺入$n喉咙！！\n"NOR,me,target);
			} else {
				message_vision(HIG "突然之间，美丽的月神随着$N手中的光芒散去，漫漫月光凝成一道刀锋刺入$n喉咙！！\n"NOR,me,target);
			}
			target->set_temp("last_damage_from",me);							
                	target->die();
                }
                else{
                	message_vision(HIR"$N收心凝神，突然发现茫茫的月光中$n的刀锋竟向自己的咽喉刺来！！\n"NOR,target,me);
                	if(objectp(weapon)){
                		weapon->unequip();
                	        message_vision(HIR"千钧一发之疾，$N放下手中兵器，飞纵急退，$n的刀锋擦身而过！！！茫茫刀光让人心神荡漾！！！！\n"NOR,target,me);
                	}
                	else message_vision(HIR"千钧一发之疾，$N飞纵急退，$n的刀锋擦身而过！！！茫茫刀光让人心神荡漾！！！！\n"NOR,target,me);
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
