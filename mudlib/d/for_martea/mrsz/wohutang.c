 inherit ROOM;
void create()
{
        set("short", "卧虎堂");
        set("long", @LONG
这里便是山庄二少爷的卧虎堂。子虎少爷长年在外奔走，只有冬天的时候赋闲
在家，因此房间布置的很简朴，堂内只摆了几张高背方椅，一张八仙桌，看起来空
荡荡的。唯一引人注目的是正面墙壁上挂着一幅虎视耽耽、雄风千里的猛虎之图。
画中之虎或纵横或静卧，状态各异，栩栩如生，将厅堂充满了虎虎生气。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"changlang4",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}       
