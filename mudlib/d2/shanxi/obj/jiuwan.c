#include <ansi.h>
inherit ITEM; 
//void apply(string confirm, object me);
void create()
{
    set_name(HIW "酒碗" NOR,({"wan"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "壶");
                set("lore",1);
                set("material", "wood");
                set("long", "碗虽不精美，但碗内却是真正的泸州大曲。\n");
                }
} 
void init()
{
        if(this_player()==environment())
        add_action("do_drink","drink");
        add_action("do_throw", "throw");
} 
int do_drink(string arg)
{
        object me, obj;
        me = this_player();
        if (!arg)
                return notify_fail("你要喝什么？\n");
        if (arg != "wan")
                return notify_fail("你要喝什么？\n");
        if (query("used")) 
                return notify_fail(this_object()->name()+"已经被喝光了。\n");  
        message_vision("$N似乎连站都站不稳了，垂死之时忽然伸手从身上摸出那碗酒。\n",me);
        message_vision("$N一口气喝了下去，本来已变成死灰的一张脸，立刻又有了生气。\n",me);
        message_vision("眼尖的$N发现碗底还有个字。\n",me);
        this_object()->set("long","喝干了的酒碗，碗底居然写了一个“摔”字(throw)。\n");
        me->clear_condition();
        me->start_busy(3);
        set("used",1);   //你刚才这里少了分号
        return 1;
}
int do_throw(string arg)
{
	if(!arg || arg != "wan" || arg != "酒碗" ) return notify_fail("你要摔什么？\n");  //add by xiaolang
	message_vision("$N用力把手中的酒碗摔了出去，「啪」的一声，酒碗破成碎片.....\n",this_player());   //add by xiaolang
        destruct(this_object());
          return 1;
} 
// add by xiaolang
/*int do_look(string arg)
{
	object me;
	me = this_player();
	if(query("used")
	*/