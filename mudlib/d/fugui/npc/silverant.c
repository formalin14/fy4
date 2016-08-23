#include <ansi.h>
inherit NPC;
int qi_yun();
void create()
{
        set_name(HIC"银蚂蚁"NOR, ({ "silver ant", "ant" }) );
        set("long",
                "他身上穿着件银光闪闪的衣服，脸上还带着个银面具，看来就象是个\n用白银铸成的小妖怪，实在说不出的诡秘可怖。\n");
        set("chat_chance",2);
        set("chat_msg", ({
                "银蚂蚁抬头望了望天上的白云，长叹一声道：“二十多年了，纵然我\n刀枪不入，纵横四海，但当年却被那厮以金刚不坏伤了元气，这刻骨\n深仇如今还无法得报，人生若此，还有什么乐趣可言。”\n",
                "银蚂蚁狠狠道：“那厮的金刚不坏这么强，复仇不易啊，能从他那里偷点宝物，气死他也好。”\n"
                                })  ); 
        set("combat_exp", 200000 + random (80000));
        set("max_gin",900);
        set("max_kee",1800);
        set("max_sen",900);
        set("int",38);
        set("str",24);
        set("cor",35);
        
        set_skill("iron-cloth",100);
        set_skill("jin-gang",50);
        set_skill("unarmed",120);
        set_skill("bloodystrike",100);
        map_skill("iron-cloth","jin-gang");
        map_skill("unarmed","bloodystrike");
        set("chat_chance_combat",25);
        set("chat_msg_combat",  ({
                        (:perform_action,"unarmed.fefawubian":),
                }));
/*        set("inquiry", (
                "江山" : (: qi_yun :),
                "lsb" : (: qi_yun :),
                "nndx" : (: qi_yun :),
                "胖天使" : (: qi_yun :) 
        ]))
*/
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
int accept_object(object who, object ob)
{       
        object jinlian;
        if (ob->query("id")=="9-ring staff") 
        {
                this_player()->set_temp("marks/银蚂蚁",1);
                write("银蚂蚁怔了一下，喜泪纵横，不禁连声道：“果真杀了那该死的葛伦\n秃驴？这这实在太好了.....”\n");
                command("thank "+this_player()->query("id"));
                return 1;
        }
        if (ob->query("name")==HIW"天竺佛珠"NOR || ob->query("name")=="舍利子") 
        {
                command("thank "+this_player()->query("id"));
                this_player()->set_temp("marks/silverant",1);
                if (ob->query("name")==HIW"天竺佛珠") write("银蚂蚁怔了一下，连声道：“拿到天竺佛珠，让葛伦那秃驴哭吧！哈哈哈.....”\n");
                        else write("银蚂蚁怔了一下，连声道：“拿到舍利子，让葛伦那秃驴哭吧！哈哈哈.....”\n");
                return 1;
        }
        write("银蚂蚁缓缓摇了摇头。\n");
        return 0;
}                 
int qi_yun()
{
        object me;
        object room;
        me = this_player();
        if (me->query("combat_exp")<1000000)
                return 0;
        message_vision("\n\n$N对$n疯狂地笑了起来：要不是那个变态，我堂堂$N怎么会在这里发痴挡道？\n",this_object(),me);
        message_vision("\n$N"HIR"越说越激动，眼看要气成红蚂蚁了！\n\n\n"NOR,this_object());
        this_player()->set_temp("marks/silverant",1);
        unconcious();
        return 1;
}    
