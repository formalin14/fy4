 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("盛大娘", ({ "sheng daniang" }) );
        set("nickname",HIR "散花玄女" NOR);
        set("gender", "女性");
        set("age", 65);
        set("long",
"满头银发如丝的盛家庄女主人，昔年人称‘散花玄女’的盛大娘。\n"
); 
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "盛大娘说：我三个媳妇一个接着一个都死在大旗门人的手里，害得我这儿子十余年都不愿再娶亲了。\n",
        }) );
          
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 5); 
        
        set("combat_exp", 3700000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40); 
        set("force", 2000);
        set("max_force",2000);
        set("force_factor", 60);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
         
        set_skill("move", 200);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 150);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);
                
        set_skill("throwing",200);            
        set_skill("hanmei-force", 100);
        set_skill("tanzhi-shentong",160);
        set_skill("anxiang-steps",160);
        set_skill("lingxi-zhi",160);
        
        map_skill("unarmed","lingxi-zhi");
        map_skill("force", "hanmei-force");
        map_skill("throwing","tanzhi-shentong");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
        
        setup(); 
        add_money("gold", random(5));
        carry_object(__DIR__"obj/n_stone")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
   enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1) {
                who->perform_action("throwing.mantianhuayu");
                return;
        }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->is_busy()&& !who->is_busy()) {
                                this_object()->smart_attack();
                        }
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<3*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("throwing.tanzhijinghun");
} 
smart_attack() {
        this_object()->perform_action("throwing.mantianhuayu"); 
        }     
