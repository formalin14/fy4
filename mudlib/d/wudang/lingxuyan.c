 inherit ROOM;
void create()
{
        set("short", "凌虚岩");
        set("long", @LONG
凌虚岩清丽幽深，与世隔绝。相传唐代陈抟曾隐居于此。他致力
于内功的研究，练就了著名的睡功：五龙睡法。传说他一睡可百天不
醒。至今南岩宫墙壁上还有陈抟亲手所书横卧着的“福寿”二字。人
称“卧福睡寿”。
     这儿有几个持剑的小童正在操练着武当的“四象阵“，四人同进
同退，攻守皆宜。
LONG
        );
        set("exits", ([
                "east" : __DIR__"wudang1",
        ]));
        set("outdoors", "wudang");
                set("objects", ([
                __DIR__"npc/swordboy1" : 1,
                __DIR__"npc/swordboy2" : 1,
                __DIR__"npc/swordboy3" : 1,
                __DIR__"npc/swordboy4" : 1,
        ]));
        set("coor/x",90);
        set("coor/y",-140);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}       
