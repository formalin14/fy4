inherit ROOM;
void create ()
{
        set ("short", "阴暗小路");
        set ("long", @LONG
这是一条阴暗潮湿的小路，位于沉香城之西南，周围散落着一些残垣断壁，路
边杂草丛生。由于官府很少管这里，所以治安并不十分好。到处是沉闷的灰色，不
见一丝生机。路边立着一个破木牌子（ｐａｉｚｉ），上边潦草得写着些官府告示。
LONG);
        set("exits", ([ //sizeof() == 4
                "east" : AREA_CHENXIANG"mw",
                "west" : __DIR__"yinroad2",
        ]));
        set("outdoors", "wolfmount");
        set("item_desc", ([
                "paizi": @TEXT
近日西山群狼横行，占山为王，专门打劫过往客商，官府无力顾及，
鉴于大家之安全问题日益严重，官府建议暂时不要西行。如有不听劝
告，私自身涉险境，一切后果自负。
TEXT
        ]) );
        set("type", "road");
        set("coor/x",-600);
      set("coor/y",-540);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
