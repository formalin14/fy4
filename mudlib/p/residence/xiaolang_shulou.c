#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short",HIG"��¥"NOR);
  set("long",@LONG
���������������ѣ��ŵ������ʮһ�ɲ�����һ������д�ֵ��ˣ�����
�����ֵĳ̶ȳ����˰��������ڸ������壬����ƫ�����飬�������Ը������
�˼��ղ�������֮������漣����Ȼ���ŵĲ���ҲΪ����������
LONG
  );
  set("exits",([
                 "eastdown" : __DIR__"xiaolang2", 
                 "southeast": __DIR__"xiaolang_qilou",
                 "northeast": __DIR__"xiaolang_hualou",                
               ]));
    set("indoors", "residence");
        set("coor/x",14);
        set("coor/y",2035);
        set("coor/z",40);
        set("no_death_penalty",1);
        setup();
    replace_program(ROOM); 
}       
