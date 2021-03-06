 // teamdrift_sense.c
#include <ansi.h> 
inherit SSERVER;
void move_team(object me,object target);
int conjure(object me, object target)
{
        
        if(me->query("class")!="bonze")
                return notify_fail("只有兴国禅寺的弟子才可以使用游识神通！\n");
        if(!me->query("open_sesame"))
                return notify_fail("你的神通尚缺突破，不能转移他人！\n");
        
        if((int) me->query_skill("essencemagic",1) < 100)
                return notify_fail("你的八识神通不够高深！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中无法使用游识神通！\n");
        if( me->query("atman") < 300 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 100 )
                return notify_fail("你的精不够！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法使用游识神通！\n");         
        write("你要将队伍移动到哪一个人身边？");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
} 
void select_target(object me, string name)
{
        object ob;
        object *team;
        int transported; 
        if( !name || name=="" ) {
                write("中止施法。\n");
                return;
        } 
        
        ob = find_living(name);
        if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)
        || !ob->query("max_atman") || !ob->query("atman") ||userp(ob)
// the following check start/arrival room.      
   || environment(ob)->query("no_death_penalty")
        || environment(me)->query("no_fly")
        || environment(ob)->query("no_fly")
        || domain_file(file_name(environment(ob)))=="eren2"
// the following is the NEW FLY FLAG, all NPCs are non-driftable by default.    
        || !ob->query("fly_target")
        ) {
                write("你无法感受到这个人的灵力 ....\n");
                write("你要移动到哪一个人身边？");
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        if( me->is_fighting() ) {
                write("战斗中无法使用游识神通！\n");
                return;
        } else if( me->query("atman") < 100 ) {
                write("你的灵力不够！\n");
                return;
        } 
        me->add("atman", -100);
        me->receive_damage("gin", 50);
        
        message_vision( HIY "$N低头闭目，开始施展游识神通 ....\n" NOR, me);
        if( random(ob->query("max_atman")) < (int)me->query("atman")/5) {
                write("你感受到对方的灵力，但是不够强烈。\n");
                return;
        }
        if( random(80) > me->query_skill("essencemagic",1)){
                write("你因为不够熟练而失败了。\n");
                return;
        }
        if(environment(ob)->query("no_magic")||environment(ob)->query("no_fly")) {
                write("你想要游识的地方不可以用神通！\n");
                return;
        }
        if(environment(ob)==environment(me)) {
                write("你已经在这里了！\n");
                return;
        }       
        message( "vision", HIY "\n一道耀眼的光芒忽然罩住" + me->name() 
           + "，几秒钟後，光芒和人一齐消失得无影无踪！\n\n" NOR, environment(me), ({ me }) );
        
        // -> team transport here
        transported = 1;
        if( pointerp(team = me->query_team()) ) {
                for (int i=0; i<sizeof(team); i++) {
                        if (!team[i]) continue;
                        if (team[i] == me) continue;
                /*      if(environment(team[i])->query("no_magic")) {
                                write(team[i]->name()+"所在的地方无法感受你的游识！\n");
                                continue;
                        } 
                */
                        if ( environment(team[i]) != environment(me)) continue;
                        if( !team[i] ||( !me->visible(team[i]))
                        || !team[i]->query("max_atman") || !team[i]->query("atman")
                        || domain_file(file_name(environment(team[i])))=="eren2"
                        ) {
                                write("你无法感受到"+team[i]->name()+"的灵力 ....\n");
                                continue;
                        }
                        if (team[i]->is_ghost()){
                        	tell_object(team[i],"你受到"+me->name()+"的心灵感应，但是你现在还是鬼魂，无法回应。\n");
                        	continue;
                        }
                        
                        if (team[i]->is_busy() ||team[i]->is_fighting() ) {
                                tell_object(team[i],"你受到"+me->name()+"的心灵感召，但是你现在正在忙，无法回应。\n");
                                tell_object(me, YEL"\n" + team[i]->name()+"似乎没有空闲来回应你的游识感应。\n"NOR);
                                continue;
                        }  
                        message_vision(HIY"忽然间一片耀眼光芒浮动在$N周围。。。\n\n"NOR,team[i]);       
                        //team[i]->move(environment(ob));
                        team[i]->start_busy(4);
                        call_out("move_team",2, me,team[i]);            
                        transported++;
                }
        }
        me->move(environment(ob));
        message( "vision", HIY "\n你的眼前耀眼的光芒浮动，光芒中现出"+ chinese_number(transported)+ "个人影！\n\n" NOR,
                environment(ob), ({ me }) );
}  
void move_team(object me,object target){ 
        message_vision(HIY"$N受到"+me->name()+"的心灵感召，顿时如虚空凌度，已到了另外一个地方。\n"NOR,target);  
        tell_object(me, target->name()+"已应你感召，游识而来。\n");     
   target->move(environment(me));
}
