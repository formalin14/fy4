 // modified from tie
// -by foxgirl@fengyun.com 
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
    int skill;
    int duration;
    
    if (me->query("class") != "huashan") return notify_fail("只有华山弟子可以使用「冰纨天障」。\n");
    if(!target) target=me;
    else if( target != me )
        return notify_fail("你只能将［冰纨天障］用在自己的身上。\n");
    if( (string)me->query("gender") != "女性" )
        return notify_fail("你一个大男人居然学来了这样扭扭捏捏的功夫，也好意思用？。\n");
    if( (int)me->query("force") < 100 )
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("daoqian") )
        return notify_fail("你已经在施展［冰纨天障］了。\n");
    skill = me->query_skill("spring-water",1);
    if(skill < 50) 
        return notify_fail("你的春水罗衫太差了！\n");
    skill = random(skill/4)+skill/2;
    me->add("force", -100);
    message_vision( HIY
"$N凝眉低首，运起［冰纨天障］，身上衣衫如春水涟波，无风自动。\n" NOR, me);
    message_vision( HIG
"似乎有一层离合的微光淡淡笼上$N周围．．．\n" NOR, me);
    me->add_temp("apply/iron-cloth", skill);
    me->set_temp("daoqian", 1);
    
    if (me->query("combat_exp")<2500000)        duration = skill;
        else if (me->query("combat_exp")<3500000)       duration=3*skill/2;
                else duration =skill*2;
                
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
                         skill :), duration);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
} 
void remove_effect(object me, int amount)
{
    me->add_temp("apply/iron-cloth", - amount);
    me->delete_temp("daoqian");
    tell_object(me, "你的［冰纨天障］的功效散光了。\n");
}       
