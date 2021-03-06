 // a skeleton for user rooms
#include <ansi.h>
#include <room.h>
#define X_COOR 15
#define Y_COOR 2035
#define Z_COOR 30
#define R_FLAG 2561
#define OWNER "xiaolang"
#define CLASS "万梅山庄"
inherit ROOM;
void create()
{
set("short", HIC"客厅"NOR);
set("long", @LONG
进入客厅，你发现这里布置的简单别致，中间一张红木大桌，北面墙上
挂着一把形状怪异的兵器，不知道是否能取下来，兵器左面挂着一幅写意画，
画中可以看到夜空圆月高挂，

                                                      ⊙
                                                      
                                                      
                                       _/| 
　　　　　　　　　　　　　　　　　　　=/_/　　　 恶 
　　　　　　　 　 　　　　　　　　　 _/ |　　 　 狼
　　　　　　　　　　　　　　　　(　 /　,|　　　　传 
　　　　　　　　　　　　 ★　　  \_/^\/||__　　　说 
　　　　　　　　　　　　★【 _/~　`""~`"` \_       


一只孤独的狼王仰天长啸，右面是一幅王羲之的《兰亭序》，这里有四个楼层
分别是琴棋书画，客厅里非常安静，虽然小门(door)关着，你能清楚的听到外
面那边传来的鸟叫声。
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
                "兵器": HIB"这把怪异的兵器正发着幽幽的蓝光，你最好不要碰它。\n"NOR,
                "门": "小门虚掩,你似乎可以拉开。\n",
                "door": "小门虚掩，你似乎可以拉开。\n",
                
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
    if( arg == "般若波罗蜜")
    {
        message_vision(HIY "$N突然消失了。。。。。。\n"
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
    message("vision","外面一阵风吹来，小门[哐]的一声，关上了。\n",this_object() );
    delete("exits/out");
    }
} 
int do_pull(string arg)
{
        object me;
    me = this_player();
    if( arg=="door" || arg =="小门") {
        message_vision("$N把小门一拉，吱。。。的一声小门开了。\n", me);
                set("exits/out", __DIR__"xiaolang_xiaodao3");
                call_out("close_path", 2);
        }
        else {
                write("你要拉什么呢？\n");
        }
        return 1;       
 }      