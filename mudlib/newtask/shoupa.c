#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void create()
{
    set_name(MAG"五罗轻烟帕"NOR, ({ "handkerchief" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "cloth");
                set("long", "一块约莫四尺见方的白缎手帕，四角上都绣著一朵红花。花红欲滴，每朵\n花旁都衬著一张翠绿色的叶子，迎着微风，不住地抖动（shaking）。\n");
                }
     setup();
} 
void init()
{
        if(this_player()==environment())
        add_action("do_shake","shaking");
} 
int do_shake(string arg)
{
        object ob;
        object me; 
        if (!arg) 
                return notify_fail("你想迷倒谁？\n"); 
        if (query("used")) 
                return notify_fail(this_object()->name()+"只能用一次。\n");
        me=this_player();
        if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells") 
        )
                return notify_fail("在这不可偷袭！\n");
        ob=present(arg,environment(me));
        if (!objectp(ob) || !living(ob)) 
                return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
        if (!me->is_fighting(ob)) 
    message_vision(GRN"\n$N右手轻轻一杨，朝$n抖了抖手中的"+this_object()->name()+GRN"，一丝若有若无的幽香拂面而过...\n"NOR,me,ob);
   if ((int)me->query_cps() > random ((int)ob->query_cps()))
        {
        message_vision(MAG "\n\n$N只觉得眼前五彩斑斓，身子微颤，转了几个圈子，倒在地上...\n"NOR,ob);
                ob->unconcious();
        }
        else
        {
        message_vision(CYN"\n\n$N急忙以手遮鼻，摒住呼吸，不去闻那香气...\n"NOR,ob);
        message_vision(HIR"\n$N对着$n大喝一声：下流的东西，不知羞耻...\n"NOR,ob,me);
                ob->kill_ob(me);
        }
        set("used",1);
        me->start_busy(3);
        return 1;
}   
