#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("��Ů", ({ "girl","shinv" }) );
        set("gender", "Ů��" );
        set("nickname", HIC"�绨����"NOR );
        set("title",HIG"����ɽׯ"NOR);
        set("long",
     "��ȫ������һ˿���ң�ÿ�缡����͸¶��һ�����ģ�����������ʹ�㲻����Ȼ�Ķ���  \n"
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
             "��Ů����΢�죬��������������Ǽҹ���ү��ϲ�����������Ů�ˡ�\n",
             (: random_move :),
        }) ); 
         set("inquiry", ([
                "��ʮһ��" : "�Ҽ����˳������⣬ż����һЩ���ѻ������͡�\n",
                "xiaolang" : "�Ҽ����˳������⣬ż����һЩ���ѻ������͡�\n",
/*                "���"     :  "���㶼����ʶ�������Ƿ���������ɫ�ǰ������Ҽ������е�һƴ����һ�����˴�\n����������������ǲ���ʵ��\n",
                "teatea"   :  "���㶼����ʶ�������Ƿ���������ɫ�ǰ������Ҽ������е�һƴ����һ�����˴�\n����������������ǲ���ʵ��\n",
                "����"     : "�Ҽҷ������ڱչأ������������ס������֮ǰ�����Ǻúõġ����̡����ӡ�",
                "coco"     : "�Ҽҷ������ڱչأ������������ס������֮ǰ�����Ǻúõġ����̡����ӡ�",
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
        if ( ob->query("gender") == "����")
	{     
		if((string)me->query("id") == "xiaolang"){
			message_vision(MAG"$N����$n����������һ���򸣵�������ׯ����\n"NOR,this_object(),ob);
			command("bow");
                                              }
		else {
			     if ( !qingtie=present("qingtie",me) ){
			     			message_vision(HIR "\n$N��$n�����ȵ���û��ׯ���������������Ҵ���\n"NOR,this_object(),me);
        		    call_out("do_faint", 2, this_player());
        		            }    
		       if(random(10)==0)
		       	   message_vision(HIR"$N��$nգ��գ�۾���Ȼ��ͻȻ�����죬�����ڵȴ�ʲô��$n��������������̲�ס����ȥ����(kiss)����\n"NOR,this_object(),ob);

		       command("smile");
		       message_vision(HIC"$N��$n΢΢һЦ��˵��ׯ���Ը����ˣ����˾��ǿͣ�������������ɡ�\n"NOR,this_object(),ob);
          }
	}
/*        else {  
             if((string)me->query("id") == "coco"){
             	command("smile coco");
             	message_vision(MAG"$N����$n���������˵ؽе������˻����˰���Ҫ��Ҫ��ū澰�����ˮϴ���裿\n"NOR,this_object(),ob);
                                                } */
             else {
             if((int)me->query("age")<= 30)
									message_vision(HIM"$N����$n��΢Ц������λС�㣬����ɽׯ����ô��\n"NOR,this_object(),ob);                
             else
								  message_vision(HIC"$N��$nЦ��:����ү˵�ˣ���СŮ�����ź��㡣\n"NOR,this_object(),ob);
                  }
//             }   
}

int kill_ob(object me)
{
        message_vision("$Nת���뿪�����������ݴ�����������ɽׯ����ɱ�ˣ��������޲��硣 \n",this_object());
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
		return notify_fail ("��׼����˭��\n");
        	}
        else {
        	remove_call_out("greeting");
        	message_vision(CYN "\n$N���β�ס�Լ���������Ů��׼������.....\n"NOR,this_player());
		if((string)me->query("id") != "xiaolang"){
			message_vision(CYN "\n$N��Цһ������������ʲô������Ҳ�����ң���\n"NOR,this_object());
        		call_out("do_faint", 2, this_player());
        					}
        	else  {
        	       message_vision(HIC "\n$N����Ů��С����������һ�¡�\n"NOR,this_player());
        	       message_vision(HIR "\n$N����һ�죬���������ӣ���Ȼ����ʮ�ָ��ˡ�\n"NOR,this_object());
        	       command("kiss xiaolang");
			}
        	}
        	return 1;
} 

int do_faint(object me)
{       
        if (!objectp(me) || me->is_ghost() || environment(me)!=environment(this_object()))
                return 1;
   	message_vision(HIC "\nͻȻһ������Ʈ����$Nֻ�����Լ�����һ��......\n"NOR,this_player());
   	message_vision(HIC "��֪����������һ��������һ���Ӱ�$N�߳���ɽׯ��\n"NOR,this_player());
        me->move("/p/residence/room4");
        me->unconcious();
        return 1;
} 












