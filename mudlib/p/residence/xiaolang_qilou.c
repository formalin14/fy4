#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short",HIG"��¥"NOR);
  set("long",@LONG
������ׯ����ʮһ�����˶Ծ�֮��������10�꿪ʼѧ���壬��ʦ�Ը��ף�15��
��ʼ��ѧΧ�壬����С�ɣ�������ֿ���ڴ˼��ս������ҹ������԰��Ӹ��ڶ���
�����������䲼�ü����ţ�ǽ���ϻ�����ʱ������Ҳо֣�����������Ͼ֮ʱ��
�������˶��ġ�
LONG
  );
  set("exits",([
                 "northdown" : __DIR__"xiaolang2", 
                 "northeast" : __DIR__"xiaolang_qinlou",
                 "northwest" : __DIR__"xiaolang_shulou",       
               ]));
    set("indoors", "residence");
        set("coor/x",15);
        set("coor/y",2034);
        set("coor/z",40);
        set("no_death_penalty",1);
        setup();
    replace_program(ROOM); 
}       
