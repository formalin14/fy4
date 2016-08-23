#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";
inherit NPC;

//inherit INQUIRY_MSG; 
void create()
{
        set_name("����·",({"fishman wang","fishman","wang"}));
        set("title","һ����");
        set("long","�������Ϊ�����ƺ�����˼�飬����·�ı��£������ܴӸ����������������������\n");
        set("gender","����");
        set("age",42);
                
        set("combat_exp",2500000);  
        set("attitude", "friendly");
        
        set("class","beggar");
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",150);
                        
        set_skill("qidaoforce", 150);
        set_skill("doggiesteps",200);
        set_skill("dragonstrike",170);
        set_skill("dagou-stick",170);
        
        map_skill("unarmed","dragonstrike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","doggiesteps");
        map_skill("move","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("staff","dagou-stick");
                 set("chat_chance_combat", 100);
         set("chat_msg_combat", ({

            (: perform_action, "staff.tianxiawugou" :),
            }) ); 
        
        
        set("inquiry", ([
                "������" :      "ʲô�����㣬û��˵����\n",
                "������" :      "�����㰡���ٺ٣�����֪����ô���������ض�����ͺ������\n",
                "���" :        "������ú���򾣬����������ô������������������أ��ⲻ�����ҵ�����ô��\n",
                "���" :        "�ţ������ҵ������Ͳųɣ�ʮ���ƽ���˵�����͸һ�ѡ�\n",
                "bait" :        "������ú���򾣬����������ô������������������أ��ⲻ�����ҵ�����ô��\n",
                "fishpole" :    "�ţ������ҵ������Ͳųɣ�ʮ���ƽ���˵�����͸һ�ѡ�\n",
                "��С·" :      "С·���ҵ�˫��̥�ܵܣ�Ҳ�Ǹ���򣬲������������ӱ��Ҳ�Զ�ˡ�\n",    
        ]));
        
        set("death_msg",CYN"\n$N̾����˵������������ȥ��һ���㡣�� \n"NOR);
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n����·�е������˰���ɱ����������\n",
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "����·���������˵����������ܴ�����ص���������\n",
        }) );                   
        
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fumostaff",2);
   
        setup();
        carry_object("/obj/armor/cloth")->wear();    
        carry_object(__DIR__"obj/staff")->wield();  
    
}  
int accept_object(object who, object ob)
{
        object fishpole;
        
        if (ob->value()>=100000) {
                command("grin "+who->get_id());
                command("say �ðɣ��Ҿ͸һ��");
                fishpole=new(__DIR__"obj/staff");
                message_vision("$N��һ��װ������͵Ĵ����ӣ��������һ���Ӹ��㡣\n",this_object());
                if (fishpole) fishpole->move(who);
                return 1;               
        }
        return 0;
}       
