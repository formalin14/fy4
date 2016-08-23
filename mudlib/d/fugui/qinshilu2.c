 inherit ROOM;
void create()
{
        set("short", "青石路");
        set("long", @LONG
这是条宽阔的青石大道，两旁尽是些不知名的树木，沿途冈峦回绕，水田蔬圃
连绵其间，宛然有若江南景色。四周草木青脆欲滴，繁花似锦。举目远眺，远处炊
烟袅袅，只见前面房屋鳞次栉比，却是个集镇。 
LONG);
        set("outdoors", "fugui");
        set("type","road");
        set("exits",([
                "east":__DIR__"qinshilu3",
                "south":__DIR__"qinshilu4",
        ]) );
        set("coor/x",-590);
        set("coor/y",70);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
