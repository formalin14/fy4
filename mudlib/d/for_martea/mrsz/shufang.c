 inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
整个房间弥漫着浓浓的墨香。右边竹帘窗楹之下，摆着一张紫檀案几，案上一
竹制花筒，却插着一枝山间常见的绿叶。左边也是一张紫檀书桌，上面斜斜的摊开
几本线装书，及些许笔墨砚石。墙角书架之上摆放着很多的书籍，一眼望过去，似
乎有关于不少琴棋方面的书。墙壁都已被书画挂满，不知出自何人手笔。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"zhengtang",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
