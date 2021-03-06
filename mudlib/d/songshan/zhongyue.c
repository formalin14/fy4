 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "中岳庙");
        set("long", @LONG
庙宇依照山势起伏自北而南，由上而下铺陈营造，气势雄伟，
景色壮观。正是“飞檐映日，杰阁联云”。寺内现有百余座石刻
碑碣，其中“中岳嵩高灵庙之碑”是嵩山最古老的石碑了。庙内
崇圣门神库四角，四个镇库武神铸于北宋年间，工艺复杂，表情
夸张。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"luya", 
  "south" : __DIR__"taishi",
  "northwest" : __DIR__"shuyuan",
  "southeast" : __DIR__"shizong",
]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"obj/bei1" : 1,
       ]) );
        
        
        set("coor/x",-180);
        set("coor/y",110);
        set("coor/z",0);
        setup();
        create_door("north", "小木门", "south", DOOR_CLOSED);
} 
