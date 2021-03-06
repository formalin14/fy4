#include <ansi.h>
inherit NPC;
//void backattack();
void create()
{ 
        set_name("侍卫", ({ "huwei"}) );
        set("long", "撼山易，撼岳家军难，这些个血战沙场的精兵儿郎，俱是精忠 
报国，慷慨赴死之辈。。\n");
        set("attitude", "friendly");
        set("title",HIY"岳家军"NOR);
        set("nickname",HIG"精忠报国"NOR);
        set("max_atman", 300);
        set("atman", 300);
        set("max_mana", 300);
        set("mana", 300);
        set("no_fly",1);
        set("no_arrest",1);
        set("combat_exp", 100000);
        set_skill("blade", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 70);
        set_skill("fall-steps",70);
        set_skill("shortsong-blade",70);
        set_skill("spear",70);
        set_skill("hammer",70);
        set_skill("yue-spear",70);
        set_skill("liuxing-hammer",70);
        set_skill("unarmed",70);
        set_skill("yue-strike",70);
        
        map_skill("unarmed","yue-strike");
        map_skill("hammer","liuxing-hammer");
        map_skill("spear","yue-spear");
        map_skill("blade","shortsong-blade");
        map_skill("parry","yue-spear");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps"); 
         set("chat_chance_combat", 100);
            set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng"  :),
            }) );
        setup();
        carry_object("/obj/armor/armor")->wear();
} 
void leave()
{
        object owner,*pros;
        message("vision",
                 name() + "闪了闪就消失不见了。\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        destruct(this_object());
}  
void init()
{
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        add_action("do_kill","kill");
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
int do_kill(string arg)
{
        object victim,who;
        
        who=this_player();
        if(!arg) return 0;
        if(environment()->query("no_fight"))
                return 0;
        victim=present(arg,environment());
        if(!victim) return 0;
        if( !victim->is_character() || victim->is_corpse() )
                return 0;
        if(victim==who) return 0;
        if(victim->query("possessed")==who && victim->query("id")=="huwei")
        {
                tell_object(who,"你不能杀自己的护卫，否则部下会离心离德的。\n");
                return 1;
        }
        if(victim==query("possessed")||victim->query("possessed")==query("possessed"))
        if(who->query("vendetta_mark")!="authority")
        {
                message_vision("$N喝道：“大胆匪徒，竟然敢加害朝廷命官！！”\n",this_object());
                kill_ob(who);
        }
        if(who==query("possessed")&&victim->query("vendetta_mark")!="authority")
        {
                message_vision("$N对"+victim->query("name")+"喝道：“大胆匪徒，还不速速束手就擒？”\n",this_object());
                kill_ob(victim);
   }
        return 0;
} 
string *lname = ({"张小宪","杨小兴","陆小龙","严小方","何小庆","狄小雷",
    }); 
void invocation(object who, int level)
{
        int i, exp;
        object *enemy,*pros;
        
        i=random(sizeof(lname));
        set_name(lname[i],({ "huwei"}) );
        set("str",10+random(level/12));
        set("agi",10+random(level/8));
        set("cor",20+random(15));
        
        set("max_kee",2500+random(level*level/40));
        set("eff_kee",query("max_kee"));
        set("kee",query("max_kee"));
                
        set_skill("parry", 100 + random(level/2));
        set_skill("dodge", 100 + random(level/2));
        set_skill("move", 100 + random(level/2));
        set_skill("fall-steps",200+random(level/2));
        set_skill("unarmed",100+ random(level/2));
        set_skill("yue-strike",200+random(level/8));
        
        if (i<3) {
                set_skill("spear", 100 + random(level/2));
                set_skill("yue-spear",50+random(level/8));
                map_skill("parry","yue-spear");
                carry_object("/obj/npc/obj/steel_spear")->wield();
        } else {
                set_skill("hammer", 100 + random(level/2));
                set_skill("liuxing-hammer",200+random(level/5));
                map_skill("parry","liuxing-hammer");
                carry_object("/obj/npc/obj/steel_hammer")->wield();
        }
        
        set("combat_exp", 100000 + level*level*10+random(level*level*level/10));
   set("max_force",4000);
        set("force",query("max_force"));
        set("force_factor",50+random(level/5));
        set("possessed",who);
        pros = who->query_temp("protectors");
        if(sizeof(pros))
                pros += ({ this_object() });
        else
                pros = ({ this_object() });
        who->set_temp("protectors",pros);
} 
void die()
{
        object owner,*pros;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        ::die();
}  
int attack()
{
        object opponent,owner;
        int exp,extra;          
        opponent = select_opponent();
        if(objectp(opponent)) {
                set_temp("last_opponent", opponent);
        owner=query("possessed");
        if(opponent==owner)
        {
                this_object()->ccommand("ah");
                message_vision("$N对$n说道：“不知是大人，小将刚才多多冒犯了，还请大人恕罪。”\n",this_object(),owner);
                this_object()->ccommand("escape");
                leave();
                return 1;
        }
        COMBAT_D->fight(this_object(), opponent);
        return 1;
        } else
                return 0;
}     
