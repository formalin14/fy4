#include <ansi.h>
inherit NPC;
void create()
{
        set_name("竹叶青", ({ "zhuyeqing" }) );
        set("gender", "男性");
        set("combat_exp", 1000000);
        set("age",47);
        set("env/wimpy",90);
        set("long",
                "竹叶青是一种烈酒的名字，喝下去很少有人能不醉的；竹叶青也是种毒蛇，毒得要命。\n"
        );
        set_skill("move",100);
        set_skill("dodge", 50);
        set_skill("unarmed",100);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}    
