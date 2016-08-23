#include <ansi.h>
 inherit NPC;
 int qingtie();
 int ask_ranran();
void create()
{
        set_name("然然", ({ "ranran",}) );
        set("gender", "女性");
        create_family(HIG"忘忧山庄"NOR,0,HIC"总管"NOR);
        set("age", 25);
        set("cps", 15);
        set("int",50);
        set("per", 100);
        set("long",
"这是一位成熟性感的女性，明亮的眸子透露出聪慧的眼神。\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 5000000);
        set("difficulty", 2);
        set("inquiry", ([
        "请帖"   :  (: qingtie :),
        "qingtie" : (: qingtie :),
        "xiaolang" : (: ask_ranran :),
        "萧十一郎" : (: ask_ranran :),
        ]));  
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 100); 
        
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 250);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("move", 250);
        set_skill("huanhua-steps",500);
        set_skill("huanhua-sword", 500);
        
        map_skill("sword", "huanhua-sword"); 
        map_skill("dodge", "huanhua-steps");
        map_skill("move",  "huanhua-steps");
        map_skill("parry", "huanhua-sword");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jingtianyijian" :),
                (: perform_action, "dodge.hongyeluanfei" :),
        }) ); 
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword");
}
void init()
{       
        object ob; 
        ::init();
        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob,object obj)
{    
	object me;
	object qingtie;
	me=this_player();
        if( !ob || environment(ob) != environment() ) return;   
		if((string)me->query("id") == "xiaolang" || (string)me->query("id") == "lsky"){
			message_vision(MAG"$N看到$n进来，微笑道：主人有什么吩咐？\n"NOR,this_object(),ob);
			command("smile");
     //add lsky
/*                	if((string)me->query("id") == "lsky"){
				message_vision(MAG"$N看到$n进来，微笑道：夫人万福。\n"NOR,this_object(),ob);
				command("smile");
               		}  */
               	}
               
    else {
        message_vision(HIC"$N微笑道：江湖血雨腥风，生活在忘忧山庄是最快乐不过的事了。\n"NOR,this_object());    
        if ( !qingtie=present("qingtie",me)){
			  message_vision(HIR "\n$N对$n冷笑一声道：弄丢了庄主的请帖就不配呆在忘忧山庄！\n"NOR,this_object(),me);
        call_out("do_faint", 0, this_player());
        		                                }   
          }  
        		            
    if( me->query("water")<= 100 ){
          if((string)me->query("id") == "xiaolang" ){
               message_vision(HIW"$N对$n说：公子，奴婢为你准备了一杯水酒接风洗尘。\n微笑着，只见$N坐在$n怀里，把手中的美酒喂给$n喝。\n"NOR,this_object(),ob);
               me->set("water",200);                }
          else {
               message_vision(HIR"$N对$n说道：主人说了，若是客人口渴的话，应随时奉上水酒。话音一落，伸手递给$n一杯竹叶青。\n"NOR,this_object(),ob);
							 message_vision(HIC"$N接过竹叶青，一饮而尽，并把酒杯递还给$n。\n"NOR,ob,this_object());
							 me->set("water",200);
               command("smile");
               }  
                                  } 
    if( me->query("food")<= 100 ){  
          if((string)me->query("id") == "xiaolang"){
               message_vision(HIW"$N对$n说：公子既然饿了，奴婢就服侍你吃些点心如何？\n$N从石桌上的点心拿起来给$n吃。\n"NOR,this_object(),ob);
               me->set("food",200);                }
          else {
               message_vision(HIR"$N对$n说道：来到山庄，不能把客人饿了，请吃些点心充饥吧。\n"NOR,this_object(),ob);
							 message_vision(HIC"$N看了看桌子上的精致点心，随便拿了几快吃了起来。\n"NOR,ob,this_object());
							 me->set("food",200);
               command("smile");
               }  
                                  }     
 }
 
 int qingtie()
{
    object me;
    object qingtie;

    me = this_player();
    
    if ((string)me->query("id") != "xiaolang") {
         message_vision(HIG"$N对$n微笑道：难道主人没有邀请你么？\n"NOR,this_object(),me);
        return 1;
                                                }   
    message_vision(HIG"$N从身上拿出一张空白请帖给$n。\n\n"NOR,this_object(),me);
    qingtie = new("/p/residence/obj/qingtie"); 
    if(objectp(qingtie)){
    qingtie->move(me);
                    }   
    return 1;
} 

