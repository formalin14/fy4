 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("卜战", ({ "master bu", "master" }) );
        set("nickname", HIW"战狼王"NOR);
        set("gender", "男性" );
        set("apprentice_available", 5);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("age", 46);
        set("int", 40);
        set("spi", 25);
        set("cor", 20);
        set("per", 40);
        set("attitude","heroism");
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 30); 
        set("long",
                "他闪着光的脸虽然枯瘦腊黄，却带着种说不出的慑人气概。\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
                "卜战一手紧紧握着旱烟枪：俺那帮好孩儿死得真惨，谁杀了那天杀星常\n无意，老夫必倾囊以授。\n",
        }) );
        create_family("狼山", 3, "大头领");
         set("rank_nogen",1); 
        set("ranks",({ "小喽罗","大喽罗","小头目","大头目","大头领",RED"大盗"NOR,RED"盗帅"NOR,HIR"副山主"NOR }));
        set("combat_exp", 2200000);
        
        set_skill("move", 140);
        set_skill("xueyeqianzong", 120);
        set_skill("wolf-strike", 180);
        set_skill("animal-training", 180);
        set_skill("assasin-hammer", 150);
        set_skill("cursism", 100);
        set_skill("parry", 120);
        set_skill("wolf-curse",180);
        set_skill("dodge", 140);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("summonwolf", 180);
        set_skill("literate", 100);
        set_skill("hammer",150);
        set_skill("wolf-force",150);
        set_skill("perception", 100);    
            map_skill("dodge","xueyeqianzong");
            map_skill("unarmed","wolf-strike");
            map_skill("parry","assasin-hammer");
            map_skill("hammer","assasin-hammer");
            map_skill("force","wolf-force");
        setup();
        carry_object(__DIR__"obj/silkcloth")->wear();
        carry_object(__DIR__"obj/hanyan")->wield();
       carry_object(__DIR__"obj/mysterypicture"); 
} 
void reset()
{
        set("apprentice_available", 5);
} 
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("say 老夫已经收够了弟子，不能再收了。\n");
        }
} 
void do_recruit(object me)
{
        if( (string)me->query("class") != "wolfmount" )
        {
                command("say 我只收本门弟子，你还是另谋高就吧！\n");
        }
        else if(!me->query_temp("marks/wolf_win_tiezhan"))
        {
                switch ( random(2) )
                {
                        case 0:
                                command("say 好个不忠不孝的家伙，竟然没有和铁战打招呼就跑来我这\n里，不收！\n");
                                break;
                        case 1:
                                command("say 学武要循序渐进，你还是打好基础再来吧。\n");
                                break;
                }
        }
        else if (!me->query_temp("marks/wolf_killed_wuyi"))
        {
                command("shake");
                command("say 不杀掉常无意那匹夫，老夫绝不收徒！\n");
        }
        else
        {
                command("say 你帮我报了大仇，我就收你为徒吧！\n");
                command("recruit " + me->query("id") );
        }
}
                
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
        add("apprentice_availavble", -1);
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill");
        if( !query_heart_beat(this_object()) ) {
                set_heart_beat(1); 
        }
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "wolfmount"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：狼山子弟,同气连枝,不容外人欺侮！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
