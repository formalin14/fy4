 inherit NPC; 
void create()
{
        set_name("欧阳镖师", ({ "biaotou ouyang", "biaotou"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位金狮镖局的镖师。\n");
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        
        set("max_force",500);
        set("force",500);
        set("force_factor",30);
        
        switch (random(3)) {
                case 0: set("resistance/kee",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/sen",30);
                }
        
        set_skill("unarmed", 150);
        set_skill("changquan",200);
        set_skill("dodge", 150);
        set_skill("move",200);
        set_skill("parry",150);
        set_skill("puti-steps",150);
        
        map_skill("dodge","puti-steps");
        map_skill("unarmed","changquan");
        
        set("chat_chance", 1);
        set("chat_msg", ({
//                (: random_move :),
              "欧阳镖师打了个哈欠说，该睡觉了。\n",
        }) );
        
        setup();
        add_money("silver", 5);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        if (!random(2))
        carry_object(__DIR__"obj/hongbao"); 
} 
/*
int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place, my_birth_place;
        object env;
        
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        env = environment(this_object());
        to_go_place = env->query("exits/"+direction);
        my_birth_place = file_name(this_object());
        
        if (domain_file(to_go_place)!= domain_file(file_name(this_object()))){
                return 1;
        }
        message_vision("my birth place is "+domain_file(my_birth_place),this_object());
//      command("go " + direction);
        return 1;
}*/     