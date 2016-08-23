 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "小山坡顶");
        set("long", @LONG
山坡虽不高，但也可以把西南的沉香镇和北面的风云城尽收眼底。占
地几百顷的风云城一眼望不到边际，整个城都向远方铺展，隐于大地的交
界处。西南的沉香镇相比之下则显得荒漠的可怜。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"sroad1",
  "westup":"/d2/shanxi/huanghe8",
]));
        set("objects", ([
        __DIR__"npc/shiren": 1,
        AREA_WANMEI"obj/tree" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",20);
        set("coor/y",-430);
        set("coor/z",20);
        set("coor/x",20);
        set("coor/y",-430);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}  
