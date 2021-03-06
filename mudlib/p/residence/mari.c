 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 5
#define Y_COOR 2040
#define Z_COOR 40
#define R_FLAG 17
#define OWNER "mariner"
#define CLASS "财神庙"
inherit ROOM;
void create()
{
set("short", "龙侯庙");
set("long", @long
这里地方破落，没什麽摆设。只有一张竹塌，一尊神像而已。四面墙
均由海底万年珊瑚自然堆砌而成。阳光从珊瑚的缝隙中落下，在地面上够
成点点斑斑的荫影，仔细看这些荫隐。有含有某些规律，好象能从中领悟
些什麽。
long
);
        set("exits", ([
//"south" : __DIR__"room7",
"west" : __DIR__"tonic1",

]));
set("objects", ([
//"/p/residence/npc/tonicwa" : 1,
       ]) );
        set("item_desc", ([
                "珊瑚": "七彩斑斓的珊瑚，似乎可以移动（move）。\n",
                "神像": "普天之下，莫非王土；率水之濒；莫非龙侯。\n自哪吒闹海之後，玉帝深感四海管理之乱，特派七海龙神下界，统辖众水神。\n然，叁百年前，七海龙神竟私自携带重宝－－朱果下界，并不慎遗失！\n以至下界众生为争夺天界至宝，死伤无数。\n故，降龙神为七海龙侯。\n",
                "竹塌": "一张万年竹做的精致床几。\n"
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
        add_action("do_go","go"); 
         add_action("do_sleep", "sleep");
        add_action("do_move", "move");

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
  
int do_go()
{
if(random(5)){
this_player()->move(this_object());
return 1;
}
}

int do_sleep(string arg)
{
   object me, obj, girl;
   int gin, kee, sen; 
   me = this_player();
   obj = this_object(); 
   if (me->is_fighting()) return 1;
   if (this_object()->query_temp("marks/taken")) {
      tell_object(me, "床上有人耶。。。。\n");
      return 1;
   }
      else{
      message_vision("$N揉揉眼、打个哈欠，躺到了竹塌上，", me);
      tell_object(me, "很快你就觉的睡意朦胧。\n");
      message("vision", me->name()+"翻了几个身，找到个舒适的姿势，很快就进入了梦乡。\n", environment(me), me);
      obj->set_temp("marks/taken", 1);
      gin = (int) me->query("eff_gin");
      kee = (int) me->query("eff_kee");
      sen = (int) me->query("eff_sen");
      me->set("gin", gin);
      me->set("kee", kee);
      me->set("sen", sen);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<睡梦中>"NOR); 
      call_out("wake", 10, me);
      return 1;
   }
   return 1;
} 
void wake(object me)
{
   object obj; 
   obj = this_object();
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision("$N睁开了眼睛，一个鲤鱼打挺从床上跳了下来。\n", me); 
   tell_object(me, "你觉得精神好了很多。\n");
   obj->set_temp("marks/taken", 0);  
} 
int do_move(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="珊瑚" || arg =="shanhu" ) {
                write("你按照阴影的提示，挪了挪珊瑚，");
        
        
        
        if(  me->query("id") == "mariner" || me->query("id") == "popeye")
                {
                write("忽然神像目光一闪，你眼前迷糊，时空交错，似乎来到另外一个地方。\n");
                me->move("/d/baiyun/zhanmangtai");                
                return 1;       
                }
                else 
                {   if(  me->query("id") == "eyes")
                      {
                      write("忽然神像目光一闪，你眼前迷糊，时空交错，似乎来到另外一个地方。\n");
                      me->move("/d/wolfmount/shuaiyi");                
                       return 1;       
                } else                
                write("但什麽都没有发现。\n");
                return 1;
                }
        }
                write("你要挪开什么？\n");
                return 1;
} 
