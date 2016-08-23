 //mac's tiankuang.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","天贶殿");
  set("long",@LONG
天贶殿为正殿，正面为高大的东岳大帝彩塑像，周围摆放着历代
皇帝举行祭典时用的祭器和乐器，殿壁东北南三面为大型壁画，展示
泰山神出巡时的浩大场面。
LONG
  );
  set("exits",([
         "north":__DIR__"houqing.c",
         "south":__DIR__"zhengyuan.c",
               ]));
        set("objects", ([
                __DIR__"npc/xi" : 1,
       ]) );
  set("coor/x",310);
        set("coor/y",2330);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}  
