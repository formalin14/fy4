 // explorer.c
inherit NPC; 
void create()
{
        set_name("探险者", ({"explorer"}) );
        set("gender", "男性" );
        set("age", 36);
        set("agi",30);
        set("per", 10);
        set("str",40);
        set("long",
                "一个疯狂的冒险家，他不信“自古华山一条路”这句话，
他相信自己一定能找出第二条路。\n"
                );
        set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500);
        set("eff_gin", 500);
        set("eff_kee", 500);
        set("eff_sen", 500);
        set("gin", 500);
        set("kee", 500);
        set("sen", 500);
        set("combat_exp", 50000);
        set_skill("move", 50);
        set_skill("parry", 50);
            set_skill("dodge", 60);
        set_skill("unarmed",50);
            setup();
            carry_object(__DIR__"obj/shoe")->wear();
            carry_object("/obj/armor/cloth")->wear();  
} 
