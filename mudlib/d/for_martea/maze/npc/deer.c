#include <ansi.h>;
inherit NPC; 
void create()
{
        set_name("小鹿", ({ "little deer", "deer"}) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一头浅浅茸毛身上带着白色斑点的小鹿。\n");
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("max_gin", 1200);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 100);
        set("combat_exp", 100);
        set("self_go_msg",1);
        set("arrive_msg","蹦蹦跳跳地跑了过来");
        set("leave_msg","蹦蹦跳跳地跑走了");
        set("wimpy",99);
        setup();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        random_move();
}      
