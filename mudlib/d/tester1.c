 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���ֵ�ʦ", ({ "man"}) );
        set("gender", "����" );
        set("age", 65);
        set("per", 27);
        set("attitude", "peaceful");
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("long",     "���ֵ�����������\n");
        set("combat_exp", 999999);
        setup();
}
private void get_encoding(string arg, object ob);
void init()
{
        object me;
        me = this_player();
        ::init(); 
		write("������˵������ã���ӭ�������Ƶ����磬����������ѵ���ң�\n");
        write("�㽫�������ֵ�ʦ����ʾ�����˽���β��������Ϸ��\n");
        write("������һ������MUD��Ϸ�����еĶ������Ժȡ����ߡ�ս����ѧϰ�����졢������������ָ��ȥ��ɵġ�\n");
        write("�������ҽ�����ôȥ���������δ֪�����硣\n");
        write("������ʹ��ָ��look��������дΪ��l�����������롰look��������д��l����ʱ��");
		write("����ԡ������������ڵĳ�������Ϣ��\n");
        write("���棬�㳢������ָ���look��������д��l�������������ڴ���һ��ʲô���ĳ����ڰɡ�\n");
		get_encoding("", me);
} 
private void get_encoding(string arg, object ob) {
	    object me, room;
		me = this_player();
	    if(arg == "look man" || arg == "l man") {
                write("������ȷ�ˡ�\n");
				room = load_object("/d/fy/ecloud1");
                this_player()->move(room);
        } 
		else {
                write("������ָ�look man\n");
                input_to((: get_encoding :), ob);
                return;
        }
}
//int ask_him(object me)
//{
//        if(environment(me) == environment())
//			   tell_object(me,name()+"�ȵ������ǲ�����ʮһ�ɵ����ѣ���answer yes/no��\n");
//               return 1;
//}

//int do_answer(string arg)
//{
//if(!arg || arg != "yes"){
//command("say �ã���Ȼ�����������ѣ��ҾͲ�����ɱһ����\n");
//command("say ������ȷ�ˡ�\n");
//}
//else {
//	command("say ���벻��ȷ\n");
//	command("say �������롣look\n");
//};
//}
