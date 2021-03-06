 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int got_me();
int leave();
void create()
{
        set_name("铁战", ({ "master tiezhan", "master"}) );
    set("nickname", HIY "战狼盗"NOR);
        set("gender", "男性" );
        set("age", 34);
        set("agi",30);
        set("per", 35);
        set("int",30);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long","一个敞着衣襟，豪迈不羁的大汉；让人一见就觉得此人够义气。\n"); 
        create_family("狼山", 4, "大头领");
       set("rank_nogen",1); 
    set("student_title","巡山盗");
  
      set("inquiry", ([
           "leave" : (: leave :),
        ]) );
        
    set("combat_exp", 800000);
        set_skill("move", 150);
        set_skill("dodge", 150);
    set_skill("hammer", 150);
    set_skill("animal-training", 120);
        set_skill("force", 100);
    set_skill("parry", 180);
        set_skill("literate", 100);
        set_skill("unarmed",120);
    set_skill("summonwolf",120);
    set_skill("wolf-strike",120);
    set_skill("wolf-force",100);
    set_skill("xueyeqianzong",100);
    set_skill("assasin-hammer",100);
    set_skill("cursism",100);
    set_skill("perception", 100);
    
    map_skill("dodge", "xueyeqianzong");
    map_skill("unarmed", "wolf-strike");
    map_skill("hammer", "assasin-hammer");
    map_skill("parry", "assasin-hammer");
    map_skill("force", "wolf-force");
    set("class","wolfmount");
    set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.duanhou" :),
        }) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/pifeng")->wear();
    carry_object(__DIR__"obj/stonehammer")->wield();  
} 
void attempt_apprentice(object me)
{
      if( (int)me->query_cor() >=15 )
    {
    command("say 我狼山又多了一个无畏无惧的热血儿郎，可喜可贺啊！\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("shake");
        command("say 我看你胆小怕事，如何与敌人生死相搏？你还是走吧！\n"); 
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
} 
int accept_fight(object me)
{
        if(me->query("class") == "wolfmount")
        {
            command("say 好！赢了我，你就可以去找狼山中更高深的师傅了！\n");
                return 1;
        }
        else
        {
                command("say 开什么玩笑？老子从来不打架，要动手就玩真的！\n");
                return 0;
        }
} 
void win_enemy(object loser)
{
    command("say 你就这点能耐啊？别跟别人说我是你师傅，丢人！丢人！\n");
} 
void lose_enemy(object winner)
{
    command("say 乖徒儿，不错不错。有前途！到山上找师爷师公学去吧。\n");
        winner->set_temp("marks/wolf_win_tiezhan",1);
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
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
int leave() {
        if (this_player()->query("class")!="wolfmount") return 0;
        message_vision(CYN"$N不屑地看了你一眼。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：想走可以，以后别指望咱狼山的独门特技。\n"NOR,this_object(),this_player());
        return 1;
}        
