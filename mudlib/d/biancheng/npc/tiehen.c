#include <ansi.h>
#include <command.h> 
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{ 
        set_name("铁恨",({"tie hen","tie"}));
        set("nickname","铁手无情");
        set("title",WHT"四大名捕"NOR);
        set("long", "
一个身子标枪般笔挺的黑衣人，冷漠的脸，残酷的眼神。他就是六扇门里，四大名
捕中的“铁手无情”，他恨的是乱臣贼子，盗匪小人。这七年来，被他侦破的巨案，
已不知有多少。。\n");
        set("age",47);
        set("combat_exp", 7000000);
        set("attitude", "friendly");    
        
        set("force_factor",100); 
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set_skill("dual-attack",200);
        
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
                (: auto_smart_fight(30) :),    
        }) );*/
                
//        auto_npc_setup("xuebin",250,190,0,"/obj/weapon/","fighter_w","dragonstrike",2);
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear();
        carry_object(__DIR__"obj/jade");
} 
void init() {
        
   object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        call_out("ask_question_1",1,ob); 
} 
int ask_question_1(object who)
{
        
        if (who->query("parrot/赴太平镇",1)) {
                message_vision(CYN"$N对$n说：“怎么样，有线索了么？”\n"NOR,this_object(),who);
                return 1;
        }
        if (who->query("m_killer/海龙王") && !who->query_temp("parrot/t_question_1")
                && !who->query("parrot/t_question_1")) {
                message_vision(HIR"\n$N看了$n一眼说：我知道海龙王一家十人，忽然在一夜之间死得干干净净。这
事和你有没有关系？”\n",this_object(),who);
                tell_object(who,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
                who->set_temp("answer_person",1);
                who->set_temp("parrot/t_question_1",1);
                return 1;
        }
        if (who->query("parrot/listen_to_story") && !who->query_temp("parrot/t_question_2")
                && !who->query("parrot/t_question_2") ) {
                message_vision(HIR"\n$N看了$n一眼说：我正在调查七年前富贵王的珠宝失窃一案，主嫌的兄弟郭易
据说潜逃于此，你是否见过？”\n",this_object(),who);
                tell_object(who,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
                who->set_temp("answer_person",2);
                who->set_temp("parrot/t_question_2",1);
                return 1;
        }
        //屏蔽相助
/*        if (who->query("parrot/t_question_1") && who->query("parrot/t_question_2")
                &&!who->query_temp("parrot/t_question_3")) {
           message_vision(HIR"\n$N说：好，阁下真乃义士，不知是否愿意相助在下一事？”\n",this_object(),who);
                tell_object(who,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
                who->set_temp("answer_person",3);
                who->set_temp("parrot/t_question_3",1);
                return 1;
        }   */
} 
int do_answer(string arg)
{
        object who,*inv,jade;
        int i, gotit;
        
        who=this_player();
        
        if(!who->query_temp("answer_person")) return 0;
        if (who->query_temp("answer_person")==1) {
                if(arg=="yes")
                {
                        message_vision(CYN"$N点了点头。\n"NOR,who);
                        message_vision(CYN"$N击掌笑道：“杀的是该杀的人，杀人后空手而去，不取分文，佩服！“\n",this_object());
                        who->delete_temp("answer_person");
                        who->set("parrot/t_question_1",1);
                        call_out("ask_question_1",1,who);
                        return 1;       
                }
                if(arg=="no"){
                        message_vision(CYN"$N赶紧摇了摇头。\n"NOR,who);
                        message_vision(CYN"铁恨说：我正在追拿凶犯，不是你就好。\n"NOR,who);
                        who->delete_temp("answer_person");
                        return 1;
                }
        }
        if (who->query_temp("answer_person")==2) {
                if(arg=="yes")
                {
                        message_vision(CYN"$N点了点头。\n"NOR,who);
                        message_vision(CYN"$N道：“好，他果然在这里，他逃不了了。“\n"NOR,this_object());
                        who->delete_temp("answer_person");
                        who->set("parrot/t_question_2",1);
                        call_out("ask_question_1",1,who);
                   return 1;       
                }
                if(arg=="no"){
                        message_vision(CYN"\n$N赶紧摇了摇头。\n\n"NOR,who);
                        message_vision(CYN"$N喝道：大胆！我明明见你与他会面，为何隐瞒，跟我到衙门里去说话！\n"NOR,this_object());
                        who->delete_temp("answer_person");
                        this_object()->kill_ob(who);
                        who->kill_ob(this_object());
                        return 1;
                }
        }
        if (who->query_temp("answer_person")==3) {
                if(arg=="yes")
                {
                        message_vision(CYN"$N一拱手：在下对铁捕头侠义心肠心仪已久，敢不从命？\n"NOR,who);
                        command("spank "+this_player()->get_id());
                        message_vision(CYN"$N道：“好，我追查太平王府一案已有三年，数月前发现大盗满天飞在出售失窃
的珠宝，费尽心机缉拿入狱，审问时他却突然毒发身亡，仅供出“鹦鹉“二字。满
天飞赃物据闻源自陕西一个叫做太平镇的地方。我沿着蛛丝马迹追查至此，却发现
处处有人监视截杀。我看见你杀入七海山庄，诛除海龙王这个恶贼之时，已经知道
你是一个正义的剑客，所以想请你助我一臂之力，先到太平镇勘查，待我打发掉跟
踪之人再与你会合。太平镇虽小，敌友难分，你需处处小心，慎重行事。“\n"NOR,this_object());
                        
                        inv=all_inventory(this_object());
                        for (i=0;i<sizeof(inv);i++){
                                if (inv[i]->query("id")=="jade") gotit=1;
                        }
                        if (!this_player()->query("parrot/赴太平镇") && !gotit) {
                                jade=new(__DIR__"obj/jade");
                                jade->move(this_object());
                                gotit=1;
                        }
                        if (gotit) {
                                ccommand("give jade to "+this_player()->get_id());
                                message_vision("$N又道：“你可凭此碧玉去找一个叫韦七娘的女子。“\n",this_object());
                        }
                        who->delete_temp("answer_person");
//      finish with 坟场 riddle, "parrot/赴太平镇" is the mark to carry on. 
//      If the player loses the jade, kill tie hen can get one.
                        who->set("parrot/赴太平镇",1);
                   who->delete("parrot/t_question_1");
                        who->delete("parrot/t_question_2");
                        return 1;       
                }
                if(arg=="no"){
                        message_vision(CYN"$N犹豫不决地摇了摇头。\n"NOR,who);
                        message_vision(CYN"$N失望地叹了口气说：人各有志，我不勉强。\n"NOR,this_object());
                        who->delete_temp("answer_person");
                        return 1;
                }
        }
        return 0;
}        
