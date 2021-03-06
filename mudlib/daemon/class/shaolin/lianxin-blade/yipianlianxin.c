 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object friend)
{
        string msg;
        int extra,i,j,k;
        string *style = ({
HIR "$N手中$w突发红光，急劈$n的$l！" NOR,
HIY "$N手中$w突发黄光，直取$n的$l！" NOR,
HIW "$N手中$w突发白光，径砍$n的$l！" NOR,
HIG "$N手中$w突发绿光，平削$n的$l！" NOR,
HIB "$A手中$W和$B手中的$V交织错合，泛出层层黑气，网向$n！" NOR,
});
        object ob,*obs, target;
        object you, *myteam;
        
        if (!friend)
                return notify_fail ("你要和谁一起使用［一片莲心］？\n");        
        if (friend==me)
                return notify_fail ("一片莲心需要与同伴一起使用。\n");
                        
        you=friend;                          
        myteam = me->query_team();
        for(j=0; j<sizeof(myteam); j++) {
                if (myteam[j]==you) 
                                {k=1; 
                                continue;
                                }
                }               
        if (k!=1)
                return notify_fail("同伴必须是与你在同一个队伍中。\n");  
        
        if(!you->query_skill("lianxin-blade",1) || you->query_skill_mapped("blade") != "lianxin-blade") 
                return notify_fail("同伴没有配合的武功。\n");
        if(!objectp(ob=you->query_temp("weapon"))) 
                return notify_fail("同伴没有执刀。\n");
        if(ob->query("skill_type") != "blade")
                return notify_fail("同伴没有执刀。\n");
   if (you->is_busy())
                return notify_fail("同伴正忙着呢。\n");
                        
        target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［一片莲心］只能对战斗中的对手使用。\n");
        
        
        message_vision( HIR "\n\n\n$N和$n的身行突然交织在一起，越转越快！\n" NOR,me,you);
        me->kill_ob(target);
        you->kill_ob(target); 
        msg = style[0];
        extra = me->query_skill("lianxin-blade");
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        
        msg = style[1];
        extra = you->query_skill("lianxin-blade");
        you->add_temp("apply/attack", extra);
        you->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(you,target, TYPE_PERFORM,msg);
        you->add_temp("apply/attack", -extra);
        you->add_temp("apply/damage", -extra);
        
        msg = style[2];
        extra = me->query_skill("lianxin-blade");
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        
        msg = style[3];
        extra = you->query_skill("lianxin-blade");
        you->add_temp("apply/attack", extra);
        you->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(you,target, TYPE_PERFORM,msg);
        you->add_temp("apply/attack", -extra);
        you->add_temp("apply/damage", -extra); 
        style[4] = replace_string(style[i],"$A", me->name());
        style[4] = replace_string(style[i],"$B", you->name());
        style[4] = replace_string(style[i],"$W", (me->query_temp("weapon"))->name());
        style[4] = replace_string(style[i],"$V", (you->query_temp("weapon"))->name());
        extra = me->query_skill("blade");
        extra += you->query_skill("blade");
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,style[4]);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        you->start_busy(3);
        return 1;
}  
