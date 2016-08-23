#include <ansi.h>
inherit NPC;
int weapon();
int jade();
void create()
{
        set_name("��ʯ��", ({ "jade man","man" }) );
        set("long",
"����һ�����ֵ��зǳ������ı�ʯ������˵���ܴ�ĥ�����Ե�������װ����Ȼ���
��ʯ��Ƕ�����档\n"); 
    set("attitude", "friendly"); 
    set("age",72); 
    set("str", 80);
    set("cor", 110);
    set("agi", 50); 
    set("combat_exp", 500000);
        set_skill("unarmed",150);
        set_skill("parry",150);
        set_skill("dodge",150);
        set("inquiry", ([
                "weapon" : (: weapon :),
                "����" : (: weapon :),
                "bingqi" : (: weapon :),
                "armor" : (: weapon : ),
                "����" : (: weapon : ),
                "jade" : (: jade : ),
                "��ʯ" : (: jade : ),
                "stone" : (: jade : ),
        ]));
    set("chat_chance", 1);
    set("chat_msg", ({
"��ʯ��̾��̾�����૵�������������ı�ʯ��������ʲô�ط��أ���\n",
    }) );
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
} 
void init(){
        ::init();
//    add_action("do_inset","inset");
    add_action("do_give", "give");
} 
int weapon(){
        object me;
        me = this_player();
        message_vision("$N������˼���૵�������Щ�����������Եģ����ҿ��Ը����Ǵ��ϰ��ۣ�\n", this_object());
        message_vision("������Щ���ۣ���Ƕ�ϱ�ʯ�Ϳ�������������װ�������ԣ�ֻ��ϧ����ʯ�Ǻ��ѵõİ�~~~~~����\n", this_object()); 
        return 1;
} 
int jade(){
        object me;
        me = this_player();
        message_vision("$N��ͷ������������Щ��ʯ�ǿ����������������ͻ��ߵ����ԣ�\n", this_object());
        message_vision("�������ʱ���������������⵱�еõ���һö���Դ˾����ѿ����ˡ���\n", this_object()); 
        return 1;
} 
int do_give(string arg){
        object ob,me,obj;
        int i, j;
        string longarg,acceptor,objectname;
        
        ob = this_object();
        me = this_player();
        
    if( sscanf(arg, "%s to %s", objectname, acceptor)==2 ){ 
        if(acceptor!="��ʯ��"&&acceptor!="jade man"&&acceptor!="man")
                return 0;
        if(ob->query("busy"))
        	return notify_fail("��ʯ�����ڰ���˴�ĥ�����Ե�һ�°ɡ�\n");
        obj=present(objectname,me);
        if(!objectp(obj)) return 0;
        
        i = obj->query("hole");
        j = obj->query("level");
        longarg = obj->query("long");
        if(obj->query("can_inset") && !obj->query("hole")) {
        	if(j <= 2){
        		ob->set("busy",1);
                	message_vision(CYN"$N����$n�ݹ�����"NOR+obj->name()+CYN"���������Ҳ���ǰ��е����ԵĶ��������Ұ���򼸸����۰ɡ���\n"NOR,
                                ob, me);
                        message_vision("$N�ӹ�$n��"+obj->name()+"���������������ش�ĥ����......��\n",ob,me);
                	obj->set("hole",j+1);
                	message_vision(CYN"һ�������$N�Ѵ�ĥ�õ�"NOR+obj->name()+CYN"����$n��������ĥ���ˣ��ɵúú���ϧ�����´εõ���ʯ������\n"NOR,ob,me);
                	message_vision(CYN"һ���������Ұ�����Ƕ(inset)��\n"NOR,ob); 
                	obj->set("long", "�������������"+chinese_number(j+1)+"�����ۡ�\n");
         		obj->save();
         		ob->delete("busy");   
                	return 1;
                }else if (j <= 5 && j > 2){ 
                	ob->set("busy",1);
                	message_vision(CYN"$N����$n�ݹ�����"NOR+obj->name()+CYN"����̾�����������������Ķ�����ֵ������ϸȥ��ĥ���ö���������\n"NOR,
                                ob, me); 
                        message_vision("$N�ӹ�$n��"+obj->name()+"���������������ش�ĥ����......��\n",ob,me);
                	obj->set("hole",j+1);
                	message_vision(CYN"һ�������$N�Ѵ�ĥ�õ�"NOR+obj->name()+CYN"����$n��������ĥ���ˣ��ɵúú���ϧ�����´εõ���ʯ������\n"NOR,ob,me);
                	message_vision(CYN"һ���������Ұ�����Ƕ(inset)��\n"NOR,ob);
                	obj->set("long", "�������������"+chinese_number(j+1)+"�����ۡ�\n");
         		obj->save();
         		ob->delete("busy");   
                	return 1;
                }else if (j <= 8 && j > 5){
                	ob->set("busy",1);
                	message_vision(CYN"$N����$n�ݹ�����"NOR+obj->name()+CYN"����̾�������������а������������Ķ������ɲ�����̣�ˣ��һ���ȫ����ȥ��ĥ����������\n"NOR,
                                ob, me);
                        message_vision("$N�ӹ�$n��"+obj->name()+"���������������ش�ĥ����......��\n",ob,me);
                	obj->set("hole",j+1);
                	message_vision(CYN"һ�������$N�Ѵ�ĥ�õ�"NOR+obj->name()+CYN"����$n��������ĥ���ˣ��ɵúú���ϧ�����´εõ���ʯ������\n"NOR,ob,me);
                	message_vision(CYN"һ���������Ұ�����Ƕ(inset)��\n"NOR,ob);
                	obj->set("long", "�������������"+chinese_number(j+1)+"�����ۡ�\n");
         		obj->save();
         		ob->delete("busy");   
                	return 1;
                }else if (j >=8 ){
                	ob->set("busy",1);
                	message_vision(WHT"$N����$n�ݹ�����"NOR+obj->name()+WHT"ȫ��ʼ�����������ļ���˵����������ֻ����һ���ϣ������������������������\n"NOR,ob,me);
                	message_vision(WHT"���������������ҽ����ܼ��˱�һ�Σ������޺��ˣ���~~~ֻ��ϧ���Ѿ�û��������ĥ���ˡ���\n"NOR,
                                ob, me);
                        ob->delete("busy");
                        return 0;
                }else {
                	message_vision(CYN"$Nҡҡͷ��һ���޹������ӡ�\n"NOR,ob);
                	return 0;
                }          	                                      	
        }
        else if(obj->query("hole")){
        	message_vision(CYN"$N΢Ц��������������Ѿ��а����ˣ������ٴ�ĥ�ˡ�\n"NOR,ob);
        	return 0;
        }
        else{
        	message_vision(CYN"$N����ؿ��˿�"NOR+obj->name()+CYN"���������Ķ���Ҳ�����������ۡ�\n"NOR,ob);
        	return 0;
        }
   }
}