#include <ansi.h> 
 inherit ITEM;
void create()
{
        set_name(HIG"����ɽׯ����"NOR, ({ "qingtie"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_write",1);
                set("long", HIG"һ�ſհ׵�����ɽׯ��������û��д�Ͽ��˵����֡�\n"NOR);
                set("value", 0);
        }
        ::init_item();
} 

void init() {
          object me;
          me=this_player();
        if((string)me->query("id") == "xiaolang"){
        			add_action("do_write","write"); 
        		             	}
        add_action("do_read", "read");
} 

int do_write(string arg)
{
        object obj,tarobj;
        string sheet, target; 
     if (this_object()->query("no_write")){
        if( !arg || sscanf(arg, "%s", target)!=1 )
                return notify_fail("��Ҫ��������д(write)��˭������(id)�� \n");
        tarobj = present(target, environment(this_player()));
        if( !tarobj) tarobj = find_living(target);
        if( !tarobj ) {
           message_vision("$N��ʰ�" + target + "д��$n���档\n", this_player(), this_object());
           this_object()->set("no_write",0);
           this_object()->set("long",
                HIG"����һ��"NOR + this_object()->name() + HIG"������д�ţ�"NOR + target + HIG"�����������֡�\n"NOR);
        }
        else {
           message_vision("$N��ʰ�" + tarobj->name() + "д��$n���档\n", this_player(), this_object());
           this_object()->set("targetname",tarobj->name());
           this_object()->set("targetgender",tarobj->query("gender"));
           this_object()->set("long",
                HIG"����һ��"NOR + this_object()->name() + HIG"������д�ţ�"NOR + tarobj->name() + HIG"�����������֡�\n"NOR);
           this_object()->set("targetid", target);
           tarobj->set_temp("����ɽׯ/������", 1);
           this_object()->set("no_write",0);
        }
                           }
     else return notify_fail("���Ѿ�д�Ͽ��˵������ˡ� \n");
        return 1;
}   

int do_read(string arg) {
        object me;
        
        me = this_player();
        if (!arg || (arg != "qingtie" && arg != "����")) {
                return 0;
        }
        if(me->query_temp("����ɽׯ/������")||(string)me->query("id") == "xiaolang"){
          tell_object(me, HIG"\n����ɽׯׯ����ʮһ�ɳ������µ�ɽׯ���档\n"NOR);
          tell_object(me, HIG"������㳡������ʮ�ת������һ�Ȼ����������·ת�����Ǳ�ׯ��\n��ף��;��ȫ��\n---����ɽׯ��ʮһ�ɰ��ϡ�\n"NOR);
          me->set_temp("����ɽׯ/����", 1); 
                                               }
        else return notify_fail(HIW"�㲻���������ˣ�͵�����˵��������Ǵ�����Ϊ�� \n"NOR);   
          return 1;
}    