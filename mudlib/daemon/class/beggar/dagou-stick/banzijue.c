 //neon@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, myexp, enemyexp, lvl;
        object weapon; 
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("［绊字诀］只传授给丐帮弟子！\n");
        
        if((int)me->query_skill("dagou-stick",1) < 60)
                return notify_fail("你的打狗棒法还不够熟练！\n");       
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［绊字诀］只能对战斗中的对手使用。\n"); 
        weapon = me->query_temp("weapon");
        
        lvl = (int) me->query_skill("dagou-stick",1);
        if (me->query("force")<lvl/2+10)        
                return notify_fail("你的内力不够。\n");
        extra = me->query_skill("staff");
        myexp = (int) me->query("combat_exp");
        enemyexp= (int) target->query("combat_exp");
        
        msg = HIY"\n$N"+HIY"看准$n"+HIY"步法的破绽，手中"+ weapon->name() + HIY"如蜻蜓点水般连续击向$n"+HIY"下盘。\n" NOR;
        
        if (target->query("disable_type")&& target->query("is_unconcious")) {
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                return 1;
        }
        else message_vision(msg,me,target); 
        if (myexp/3 + random(myexp/80*extra) > enemyexp) {
                msg = HIG"\n只见"+ weapon->name() + HIG"点在地下，轻轻弹起，$n"HIG"似乎是一步赶来凑上去一样。\n"
                        HIR+ weapon->name()+HIR"“啪”的一声，狠狠敲在$n"HIR"胫骨上！"NOR"\n\n"
                   WHT"随着长声惨叫，$n扑通一下倒在地上！\n\n"NOR;
                if (me->query("cps")<random(target->query("cps")*3)) {
                        msg +=CYN"$N看着$n疼得在地上打滚，笑得腰都直不起来，\n上气不接下气地说：“怪不得狗腿需要比人腿多两条！”\n"NOR;
                        me->start_busy(3);
                }
                else me->start_busy(2);
                if (userp(me))  me->add("force",-lvl/2);
                //Beat down enemy
                target->start_busy(3);
                target->receive_wound("kee", extra+random(extra*2), me);
                call_out("get_up",3, me,target);
                message_vision(msg,me,target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
                        
        }
        else {
                me->add_temp("apply/attack", extra/2);
                me->add_temp("apply/damage", extra/2);
                msg = HIR"\n眼见$n迅速变换步法，$N只好招式突换，一棍随手挥出！\n"NOR;
//              me->set_temp("dagou/pfm",1);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
//              me->delete_temp("dagou/pfm",1);
                me->add_temp("apply/attack", -extra/2);
                me->add_temp("apply/damage", -extra/2);
                me->start_busy(2);
        }
        return 1;
} 
void get_up(object me,object target){
        
        if(!target||!living(target)||target->is_ghost())
                return ;
        message_vision(YEL "\n\n$N在地上打了几个滚，忍着疼痛狼狈不堪地爬了起来！！\n\n" NOR, target);
        
}     
