#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"梅园小道"NOR);
        set("long", @LONG
跨入山庄大门，一条碎石小路延伸到前方的花园，小路两旁长着各式各样的奇
花异草，茂盛的树枝遮挡在小路上方，形成特有的拱门，各种小鸟在花草树木中雀
跃欢叫，这里四季如春，花朵散发的香味让你不禁想深吸一口。
LONG
        );
    set("exits", ([ 
                "south" : __DIR__"xiaolang1",
                "north" : __DIR__"xiaolang_xiaodao2",
        ]));
/*    set("objects", ([
                __DIR__"npc/woodcutter2" : 1,
        __DIR__"npc/yellowbird" : 1,
    ]));    */
    set("outdoors", "residence"); 
    set("coor/x",15);
    set("coor/y",2031);
    set("coor/z",30);
        setup();
} 
void init(){
    int i;
    
    add_action("do_smell","smell");
    i = NATURE_D->set_season();
        if(i == 4){
                return;
        }
        if(NATURE_D->is_day_time() && NATURE_D->get_weather() == "晴" 
                && !query("heal_bird")) {
                set("heal_bird", 1);
        call_out("heal_bird", random(20), this_player());
    }    
} 
int heal_bird(object me){
    object bird;
    
    if(environment(me) != this_object()) {
        return 0;
    } 
    bird = new(__DIR__"npc/bird");
    if(objectp(bird) && !present("yellow bird", this_object()) ){
        bird->move(this_object());
        message_vision(HIG"\n突然草丛中一阵响动，原来是一只受伤的$N在挣扎。\n"NOR,bird);
    }  
} 

int do_smell(string arg) 
{ 
   object me; 
   int gin, sen; 
   
   me = this_player(); 
   
   if(!me->query_temp("marks/smelled")){
      	tell_object(me,HIR "你深吸了一口气，顿时满园花香扑鼻而来，让你精神为之一振！\n"NOR); 
   			gin = (int) me->query("eff_gin");
   			sen = (int) me->query("eff_sen");
   			me->set("gin", gin);
   			me->set("sen", sen);
   			me->set_temp("marks/smelled", 1); 
                                       } 
    else{
   			tell_object(me,HIR "你深吸了一口气，顿时满园花香扑鼻而来！\n"NOR);  
   			message("vision",me->name(me)+"闭着眼睛，用鼻子深吸了一口气。\n", environment(me),me);   
   			me->start_busy(1); 
   			me->set_temp("marks/smelled", 1); 
   			}
   return 1; 
} 

 void reset(){
        ::reset();
        delete("heal_bird");
}
