#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
    set_name("萧别离",({"xiao bieli","xiao","bieli"}));
    set("title","服装很华丽、修饰很整洁的中年人");
    set("long","他两鬓斑白，脸上每一条皱纹中，都不知隐藏着多少欢乐，多少痛苦，多少秘密，
但一双手却仍柔细如少女。他穿着很华丽，华丽得甚至已接近奢侈。\n");
        set("gender","男性");
        set("age",52);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N满眼泪水地看了一眼屋子里的家具。。。。 \n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );    */
        set("chat_chance",1);
        set("chat_msg",({
                "萧别离正在将骨牌一张张慢慢地摆在桌上，摆成了个八卦。\n"
        }) );                   
        
/*           CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
*/        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}       
