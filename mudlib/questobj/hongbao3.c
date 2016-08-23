#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "新春红包" NOR, ({ "hong bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个小小的红包，上面绣着：恭喜发财。\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, me,ob;
        int max_gin,max_kee,max_sen;
        int n;
        string msg;
        msg = "";
        me = this_player();
        max_gin = (int) me->query("max_gin");
        max_kee = (int) me->query("max_kee");
        max_sen = (int) me->query("max_sen");
        if(arg != "hong bao" && arg != "新春红包") return 0;
        if(me->query("marks/open_hongbao"))
        	return notify_fail("你已经领过红包了！\n");
        if(query("opened"))
                return notify_fail("你打开小红包，但里面是空的！\n");
                
        if (me->query("combat_exp")>3000000) n=24;
                else if (me->query("combat_exp")>2500000) n=25;
                        else n=26;
        max_gin = max_gin * n/20;
        max_kee = max_kee * n/20;
        max_sen = max_sen * n/20;
        me->set("max_gin", max_gin);
        me->set("max_kee", max_kee);
        me->set("max_sen", max_sen); 
        if( me->query("age") >= 12 && me->query("combat_exp")>= 400000 ){        
        	gold = new("/obj/money/gold");
        	gold->set_amount(200);
        	gold->set("name","压岁钱");
        	gold->set("base_unit","张");
        	gold->move(this_player());
        	msg="还得到了二百两金子的压岁钱。";
        }
        
        me->add("combat_exp",20000);
        me->add("potential",20000);
        message_vision(HIR "\n$N悄悄打开红包，两眼发光，一阵窃喜！\n\n" NOR,me);
        tell_object(me,HIC"\n恭喜恭喜！你被奖励了：\n" + chinese_number(20000) + "点实战经验\n" + chinese_number(20000) + "点潜能。"+msg+"\n" NOR);
        message_vision(HIR"只见$N全身上下泛出红光，好像有股神奇的力量注入$N体内。\n"NOR,me);
        me->set("marks/open_hongbao",1);
        set("opened",1);
        return 1;
}
