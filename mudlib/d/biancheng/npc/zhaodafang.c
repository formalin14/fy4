#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("赵大方",({"zhao dafang","zhao","dafang"}));
//      set("title","绿林好汉");
        set("long","一个穿着孝服的男人。他哭得很伤心。他将桌上的纸人纸马纸刀拿下，点起了火，眼睛里还在流
泪。\n");
        set("gender","男性");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
    set("class","wudang");
    set_skill("literate", 140);
    set_skill("force", 150);
    set_skill("move", 150);
    set_skill("unarmed", 130);
    set_skill("sword", 200);
    set_skill("parry", 220);
    set_skill("dodge", 160);
    set_skill("changelaw", 180);
    set_skill("three-sword", 160);
    set_skill("taijiforce", 200);
    set_skill("taiji", 150);
    set_skill("foreknowledge",120);
    set_skill("five-steps", 180);
    set_skill("spells",100);
    set_skill("qixing",180);
    set_skill("incarnation",180);
    set_skill("perception", 200);
    map_skill("spells","qixing");
    

        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",400000);  
        set("attitude", "friendly");
        set("chat_chance_combat", 100);
            set("chat_msg_combat", ({
            (: cast_spell, "jixing" :),
            (: perform_action, "sword.nianzijue" :),
             }) ); 

        
        set("death_msg",CYN"\n$N喃喃自语说：“我是君子。。还是。。。永远是。。没人。。能改变。。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
       
        set("chat_chance",1);
        set("chat_msg",({
//                "李马虎笑眯眯地道：“女人用鸡蛋清洗脸，越洗越年轻的。”\n",
        }) );                   
        
//           CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
        carry_object("/obj/weapon/sword")->wield();    
}     
