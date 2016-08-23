#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"��¥"NOR);
        set("long", 
"������¥��Ծ�������������ǰ��ڶ���������������Ź��٣������"+HIC"����"NOR+"��
�����"+MAG"����"NOR+"�������"+HIG"���"NOR+"�������"+YEL"����"NOR+"��ÿ�Ź������Ų�ͬ����ɫ����ʷ����
˵�������ǻᷢ����ͬ����������ȥ��Щ���٣�ǽ�ϻ��кܶ��������ף�����
������ׯ������֮�ء�\n\n"
        );
    set("exits", ([ 
                "westdown" : __DIR__"xiaolang2",
                "southwest" : __DIR__"xiaolang_qilou",
                "northwest" : __DIR__"xiaolang_hualou",       
        ]));
/*    set("objects", ([
                __DIR__"obj/jiupei" : 1,
                __DIR__"obj/lvqi" : 1,
                __DIR__"obj/songwen" : 1,
                __DIR__"obj/chunlei" : 1,

    ])); */
    
    set("item_desc", ([
                "����": HIC"���������������ƺ��ϴ֣�������Ҫ�ܸߵ����༼�����ǹŴ�����֮һ��\n"NOR,
                "chunlei": HIC"���������������ƺ��ϴ֣�������Ҫ�ܸߵ����༼�����ǹŴ�����֮һ��\n"NOR,
                "����": MAG"����һ�����٣���ɫ����ϲ����ʽ�����履�����������ᣬ������ɰ��\n֮ɫ�� ���ξ�ѣ�Ϊ����֮��Ʒ��\n"NOR,
                "jiupei": MAG"����һ�����٣���ɫ����ϲ����ʽ�����履�����������ᣬ������ɰ��\n֮ɫ�� ���ξ�ѣ�Ϊ����֮��Ʒ��\n"NOR,
                "���": HIG"���尵����ɫ���ǹŴ�����֮һ��\n"NOR,
                "lvqi": HIG"���尵����ɫ���ǹŴ�����֮һ��\n"NOR,
                "����": YEL"�����Գ���ľ�����ǹŴ�����֮һ��\n"NOR,
                "songwen": YEL"�����Գ���ľ�����ǹŴ�����֮һ��\n"NOR,
                
        ]) );  
        
    set("indoors", "residence"); 
    set("coor/x",16);
    set("coor/y",2035);
    set("coor/z",40);
    set("no_death_penalty",1);
        setup();
} 
void init()
{
	add_action("do_play","play");
}

int do_play(string arg) 
{ 
   object me; 
   me=this_player();   
       
   if(!arg || (arg != "����" && arg != "����" && arg != "���" && arg != "����" && arg != "chunlei" && arg != "jiupei" && arg != "lvqi" && arg != "songwen" ))
            return notify_fail("��Ҫ��ʲô��\n");
   if( me->query_skill("music",1) >= 200 && (arg == "����" || arg == "chunlei")){   
        message_vision("$N���񵯲����ң�"HIC"����"NOR"�����ͳ������죬�����׳��������Ļꡣ\n",this_player());
        return 1; }
   if( me->query_skill("music",1) >= 100 && (arg == "����" || arg == "jiupei")) {
        message_vision("$N�����������ң�"MAG"����"NOR"��������֮����������ɽ���ꡣ\n",this_player());
        return 1; }
   if( me->query_skill("music",1) >= 20 && (arg == "���" || arg == "lvqi"))  {
        message_vision("$N�Ღ���ң�"HIG"���"NOR"���������峪�����ɫ��\n",this_player());
        return 1; }
   if( me->query_skill("music",1) >= 50 && (arg == "����" || arg == "songwen")){
        message_vision("$N�������ң�"YEL"����"NOR"�����ɷ紵�������ɫ��\n",this_player());
        return 1; }              
   else return notify_fail("����ٵ��ȼ�������ѧѧ�ٵ��ٰɡ�\n");
   
   return 1;

} 