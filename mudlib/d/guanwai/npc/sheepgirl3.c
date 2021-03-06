 // worker.c
inherit NPC; 
void create()
{
        set_name("牧羊女", ({ "sheep girl", "girl" }) );
        set("gender", "女性" );
        set("age", 17);
        set("long", "一个天真活泼，美丽大方的少女。 \n");
        set("combat_exp", 7000);
        set("per", 30);
        set("attitude", "friendly");
        set_skill("whip", 10);
        set_skill("parry", 25);
        set_skill("dodge", 100);
        set_skill("snowwhip", 10);
        map_skill("whip", "snowwhip");
        map_skill("parry", "snowwhip"); 
        setup();
        add_money("coin", 5);
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/whip")->wield();
}    
