#include <ansi.h>
inherit NPC;
void create()
{
    set_name("小黄雀", ({ "yellow bird", "bird" }) );
    set("race", "野兽");
    set("age", 1);
    set("gender", "雄性");
    set("long", "这是一只小黄雀，美丽的羽毛闪耀着黄色的光泽。\n");
    set("attitude","peaceful");
    set("limbs", ({ "头部", "身体","尾巴" }) );
    set("verbs", ({ "bite","claw" }) );
        set("arrive_msg","飞了过来。\n");
        set("leave_msg","飞开了。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            (: random_move :),
            "咭咭。\n",
            "喳喳。\n",
                "小黄雀低头在地上哚了几下。\n",
        }));
        set_temp("apply/dodge", random(200));
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 5);
        set("weight", 200);
    setup();
}         
