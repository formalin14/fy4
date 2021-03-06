 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 15
#define Y_COOR 2040
#define Z_COOR 50
#define R_FLAG 2048
#define OWNER "chuchu"
#define CLASS "白云城"
inherit ROOM;
void create()
{
set("short", HIC"小羊卓雍错"NOR);
set("long", @LONG
楚楚于九七年西藏游羊卓雍错，回来一直不能释怀，遂依记忆命人开凿此湖。
    这里美得象个童话世界，是梦开始的地方。一面蓝蓝的湖水。那湖水蓝得令人
心痛。你忽然有一种不顾一切跳下去的冲动。刹那间你明白了什么叫飞蛾扑火，也
许美到了极至就是一种毁灭。湖面上游着几只黄澄澄的小鸭子，呷呷地唱着只有它
们能听懂的歌。湖边长满了郁郁葱葱的青草，草丛中盛开着好好多多不知名的野花，
还有很多圆圆、大大的蒲公英，微风拂过时一把把小伞带着各自的梦想飞向远方。
草地上趴着的一只小狗狗陶醉在眼前的美景中。
　　园子的一角有一座很高的假山，山顶上有一座别致的小亭。园子的尽头是一片
苍翠欲滴的竹林，似乎有一条曲曲折折的小路消失在林中，不知通向何方。

LONG
);
        set("exits", ([
	//	"north" : __DIR__"chuchu8",
		"up" : __DIR__"chuchu7",
		"south" : __DIR__"chuchu2",
	]));

        set("item_desc", ([
        	"duck": "小小鸭子呷呷呷地叫，走起路来摇啊摇啊摇。\n它们长着黄澄澄的羽毛，嫩黄的扁扁的嘴巴和脚掌，远远看去象一个个黄色的小绒球。\n"NOR,
        	"小鸭子": "小小鸭子呷呷呷地叫，走起路来摇啊摇啊摇。\n它们长着黄澄澄的羽毛，嫩黄的扁扁的嘴巴和脚掌，远远看去象一个个黄色的小绒球。\n"NOR,
        ]) );

        set("coor/x",X_COOR);
        set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("outdoors","residence");
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
        add_action("do_jump","jump");
        add_action("do_listen","listen");
}

int do_listen(string arg) 
{ 
   	object me, room; 
   	me = this_player(); 
	
	if(random(5)) 
	{
   		tell_object(me,HIM"你摒除心中所有杂念驻足倾听，有风声自竹林而来，仿佛倾诉着一个个遥不可及的幻朦。\n"NOR); 
   		message("vision",HIM""+me->name(me)+"突然驻足，似乎在用心聆听着什么。\n"NOR, environment(me),me); 
   	} else {
   		tell_object(me,HIG"冥冥中一个声音宛如竹林化身仙子轻声低唤你，悠扬空灵的旋律化成一支使人迷醇的歌，
将你不断的引向竹林深处。在竹林深处，人和竹之间留下了一段千古难解的迷。。。。。。\n"NOR); 
   		message("vision",HIG"一个声音自竹林旖旎而来，如水涓涓一洗江湖的杀孽之气，"+me->name(me)+"乘着一缕飘逸融入了冥冥。。。。。。\n"NOR, environment(me),me); 
      		room = find_object(__DIR__"chuchu8"); 
      		if(!objectp(room)) room=load_object(__DIR__"chuchu8"); 
      		me->move(room); 
   	}     
 
   	return 1; 
} 


int do_jump()
{
        object me;
        me = this_player();
        message_vision(HIC"$N被眼前的景致所惑，不顾一切跳了下去。只听“噗通”一声，宁静的湖面溅起十几\n", me);
	message_vision("尺高的水花，小鸭子被吓得四散游开，$N游啊游试图追上小鸭子。\n"NOR, me);
        remove_call_out("curehimup");
        call_out("curehimup", 5+random(10), me);
	return 1;
}

void curehimup(object me)
{
        int gin,kee,sen,mana,force,atman;
        object ob;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
        mana=(int)me->query("max_mana");
        force=(int)me->query("max_force");
        atman=(int)me->query("max_atman");
	if( me && environment(me) == this_object())
        {
        	message_vision(HIC"$N游了半天一只小鸭子也没追上，懊恼的爬上岸一头倒在草地上。\n"NOR, me);
	       	if(ob=present("dongdong", this_object()))
	       	{
        		message_vision(HIC"$N"+HIW"歪着脑袋看着$n，似乎很不明白", ob, me);
        		message_vision("$N为什么要把自己弄得浑身湿淋淋的。\n"NOR, me);
        	}
        	message_vision("$N的精气神全恢复了！！\n", me);
        	me->set("eff_gin",gin);
        	me->set("eff_kee",kee);
        	me->set("eff_sen",sen);
        	me->set("gin", gin);
        	me->set("kee", kee);
        	me->set("sen", sen);
        	me->set("mana", mana);
        	me->set("force", force);
        	me->set("atman", atman);
        	me->clear_condition();
        }
return;
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
    
