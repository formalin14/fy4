#include <room.h>
inherit ROOM;
void cloth_path();
void create()
{
        set("short", "地下石屋");
        set("long", @LONG
这石阶之下，虽是在地底却别有天地，一进这里如入幻境，一眼望去，只觉得
神奇精巧，不可言喻。这里按风、雪、雷、电、火、水、雨、冰分做八间房屋，正正
中央还有一个凹下去的石板。半依天然，半倚人工。人工固然精巧，而天工之妙成却
更难求。
LONG
        );
        set("objects", ([
       ]) );
       
        set("exits/water",__DIR__"swordroom");
        set("exits/snow",__DIR__"bladeroom");
        set("exits/rain",__DIR__"staffroom");
        set("exits/lightning",__DIR__"axeroom");
        set("exits/wind",__DIR__"whiproom");
        set("exits/thunder",__DIR__"hammerroom");
        set("exits/ice",__DIR__"spearroom");
        set("exits/fire",__DIR__"daggerroom");
        set("exits/up",__DIR__"studyroom");
        set("item_desc", ([
                "石板": "这块石板似乎可以拉开(pull)。\n",
                "shiban": "这块石板似乎可以拉开(pull)。\n", 
        ]) );
        set("indoors", "fycycle");
        set("coor/x",-160);
        set("coor/y",50);
        set("coor/z",0);
        setup(); 
}                                    
void init()
{
        add_action("do_open", "pull");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "shiban" || arg == "石板")
        {
        me = this_player();
        message_vision("$N拉起凹下去的石板，发现下面又是一个石室。\n", me);
        if( !query("exits/star") ) {
        set("exits/star", __DIR__"throwingroom");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("你不可以打开"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/star") ) return;
        message("vision",
"石板又倒了回来，封住了夹缝。\n",
                this_object() );
                delete("exits/star");
} 