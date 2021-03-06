 // teacher.c
//Modified by justdoit 04/11/2001 
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("测试人物", ({ "tester" }) );
    set("gender", "男性" );
    set("age", 32);
    set("force",500);
    set("force_factor",20);
    set("max_force",500);
    
    set("inquiry",      ([
        "mission" : (: test_dart :),
        ]) );
    set("int", 30);
    set("long",
        "测试护送任务的NPC.\n"
        );
    set("chat_chance", 2);
    set("chat_msg", ({
            }) );
    
    set_skill("unarmed", 80);
    set_skill("dabei-strike", 80);
    set_skill("literate", 80);
    set_skill("force", 80);
    set_skill("dodge",80);
    set_skill("parry",80);
    set_skill("move",80);
    set_skill("hammer",80);
    set_skill("xiaochengforce",80);
    set_skill("liuxing-hammer",80);
    set_skill("puti-steps",80);

    map_skill("force", "xiaochengforce");    
    map_skill("unarmed", "dabei-strike");
    map_skill("dodge","puti-steps");
    map_skill("move","puti-steps");
    map_skill("hammer","liuxing-hammer");
    
    set("combat_exp", 3500000);
    setup();
} 
void init()
{
        ::init();
        add_action("do_accept", "accept");
} 
int test_dart()
{
    object me;
        
    me=this_player();
    if (query("护送任务/gived") )
    {
        set("护送任务/gived",1);
        command("say 我们这里还没有你要的护送任务。");
        return 1;
    }
    command("say 现在有一个重要的人物要去目的地，你是否愿意？(accept mission)");
    return 1;
} 
int do_accept(string arg)
{    
    object ob,cart,biaotou;
    object me,*team;
    string location;
    int i, exp; 
    
    if (arg != "mission") return 0;
    me=this_player();
    team=me->query_team();
    if (sizeof(team)==0) team=({me}); 
   if (sizeof(team) != 0 && (team[0]!=me)) 
        return notify_fail("say 只有队伍首领才能提出接镖。\n");
        
    for (i=0;i<sizeof(team);i++)
    {
    	team[i]->set_temp("护送任务/难度",1);
/*        if (team[i]->query("combat_exp")<1000000)
        {
            command("say 护镖路途危险，我看这位"+RANK_D->query_respect(team[i])+"似乎不宜！");
            return 1;
        }
        if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
        {
            command("say 护镖是危险的事，我看"+RANK_D->query_respect(team[i])+"没有赔偿能力。");
            return 1;
        }  */
        if (team[i]->query("combat_exp")>exp)
                exp= team[i]->query("combat_exp");
    } 
    

        if (query("护送任务/gived"))
                {
                 command("say 你来晚了，已经有人接下这个任务了。");
                 return 1;
                }

    set("护送任务/gived",1);
    command("say 一路小心。");
    location = environment(me)->query("short");
    CHANNEL_D->do_sys_channel(
                "info",sprintf("%s，%s保护一名重要人物从%s出发！", NATURE_D->game_time(),
                me->query("name"),location) );  
        
    biaotou=new("/gift/ceshi");
    biaotou->move(environment());
    biaotou->get_quest("/gift/missionway");
    biaotou->set_protector(team);
    biaotou->set("combat_exp",exp/5);
    create_level(biaotou,"ceshi",exp/5);
        

    me->set_leader(biaotou);
    me->set_temp("护送任务/accepted",1);
    biaotou->go_now();
    return 1;   
} 
void reset()
{
    delete("护送任务/gived");
}  
void create_level(object who,string name, int exp)
{
        int level;
        level=100+130*(exp-1000000)/6500000;
        if (exp<1000000) level=100;
        if (exp>7500000) level=200;
        level=level*level/100;
        if (name=="ceshi") {
                
                who->command("say biao is me。");
                who->set("str",10+random(level/15));
                who->set("agi",10+random(level/8));
           who->set("cor",20+random(15));
                who->set("max_kee",1000+random(level*level/40));
                who->set("eff_kee",who->query("max_kee"));
                who->set("kee",who->query("max_kee"));
                who->set_skill("hammer", 70 + random(level/2));
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("changquan",50+random(level/2));
                who->set_skill("unarmed",70 + random(level/2));
        }
        if (name=="gangster") {
                who->set("str",10+random(level/12));
                who->set("agi",10+random(level/8));
                who->set("cor",20+random(15));
                who->set("max_kee",2500+random(level*level/40));
                who->set("eff_kee",who->query("max_kee"));
                who->set("kee",who->query("max_kee"));
                who->set("max_sen",who->query("max_kee")/2);
                who->set("max_gin",who->query("max_kee")/2);
                who->set("eff_sen",who->query("max_sen"));
                who->set("sen",who->query("max_sen"));
                who->set("eff_gin",who->query("max_gin"));
                who->set("gin",who->query("max_gin"));
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("blade",70+random(level/2));
                who->set_skill("fall-steps",70+random(level/2));
                who->set_skill("unarmed",70+ random(level/2));
                who->set_skill("yue-strike",50+random(level/8));
                who->set_skill("shortsong-blade",50+random(level/8));
        } 
}   
