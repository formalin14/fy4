#include <ansi.h>
inherit QUESTNPC;
//inherit F_MASTER;
//inherit SSERVER;
void do_fight();
void create()
{
        set_name("宫九", ({ "gong jiu", "gong" }) );
        set("gender", "男性" );
        set("npc_difficulty",10);
        set("organization/性质","邪");
        set("age", 27);
        set("int", 70);
        set("per", 38);
        set("str", 150);
        set("dur", 35);
        set("cor", 110);
        set("agi",100);
        set("title","太平王府 第七代世子");
        set("long",
"他便是宫九，那个由毒蛇的液，狐狸的心，北海中的冰雪，天山上的岩石，狮子的勇猛，豺狼
的狠辣，骆驼的忍耐，人的聪明，再加上一条来自十八层地层下的鬼魂构成的宫九。\n"
                );
        set("force_factor", 100);
        set("max_gin", 80000);
        set("max_kee", 100000);
        set("max_sen", 80000);
        set("max_force",4000);
        set("force",4000); 
        set("combat_exp", 130000000);
        set("score", -3000);
        set_skill("unarmed", 600);
        set_skill("sword", 600);
        set_skill("force", 400);
        set_skill("parry", 500);
        set_skill("literate", 300);
        set_skill("dodge", 500);
        
        set("chat_chance",10);
        set("chat_msg",({
                        "宫九刀锋般的目光正盯在你脸上，傲然道“我就是宫九，独一无二的宫九。”\n",
                })      );
//         set("chat_chance_combat",100);
//              set("chat_msg_combat",({
//                      (:do_fight:),
//              })      );
        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/diewusword")->wield();
        add_money("tenthousand-cash",1);
} 
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
} 
void crazy(int i,int exp);
void init()
{       
        add_action("do_show","show");
} 
void begin_crazy(); 
void remove_crazied()
{
        set("crazied",0);
} 
int do_show(string arg)
{       
        object whip,me;
        int i,dayTime; 
        mixed *local; 
        me=this_player();
        
        i=me->query("show_gongjiu");        
        local = NATURE_D->get_current_time(); 
        dayTime = local[5]; 
        
        if(!arg) 
        {
                write("你想给别人看什么东西？\n");
                return 1;
        }
        if( !whip=present(arg,this_player()))
   {       
                write("你身上没有这样东西呀？\n");
                return 1;
        }
/*        if (whip->query("skill_type")!="whip"||query("crazied")||(string)(NATURE_D->outdoor_room_description()) != "    " +
"夜幕低垂，满天繁星，四周一片暗灰。
") */    if ( whip->query("skill_type")!="whip"||query("crazied")||me->query("combat_exp")<25000000 || (dayTime > 240 && dayTime < 1250) )
        {
                message_vision("$N拿出手中的"+whip->name()+"给$n看，但$n什么反应都没有。。。\n",this_player(),this_object());
                return 1;
        }
        if (random(10) >= i){	
        	message_vision("$N拿出手中"+whip->name()+"在$n眼前晃了晃\n",this_player(),this_object());
        	begin_crazy();
        	set("crazied",1);
        	call_out("remove_crazied",900);
        	return 1;
        }
        else{
        	message_vision("$N冷冷的看着$n道：“你的把戏还没有玩够么？”\n",this_object(),me);
        	this_object()->kill_ob(me);
        	set("crazied",1);
        	return 1;
        }
        
} 
void begin_crazy()
{
        object weapon;
        object me,ob;
        int exp; 
        ob=this_object();
        me=this_player();
        
//      weapon=me->query_temp("weapon");
//      if(!this_object()->query_temp("crazy") )
//      if (weapon->query("skill_type")=="whip") 
        {
                message_vision("宫九脸色忽然大变，两眼逐渐变红，倒在地上撕叫翻滚起来。\n",this_object());
                exp=this_object()->query("combat_exp");
                this_object()->delete("no_busy");
                this_object()->start_busy(100);
                this_object()->set("combat_exp",1);
                if(me->query("show_gongjiu") <= 8) { me->add("show_gongjiu",1);me->save();}         //把show鞭子的次数加1，加到9，那么最后的成功率只有1/10
                call_out("crazy",4+random(1),0,exp);
                return;
        }
}  
void crazy(int i,int exp)
{       
        object ob,me,weapon;
   
        ob=this_object();
        me=this_player();
        weapon=me->query_temp("weapon"); 
        if(ob)
        if (!weapon||weapon->query("skill_type")!="whip"||i>12)
        {
                message_vision("$N忽又恢复了冷静，冷冷的望着$n道：“凡是和我作对的，都只有死路一条。”\n",ob,this_player());
                ob->stop_busy();
                ob->set("no_busy",10);
                ob->set("combat_exp",exp);
//              ob->set("kee",ob->query("max_kee"));
                ob->delete_temp("crazy");
                return;
        }
        else
        {       
                if(!random(2))
                        message_vision("宫九的气息喘动如一头奔跑了数十里的蛮牛，已经疯狂般撕扯自己的衣服，喘着气，狂叫道：“打我，打我。”\n",ob);
                ob->receive_damage("kee",5000);
                call_out("crazy",1+random(1),i+1,exp);
        }
}   
int accept_fight(object me)
{
	command("grin");
        command("say 你很喜欢打架么？除了打架你不知道还有很多美好的事情么？");
        return 0;
}