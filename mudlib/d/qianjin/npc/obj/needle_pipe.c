#include <ansi.h>
#include <combat.h>
inherit ITEM;
void create()
{
        set_name(GRN"漆黑的铜管"NOR, ({ "needle pipe"}) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个小小的黑色圆筒。\n"
);
                set("material", "gold");
                
        } 
        ::init_item(); 
}
void init()
{
        add_action("do_shoot","shoot");
}
int do_shoot(string arg)
{
        object ob;
        object me;
        int dp;
        int damage;
        if (!arg) return notify_fail("你要打谁？\n");
    if (query("used")) return notify_fail(this_object()->name()+"只能用一次。\n");
        me=this_player();
    if ( me->query("combat_exp") < 50000 )
                return notify_fail("你经验太差了，没有办法掌握" + this_object()->name()+"的发射秘诀。\n");
    if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells"))
        return notify_fail("在这不可偷袭！\n");
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
    if(userp(me))
    message_vision("$N一张嘴，一丛黑色的细针从口中电射而出．．\n",me);
    if (ob->query_skill("perception")/10>random(15)) 
        message_vision("$N听风辨形，居然在间不容发之际躲过了这漫天针雨！\n",ob);
    else {
    message_vision("牛毛般的针雨打在$N身上。\n",ob);
    ob->receive_damage("kee", 0, me);
        dp = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
    damage=200000-dp;
    damage/=50;
    if (damage<0) damage=0;
    ob->receive_wound("kee",damage,me);    
    ob->receive_wound("gin",damage,me);    
    ob->receive_wound("sen",damage,me);    
    }
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
if (userp(me))
    set("used",1);
    me->start_busy(3);
    return 1;
}   
