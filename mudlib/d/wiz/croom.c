 // Tea@fy4
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�ߵ�����Ѿ��ܽӽ������ˡ����Ŷ����ƴӴ��⾭������
��ȫ�������Լ����ںη�������û�����û�л��㣬ȴ��һ��Ī
�������ʣ����˸е�����ͨ������Ȼһ�¡�
LONG
        );
        set("exits", ([
//  "south" : __DIR__"ahome",
//  "north" : __DIR__"bhome",
//  "east"  : __DIR__"marhome",
//  "west"  : __DIR__"teahome",
//  "up"    : __DIR__"chome",
  "down"  : __DIR__"home",
]));


        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",100);
        set("no_magic",1);
        setup();
        replace_program(ROOM);
}    
