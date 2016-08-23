#include <ansi.h>
#include <command.h>  
inherit "/d/taiping/npc/smart_npc"; 
int show_me();
int ask_tie(); 
void create()
{ 
        set_name("红衣裳的小姑娘",({"redgirl","girl"}));
        set("title","鹦鹉楼");
        set("long", "穿着套红衣裳的小姑娘，一双眸子黑如点漆。\n");
        set("age",40);
        set("combat_exp", 7000000);
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",120); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "韦七娘" :      (: show_me :),
                "wei qiniang" : (: show_me :),
                "tie hen" :     (: ask_tie :),
                "铁恨" :        (: ask_tie :),
        ]));
        
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
   
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
             
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
        
        }) );    
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
        
        setup();
        
        carry_object(__DIR__"obj/redskirt")->wear();
        carry_object(__DIR__"obj/needle")->wield();
}  
void init(){
        ::init();
        add_action("do_look", "look");
}  
int do_look(string arg) {
        if(arg == "redgirl" || arg == "girl"){
                write("穿着套红衣裳的小姑娘，一双眸子黑如点漆。\n");
                write("她看起来约十多岁。\n");
                write("她长的不胖不瘦，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。\n");
                write("她精神饱满，正处于巅峰状态。\n");
                write("她身穿红短裙(Red skirt)\n");
                return 1;
        }
   return 0;
} 
int accept_object(object who, object ob)
{
        if( ob->name()==HIG"碧玉"NOR) {
                if (who->query("parrot/赴太平镇") && who->query_temp("parrot/ask_wei")) {
                        message_vision("$N说：“原来你是铁捕头的朋友，刚才失礼了。此处隔墙有耳，我不敢大意。”\n",this_object());
                        message_vision("$N说：“你可速去找镇上驿站的安子豪，就说是我叫你去的。\n",this_object());
                        who->set("parrot/韦七娘",1);
                        return 1;
                }                 
                command("say 这位"+RANK_D->query_respect(who)+"，还是留着赏给姑娘们吧。");
                return 0;
        }        
        return 0;
}   
int show_me()   {
        
        if (this_player()->query("parrot/韦七娘"))
                ccommand("say 铁恨，安子豪和我都在追查太平王府失窃珠宝的下落。");
        else {
                command("ack "+this_player()->get_id());
                this_object()->set("name","韦七娘");
                this_player()->set_temp("parrot/ask_wei",1);
                message_vision("$N说：“你竟然知道我的来历！不过，我前后己在江湖上七年，已太累了。”\n",this_object());
                message_vision("$N说：“我现在只是鹦鹉楼一个应门的丫头。”\n",this_object());
        }
        return 1;
}  
int ask_tie()  {
        
        object who;
        who=this_player();
        if (who->query("parrot/韦七娘"))
                ccommand("say 铁恨，安子豪和我都在追查太平王府失窃珠宝的下落。");
                else
                ccommand("say 铁恨？是不是昨儿个晚上来找翠花的那位大爷？");
        return 1;
}          