int ask_ranran(){
        object me;
        me = this_player();
        if( !me->query_temp("ask_xiaolang") ){
           message_vision(WHT"$N道：“既然你问起我家庄主，那么你就是认识他了？(answer yes/no)”\n"NOR,this_object()); 
           me->set_temp("answer",1);
           add_action("do_answer", "answer");
        }
        else message_vision(WHT"然然不再想回答$N的问题......\n"NOR,me);
        return 1;
} 
 
 void die(){
         message_vision(HIR"$N诡笑道：忘忧山庄的人是不死的!\n"NOR, this_object());
        "/cmds/imm/full"->main(this_object(),"");
} 

int do_faint(object me)
{       
        if (!objectp(me) || me->is_ghost() || environment(me)!=environment(this_object()))
                return 1;
   	        message_vision(HIC "只见然然右手一挥，齐点你周身各大要穴，$N暗叫“不好！”，但是来不及了！\n"NOR,this_player());
            me->unconcious();
            message_vision(HIC "然然一脚把晕倒的$N踢出山庄外，叹气道：为什么总是有这么多无聊的人呢？\n"NOR,this_player());
            me->move("/p/residence/xiaolang1");
            return 1;
} 

int do_killing(string arg)
{       
        object player, victim, weapon;
        string name,id;
        if(!arg) return 0;
        player = this_player();
        		
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = victim->name();
                id = victim->query("id");
                if( name == "然然")
                {        
                        if( (string)player->query("id")=="xiaolang" ){
                           message_vision(RED"$N突然想动手杀$n。\n"NOR,player,this_object());
        		               message_vision(HIW"\n然然慌忙向$N下跪道：奴婢哪里做错了？请庄主赎罪！\n"NOR,player);
        		            return 1;
        		                }
                        if (weapon = present("sword", this_object())) {
                                message_vision(HIW"$N叹了一口气道：在忘忧山庄捣乱的人只有一个字：死！。\n"NOR, this_object());
                                message_vision("$N从腰间抽出佩剑！\n", this_object());
                                weapon->wield();
                                call_out("do_unwie", 3);
                                }
                        return 0;
               }
               if( id == "xiaolang")
               {
                  message_vision(RED"$N冷笑一声道：在忘忧山庄里竟然敢杀庄主，难道不想活了？！\n"NOR, this_object());
                  weapon = present("sword", this_object());
                  if(weapon)
                    {
                    message_vision("$N从腰间抽出一把佩剑。\n", this_object());
                    weapon->wield();
                    }
               this_object()->kill_ob(player);
               player->kill_ob(this_object());
               remove_call_out("do_unwie");
               call_out("do_unwie", 3);
               return 0;
               }
        //
                return 0;
        }
        return 0;               
} 
int do_unwie()
{        

        if( !this_object()->is_fighting())
        {     
                command("unwield sword");
                message_vision(BLU"$N轻轻的放下手中的剑，眼神变的异常的蒙胧！\n"NOR, this_object());
                command("get sword");
                command("sigh");
                return 1;
        }
        else
                call_out("do_unwie", 3);
} 

int do_answer(string arg)
{
     object me, obj;
     obj = this_object();
     me =this_player();
     if( !me->query_temp("answer") )
        {                        
          command("smile");
          return 1;
        }
     if( arg == "yes" || arg == "YES" )
     {        
        message_vision(CYN"$N对然然点点头，表示认识萧十一郎。\n"NOR,me);
        message_vision(WHT"然然对$N嫣然一笑道：既然你是我家主人的朋友，那他最喜欢的一句话是什么？(like)\n"NOR,me);
        me->set_temp("answering",1);
        me->delete_temp("answer");
        add_action("do_like", "like"); 
        return 1;
     }
     else if( arg == "no" || arg == "NO" )
     {    
          message_vision(CYN"$N对然然摇摇头。\n"NOR,me);
          command("sigh");
          message_vision(WHT"然然对$N道："+me->name()+"也不过如此，既然不认识，也就不必多问了！\n"NOR, obj);
          me->set_temp("ask_xiaolang",1);
          return 1;
      }
} 

int do_like(string arg)
{
    object me;
    me=this_player();
    
    if( !me->query_temp("answering") )
        {                        
          command("smile");
          return 1;
        }
        
    if( arg == "学会放弃" )
    {   
        message_vision("$N小声地对然然耳旁说了几句。\n",me);
        message_vision(WHT"然然脸上露出了灿烂的笑容，突然凑向$N的耳朵......\n"NOR,me);
      	tell_object(me, HIW"然然悄悄的在你耳边道:让你放弃下面的一种，你愿意放弃(fangqi)哪个？\n"NOR+WHT"才智(caizhi)/朋友(friend)/绝技(skill)。\n"NOR); 
        me->delete_temp("answering");
        me->set_temp("fangqi",1);
      	add_action("do_fangqi", "fangqi"); 
        return 1;
    }
    return notify_fail(CYN"然然摇摇头道：不对不对！\n"NOR);
//    return 0;
} 

