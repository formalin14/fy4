 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("单峰雄驼", ({ "male camel","camel" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 3);
        set("long", "一匹大漠中常见的单峰骆驼，正在湖边歇息。\n");
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set("int",40);
        set("cor",80);
        set("str",50);
        set("attitude", "peaceful");
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "hoof"}) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
                "骆驼低下头去啃了几口青草，转首打量了你几眼，毫无兴趣。\n",
        }) );
        set("combat_exp", 2000000);
        set_temp("apply/attack", 300);
        set_temp("apply/armor", 100);
        set_temp("apply/dodge",300);
        set_temp("apply/damage",200);
        setup();
        carry_object(__DIR__"obj/an")->wear();
}  
void die(){
        object spouse;
        
        if (spouse=present("female camel",environment(this_object())))
        if (!userp(spouse)) {
                spouse->die_next();
        }
        ::die();
} 
