 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("蓑笠老翁", ({ "old man", "man"}) );
        set("title", HIB"沧海一粟"NOR);
        set("gender", "男性" );
    set("age", 244);
    set("per", 65);
        set("int",28);
        set("attitude","friendly");
        
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor",50); 
        set("long",
      HIW"一个蓑衣斗笠的白胡子老者，脸色红润，颏下银髯，童颜鹤发，当真便如图\n画中的神仙人物一般。正自盘膝闭目而坐，垂钓怒礁。\n"NOR
        );
        set("chat_chance", 1);
        set("chat_msg", ({
        name()+"如石雕般在海风巨浪中纹丝不动，安然垂钓。\n",
        }) );
        
    set("combat_exp", 400000);
        
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 160);
        set_skill("unarmed",200);
    set_skill("changquan",200);
        set_skill("parry",200);
        
    map_skill("unarmed", "changquan");
        
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
