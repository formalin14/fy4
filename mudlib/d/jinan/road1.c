 // street2.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","б����");
  set("long",@LONG
�ƹ������������������У�����һ��������ʯ��·��������ɣ��ʯ������
�ӿ����ݣ����Ծ��������������������ϻ�����һ�����������������·����
�����У�һƥ����������������������Զ���������಻�ϵ�ɽ�ͱ��Ƕ���̩
ɽ�ˡ�
LONG
  );
  set("exits",([
         "southwest":__DIR__"lake",
         "northeast":__DIR__"road2",
               ]));
        set("objects", ([
                __DIR__"npc/sadguy" : 1,
                __DIR__"npc/shouma" : 1,
       ]) );
    set("outdoors", "jinan");
    set("coor/x",60);
    set("coor/y",1970);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}     