 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
int give_hint();
string sysmsg;
void create()
{
        set_name(HIG"连城璧"NOR, ({ "lian", "lian cheng bi", "chengbi" }) ); 
        set("gender", "男性");
        set("age", 29);
        set("long",
 "一个文雅的世家公子，在文雅中却又带着种令人觉得高不可攀的清华之气。竟然\n便是当代武林年青一代中的领袖，无垢山庄的少主，万人仰慕的绝世奇才。\n");
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 10);
//      set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "连城璧向你拱了拱手道：＂这位英雄，今朝相遇，我连某深感荣幸！＂\n",
        }) );
        set("inquiry", ([
                "天宗" : (: give_hint:),
                "tianzong" : (: give_hint:) 
        ]));
        set("force", 4000);
        set("max_force", 80000);
        set("force_factor", 40);
        set("atman",1000);
        set("max_atman",1000);
        set("fly_target",1);
        set("combat_exp", 10000000);
        set_skill("unarmed", 180);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_temp("apply/attack",100);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/damage",100); 
        set("title", "无垢山庄 少庄主");
        set("nickname", HIR"侠义无双"NOR);
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        create_organization("天宗",1,"邪");
}
int accept_fight(object me)
{
        command("say 想砌蹉武功！好！我连某理应奉陪，但拳脚无情，你小心了！");
        return 1;
}
void init()
{
	object ob;
        ::init();
        if( userp(ob = this_player()))
        if(ob->query("improbity")&&(string)ob->query("organization/org_name") == "天宗")
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
//      add_action("give_mission", "mission");
//      add_action("join_in","join");
}
int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
        string test;
        string mission;
// Let's see if this player is one of us
        if((string)who->query("organization/org_name") != "天宗")
                return 0;
        val = ob->value();
        if(!(mission =  who->query("mission/name")))
        {
        tell_object(who,"连城璧说道：这不是天孙要的。\n");
        return 0;
        }
