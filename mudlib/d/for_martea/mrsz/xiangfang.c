 inherit ROOM;
void create()
{
        set("short", "厢房");
        set("long", @LONG
这是间整洁的厢房，是供客人休息的地方，但山庄很少有客拜访，所以现在都
是丫鬟、下人们住在里面。房间里门窗紧闭，光线很昏暗。唯一特别之处是在床边
有一梳妆小柜，那是给女孩们睡醒后梳妆打扮用的。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"dayuan",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
