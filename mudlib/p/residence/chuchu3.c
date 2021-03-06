 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 16
#define Y_COOR 2039
#define Z_COOR 50
#define R_FLAG 2063
#define OWNER "chuchu"
#define CLASS "白云城"
inherit ROOM;
void create()
{
set("short", HIM"凝梦轩"NOR);
set("long", @LONG
才至房门，一缕幽香袭人而来，原来已经到了唠叨和楚楚的卧室。
　　从屋顶中央垂下的曼妙轻纱将一张圆圆的大床罩在里面，纱帐里几只萤火虫轻
盈飞舞，明明灭灭，亦真亦幻。床上铺着厚厚软软的天鹅绒，枕边躺着一方雪白手
帕（Shoupa）。床几上一盆纤尘不染的马蹄莲正在盛放。
　　屋子的角落里檀香炉温暖的燃烧着，终年氤氲着一缕香烟，让人总会不自觉地
出了神，痴痴看那袅袅不绝的香烟，仿佛勾起人沉深平和的心胸世界。
　　大熊爸爸站在墙边，面带微笑看着屋子里的一切，似乎很满意的样子。

LONG
);
        set("exits", ([
		"west" : __DIR__"chuchu2",
	]));

        set("item_desc", ([
        	"shoupa": "这是当年楚楚送给唠叨的信物，上面绣着几行娟秀的小字：
"+HIC"死生契阔，与子相悦，执子之手，与子偕老。\n"NOR,
        	"手帕": "这是当年楚楚送给唠叨的信物，上面绣着几行娟秀的小字：
"+HIC"死生契阔，与子相悦，执子之手，与子偕老。\n"NOR,
        	"bearpapa": "一个很大很大的毛绒玩具，是一只大熊的造型，所以叫做大熊爸爸。它高大魁梧，
高约八尺，宽也有七尺，站在墙边几乎挡住了半面墙。圆圆的大头，两只半圆的
耳朵，总是笑咪咪的黑眼睛。他身上穿着件天蓝色的T-Shirt，脖子上系着一条
"+HIR"血红丝巾"+NOR"。炯炯有神的眼睛的正在看着你，仿佛在笑，又仿佛马上就要张口和你
说话一样。\n",
        	"大熊爸爸": "一个很大很大的毛绒玩具，是一只大熊的造型，所以叫做大熊爸爸。它高大魁梧，
高约八尺，宽也有七尺，站在墙边几乎挡住了半面墙。圆圆的大头，两只半圆的
耳朵，总是笑咪咪的黑眼睛。他身上穿着件天蓝色的T-Shirt，脖子上系着一条
"+HIR"血红丝巾"+NOR"。炯炯有神的眼睛的正在看着你，仿佛在笑，又仿佛马上就要张口和你
说话一样。\n",
        ]) );

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
        add_action("do_rabbit","rabbit");
        add_action("do_ask","ask");
}

int do_ask(string arg)
{
	string obname, things, about;
	if(!arg || sscanf(arg, "%s %s %s", obname, about, things)!=3 )
	{
		write("你要问谁什么事啊？\n");
		return 1;
	}
	if(obname=="bearpapa" || obname=="大熊爸爸")
	{
		if(things=="今天有没有坏人来啊？")
		{
			message_vision(HIC"大熊爸爸威武的站在那里，好象在说：“有我在这里，哪有坏人敢来这里啊！”\n"NOR, this_player());
		}
		else
		{
			if(random(2))
				message_vision(HIC"看起来大熊爸爸不想理$N。\n"NOR, this_player());
			else
			{	message_vision(HIC"大熊爸爸对$N嚷道：你以为你是林青霞啊？！"NOR, this_player());
				message_vision(HIC"大熊爸爸看都不看$N一眼，哼了一声，高高\n"NOR, this_player());
				message_vision(HIC"的把头扬起来了.......不理$N....\n"NOR, this_player());
			}
		}
	return 1;
	}
	else
	{
		write("你要问谁啊？\n");
	}
	return 1;
}

int do_rabbit(string arg)
{
	if(arg=="bearpapa" || arg=="大熊爸爸")
	{
		message_vision(HIC"$N对大熊爸爸唱道：“大熊爸爸，把门儿开开，小白兔要进来。”\n"NOR, this_player());
	        if( !query("exits/east") ) 
	        {
	        	message_vision(HIC"大熊爸爸对$N笑了笑，一闪身露出墙上的一扇白玉小门。\n"NOR, this_player());
        		set("exits/east", __DIR__"chuchu5");
        		call_out("close_path", 5);
        	}
		return 1;
	}
	message_vision(HIC"$N唱道：“小兔乖乖，把门儿开开。”\n"NOR,this_player());
	return 1;
}

void close_path()
{
        if( !query("exits/east") ) return;
        message("vision","大熊爸爸闪身挡住了墙上的小门\n", this_object() );
        delete("exits/east");
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
    