/*        if( (string)ob->query("unit")+(string)ob->query("name") != quest_tianzong)
        {
        tell_object(who,"连城璧说道：这不是天孙要的。\n");
        return 0;
        } */
        if( ob->is_character())
        {
        tell_object(who,"连城璧说道：这不是天孙要的。\n");
        return 0;
        }
        if ((int) who->query("mission_time") < time() )
        {
        tell_object(who,"连城璧说道：真可惜！你没有在指定的时间内完成！\n");
                        return 1;
        }
        else
        {
        tell_object(who,"连城璧说道：好！做得好！天宗就需要你这样的人才！\n");
        exp = random(150) + 10;
// put a cap
        exp = exp * (int) who->query_temp("mission_number")/3;
        exp += 1;
        pot = exp / 5 + 1;
        score = 1;
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",-score);
        tell_object(who,HIW"你被〔天孙〕奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"NOR);
//      chinese_number(score)+"点综合评价\n"NOR);
        who->set("mission/name", 0 );
        who->add("QUEST",1);
                        return 1;
        }
                return 1;
}
int give_mission(string arg)
{
        string mission ;
        object me;
        int j, combatexp, timep, lvl=0;
        mixed *local;
        string *npcs,*objs,file;
        int  t;
        me = this_player();
// Let's see if this player is one of us
        if((string)me->query("guild") != "天宗")
                return 0;
   if((int)me->query("last_good_kill") < ((int)me->query("mud_age") - 24*3600))
        {
                tell_object(me,"连城璧对你阴笑着说：
＂我看你对〔天宗〕并不很忠心，除非你去杀一个和你武功相当的「人」物＂\n");
                return 1;
        } 
// Let's see if this player is a ghost
        if((int) me->is_ghost())
        {
                write("鬼魂不可要任务．\n");
                return 1;
        }
        if( me->query("mission/name"))
        {
        	write("你现在的任务是关于"+me->query("mission/name")+"。\n");
        return 1;
        }
// Let's see if this player still carries an un-expired task
        if((mission =  me->query("mission/name")))
        {
        if( ((int) me->query("mission_time")) >  time() )
                return 0;
        else
                me->set("kee", me->query("kee")/2+1);
                me->delete_temp("mission_number");
        }
        file = read_file("/quest/NPC");
        npcs = explode(file,"\n");
        file = read_file("/quest/OBJ");
        objs = explode(file,"\n");
        timep = random(300)+60;   //  big random factor
// A factor here to make time random
        timep = random(timep/2)+timep/2;
        time_period(timep, me);
        if(random(2))
        {
        mission = npcs[random(sizeof(npcs))];
        tell_object(me,"替天宗杀了"+mission+"。\n"NOR);
        sysmsg +="杀了"+mission+"。";
        }
        else
        {
        mission = objs[random(sizeof(objs))];
        tell_object(me,"去抢"+mission+"给天宗。\n"NOR);
        sysmsg +="去抢"+mission+"。";
   }
        me->set("mission/name", mission);
//        me->add("vendetta/authority",1);
        me->set("mission_time", (int) time()+(int) timep);
        if((int)me->query_temp("mission_number") < 5)
        me->add_temp("mission_number",1);
        CHANNEL_D->do_sys_channel("qst", sprintf("%s(%s)：%s",
        me->query("name"),me->query("id"),sysmsg)); 
return 1;
} 
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t; 
        if(d) time = chinese_number(d) + "天";
        else time = ""; 
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒"; 
        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n在" + time + "内");
        sysmsg = "在" + time + "内";
        return 1;
}
int give_hint()
{
        object me,obj;
        me = this_player();
        obj = this_object();
        if(me->query("combat_exp") < 15000000)
        {
        tell_object(me,"连城璧道：＂〔天宗〕是当今武林中最神秘，邪恶的帮会，它笼络天下各
派高手，以暗杀方式来铲除异己。〔天宗〕的主人－－天孙的身份也是个天大的迷。
〔天宗〕经常无故残杀天下老少英雄，以巩固自己在武林中的地位！\n");
                return 1;
   }
        else{
           if(!me->query("天宗/加入失败")&& !me->query_temp("天宗/准备杀杨凡"))
           {
             tell_object(me,"连城璧道：＂你似乎对〔天宗〕很感兴趣，是否想加入呢（answer yes/no）？＂\n");
             add_action("answer_lian", "answer");
           }
           else if( me->query_temp("天宗/准备杀杨凡") )
                 tell_object(me,"连城璧道：我给你的任务你没有完成吧！\n");
           else 
               tell_object(me,"连城璧冷笑一声，没有说话。\n");
           return 1;
        } 
}
int answer_lian(string arg)
{
	object me;
	me = this_player();
	
	if(arg == "yes" || arg == "YES")
	{
		tell_object(me,"连城璧对你说道：既然如此，你去把杨凡的人头给我拿来，
我就让你进天宗！\n");
		me->set_temp("天宗/准备杀杨凡",1);
		return 1;
	}
	else if(arg == "no" || arg == "NO")
	{       
		tell_object(me,"连城璧微笑道：我是考验你的，（天宗）是极邪，极毒的组织，
如果你加入了，我是不会放过你的！\n");
		me->set("天宗/加入失败",1);
                return 1;
         }
         else
         {
         	tell_object(me,"连城璧惊诧道：你说什么啊，我不明白！\n");
         	return 1;
        }
}
void accept_member(object me)
{
        command("smile");
        command("enroll "+me->query("id"));
        tell_object(me,"连城璧在你耳边悄声道：
＂其实我就是〔天宗〕的少主，从今以后，你就为〔天宗〕出力吧！我绝对不会亏待你的！
你可以向天孙要任务（mission），但你一定要证明你是强者！完成任务去天孙那里领取奖励
(filish)＂\n");
        me->delete("天宗/入天宗");
        me->set("organization/org_name","天宗");
        me->set("organization/性质","邪");
        me->set("organization/org_level",0);
        CHANNEL_D->do_sys_channel("info",sprintf("%s，某人秘密加入了邪派组织%s。",NATURE_D->game_time(),me->query("organization/org_name")) );
        me->save();
} 
void attempt_join(object me)
{
        if(me->query("天宗/入天宗"))
           accept_member(me);
        else
        message_vision("连城璧微笑不语.........\n",this_object());
}  

void greeting(object me)
{
        if(!me ||environment(me)!=environment())
                return ;
        if(!living(me))
                me->revive();
	if( me->query("improbity")>=800 && me->query("improbity") < 3000 && me->query("organization/org_level") != 5){
	   message_vision(CYN"$N拍拍$n的肩膀说到：“好兄弟，看你对天宗如此衷心，加上你为组织立了不少功劳，\n天孙将让你担任一个重要职务，好好干吧！！”\n"NOR,this_object(),me);
	   me->set("organization/org_title",CYN"快骑"NOR);
	   me->set("organization/org_level",5);      //除了成员外最低的职务
	   me->save();
	   tell_object(me,"恭喜你成为天宗"+CYN"快骑"NOR+"。\n");
	   CHANNEL_D->do_sys_channel("info",sprintf("组织任命：%s，某人被任命为%s的%s。",NATURE_D->game_time(),me->query("organization/org_name"),me->query("organization/org_title")) );
	}
	if( me->query("improbity")>=3000 && me->query("improbity")<8000 && me->query("organization/org_level") != 4){
	   message_vision(CYN"$N对这$n微微一笑，然后慢慢说到：“没有想到兄弟如此的干练，天宗就是需要你这样狠毒干练之人，\n天宗的"+RED"夺命追魂"NOR+"还空缺着，你去任职吧！”\n"NOR,this_object(),me);
	   me->set("organization/org_title",RED"夺命追魂"NOR);
	   me->set("organization/org_level",4);
	   me->save();
	   tell_object(me,"恭喜你成为天宗"+RED"夺命追魂"NOR+"。\n");
	   CHANNEL_D->do_sys_channel("info",sprintf("组织任命：%s，某人被任命为%s的%s。",NATURE_D->game_time(),me->query("organization/org_name"),me->query("organization/org_title")) );
	   }
        return ;
}  