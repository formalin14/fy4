 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("地匹", ({ "master di", "master"}) );
    set("nickname", HIY "随缘" NOR);
    set("vendetta_mark","shaolin");
    set("gender", "男性" );
    set("reward_npc", 1);
        set("difficulty", 3);
    set("age", 64);
    set("agi",30);
    set("per", 35);
    set("int",30);
    set("cps",80);
//  set("str",20+random(20));
    set("attitude","friendly");
    set("max_force", 1000);
    set("force", 1000);
    set("long", "少林第十九代长老，专门传授少林罗汉武功。\n");
    create_family("少林寺", 19, "长老");
    set("student_title","罗汉");
    set("combat_exp", 1100000);
    set_skill("move", 120);
    set_skill("dodge", 120);
    set_skill("force", 120);
    set_skill("literate", 140);
    set_skill("unarmed",120);
    set_skill("puti-steps",120);
    set_skill("dabei-strike",120);
    set_skill("zen",140);
    set_skill("chanting",120);
    set_skill("xiaochengforce",120);
    set_skill("staff",120);
    set_skill("parry",120);
    set_skill("fumostaff",120);
    set_skill("blade",120);
    set_skill("sword",120);
    set_skill("suiyuan-sword",120);
    set_skill("lianxin-blade",120);
//  set_skill("xingyi-stick",120);
    set_skill("liuxing-hammer",120);
    set_skill("hammer",120);
    map_skill("hammer","liuxing-hammer");
    map_skill("sword","suiyuan-sword");
    map_skill("staff","xingyi-stick");
    map_skill("parry","lianxin-blade");
    map_skill("dodge", "puti-steps");
    map_skill("force", "xiaochengforce");
    map_skill("unarmed", "dabei-strike");
    map_skill("blade","lianxin-blade");
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: perform_action, "staff.hequhecong" :),
        (: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    
    setup();
    carry_object(__DIR__"obj/monk21_cloth")->wear(); 
} 
void attempt_apprentice(object me)
{
    if(me->query("gender") != "男性")
    {
        command("say 少林罗汉只可以是男弟子。。。\n");
        return;
    }
    if(me->query_temp("won_master_meng"))
    {
        me->set("once_menpai/shaolin",1);
        command("smile");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("shake");
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
} 
int accept_fight(object me)
{
    if((me->query("family/family_name") == query("family/family_name") &&
        me->query("family/master_id") == query("id")) || me->query_temp("won_master_meng"))
    {
        if (me->query("combat_exp")<400000) {
                command("say 徒儿，学武不能好高骛远啊！\n");    
                return 0;
                }
        
        
        command("say 好，你赢了我，你就可以去找少林中更高深的师傅了！\n");
        return 1;
    }
    else
    {
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
    }
}
void win_enemy(object loser)
{
    command("say 阿弥陀佛！徒儿还要努力呀！\n");
}
void lose_enemy(object winner)
{
    command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
    winner->set_temp("won_master_di",1);
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
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：阿弥陀佛,佛门清静之地,岂可妄起杀心?施主请恕老衲得罪了！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}   
