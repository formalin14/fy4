 //mac's tongting.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","铜亭铁塔");
  set("long",@LONG
眼前矗立的是一座高两丈的铜铸亭子，亭中为一实心铁塔，塔上
刻有日月星云，山水岩石，寓意光明普照，坚固永生，山海年长的意
思。
LONG
  );
  set("exits",([
         "north":__DIR__"houzai.c",
         "south":__DIR__"houqing.c",
               ]));
        set("objects", ([
                "/obj/specials/ding/ding_dm" : 1,
       ]) );
  set("coor/x",310);
        set("coor/y",2350);
        set("coor/z",0);
        setup();
//  replace_program(ROOM);
}    
void init()
{
        add_action("do_climb","climb");
}
int do_climb()
{
        object me,room;
        me = this_player();
        message_vision("$N手脚并用，攀着亭柱亭梁，翻上了亭顶。\n",me);
        room = load_object(__DIR__"ttop");
        me->move(room);
        return 1;        
} 