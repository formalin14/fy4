 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���в�");
        set("long", @LONG
���Ǻ�����ӵĳ��������Ӻܳ������ŷ������ų�ľ���������Ǳ�
������ϯ��һ�����������ڽ�ּ��Ҫ�������ж��֣��������ڵ����޲�
ʱ���������С����϶���ϰ���գ����Լ����϶���Ҳ����˰��ޡ�
LONG
        );
        set("exits", ([ 
 "south" : __DIR__"heshang2",  
]));
        set("objects", ([
                __DIR__"obj/buobei" : 1,
                __DIR__"obj/zhuxi" : 1
       ]) );
        set("coor/x",-200);
        set("coor/y",320);
        set("coor/z",60);
        setup();
create_door("south", "ľ��", "north", DOOR_CLOSED);
}       