#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{ 
        set_name("青竹蛇",({"qingzhu she","qingzhu","she"}));
        set("title",WHT"江湖五毒"NOR);
        set("long", "江湖五毒之首，原是武当的护教长老，因贪恋女色被石雁重责后赶出，从
此变本加厉，勾结一批臭味相投之采花贼，足迹遍布中原。\n");
        set("age",59);
        set("gender","男性");
        set("combat_exp", 7000000);
         set("attitude", "aggressive");
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("literate", 100);
        set_skill("dodge", 200);
        set_skill("spring-sword", 450);
        map_skill("sword", "spring-sword");
        map_skill("parry", "spring-sword");
        set("reward_npc", 1);
        set("difficulty", 5);
        set("free_rain/ending", 1);
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
   set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                             (: perform_action, "sword.luohualiushui" :),
        }) );
         
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
        setup();
        carry_object("/d/fy/npc/obj/killersword1")->wield();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/biancheng/npc/obj/paper_3");
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        object another;
        message("vision",name() + "诡异地一笑，又成了那个裹着油围裙招待客人的丁老四。\n", 
                environment(),this_object() );
        another = new(__DIR__"bossding");
        another->move(environment(this_object()));
        destruct(this_object());
}  
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if(me->query("wanma/棺材之谜"))
                        me->set_temp("wanma/江湖五毒d",1);
        ::die();
} 
