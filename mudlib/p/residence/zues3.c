#include <ansi.h>
#include <room.h>
#define X_COOR -10
#define Y_COOR 2040
#define Z_COOR 50
#define R_FLAG 2561
#define OWNER "zues"
#define CLASS "财神庙"
inherit ROOM;
void create()
{
set("short", WHT"正厅"NOR);
set("long", @LONG
这是一间极为宽敞的屋子，正面挂着一副画（picture)，东面是门（door)，西面是一
副屏风（pingfeng)。屋子中央摆着一张红木八仙桌，桌上放着山珍海味和四季鲜果，还
有几副碗筷。
LONG
);
        set("exits", ([
	"south" : __DIR__"zues2",
/*	"east"  : __DIR__"zues4",
	"west"  : __DIR__"zues5",*/
	]));
set("objects", ([

       ]) );
    set("item_desc", ([
                "picture": "这是一副春游图，记载着主人携手郊游的趣事。\n",
                "door": "这是主人卧室的房门，似乎可以拉开(pull)。\n",
                "pingfeng": "这是一副画着梅兰竹菊花卉的屏风，似乎可以拉开(pull)。\n",
        ]) );
//        create_door("east", "door", "west", DOOR_CLOSED);
//        create_door("west", "pingfeng", "east", DOOR_CLOSED);
        set("coor/x",X_COOR);
   	set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("indoors","residence");
        setup();
}
void init()
{
        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("indoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");
        add_action("do_pull","pull");
//        add_action("do_push", "push");
                //add_action("do_sleep", "sleep");
}
int valid_enter(object me)
{
        int flag;
// means no enter at the beginning.
        int enter = 0;
    flag = (int) query("room_flag");
// always let owner go in:
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 16)
        enter = 1;
        if(flag & 512)
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
        if(flag & 2048) 
        {
                if(strlen(query("invite")) && strsrch((string)query("invite"),"["+(string)me->query("id")+"]") != -1)
           enter = 1;
        }
//      write(sprintf("%d", enter));    
        return enter;
}
int do_list()
{
        object me;
        string *list,invitelist;
        me = this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        invitelist = query("invite");
        if (strlen(invitelist))
        {
                list = explode("]"+invitelist+"[", "][");
                write("你邀请了下列玩家到你的房间:\n");
                for(int i=0;i<sizeof(list);i++)
                        write(list[i]+"\n");
        }else
                write("你没有邀请任何人到你的房间。\n");
        return 1;
} 
int do_invite(string arg)
{
        object me;
        string invitelist;
        me= this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        if( !arg )
        {
                write("你要邀请谁? \n");
                return 1;
        }
        invitelist = (string)query("invite");
        if(strlen(invitelist) && strsrch(invitelist,"["+arg+"]") != -1)
        {
                //if the person has already been invited, remove it from invite list.
                invitelist = replace_string(invitelist,"["+arg+"]","");
           set("invite",invitelist);
                write("你将"+arg+"从你的邀请名单中除去。\n");
        }else
        {
                //invite the person.
                if( find_player(arg))
                {
                        if(!strlen(invitelist))
                                set("invite","["+arg+"]");
                        else
                                set("invite",invitelist+"["+arg+"]");
                        write("你邀请"+arg+"来你的房间。\n");
                }else
                {
                        write("咦... 有这个人吗?\n");
                }
        }
        return 1;
} 
int do_setowner(string arg)
{
        string oldowner;
        oldowner = (string)query("owner");
        set("owner",arg);
        write("你将房间的主人暂时设为"+arg+"。\n");
        call_out("set_back",60, oldowner);
        return 1;
} 
int set_back(string oldowner)
{
        set("owner", oldowner);
        return 1;
}
void close_door()
{
    if( query("exits/east") ) {
       message("vision","小门自动关上了。\n",this_object() );
       delete("exits/east");
    }
} 

void close_pingfeng()
{
    if( query("exits/west") ) {
       message("vision","屏风自动合上了。\n",this_object() );
       delete("exits/west");
    }
} 

int do_pull(string arg)
{
        object me;
        me = this_player();
        if( arg=="door" ) {
        	message_vision("$N轻轻的拉开小门。\n", me);
        	set("exits/east", __DIR__"zues4");
        	call_out("close_door", 5);
	}else if(arg=="pingfeng"){
	        	message_vision("$N轻轻的拉开屏风。\n", me);
        		set("exits/west", __DIR__"zues5");
        		call_out("close_pingfeng", 5);
        }else{
        	write("你要拉开什么？\n");
        }
        
        return 1;       
 }      