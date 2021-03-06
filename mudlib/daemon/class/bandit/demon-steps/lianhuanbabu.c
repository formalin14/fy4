 // ice@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp, extra, bonus;
        extra = me->query_skill("demon-steps",1);
		bonus = me->query_skill("demon-force",1);
        if ( extra < 30) return notify_fail("你的［如意人魔连环八步］还不够纯熟！\n");
        if (( extra > 160)&& me->query("bellicosity")< 1000 && userp(me) ) return notify_fail("你的杀气不够高。需要一千杀气。\n");
        if ((extra > 100)&&(extra <= 160)&& me->query("bellicosity")< 800 && userp(me) ) return notify_fail("你的杀气不够高。需要八百杀气。\n");
        if (( extra <= 100)&& me->query("bellicosity")< 400 && userp(me) ) return notify_fail("你的杀气不够高。需要四百杀气。\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［连环八步］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");

        message_vision(HIB"\n$N"+HIB"将［如意人魔连环八步］六十四式连续施展，围着$n"+HIB"转个不停！\n"NOR, me, target);
		myexp = (me->query("combat_exp")/50)*(extra/50)+(random(me->query("combat_exp") / 50)*extra);
		if( me->query("class")=="bandit" && me->query_skill_mapped("force") == "demon-force" && extra >100 && bonus> 100 ) {
			message_vision(HIB"$N"+HIB"催动真气，身形愈闪愈快！\n"NOR, me);
			myexp = (me->query("combat_exp")/50)*extra+ (random(me->query("combat_exp"))/ 80) * bonus+extra*bonus;
		}

        if( myexp*2/3+random(myexp/3) > target->query("combat_exp") )
        {
        message_vision(HIW"$N"+HIW"被扰得手忙脚乱，破绽百出！\n"NOR, target);
        target->start_busy(3);
        }
        else{
        message_vision(BLU"但是$N"+NOR BLU"以静制动，并不慌乱！\n"NOR, target);
        me->start_busy(2);
		}
        return 1;
}   
