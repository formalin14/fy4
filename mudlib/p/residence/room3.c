 inherit ROOM;
void create ()
{
  set ("short", "��Ϫ̶");
  set ("long", @LONG
��Ϫ̶����������ˮ�������������Ͽ���С�ɽȪ�Ҹ�ӿ��������к����
Ϫ��أ�׳�����裬��������ˮ��ʯ������̽��ӣ����׳����Ϫ��Ϫǰ���²�
԰�������̣������˱ǡ���ͨ�裬����گʱ��������ֲ�����׿���ɽ������ͦ
�㣬����ʮ�����
LONG);
        set("exits", ([
"eastup" : __DIR__"spear1",
//"southwest" : __DIR__"yeee1034829620",
//"northeast" : __DIR__"digi1030355695",
"northdown" : __DIR__"zack1",
//"down" : __DIR__"xigua1022982983",
"westup" : __DIR__"shenlany1",
"east" : __DIR__"cherry1",
//"up" : __DIR__"xigua1021957669", 
  "south" : __DIR__"room2",
  "north" : __DIR__"room4",
]));
        set("outdoors","qianfo");
        set("coor/x",10);
        set("coor/y",2020);
        set("coor/z",20);
        set("owner","public");
        setup();
  replace_program(ROOM); 
} 