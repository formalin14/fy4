#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "蛰龙沙穴");
        set("long", @LONG
这里是一个地下溶洞，四周黑黑的，隐约可以看见周围怪石密布，地上有一黑
洞，似有一条暗河从中流过，隐约可以听到水声。如此地下深处居然还可以见物，
只因为在角落里，有一点暗红的光芒，蒙蒙照亮了幽幽的沙水洞。
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"sandriver1",
        ]));
        set("no_fly",1);
//      set("no_curse",1);
        set("objects", ([
//              __DIR__"npc/sand_dragon" : 1,
        ]) );
        set("indoors", "quicksand");
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        set("dragon_death",0);
        setup();
} 
int valid_enter(object me) {
        tell_object(me, HIR"\n你往上一钻，吃惊地发现，这里竟然是一个巨大的空洞。
四周怪石嶙峋，给你一种不祥之感。 \n\n"NOR);
        me->set_temp("out_river", time());
        return 1;
} 
void tell_exit(){
        object *inv, room;
        int j;
    
        room = find_object(__DIR__"dongd1");
        if(!objectp(room)) room = load_object(__DIR__"dongd1");        
        message("vision",HIY"红宝石发出的灿灿红光隐隐照亮了洞穴，在红光的映衬下，你看到一块石头
上似乎有一个标记。\n"NOR, this_object());
        inv = all_inventory(this_object());
        for(j=0; j<sizeof(inv); j++) {
                inv[j]->move(room);
        }
}   
void reset() {
        object dragon,new_dragon;
        
        ::reset();
        dragon=present("hibernating dragon",this_object());
        new_dragon=new(AREA_QUICKSAND"npc/sand_dragon");
        
        if (dragon)     return;
        
        if (!query("dragon_death")) {
                new_dragon->move(this_object());
                set("dragon_death",1);
                return;
        }
        
        if(query("dragon_death")+86400<time() && !random(4))
                new_dragon->move(this_object());
                
        return;
}
        
        
        
          
