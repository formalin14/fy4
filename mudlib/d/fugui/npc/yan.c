#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("燕七", ({ "yan qi", "yan" }) );
        set("long",
         "燕七的脸很秀气，甚至有点像小姑娘脸，大大的眼睛，小小的嘴，\n笑起来的时候还有两个酒窝；但不笑的时候，他的脸立即就变得冷冰\n冰，脸色也白的发青，几乎令人有点不敢亲近。\n");
        set("attitude", "heroism");
        create_family("富贵山庄",7,"副庄主");
    set("gender","女性");
        set("age",24);
        set("str", 36);
        set("cor", 50);
        set("cps", 25);
        set("agi",40);
        set("int",40);
        set("per",40);
        set("class","legend");
        
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 50);
        set("chat_chance",1);
        set("chat_msg", ({
        "燕七跺着脚，恨恨得道：“那该千刀的呆子，这时候却犯什么牛脾气啊，......\n\n哎，如果拿不到赤练蛇的解药，这...这...该如何是好呀？”\n",
                                })  );
        set("inquiry",  ([
            "郭大路" : "那头又蠢又瞎又笨又白痴的犟牛，真把人气死不可。\n",
            "林太平" : "林兄弟中了赤练蛇的赤练蛇毒，如果没解药，这.....哎...\n",
            "王动" : "看得出王大哥还是很喜欢红娘子的，得想个法撮合撮合他们才是。\n",
                ])                      ); 
        set("chat_chance_combat", 85);
        set("chat_msg_combat", ({
                (: perform_action, "sword.caidiekuangwu" :),
                (: perform_action, "dodge.luoyeqiufeng" :),
        }) );
        set("combat_exp", 2400000); 
        set_skill("unarmed", 160);
        set_skill("force",100);
        set_skill("parry",180);
        set_skill("dodge", 140);
        set_skill("move",200);
        set_skill("sword",140);
        set_skill("diesword",120);
        set_skill("fall-steps",150);
        set_skill("qidaoforce",100);
        set_skill("literate",100);
        
        map_skill("unarmed","qidaoforce");     
        map_skill("sword","diesword");
        map_skill("dodge","fall-steps");
        map_skill("force","qidaoforce");
        map_skill("parry","diesword");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
void init()
{
        ::init();
       add_action("do_look","look");
} 
int do_look(string arg)
{ 
        if (arg == "yan" || arg == "yan qi")
        {
                write("燕七的脸很秀气，甚至有点像小姑娘脸，大大的眼睛，\n");
                write("小小的嘴，笑起来的时候还有两个酒窝；但不笑的时候，\n");
                write("他的脸立即就变得冷冰冰，脸色也白的发青，几乎令人有点不敢亲近。\n");
                write("他看起来约二十多岁。\n");
                write("武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。\n");
                write("他"+HIG "精神饱满，正处于巅峰状态。"NOR+"\n");
                write("他身上带著：\n");
                write("  "+HIC "√"NOR+"布衣(Cloth)\n");
                write("  "+HIC "√"NOR+"长剑(Sword)\n");
                return 1;
        }
        return 0;
} 
int accept_object(object me, object ob)
{
        object lin;
        if(ob->query("name") == "青瓷瓶" && ob->query("liquid/name")=="解药")
        {
                me->set_temp("marks/青瓷瓶",1);
                me->start_busy(3);
                if (lin=present("lin taiping",environment(this_object()))) {
                        message_vision("燕七扶起林太平，将解药缓缓倒入林太平口中.......\n\n",me);
                        message_vision(RED"$N“哇”的一声吐出一大口黑血，脸上逐渐有了些血色。。\n\n"NOR, lin); 
                        if(!me->query("m_success/义救林太平")){
                    command("touch " + me->query("id"));
                                command("say 这位" + RANK_D->query_respect(me)+ "，大恩不言谢，只要你愿意，你可以找我王大哥学艺了！\n");
                                me->set("m_success/义救林太平",1);
                                me->add("score",500);
                }
                        if(!me->query("imbue/lin")) {
                                lin->imbue_event(me);
                        }
            } else {
                        command("say 多谢这位" + RANK_D->query_respect(me)+ "的解药，你可以找我王大哥学艺了！\n");
                }
                return 1;
        }
        else
                tell_object(me,"燕七说道：这不是我想要的。\n");
                return 0;      
}
