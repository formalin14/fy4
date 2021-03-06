#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"琴楼"NOR);
        set("long", 
"进入琴楼，跃入眼帘的首先是摆在东南西北四面的四张古琴，东面的"+HIC"春雷"NOR+"，
南面的"+MAG"九佩"NOR+"，西面的"+HIG"绿绮"NOR+"，北面的"+YEL"松纹"NOR+"；每张古琴有着不同的颜色和历史，据
说弹奏他们会发出不同的声音，除去这些古琴，墙上还有很多名家乐谱，看来
这里是庄主弹琴之地。\n\n"
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
                "春雷": HIC"琴体狭长，琴弦似乎较粗，看来需要很高的演奏技法。是古传名琴之一。\n"NOR,
                "chunlei": HIC"琴体狭长，琴弦似乎较粗，看来需要很高的演奏技法。是古传名琴之一。\n"NOR,
                "九佩": MAG"这是一把唐琴，漆色富贵喜伏羲式，形体饱满，上髹紫漆，间杂朱砂补\n之色， 声形俱佳，为传世之极品。\n"NOR,
                "jiupei": MAG"这是一把唐琴，漆色富贵喜伏羲式，形体饱满，上髹紫漆，间杂朱砂补\n之色， 声形俱佳，为传世之极品。\n"NOR,
                "绿绮": HIG"琴体暗现绿色，是古传名琴之一。\n"NOR,
                "lvqi": HIG"琴体暗现绿色，是古传名琴之一。\n"NOR,
                "松纹": YEL"琴体显出松木纹理，是古传名琴之一。\n"NOR,
                "songwen": YEL"琴体显出松木纹理，是古传名琴之一。\n"NOR,
                
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
       
   if(!arg || (arg != "春雷" && arg != "九佩" && arg != "绿绮" && arg != "松纹" && arg != "chunlei" && arg != "jiupei" && arg != "lvqi" && arg != "songwen" ))
            return notify_fail("你要弹什么？\n");
   if( me->query_skill("music",1) >= 200 && (arg == "春雷" || arg == "chunlei")){   
        message_vision("$N凝神弹拨琴弦，"HIC"春雷"NOR"发出低沉的声响，如蛰雷初动，震撼心魂。\n",this_player());
        return 1; }
   if( me->query_skill("music",1) >= 100 && (arg == "九佩" || arg == "jiupei")) {
        message_vision("$N缓缓拨动琴弦，"MAG"九佩"NOR"发出玲珑之声，宛若空山新雨。\n",this_player());
        return 1; }
   if( me->query_skill("music",1) >= 20 && (arg == "绿绮" || arg == "lvqi"))  {
        message_vision("$N轻拨琴弦，"HIG"绿绮"NOR"发出梵天清唱般的音色。\n",this_player());
        return 1; }
   if( me->query_skill("music",1) >= 50 && (arg == "松纹" || arg == "songwen")){
        message_vision("$N曼挑琴弦，"YEL"松纹"NOR"发出松风吹动般的音色。\n",this_player());
        return 1; }              
   else return notify_fail("你的琴道等级不够，学学再弹琴吧。\n");
   
   return 1;

} 