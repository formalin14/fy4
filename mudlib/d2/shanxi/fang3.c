 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "厢房");
        set("long", @long
一间又一间金碧辉煌的厢房，镶嵌了巨大闪亮的明镜，张扬的
影子蠕动在每一个方寸角落。室内满是瓷器、漆器、刺绣，四壁以
红、黑、金为主色的漆面上，由大内画家画上了花鸟老树、蜻蜓白
鹤的景致，黄呢布的大床占据了房间的三分之一。
long
        );
        set("exits", ([ /* sizeof() == 4 */
                //"northeast":__DIR__"fang3",
                "southwest":__DIR__"hyuan",
               // "east":__DIR__"hyuan",
                //"west":__DIR__"hyuan",
                //"north":__DIR__"tang",


   ]));
        set("item_desc", ([
                "bed": "一张柔软的大床，睡上去一定很舒服。\n",
                "床": "一张柔软的大床，睡上去一定很舒服。\n",
        ]) );
        set("objects", ([
      
                                __DIR__"npc/xiaofan4" : 1,
                        ]) );



        set("no_dazuo",1);
        //set("no_study",1);
        set("no_magic",1);
//        set("NONPC",1);
      //set("valid_startroom", 1); 
        set("indoors", "shanxi");
  //      set("no_death_penalty",1);
set("coor/x",-490);
        set("coor/y",-320);
        set("coor/z",100);
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
      tell_object(me, "床上有人耶。。。。\n");
      return 1;
   }
      else{
      message_vision("$N揉揉眼、打个哈欠，躺到了床上，", me);
      tell_object(me, "很快你就觉的睡意朦胧。\n");
      message("vision", me->name()+"翻了几个身，找到个舒适的姿势，很快就进入了梦乡。\n", environment(me), me);
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
      me->set("disable_type",HIG "<睡梦中>"NOR); 
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
   message_vision("$N睁开了眼睛，一个鲤鱼打挺从床上跳了下来。\n", me); 
   tell_object(me, "你觉得精神好了很多。\n");
   obj->set_temp("marks/taken", 0);  
}  