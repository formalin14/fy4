 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM; 
void create()
{
        set("short", "私塾学堂");
        set("long", @LONG
这里以前是一家洗衣店，是有钱人将衣服拿来浆洗的地方。自从这里的老
板娘去了以后，有一个老人住了进来，把这里改成一间私塾，但因为地区太乱，
并没有几个学生。门口有一个大木牌（ｓｉｇｎ）。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"workroom2",
])); 
        set("item_desc", ([
                "sign": @TEXT
用私塾先生给的四个数和+,-,*,/,及()算出二十四。
例如： 
如果这四个数是：九,二,三,三. 请在一分钟内给出答案(answer)
answer (9-2)*3+3
第一个答对的奖励十文。     
TEXT
        ]) );
        set("objects", ([
        __DIR__"npc/pianzi" : 1,
                        ]) );
        set("coor/x",30);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
