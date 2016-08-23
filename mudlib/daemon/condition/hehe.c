 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
        int dam_kee,dam_gin,dam_sen;
        string msg;
        dam_kee = (int) me->query("max_kee")/10;
        dam_gin = (int) me->query("max_gin")/10;
        dam_sen = (int) me->query("max_sen")/10;
        me->receive_wound("kee", dam_kee);
    me->receive_wound("gin", dam_gin);
    me->receive_wound("sen", dam_sen);
        me->apply_condition("hehe", duration - 1);
    if( duration < 1 )
        {
                tell_object(me, HIR "你终于受不了" HIY "阴阳合和散" HIR "的催情作用，全身爆裂而死！\n" NOR );
                message("vision", me->name() + "全身经脉爆裂。\n", environment(me), me); 
                me->die();
        }
        else {
                tell_object( me, HIR "你中的" HIY "阴阳合和散" HIR  "发作了，你觉得全身燥热不已！\n" NOR );
                msg = me->query("gender") == "男性" ? 
                        "头颈赤红发热，赤红的一双眼睛充满了欲望，那眼光象要把你扒光。\n" 
                        : "娇喘微微，面上泛出一层桃花般淡淡的红色，春情难禁，眼中媚波流动，似乎要滴出水来。\n" ;
                message("vision", "只见" + me->name() + msg, environment(me), me);
        } 
        if( duration < 1 ) 
                return 0;
        return 1;
}  
int condition_type()
{
// in condition.h
/* 
#define NO_CURE                 10
#define NON_POISON              9
#define BLOOD_POISON            8
#define NERVE_POISON            7
#define BRAIN_POISON            6
#define OBSCENE_POISON             5
#define GENERIC                 0 
*/ 
        return OBSCENE_POISON;
}
