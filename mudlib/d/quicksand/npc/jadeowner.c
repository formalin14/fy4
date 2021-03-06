 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("珠宝商", ({ "jade seller", "seller" }) );
        set("gender", "男性" );
        set("age", 49);
        set("long", "这是一位饱经风霜的店掌柜\n");
        set("combat_exp", 700000);
        set("str", 300);
        set("attitude", "friendly");
        set_skill("blade", 130);
        set_skill("shortsong-blade", 100);
        set_skill("fall-steps", 130);
        set_skill("dodge", 100);
        set_skill("parry", 120);
        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");
        set("vendor_goods", ([
                __DIR__"obj/jade1":12,
                __DIR__"obj/jade2":12,
                __DIR__"obj/jade3":12,
                __DIR__"obj/jade4":12,
                __DIR__"obj/jademonk":12,
                __DIR__"obj/snake_drug":12,
                __DIR__"obj/amber1":3,
        ]) ); 
        setup();
        add_money("silver", 1);
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/jadeblade")->wield();
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
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买玉挡灾吗？ \n");
                        break;
                case 1:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉是吉祥之物，大漠无情，还是买一块挡灾吧。 \n");
                        break; 
        }
}  
void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/jade1":12,
                __DIR__"obj/jade2":12,
                __DIR__"obj/jade3":12,
                __DIR__"obj/jade4":12,
                __DIR__"obj/jademonk":12,
                __DIR__"obj/snake_drug":12,
                __DIR__"obj/amber1":3,
        ]) );
} 
