#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        extra = me->query_skill("xuezhan-spear",1);
        tmp = me->query_skill("hawk-steps",1); 

        if(me->query("class")!="fugui")
                return notify_fail("只有富贵山庄弟子才能使出「八方风雨会中州」的绝技。\n");
        if ( extra < 120) 
                return notify_fail("你的血战枪法还不够纯熟！\n");
                
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "hawk-steps")
                return notify_fail("［八方风雨会中州］需要［鲲鹏步法］的配合！\n");
        if ( tmp < 100 )return notify_fail("你的［鲲鹏步法］还不够纯熟！\n");
        
        if ( userp(me) && me->query_skill_mapped("force") != "skyforce")
                return notify_fail("［八方风雨会中州］需要［碧空心法］的配合！\n");
        if ( me->query_skill("skyforce",1) < 100 )return notify_fail("你的［碧空心法］还不够纯熟！\n");
                
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［八方风雨会中州］只能对战斗中的对手使用。\n");
        /*if (me->query_temp("timer/bafang")+10>time())
                return notify_fail("［八方风雨会中州］不能连续使用。\n"); */
        tmp=tmp/2;       
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra*3);
    msg = HIW "\n\n$N大喝一声，漫天矛影中赫然使出『血战枪法』中的雷霆一击『--八方--风雨--会中州--』!!\n\n\n★休门★\n$N手中$w"+HIW"由缓至快向$n"+HIW"刺来！" NOR;
   COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★伤门★\n$N挥舞$w"NOR+HIR",化作漫天矛影,当空刺向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIM  "★杜门★\n$N将$w"NOR+HIM"灌满真力,硬生生便朝$n"NOR+HIM"砸了过来！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIY  "★景门★\n但见$N手中$w"NOR+HIY"幻化出千万条银蛇,漫天攒动,扑向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "★惊门★\n$N将$w"NOR+HIC"舞得虎虎生风,卷起一波又一波滔天巨浪，飞向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIG  "★开门★\n$N奋起神威,手中$w"NOR+HIG"大开大阖,旋风般朝$n"+HIG"袭了过来！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIB  "★生门★\n$N断喝一声,手中$w"NOR+HIB"迅如奔雷快如电掣,当胸捅向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "★死门★\n$w"NOR+HIW"划出一道超出任何世俗之美的弧线,宛如刀刃般划过$n"NOR+HIW"的面门！" NOR;
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra*3);   
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp*2);
        me->add_temp("apply/damage",-extra*6);
        me->set_temp("timer/bafang",time());
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}   
