 inherit ROOM;
void create()
{
        set("short", "练武场");
        set("long", @LONG
场地中间立了几个梅花桩，靠边有两排石凳，上面摆着几个没挂起来的沙袋。
除了这些，别无它物。与其说这里是个练武场，倒不如说是一块空地。
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"dayuan",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}     
