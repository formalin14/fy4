 // TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        mapping myfam, vtfam;
        int sp, dp; 
        object where = environment(me);
        if ( userp(me) && me->query("class")!="beggar" )
          return notify_fail("只有丐帮弟子才能乞讨！\n"); 
        if( environment(me)->query("no_beg")
                || domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("这里是不适合丐帮弟子讨饭的地方！\n"); 
        if( me->query_temp("begging") )
                return notify_fail("你正在在向别人乞讨了！\n"); 
        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("指令格式：beg <某物> from <某人>\n"); 
        if ( userp(me) && ((int)me->query_skill("begging",1) < 25 || me->query("combat_exp")<10000))
        {
                return notify_fail("你现在还没有能力乞讨。\n");
        } 
        victim = present(who, environment(me)); 
        if( !victim || victim == me) return notify_fail("你想乞讨的对象不在这里。\n"); 
        if( !living(victim) || !objectp(victim))
                return notify_fail("你要向谁乞讨？\n"); 
        if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "丐帮" )
                return notify_fail("你不能向本帮弟子乞讨！\n"); 
        if( !wizardp(me) && wizardp(victim) )
                return notify_fail(victim->name()+"不会施舍给你任何东西的。\n"); 
        if( me->is_fighting() )
                return notify_fail("不可以一边打架一边乞讨！\n"); 
        if( victim->is_fighting() ) 
                return notify_fail(victim->name() + "正在打架，没空理你！\n");
        
        if((int)me->query_skill("begging",1) < 25)
                return notify_fail(victim->name()+"好象不会施舍给你任何东西似的。\n");
        
        if( !ob = present(what, victim) ) {
           object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + "身上看起来没有什麽让你感兴趣的东西。\n");
                ob = inv[random(sizeof(inv))];
        } 
        if ( ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
                return notify_fail(victim->name()+"好象不会施舍给你任何东西似的。\n");
        if(me->query("sen") <= 100 && userp(me))
                return notify_fail("你精神不足，不能乞讨。\n"); 
        if (userp(me)) 
                me->add("sen",-100); 
        sp = (int)me->query_skill("begging",1) * (int)me->query_skill("begging",1) 
     + (int)me->query_kar() * (int)me->query_kar() * (int)me->query_kar() ;
         if(me->query_skill("begging",1)<50)
                sp=sp/3;
        if( sp < 1 ) sp = 1;
        dp = (int)victim->query("bellicosity")-(int)victim->query("score") + 30000;
        tell_object(me, "你一脸可怜巴巴的样子，慢慢地向" + victim->name() + "走过去，伸出双手，想要"
                        + ob->query("unit") + ob->name() +"...\n\n");
        tell_object(victim, me->name() + "一脸可怜相，向你慢慢走过来，伸出手，说道：" + RANK_D->query_respect(victim) + "行行好，给我" 
                        + ob->query("unit") + ob->name() + "吧 ...！\n\n");
        message("vision", "只见" + me->name() + "装出可怜巴巴的样子，慢慢地向" 
                + victim->name() + "走过去，\n伸出双手，说道："
                + RANK_D->query_respect(victim) + "，行行好吧 ...\n\n", environment(me), ({ me, victim }) ); 
        me->set_temp("begging", 1);
        call_out( "compelete_beg",random(3)+1, me, victim, ob, sp, dp); 
        return 1;
} 
private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
        int amount;
        object ob1; 
        me->delete_temp("begging");
        if(!victim) {
                tell_object(me, "太可惜了，你要乞讨的人已经不见了。\n");
                return;
        }
        if( environment(victim) != environment(me) ) {
                tell_object(me, "太可惜了，你要乞讨的人已经走了。\n");
           return;
        }
// exp limit to stop beggar dummies
        if (userp(me) && victim->query("combat_exp")>me->query("combat_exp")*15) {
                tell_object(me,victim->name()+"不屑地看了你一眼说：“再去练练吧。“\n");
                return;
        }
// not a human being    
        if(!victim->query("spi")) {
                tell_object(me,victim->name()+"根本就无动于衷！\n");
                return;
        }
        if( living(victim) && (random(sp+dp) > dp) && ob->move(me)) 
        {
                message_vision("$N看着$n的可怜样，叹了口气，丢给$n一" 
                                + ob->query("unit") + ob->name() + "。\n",victim,me);
                me->start_busy(3);
        } 
        else 
        {
                if( random(sp+dp) > dp/2 ) {
                message_vision("$N扭过头去，对$n理都不理。\n", victim,me);
                me->start_busy(3);
                        return;
                }
                else
                message_vision("$N狠狠地瞪了$n一眼，喝道：穷叫化子！真讨厌！不打不行了！\n", victim,me);
                if(!environment(victim)->query("no_fight"))     
                victim->fight_ob(me);
                me->start_busy(3);
        }
} 
int help(object me)
{
write(@HELP
指令格式 : beg <东西> from <他人>
这是一个丐帮专用的指令。 
HELP
    );
    return 1;
}       
