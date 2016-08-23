 // Room: white_earth.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "白色土地"); 
        set("long", @LONG
这是一个白皑皑的土坡，它延伸而下，构成了五色土金字塔的一面。
LONG);
        set("type","street");
        set("exits",([
        "southup":__DIR__"earthtemple",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/huo_tianqing" : 1,
        ]) );
        set("jade", 1);
        setup(); 
}
void init(){
        add_action("do_search", "search");
} 
int do_search(){
        object me, obj, huo;
        me = this_player();
        huo = present("huo tianqing", this_object());
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("你正在忙！\n");
        }
        me->start_busy(1);
        message_vision("$N在土地上仔细寻找。\n", me);
        if(objectp(huo)){
                message_vision("$N对着$n大喝一声：你鬼鬼祟祟的在干什么？\n", huo, me);
                huo->kill_ob(me);
        } else if(query("jade")){
                obj = new(__DIR__"obj/white_jade");
                if(objectp(obj)){
                        obj->move(me);
                }
                message_vision("$N从地上捡起一块白色的玉石。\n", me);
           delete("jade");
        } else {
                tell_object(me, "你什么都没有发现。\n");
        }
        return 1;
} 
void reset(){
        ::reset();
        if(!query("jade")) {
                set("jade", 1);
        }
}  
