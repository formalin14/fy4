 // half_god.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int give_reward(object who,mapping quest);
int time_period(int timep, object me);
int wait_period(int timep, object me);
string sysmsg;
void create() {
        set_name(HIY"天机老人"NOR, ({ "tianji", "Tian ji", "Tian" }) );
        set("gender", "男性");
        set("age", 99);
        set("long", "天机老人年过六甲，鹤发童颜。在兵器谱上排名第一，
尤在上官，小李之上．此人亦正亦邪，凡事都由爱恶而定。天机老人收徒极挑剔．．．．\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({ "天机老人拿起旱烟抽了几口．．．．\n" }));
        set("force", 40000);
        set("max_gin", 8000);
        set("max_sen", 8000);
        set("max_force", 80000);
        set("force_factor", 1000);
    set("combat_exp", 100000000);
        set("score", 200000);
        set_skill("unarmed", 120);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_skill("yiqiforce", 30);
        set_skill("dagger",200);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
   map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce"); 
        create_family("潇遥派", 1, "祖师");
        set("title", "闲云野鹤");
        setup(); 
//        carry_object(__DIR__"obj/jade-cloth")->wear();
//        carry_object(__DIR__"obj/hanyan")->wield();
} 
int accept_fight(object me) {
                command("say 生命可贵！不要自寻死路！");
                return 0;
} 
void init() {
                
                 object ob;
        ::init();
        add_action("give_quest", "quest");
//        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
} 
int accept_object(object who, object ob) {
        return QUESTS_D->accept_quest_object(who, ob, this_object());
} 
int give_quest(string arg) {
	
	if(this_player()->query("combat_exp")>=50000000&& arg ==""){
	    tell_object(this_player(),"你已经不能从天机老人这里接任务了。\n");
	    return 1;
	}
        int gold = this_player()->query("deposit")/10000; 
        if (arg == "cancel" && this_player()->query("quest")) {
                if (gold <5 ) return notify_fail("你银行里存款不够五两金子。\n");
                this_player()->add("deposit", -50000);
                tell_object(this_player(), HIY"任务取消了。\n你现在账面上还有"+chinese_number(gold)+"两黄金。\n"NOR);
                this_player()->delete("quest");
                return 1;
        }
                
        return QUESTS_D->give_quest(this_player(), 
                        ([      "name" : this_object()->name(),
                                "employer" : "天机老人" ])
                        );      
} 
void attempt_apprentice(object me) {
        switch(random(4)) {
                case 0:
                        message_vision("$N对$n笑问道：什么是心剑？\n", this_object(),me);
                        break;
                case 1:
                   message_vision("$N对$n笑问道：什么是＂敌不动，我不动；敌一动，我先动？＂\n", this_object(),me); 
                        break;
                case 2:
                        message_vision("$N对$n笑问道：＂有形，无形＂是什么？\n", this_object(),me);             
                        break;
                case 3:
                        message_vision("$N对$n笑问道：武学的最高境界是什么？\n", this_object(),me);
                        break;
        }
} 
void recruit_apprentice(object ob) {
        if(::recruit_apprentice(ob)) {
                ob->set("class", "xianren");
        }
}
int attack()
{
        object opponent;
        opponent = select_opponent();
        if (userp(opponent)) {
                if (random(10)) {
                        set_temp("last_opponent", opponent);
                        command("say 生命可贵，不要自寻死路。");
                        this_object()->remove_all_killer();
                        return 1;
                } else {
                        command("say 不知死活的东西，去死吧。");
                        COMBAT_D->do_attack(this_object(), opponent, query_temp("weapon"));
                        return 1;
                }
        } else if(objectp(opponent)) {
                COMBAT_D->fight(this_object(), opponent);
                return 1;
        } else
                return 0;
        
} 
void unconcious()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
} 
void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
}   

void punish_betray(object ob)
{
        if( ( ob->query("once_xman")==1) && ( (ob->query("class"))!= "shaolin"))
          {      
                tell_object(ob, YEL"\n天机老人长叹:忘恩负义之徒！！！\n"NOR);                  
                message("vision", YEL"天机老人对"+ ob->name() +"叹道：“"+ ob->name() + "！ 国师叫我代他清理门户，容你不下了！\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"天机老人一拳击在你的天灵盖上！\n"NOR);              
                message("vision", HIW"天机老人一拳击在"+ ob->name() +"的天灵盖上！\n"NOR, environment(ob), ob);
                tell_object(ob, HIR"你只觉天晕地转,摇摇晃晃地倒了下去----悔不当初呀!\n"NOR);
                ob->set("title",HIC"少林叛徒"NOR);
                ob->die();
          }
}  