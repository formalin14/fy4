#include <ansi.h> 
 inherit ROOM;
void create()
{
        object          con, item; 
        set("short", "石屋");
        set("long", @long
房间虽属人工凿造，但石纹相连，设计布局合理，精雕细刻。
只是这间原本布置得清淡幽雅的屋子里，相当  乱，到处都似乎带
一点儿灰尘。房间中仅有一石桌，桌上放了两碗酒。
long
        );
        set("exits", ([ 
                //"west" : __DIR__"xzroad2",
                //"east" : __DIR__"xzh1k",
        ]));
        set("objects", ([
                __DIR__"obj/table": 1,
        ]));
        set("coor/x",110);
        set("coor/y",-50);
        set("coor/z",0);
        setup(); 
        con = present("table", this_object());
        if(con && item = new(__DIR__"obj/jiuwan")) item->move(con);

} 
void init()
{
	object ob;
//        ::init();
        add_action("do_throw", "throw");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",3, ob);
        }

}
void close_path()
{
        if( !query("exits/enter") ) return;
        message("vision",
        "门忽然被人关上。\n",
                this_object() );
                delete("exits/enter");
}  
int do_throw(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="wan" || arg =="酒碗" ) {   //删除arg == "jiuwan"
            if(!ob=present(arg,me) )         // add by xiaolang,检查player身上是否有酒碗,这里是：假如身上没有酒碗
            	return notify_fail("你身上没有酒碗。\n");
             write("你把酒碗往地上用力一扔。\n");
             write("石壁忽然开始移动，露出了一道暗门。\n");
             if( !query("exits/east") ) {
                set("exits/enter", __DIR__"alou4");
                call_out("close_path", 10);
                        }
              destruct(ob);    //add by xiaolang  如果有酒碗，那么摧毁他
                return 1;       
        }
                write("你要扔什么？\n");
                return 1;
} 
void punish_betray(object ob)
{
        message_vision( BLU"$N忽然惊觉这屋子里好像有  特别的香  ，但神智已经开始有点模糊。。。\n\n\n"NOR,ob);
        if(!ob->query_condition("green_blood"))
                ob->apply_condition("green_blood",random(10)+10); 
} 