 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra, myexp, hisexp;
        object weapon, myweapon; 
        if (me->query("class")!="quanli")
                return notify_fail ("［银蛇出动］只有财神庙的兄弟姐妹才能使用。\n");
        extra = me->query_skill("yinshe-stick",1); 
        if ( extra < 100) return notify_fail("你的［银蛇杖法］还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［银蛇出动］只能对战斗中的对手使用。\n"); 
        weapon = target->query_temp("weapon");
        myweapon = me->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        
        if (hisexp>3500000) hisexp=hisexp*3;
        
        if(random(hisexp) < myexp && weapon && random(2))       {
                message_vision(HIW "\n\n$N"+HIW"手中的"NOR+ myweapon->name() +HIW"竟如银蛇一般盘住$n"+HIW"手中的兵刃，$n"+HIW"的"NOR+ weapon->name()+  HIW"脱手而飞！\n\n" NOR, me,target);
                if( weapon->unequip()) 
                        weapon->move(environment(target));
        } else  {
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", extra*2);
                msg = HIW+ "\n\n$N"HIW"一式［银蛇出动］，手中的"NOR+myweapon->name()+HIW"如银蛇般直咬$n"+HIW"的$l！\n\n"+ NOR;
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
           me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra*2);
        }
        if (me->query_busy()<2) me->start_busy(2);
        return 1;
}    
