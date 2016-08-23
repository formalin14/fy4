#include <ansi.h> 
 inherit ITEM;
void create()
{
        set_name(HIG"忘忧山庄请帖"NOR, ({ "qingtie"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("no_write",1);
                set("long", HIG"一张空白的忘忧山庄请帖，还没有写上客人的名字。\n"NOR);
                set("value", 0);
        }
        ::init_item();
} 

void init() {
          object me;
          me=this_player();
        if((string)me->query("id") == "xiaolang"){
        			add_action("do_write","write"); 
        		             	}
        add_action("do_read", "read");
} 

int do_write(string arg)
{
        object obj,tarobj;
        string sheet, target; 
     if (this_object()->query("no_write")){
        if( !arg || sscanf(arg, "%s", target)!=1 )
                return notify_fail("你要在请帖上写(write)上谁的名字(id)？ \n");
        tarobj = present(target, environment(this_player()));
        if( !tarobj) tarobj = find_living(target);
        if( !tarobj ) {
           message_vision("$N提笔把" + target + "写在$n上面。\n", this_player(), this_object());
           this_object()->set("no_write",0);
           this_object()->set("long",
                HIG"这是一张"NOR + this_object()->name() + HIG"，上面写着＂"NOR + target + HIG"亲启”几个字。\n"NOR);
        }
        else {
           message_vision("$N提笔把" + tarobj->name() + "写在$n上面。\n", this_player(), this_object());
           this_object()->set("targetname",tarobj->name());
           this_object()->set("targetgender",tarobj->query("gender"));
           this_object()->set("long",
                HIG"这是一张"NOR + this_object()->name() + HIG"，上面写着＂"NOR + tarobj->name() + HIG"亲启＂几个字。\n"NOR);
           this_object()->set("targetid", target);
           tarobj->set_temp("忘忧山庄/有请帖", 1);
           this_object()->set("no_write",0);
        }
                           }
     else return notify_fail("你已经写上客人的名字了。 \n");
        return 1;
}   

int do_read(string arg) {
        object me;
        
        me = this_player();
        if (!arg || (arg != "qingtie" && arg != "请帖")) {
                return 0;
        }
        if(me->query_temp("忘忧山庄/有请帖")||(string)me->query("id") == "xiaolang"){
          tell_object(me, HIG"\n忘忧山庄庄主萧十一郎诚邀阁下到山庄游玩。\n"NOR);
          tell_object(me, HIG"从天机广场向北行至十里，转东再走一里，然后复向北行三里路转东便是敝庄。\n谨祝旅途安全。\n---忘忧山庄萧十一郎拜上。\n"NOR);
          me->set_temp("忘忧山庄/请帖", 1); 
                                               }
        else return notify_fail(HIW"你不是请帖主人，偷看别人的请帖不是大侠所为。 \n"NOR);   
          return 1;
}    