 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("老妈子",({"maid"}));
        set("title",YEL"鹦鹉楼"NOR);
        set("long","
鹦鹉楼里打扫屋子的老女人。\n");
        set("nickname","见多识广");
        set("gender","女性");
        set("age",55);
        set("no_arrest",1);
        set("int",22);
        set("cor",30);
        set("per",60);
        set("cps",20);
        
        set("combat_exp",250000);  
        set("attitude", "friendly"); 
        set("inquiry", ([
                "从良" : "门户里的姑娘，从良就像是重投一次胎。不过，有个真从良，
有个假从良，有个苦从良，有个乐从良，有个趁好的从良，有个没奈何的从
良。\n",
                "讲究" : "门户里的姑娘，从良就像是重投一次胎。不过，有个真从良，
有个假从良，有个苦从良，有个乐从良，有个趁好的从良，有个没奈何的从
良。\n",
                "真从良":"如何叫做真从良？大凡才子必须佳人，佳人必须才子，方成佳
配。然而好事多磨，往往求之不得。幸然两下相逢，你贪我爱，割舍不下。
一个愿讨，一个愿嫁。好像捉对的蚕蛾，死也不放。这个谓之真从良。\n",
                "假从良":"如何叫做假从良？有等子弟爱著小娘，小娘却不爱那子弟。晓
得小娘心肠不对他，偏要娶他回去。拚著一主大钱，动了妈儿的火，不怕小
娘不肯。勉强进门，心中不顺，故意不守家规，小则撒泼放肆，大则公然偷
汉。人家容留不得，多则一年，少则半载，依旧放他出来，为娼接客。把从
良二字，只当个赚钱的题目。这个谓之假从良。\n",
                "苦从良":"如何叫做苦从良？一般样子弟爱小娘，小娘不爱那子弟，却被
他以势凌之。妈儿惧祸，已自许了。做小娘的，身不繇主，含泪而行。一入
侯门，如海之深，家法又严，抬头不得。半妾半婢，忍死度日。这个谓之苦
从良。\n",
                "乐从良":"如何叫做乐从良？做小娘的，正当择人之际，偶然相交个子弟，
见他情性温和，家道富足，又且大娘子乐善，无男无女，指望他日过门，与
他生育，就有主母之分。以此嫁他，图个日前安逸，日后出身，这个谓之乐
从良。\n",
                "趁好的从良":"如何叫做趁好的从良？做小娘的，风花雪月，受用已够，趁这
盛名之下，求之者众，任我拣择个十分满意的嫁他，急流勇退，及早回头，
不致受人怠慢。这个谓之趁好的从良。\n",
                "没奈何的从良":"如何叫做没奈何的从良？做小娘的，原无从良之意，或因官司
逼迫，或因强棋欺瞒，又或因债负太多，将来赔偿不起，别口气，不论好歹，
得嫁便嫁，买静求安，藏身之法，这谓之没奈何的从良。。\n",
                "梳弄" : "门户中梳弄，就是姑娘的破身了，也有个规矩。十三岁太早，谓之试花。
十四岁谓之开花，此时天癸已至，男施女受，也算当时。到十五谓之摘花，
那是最晚的了。",
                
        ]));
    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
        ]) ); 
        
        set("chat_chance",1);
        set("chat_msg",({ 
        }) );
        setup();    
        carry_object("obj/armor/cloth")->wear();
} 
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        return;
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        switch (random(3)){
                case 0: message_vision(CYN"老妈子拿着抹布勤快地打扫着。\n"NOR,ob); break;
                case 1: message_vision(CYN"老妈子自言自语地说：“碧莲儿不肯梳弄，妈妈正在劝她呢。”\n"NOR,ob); break;
           case 2: message_vision(CYN"老妈子说：“哪个姑娘不想从良，不过，这从良也有个讲究。”\n"NOR,ob);
        }
        return;
}       
