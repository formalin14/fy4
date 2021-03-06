 // changquan.c
inherit SKILL; 
void setup() {
        set("name",                                     "少林长拳");
        set("effective_level",          60);
        set("practice_limit",250);
        set("usage/unarmed",            1);
        set("skill_class",                      "official");
        set("parry_msg",                        ({
                        "$n以守为攻，一招「反客为主」，猛击$N握$w的手腕。\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
                        })
        );
        action = ({
                        ([      "action":               "$N使一招「黑虎掏心」，对准$n的$l「呼」地一拳",
                                "force":                80,
                                "parry":                60,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N扬起拳头，一招「泰山压顶」便往$n的$l招呼过去",
                                "force":                60,
                                "parry":                30,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N左手虚晃，右拳「中宫直进」便往$n的$l击出",
                                "force":                60,
                                "parry":                30,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N步履一沉，左拳拉开，右拳使出「老汉推车」击向$n$l",
                                "force":                60,
                                "parry":                80,
                                "damage_type":  "瘀伤"
                        ]),
        });
} 

int effective_level()
{
        object me=this_player();
        int skill,n;
        //n=(skill-200)/5*10+60;
        skill=me->query_skill("changquan",1);
        if (skill < 200) return 60;
        if (skill >= 300) return 220;
        if (skill >=280) return 200;
        if (skill >=260) return 180;
        if (skill >=240) return 150;
        if (skill >=220) return 120;
        if (skill >=200) return 90;
        
        
        
        
        
        
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 100 ) return 0;
        badint = victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth")*2;
        if (victim->query_skill_mapped("iron-cloth") == "xuanxinjue"
         
                ) {
                if(badint) {
                        victim->receive_wound("kee",badint);
                        switch(random(3)) {
                                case 0: return "$N大喝一声，全力出击，往$n气墙最弱的双耳打去！\n";
                                case 1: return "$N劲力尽处竟再生劲力，两劲齐发，$n的$l发出“喀”地一声爆响！\n";
                                case 2: return "只听见$n的$l“喀”地一声 ．．．\n";
                                }
                }
        }
}  