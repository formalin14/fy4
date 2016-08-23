 // a skeleton for user rooms
#include <ansi.h>
#include <room.h>
#define X_COOR 15
#define Y_COOR 2035
#define Z_COOR 30
#define R_FLAG 2561
#define OWNER "xiaolang"
#define CLASS "��÷ɽׯ"
inherit ROOM;
void create()
{
set("short", HIC"����"NOR);
set("long", @LONG
����������㷢�����ﲼ�õļ򵥱��£��м�һ�ź�ľ����������ǽ��
����һ����״����ı�������֪���Ƿ���ȡ�����������������һ��д�⻭��
���п��Կ���ҹ��Բ�¸߹ң�

                                                      ��
                                                      
                                                      
                                       _/| 
��������������������������������������=/_/������ �� 
�������������� �� ������������������ _/ |���� �� ��
��������������������������������(�� /��,|���������� 
������������������������ ���  \_/^\/||__������˵ 
������������������������� _/~��`""~`"` \_       


һֻ�¶����������쳤Х��������һ������֮�ġ���ͤ�򡷣��������ĸ�¥��
�ֱ��������黭��������ǳ���������ȻС��(door)���ţ����������������
���Ǳߴ������������
LONG
);
        set("exits", ([
								"eastup" : __DIR__"xiaolang_qinlou",
								"southup":__DIR__"xiaolang_qilou",
								"westup": __DIR__"xiaolang_shulou",
								"northup":__DIR__"xiaolang_hualou",
//								"out" : __DIR__"xiaolang_xiaodao3",
]));
         set("item_desc", ([
                "����": HIB"��ѹ���ı������������ĵ����⣬����ò�Ҫ������\n"NOR,
                "��": "С������,���ƺ�����������\n",
                "door": "С�����ڣ����ƺ�����������\n",
                
        ]) );  
        set("objects", ([
               __DIR__"npc/xiaolangwa" : 1,
               __DIR__"obj/xiaolang_desk" : 1,
                        ]) );
        set("coor/x",X_COOR);
        set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("no_fight",1);
        set("no_steal",1);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("no_death_penalty",1);
        setup();
}
void init()
{
	add_action("do_say","say");
	add_action("do_pull", "pull");
}
    
int do_say(string arg)
{
    object me;
    object room;
    me=this_player();
    if( arg == "����������")
    {
        message_vision(HIY "$NͻȻ��ʧ�ˡ�����������\n"
        NOR, this_player());
        switch( random(4) ) {

	        case 0:
        	room = load_object("/d/tieflag/stone1");
        	this_player()->move(room); 
        	break; 

	        case 1:
        	room = load_object("/d/shenshui/shanfang");
        	this_player()->move(room);
        	break;
     
/*		case 2:     	
        	room = load_object("/d/guanwai/citygate");
        	this_player()->move(room);
        	break;     */

		case 2:
        	room = load_object("/d/bat/dong");
        	this_player()->move(room);
        	break;
        	
		case 3:
        	room = load_object("/d/wolfmount/backroom");
        	this_player()->move(room);
        	break;
        	        }       	
        return 1;
    }
    return 0;
} 

void close_path()
{
        if( query("exits/out") ) {
    message("vision","����һ��紵����С��[��]��һ���������ˡ�\n",this_object() );
    delete("exits/out");
    }
} 
int do_pull(string arg)
{
        object me;
    me = this_player();
    if( arg=="door" || arg =="С��") {
        message_vision("$N��С��һ����֨��������һ��С�ſ��ˡ�\n", me);
                set("exits/out", __DIR__"xiaolang_xiaodao3");
                call_out("close_path", 2);
        }
        else {
                write("��Ҫ��ʲô�أ�\n");
        }
        return 1;       
 }      