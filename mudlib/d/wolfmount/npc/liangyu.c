#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("温良玉", ({"wen liangyu", "liangyu","wen" }));
        set("nickname", HIC"谦谦君子"NOR HIG"温良如玉"NOR );
        set("gender", "男性");
        set("age", 42);
        set("long",
                "白衣高冠，温文儒雅，手里轻摇着一把折扇，看上去可佩可亲。\n");
        set("attitude","friendly");
        create_family("狼山", 3, "大头领");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("apprentice_available", 5);
        set("rank_nogen",1); 
        set("ranks",({ "小喽罗","大喽罗","小头目","大头目","大头领",RED"大盗"NOR,RED"盗帅"NOR,HIR"副山主"NOR }));       
        set("str", 50);
        set("int", 40);
        set("con", 26);
        set("agi", 50);
        set("per", 40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "太阳使者慢慢道：“你若是诚心皈依，我就收容你。引导你到极乐和永生。” \n",
        }));
    set("max_force", 2000);
    set("force", 2000);
    set_temp("apply/damage", 100);
    set("force_factor", 100);
    set("combat_exp", 10000000);
        set("score", -50000);
        set_skill("force", 150);
        set_skill("bibo-force", 150);
   set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("luoriquan", 220);
        set_skill("move", 180);
        set_skill("fengyu-piaoxiang", 320);
        set_skill("parry", 150);
        set_skill("literate",150);
        set_skill("stealing",320);
        map_skill("force"  , "bibo-force");
        map_skill("unarmed", "luoriquan");
        map_skill("dodge"  , "fengyu-piaoxiang");
        map_skill("move"  , "fengyu-piaoxiang");
        setup();
        carry_object(__DIR__"obj/mask")->wear();
        carry_object(__DIR__"obj/silkcloth")->wear();
} 
void die()
{
        object me;
        object grass; 
        if(objectp(me = query_temp("last_damage_from")))
        {
                command("say 都怪我大意，纵虎归山。悔之晚矣！\n");
                if(me->query_temp("marks/拜朱五太爷")){
                        me->delete_temp("marks/拜朱五太爷");
                        me->set("m_success/狼山灭奸",1);
                }
                me->set("marks/杀太阳使者",1);
                grass = new(__DIR__"obj/grass");
                grass->move(this_object());
                ::die();
        }
} 
void init()
{
        object me;
        ::init();      
        if( interactive(me = this_player()) && !is_fighting()) 
        {
                call_out("greeting", 1, me);
   }
        add_action("do_kill", "kill");
} 
int greeting(object me)
{
        object npc;
        object xiaoma;
        npc = this_object();
        if ( me->query_temp("marks/wolf_xiaoma_good") )
        {
                message_vision(HIY "$N冷笑道：嘿嘿，怪不得小马这么有勇气，原来是找了个帮手，还等什么？\n"NOR, npc);
        }
        else
        {
                message_vision(HIY "$N缓缓道：诚心皈依我吧，你会永享极乐！\n"NOR, npc);
        }
        return 1; 
} 
int do_kill(string arg)
{
        object me,ob;
        me = this_player();
        ob = this_object();
        if (arg != "sun legate")
                return 0;
        else 
        {
                me->kill(ob);
                ob->kill(me);
                environment(me)->kill_notify(ob,0);
        }
        return 1;
}
void do_recruit(object me){
        if(me->query("title") == "狼山 "+HIR"蚩尤传人"NOR){
                command("say 好我就收你为徒吧。\n");
                command("recruit" + me->query("id"));
        } else {
                command("hmm");
        } 
} 
int recruit_apprentice(object ob){
        if( ::recruit_apprentice(ob) )
            ob->set("class", "wolfmount");
    add("apprentice_availavble", -1);    
} 
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
            if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
            else
            call_out("do_recruit", 2, ob);
        } else {
            command("say 今日不再收了。");
        }
} 
void reset(){
        set("apprentice_available", 5);
}
