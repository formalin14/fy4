#include <ansi.h>
inherit NPC;
int do_leave(object me);
void create()
{
        set_name("孙远超", ({ "sun yuanchao", "sun" }) );
        set("gender", "男性" );
        set("age", 28);
        set("nickname", HIW"江里白龙"NOR);
        set("long", @LONG
他身材颀长，双目炯然，看上去一表人材。
LONG
);
        set_skill("unarmed", 150);
        set_skill("blade", 150);
        set_skill("move", 120);
        set_skill("dodge", 140);
        set_skill("force", 130);
        set_skill("parry", 150);
        set_skill("meng-steps", 100);
        set_skill("liumang-strike", 90);
        set_skill("lianxin-blade", 140);
        map_skill("unarmed", "liumang-strike");
        map_skill("blade", "lianxin-blade");
        map_skill("move", "meng-steps");
        map_skill("dodge", "meng-steps");
        map_skill("parry", "lianxin-blade");
    set("max_gin", 3000);
    set("max_kee", 3000);
    set("max_sen", 3000);
    set("max_force", 1000);
    set("force", 1000);
        set("combat_exp", 300000);
        setup();
        carry_object("/obj/armor/cloth",
                ([ "name": "白衫" ])
                )->wear();
        carry_object("/obj/weapon/blade")->wield();
} 
void die(){
        object me;
        
        if(objectp(me=query_temp("last_damage_from") )){ 
                if(me->query("marks/初见方少璧")){
                        me->delete("marks/初见方少璧");
                        if(!me->query("m_success/救方少璧")){
                                me->set("m_success/救方少璧",1);
                                me->add("score",800);
                                me->add("combat_exp", 300);
                                me->add("potential", 200);
                        }
                environment(this_object())->check_rescue(me);
                }
        }       
        ::die();
}      
