 inherit ROOM;
void create()
{
        set("short", "隧道北");
        set("long", @long
隧道内漆黑一片，但乾爽宁静。虽然横七竖八摆了很多东西，不过依然显
得很宽敞。地上还有一些湿漉漉的脚印，显然经常有人来往。偶然身边闪过一
个身影，也不觉得惶恐。人们似乎对地上的宝物并不贪婪，只取去自己所需，
便悄悄离开。
long
        );
        set("exits", ([ /* sizeof() == 4 */
"out" : "/d/fy/ngatedown",
  "enter" : __DIR__"nnewbie2",
  
]));
        set("objects", ([
                __DIR__"obj/gui1" : 1,
                "/obj/newbie/sword2" :1,
"/obj/newbie/windsword" : 1,
"/obj/newbie/zheshan" : 1,
"/obj/newbie/toysword" :1,
 "/d/shaolin/npc/obj/axe" :1,
 "/obj/newbie/xiesword" : 1,

/*/obj/newbie/s_spear
/obj/newbie/g_spear
/obj/newbie/sword_katana
/obj/newbie/rockhammer
/obj/newbie/juque
/obj/newbie/wolf_hammer
/obj/newbie/guzi
/obj/newbie/bamboo_staff
/obj/newbie/dafeng*/
                
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",0);
        set("coor/y",50);
        set("coor/z",-10);
        
        setup();
}
