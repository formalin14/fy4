 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","步天桥");
  set("long",@LONG
登泰山如登天，从登上步天桥的一刻，便仿佛置身天阙，下看齐鲁
大地，上则见中天门的门楼，直在头顶，山势陡峭，说来是桥，其实说
是登天之路似乎更为确切。从此往上便是中天门，俯瞰则为壶天阁。
LONG
  );
  set("exits",([
        "down" : __DIR__"hutian",
        "up" : __DIR__"zhongtian",
               ]));
        set("objects", ([
        __DIR__"npc/dazui" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}      
