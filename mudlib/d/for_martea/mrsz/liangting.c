 inherit ROOM;
void create()
{
        set("short", "凉亭");
        set("long", @LONG
山庄的凉亭造得颇为精致，中间一石桌，桌上刻着横十九，纵十九的一张棋盘，
残局还未撤去。从这望去，整个后花园的景色尽收眼底，令人心旷神怡。凉亭的东
面便是个池溏，西面是座楼阁，门上横匾上写“舞凤楼”三字。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"chitang",
        "south" : __DIR__"changlang1",
        "west" : __DIR__"wufenglou",
        "northeast" : __DIR__"houhuayuan1",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}    
