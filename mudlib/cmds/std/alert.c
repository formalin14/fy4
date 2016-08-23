#include <ansi.h>
inherit F_CLEAN_UP;
#define MAX_GUARD 1
int main(object me, string arg)
{
        object soldier;
        string where;
        int strategy,leadership, exp, title;
        if ((string)me->query("class") != "official")
        return notify_fail("你不是朝廷命官，还是自己照顾自己吧！\n");
        
/*      where=file_name(environment(me));
        if (userp(me) && where[0..6]=="/d/cave") 
                return notify_fail("此地已不属官府管辖范围，只能靠你自己的能力了，加油！\n");*/
        
        strategy = (int)me->query_skill("strategy",1);
        leadership = (int)me->query_skill("leadership",1);
        exp = (int)me->query("combat_exp");
        if(strategy < 25 || leadership < 25)
        return notify_fail("你兵法和用人之技太差了，没人愿意理你！\n"); 
        if (exp<10000)
        return notify_fail("你的经验太低了，还不能啸警。\n");
        
        
        if (me->query("marks/官府/岳飞"))
        return notify_fail("关键时刻叫别人替死？岳少保没有这样孬种的徒弟。\n");
        if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");
        if((int)me->query("sen")< 150)
                return notify_fail("你的神太差了！\n");
        if((int)me->query("sen")< 150+(strategy+leadership-200)*3/5)
                return notify_fail("你的神太差了！\n");
        
        if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("以你现在的官位，你已经受到足够的保护！\n");
        
        if ((strategy+leadership)>200)
                me->receive_damage("sen",150+(strategy+leadership-200)*3/5);
                else me->receive_damage("sen",150);
        
           if (random(leadership+strategy) < 13) {
        message_vision(HIB "\n$N发出一声长啸求援！但是什麽也没有发生！\n" NOR, me);   
        return 1;
        } 
        if (leadership+strategy>260 && random(100)<5)
                message_vision(HIB "\n$N发出一声长啸求援！但是什麽也没有发生！\n" NOR, me); 
        else {
                seteuid(getuid());
                soldier= new("/obj/npc/danei_guard");
                soldier->move(environment(me));
                if (leadership>220) leadership = 220;
                if (strategy>200) strategy = 200;
                soldier->invocation(me, (leadership+strategy));
                soldier->set("possessed", me);
                soldier->set_leader(me);
                
                title = leadership+ strategy;
                if (title < 200)
                        soldier->set_name("大内高手",({ "bodyguard" }));
                else if (title<300)
                        soldier->set_name(HIY"御前侍卫"NOR,({ "bodyguard" }));
                else 
                        soldier->set_name(HIR"锦衣卫"NOR,({ "bodyguard" }));
                        
                me->add_temp("max_guard",1);
                me->remove_all_killer();
                message_vision(HIB "\n$N发出一声长啸求援！\n" NOR, me);   
                message_vision(HIB "\n$N应声而来！\n" NOR, soldier);
        } 
        return 1;
} 
int help(object me)
{
        write(@HELP
指令格式：alert
 
这个指令让官员呼唤高手来保护自己。
能否招呼出高手，呼出高手水平的高低就要看官员
官职的大小了。
 
HELP
    );
    return 1;
}    
