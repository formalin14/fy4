#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
        set_name(HIC"唤雨梧桐"NOR, ({ "phoenix tree", "tree" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","青色的树干掂起来轻飘飘的。也许可以造（ｍａｋｅ）些东西．\n");               set("unit", "捆");
                set("base_unit", "根");
                set("base_weight", 10000);
                set("base_value", 10);
        }
        set_amount(1);
    ::init_item();
}
void init(){
    if(this_player()==environment()) {
        add_action("do_make","make");
    }
} 
int do_make(){
        object woodcage, me, ptree, mtree, pvine; 
        me = this_player();
    if(me->query("str") < 16)
        return notify_fail("你年小体弱，无法造出锁麟笼。\n");
        if( objectp(ptree = present("plum tree", me)) 
                        && objectp(mtree = present("maple tree", me)) 
                        && objectp(pvine = present("purple vine", me))){
                if((int)me->query_encumbrance() + 150000 > (int)me->query_max_encumbrance())
                return notify_fail("你的负重太大，无法造出锁麟笼。\n");
                seteuid(getuid());
                woodcage = new(__DIR__"woodcage");
                if(objectp(woodcage)) {
                        woodcage->move(me);
                        message_vision("$N用灵巧的双手造出了个锁麟笼。\n", me);
                }
                if(!me->query("m_success/锁麟笼")){
            me->set("m_success/锁麟笼",1);
            me->add("score",300);
           me->add("potential", 2000);
                me->add("combat_exp", 2000);
        }
        destruct(ptree);
        destruct(mtree);
        destruct(pvine);
        destruct(this_object());
        } else {
                return notify_fail("缺少制造锁麟笼的材料。\n");
        }
        return 1;
}    
