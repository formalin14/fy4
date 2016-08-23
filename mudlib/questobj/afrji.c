#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL "阿发日记" NOR, ({ "afrji" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("long", "一本阿发以前的日记，你可以读一读（ｒｅａｄ）。\n");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

        } 
        ::init_item();
}  
void owner_is_killed(object killer)
{
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);
}
void init()
{
        if(environment(this_object())==this_player())
                add_action("do_read","read");
        add_action("do_go","go");
} 
int do_read(string arg)
{
        object me;
        mapping exits;
        string *dirs;
        string thisdir;
        if(arg != "afrji" && arg != "阿发日记") return 0;
        me=this_player();
        
        if(find_call_out("markit")== -1)
                call_out("markit",random(60)+20,me);
        if( !mapp(exits = environment(me)->query("exits")) )    {
                tell_object(me,"有一批宝藏就在附近！\n");
                return 1;
        }
        dirs = keys(exits);
        thisdir = dirs[random(sizeof(dirs))];
        set("thisdir",thisdir);
        if (!query("already")) tell_object(me,"有一批宝藏就在"+thisdir+"的方向！你可以用 go "+thisdir+" 来寻找它。\n");
           else tell_object(me,"日记上记载着一批宝藏的位置，不过前几天这批宝藏就被人挖走了。\n");
        return 1;
} 
int do_go(string arg)
{
        if(arg==query("thisdir"))
                this_player()->add_temp("going",1);
        return 0;
}  
int markit(object me)
{
        object gold;
        if(me->query_temp("going") <= 20 || environment()!=me) return 1;
        if(!query("already"))           {
                gold = new("/obj/money/gold");
                tell_object(me, YEL"\n\n你一弯腰，从『阿发日记』所指示的地方挖出些金子！\n"NOR);
                if (me->query("combat_exp")>300000)
                if (!me->query("m_success/阿发日记")) {
                        tell_object(me,HIY"你简直不敢相信自己的眼睛，这是一个大宝藏！！！\n");
                        tell_object(me,HIY"你的银行储蓄增加了200两金子！！！\n"NOR);
                        me->set("m_success/阿发日记",1);
                        me->add("deposit",2000000);
                }
                gold->set_amount(1+random(50));
                gold->move(me);
                me->delete_temp("going");
                set("already",1);
        }
        return 1;
}        
