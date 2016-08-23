 // Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h> 
inherit ROOM;
int do_sanddrop(object me, object obj);
void create()
{
        set("short", "流沙");
        set("long", @LONG
你已经陷入流沙之中，四周没有一点着力的地方。你一点点地向下落去。除非
有人拉(pull)你一把，想活着离开这里恐怕比登天还难。你似乎已经看到黑白无常
在向你招手。
LONG
        ); 
    set("NONPC",1);
        set("coor/x",-1060);
        set("coor/y",-10);
        set("coor/z",-10);
        setup();
} 
void init(){    
        
        object ob;
        if( interactive( ob = this_player())) {
                ob->set_temp("sinking", 1);
                remove_call_out("sinking");
                call_out("sinking", 1, ob);
        }
} 
int sinking(object ob){
        int i, j;
        int damage;
  
        if(ob && environment(ob) == this_object()){
                j = ob->query_temp("sinking");
                message_vision(HIW"$N又在流沙中陷深了一些！！", ob);
                message_vision("$N几乎在绝望中哭了出来！！\n"NOR, ob);
                ob->set_temp("sinking", j + 1);
                damage = random(5)+5;
                i =  (int)ob->query("kee");
           ob->set("kee",(int) i - damage);
                if (j == 5) {
                        message_vision(HIG"\n突然间，流沙下滑的趋势顿了一下。露出了一个向下的洞口。\n"NOR,ob);
                        set("exits/down", __DIR__"chensha1");
                        call_out("close_path", random(6)+10, ob);
                }
                if( environment(ob) == this_object()){
                        call_out("sinking",random(5)+10, ob);   
                }
        }
        else 
        return 1;
} 
int close_path(object ob){
        if( query("exits/down") ) {
        message("vision","\n流沙慢慢下滑，洞口越来越小，很快就不见了。\n", this_object() );
        delete("exits/down");
    }
}  
int valid_leave(object who,string dir)
{
        object me;
     
        me = this_player();
        if(dir=="down"){
                if(me->query_cor() > 20) {
                message("vision",me->name() + "一横心，用足力气往下钻去... " , this_object(), me);
                return 1;
        } else {
                return notify_fail("那里似乎深不见底，你心里犹豫起来，不敢往流沙下面钻。 \n");
        }
    }
    return 0;
}  
int do_quit()
{
        object me, *inv;
        int i;
        me = this_player();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        do_sanddrop(me, inv[i]);
                }
} 
int do_sanddrop(object me, object obj)
{
        mixed no_drop;
        if( no_drop = obj->query("no_drop") )
                return 0;
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
                else {
                        message_vision( sprintf("$N丢下一%s$n。\n",     obj->query("unit")),
                                me, obj );
                        me->save();
                        if( !obj->query("value") && !obj->value() ) {
                                write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;  
}     
