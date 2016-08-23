 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��ʮһ��", ({ "xiaolang"}) );
        set("gender", "����" );
        set("age", 25);
        set("per", 50);
        set("attitude", "peaceful");
        set("class","quest_npc");
        set("max_atman", 50000);
        set("atman", 50000);
        set("max_force", 50000);
        set("max_kee",999999);
        set("max_sen",999999);
        set("max_gin",999999);
        set("kee",999999);
        set("gin",999999);
        set("sen",999999);
        set("force", 5000);
        set("max_mana", 30000);
        set("force_factor",500);
        set("mana", 30000);
        set("no_busy",99);
        set("resistance/kee",90);
    	set("resistance/sen",90);
    	set("resistance/gin",90);
    
        set("long",     "��ȫ����һ������װ������ȥ����ɢɢ��������ͻȻ������\n�ӱ��������˳�������û��˯��һ��������Զ����������ν�����ӡ�\n");
        set("combat_exp", 999999999);
    	set("title", WHT"����ɴ���׷��"NOR);
    	set("nickname",HIR"����NPC��������ɱ�ҿ���"NOR);
        set_skill("blade", 1000);
        set_skill("unarmed",1000);
        set_skill("dodge", 1000);
        set_skill("force", 1000);
        set_skill("doomforce", 500);
        set_skill("parry",1000);
        set_skill("move",1000);
        set_skill("moon-blade",500);
        set_skill("sky-steps",1000);
        set_skill("perception",1000);
        map_skill("move","sky-steps");
        map_skill("dodge","sky-steps");
        map_skill("parry","moon-blade");
        map_skill("blade","moon-blade");
        map_skill("force","doomforce");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
		(:perform_action,"blade.yueshen-feidao":),
        }) );
        setup();
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}
void die(){
         message_vision("$N��Ц��һ������ɱ�ң��Ŷ���û�У���\n", this_object());
        "/cmds/imm/full"->main(this_object(),"");

}
void init()
{       
        object ob; 
   ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch(random(3)){
        case 0:
		message_vision("$N������Զ����������˼......\n",this_object());
		break;
	case 1:
		message_vision("$N��̾�����������Ҳ��ȥ�����ҽ����ˣ�Ҫ�����ӹǶ�ɢ�ˡ���\n",this_object());
		break;
	case 2:
		message_vision("$N������ص�����û��˯����......���ֱ���������......\n",this_object());
		break;
	}
}  
