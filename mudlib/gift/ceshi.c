#include <ansi.h>
inherit "/std/char/missionnpc.c";
void create()
{
        set_name("��Ҫ�����Ĳ�������", ({ "ceshi", "ce shi" }) );
        set("long",
                "һȺ�����ƻ������ɻ���\n");
        set("cor",20);
        set("max_kee",99999);
        set("max_sen",99999);
        set("max_gin",99999);
        set("combat_exp", 1000000000);
        set_skill("unarmed", 1000);
        set_skill("spear", 1000);
        set_skill("parry", 1000 );
        set_skill("dodge", 1000);
        set_skill("move",1000 ); 
        set_skill("strategy",500);
        set_skill("jin-gang",300);
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", 30+random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
        }) ); 
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/spear")->wield();
}      
