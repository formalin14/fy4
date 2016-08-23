#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("侍女", ({ "girl","shinv" }) );
        set("gender", "女性" );
        set("nickname", HIC"如花似玉"NOR );
        set("title",HIG"忘忧山庄"NOR);
        set("long",
     "她全身上下一丝不挂，每寸肌肤都透露出一种妩媚，那阵阵幽香使你不觉怦然心动。  \n"
                );
        set("attitude", "peaceful");
         set("age", 20);
        set("str", 15);
        set("cps", 15);
        set("int",30);
        set("per", 70);
        set("combat_exp", 100000);
        set("force", 200);
        set("max_force", 200);
        set("mana", 100);
        set("max_mana", 100);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force_factor", 10);
        set("chat_chance", 50);
        set("chat_msg", ({
             "侍女脸颊微红，自言自语道：咱们家公子爷最喜欢温柔贤淑的女人。\n",
             (: random_move :),
        }) ); 
         set("inquiry", ([
                "萧十一郎" : "我家主人常年在外，偶尔带一些朋友回来作客。\n",
                "xiaolang" : "我家主人常年在外，偶尔带一些朋友回来作客。\n",
/*                "茶茶"     :  "这你都不认识啊，他是风云里最大的色狼啊，和我家主人有得一拼，有一次主人带\n他来这里，他的手总是不老实。\n",
                "teatea"   :  "这你都不认识啊，他是风云里最大的色狼啊，和我家主人有得一拼，有一次主人带\n他来这里，他的手总是不老实。\n",
                "冰心"     : "我家夫人正在闭关，不常来这里居住，她走之前叫我们好好的“服侍”公子。",
                "coco"     : "我家夫人正在闭关，不常来这里居住，她走之前叫我们好好的“服侍”公子。",
*/                 ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}    


void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                add_action("do_kiss", "kiss");
                call_out("greeting", 1, ob);
        }
} 

void greeting(object ob)
{    
	object me,qingtie;
	me=this_player();
        if( !ob || environment(ob) != environment() ) return;
        if ( ob->query("gender") == "男性")
	{     
		if((string)me->query("id") == "xiaolang"){
			message_vision(MAG"$N看到$n进来，道了一个万福道：见过庄主。\n"NOR,this_object(),ob);
			command("bow");
                                              }
		else {
			     if ( !qingtie=present("qingtie",me) ){
			     			message_vision(HIR "\n$N对$n大声喝道：没有庄主邀请贴，还敢乱闯？\n"NOR,this_object(),me);
        		    call_out("do_faint", 2, this_player());
        		            }    
		       if(random(10)==0)
		       	   message_vision(HIR"$N对$n眨了眨眼睛，然后突然噘起嘴，好像在等待什么，$n看的面红心跳，忍不住想上去亲吻(kiss)她。\n"NOR,this_object(),ob);

		       command("smile");
		       message_vision(HIC"$N对$n微微一笑道说：庄主吩咐过了，来了就是客，这个公子请随便吧。\n"NOR,this_object(),ob);
          }
	}
/*        else {  
             if((string)me->query("id") == "coco"){
             	command("smile coco");
             	message_vision(MAG"$N看到$n进来，高兴地叫道：夫人回来了啊，要不要让奴婢帮你烧水洗个澡？\n"NOR,this_object(),ob);
                                                } */
             else {
             if((int)me->query("age")<= 30)
									message_vision(HIM"$N看着$n，微笑道：这位小姐，忘忧山庄好玩么？\n"NOR,this_object(),ob);                
             else
								  message_vision(HIC"$N对$n笑道:公子爷说了，叫小女好生伺候你。\n"NOR,this_object(),ob);
                  }
//             }   
}

int kill_ob(object me)
{
        message_vision("$N转身离开，你听见内屋传来：在忘忧山庄行凶杀人，真是禽兽不如。 \n",this_object());
        destruct(this_object()); 
        return 1;
} 

int do_kiss(string arg)
{
        object *inv;
        object me;
        int i;
        me=this_player();
        if(arg != "girl"){
        	remove_call_out("greeting");
		return notify_fail ("你准备亲谁？\n");
        	}
        else {
        	remove_call_out("greeting");
        	message_vision(CYN "\n$N按奈不住自己，抱着侍女就准备亲吻.....\n"NOR,this_player());
		if((string)me->query("id") != "xiaolang"){
			message_vision(CYN "\n$N冷笑一声，道：你是什么东西，也配亲我？！\n"NOR,this_object());
        		call_out("do_faint", 2, this_player());
        					}
        	else  {
        	       message_vision(HIC "\n$N在侍女的小嘴上亲吻了一下。\n"NOR,this_player());
        	       message_vision(HIR "\n$N脸上一红，看她的样子，显然心中十分高兴。\n"NOR,this_object());
        	       command("kiss xiaolang");
			}
        	}
        	return 1;
} 

int do_faint(object me)
{       
        if (!objectp(me) || me->is_ghost() || environment(me)!=environment(this_object()))
                return 1;
   	message_vision(HIC "\n突然一股幽香飘过，$N只觉得自己身子一轻......\n"NOR,this_player());
   	message_vision(HIC "不知道哪里来的一股力道，一下子把$N踢出了山庄。\n"NOR,this_player());
        me->move("/p/residence/room4");
        me->unconcious();
        return 1;
} 












