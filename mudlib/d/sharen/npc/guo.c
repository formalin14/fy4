 // hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();
int give_jade();
void create()
{
        set_name("高老头", ({ "gao oldman" }) );
        set("gender", "男性" );
        set("age", 45);
        set("title","隐姓埋名");
        set("long",
                "一个上了年纪的老人家，笑容慈祥，满脸风霜。
他似乎在这里很久了，对这个暗道是那麽的熟悉。\n");
        set("force_factor", 100);
        set("combat_exp", 100000+random(10000000));
        set("attitude", "friendly");

        set_skill("force",100);
        set_skill("dodge",120);
        set_skill("perception",160);        
        set_skill("jingyiforce",200);        
        set_skill("blade",180);
        set_skill("springrain-blade",160);
        set_skill("chaos-steps",120);
        map_skill("force","jingyiforce");
        map_skill("dodge","chaos-steps");
        map_skill("blade","springrain-blade");

        set("chat_chance", 1);
        set("chat_msg", ({
                "高老头皱着眉头：“这盛药的药瓮用完了，该怎麽办啊。。。”\n"
                    }));
        set("skill_public", 1);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
        	                (: wieldblade  :),
        }) );
        set("inquiry", ([
                "先天无极门" : (: give_jade :),
        ]));
        setup();
        //carry_object(__DIR__"obj/birdbox");
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/armor/cloth")->wear(); 
} 

int accept_object(object me, object ob){
        if (ob->query("name") == "黑瓷药瓮" && ob->query("id") == "medvase" && !me->query("free_rain/med"))
		{
                message_vision("$N松了眉头，接过"+ob->query("name")+"：“多谢多谢，这样可以省了我不少麻烦了。”\n", this_object());
                message_vision("$N忽然敲了敲了头；“哎呀，这下药的天山雪莲还没找回来，怎麽办呢？”\n", this_object());        
                me->set("free_rain/med", 1);
                return 1;
		}

        if (ob->query("name") == HIC"天山雪莲"NOR && ob->query("id") == "snow lotus" && me->query("free_rain/med") && !me->query("free_rain/lotus"))
		{
                        message_vision("$N接过"+ob->query("name")+"仔细一看，大呼：“对对对，就是这个，好了，就缺块盐巴做药引子了。”\n", this_object());
						me->set("free_rain/lotus", 1);
                return 1;
		}

		if (ob->query("name") == "盐巴" && ob->query("id") == "salt rock" && me->query("free_rain/lotus") && !me->query("free_rain/ending"))
		{
                		message_vision(CYN"$N哈哈大笑：皇天不负有心人，你果然是我要找的人。为寻东郭，我大可指点你一二！”\n\n"NOR, this_object());

                        me->set("free_rain/ending",1);
                        me->add("combat_exp",20000);
						me->add("potential",1000);
						me->add("score",500);
                        tell_object(me,"你被奖励了：\n" + chinese_number(1000) + "点实战经验\n"
                        + chinese_number(200) + "点潜能\n" + chinese_number(500)+"点综合评价\n");
						return 1;
		}
        return 0;

} 
int recognize_apprentice(object ob){
    if(ob->query("free_rain/ending")) {
        return 1;
    } else {
        if (random(2))
        message_vision("$N摸了摸胡子：“只有天山雪莲才能让人起死回生。。。”\n", 
                        this_object());
        else 
        message_vision("$N拍了拍$n肩膀：“你知道麽，有时候一道药是需要药引子的，例如盐巴之类。”\n", 
                        this_object(), ob);             
                return 0;
    }
} 

int give_jade()
{
        object obj;
if( !query("given"))
        {
message_vision(CYN"$N惊叹道：“你这后辈竟然也知道这回事？俞老人若仍然在世……\n我这里有块当初他留下的记物，你小心保存，不要让姬家的人看见了。”\n"+"$N递给$n一块"+GRN"无极八卦玉佩"NOR+"。\n", this_object(),this_player());
obj = new(__DIR__"obj/jade");
obj->move(this_player());
set("given",1);
        }
else
command("say 你这后辈竟然也知道这回事？可惜先天无极门已是昨日黄花。。。\n");
        return 1;
} 
int wieldblade()
{
command("sigh");
perform_action("blade.dangshimingyue");
command("grin");
return 1;
}