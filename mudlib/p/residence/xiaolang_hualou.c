#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short",HIG"��¥"NOR);
  set("long",@LONG
��ʮһ��ʮ���꿪ʼ�Ӵ��й��������ʦѧ�գ����ڻ�÷����˵����
����Ϊ׷��һŮ�ӣ���������Ϊ�仭����ɽˮ���񣬴�Ů����Ϊ�������
���������Ļ����䣬����������ڻ���������ˣ�����Ҳ�ղ��˹�������
��������������˼�ֵ���ǵĴ���֮����
LONG
  );
  set("exits",([
                 "southdown" : __DIR__"xiaolang2", 
                 "southwest" : __DIR__"xiaolang_shulou",
                 "southeast" : __DIR__"xiaolang_qinlou",                
               ]));
    set("indoors", "residence");
        set("coor/x",15);
        set("coor/y",2036);
        set("coor/z",40);
        set("no_death_penalty",1);
        setup();
    replace_program(ROOM); 
}       