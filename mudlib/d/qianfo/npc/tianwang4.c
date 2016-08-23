 inherit NPC;
void create()
{
        set_name("守护天王", ({ "tianwang","天王","守护天王" }) );
        set("gender", "男性" );
        set("combat_exp", 1100000);
        set("attitude", "friendly");
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 15);
        set("no_shown",1);
        set_skill("force", 60);
        set_skill("sword", 300);
        set_skill("dodge", 200);
        setup();
        carry_object(__DIR__"obj/godsword")->wield();
}
int is_ghost() { return 1; } 
void init()
{
add_action("do_kill","kill");
}
int getme(object me)
{
this_object()->kill_ob(me);
return 1;
} 
int do_kill(string arg)
{
        object me;
        me = this_player();
        if(arg == "master can" || arg == "master" || arg == "can")
        {
        message_vision("参机大师说道：阿弥陀佛！如此涂碳生灵，让佛祖来惩罚$N吧！！\n",me);
        call_out("getme",1,me);
        return 1;
        }
        return 0;
}      
