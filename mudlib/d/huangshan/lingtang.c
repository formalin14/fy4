 // mimicat@fy4
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "禅房");
    set("long", @LONG
这是一个素雅的长生堂，纪念一代风云人物【飞扬】。【飞扬】生前很热
爱风云，除了当过深圳风云三的巫师外，还为这里贡献良多。可惜天妒英才，
他不幸车祸去世，一众好友深感哀痛，于是在他生前喜爱的黄山松谷庵内，为
他建了一个长生堂，供奉了一个灵位（ｓｉｇｎ）。庵内的主持亦长年为这一
代人杰颂经，希望他在天之灵好好安息。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"yard",  
//                "north" : __DIR__"songgu",
        ]));
set("objects", ([
                __DIR__"npc/fywaiter" : 1, 
                        ]) );  
set("item_desc", ([
                "sign": @TEXT
                挚
                友

                飞             
                扬
立              
于              长
零              生
三              位
年
TEXT
        ]) );
        set("no_fight",1);
        set("no_magic",1);
        set("NONPC", 1);
    set("indoors", "huangshan");
        set("coor/x",-648);
    set("coor/y",-545);
        set("coor/z",30);
        setup();
      call_other( "/obj/board/common_hs", "???" );

} 
