 // Tea@fy4
inherit ROOM;
void create()
{
        set("short", "卧室");
        set("long", @LONG
此间主人一定是个雅士，皆因一进入此处，触目可见的都是
不可多得的古玩、墨宝。窗台边一个不高的书柜上，陈列了诸子
百家、四大名著等等。而书柜最上一层，就是整整齐齐的一套古
龙小说。唯一可显示出该主人性别、身份的，则是床头上斜挂悬
垂的镶钻宝剑。

LONG
        );
        set("exits", ([
//  "south" : __DIR__"home",
//  "north" : __DIR__"home",
//  "east"  : __DIR__"home",
    "west"  : __DIR__"home",
//  "up"    : __DIR__"home",
//  "down"  : __DIR__"jobroom",

])


);




        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",100);
        set("no_magic",1);
        setup();
        replace_program(ROOM);
}    
