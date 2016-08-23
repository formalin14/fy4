 // ice@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, yourexp,myexp,cpexp;
        extra = me->query_skill("shenji-steps",1);
        if ( userp(me) && extra < 50) 
                return notify_fail("你的［神机步法］还不够纯熟！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［神机妙算］只能对战斗中的对手使用。\n");
                
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
                
        message_vision(HIG"$N"+HIG"身形如闪电，紧紧贴在$n"+HIG"的身后，$n"+HIG"的一举一动，皆在$N"+HIG"的算计之中！\n"NOR,me,target);
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=myexp+(extra*(random(2)+3))+ (5+extra/100)*random(myexp)*(1+random(7))/2;
        if(me->query("class") != "emei" && userp(me)) cpexp=(2+extra/100)*random(myexp)*1/2;
        if(yourexp < cpexp)
        {
        message_vision(HIB"结果$N"+HIB"被攻得大惊失色，手忙脚乱！\n"NOR,target);
        target->start_busy(3);
        }
        else{
        message_vision(HIY"结果$N"+HIY"并不慌张！\n"NOR,target);
        me->start_busy(2);
        }
        return 1;
}       
