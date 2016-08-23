 // Room: /d/wiz/courthouse.c
#include <ansi.h>
void test_me(object me);
inherit ROOM; 
void create()
{
        set("short", "监狱");
        set("long", @LONG
风云唯一的一个监狱，能到这里来的人一定都是令人头痛的角色。
但是一到这里，别人的头就不痛了，你的头应该开始痛了吧．．．
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jobroom"
])); 
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_spells", 1);
        set("coor/x",10);
        set("coor/y",0);
        set("coor/z",10);
        setup();
}
void init()
{
        if(!wizardp(this_player()))
        {
        "/cmds/std/look"->look_room(this_player(),this_object());
        this_player()->set("startroom", __FILE__);
        add_action("do_nothing", "");
        add_action("do_quit","quit");
        }
}        
int do_nothing()
{
write("监狱的生活真苦啊．．．．！\n");
return 1;
} 
int do_quit()
{
"/cmds/usr/quit"->main(this_player(),"");
return 1;
}    
