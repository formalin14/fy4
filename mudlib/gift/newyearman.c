#include <ansi.h>
inherit NPC;
int hongbao(); 
void create()
{
    set_name(HIR"����"NOR, ({"oldman","����"}) );
    set("gender", "����" );
    set("nickname", HIC"�����"NOR);
    set("title", HIR"�´�����"NOR);
    set("long", "��˵��������������·������ɣ�������װ�źܶ���(hongbao)�����������Ҫ��\n");
        set("attitude", "friendly");
        set("age", 25);
        set("cor", 25);
        set("cps", 25);
        set("per", 25);
        set("combat_exp", 30000000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 200);

        set_skill("parry", 1000);
        set_skill("unarmed",1000);
        set_skill("dodge", 1000);
        set_skill("force",1000);
        set_skill("yiqiforce", 100);
        map_skill("force","yiqiforce");
        map_skill("unarmed","yiqiforce");

        set("chat_chance", 1);
        set("chat_msg", ({
           "����΢Ц������κ�����ŵķǳ�˳����\n",
        }) );
        set("inquiry", ([
                "���" : (: hongbao :),
                "hongbao" : (: hongbao :),
                "�´�����" : (: hongbao :),
                "gift" : (: hongbao :),
        ]));
        setup();
} 

 void init()
{       
        add_action("do_killing", "kill");
}   

int hongbao(){
    object me,ob;
    int exp;
    
    me = this_player();
    exp=(int)me->query("combat_exp");
    ob=new("/questobj/hongbao1");
    if(exp<300000)
       message_vision(WHT"��������������$N��ͷ��΢Ц��˵���㻹С�����㸸ĸ������ɡ�\n"NOR,me);
    else{
      if(!me->query("newyear_2005"))
      {
        message_vision(WHT"�����$N˵�����´����֣���ϲ���ƣ�������ĺ����\n"NOR,me);
        message_vision("����Ӷ�������һ��"+ob->query("name")+"��Ȼ��ݸ�$N\n",me);
        ob->move(me);
        me->set("newyear_2005",1);
       }
       else message_vision(WHT"�����$N��Ц�������������÷��������ǲ���Ҳ���������ˡ�\n"NOR,me);
       }
    return 1;
} 
int do_killing(string arg)
{
        object player;
        if(!arg) return 0;
        player = this_player();
        message_vision("����΢Ц�Ŷ�$N�����������ɱ���˰ɡ�\n",player);
        return 1;
}