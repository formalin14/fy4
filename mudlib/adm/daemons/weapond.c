// weapond.c
#pragma optimize
#include <ansi.h>
#include <combat.h>

mapping weapon_actions = ([
        "slash": ([
                "damage_type":  "割伤",
                "action":               "$N挥动$w，斩向$n的$l",
                "parry":                20,
                ]),
        "slice": ([
                "damage_type":  "砍伤",
                "action":               "$N用$w往$n的$l砍去",
                "dodge":                20,
                ]),
        "chop": ([
                "damage_type":  "劈伤",
                "action":               "$N的$w朝著$n的$l劈将过去",
                "parry":                -20,
                ]),
        "hack": ([
                "action":               "$N挥舞$w，对准$n的$l一阵乱砍",
                "damage_type":  "砍伤",
                "damage":               30,
                "dodge":                30,
                ]),
        "thrust": ([
                "damage_type":  "刺伤",
                "action":               "$N用$w往$n的$l刺去",
                "dodge":                15,
                "parry":                -15,
                ]),
        "pierce": ([
                "action":               "$N的$w往$n的$l狠狠地一捅",
                "damage_type":  "刺伤",
                "dodge":                -30,
                "parry":                -30,
                ]),
        "whip": ([
                "action":               "$N将$w一扬，往$n的$l抽去",
                "damage_type":  "鞭伤",
                "dodge":                -20,
                "parry":                30,
                ]),
        "impale": ([
                "action":               "$N用$w往$n的$l直戳过去",
                "damage_type":  "刺伤",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "bash": ([
                "action":               "$N挥舞$w，往$n的$l用力一砸",
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "crush": ([
                "action":               "$N高高举起$w，往$n的$l当头砸下",
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "slam": ([
                "action":     "$N手握$w，眼露凶光，猛地对准$n的$l挥了过去",          
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "throw": ([
                "action":               "$N将$w对准$n的$l射了过去",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
]);

varargs mapping query_action()
{
        string verb, *verbs;

        verbs = previous_object()->query("verbs");

        if( !pointerp(verbs) ) return weapon_actions["hit"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return 
weapon_actions[verb];
                else return weapon_actions["hit"];
        }       
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
                        tell_object(me, "\n你的" + weapon->query("name") + 
"用完了！\n\n");
                }
                weapon->add_amount(-1);
        }
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp;

        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query_str() * 10;
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str() * 10;
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "只听见「啪」地一声，$N手中的" +
ob->name()
                                + "已经断为两截！\n" NOR, victim );
                        ob->unequip();
                        ob->set("name", "断掉的" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
			ob->set("no_get",0);
			ob->set("no_drop",0);
			ob->save();
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision(HIW "$N只觉得手中" + ob->name() +
"把持不定，脱手飞出！\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp / 2 ) {
                        message_vision("$N只觉得手中" + ob->name() +
"一震，险些脱手！\n", victim);
                } else {
                        message_vision("$N的" + weapon->name() + "和$n的" + 
ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                }
        }
}
 

void wear_off(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp,i;
	object *inv;
// weapon is me's weapon if it is not null
// ob is my victiim's weapon if it is not null
// damage could be RESULT_PARRY, RESULT_DODGE, or a positive number (victim got hit!)
// we won't do anything if it is a DODGE, what can we do?
	ob = victim->query_temp("weapon");
	if (damage == RESULT_DODGE) return;
        if( objectp(weapon) && damage==RESULT_PARRY && objectp(ob))
	{
// we also use wap/(wap+wdp) formular
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query_str() * 10;
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str() * 10;
// I don't think player can afford damage to their things every time two weapons hit each other
	if(!random(10) && random(wap) > random(wap+wdp))
	{
		message_vision(HIW "$N手中的" +ob->name()+ "被磕出一个缺口！\n" NOR, victim );
		ob->add("weapon_prop/damage",-1);
		if((int)ob->query("weapon_prop/damage") <= 1 ) 
		ob->set("weapon_prop/damage",1);
		else victim->add_temp("apply/damage",-1);
		if(ob->query("owner"))
		ob->save();
		
	}
        if(!random(10) && random(wdp) > random(wap+wdp))
        {
                message_vision(HIW "$N手中的" +weapon->name()+ "被磕出一个缺口！\n" NOR, me);
                weapon->add("weapon_prop/damage",-1);
                if((int)weapon->query("weapon_prop/damage") <= 1 ) 
                weapon->set("weapon_prop/damage",1);
                else me->add_temp("apply/damage",-1);
		if(weapon->query("owner"))
                weapon->save();

        }
    }
        if( damage > 10 && !random(10))
	{
		inv = all_inventory(victim);
		for(i=0;i<sizeof(inv);i++)
			if(inv[i]->query("equipped") == "worn" && inv[i]->query("owner")== victim->query("id") && random(2))
		{
		message_vision(HIW "$N身上的" +inv[i]->name()+ "被弄坏了一点儿！\n" NOR, victim);
                inv[i]->add("armor_prop/armor",-1);
                if((int)inv[i]->query("armor_prop/armor") <= 1 ) 
                inv[i]->set("armor_prop/armor",1);
                else victim->add_temp("apply/armor",-1);
                inv[i]->save();
		}
	
	}
	return;

}
 
