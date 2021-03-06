#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("南宫十二郎", ({ "shier" }) );
        set("title",RED"钱庄大少"NOR);
        set("gender", "男性" );
        set("age", 22);
        set("richness",5000000);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("fly_target",1);
        set("long",
                
                "中原南宫世家，家财万贯，产业不可胜数，南宫十二郎乃钱庄二少\n"); 
        set("combat_exp", 1000000);
        set("attitude", "friendly"); 
        set("max_atman", 1000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_force", 500);
        set("force", 500);             
        set("max_mana", 1000);
        set("mana", 1000);              
        set("mana_factor", 3); 
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("celestrike", 120);
        set_skill("celestial", 100);
        set_skill("chaos-steps", 120); 
        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        map_skill("dodge", "chaos-steps");
        
        set("inquiry", ([
                "抢劫" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
                "rob" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
        ]) ); 
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        add_money("silver", 10);
} 
void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");
        add_action("do_show","show");
} 
int do_show(string arg)
{
        object letter;
        object me;
        if (!arg) return 0;
        me=this_player();
        if(!objectp(letter=present(arg,me)))
                return 0;
        if(!letter->query("for_di"))
                return 0;
        if ( !me->query("libie/离别钩_杀死狄青麟"))
                return 0;
        if (me->query("libie/南宫十二郎")) {
                message_vision("$N不悦道：“咱们已经两清了。”\n",this_object());
                return 1;
                }               
        message_vision("$N脸色微变，道：“只有狄小侯爷亲来才能动用这些银子。”\n",this_object());
        message_vision("$N对$n说道：“不过既然狄小侯爷已经死了，那么这样好了，我用一万两银子买这封信，如何？”\n",this_object(),me);
        destruct(letter);
        add_action("do_answer","answer");
           return notify_fail(HIY"answer(yes/no)\n"NOR);
        return 1;
} 
int do_answer(string arg)
{
        object ob, me;
        object room, money_reward;
        int i; 
        me=this_player();
        if ( !me->query("libie/离别钩_杀死狄青麟"))
                return 0;
        
        if (arg=="no")
        {
                message_vision(HIW"南宫十二郎微笑的对$N说道：“我是试试你的,我对此事一无所知。”\n"NOR,me);
                remove_action("do_answer","answer");
                if (!me->query("libie/南宫十二郎")){
                        me->add("score",500);
                        me->set("libie/南宫十二郎",1);
                        }
                return 1;
        }
        if (arg=="yes")
        {
                message_vision(HIB"南宫十二郎悄声的对$N说道：“好,好,此事天知地知,你知我知。”\n"NOR,me);
                remove_action("do_answer","answer");
                if (!me->query("libie/南宫十二郎")){
                        money_reward = new("/obj/money/tenthousand-cash");
                        money_reward ->move(me);
                        me->set("libie/南宫十二郎",1);
                        message_vision(HIB"南宫十二郎塞给$N一张银票.\n"NOR,this_player());
                        }
                return 1;
        }
        return 0;
}      
