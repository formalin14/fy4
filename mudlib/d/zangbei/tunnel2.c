 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ˮ�°���");
        set("long", @LONG
���¾��������ܵĺ��������ŵƻ𣬲ſ�������������խ��������ȴ������ˮ
�ж��Ҳ��֪ͨ����������Ǽ�̵�ʯ�ڣ���ߵ�ʯ���ϣ����������и��޴�
�����������źֵܴ�������ʯ���ϳ�����̦������Ҳ�����⡣
LONG
        );
        set("exits", ([ 
                "south":        __DIR__"tunnel1",
                "north":        __DIR__"tunnel3",
        ]));
        set("item_desc", ([
                "����":         "�������Ѿ����⣬������������˨���ġ�\n", 
                "ring":         "�������Ѿ����⣬������������˨���ġ�\n", 
                "����":         "�������Ѿ����⣬������������˨���ġ�\n", 
                "chain":        "�������Ѿ����⣬������������˨���ġ�\n", 
        ]));
        set("objects", ([
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        if (userp(obj) && random(20)) {
                obj->move(this_object());
                return notify_fail("");
                }
        return 1;
}   