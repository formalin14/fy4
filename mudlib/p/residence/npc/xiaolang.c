 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("萧十一郎", ({ "xiaolang"}) );
        set("gender", "男性" );
        set("age", 25);
        set("per", 50);
        set("attitude", "peaceful");
        set("class","quest_npc");
        set("max_atman", 50000);
        set("atman", 50000);
        set("max_force", 50000);
        set("max_kee",999999);
        set("max_sen",999999);
        set("max_gin",999999);
        set("kee",999999);
        set("gin",999999);
        set("sen",999999);
        set("force", 5000);
        set("max_mana", 30000);
        set("force_factor",500);
        set("mana", 30000);
        set("no_busy",99);
        set("resistance/kee",90);
    	set("resistance/sen",90);
    	set("resistance/gin",90);
    
        set("long",     "他全身穿着一身休闲装，看上去懒懒散散，好像是突然被老婆\n从被窝里拉了出来，还没有睡醒一样。他永远是那样无所谓的样子。\n");
        set("combat_exp", 999999999);
    	set("title", WHT"此情可待成追忆"NOR);
    	set("nickname",HIR"我是NPC，不信你杀我看看"NOR);
        set_skill("blade", 1000);
        set_skill("unarmed",1000);
        set_skill("dodge", 1000);
        set_skill("force", 1000);
        set_skill("doomforce", 500);
        set_skill("parry",1000);
        set_skill("move",1000);
        set_skill("moon-blade",500);
        set_skill("sky-steps",1000);
        set_skill("perception",1000);
        map_skill("move","sky-steps");
        map_skill("dodge","sky-steps");
        map_skill("parry","moon-blade");
        map_skill("blade","moon-blade");
        map_skill("force","doomforce");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
		(:perform_action,"blade.yueshen-feidao":),
        }) );
        setup();
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}
void die(){
         message_vision("$N冷笑了一声：想杀我？门儿都没有！。\n", this_object());
        "/cmds/imm/full"->main(this_object(),"");

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
        switch(random(3)){
        case 0:
		message_vision("$N凝视着远方，若有所思......\n",this_object());
		break;
	case 1:
		message_vision("$N对叹气道：“最近也该去哪里打家劫舍了，要不身子骨都散了。”\n",this_object());
		break;
	case 2:
		message_vision("$N懒洋洋地道：还没有睡够呢......，又被叫起来了......\n",this_object());
		break;
	}
}  
