#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("������", ({ "feng xiaoxiao","xiaoxiao" }) );
        set("gender", "Ů��" );
        set("title",HIG"С����Ů"NOR);
        set("long",
     "���������ֽ����ʮ�˾�Ψһ����Ů��\n"
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
             "�������૵�˵������֪����������ϲ����ʲô���Ĳ��ȡ�\n",
             (: random_move :),
        }) ); 
        setup();
        carry_object("/d/resort/npc/obj/pink_cloth")->wear();
        carry_object("/d/resort/npc/obj/shoe")->wear();
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

int accept_fight(object me)
{
        command("emote ҡͷ�����Ҳ�ϲ����ܡ�");
        command("shy");
        return 0;
}
       
void greeting(object ob)
{   

  message_vision("$N����$n΢΢һЦ��\n", this_object(),ob );
  return;
}   


