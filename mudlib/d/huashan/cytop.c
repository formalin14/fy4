 inherit ROOM;
void create()
{
        set("short", "朝阳峰巅");
        set("long", @LONG
峰顶长满高大的桧松，似在峰顶盖了块绿色的毯子，林中浓荫蔽日，树下石径
上铺满了松针。无风的时候，走在石径上，可以清楚的听见松针断裂的声音；然而
当山风吹来，穿过林间只听松涛阵阵，此起彼伏，又是一番景色。
LONG
        );
    set("exits", ([ 
                "down" : __DIR__"chaoyang",
        ]));
        set("objects", ([
                __DIR__"obj/pineneedle" : 1,
                __DIR__"obj/pinetree" : 1,
                __DIR__"npc/songshu" : 1,
        ]));  
    set("outdoors", "huashan"); 
        set("coor/x",-569);
        set("coor/y",-93);
        set("coor/z",-83);
        setup();
    replace_program(ROOM);
}   
