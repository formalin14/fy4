 // Room: earthtemple.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "五色土祭坛");
        set("long", @LONG
这是一座金字塔状的神坛的顶部。脚下是一方紫色的土地，中央有一张紫石英
神台。祭坛四面分别以白，红，黄，黑四色土壤镶砌而成。身居坛顶，下面五色相
托，万物肃穆，一种沉静庄严之感悄然而生。
LONG);
//as earth people gets weapons first, they also
//face more puzzles to solve and npcs to fight
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
                "eastdown":__DIR__"black_earth",
                "westdown":__DIR__"yellow_earth",
                "southdown":__DIR__"red_earth",
                "northdown":__DIR__"white_earth",
        ]) );
        //}}
        set("item_desc", ([
                "紫玉柱" : "紫色玉柱，似乎可以转动。（ｔｕｒｎ）\n",
                "jade" : "紫色玉柱，似乎可以转动。（ｔｕｒｎ）\n",
        ]));
        set("objects", ([
                __DIR__"obj/altar" : 1,
                __DIR__"obj/red" : 1,
                __DIR__"obj/black" : 1,
                __DIR__"obj/white" : 1,
                __DIR__"obj/yellow" :1,
        ]));
        setup();
        replace_program(ROOM);
}
