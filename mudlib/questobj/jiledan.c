#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"极乐丹"NOR, ({ "jiledan" }) );
//    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "丸");
            set("base_unit", "丸");
            set("base_weight", 1);
            set("material", "stone");
            set("long", "一丸极乐丹，你可以把它倒(pour)在酒水之中使用。\n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

          } 
        set_amount(1);
//    ::init_item();
}
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
        
}
   
void init()
{
        add_action("do_pour", "pour");
} 
int do_pour(string arg)
{
        string me, what;
        object ob;
        function f; 
        if( !arg
        ||      sscanf(arg, "%s in %s", me, what)!=2
        ||      !id(me) )
                return notify_fail("指令格式: pour <药粉> in <物品>\n"); 
        ob = present(what, this_player());
        if( !ob )
                return notify_fail("你身上没有 " + what + " 这样东西。\n");
        if( !ob->query("liquid/remaining") )
                return notify_fail(ob->name() + "里什麽也没有，先装些水酒才能溶化药粉。\n");
        f = (: call_other, __FILE__, "drink_drug" :);
        ob->set("liquid/drink_func", bind(f, ob));
        ob->add("liquid/slumber_effect", 100);
        message_vision("$N将一些" + name() + "倒进" + ob->name() 
                + "，摇晃了几下。\n", this_player());
   add_amount(-1);
        return 1;
} 
int drink_drug(object ob)
{
        this_player()->apply_condition("slumber_drug",
                (int)this_player()->query_condition("slumber_drug") 
                + (int)ob->query("liquid/slumber_effect") );
        return 0;
}         
