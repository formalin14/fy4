#include <ansi.h>
string damage_message = ""; 
int exert(object me, object target)
{
        int skill, extra;
        
        skill=me->query_skill("wolf-force",1);
        extra= me->query_skill("summonwolf",1);
    
        if (me->query("class")!="wolfmount")
                return notify_fail("只有狼山弟子才能使用『天狼吞月』。\n");             
        
        if (extra<100)  return notify_fail("你的唤狼之术不够高深。\n");
        if (skill<100)  return notify_fail("你的天狼心法不够高深。\n");
        
        if(me->query_temp("wolfbuff/shiri")+60>time())
                return notify_fail("『天狼嗜日』不能连续施展！！\n");
        if( me->is_fighting())
                return notify_fail(HIR "你自己还在战斗中，无法分心使出『天狼嗜日』！\n"NOR);
        if( (int)me->query("force")< 100)
                return notify_fail("你的真气不够。\n");
        if( target->query("id") != "wolf" )
                return notify_fail(target->query("name")+"不是狼，不能使用『天狼嗜日』。\n");   
        if( me != target->query("possessed") )
                return notify_fail("这头狼不是你的，你的『天狼嗜日』无法激发其血气。\n");
        if( !target->is_fighting())
                return notify_fail(HIR "你只能在狼战斗中使用『天狼嗜日』。\n"NOR);
        if( target->query_temp("is_unconcious"))
                return notify_fail( target->name() + "已经昏迷，经不起『天狼嗜日』！\n");
        if (target->query("wolfbuff"))
                return notify_fail("你已经在这头狼身上下过天狼心法了。\n");
        
        message_vision(
                RED "$N深吸一口气将手掌搭在$n"NOR+RED"背心，一片淡淡的红光从$N手中透出....\n\n"NOR+
                HIR"$n"+HIR"原本莹绿的双眼变的滴血似通红，闪着妖异的光芒，忽地嘶嚎一声，天地为之颤栗！\n" NOR,
                me, target );
        
        target->start_call_out( (: call_other, __FILE__, "remove_shiri",target:),
                                skill);
                
   target->set("wolfbuff/shiri",1);
        target->set("combat_exp",me->query("combat_exp"));
        target->set_temp("apply/parry",me->query_skill("parry"));
        target->set_temp("apply/attack",me->query_skill("unarmed"));
        target->set("str",me->query("str")+me->query_skill("force")/9); 
        me->add("force",-100);
        me->set_temp("wolfbuff/shiri",time());
        me->start_busy(2);
        return 1;
} 
void remove_shiri(object wolf)
{
        wolf->delete("wolfbuff/shiri");
        message_vision(HIR "\n\n$N"HIR"周身颤抖了几下，化作一团红炎消失了。\n", wolf);
        wolf->die();
}    
