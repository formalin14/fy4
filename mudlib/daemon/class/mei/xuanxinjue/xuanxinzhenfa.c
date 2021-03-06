 // SFY@FY4
//mod by ice@fy4
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    string msg;
    int extra, myexp, yourexp, cpexp, busy;

    if(me->query("class")!="mei")
        return notify_fail("只有松谷庵的圣女才能运用玄心奥妙决。\n");
    if( me->query_skill("xuanxinjue", 1) < 70 )
        return notify_fail("你的玄心奥妙决不够高！\n");
    
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［玄心正法］只能对战斗中的对手使用。\n");
    if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n"); 
    if((int)me->query("mana") < 80 )
        return notify_fail("你的法力不够！\n"); 
    if((int)me->query("sen") <= 50 )
        return notify_fail("你的精神没有办法有效集中！\n"); 
    me->add("mana", -80);
    me->receive_damage("sen", 50);
    
    msg = HIW "\n$N"HIW"大喝一声：【天-地-无-极  玄-心-正-法】！ 一股奇异的劲气向$n"HIW"射来。\n"NOR ;
    
    extra = me->query_skill("spells");
	myexp = me->query("combat_exp");
    cpexp=myexp+ random(myexp/7) + random((extra-70)*extra/7*extra+7);
    //cpexp=myexp/2 + (2+extra/120)*random(myexp)/2;
    yourexp = target->query("combat_exp");

    if( cpexp > yourexp) {
        msg +=HIC"$n"HIC"刚欲移动，一股奇异的劲气，已封死移路，$n"HIC"登时动弹不得！\n";
		message_vision(msg+NOR, me, target);
		busy = target->query("no_busy");
		target->delete("no_busy");
        target->start_busy(30);
		if(busy) target->set("no_busy", busy);
        target->start_call_out( (: call_other, __FILE__, "remove_effect",target :), 3+extra/100);
     } else  {
		 msg += YEL"但是被$n"NOR YEL"躲开了。\n";
		 message_vision(msg+NOR, me, target);
		 if(me->query_busy()<2) me->start_busy(2);
	 }
    return 1;
} 
 
void remove_effect(object target)
{
        message_vision(HIR "\n$N"HIR"终于从无形的劲气中挣扎出来！\n" NOR, target);
		target->stop_busy();
}      