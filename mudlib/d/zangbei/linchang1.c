 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ɽ·");
        set("long", @LONG
·��ɽת������ɽ�䣬��ˮ��������ľ�дС�����ǰ��ɽ�ƶ��ͣ������ţ�
�������֣���ʯ��ᾣ�ѩ�塢ɭ�֡��ݳ���Ϫ�����������ٲ��ͷ�ľ�˵�ľ����ӳ
��Ȥ��Զ�������๱�����ɹ���������ѩ�御��������
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"spring",
                "northdown":  __DIR__"linchang2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}   
