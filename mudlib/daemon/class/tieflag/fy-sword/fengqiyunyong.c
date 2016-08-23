#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,mystr,yourstr,lvl;
        object weapon; 
        if (me->query("class")!="tieflag")
                return notify_fail ("非大旗弟子不能使用［风起云涌］\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［风起云涌］只能对战斗中的对手使用。\n");
        weapon = target->query_temp("weapon");
        if(!objectp(weapon)) return notify_fail("你的对手没有用兵器！\n");
        myexp = (int) me->query("combat_exp") / 1000;
        mystr = (int) me->query_str();
        yourexp = (int) target->query("combat_exp") / 1000;
        yourstr = (int) target->query_str();
        lvl = (int) me->query_skill("sword") / 1 + 100;
        msg = YEL "$N以风卷残云之势一挥，$n的兵器不知怎么就落在了地下！ \n" NOR;
if(objectp(weapon) )
{
        if (( myexp * lvl * mystr) > (yourexp * yourstr) )
        {
                weapon->unequip();              
                weapon->move(environment(target));
                message_vision(msg, me, target);
                target->start_busy(1);
        }
        else 
        {
                COMBAT_D->do_attack(target,me, TYPE_PERFORM);
        }
                me->start_busy(2);
}
        return 1;
}      
