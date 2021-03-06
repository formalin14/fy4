 // heaven_soldier.c
#include <ansi.h> 
inherit NPC;
object F_boss;
void create()
{       
        set_name( "狼" , ({ "wolf" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "一头双眼泛着绿光，嗷嗷嚎叫的恶狼。\n");
        set("max_kee", 100);
        set("str",50);
        set("cor",50);
        set("limbs", ({ "头部", "身体", "尾巴","爪子" }) );
        set("verbs", ({ "bite","claw"}) );
        set("attitude","heroism");
        set("no_arrest",1);
        set("no_fly",1);         
        set("combat_exp", 200000);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("move", 50); 
        setup();  
} 
 void init()
{       ::init();
        add_action("do_killing", "kill");
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        message("vision",
         name() + "仰天长嚎一声，几个起落消失在苍茫雾色中。\n" , environment(),
                this_object() );
        destruct(this_object());
} 
void setguard(object who, int level)
{
        int i;
        object *enemy;
        set_skill("unarmed", 100 + level+random(level));
        set_skill("parry", 100 + 3*random(level)+3*level);
        set_skill("dodge", 100 + 3*random(level)+3*level);
        set_skill("move", 100 + 3*random(level)+3*level);
        set("str",30+random(level/5)+level/5);
        set("kee",10000+level*30);
        set("max_kee",10000+level*30);
        set("eff_kee",10000+level*30);
        set("sen",10000+level*20);
        set("max_sen",10000+level*20);
        set("eff_sen",10000+level*20);
        set("gin",10000+level*20);
        set("max_gin",10000+level*20);
        set("eff_gin",10000+level*20);
        set("combat_exp", 3000000 + level/3*level*level+random(level/3*level*level)/2);
        enemy = who->query_enemy(); 
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
/*                        message("vision",
         name() + "对"+enemy[i]->name()+"嗷嗷嘶叫着，看来充满了敌意。\n" NOR,
                 environment(), this_object() );*/
                }
        }
        set_leader(who);
        set("possessed",who);
} 
void die()
{
        object boss;
        F_boss = find_living("wolf boss");
        if(environment(F_boss))
        {
           message_vision(HIR"幽灵狼仰天长啸，突然全身又充满了活力！！\n"NOR,this_object());
           "/cmds/imm/full"->main(this_object(),"");
        }
/*        if(objectp(boss=this_object()->query("boss"))){
        	message_vision(HIR"$N仰天长啸，突然全身又充满了活力！！\n"NOR,this_object());
        	"/cmds/imm/full"->main(this_object(),"");
        }*/
        else ::die();
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        object owner;
        owner=me->query("possessed");
        if (!owner) return;
        dam = owner->query_skill("wolf-curse",1);
        victim->receive_wound("kee",random(dam*20), me);
        return;
}      
int do_killing(string arg)
{       
        object player, victim;
        object owner;
        string id;
        if(!arg) return 0;
        player = this_player();
        owner=this_object()->query("possessed");         
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                id = victim->query("id");
                if(id==owner->query("id"))
                {
                	message_vision(RED"$N突然长啸一声，身形一闪，挡在"+owner->name()+"和$n中间！\n"NOR, this_object(),player);
                	this_object()->kill_ob(player);
               		player->kill_ob(this_object());
               		owner->remove_all_killer();
               		return 0;
               	}
               	return 0;
        }
        return 0;
}