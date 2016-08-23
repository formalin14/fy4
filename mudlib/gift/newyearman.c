#include <ansi.h>
inherit NPC;
int hongbao(); 
void create()
{
    set_name(HIR"财神"NOR, ({"oldman","财神"}) );
    set("gender", "男性" );
    set("nickname", HIC"慈祥的"NOR);
    set("title", HIR"新春快乐"NOR);
    set("long", "据说这个财神是天上下凡的神仙，他兜里装着很多红包(hongbao)，你可以向他要。\n");
        set("attitude", "friendly");
        set("age", 25);
        set("cor", 25);
        set("cps", 25);
        set("per", 25);
        set("combat_exp", 30000000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 200);

        set_skill("parry", 1000);
        set_skill("unarmed",1000);
        set_skill("dodge", 1000);
        set_skill("force",1000);
        set_skill("yiqiforce", 100);
        map_skill("force","yiqiforce");
        map_skill("unarmed","yiqiforce");

        set("chat_chance", 1);
        set("chat_msg", ({
           "财神微笑道：这次红包发放的非常顺利。\n",
        }) );
        set("inquiry", ([
                "红包" : (: hongbao :),
                "hongbao" : (: hongbao :),
                "新春礼物" : (: hongbao :),
                "gift" : (: hongbao :),
        ]));
        setup();
} 

 void init()
{       
        add_action("do_killing", "kill");
}   

int hongbao(){
    object me,ob;
    int exp;
    
    me = this_player();
    exp=(int)me->query("combat_exp");
    ob=new("/questobj/hongbao1");
    if(exp<300000)
       message_vision(WHT"财神慈祥的拍了拍$N的头，微笑着说：你还小，叫你父母代你领吧。\n"NOR,me);
    else{
      if(!me->query("newyear_2005"))
      {
        message_vision(WHT"财神对$N说道：新春快乐，恭喜发财，这是你的红包。\n"NOR,me);
        message_vision("财神从兜里摸出一个"+ob->query("name")+"，然后递给$N\n",me);
        ob->move(me);
        me->set("newyear_2005",1);
       }
       else message_vision(WHT"财神对$N大笑道：像你这样拿法，即便是财神也被你拿穷了。\n"NOR,me);
       }
    return 1;
} 
int do_killing(string arg)
{
        object player;
        if(!arg) return 0;
        player = this_player();
        message_vision("财神微笑着对$N道：新年就少杀人了吧。\n",player);
        return 1;
}