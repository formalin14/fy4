 // heaven_soldier.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        string *order = ({"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"}); 
        set_name("天" + (order[random(10)]) + "神兵", ({ "heaven soldier", "heavensoldier" }) );
        set("long", "这是一位来自天界的守护神，专门担任护法之责。\n");
        set("attitude", "friendly"); 
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000); 
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("no_fly",1);
        set("no_arrest",1); 
        set("str", 40);
        set("cor", 30);
        set("cps", 25); 
        set("combat_exp", 100000); 
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 70);
        set_skill("five-steps",70);
        set_skill("three-sword",70);
        map_skill("sword","three-sword");
        map_skill("parry","three-sword");
        map_skill("dodge","five-steps");
        setup(); 
        carry_object(__DIR__"obj/golden_armor")->wear();
        carry_object(__DIR__"obj/golden_sword")->wield();
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
        object *pros,owner;
        
        message("vision",
                HIY + name() + "说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
                + name() + "化成一道金光，冲上天际消失不见了。\n" NOR, environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("max_guard",-1);                
                pros = owner->query_temp("protectors");
                pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        destruct(this_object());
} 
void invocation(object who, int level)
{
        int i, bonus_skill;
        object *enemy,*pros;
        
        set("str",10+level/16+random(level/16));
        set("agi",10+level/10);
        set("cor",15+random(level/12));
        
        set("max_kee",300+random(level*level/60));
        set("eff_kee",query("max_kee"));
        set("kee",query("max_kee"));
        set("max_gin",query("max_kee")/2);
        set("gin",query("max_kee")/2);
        set("eff_gin",query("max_kee")/2);
        set("max_sen",query("max_kee")/2);
        set("eff_sen",query("max_kee")/2);
        set("sen",query("max_kee")/2);
        
        
   set("max_force",500+random(level*level/200));
        set("force",query("max_force"));
        
        bonus_skill = 50 + level/4 + random(level/4);
        set_skill("sword", 50 + level/4 + random(level/4));
        set_skill("parry", 50 + level/4 + random(level/4));
        set_skill("dodge", 50 + level/4 + random(level/4));
        set_skill("move", 50 + level/4 + random(level/4));
        set_skill("five-steps",20 + level/4 + random(level/4));
        set_skill("three-sword",20 + level/4 + random(level/4));
        
        set("combat_exp", 20000 + level/8*level*level/2+random(level/8*level*level/2));   
        pros = who->query_temp("protectors");
        if(sizeof(pros))
                pros += ({ this_object() });
        else
                pros = ({ this_object() });
        who->set_temp("protectors",pros);
        message("vision",
                HIY "一道金光由天而降，金光中走出一个身穿金色战袍的将官。\n\n"
                + name() + "说道：末将奉法主召唤，特来护法！\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
        set("possessed",who);
}
void die()
{
        int i;
        object owner, *enemy,*pros;
        if(objectp(owner=query("possessed")))
        {
        pros = owner->query_temp("protectors");
        pros -= ({ this_object() });
        owner->set_temp("protectors",pros);             
        enemy = query_enemy();
                owner->add_temp("max_guard",-1);        
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        } 
        }
        ::die(); 
} 
void heart_beat()
{
        object leader;
        
        ::heart_beat();
        
        if(query_temp("is_unconcious")||is_busy())
                return ;
        if(query("possessed"))
        {
                leader=query("possessed");
                if(environment(leader)!=environment()&&(!leader->is_ghost()))
                {
                        message_vision("$N匆匆离去。\n",this_object());
                        this_object()->move(environment(leader));
                        message_vision("$N走了过来。\n",this_object());
                        delete("leave_room");
                }
        }
        
        else
        {
                if(!query("leave_room"))
                        set("leave_room",1);
                else
                   add("leave_room",1);
                if(query("leave_room")==5)
                        leave();
        }
}       
