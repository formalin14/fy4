#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
这儿的摆设更为简陋。屋子里到处都积着灰尘，像是已许久没有人来过。一个
米袋打散在地上，长出了厚厚的一层青苔。东墙有把断了的长枪，枪尖锈得没有一
丝光泽。西角布满了蛛网，一晃一晃的，有些蛛网巳经脱落下来，蜘蛛正忙着在重
新织起。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"yard1",
        ]));
        set("item_desc", ([
                "长枪": "一把普普通通的长枪，枪尖锈的没有一丝光泽。\n",
                "米袋": "一个破旧的米袋(bag)，已经不能再装什么东西了。\n",
                "青苔": "也许是太潮湿的缘故，米袋上长了一层青苔(moss)。\n",
                "蛛网": "蛛网(web)上沾了许多灰尘，几只蜘蛛正忙碌地在修补着，几根蛛丝(thread)垂落下来。\n",
                "蛛丝": "你仔细地看了看，有根蛛丝特别奇怪，似乎是根金属的细丝(metalthread)。\n",
                "金属的细丝": "这根细丝可以拉动（pull），不过细丝的后面似乎连着警铃，若
机关不排除，肯定会招来守卫。\n",
                "bag": "一个破旧的米袋，已经不能再装什么东西了。\n",
                "moss": "也许是太潮湿的缘故，米袋上长了一层青苔。\n",
                "web": "蛛网上沾了许多灰尘，几只蜘蛛正忙碌地在修补着，几根蛛丝垂落下来。\n",
                "thread": "你仔细地看了看，有根蛛丝特别奇怪，似乎是根金属的细丝(metalthread)。\n",
                "metalthread": "这根细丝可以拉动（pull），不过细丝的后面似乎连着警铃，若
机关不排除，肯定会招来守卫。\n",
        ]) );
        set("alarm",0);
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_pull", "pull");
}  
int do_pull(string arg){
        
        object me, guard, op_room, room, another;
            
        me = this_player();
        if(!arg || (arg != "金属的细丝" && arg != "细丝"
                && arg != "metalthread" )) {
                return 0;
        }
        if (guard=present("guardian",this_object()))
                return notify_fail("守卫大喝一声，“偷偷摸摸地想干什么！“\n");
        seteuid(getuid());
        op_room = find_object(__DIR__"controlroom");
        if(!objectp(op_room)) 
                op_room = load_object(__DIR__"controlroom");       
        if (op_room->query("thread")) {
                message_vision("$N一拉蛛丝，忽然警铃大作，跳出了几个守卫。\n", me);
                another = new(AREA_EREN2"npc/guarda");
                another->move(this_object());
                add("alarm",1);
                if (query("alarm")>=3) {
                        another = new(AREA_EREN2"npc/guarda");
                        another->move(this_object());
                        another = new(AREA_EREN2"npc/guarda");
                        another->move(this_object());
                        message("vision","守卫说：“看来不多叫几个兄弟是摆不平你了！“\n",this_object());
                }
                return 1;
        }
        room = find_object(__DIR__"studyroom");
        if(!objectp(room)) 
                room = load_object(__DIR__"studyroom");   
        message_vision(HIW"$N只听“格”的一声，接着，又是一连串‘格格”声响，蛛网下的
一堆枯柴突然缓缓移动，露出一个洞来！\n"NOR,me); 
        message_vision(YEL"$N一声惊呼，向洞里掉了下去。\n"NOR,me);
        me->move(room);
        return 1;
} 
void reset()
{
        ::reset();
        set("alarm",0);
        
}   
