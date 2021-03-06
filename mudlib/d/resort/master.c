 inherit NPC;
inherit F_MASTER;
int leave(); 
#include <ansi.h> 
void create()
{
    set_name("铁少", ({ "master tieshao", "master","tieshao" }) );
    set("gender", "男性" );
    set("nickname", HIG "多情刀客"NOR);
    set("reward_npc", 1);
    set("difficulty", 35);
    set("age", 25);
    set("int", 30);
    set("per", 30);
    set("cor",55);
    set("str",100);
    set("class","legend");      
    set("apprentice_available", 50);
    create_family("铁雪山庄", 1, "庄主");
    set("rank_nogen",1);
    set("ranks",({"茶童","小侠","少侠","大侠","奇侠",WHT"狂侠"NOR,WHT"侠圣"NOR,HIW"隐侠"NOR}));
    set("long",
        "铁少从十五岁开始就和爱妻雪蕊儿行侠江湖，俩人刀剑合壁，\n"
        "天下无敌。正当俩人名声顶盛之时，又忽然退出江湖，隐居于此。\n"
        );
    set("inquiry", ([
        "leave" : (: leave :),
                ]));
    set("force_factor", 150);
    set("max_atman", 300);
    set("atman", 300);
    set("max_force", 1500);
    set("force", 1500);
    set("max_mana", 300);
    set("mana", 300);
    set("fly_target",1);
    set("combat_exp", 9999999);
    set("score", 90000);
    set_skill("unarmed", 100);
    set_skill("blade", 220);
    set_skill("force", 160);
    set_skill("parry", 100);
    set_skill("literate", 180);
    set_skill("dodge", 150);
    set_skill("move",150);
    set_skill("meihua-shou", 100);
    set_skill("shortsong-blade", 180);
    set_skill("qidaoforce", 160);
    set_skill("fall-steps", 180);
    set_skill("sword",150);
    set_skill("diesword",100);
    set_skill("dormancy",220);
    set_skill("perception", 200); 
    map_skill("unarmed", "qidaoforce");
    map_skill("blade", "shortsong-blade");
    map_skill("force", "qidaoforce");
    map_skill("parry", "shortsong-blade");
    map_skill("dodge", "fall-steps"); 
 /*   set("chat_chance", 1);
        set("chat_msg", ({
               (: exert_function, "juqi" :),
        }) );   */ 
    set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "blade.duangechangmeng" :),
                (: perform_action, "blade.daojianruomeng" :),
                (: perform_action, "dodge.luoyeqiufeng" :),
                  
        }) ); 
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
    carry_object(__DIR__"obj/mblade")->wield();
}  
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢着，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
    }
}
void do_recruit(object ob)
{
    if( (string)ob->query("gender") != "男性" )
    {      command("say 我只收男弟子，你还是去拜我的内人吧！");
    }
    else { 
        command("smile");
        command("say 你日后必有大成！");
        command("smile");
        command("recruit " + ob->query("id") );
    }
}
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "legend");
    add("apprentice_availavble", -1);
} 
int accept_fight(object me)
{
    object xiaocui;
    if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    {   
        command("smile");
        command("say 还是让小翠来吧。");
        return 0;
    }
    else
        command("sigh");
    command("铁少慢慢的从翠竹凳上站起来，放下了手中的紫砂杯。");
    command("wield wangblade");
    command("say 请！");
    call_out("do_unwie", 3);
    return 1;
}
int do_unwie()
{
    if( !this_object()->is_fighting())
    {
//      command("unwield wangblade");
        message_vision("$N拿起茶杯浅啖一口，含情脉脉的望了雪蕊儿一眼，又坐在竹凳上。\n", this_object());
        command("smile");
        return 1;
    }
    else
        call_out("do_unwie", 3);
} 
void init()
{       
        object me;
        add_action("do_killing", "kill");
        ::init();
        if( interactive(me = this_player()) && !is_fighting())
        if (me->query_temp("marks/tie_ask") && !me->query("marks/黄山送信")) {
                message_vision(HIY"$N问：我叫你办的事怎么样了？\n"NOR,this_object());
                return;
                }
        if (me->query("combat_exp")>3200000 && me->query("class")=="legend" 
                && !me->query("marks/黄山学艺") && !me->query("marks/黄山送信") 
                && !me->query_temp("marks/tie_ask")&&userp(me)) {
                remove_call_out("greeting");
                add_action("do_accept", "accept");
                me->set_temp("tie_in_ask",1);
                call_out("greeting", 1, me);
    }
            
} 
int greeting(object me)
{
    message_vision(HIY"\n$N看了$n一眼说道：“你跟我学艺业已有成，今日有一事嘱托于你。（accept yes/no）\n" NOR, this_object(), me);
    return 1;
}  
int do_accept(string arg)
{
        string name;
        if (!this_player()->query_temp("tie_in_ask"))
                return notify_fail("什么？\n");
        if( arg != "yes" &&  arg != "no") 
                return notify_fail("你要接受什么？\n");
        if( arg == "yes") {
                this_player()->set_temp("marks/tie_ask",1);
                message_vision(CYN "$N说道：数日前小翠路过嵩山，见几个番僧在山下挑衅，还打伤了几个少林门人。\n"NOR,this_object());
                message_vision(CYN"据说这几个僧人号称[恒河叁佛]，很是嚣张。\n"NOR,this_object());
                message_vision(CYN"$N说：你且代为师走一趟，把他们赶回西域去。\n"NOR,this_object());
        }
        else 
                command("sigh");
        this_player()->delete_temp("tie_in_ask");
        return 1;
} 
int accept_object(object who, object ob)
{
        object gletter;
        if(!who->query("marks/番僧1") || !who->query("marks/番僧2") ||!who->query("marks/番僧3")) return 0; 
        if( ob->query("id")!="yellow bead" ) return 0;
        message_vision(CYN"$N大笑道：好，好，好徒弟！！\n"NOR,this_object());
        who->set("marks/铁雪疗伤",1);
        message_vision(CYN"$N说：为师现在把棋道心诀的疗伤术(heal)传给你。\n",this_object());
        message_vision(CYN"$N说:为师还有一事，黄山拥翠山庄李庄主是为师多年好友，这封信替我带给他。\n"NOR,this_object());
        message_vision(CYN"雪蕊儿朝你一笑说，代我向李夫人问好。\n"NOR,this_object());
        who->set("marks/黄山送信",1);
        gletter = new(__DIR__"obj/gletter");
        gletter ->move(this_player());
        return 1;
} 
int do_killing(string arg)
{
    object player, victim, weapon;
    string name, id, id_class;
    if(!arg) return 0;
    player = this_player();
    if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
    {
        name = victim->name();
        if( name == "雪蕊儿")
        {
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangblade", this_object());
            if(weapon)
            {
                message_vision("$N从乌皮刀鞘中抽出一把杀气逼人的垓下刀握在手中。\n", this_object());
                weapon->wield();
            }
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        if( name == "铁少")
        {
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangblade", this_object());
            if(weapon)
            {
                message_vision("$N从乌皮刀鞘中抽出一把杀气逼人的垓下刀握在手中。\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "legend"&& userp(victim)&&player!=victim)
        {
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangblade", this_object());
            if(weapon)
            {
                message_vision("$N从乌皮刀鞘中抽出一把杀气逼人的垓下刀握在手中。\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            message_vision("$N对着$n喝道：" + RANK_D->query_rude(player) 
                                                + "竟敢杀" + RANK_D->query_self_rude(this_object()) 
                                                + "的徒弟，去死吧。\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
               
        return 0;
    }
    return 0;           
}  
int leave() {
        if (this_player()->query("class")!="legend") return 0;
        message_vision(CYN"$N道：人各有志，我不勉强你留下。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：只是聚气心法非弟子不能使用，短歌刀法的精髓你大概也体会不到了。\n"NOR,this_object(),this_player());
        return 1;
}     
void punish_betray(object ob)
{
        if( ( ob->query("tiexue_once")==1) && ( (ob->query("class"))!= "legend"))
          {      
                tell_object(ob, YEL"\n铁少看见你忽然一楞:我派中人，讲求一个信字，你已背我而去，我派武学就不能再用了！”\n"NOR);                  
                message("vision", YEL"铁少对"+ ob->name() +"叹道：“"+ ob->name() + "！ 尔等背信弃义,还我武功！\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"雪蕊儿一缕指风击在你的身上七大穴道！\n"NOR);              
                message("vision", HIW"雪蕊儿一缕指风击在"+ ob->name() +"的身上七大穴道！\n"NOR, environment(ob), ob);
              if (ob->query_skill("dormancy",1)>100) ob->delete_skill("dormancy");
              ob->add("max_force",-650);
                tell_object(ob, HIR"你只觉天晕地转,摇摇晃晃地倒了下去----悔不当初呀!\n"NOR);
                ob->set("tiexue_once",2);
                ob->unconcious();
          }
}  
