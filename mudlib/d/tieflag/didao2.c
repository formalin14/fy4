 // 地道
inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
前面终于出现一道光明，漫长的地道走到了尽头
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"didao",
  "westdown" : AREA_QIANFO"shanjiao",
]));
        set("coor/x",30);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if( userp(me) && dir == "eastup" )
                    message_vision("$N手脚并用，向地道深处爬去\n",me); 
        return 1;
} 
