 // heart_sense.c
// silencer@fy4 -------- this is the revive skill ------------ 
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        int skill,exp_recovered,pot_recovered;
        int extra,i,my_score,his_exp,my_loss;
        object *inv;
        
//      if(me->query("class")!="bonze")
//              return notify_fail("只有兴国禅寺的弟子才可以使用八识神通！\n");
        if((int) me->query_skill("essencemagic",1) < 150)
                return notify_fail("你的八识神通不够高深！");
        if ((int)me->query("score")<20000)
                return notify_fail("你的评价不够高(20000)。\n");
        if( !target || !target->is_character() ||target->is_corpse())
                return notify_fail("你要对谁使用心识神通？\n");
        if( !target->is_ghost())
                return notify_fail("心识神通不能用在活人身上。\n");
        my_score=me->query("score");
        his_exp=target->query("combat_exp");
        if (his_exp<500000) my_loss=0;
                else my_loss=(int)his_exp/5000;         
        if (target==me && me->query("combat_exp")>5000000) my_loss=5000;
        if( !userp(target))
                return notify_fail("此神通只能用在玩家身上。\n");       
        if( (int)target->query("death/time")+ 10800  < time())
                return notify_fail("太晚了，他的肉身已经消失，救不活了。（死亡时间需在三小时内）\n");
        if( (int)me->query("atman") < 500 ) 
                return notify_fail("你的灵力不够！\n");
        if( me->query("sen") <= 10 )
                return notify_fail("你的神不够！\n");
        if (!target->query("env/revive"))
                return notify_fail("此人不愿意被人施心识神通。（需要对方Set revive 1）\n"); 
                
        me->add("atman", -500);
        me->receive_damage("sen", 5);
                
        exp_recovered=target->query("death/exp_lost");
   pot_recovered=target->query("death/pot_lost");
        
        
        inv = all_inventory(this_player());
        for(i=0;i<sizeof(inv);i++) {
                if (inv[i]->query("id")=="sacrifice pill")
                {
                destruct(inv[i]);
                message_vision(HIY"$N暗运内力,"NOR+HIR"舍身丹"NOR+HIY"在掌心渐渐融化.\n"NOR,me);
                extra=140;
                break;
                }
        }
        skill = me->query_skill("essencemagic",1);
        if (skill>200) skill=200;  // cap the skill, prevent overflow
        
        exp_recovered=(int)(exp_recovered*(skill+extra)/400);
        pot_recovered=(int)(pot_recovered*(skill+extra)/400);
                        
        if(me->query("class")!="bonze") {
                exp_recovered = (int)(exp_recovered/2);
                pot_recovered = (int)(pot_recovered/2);
        }
        
        me->add("score",-my_loss);
        
        message_vision( HIY "$N一手放在$n的天灵盖上, 一手贴在$n的后心, 闭上眼睛缓缓低吟...\n" NOR, me, target);
        target->add("combat_exp", exp_recovered);
        target->add("potential", pot_recovered);
        target->set("death/time",0);
        target->set("death/exp_lost",0);
        target->set("death/pot_lost",0);
        target->reincarnate();
        message_vision( HIW "$N浑身剧烈地颤抖着，忽然，一道光芒注入$N的顶门。\n",target);
        message_vision( HIW "光芒越来越强烈。。。。\n",target);
        message_vision( HIR "$N复活了！！\n"NOR,target);
        me->start_busy(3);
        return 1;
}   
/*int conjure(object me, object target)
{ 
        if(me->query("class")!="bonze")
                return notify_fail("只有兴国禅寺的弟子才可以使用八识神通！\n"); 
        if( !target || !target->is_character() )
                return notify_fail("你要对谁使用心识神通？\n");
        if( target->is_corpse() )
                return notify_fail("来不及了，只有活人才能救醒。\n");
        if((int) me->query_skill("essencemagic",1) < 80)
                return notify_fail("你的八识神通不够高深！");
        if( (int)me->query("atman") < 50 ) return notify_fail("你的灵力不够！\n");
        if( me->query("sen") <= 30 )
                return notify_fail("你的神不够！\n");
        me->add("atman", -50);
        me->receive_damage("sen", 30);
        message_vision( HIY "$N一手放在$n的天灵盖上, 一手贴在$n的后心, 闭上眼睛缓缓低吟...\n" NOR, me, target);
        if( random(me->query("max_atman")) > 100 )
                target->revive();
        else
                me->unconcious();
        if( me->is_fighting() )
                me->start_busy(3);
        return 1;
}*/    
