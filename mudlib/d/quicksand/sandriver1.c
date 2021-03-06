#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "沙河底");
        set("long", @LONG
原来这里是一道暗河，冰冷的水让你忘却了身在沙漠，周围一片昏暗，都是迷
迷蒙蒙的沙水，你可以感觉到水中的沙子轻轻地摩擦着你的面颊，并住一口气，你
微微睁眼向四周望去，透出微微红光的洞口更加清楚了，就在你的正上方。 
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"shaxue",
        ])); 
        set("indoors", "quicksand"); 
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
} 
void init() {
        call_out("airing", 5, this_player());
} 
int airing(object ob, int i)
{
        int htime, ntime;
    
        if( environment(ob) == this_object())   {
                htime = (int)ob->query_str() + (int)ob->query_kar();
                if(!(ntime = (int)ob->query_temp("marks/水时"))) {  
                        ntime = 5;
                } else {
                        ntime = ntime + 5;
                }
                ob->set_temp("marks/水时", ntime);
                if( ntime > htime ) {
                ob->die();
                ob->set_temp("marks/水时", 0);
        }
        else if( ntime > (htime - 15) )
            message_vision(HIR "$N已经憋成半昏迷状态，再不赶快出水，就会憋死在这儿。\n"NOR, ob);
        else if( ntime > (htime - 30) )
            message_vision(HIR "$N已经憋得面红耳赤，半分钟之内再不出水，恐怕会憋死在这儿。\n"NOR, ob);
        else 
            message_vision(HIB "$N觉得胸口越来越闷，大概在水里已呆不了很久。\n"NOR, ob);
        
        call_out("airing",5, ob);
    }
    return 1;
} 
int valid_leave() {
        message_vision(HIB"$N屏住气，连游带爬入了洞口。\n"NOR, this_player()); 
        this_player()->set_temp("marks/水时", 0);
        return 1;
}
