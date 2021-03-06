 // enable.c
#include <ansi.h>
inherit F_CLEAN_UP; 
mapping valid_types = ([
//              "array":        "阵法",
                "animal-training":  "训兽术",
                "axe":                  "斧法",
                "blade":        "刀法",
                "dagger":       "短兵刃",
                "dodge":        "闪躲术",
                "force":        "内功",
                "fork":         "叉法",
                "hammer":       "锤法",
                "iron-cloth":   "硬功",
                "literate":     "读写",
                "magic":        "法术",
                "move":         "轻功",
                "parry":        "招架",
                "perception":   "听风术",
                "scratching":   "符之术",
                "cursism" :     "降头术",
                "spells":       "咒文",
                "staff":        "杖法",
                "stealing":     "妙手术",
                "sword":        "剑法",
                "throwing":     "暗器",
                "unarmed":      "拳脚",
                "whip":         "鞭法",
                "herb":         "药道",
                "spear":        "枪法",
]); 
int main(object me, string arg) {
        mapping skill_map;
        string *types, *skill, *usr_skill, ski, map_to;
        int i, j, modify;
        string s;
        string skill_name,enable_skill;
        int skill_level;
        
        seteuid(getuid());
   
        if(!arg) {
                skill_map = me->query_skill_map();
                if(!mapp(skill_map) || sizeof(skill_map)==0 ) {
                        return notify_fail("你现在没有使用任何特殊技能。\n");
                }
                skill = keys(valid_types);
                write("以下是你目前使用中的特殊技能。\n");
                for(i=0; i<sizeof(skill); i++) {
                        if(undefinedp(valid_types[skill[i]])) {
                                map_delete(skill_map, skill[i]);
                                continue;
                        }
                        if(!me->query_skill(skill[i])) {
                                continue;
                        }
                        modify = me->query_temp("apply/" + skill[i]);
                        printf("  %-20s： %-20s  有效等级：%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(skill_map[skill[i]]) ? "无" : 
                                        SKILL_D(skill_map[skill[i]])->name(),
                                    (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i]));
                }
                return 1;
        }
        
        if(arg=="?") {
                write("以下是可以使用特殊技能的种类和你会的特殊技能：\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                if (me->query_skills())
                        usr_skill = keys(me->query_skills());
                for(i=0; i<sizeof(skill); i++) {
                        s = sprintf("%6s (%s)", valid_types[skill[i]], skill[i]);
                        if (me->query_skills())
                                usr_skill = filter_array(keys(me->query_skills()), (: SKILL_D($1)->valid_enable($2) :), skill[i]);
                        if(sizeof(usr_skill)) {
                                for(j=0; j<sizeof(usr_skill); j++) {
                                        printf("  %-20s : %s (%s)\n", s, SKILL_D(usr_skill[j])->name(), usr_skill[j]);
                                        s = " ";
                           }  
                        } else {
                                printf("  %-20s\n", s); 
                        }
                }
                return 1;
        } 
        if (arg)
        if (sscanf(arg, "%s %s", ski, map_to)!=2)
        if (sscanf(arg,"%s",skill_name)==1 && skill_name!="none") {
                if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
                        return notify_fail("「" + skill_name + "」，有这种技能吗？\n"); 
                if( !(skill_level=me->query_skill(skill_name,1)))
                        return notify_fail("你并没有学过这项技能或是技能等级为零。\n");
                
                if(undefinedp(valid_types[skill_name])) 
                        return notify_fail("此项技能不是基本技能种类，用 enable ? 可以查看有哪些种类。\n");
                enable_skill=me->query_skill_mapped(skill_name);
                                        
                write("以下是你查询的特殊技能状况。\n\n");
                modify = me->query_temp("apply/" + skill_name);
                printf("  %-20s： %-20s  有效等级：%s%3d\n\n" NOR, 
                                valid_types[skill_name] + " (" + skill_name + ")",
                                (!me->query_skill_mapped(skill_name)) ? "无" : 
                                        SKILL_D(enable_skill)->name(),
                                    (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill_name)
                        );
                return 1;
        } 
        
        if(sscanf(arg, "%s %s", ski, map_to)!=2) {
                return notify_fail("指令格式：enable <技能种类> <技能名称>|none\n");
        }
        
        if(undefinedp(valid_types[ski])) {
                return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。\n");
        }
        
        if(map_to=="none") {
           me->map_skill(ski);
                me->reset_action();
                write("停止使用「" + valid_types[ski] + "」的特殊技能。\n");
                return 1;
        } else if(map_to==ski) {
                write("「" + SKILL_D(ski)->name() + "」是所有" + valid_types[ski] + "的基础，不需要 enable。\n");
                return 1;
        }
        
        if(!find_object(SKILL_D(map_to)) && !load_object(SKILL_D(map_to))) {
                return notify_fail("「" + map_to + "」，有这种技能吗？\n");     
        } 
        if(!me->query_skill(map_to, 1)) {
                return notify_fail("你不会特殊技能「" + SKILL_D(map_to)->name() + "」。\n");
        } 
        if(!me->query_skill(ski, 1)) {
                return notify_fail("你连「" + SKILL_D(ski)->name() + "」都没学会，如何使用特殊技能「" + SKILL_D(map_to)->name() + "」？\n");
        }
        if (map_to == "tanzhi-shentong" && ski=="parry" && !me->query("open_sesame") ) {
                return notify_fail("特殊技能「" + SKILL_D(map_to)->name() + "」不能用在「" + valid_types[ski] + "」上。\n");
        }
        if(!SKILL_D(map_to)->valid_enable(ski)) {
                return notify_fail("特殊技能「" + SKILL_D(map_to)->name() + "」不能用在「" + valid_types[ski] + "」上。\n");
        } 
        if(ski=="dodge" && me->query_temp("stepup"))
                return notify_fail("你正在使用闪躲术的特殊技能，必须等其效果消失后才能转换此武功。\n");
        
        if(ski=="iron-cloth" && me->query_temp("daoqian"))
                return notify_fail("你正在使用硬功的特殊技能，必须等其效果消失后才能转换此武功。\n");
        
        if(ski=="force" && me->query_temp("buffup/buffed_kee"))
                return notify_fail("你正在使用冰心诀的特殊技能，必须等其效果消失后才能转换此武功。\n");
                
        me->map_skill(ski, map_to);
        me->reset_action();
        write("开始使用「" + valid_types[ski] + "」的特殊技能「" + SKILL_D(map_to)->name() + "」。\n");
        
        if( ski=="magic" ) {
                write("你改用另一种法术系，灵力必须重新锻炼。\n");
                me->set("atman", 0);
   } else if( ski=="force" ) {
                write("你改用另一种内功，内力必须重新锻炼。\n");
                me->set("force_factor",0);
                me->set("force", 0);
        } else if( ski=="spells" ) {
                write("你改用另一种咒文系，法力必须重新修炼。\n");
                me->set("mana", 0);
        }
        
        return 1;
}
int help(object me) {
        write(@HELP
指令格式 :      enable
                enable ?
                enable <技能种类>
                enable <技能种类> <技能名称> | none 
这个指令让你指定所要用的技能，需指明技能种类和技能名称。
如果不加参数则会显示出技能种类及你目前所使用的技能名称 ，
如果加一个 ? 会列出所有能使用特殊技能的技能种类，
如果直接跟技能种类会列出目前该技能的ｅｎａｂｌｅ状态。
 
HELP
        );
        return 1;
}
       