int do_fangqi(string arg)
{
    object me,obj;
    me=this_player();
    obj=this_object();
    
    if( !me->query_temp("fangqi") )
        {                        
          command("smile");
          return 1;
        }
    
    switch( arg ) {   
        case "caizhi":
        message_vision("$N在$n耳边悄悄的说了什么。\n",me,obj);
        message_vision(WHT"$N微微一笑，对$n道：看来你对研究不大感兴趣啊。\n"NOR,obj,me);
      	tell_object(me, HIW"然然继续道:再让你留下一种，你愿意留下(liuxia)哪个？\n"NOR+WHT"朋友(friend)/绝技(skill)。\n"NOR); 
        me->delete_temp("fangqi");
        me->set_temp("fangqi/caizhi",1);
        me->set_temp("liuxia",1);
        me->set("忘忧山庄/结局",1);
      	add_action("do_liuxia", "liuxia"); 
      	return 1; 
        break;
        
        case "friend":
        message_vision("$N在$n耳边悄悄的说了什么。\n",me,obj);
        message_vision(WHT"$N叹了一口气，对$n道：你难道不需要朋友了么？倒是一个现实的家伙。\n"NOR,obj,me);
      	tell_object(me, HIW"然然继续道:再让你留下一种，你愿意留下(liuxia)哪个？\n"NOR+WHT"才智(caizhi)/绝技(skill)。\n"NOR); 
        me->delete_temp("fangqi");
        me->set_temp("fangqi/friend",1);
        me->set_temp("liuxia",1);
        me->set("忘忧山庄/结局",1);
      	add_action("do_liuxia", "liuxia");  
      	return 1;
        break;
        
        case "skill":
        message_vision("$N在$n耳边悄悄的说了什么。\n",me,obj);
        message_vision(WHT"$N点点头，对$n道：恩，有见地。\n"NOR,obj,me);
      	tell_object(me, HIW"然然继续道:再让你留下一种，你愿意留下(liuxia)哪个？\n"NOR+WHT"才智(caizhi)/朋友(friend)。\n"NOR); 
        me->delete_temp("fangqi");
        me->set_temp("fangqi/skill",1);
        me->set_temp("liuxia",1);
      	add_action("do_liuxia", "liuxia");  
      	return 1;
        break;
        
        default:
        break;
   }
    return notify_fail("你要放弃什么？\n");
 //   return 0;
} 

int do_liuxia(string arg)
{
    object me,obj;
    me=this_player();
    obj=this_object();
    
    if( !me->query_temp("liuxia") )
        {                        
          command("smile");
          return 1;
        } 
 
    switch( arg ) {   
        case "caizhi":
        if( me->query_temp("fangqi/caizhi") ){
           message_vision(HIR"$N瞪着一双大眼睛看着$n，惊讶道：你不是早就放弃才智了么？\n"NOR,obj,me);
        }
        else{
           message_vision(WHT"$N看了$n一眼，道：果然是一个练功狂，可惜这么好的机缘就被你浪费了。\n"NOR,obj,me);
           me->set("忘忧山庄/结局",1);
           me->delete_temp("liuxia");
      	   add_action("do_liuxia", "liuxia"); 
      	}
      	return 1; 
        break;
        
        case "friend":
        if( me->query_temp("fangqi/friend") ){
           message_vision(HIR"$N瞪着一双大眼睛看着$n，惊讶道：你不是早就放弃朋友了么？\n"NOR,obj,me);
        }
        else{
        message_vision(WHT"$N佩服地看着$n道：公子真乃忠义之士。\n"NOR,obj,me);
        if( !me->query("忘忧山庄/结局") ){
           message_vision(WHT"$N突然神秘地告诉了$n一些话。\n"NOR,obj,me);
           tell_object(me,MAG"然然对你悄悄道：主人有一句话相赠：向西行三里，飞纵入山峰。\n"NOR);
           me->set("忘忧山庄/秘密",1);
        }
           me->set("忘忧山庄/结局",1);
           me->delete_temp("liuxia");
      	   add_action("do_liuxia", "liuxia");  
      	}
      	return 1;
        break;
        
        case "skill":
        if( me->query_temp("fangqi/skill") ){
           message_vision(HIR"$N瞪着一双大眼睛看着$n，惊讶道：你不是早就放弃武功了么？\n"NOR,obj,me);
        }
        else{
            message_vision("$N看着$n叹了一口气，竟然不再说话。\n",obj,me);
            me->delete_temp("liuxia");
            me->set("忘忧山庄/结局",1);
      	    add_action("do_liuxia", "liuxia"); 
      	}
      	return 1;
        break;
        
        default:
        break;
   }
    return notify_fail("你要留下什么？\n");
 //   return 0;
} 