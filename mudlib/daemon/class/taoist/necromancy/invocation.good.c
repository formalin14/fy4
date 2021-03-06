 // invocation.c
inherit SSERVER;
#define MAX_GUARD 4
int cast(object me, object target)
{
        object soldier;
        int     spells,lvl; 
        if(me->query("class")!="taoist")
                return notify_fail("只有三清宫的弟子才能够使用三清道术。\n");
                    
        spells = me->query_skill("spells");
        if(me->query_skill("necromancy",1) < 20 )
                return notify_fail("你的法术不够高！\n"); 
        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤天将！\n");
        if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("你已经召唤太多天兵鬼卒了！\n"); 
        lvl=me->query_skill("necromancy",1); 
        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
        if( (int)me->query("sen") < 60 )
                return notify_fail("你的精神无法集中！\n"); 
        message_vision("$N喃喃地念了几句咒语。\n", me); 
        if (lvl<130) {
                me->add("mana", -50);
                me->receive_damage("sen", 30);
        } else {
                me->add("mana", -50-(lvl-130));
                me->receive_damage("sen", 30+(lvl-130));
        } 
        if( random(me->query("max_mana")) < 100 ) {
                message("vision", "但是什麽也没有发生。\n", environment(me));
                return 1;
        } 
        seteuid(getuid());
        if( random(spells) > (spells/2))
                soldier = new("/obj/npc/heaven_soldier");
        else
                soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
   spells=spells/5*4;
        if (spells>260) spells=260;     
        soldier->invocation(me, spells);
        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
        me->start_busy(1);
        return 1;
}       
