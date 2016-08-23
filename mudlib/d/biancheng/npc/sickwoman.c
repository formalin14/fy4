#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me();
int finished(); 
void create()
{
        set_name("陶氏",({"tao shi","taoshi","tao"}));
        set("title","奄奄一息");
        set("long","陶保义媳妇两年前到镇上的坟地里去祭了次公婆，回来就得了种怪病，浑身溃
烂。也不知投了多少医，吃了多少药，家里越来越穷，病却一点没起色。此刻
她正躺在床上辗转呻吟。\n");
        
        set("gender","女性");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",500000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_force",200+random(500));
        set("force",query("max_force"));
        set("force_factor",30);
        
        set("death_msg",CYN"\n$N说：“死了就不用再花钱吃药了。。”\n"NOR);      
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"叫道：“来人啊，强盗上门抢劫啦！”\n", 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                (: finished() :),
        }) );                   
           
        setup();
        carry_object("/obj/armor/cloth")->wear();     
} 
int finished() {
        object tao1,tao2; 
        tao1=this_object();
        tao2=present("tao baoyi",environment(tao1));
        if (!tao2) {
                command("say 保义，保义，你在哪里呀？");
                return 1;
        }else {
                command("say 保义啊，我。。看来是不行了。，你还是趁早替我准备后事吧。。");
                message_vision("$N伸手替$n掖好被子说道，“我上风云城替你抓了帖新药，吃了就好了。”\n",tao2,tao1);
        }
        return 1;
}
        
        
                   
