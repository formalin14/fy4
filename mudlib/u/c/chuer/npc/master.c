inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("�����ͨ", ({ "master zhuge","master" }) );
        set("nickname", HIC"���о�ʿ"NOR);
        set("gender", "����" );
        set("age", 64);
        set("str", 30000);
        set("cor", 30000);
        set("cps", 30000);
        set("int", 30000);
        set("per", 30000);
        set("agi", 30000);
	set("attitude","friendly");
        set("max_force", 50000000);
        set("force", 50000000);
        set("force_factor", 50000);
	set("max_kee",9999999);
        set("max_gin",9999999);
        set("max_sen",9999999);
	set("kee",9999999);
	set("gin",9999999);
	set("sen",9999999);
        set("chat_chance", 3);
        set("chat_msg", ({
"�����������һЦ�������뵱�����ʦ���ݺὭ�����Ǻε���ңʹ�죬�����......��\n",
"��������ع�ͷ��������������֪������ʦ����������ɽ�����±�����һ�����Ҷ��֣���\n",
"�������ע�����ǿ����ң���Ц�˼�����������̾�˿�����������ǳ�Ĭ���\n",
        }) );
 set("long",
		HIR"�����������ɨ����һ�ۣ�����������û��ûС����֪��أ���\n\n\n"NOR
	);
        create_family("������", 2, "����");
        set("combat_exp", 999999999);
        set("score", 200000);
        set_skill("move", 5000);
        set_skill("dodge", 5000);
        set_skill("parry", 5000);
        set_skill("unarmed", 5000);
        setup();
}
void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 5000000 ) {
                student->set("title","������ʥ��");
                return ;
        } else
                student->set("title","��������ң��");
                return ;
}
void init()
{
	object		me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, me);
        }
}
int greeting(object me)
{
	object		groom;;
	if((string)me->query("family/family_name")!="������") {
	       message_vision(HIR "\n\n$N����$nһ��,��$nŭ�ȵ���������ʲô��ݣ������ȥ��Īð���˴˼����ˣ���\n" NOR, this_object(), me);
             message_vision(HIY "\n\n$n΢һ̧�֣�һ������ƿն�������$Nײ���˳�ȥ��\n\n\n" NOR, me,this_object());
	       groom = find_object("/d/wiz/hall");
		if(!objectp(groom)) groom = load_object("/d/wiz/hall");
		me->move(groom);
	}
	else {
               if(me->query("id")!="chuer") {
message_vision(HIR "\n\n$Ņ��ͷ����˫Ŀ����һ��������$nһ�ۣ�˵�������˵ط������룡��\n" NOR, this_object(), me);
message_vision(HIY "\n\n$n����һ�ӣ���$N���ȵ������˳�ȥ!\n\n\n" NOR, me,this_object());
		groom = find_object("/d/wiz/hall");
		if(!objectp(groom)) groom = load_object("/d/wiz/hall");
		me->move(groom);
				}
	else {
     message_vision(CYN "\n$N��$nЦ��������������ˣ�\n" NOR, this_object(), me);
	}
	}
	return 1;
}
