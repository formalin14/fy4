 inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu(); 
void create()
{
        set_name("西门风", ({ "ximen feng" }) );
        set("gender", "男性");
        set("age", 65);
        set("long",
"这位号称软功天下第一的武林名人在冷冷瞧着你，眼神中
带着惊讶，也带着怜悯。。\n" );
        set("inquiry", ([
            "俞独鹤" : (: kill_him :),
             "俞放鹤" : (: fanghe :),
              "俞佩玉" : (: peiyu :),
   ]));
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "西门风笑道：“先天无极门的威名，岂是你这小辈可以想象的！”\n",
                "西门风道：好茶呀好茶！\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIY"茅山"NOR);
        set("nickname",HIY"西门无骨"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",10);
        set("class","lama");
        
        set("combat_exp", 2500000);        
        set("int", 40);
        set("cps", 20);
        set("spi", 30);
        set("fle",100);
        
        set("force", 2000);
        set("max_force",2000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action("unarmed.fefawubian") :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);
                
          
        set_skill("bloodystrike", 200);
        set_skill("iron-cloth",1000);
        
        map_skill("unarmed","bloodystrike");
        map_skill("iron-cloth","xisui");
        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
        carry_object("/obj/armor/cloth")->wear();
} 
 
int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你知道得真不少！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
int fanghe()
{
    command( "say 放鹤兄是我先天无极门的掌门人。");     
    return 1;
}  
int peiyu()
{
    command ("say 这小子是我义兄不成材的儿子。");
    return 1;
}     
