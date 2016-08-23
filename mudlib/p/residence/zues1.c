 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 0
#define Y_COOR 2038
#define Z_COOR 50
#define R_FLAG 16
#define OWNER "zues"
#define CLASS "财神庙"
inherit ROOM;
void create()
{
set("short", RED"宙斯神殿"NOR);
set("long", @LONG
这里其实并不是传说当中的天堂，只是因为此间主人当年纵横江湖数十载，
后来厌倦了打打杀杀的日子，便托人建造了此庄园，主人每年常常携妻来此居
住，只因主人叫宙斯，故来此名。抬头望去，有扇大门(door)紧闭，你可以去
敲敲(knock)。
LONG
);
        set("exits", ([
		"east" : "/p/residence/room7",
	])); 
	set("objects", ([
      		 ]) );
      	set("item_desc", ([
                "大门": "这扇大门紧紧关着。\n",
                "door": "这扇大门紧紧关着。\n",
        ]) ); 
        set("coor/x",X_COOR);
        set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
	set("outdoors","residence");
   	set("class", CLASS);
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
        if(flag & 16) set("outdoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");
        add_action("do_knock","knock");
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
  
int closepath()
{
        if( !query("exits/enter") ) 
                return 1;
        message("vision","大门又无声无息的关上了。\n",this_object());
                delete("exits/enter");
   return 1;
} 
int do_knock()
{
	object me;
	me=this_player();
	message_vision("$N走上前去，“咚咚咚”的敲了敲大门。\n",me);
        set("exits/enter",__DIR__"zues2");
        message("vision","＂吱啦＂一声，小门自动向里打开。\n",this_object());
        call_out("closepath",5);
        return 1;
} 