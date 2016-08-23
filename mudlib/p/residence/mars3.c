 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 10
#define Y_COOR 2040
#define Z_COOR 40
/*#define R_FLAG 18
#define OWNER "mars"
#define CLASS "������"  */
inherit ROOM;
void create()
{
set("short", WHT"�Է�"NOR);
set("long", @LONG
ת���������������Է������ڸɸɾ������������˳��ھ�ס�����Գ���
���˴�ɨ��ǽ�ϻ���һЩɽˮ����һ����֪�ǳ�������֮�֣�����г·�
�Ÿ�����ѧ�鼮�����������������ʿ��������Ķ�����ѧ������Ա���һ
Ư�����³�(wardrobe)�����������һЩ�·����ٿ����г��軪�������ϱ�
����ȫ�����˿����������ˡ�

LONG
);
        set("exits", ([
		"east" : __DIR__"mars2",

]));

set("objects", ([
          "/p/residence/obj/mars_desk" : 1,
          "/p/residence/npc/marswa" : 1,
       ]) );

        set("item_desc", ([
                "bed": "һ������Ĵ󴲣�˯��ȥһ���������\n",
                "��": "һ������Ĵ󴲣�˯��ȥһ���������\n",
        ]) );

        set("coor/x",X_COOR);
        set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
/*        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);  */
        set("indoors","residence");
        setup();
}
void init()
{
/*        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("indoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");  */
        add_action("do_sleep", "sleep");
}
/*
int valid_enter(object me)
{
        int flag;
// means no enter at the beginning.
        int enter = 0;
    flag = (int) query("room_flag");
// always let owner go in:
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 16)
        enter = 1;
        if(flag & 512)
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
        if(flag & 2048) 
        {
                if(strlen(query("invite")) && strsrch((string)query("invite"),"["+(string)me->query("id")+"]") != -1)
           enter = 1;
        }
//      write(sprintf("%d", enter));    
        return enter;
}
int do_list()
{
        object me;
        string *list,invitelist;
        me = this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        invitelist = query("invite");
        if (strlen(invitelist))
        {
                list = explode("]"+invitelist+"[", "][");
                write("��������������ҵ���ķ���:\n");
                for(int i=0;i<sizeof(list);i++)
                        write(list[i]+"\n");
        }else
                write("��û�������κ��˵���ķ��䡣\n");
        return 1;
} 
int do_invite(string arg)
{
        object me;
        string invitelist;
        me= this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        if( !arg )
        {
                write("��Ҫ����˭? \n");
                return 1;
        }
        invitelist = (string)query("invite");
        if(strlen(invitelist) && strsrch(invitelist,"["+arg+"]") != -1)
        {
                //if the person has already been invited, remove it from invite list.
                invitelist = replace_string(invitelist,"["+arg+"]","");
           set("invite",invitelist);
                write("�㽫"+arg+"��������������г�ȥ��\n");
        }else
        {
                //invite the person.
                if( find_player(arg))
                {
                        if(!strlen(invitelist))
                                set("invite","["+arg+"]");
                        else
                                set("invite",invitelist+"["+arg+"]");
                        write("������"+arg+"����ķ��䡣\n");
                }else
                {
                        write("��... ���������?\n");
                }
        }
        return 1;
} 
int do_setowner(string arg)
{
        string oldowner;
        oldowner = (string)query("owner");
        set("owner",arg);
        write("�㽫�����������ʱ��Ϊ"+arg+"��\n");
        call_out("set_back",60, oldowner);
        return 1;
} 
int set_back(string oldowner)
{
        set("owner", oldowner);
        return 1;
} */
    
int do_sleep(string arg)
{
   object me, obj, girl;
   int gin, kee, sen; 
   me = this_player();
   obj = this_object(); 
   if (me->is_fighting()) return 1;
   if (this_object()->query_temp("marks/taken")) {
      tell_object(me, "��������Ү��������\n");
      return 1;
   }
      else{
      message_vision("$N�����ۡ������Ƿ���ɵ��˴��ϣ�", me);
      tell_object(me, "�ܿ���;���˯�����ʡ�\n");
      message("vision", me->name()+"���˼������ҵ������ʵ����ƣ��ܿ�ͽ��������硣\n", environment(me), me);
      obj->set_temp("marks/taken", 1);
      gin = (int) me->query("eff_gin");
      kee = (int) me->query("eff_kee");
      sen = (int) me->query("eff_sen");
      me->set("gin", gin);
      me->set("kee", kee);
      me->set("sen", sen);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<˯����>"NOR); 
      call_out("wake", 10, me);
      return 1;
   }
   return 1;
} 
void wake(object me)
{
   object obj; 
   obj = this_object();
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision("$N�������۾���һ�������ͦ�Ӵ�������������\n", me); 
   tell_object(me, "����þ�����˺ܶࡣ\n");
   obj->set_temp("marks/taken", 0);  
}  