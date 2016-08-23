 inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIC"����ˮ"NOR, ({ "xiao qiushui" }) );
        create_family(HIG"����ɽׯ"NOR,0,RED"ͳ��"NOR);
        set("gender", "����" );
        set("no_fly",1);
        set("age", 32);
        set("str", 100);
        set("dur",100);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("long", "��������ɽׯ��ȫ��ͳ�죬�����ڹ��������ò�Ҫ������\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                }) );   
        set("combat_exp", 5000000);
        set("attitude", "friendly");
            
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 100);
        set_skill("unarmed",250);
        set_skill("dodge",500);
        set_skill("move",500);
        set_skill("parry",200); 
        set_skill("blade",300);
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
        carry_object("/obj/weapon/sword")->wield();
} 
 void die(){
         message_vision(RED"$N��Цһ����������ɽׯ�����ǲ����ģ�\n"NOR, this_object());
        "/cmds/imm/full"->main(this_object(),"");
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
	object me,qt;
	me=this_player();
        if( !ob || environment(ob) != environment() ) return;   
		if((string)me->query("id") == "xiaolang"){
			 message_vision(MAG"$N����$n����������������ӭׯ����\n"NOR,this_object(),ob);
		return;
               }

    if (qt=present("qingtie",me) && me->query_temp("����ɽׯ/����")){
    	 message_vision(HIW"$N����$n������΢Ц������ӭ��������ɽׯ��ׯ���ڴ��������ʱ�ˣ��룡\n"NOR,this_object(),ob);
    return;}
    else
       message_vision(MAG"$N����Ŀ���$n��������������$n����������\n"NOR,this_object(),ob);
    return;
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
                if( id == "xiao qiushui")
                {        
                        if( (string)player->query("id")=="xiaolang" ){
                           message_vision(RED"$NͻȻ�붯��ɱ$n��\n"NOR,player,this_object());
        		               message_vision(HIW"\n����ˮ��æ��$N�¹������ׯ�����\n"NOR,player);
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
                message_vision(WHT"$N����ķ������еĽ�!\n"NOR, this_object());
                command("get sword");
                command("sigh");
                return 1;
        }
        else
                call_out("do_unwie", 3);
} 