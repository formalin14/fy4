inherit QUESTNPC;
//inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("吕迪", ({ "master lv", "master"}) );
        set("nickname", HIR "权法天王"NOR);
        set("gender", "男性" );
        set("age", 31);
        set("per", 30);
        set("npc_difficulty",8);
        set("organization/性质","邪");
        set("agi",25);
        set("int",30);
        set("cor",40);
        set("combat_exp",80000000);
        set("max_kee",200000);
        set("max_gin",100000);
        set("max_sen",100000);
        set("max_force", 8000);
        set("force", 8000);
        set("force_factor", 120);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("long",
"
没有人的脸上会发出这种青光的，除非他脸上戴着个青铜面具。
这人的脸上就戴着青铜面具，在星光下看来，显得更狰狞而怪异。
他身上穿着的，却是件美丽的绣花长袍，腰带上斜插着三柄弯刀。
惨碧色的刀鞘上，缀满了明珠美玉。 
\n"
        );
        create_family("西方神教", 2, "天主"); 
        set("score", 20000);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: exert_function, "mihun" :)
        }) );
        set_skill("move", 400);
        set_skill("blade",400);
        set_skill("parry",400);
        set_skill("dodge", 400);
        set_skill("force", 200);
        set_skill("literate", 90);
        set_skill("unarmed",220);
        set_skill("demon-steps",300);
        set_skill("demon-blade",300);
        //set_skill("wenhou-claw",150);
        set_skill("demon-force",220);
        set_skill("iron-cloth",200);
        set_skill("jin-gang",180);
        map_skill("dodge", "demon-steps");
        map_skill("parry", "demon-blade");
        map_skill("move",  "demon-steps");
        map_skill("force", "demon-force");
        map_skill("blade", "demon-blade");
        map_skill("iron-cloth","jin-gang"); 
        setup();
        carry_object(__DIR__"obj/xiuhuacloth")->wear();
        carry_object(__DIR__"obj/duomianju")->wear();
        carry_object(__DIR__"obj/duoblade")->wield();
} 
int accept_fight(object me)
{
	command("heng");
        command("say 不知死活的家伙出招吧！");
        return 1;
}