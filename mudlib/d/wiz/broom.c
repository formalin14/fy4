 // Tea@fy4
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
һ�ҹ�ɫ����ĵ��̴��ã�������ʱ�˿̿���һ�ˡ��������
����ľ���棬����һ���ų��룬�ƺ����ź�Щ���������ұ�ɢ����
Щ�������ӣ��������е���졣�����п��������Լ͸�����ĵĵ�
�⡣�����ڷ��ź�Щ��Ѭ����ǽ�ĵط����������ٺϡ�һ�ж���
ô�ջ����ˡ�
LONG
        );
        set("exits", ([
  "south" : __DIR__"home",
  "north" : __DIR__"home",
  "east"  : __DIR__"home",
  "up"    : __DIR__"home",
  "down"  : __DIR__"jobroom",
]));


        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",100);
        set("no_magic",1);
        setup();
        replace_program(ROOM);
}    
