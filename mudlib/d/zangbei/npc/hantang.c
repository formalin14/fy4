#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";
inherit INQUIRY_MSG; 
int estate(); 
void create()
{
        set_name("韩棠",({"han tang","han"}));
//      set("title","与世无争");
        set("long","
韩棠并不野蛮，并不凶恶．只不过眉目间仿佛总是带着一种说不出的冷漠之
意，无论谁都没法子和他亲近。他自然也不愿和任何人亲近，随便在什么地
方．他都是站得远远的。若有人走近他七尺之内，他立刻就会走得更远些。
除了在老伯的面前，也从来没有人见他开过口。\n");
        
        set("gender","男性");
        set("group","ma");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "老伯": "无论老伯做什么，都是对的，无论老伯对我怎么样，我都不会埋怨。",
           "孙玉伯":"无论老伯做什么，都是对的，无论老伯对我怎么样，我都不会埋怨。",
        ]));
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "\n韩棠坐在鱼池旁，钓竿已扬起鱼已被钧钩住，他就静静地坐在那里
欣赏鱼在钓钩上挣扎。\n",
        }) );                   
        
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_u","nine-moon-claw",1);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
 
}      
