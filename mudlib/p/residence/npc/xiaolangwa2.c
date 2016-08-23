#include <ansi.h>
 inherit NPC;
 int qingtie();
 int ask_ranran();
void create()
{
        set_name("ȻȻ", ({ "ranran",}) );
        set("gender", "Ů��");
        create_family(HIG"����ɽׯ"NOR,0,HIC"�ܹ�"NOR);
        set("age", 25);
        set("cps", 15);
        set("int",50);
        set("per", 100);
        set("long",
"����һλ�����Ըе�Ů�ԣ�����������͸¶���ϻ۵�����\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 5000000);
        set("difficulty", 2);
        set("inquiry", ([
        "����"   :  (: qingtie :),
        "qingtie" : (: qingtie :),
        "xiaolang" : (: ask_ranran :),
        "��ʮһ��" : (: ask_ranran :),
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
			message_vision(MAG"$N����$n������΢Ц����������ʲô�Ը���\n"NOR,this_object(),ob);
			command("smile");
     //add lsky
/*                	if((string)me->query("id") == "lsky"){
				message_vision(MAG"$N����$n������΢Ц���������򸣡�\n"NOR,this_object(),ob);
				command("smile");
               		}  */
               	}
               
    else {
        message_vision(HIC"$N΢Ц��������Ѫ���ȷ磬����������ɽׯ������ֲ��������ˡ�\n"NOR,this_object());    
        if ( !qingtie=present("qingtie",me)){
			  message_vision(HIR "\n$N��$n��Цһ������Ū����ׯ���������Ͳ����������ɽׯ��\n"NOR,this_object(),me);
        call_out("do_faint", 0, this_player());
        		                                }   
          }  
        		            
    if( me->query("water")<= 100 ){
          if((string)me->query("id") == "xiaolang" ){
               message_vision(HIW"$N��$n˵�����ӣ�ū�Ϊ��׼����һ��ˮ�ƽӷ�ϴ����\n΢Ц�ţ�ֻ��$N����$n��������е�����ι��$n�ȡ�\n"NOR,this_object(),ob);
               me->set("water",200);                }
          else {
               message_vision(HIR"$N��$n˵��������˵�ˣ����ǿ��˿ڿʵĻ���Ӧ��ʱ����ˮ�ơ�����һ�䣬���ֵݸ�$nһ����Ҷ�ࡣ\n"NOR,this_object(),ob);
							 message_vision(HIC"$N�ӹ���Ҷ�࣬һ�����������ѾƱ��ݻ���$n��\n"NOR,ob,this_object());
							 me->set("water",200);
               command("smile");
               }  
                                  } 
    if( me->query("food")<= 100 ){  
          if((string)me->query("id") == "xiaolang"){
               message_vision(HIW"$N��$n˵�����Ӽ�Ȼ���ˣ�ū澾ͷ������Щ������Σ�\n$N��ʯ���ϵĵ�����������$n�ԡ�\n"NOR,this_object(),ob);
               me->set("food",200);                }
          else {
               message_vision(HIR"$N��$n˵��������ɽׯ�����ܰѿ��˶��ˣ����Щ���ĳ伢�ɡ�\n"NOR,this_object(),ob);
							 message_vision(HIC"$N���˿������ϵľ��µ��ģ�������˼������������\n"NOR,ob,this_object());
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
         message_vision(HIG"$N��$n΢Ц�����ѵ�����û��������ô��\n"NOR,this_object(),me);
        return 1;
                                                }   
    message_vision(HIG"$N�������ó�һ�ſհ�������$n��\n\n"NOR,this_object(),me);
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
           message_vision(WHT"$N��������Ȼ�������Ҽ�ׯ������ô�������ʶ���ˣ�(answer yes/no)��\n"NOR,this_object()); 
           me->set_temp("answer",1);
           add_action("do_answer", "answer");
        }
        else message_vision(WHT"ȻȻ������ش�$N������......\n"NOR,me);
        return 1;
} 
 
 void die(){
         message_vision(HIR"$N��Ц��������ɽׯ�����ǲ�����!\n"NOR, this_object());
        "/cmds/imm/full"->main(this_object(),"");
} 

int do_faint(object me)
{       
        if (!objectp(me) || me->is_ghost() || environment(me)!=environment(this_object()))
                return 1;
   	        message_vision(HIC "ֻ��ȻȻ����һ�ӣ�������������ҪѨ��$N���С����ã����������������ˣ�\n"NOR,this_player());
            me->unconcious();
            message_vision(HIC "ȻȻһ�Ű��ε���$N�߳�ɽׯ�⣬̾������Ϊʲô��������ô�����ĵ����أ�\n"NOR,this_player());
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
                if( name == "ȻȻ")
                {        
                        if( (string)player->query("id")=="xiaolang" ){
                           message_vision(RED"$NͻȻ�붯��ɱ$n��\n"NOR,player,this_object());
        		               message_vision(HIW"\nȻȻ��æ��$N�¹����ū����������ˣ���ׯ�����\n"NOR,player);
        		            return 1;
        		                }
                        if (weapon = present("sword", this_object())) {
                                message_vision(HIW"$N̾��һ��������������ɽׯ���ҵ���ֻ��һ���֣�������\n"NOR, this_object());
                                message_vision("$N���������彣��\n", this_object());
                                weapon->wield();
                                call_out("do_unwie", 3);
                                }
                        return 0;
               }
               if( id == "xiaolang")
               {
                  message_vision(RED"$N��Цһ������������ɽׯ�ﾹȻ��ɱׯ�����ѵ�������ˣ���\n"NOR, this_object());
                  weapon = present("sword", this_object());
                  if(weapon)
                    {
                    message_vision("$N��������һ���彣��\n", this_object());
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
                message_vision(BLU"$N����ķ������еĽ����������쳣�����ʣ�\n"NOR, this_object());
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
        message_vision(CYN"$N��ȻȻ���ͷ����ʾ��ʶ��ʮһ�ɡ�\n"NOR,me);
        message_vision(WHT"ȻȻ��$N��ȻһЦ������Ȼ�����Ҽ����˵����ѣ�������ϲ����һ�仰��ʲô��(like)\n"NOR,me);
        me->set_temp("answering",1);
        me->delete_temp("answer");
        add_action("do_like", "like"); 
        return 1;
     }
     else if( arg == "no" || arg == "NO" )
     {    
          message_vision(CYN"$N��ȻȻҡҡͷ��\n"NOR,me);
          command("sigh");
          message_vision(WHT"ȻȻ��$N����"+me->name()+"Ҳ������ˣ���Ȼ����ʶ��Ҳ�Ͳ��ض����ˣ�\n"NOR, obj);
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
        
    if( arg == "ѧ�����" )
    {   
        message_vision("$NС���ض�ȻȻ����˵�˼��䡣\n",me);
        message_vision(WHT"ȻȻ����¶���˲��õ�Ц�ݣ�ͻȻ����$N�Ķ���......\n"NOR,me);
      	tell_object(me, HIW"ȻȻ���ĵ�������ߵ�:������������һ�֣���Ը�����(fangqi)�ĸ���\n"NOR+WHT"����(caizhi)/����(friend)/����(skill)��\n"NOR); 
        me->delete_temp("answering");
        me->set_temp("fangqi",1);
      	add_action("do_fangqi", "fangqi"); 
        return 1;
    }
    return notify_fail(CYN"ȻȻҡҡͷ�������Բ��ԣ�\n"NOR);
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
        message_vision("$N��$n�������ĵ�˵��ʲô��\n",me,obj);
        message_vision(WHT"$N΢΢һЦ����$n������������о��������Ȥ����\n"NOR,obj,me);
      	tell_object(me, HIW"ȻȻ������:����������һ�֣���Ը������(liuxia)�ĸ���\n"NOR+WHT"����(friend)/����(skill)��\n"NOR); 
        me->delete_temp("fangqi");
        me->set_temp("fangqi/caizhi",1);
        me->set_temp("liuxia",1);
        me->set("����ɽׯ/���",1);
      	add_action("do_liuxia", "liuxia"); 
      	return 1; 
        break;
        
        case "friend":
        message_vision("$N��$n�������ĵ�˵��ʲô��\n",me,obj);
        message_vision(WHT"$N̾��һ��������$n�������ѵ�����Ҫ������ô������һ����ʵ�ļһ\n"NOR,obj,me);
      	tell_object(me, HIW"ȻȻ������:����������һ�֣���Ը������(liuxia)�ĸ���\n"NOR+WHT"����(caizhi)/����(skill)��\n"NOR); 
        me->delete_temp("fangqi");
        me->set_temp("fangqi/friend",1);
        me->set_temp("liuxia",1);
        me->set("����ɽׯ/���",1);
      	add_action("do_liuxia", "liuxia");  
      	return 1;
        break;
        
        case "skill":
        message_vision("$N��$n�������ĵ�˵��ʲô��\n",me,obj);
        message_vision(WHT"$N���ͷ����$n���������м��ء�\n"NOR,obj,me);
      	tell_object(me, HIW"ȻȻ������:����������һ�֣���Ը������(liuxia)�ĸ���\n"NOR+WHT"����(caizhi)/����(friend)��\n"NOR); 
        me->delete_temp("fangqi");
        me->set_temp("fangqi/skill",1);
        me->set_temp("liuxia",1);
      	add_action("do_liuxia", "liuxia");  
      	return 1;
        break;
        
        default:
        break;
   }
    return notify_fail("��Ҫ����ʲô��\n");
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
           message_vision(HIR"$N����һ˫���۾�����$n�����ȵ����㲻����ͷ���������ô��\n"NOR,obj,me);
        }
        else{
           message_vision(WHT"$N����$nһ�ۣ�������Ȼ��һ�������񣬿�ϧ��ô�õĻ�Ե�ͱ����˷��ˡ�\n"NOR,obj,me);
           me->set("����ɽׯ/���",1);
           me->delete_temp("liuxia");
      	   add_action("do_liuxia", "liuxia"); 
      	}
      	return 1; 
        break;
        
        case "friend":
        if( me->query_temp("fangqi/friend") ){
           message_vision(HIR"$N����һ˫���۾�����$n�����ȵ����㲻����ͷ���������ô��\n"NOR,obj,me);
        }
        else{
        message_vision(WHT"$N����ؿ���$n����������������֮ʿ��\n"NOR,obj,me);
        if( !me->query("����ɽׯ/���") ){
           message_vision(WHT"$NͻȻ���صظ�����$nһЩ����\n"NOR,obj,me);
           tell_object(me,MAG"ȻȻ�������ĵ���������һ�仰���������������������ɽ�塣\n"NOR);
           me->set("����ɽׯ/����",1);
        }
           me->set("����ɽׯ/���",1);
           me->delete_temp("liuxia");
      	   add_action("do_liuxia", "liuxia");  
      	}
      	return 1;
        break;
        
        case "skill":
        if( me->query_temp("fangqi/skill") ){
           message_vision(HIR"$N����һ˫���۾�����$n�����ȵ����㲻����ͷ����书��ô��\n"NOR,obj,me);
        }
        else{
            message_vision("$N����$n̾��һ��������Ȼ����˵����\n",obj,me);
            me->delete_temp("liuxia");
            me->set("����ɽׯ/���",1);
      	    add_action("do_liuxia", "liuxia"); 
      	}
      	return 1;
        break;
        
        default:
        break;
   }
    return notify_fail("��Ҫ����ʲô��\n");
 //   return 0;
} 