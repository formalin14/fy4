 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"灭","空","孟","去","可","心","明","吝","迩","奇","足","位"});
        set_name("圆"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("class","shaolin");
        set("age",random(20)+ 32);
        create_family("少林寺", 22, "弟子");
        set("long", "这是少林寺的和尚\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", random(100000)+100000);
        set("attitude", "friendly");
        set("cps",80);
        set("force",500);
        set("max_force",500);
        set("force_factor",15);
        
        set_skill("blade", 60+random(100));
        set_skill("dodge", 60+random(60));
        set_skill("puti-steps",60);
        set_skill("dabei-strike",60);
        set_skill("lianxin-blade",random(100)+50);
        set_skill("move",80);
        set_skill("force",200);
        map_skill("unarmed","dabei-strike");
        map_skill("dodge","puti-steps");        
        map_skill("blade", "lianxin-blade");
        
/*      set("chat_chance", 2);
        set("chat_msg", ({
                name()+"说道：听说昨天又有人从木人巷打下山去了！\n",
        }) );*/
        
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
//         name()+"笑道：在少林寺大门前撒野！\n",
                (: perform_action, "blade.yipianlianxin-npc" :),
        }) );
        setup();
        carry_object(__DIR__"obj/monk22_cloth")->wear();
        carry_object(__DIR__"obj/jiblade")->wield();
} 
int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 50000 ) {
                        say( name()+"掂了掂手中的"+ob->name()+"，笑道：啊？？．．哈哈哈．．\n");
                        say( name()+"顺手将"+ob->name()+"揣入了怀中。\n");
                        who->set_temp("shaolin", 1);
                        return 1;
                } else {
                        command("shake");
                        return 0;
                }
        return 0;
}      
