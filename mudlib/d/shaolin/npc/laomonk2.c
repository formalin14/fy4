 // teacher.c
inherit NPC;
#include <ansi.h>
void restrict_move(); 
void create()
{
        set_name("送菜的老和尚", ({ "old monk", "monk" }) );
        set("nickname",HIW"一尘不染"NOR);
        set("gender", "男性" );
        set("age", 62);
        set("vendetta_mark","shaolin");
        set("int", 30);
        set("cor",30);
        set("cps",60);
        set("str",40+random(20));
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("class","shaolin");
        set("pursuer", 1);
        set("long",
                "在少林寺里打扫卫生的老僧，据说个个是深藏不露的高手。\n"
                );
        set("chat_chance", 1);
        set("chat_msg", ({
                (: restrict_move :)
         }) ); 
        set("attitude", "peaceful");
        set_skill("move", 200);
        set_skill("dodge", 140);
        set_skill("force", 140);
        set_skill("unarmed",140);
        set_skill("puti-steps",140);
        set_skill("dabei-strike",140);
        set_skill("xiaochengforce",140);
        set_skill("yiyangzhi",140);
        set_skill("iron-cloth",100);
        set_skill("yijinjing",100);
           map_skill("iron-cloth","yijinjing");
        map_skill("dodge", "puti-steps");
        map_skill("force", "xiaochengforce");
        map_skill("unarmed", "yiyangzhi");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
          (: perform_action, "unarmed.qiankun" :)
            }) );
        
        set("combat_exp", 4000000);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/ironfist")->wield();
        carry_object(__DIR__"obj/ironfist")->wield();
}  
restrict_move() {
            string where;
            where=file_name(environment(this_object()));
            if (where[0..9]=="/d/shaolin") {
                        this_object()->random_move();
                        }
                else {  message_vision(YEL"老和尚看了看四周，一语不发地离开了。\n"NOR,this_object());
                        this_object()->move("/d/shaolin/lixue");
                }
           }    
                 
