#include <ansi.h> 
 inherit ITEM;
void create()
{
        set_name(RED"纸条"NOR, ({ "note", "纸条"}) );
        set_weight(1);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张红色见方的纸条。
纸条上面似乎有些重要的提示，你可以仔细阅读(read)一下。\n");
                set("value", 0);
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
        }
        ::init_item();
} 
void init() {
        add_action("do_read", "read");
} 
int do_read(string arg) {
        object me;
        
        me = this_player();
        if (!arg || (arg != "note" && arg != "纸条")) {
                return 0;
        }
        else
        {
           message_vision("$N拿着纸条仔细察看。\n" ,this_player());
           tell_object(me, "只见纸条上写着：恭喜你将获得圣诞大礼，你去问问(whisper)圣诞老人(tianji)\n关于你礼物(gift)的具体领取办法吧。\n");
           me->set("圣诞礼物/gift", 1); 
         }
         return 1;
}    
