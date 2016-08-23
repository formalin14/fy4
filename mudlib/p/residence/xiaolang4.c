 inherit ROOM;
#include <ansi.h>
#include <room.h> 
void create()
{
        set("short", HIC"露天浴池"NOR);
        set("long", @LONG
你寻声而至，眼前情形让你惊讶不已：不知道哪里的温泉从小山坡上的泉眼中
喷涌而出，形成特有的小瀑布流入下面的浴池，据说这里的温泉有疗伤的奇效，
你真想跳（ｊｕｍｐ）进去享受享受。
LONG
        );
        set("exits", ([
                "east" : __DIR__"xiaolang_xiaodao4",
        ]));
        set("item_desc", ([
                "瀑布": "从泉眼中喷涌而出的温泉形成的小型瀑布，看上去非常壮观！\n",
                "浴池": "由于瀑布长期冲击形成的天然浴池，你忍不住想跳（jump)进去。\n",
        ]) );
          set("objects", ([
//              __DIR__"npc/xiaolangwa" : 1,
                     ]) );
        set("outdoors","residence");
        set("no_steal",1);
        //set("no_fight",1);
        set("coor/x",13);
        set("coor/y",2033);
        set("coor/z",30);
        set("resource/water", 1);
        set("liquid/container", "泉眼"); 
        setup();
} 
void init()
{
        add_action("do_jump", "jump");
        add_action("do_fly", "feizong"); 
} 
int do_jump()
{
        object me;
        int wait;
        me = this_player();
        wait=5;
        message_vision(HIG"$N脱掉了所有衣服，「扑通」一声跳入了露天浴池!\n"NOR,me);
        tell_object(me,HIG"温泉让你感到全身非常舒服......\n"NOR);
        remove_call_out("curehimup");
        call_out("curehimup",wait, me);
        return 1;
} 

void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
        {
        message_vision(HIG"温泉居然使$N的伤口慢慢愈合！！\n"NOR, me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        }
return;
}  

int do_fly()
{
        object obj;
        object me;

        me = this_player();
        message_vision("$N看看了高高的山坡，深吸一口真气，纵身飞跃上去。\n", me);
        me->move(__DIR__"xiaolang_shanfeng");
        message_vision(HIW"$N从山下飞跃了上来。\n"NOR, me);
        return 1;

}
