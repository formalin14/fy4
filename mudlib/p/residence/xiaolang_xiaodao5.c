#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"÷԰С��"NOR);
        set("long", @LONG
��������������ʯС·�ϣ����Ż��ݵ���ζ���������������������ʱ��ȴ��
�����е�Ѫ���ȷ磬�㿴������С���ڻ�����ľ��ȸԾ���У�ʱ��ʱ�Ļ��и���С
������С·�����ش��������ȥ�����˵��Է���
LONG
        );
    set("exits", ([ 
								"west" : __DIR__"xiaolang_huayuan",
								"east" : __DIR__"xiaolang3",
        ]));
    set("objects", ([

    ]));
    set("outdoors", "residence"); 
    set("coor/x",16);
    set("coor/y",2033);
    set("coor/z",30);
        setup();
} 
