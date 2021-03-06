#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
inherit F_MASTER;
inherit NPC;
void imbue_event(object me);
void create()
{
        set_name("天枫十四郎", ({ "tianfeng"}) );
        set("gender", "男性" );
        set("age", 55);
        set("nickname", CYN "伊贺忍侠" NOR);
        set("long", 
"一个面色蜡黄，浓眉高颧的乌衣老者，浑身尽是杀气。他盘膝坐在山巅之上，
衣抉下露出赤足，却将一双高齿乌木的木屐端放于前，木屐上竟又放着柄乌
鞘长刀。\n");
//      create_family("一刀流", 7, "家督");
//      set("rank_nogen",1);
//      set("ranks",({"下忍","中忍","上忍",RED"罗刹"NOR,HIR"修罗"NOR}));
//      set("rank_levels",({32000,512000,1536000,3456000 }));
        set("combat_exp", 3200000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 10);
        
        set("force", 800);
        set("max_force",800);
        set("force_factor",30);
        set("skill_public",1);
        
        set_skill("unarmed", 140);
        set_skill("ghosty-force", 300);
        set_skill("enmeiryu",150);
        set_skill("ittouryu",160);
        set_skill("ninjitsu",200);
        set_skill("dodge", 140);
        set_skill("ghosty-steps",200);
        set_skill("blade",140);
        set_skill("literate", 140);
           set_skill("force", 180);
        set_skill("parry", 140);
        set_skill("magic", 100);
        set("resistance/kee",10);
        
        map_skill("magic", "ninjitsu");
        map_skill("unarmed", "enmeiryu");
        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("force", "ghosty-force");
        
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );  
   
   
   
        set_temp("apply/damage",100);
        set("chat_chance", 1);
        set("chat_msg", ({
                        "天枫十四郎那亘古不变的死灰色的脸突然颤抖起来，哇的一声咳出口鲜血。\n",
                                })  );
        set("inquiry",  ([
                "李菊" : "菊子。。菊子。。你在哪里。。。\n",
                "南宫灵" : "我失散多年的孩子啊，有生之年如果能见他一面死也无憾啊。\n",
                "无花" : "我失散多年的孩子啊，有生之年如果能见他一面死也无憾啊。\n",
                ])              );
        
        setup();
        carry_object(__DIR__"obj/wucloth")->wear();
        carry_object(__DIR__"obj/muji")->wear();
        carry_object(__DIR__"obj/blackblade")->wield();
}   
void win_enemy(object loser)
{
    message_vision(HIC "天枫十四郎仰天长叹一声，良久。。\n"NOR,loser);
    message_vision(HIR "天枫十四郎突然哇地一声喷出口鲜血，发狂一般仰天长嘶：
菊子啊，你。。。你。。在何方。。\n"NOR,loser);
   loser->set("天枫_quest1",time());
} 
void lose_enemy( object winner)
{
        object blade;
        
        winner->set("天枫_quest1","成功");
        if(blade=present("black blade",this_object()))
        {
                message_vision(HIR"天枫十四郎死灰般的眼睛突然亮了起来，双手将乌鞘长刀交给$N，
双膝跪地肃然道：你，好汉。此刀请你转交给我子灵儿。。拜托了。。\n"NOR,winner);
                blade->move(winner);
        }
                
} 
int accept_fight(object me)
{
        int count;
        object blade,who;
        who=this_object();
        
        if (this_object()->is_fighting() || this_object()->is_busy())
                return notify_fail("天枫十四郎正在忙着呢，没空和你搭话！\n");
        
        if(!present("black blade",this_object())) return 0;
        if(me->query("天枫_quest1")=="成功")
        {
                message_vision(HIW"天枫十四郎问道：“我拜托你的事情，帮我做到了吗？”\n"NOR,me);
                return 0;
        }
        if(me->query("天枫_quest1")&&me->query("天枫_quest1")+600>time())
        {
                message_vision(HIR"天枫十四郎不屑的看着$N说道：“手下败将，还来做甚？”\n"NOR,me);
                return 0;
        }
        count=me->query_temp("天枫_挑战次数");
        
        if(me->query("combat_exp")<2500000||me->query("score")<15000)
        {
        if(count==0)
           message_vision(HIY"天枫十四郎霍然睁开双眸，扫了$N一眼，微叹一声，闭目无语。\n"NOR,me);
        
        else if(count==1)
                message_vision(HIY"天枫十四郎哼了一声低喝道：吾乃东瀛天枫十四郎，不战阁下这等碌碌无为之辈。\n"NOR,me);
        else if(count==2)
        {
                message_vision(HIW"天枫十四郎眉头微皱，“呛”的一声，刀光乍现。\n"NOR,me);
                kill_ob(me);
                me->delete_temp("天枫_挑战次数");
                return 2;
        }
        me->add_temp("天枫_挑战次数",1);
        return 0;
        }
        
        if (who->query("kee")<who->query("max_kee") || who->query("eff_kee")<who->query("max_kee")
        || who->query("sen")<who->query("max_sen") || who->query("eff_sen")<who->query("max_sen")
        || who->query("gin")<who->query("max_gin") || who->query("eff_gin")<who->query("max_gin"))
                {tell_object(this_player(),"天枫十四郎正在疗伤,没空理你.\n");
                return 0;
                }
        message_vision(HIY"天枫十四郎长吸一口气,霍然睁开双眸，目光如电盯着$N，冷冷道：你，出招！\n"NOR,me);
        return 1;
}
        
        
int accept_object(object who, object ob)
{
        if(!ob->query("saki")) return 0;
        message_vision(HIC"天枫十四郎双手紧握这瓶清酒，如获重宝。\n"NOR,who);
        call_out("be_poisoned",5+random(5),who);
        return 1;
} 
int be_poisoned(object who)
{
    message_vision(HIR"\n天枫十四郎颤抖着捧起清酒，老泪纵横，一仰而尽。\n
突然天枫十四郎浑身颤抖，大汗淋漓，凄然道：菊子，你。。你。。唉。。
这位"+RANK_D->query_respect(who)+"，吾身中奇毒，即便能逼出，也必功力尽废，但有一事想求，
不知你可否答应？\n"NOR,who);
        if(who->query("天枫_quest4")!="成功")
   {
                die();
                return 1;
        }
    tell_object(who,HIY"answer yes/no \n"NOR);
        who->set_temp("answer_person",1);
        return 1;
} 
int do_answer(string arg)
{
        object skinmask,who;
        
        who=this_player();
        if(!who->query_temp("answer_person")) return 0;
        if(arg=="yes")
        {
                message_vision("$N神色凝重地点了一下头。\n",who);
                message_vision(HIB"天枫十四郎仰天狂笑道：好，我今日约战了中原一点红，你就代我
一战吧。大恩必当涌泉相报。\n"NOR,who);
                skinmask=new(__DIR__"obj/skinmask");
                skinmask->move(who);
                message_vision("天枫十四郎给$N一件装束。\n",who);
                who->set("天枫_quest5","成功");
                who->delete_temp("answer_person");
                return 1;
                
        }
        if(arg=="no")
        {
                message_vision(HIR"天枫十四郎凄然一笑，吐出口鲜血，倒地而亡。\n"NOR,who);
                die();
                return 1;
        }
        return 0;
}  
void imbue_event(object me){
    object obj, weapon, *inv;
    string prop;
    int i;
    
    if(!interactive(me) || environment(me) != environment(this_object())) {
            return;
    }
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }
        if(!objectp(weapon)){
                if(!objectp(obj)) {
                        message_vision(HIG"\n泪水滚到地上，一会儿就消失了。。。\n"NOR, me);
                } else {
                        message_vision(HIG"\n泪水溅到了$N的" + obj->name() + HIG"上，又顺着"
                        + obj->name() + HIG"落到了地上。\n"NOR, me);    
                }
        }else{
                message_vision(HIG"\n泪水溅到了$N的"NOR + weapon->name() + 
                                HIG"上，竟有生命似的渗了进去。。 \n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                }
                weapon->add(prop+"strength", 3);
                weapon->add(prop+"damage", 10);
                weapon->add("base_damage", 10);
                weapon->save();
                me->set("imbue/tianfeng", 1);
                return;
        }
        me->set("imbue/tianfeng", 2);
        return;
} 
void init()
{       object ob;
        ::init();
        add_action("do_answer","answer");
        add_action("do_accept", "accept");
        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) && !is_fighting() ) 
        if (ob->query("天枫_quest6"))
        {
                remove_call_out("recruiting");
                call_out("recruiting", 1, ob);
        } 
}  
void recruiting(object ob)
{
        if(ob->query("天枫_quest6")=="失败")
        {
                message_vision(HIR"天枫十四郎凄然一笑，吐出口鲜血，倒地而亡。\n"NOR,ob);
                ob->delete("天枫_quest6");
                this_object()->die();
                return;
        }
        if(ob->query("天枫_quest6")=="成功"&& !ob->query("tianfeng/done_quest"))
        {
                tell_object(ob,WHT"天枫十四郎睁开无力的双眼，微微笑道：好，好，你不愧是仁义武者。\n"NOR);
                tell_object(ob,WHT"我虽中毒已深，命在旦夕，但这番中原之行心愿已了，却也无憾。\n"NOR);
                tell_object(ob,WHT"我有几门打基础的武功,你可以随便学.\n"NOR);
                tell_object(ob,WHT"沉默片刻天枫十四郎又道，你我有缘，我可传你一门扶桑武功，你可愿意？（accept yes or no）\n"NOR);
                ob->set_temp("tianfeng/a_sk1",1);
                return;
        }
}  
int do_accept(string arg)
{
    if(!this_player()->query_temp("tianfeng/a_sk1")) return 0;
    if( arg == "no" )
    {
        message_vision(HIB"\n$N犹豫了一下，摇了摇头道：在下已有师承，不敢妄自学艺。\n"NOR, this_player());
        message_vision(WHT"天枫十四郎叹了口气,“"+RANK_D->query_respect(this_player())+"志向非我可及.", this_player());
        message_vision(WHT"可惜我一身功夫竟无传人。。“\n"+HIG"两滴浑浊的泪水从天枫十四郎脸颊上滚落下来。\n"NOR, this_player());
        this_player()->set("tianfeng/done_quest","2");
        if(!this_player()->query("imbue/tianfeng")){
              imbue_event(this_player());
        }
        return 1;
    }
    else if( arg == "yes" )
    {
        message_vision(CYN "\n$N长身一揖：得前辈指点," + RANK_D->query_self(this_player()) + "终身受益！\n\n"NOR, this_player());
        tell_object(this_player(),WHT"天枫十四郎道:以下这几门武功,你可以任选一样....\n"NOR,this_object());
        if (this_player()->query("gender")=="女性") {
                tell_object(this_player(),HIG"陆奥圆明流拳术(enmeiryu),  无坎真阴(ghosty-force),  太虚幻步(ghosty-steps),
                一刀流剑术(ittouryu),  忍术(ninjitsu).\n"NOR+HIY"（choose 武功）\n"NOR);
                }
                else
                tell_object(this_player(),HIG"陆奥圆明流拳术(enmeiryu),  一刀流剑术(ittouryu),  无坎真阴(ghosty-force),  忍术(ninjitsu).\n"NOR+HIY"（choose 武功）\n"NOR);
        this_player()->set_temp("tianfeng/a_sk2",1);
        add_action("do_choose", "choose");
        return 1;
     }
    else  return 0;
}  
int do_choose(string arg)
{
    if(!this_player()->query_temp("tianfeng/a_sk2")) return 0;
    if( this_player()->query("tianfeng/done_quest")) return 0;
    if( arg == "陆奥圆明流拳术"|| arg== "enmeiryu" )
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/enmeiryu",1);
        tell_object(this_player(),WHT"天枫十四郎点了点头说:好,陆奥圆明流乃一刀流第一代家督所创，讲究的是一个快字，拳法瞬息多变,令对手防不胜防.你好好练吧.\n"NOR);
        tell_object(this_player(),WHT"不过,扶桑武功只传有缘之人,即使是夫妻手足也不例外,切记!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    if( (arg == "无坎真阴"|| arg== "ghosty-force"))
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/ghosty-force",1);
        tell_object(this_player(),BLU"天枫十四郎叹了口气,这无坎真阴....你好好练吧.\n"NOR);
        tell_object(this_player(),WHT"不过,扶桑武功只传有缘之人,即使是夫妻手足也不例外,切记!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    if( (arg == "太虚幻步"|| arg== "ghosty-steps") && this_player()->query("gender")=="女性")
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/ghosty-steps",1);
        tell_object(this_player(),BLU"天枫十四郎叹了口气,这太虚幻步....你好好练吧.\n"NOR);
        tell_object(this_player(),"WHT不过,扶桑武功只传有缘之人,即使是夫妻手足也不例外,切记!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    if( arg == "一刀流剑术"|| arg== "ittouryu" )
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/ittouryu",1);
        tell_object(this_player(),WHT"天枫十四郎点了点头说:此刀法求的是一个狠字,出刀之时,需偕天地之气,置自身安危于度外....你好好练吧.\n"NOR);
        tell_object(this_player(),WHT"不过,扶桑武功只传有缘之人,即使是夫妻手足也不例外,切记!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    if( arg == "忍术"|| arg== "ninjitsu")
    {
        this_player()->set("tianfeng/done_quest",1);
        this_player()->set("tianfeng/ninjitsu",1);
        tell_object(this_player(),WHT"天枫十四郎点了点头说:忍术是武士精粹所在....你好好练吧.\n"NOR);
        tell_object(this_player(),WHT"不过,扶桑武功只传有缘之人,即使是夫妻手足也不例外,切记!\n"NOR);
//      remove_action("do_choose", "choose");
        return 1;
    }
    return 0;
} 
int recognize_apprentice(object ob)
{
    if(ob->query("tianfeng/done_quest"))  return 1;
        return 0;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_temp("weapon")&& !random(5))
                        {
                                command("wield all");
                                this_object()->smart_busy();
                        } else 
                        {       if (this_object()->query_temp("weapon"))
                                        command("say 好,我不用兵器!");
                                command("unwield all");
                                this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("blade.gobankiri");
}
smart_attack() {
        this_object()->perform_action("unarmed.shiden");        
}  
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        if(victim->query("id")=="tianfeng")
        {
            this_object()->remove_all_enemy();
            command ("say 好，先杀你!");
            return 0;
        } 
    }
    return 0;
}      
