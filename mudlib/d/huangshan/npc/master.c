inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();
void create()
{
    set_name( "玉兰溪" , ({ "master yu",  "master" }) );
    set("gender", "女性");
    set("title", "松谷庵 主持");
    set("nickname", HIC"空谷幽居"NOR);
    set("age", 46);
    set("long", "一个小尼庵的主持．\n");
        set("reward_npc", 1);
        set("difficulty", 2); 
    set("combat_exp", 10000000);
    set("score", 50000); 
    set("class", "mei"); 
    set("str", 30);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30); 
    set("force", 2000);
    set("max_force", 2000);
    set("force_factor", 60); 
    set("atman", 1500);
    set("max_atman", 1500); 
    set("mana", 3000);
    set("max_mana", 3000);
    set("inquiry", ([
         "leave" : (: leave :),
        ]) ); 
    set("apprentice_available", 5);
    create_family("松谷庵", 1, "主持");
    set("rank_nogen",1);
    set("ranks",({"杂工","伙头","尼姑","师姑","法师",WHT"长老"NOR,WHT"圣姑"NOR,HIW"神尼"NOR}));
    set_skill("literate", 140);
    set_skill("force", 200);
    set_skill("spells", 280);
    set_skill("move", 200);
    set_skill("unarmed", 150);
    set_skill("tenderzhi",160);
    set_skill("sword", 200);
    set_skill("qiuzhi-sword", 220);
    set_skill("iron-cloth", 180);
    set_skill("parry", 160);
    set_skill("dodge", 200);
    set_skill("xuanxinjue", 200);
    set_skill("liuquan-steps", 160); 

    map_skill("iron-cloth", "xuanxinjue");
    map_skill("unarmed", "tenderzhi");
    map_skill("sword", "qiuzhi-sword");
    map_skill("parry", "qiuzhi-sword");
    map_skill("force", "xuanxinjue");
    map_skill("spells", "xuanxinjue");
    map_skill("dodge", "liuquan-steps");  
    map_skill("move", "liuquan-steps");  
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :),
        }) );
        setup();
    set_temp("apply/dodge", 200);
    set_temp("apply/armor", 30); 
	set_temp("xuanxinaomiao",1);
    setup(); 
        carry_object("/obj/armor/cloth")->wear();
} 
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢着，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 贫尼今天已经收了五个弟子，施主还是改日再来吧。");
        }
} 
void do_recruit(object ob)
{
     if(ob->query("marry")){
                message_vision("$N叹了口气道，“女施主已是红尘中人，可惜，可惜。”\n", 
                                this_object(), ob);
                return;
        }
    if (ob->query("once_menpai/mei")&& ob->query("class")!="mei") {
                command("sigh");
                command("say 施主既然已经再入红尘，就不必回头了。");
                return;
                } 

 
        if( (string)ob->query("gender") != "女性" )
                command("say 松谷庵不收男徒，得罪了。");
        else {
                command("say 嗯... 天助我松谷。既然你看破红尘，我就收留你吧....");
                command("recruit " + ob->query("id") );
        }
} 
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mei");
        add("apprentice_availavble", -1);
} 

int leave() {
   if (this_player()->query("class")!="mei") return 0;
        message_vision(CYN"$N叹道：天弃松谷，你若走了，这玄心奥妙决和虬枝剑式的精髓就领悟不到了。\n"NOR, this_object(),this_player());
        return 1;
}  