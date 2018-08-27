  // butcher.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR; 
int tell_him();
void create()
{
        set_name("大胡子", ({ "butcher", "da" }) );
        set("title", "屠记肉铺");
        set("gender", "男性" );
        set("age", 35);
        set("long", "一个满脸大胡子，和横肉的家伙。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 25000);
                set("chat_chance", 1);
        set("chat_msg", ({
                "大胡子叹了口气：莫非我的方法有错？刀怎麽磨都老是用坏．．．\n",
        }) ); 
                set("inquiry", ([
                "方法" : (: tell_him :),
                "磨刀" : (: tell_him:),
                "磨刀石" : (: tell_him:),
                "庖丁解牛图册" : (: tell_him:),
        ])); 

        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set("vendor_goods", ([
                __DIR__"obj/yangtou": 22,
                __DIR__"obj/zhutou" : 22,
                __DIR__"obj/niutou" : 22,
        ]) ); 
        setup();
        add_money("coin", 2);
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
        add_action("do_spare","spare");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 2:
                        say( "大胡子咧开大嘴, 笑着道：这位"  
                                + RANK_D->query_respect(ob)
                                + "，要买肉是吗? \n");
                        break;
        }
} 
 
int do_spare(string arg)
{
        object me;
        object obj;
        string file;
        me = this_player();
        if(!arg) return notify_fail("指令：spare <name>\n");
                if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有"+arg+"。\n");
        if(base_name(obj) == "/obj/npc/pet" && obj->query("owner") == me->query("id")
        && obj->query("possessed") == me)
        {
        message_vision("$N对大胡子说：＂帮我处理掉$n，我自己不忍动手！＂\n",me,obj);
        message_vision("$N伸手一抄，＂喀碴＂一声扭断了$n的脖子！\n",this_object(),obj);
        seteuid(ROOT_UID);
        file = obj->query_save_file()+".o";
        obj->die();     
        rm(file);
        seteuid(getuid());
        return 1;
        }       
        return notify_fail("你不可以这么做！\n");
} 
void reset(){ 
    set("vendor_goods", ([
            __DIR__"obj/yangtou": 22,
            __DIR__"obj/zhutou" : 10,
            __DIR__"obj/niutou" : 10,
    ]) );       
}   
int tell_him()
{
    object me;
    me =this_player();
        
    tell_object(me,"大胡子道：邵大师给了块宝石我磨刀，可是刀还是坏。如果有庖丁的屠宰方法就好了！\n");
               
    return 1;
} 

int accept_object(object me, object obj)
{
        object iron;
        if( (string) obj->query("name") == "庖丁解牛图册")
        {
                obj = new(__DIR__"obj/giron");
                message_vision(NOR"\n$N一把拿起图册狂翻了几遍，激动地握着$n的手说不出话来。\n"+CYN"$N说道：有了这麽方便的屠宰方法，邵大师给我的这磨刀的石头我就不要了。\n" + NOR"$N随手把案上的"+obj->name() + NOR"扔到地上，津津有味地研究起图册来。\n"+"$n趁$N不留神，马上捡起地上的"+obj->name()+NOR"塞入怀中。\n\n"NOR, 
                            this_object(),this_player() );

                        iron = new(__DIR__"obj/giron");
                        if(iron) iron->move(this_player());
                        
                        
           return 1;       
        }
        else {return notify_fail("大胡子古古怪怪地瞄了一眼，转过身去继续干活。\n");}
            
        return 1;
} 
