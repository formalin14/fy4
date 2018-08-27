 // FYteam
#include <ansi.h>
inherit ROOM;
void create(){
        set("short", "银色沙丘顶");
        set("long", @LONG
这里是一个大沙丘的顶端，四周是一大片晶莹洁白的沙丘，似雪如银。脚踩在
沙地上，竟然有玲珑悦耳的乐声。沙丘连绵不断，占地广大。
LONG); 
        set("exits",([
                "northdown":__DIR__"silversand",
        ]) );
        //}}
        set("item_desc", ([
                "sand" : "一片晶莹洁白沙坡，然你有种想滑下去的感觉。（ｓｌｉｄｅ）\n",
                "沙丘" : "一片晶莹洁白沙坡，然你有种想滑下去的感觉。（ｓｌｉｄｅ）\n",
                "沙" : "一片晶莹洁白沙坡，然你有种想滑下去的感觉。（ｓｌｉｄｅ）\n",
        ]));
        set("indoors", "yinghe");
        setup();
} 
void init(){
        add_action("do_slide", "slide");
} 
int do_slide(){
        object me;
        
        me = this_player();
        message_vision(HIG"$N向下一坐，伴随着玲珑悦耳的乐声飞快的向下滑去。。。。\n"NOR, me);
        me->start_busy(2);
        call_out("falling", 1, me);
        return 1;
}
void falling(object me){
        object room;
        
        room = find_object(__DIR__"snakehall");
        if(!objectp(room)){
                room = load_object(__DIR__"snakehall");
        }
   message("vision", HIY"\n突然间一阵惊恐已极的惨叫声回荡在沙丘间。\n"NOR, this_object(), me);
        me->move(room);
        tell_object(me, HIY"\n你猛然向下一坠，落入了一个不大的空间，你身形尚未停稳，却已被眼前的景色
吓得失声大叫“啊~~~~~\n"NOR);
        message("vision", "只听一声惊恐已极的叫声，你注意到" + me->name() +"的存在。\n", 
                        environment(me), me); 
}       
