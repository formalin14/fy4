 // Tie@fy3
inherit ROOM;
void create()
{
        set("short", "会客厅");
        set("long", @LONG
四下的灯散发着柔和的光，红木长台的周围放了几个
椅子。整个房间的布置是那么的和谐，你真的想敞开你的
心扉，痛痛快快地将所有的实情和大家分享。往南是休息
室，往北是法院，往东则是监狱。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hall",
  "north" : __DIR__"courthouse",
  "east"  : __DIR__"jail",
  "up"    : __DIR__"home",
  "down"  : AREA_FY"fysquare",
]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",10);
        set("no_magic",1);
        setup();
        call_other("/obj/board/wizard_j", "???");
        replace_program(ROOM);
}    
