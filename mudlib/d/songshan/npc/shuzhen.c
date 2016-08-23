 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("叶淑贞", ({ "ye shuzhen", "ye"}) );
        set("nickname", HIR "前任帮主夫人"NOR);
        set("gender", "女性" );
        set("age", 44);
        set("per", 55);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 10);
        set("long",
"
叶淑贞是丐帮的前任帮主任慈的夫人，只因任慈病逝后才隐居于此。
\n"
        );
        set("combat_exp", 4);
        set("inquiry", ([
                "南宫灵" : (: kill_him :),
                "master nangong" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear(); 
} 
int kill_him()
{
        command("say 南宫对我甚为孝顺，每天清粥一碗，从未间断！\n");
        return 1;
} 
int accept_object(object who, object ob)
{
        if(ob->name() == "云素密函"){
        command("say 我写此信也是万不得以，南宫野心勃勃，想用天一神水
毒尽天下武林豪杰，他还有一个嫡亲的哥哥，更是心黑手辣！
此人不除，天下武林永无宁日！其实南宫灵就是天枫十四郎的二儿子，
而其长子则在天峰掌门的门下。\n");
        who->set_temp("天一神水",1);    
        if(!who->query("m_success/丐帮前任"))
        {
                who->set("m_success/丐帮前任",1);
                who->add("score",100); 
        }
                return 1;
        }
    return 0;
} 
