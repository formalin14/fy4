#include <ansi.h>
#include <command.h> 
inherit "/d/taiping/npc/smart_npc"; 
void create()
{ 
        set_name("蓝衣大汉",({"blue cloth man","man"}));
        set("title",WHT"七海山庄"NOR);
        set("long", "七海龙王从各地聘来的高手，身穿蓝衣，手持钢刀。\n");
        set("age",40);
        set("combat_exp", 4500000);
                
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100);
        set("group","qihai");
        
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",10);
        set("resistance/kee",10);
        set("resistance/sen",10);
        
                
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("nb_chat_chance", 100);
           set("nb_chat_msg_combat", ([
                1: name()+"喝道：“再不滚，坏了龙王的兴致，你想走也走不了了！”\n", 
        ]) );  
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "蓝衣大汉百无聊赖地拿刀削着船舷上的一块木头。\n",
                "蓝衣大汉说：“龙王在里面又吃又喝，咱们却在外头干耗着，不爽！”\n",
                "蓝衣大汉侧耳听了听船舱里的动静，暧昧地笑了起来。\n",
                "蓝衣大汉摸了摸肚子嘀咕着，“怎么还没换班，老子嘴里都淡出个鸟来了。”\n",
        }) ); 
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
                
        auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","shenji-blade",2); 
        setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
}  
int accept_object(object who, object ob)
{
        if (ob->query("food_supply")) {
        if (ob->query("food_remaining")) {
                if (ob->query("value")>=2000) {
                        message_vision(CYN"
$N舔了舔嘴唇说：“挺乖巧的，就让你进去转转吧，不要打扰了龙王，否则没好果子吃！”\n"NOR,this_object());
                        who->set_temp("taiping/boat_enter",1);
                        return 1;
                } else 
                        message_vision(CYN"
$N不屑地看了"+ob->name()+"一眼说：“什么乱七八糟的玩意儿！”\n"NOR,this_object());
        } else 
                message_vision(CYN"$N大怒：“你小子想诳大爷！”\n"NOR,this_object());   
        }
        
        return 0;
}       
