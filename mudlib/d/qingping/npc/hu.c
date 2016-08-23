 // XXDER@FY3
inherit NPC;
void create()
{
        set_name("胡不愁" , ({ "buchou", "hu buchou", "hu" }) );
        set("long", "只见他头大身短，额角开阔，面上纵然未笑，也带着几分笑意。\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500); */
        set("age", 19);
        set("gender", "男性" );
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */
        create_family("清平山庄", 1, "弟子");
        set("combat_exp", 350000);
        set_skill("dodge", 50+random(50));
        set_skill("unarmed", 80);
        set_skill("sword", 65);
        set_skill("qingpingsword", 60);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 54);
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengzijue" :),
        }) ); 
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}   
