#include <ansi.h>
#define X_COOR 0
#define Y_COOR 2040
#define Z_COOR 50
inherit ROOM;
void create()
{
set("short", WHT"�Է�"NOR);
set("long", @LONG
�������˵����ң��м���һ�Ŵ���bed)��������һ��������͸�������������
������������߶�ķ��ӣ�����������һ���ʻ��������ķҷ�ɢ���ڿ����С�
LONG
);
        set("exits", ([
		"west" : __DIR__"zues3",
]));

set("objects", ([
       ]) );

        set("item_desc", ([
                "bed": "һ������Ĵ󴲣�˯��ȥһ���������\n",
                "��": "һ������Ĵ󴲣�˯��ȥһ���������\n",
        ]) );

        set("coor/x",X_COOR);
        set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("indoors","residence");
        setup();
}
void init()
{
        add_action("do_sleep", "sleep");
}
    
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