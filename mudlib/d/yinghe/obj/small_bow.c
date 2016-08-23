#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("落雁神弓", ({ "yan bow", "bow" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个漆黑的小弓，看上去像儿童的玩具，掂在手中却异常的
沉重，弓上还铸有奇怪的花纹。小弓似乎可以拉开。（ｏｐｅｎ）\n");
                set("value", 10000);
        set("material", "metal");
    }
} 
void init(){
        add_action("do_open", "open");
} 
int do_open(string arg){
        object me;
        
        me = this_player();
        if(!arg || arg != "bow" && arg != "pili bow"){
                return 0;
        }
        if(me->query("kee") < 100) {
                return notify_fail("你实在太累了，先休息一下吧。\n");
        }
        if(me->query_str() > 35 ) {
                message_vision(HIG"$N奋起神力，缓缓把弓拉满。。。\n"NOR, me);
                call_out("release_bow", 1, me);
        } else {
                message_vision("$N用力拉弓，神弓却丝毫不动。\n", me);
        }
        me->receive_damage("kee", 50);
        return 1;
} 
int release_bow(object me){
        object bat;
   if(!objectp(me) || environment(this_object()) != me) {
                return 0;
        }
        message_vision(HIG"\n$N微一松手，一股无形的箭气向前射出。\n"NOR, me);
        bat = present("soul bat", environment(me));
        bat->bat_die(me);
        return 1;
}      
