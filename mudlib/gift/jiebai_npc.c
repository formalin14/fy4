#include <ansi.h> 
inherit NPC; 
string jiebai();
string unjiebai(); 
void create()
{
    set_name("��ݲ�����Ա", ({ "man" }) );
    set("gender", "����" );
    set("age", 43);
    set("long",
        "һλ�����ܸɵ���\n");
    set("combat_exp", 10000);
    set("attitude", "friendly");
    set_skill("literate", 70);
    set_skill("dodge", 500);
    set_skill("unarmed", 300);
    setup();
    carry_object("/obj/armor/cloth")->wear(); 
    add_money("gold", 1);
} 
void init()
{
    ::init();
    add_action("do_jiebai", "jiebai"); 
    add_action("do_unjiebai", "divorce");
} 
int do_jiebai(string arg) 
{
    object obj, me;
    object ob;
    int i;
    string myclass,otherclass,location;
    me = this_player();
    
    location = environment(this_object())->query("short");
    
    if( me->query("jiebai"))
        write("�����ڻ��н�ݵ��ֵܽ��ã������ٽ���������ˡ�\n");
    else if(me->query("��������"))
    	write("�����û�����������������ʲô��\n");
    else if(!arg || !objectp(obj = present(arg, environment(me))))
        write("�����˭��ݣ�\n");
    else if(obj->query("��������"))
    	write("�Է��Ǹ����������С�ˣ���ֵ����ȥ��ݣ�\n");
    else if( obj->query("jiebai"))
        write("��Ķ����Ѿ��ͱ��˽���ˡ�\n");
/*    else if((int)me->query("age")<16 && (string)me->query("gender")=="����" ||
            (int)me->query("age")<14 && (string)me->query("gender")=="Ů��")
        write("��̫С������ô��������\n");  */
    else if((myclass = me->query("class")) != "bonze" && myclass != "wudang" &&
            myclass != "lama" && myclass != "shaolin" && myclass != "taoist" &&
            myclass != "mei"  &&
            (otherclass = obj->query("class")) != "bonze" && myclass != "wudang" &&
            otherclass != "lama" && otherclass != "shaolin" && myclass != "taoist" &&
            otherclass != "mei" )
        write("�������ڹ涨��ֻ�г����˲ſ��Խ�ݡ�\n");
    else if( !living(obj) )
        write(obj->name() + "�Ѿ��޷��������ˡ�\n");
    
    else if(obj==me)
        write("���ѵ�Ҫ���Լ������̫�����˰ɣ�\n");
    else if(!userp(obj))
        write("��ֻ�ɺ���ҽ�ݣ�\n");
/*    else if((string)obj->query("gender")== (string)me->query("gender"))
        write("ֻ�ܺ�ͬ�Խ��\n");   */                          //����ֻ�ܺ�ͬ�Խ��
    else if( userp(obj) && !obj->query_temp(me->query("id") + "j"))
    {
        message_vision(MAG "\n$N����$n˵����" 
                       + RANK_D->query_self(me) 
                       + me->name() + "��Ը���"
                       + RANK_D->query_respect(obj) + 
                       "��Ϊ����֮��\n\n"NOR, me,obj);           
        me->set_temp(obj->query("id") + "j",1);
        tell_object(obj, MAG "�����Ը��ͶԷ�������������Ҳ��" 
                    +me->name() + "("+(string)me->query("id")+
                    ")"+ "��һ�� jiebai ָ�\n"NOR);
    }
    else
    {
        me->set("jiebai",obj->query("id"));
        me->set("jiebai_name",obj->query("name"));
        obj->set("jiebai",me->query("id"));
        obj->set("jiebai_name",me->query("name"));
        
        message_vision(MAG "��ϲ $N �� $n �ڴ���������\n"NOR,
                       obj, me);
        if(me->query("gender")=="����")
            CHANNEL_D->do_sys_channel("info",sprintf(
                "%s,%s(%s)��%s(%s)��%s���������и�ͬ������ͬ����", 
                NATURE_D->game_time(),me->name(1),me->query("id"), 
                obj->name(1), obj->query("id"),location));
        else
            CHANNEL_D->do_sys_channel("info",sprintf(
                "%s,%s(%s)��%s(%s)��%s���������и�ͬ������ͬ����", 
                NATURE_D->game_time(),obj->name(1), obj->query("id"),
                me->name(1),me->query("id"),location));
    }
    return 1;
} 
int do_unjiebai(string arg)
{
    object jiebai_card1,jiebai_card2,  me;
    object couple_ob;
    int i, have_jiebai;
    string target, tmpstr1, tmpstr2,str1,str2;
    string cardname;
             
    me = this_player();       
    if (!me->query("jiebai"))  write("��δ�����κ��˽�ݡ�\n");
    else if(!objectp(couple_ob =
                present(target=(string)me->query("jiebai"), environment(me))))
        write("���ݵ��˲��ڳ�.\n"); 
    else if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"d"))
    {
        message_vision(MAG "\n$N����$n˵����" + RANK_D->query_self(me) 
                       + me->name() + "�����ǽ�����!�����������?\n\n"
                      NOR, me, couple_ob);           
        me->set_temp(couple_ob->query("id")+"d",1);
        tell_object(couple_ob, MAG "�����Ը������ݣ�����Ҳ"
                    + "��һ�� divorce ָ�\n"NOR);
//        write(MAG"������ֻ�е���" +couple_ob->query("name")+"ͬ����...\n"NOR);
    } else { 
        me->delete("jiebai");
        couple_ob->delete("jiebai");
        me->set("��������",1);
        couple_ob->set("��������",1);
        message_vision(MAG " $N �� $n �����ڿ�ʼ�����ݹ�ϵ���Ӵ�����������ص����ҹ��ҵĶ�ľ�ţ�\n"NOR,
                       couple_ob, me);
        if(me->query("gender")=="����")
            CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)��%s(%s)�����ݹ�ϵ���Ӵ�����������ص����ҹ��ҵĶ�ľ�ţ�", me->name(1),
                me->query("id"),couple_ob->name(1),couple_ob->query("id")));
        else
            CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)��%s(%s)�����ݹ�ϵ���Ӵ�����������ص����ҹ��ҵĶ�ľ�ţ�",couple_ob->name(1),
                couple_ob->query("id"),me->name(1),me->query("id")));
    }
    return 1;
} 
