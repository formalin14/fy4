 // Tea@fy4
inherit ROOM;
void create()
{
        set("short", "茶楼");
        set("long", @LONG
一家古色古香的店铺大堂，不过此时此刻空无一人。最左边是
个红木柜面，后面一排排抽屉，似乎放着好些东西。最右边散放着
些桌子椅子，凌乱中有点诡异。正面有块挂帘，隐约透出幽幽的灯
光。房间内放着好些香熏，靠墙的地方则摆着数盆百合。一切都那
么诱惑迷人。
LONG
        );
        set("exits", ([
  "south" : __DIR__"aroom",
  "north" : __DIR__"broom",
  "east"  : __DIR__"tearoom",
  "west"  : __DIR__"marroom",
  "up"    : __DIR__"croom",
  "down"  : __DIR__"jobroom",
]));


        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",100);
        set("no_magic",1);
        setup();
        replace_program(ROOM);
}    
