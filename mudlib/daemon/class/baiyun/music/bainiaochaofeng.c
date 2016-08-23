#include <ansi.h>
inherit SSERVER; 
int conjure(object me, object target)
{       int damage,myexp,yourexp,cpexp,lvl;
        string msg;
    //add qin check here ->
    
    //<-
//    if( me->is_fighting() )
//        return notify_fail("「百鸟朝凤」不能在战斗演奏。\n"); 
/*
play 百鸟朝凤（play bainiaochaofeng) （60 lev music，耗心神100点，需隔1分钟 
才能反复使用) 
CYN你轻拨琴弦，琴声清丽，平正中和，隐隐有王者之意，忽听得空中振翼之声大作，各处飞 
来无数雀鸟，或止歇树巅，或上下翱翔，毛羽缤纷，蔚为奇观。 
GRN碧空中一只青鸟来回盘旋了几下，叼了一颗灵草丢在你身上，清啼一声，飞了开去。 
*/
		lvl = me->query_skill("music",1);
        if(lvl < 100)
                return notify_fail("你的琴道不够高！\n");
               
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「百鸟朝凤」只能在战斗中演奏。\n"); 
        if((int)me->query("gin") <= 50 )
                return notify_fail("你的精力不够！\n"); 
        if((int)me->query("atman") < 50 )
                return notify_fail("你的灵力不够！\n");

		me->receive_damage("gin", 50);
        me->add("atman",-50);
/*        if( random(me->query("max_atman")) < 200 ) {
                write(CYN"你失败了！\n"NOR);
                return 1;
        }*/
        msg = HIC "\n$N"+HIC"轻拨琴弦，琴声清丽，平正中和，隐隐有王者之意！\n" NOR;
		msg += HIC "忽听得空中振翼之声大作，各处飞来无数雀鸟，或止歇树巅，或上下翱翔，毛羽缤纷，蔚为奇观。\n\n"NOR;
        message_vision(msg, me);
		if( target->query("big_boss") || me->query_skill("music") < random(target->query_skill("perception")) * 5/2) {
			message_vision(HIR"但是$N"+HIR"听声辨位，反而直击$n的脉门！\n"NOR, target,me);
			if(!me->is_busy()) me->start_busy(1);
			return 1;
		}

        damage = me->query_skill("magic")*2;
        damage = damage + random(damage);
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=myexp/2+ (4+lvl/100)*random(myexp)/2;
		if(yourexp>5000000) yourexp = yourexp*1.3;

        if( target->query_busy() ) {
                message_vision(CYN "空中忽然冲下一只青鸟狠狠啄向$N"NOR CYN"，继而振翼盘旋离去！\n" NOR, target);
				if(random((int)me->query_skill("magic")) > 50) {
                target->receive_damage("sen", damage, me);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
				}
				else message_vision(HIR "但是$N"HIR"一个箭步蹿开丈许，躲开了这一击！\n" NOR, target);
		} else if (yourexp < cpexp) {
            message_vision(HIY"一阵鸟凤和鸾的琴音，令$N"+HIY"痛苦地捂着双耳，脚步漂浮，神智亦开始变得迷糊。\n"NOR, target); 
			target->receive_damage("sen", damage/10, me);
            target->start_busy(3+random(lvl/50));
		}
		else {
			message_vision(HIG"但是$N"HIG"自己沉迷在音乐之中，忘记了战斗！\n"NOR, me);
		}			
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
}      
