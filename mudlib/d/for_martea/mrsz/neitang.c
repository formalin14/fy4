 inherit ROOM;
void create()
{
        set("short", "内堂");
        set("long", @LONG
这里是正堂后面的内堂，是庄人吃饭用餐之地。厅堂很是很大，房子中央有张
红木桌，上面沏了一壶好茶，摆着几盘点心。西面是厨房，从里面飘出阵阵饭香。
北面就是通往后院的一条长廊。
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"zhengtang",   
        "west" : __DIR__"chufang",
        "north" : __DIR__"changlang3",  
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
