#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"��������"NOR);
        set("long", @LONG
������������ʮһ�ɵ��Է���һ���˼䣬���ʱ�������ܺ������ˣ�ԭ��
�����������һ�ź����񴲣���˵�˴��ǳ����棬˯(sleep)��ȥ���Իָ���
�������Ĵ������н������ţ�����һ������ѩɽׯ����������ɽׯ�����˳�
���ڴ����������Ķ���ǽ�ϻ���һ���ǳ���ֵıڻ�(picture)��
LONG
        );
        set("exits", ([ 
                    "west" : __DIR__"xiaolang_xiaodao5",
           ]));
        set("objects", ([
//                      __DIR__"npc/xiaolangwa" : 1,
                        ]) );
        set("item_desc", ([
                "bed": "һ�ź����񴲣�˯��ȥ���Իָ�����\n",
                "��": "һ�ź����񴲣�˯��ȥ���Իָ�����\n",
                "picture": HIC"���ɿ��ǽ���ϣ����������ˡ�\n"+
HIC"��ʽ���������ˣ��е��ǰ��˰��ǣ��е��Ƿ��˷��ǣ��е���ʽ���ˣ�ȴ�����ˣ��е�\n"+HIC"��״���ǣ�ȴƫƫ�п����ġ�\n"+
HIC"���ɿ�ǽ������Ҳ��û��ʮ�����ˣ�ȴ��ֻ�������ǡ�\n"+
HIY"Ѫ�ǡ�\n"+
HIC"�����Ǿ�Ȼ���С��֡������ﶼ�б��䵶�������϶��ڵ���Ѫ���γ�����ֻѪ�ǡ�\n"+
HIC"Ѫ�Ǳ�����һ�Գ�򣬳��һ�γɣ����ͷ���һ�������Ͻ����ڵ������ˡ�\n"+
HIC"һ����Ӣ�������º͵�������---"+RED"��ʮһ�ɡ�\n"+
HIC"������ȴ������Ĥ�ݣ�����������ʵ�ĳ�����Ĥ�ݵ�����\n"+
HIC"�ѵ���������������֮����\n"+
HIC"�ѵ�����������ħ�����ʮһ�ɣ�����������\n"+
HIC"Ѫ��Ҳ�����ĳ��ӡ�\n"+
HIC"ʮ��ֻ�����Ĺ���Χ�������������������ң��п�ȸ���ᣬ������ĳᣬ�����ӵ���\n"+HIC"ӯ�������۷�Ķ��롣\n"+
HIC"�����������ū��\n"NOR
        ]) );
        set("no_steal",1);
        set("coor/x",17);
        set("coor/y",2033);
        set("coor/z",30);
        //set("no_fight",1);
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
      message_vision(HIW"$N�ں���������������......"NOR, me);
      tell_object(me, HIW"�����أ���е�һ�������Ե������𣡡�\n"NOR);
      message("vision", me->name()+HIW"���������ڴ��ϣ�ȫ���ϵ�ð�Ű�����\n"NOR, environment(me), me);
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

void wake(object me)
{
   object obj; 
   obj = this_object();
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision(HIY"$N�������۾���һ�������ͦ�Ӵ�������������\n"NOR, me); 
   tell_object(me, HIY"�����ȫ������������ƺ���ʹ����ľ���\n"NOR);
}   
