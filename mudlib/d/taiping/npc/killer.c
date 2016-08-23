#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";
inherit INQUIRY_MSG; 
void create()
{
        set_name("老大",({"laoda"}));
        set("title","七杀手");
        set_temp("condition_type",RED"< 奄奄一息 >"NOR);
        set("long","
这人身上一袭黑衣，腰问一条红缎带，挂一口带鞘长刀，不过，刀鞘还在，
刀却不知去向，人也是奄奄一息。\n");
        set("gender","男性");
        set("age",52);
        
        set("combat_exp",3200000);  
        set("no_heal",1);
        
        set("eff_kee",2000);
        set("eff_sen",2000);
        set("eff_gin",2000);
        set("kee",2000);
        set("sen",2000);
        set("gin",2000);
                
        set("inquiry", ([
                "*":    "厄。。。。厄。。。\n",
        ]));
                
  
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n老大说：我跟你拼了！\n",
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "老大惊恐地说：“那不是人，是鬼，是鬼！！”\n",
           }) );                   
 
        auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        delete_skill("xisui");
        setup();
        carry_object("/obj/armor/cloth")->wear();   
        add_money("gold",random(2)); 
    
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1+random(3), ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        message_vision("老大惊恐地说：“那不是人，是鬼，是鬼！！”\n",this_object());
                        break;
                case 1:
                        message_vision("老大喉咙里咕咕几声，又吐出一口血来。\n",this_object());
                        break;
                case 2:
                        message_vision("老大挣扎着用手在地上摸索着什么。。。\n",this_object());
                        break;
        }
}     
