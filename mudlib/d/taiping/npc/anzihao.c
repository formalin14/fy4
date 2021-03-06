#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";
inherit INQUIRY_MSG; 
int show_me();
int ask_tie(); 
void create()
{ 
        set_name("安子豪",({"an zihao","an"}));
        set("long", "太平镇驿站的驿丞，这儿远近八百里人烟稀少，这个驿站成了当地最高的官家象征，
驿丞就是八十三户百姓的父母官。\n");
        set("title", "太平镇驿丞");
        set("nickname", "万事通");
        set("age",40);
        
        set("combat_exp", 8000000);
        set("gender","男性");   
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("reward_npc", 1);
        set("difficulty", 10); 
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "韦七娘" :      (: show_me :),
                "wei qiniang" : (: show_me :),
                "tie hen" :     (: ask_tie :),
                "铁恨" :        (: ask_tie :),
        ]));
                
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n安子豪喝道：反了反了，竟然敢杀官差！！！\n",
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "安子豪说：“我姓安，安子豪。平安的安，子孙的子，豪杰的豪。”\n",
        }) );  
         
        auto_npc_setup("wang",300,160,0,"/obj/weapon/","fighter_w","yue-spear",1);
        set_skill("changquan",220);
        setup();
        carry_object(__DIR__"obj/o_cloth")->wear();
        carry_object(__DIR__"obj/sspear")->wield();
}  
int show_me()   {
        if (this_player()->query("parrot/韦七娘")) {
                ccommand("say 原来是七娘叫你来的，铁恨与我提起过，我先给你介绍一下这里的情况吧。");
                call_out("event1",1,this_player(),0);
        }
        else {
                command("consider");
                message_vision("$N说：“韦七娘又叫神针韦七娘，在江湖上大大有名，专杀那些穷凶极恶之人。”\n",this_object());
                message_vision("$N说：“不过，这几年来她销声匿迹，听说已经隐退了，。”\n",this_object());
        }
        return 1;
}  
int ask_tie()  {
        
        object who;
        who=this_player();
        if (who->query("parrot/韦七娘"))
                ccommand("say 铁恨，韦七娘和我都在追查太平王府失窃珠宝的下落。");
                else
                ccommand("say 铁恨是天下闻名的四大名捕之铁手无情。");
        return 1;
}          
string *event1_msg=     ({
        
        GRN"\n  安子豪道：“方圆八百里，太平镇是唯一有人烟的地方。地方虽然不小，可是附
近有沼泽和密林，山上听说还有猛虎，所以能让人生存的地方并不多。据我们上次
调查，镇上一共只有八十三户人家。”\n"NOR,
   
        GRN"  “天高皇帝远，这驿站是唯一官家的象征，我也算是这里的父母官。”安子豪笑
笑说：“不过，这也只是在三爷不管事的时候。。三爷姓武，文武的武，叫"+HIG"武镇山"NOR+GRN"，
这地方有一半是他的。”\n"NOR,
        
        GRN"  “如果没有"+HIG"李大娘"NOR+GRN"，他也许早就把另一半也买了下来。没有人知道大娘真名叫什
么，也没人知道她的来历，只知道她三年前在镇旁买下了座庄园。”\n"NOR, 
        GRN"  “一山容不得二虎，"+HIG"李大娘"NOR+GRN"和"+HIG"武三爷"NOR+GRN"一直在明争暗斗，到现在为止，似乎谁都没
能占上风。”\n"NOR, 
        GRN"  “两年前铁捕头在审问一些江湖大盗时，发现他们手中曾有一批太平王府失窃的
珠宝，而这些珠宝的来源都归结到这个小镇周围。韦三娘和我在此明查暗访，还是
一无所获。直到数月前铁恨擒住满天飞，满天飞在临死前供出又有一笔珠宝将在此
地易手，我想这就是他请你来协助的原因。“\n"NOR,
        
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) 
                || this_object()->is_fighting())        return;
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                tell_object(me,GRN"  除了武三爷和李大娘外，这镇上还有"+HIG"老蛔虫，谭氏兄弟，宋妈妈，老掌柜"NOR+GRN"等人值
得一查。前几日京城四大名捕之一的毒手"+HIG"常笑"NOR+GRN"也突然来到这里，此人心狠手辣，你
需小心。若有空，也可去鹦鹉楼转转，说不定还能见到"+HIG"血奴"NOR+GRN"姑娘。\n\n"NOR);
                me->set("parrot/安子豪背景",1);
                command("addoil "+me->get_id());
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}    
