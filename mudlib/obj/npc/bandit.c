 // bandit.c
#include <ansi.h>
inherit NPC;
void create() {
        set_name("土匪", ({ "tufei", "bandit"}) );
        set("long","一个满脸伤疤加横肉的家伙。\n");
        set("attitude", "friendly");
        set("vendetta/authority",1);
        set("per", 1);
        set("intellgent",1);
        set("pursuer",1);
        set("no_return",1);
        set("combat_exp", 100000+random(400000));
                set("bellicosity", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                name()+ "喝道：今天老子要钱又要命！！\n",
                name()+ "笑道：贼娘的，去死吧！\n",
                                HIR+ name()+ HIR"大喊：砍死一个够本，砍死两个赚一个！！\n"NOR,
                                (: random_move :),
        }) );
        set("chat_chance", 99);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        set_skill("unarmed", 70+random(150));
        set_skill("axe", 70+random(150));
        set_skill("blade", 70+random(150));
        set_skill("hammer", 70+random(150));
        set_skill("sword", 70+random(150));
        set_skill("parry", 70+random(150));
        set_skill("dodge", 70+random(150));
        set_skill("move", 100+random(150)); 
        set_temp("apply/attack", 20+random(200));
        set_temp("apply/dodge", 20+random(200));
        set_temp("apply/armor", 20+random(200));
        set_temp("apply/damage", 20+random(200));
        set_temp("apply/move", 20+random(200)); 
        setup();
} 
void init() {
    remove_call_out("hunting");
        if(environment() && !environment()->query("no_fight")) {
        call_out("hunting",1);
        }
} 
void hunting() {
        int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(ob[i]->query("class")=="bandit") continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
} 
void setup_bandit(string name, string armor, string weapon, string mark) {
        object armor_ob, weapon_ob;
        
        set("name", name);
        armor_ob = new(armor);
        if(objectp(armor_ob)) {
                armor_ob->move(this_object());
                armor_ob->wear();
        }
        weapon_ob = new(weapon);
        if(objectp(weapon_ob)) {
                weapon_ob->move(this_object());
                weapon_ob->wield();
        }
        set("area_mark", mark);
}   
void die()
{
        int i,score,exp,pot;
        object killer,owner; 
        score=random(5);
        pot=60+random(40);
        exp=300+random(200);
        
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->add("combat_exp",exp);
             killer->add("potential",pot);
             killer->add("score",score);
             tell_object(killer,"\n成功剿匪！！！被奖励了：\n" + chinese_number(exp) + "点实战经验\n"
                        + chinese_number(pot) + "点潜能\n" + chinese_number(score)+"点综合评价\n");
        }
        
        ::die(); 

}
