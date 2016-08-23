 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name( "石门", ({ "door"  }) );
        set("unit", "扇");
        set("no_get",1);
        set("value",20);
        set("long","
这是一扇沉重的石门，门上有一个星状的缺口(Hole)。
\n");
        set_weight(5000);
        ::init_item();
} 
/*
void init()
{
        add_action("do_touch","move");
} 
int check_needles()
{
        object liver,kidney,stomach, heart, lung, env,*inv;
        object red,green,yellow, white,black;
        env = environment(this_object());
        
        if(!objectp(liver=present("green",env))) return 0;
        if(!objectp(kidney=present("kidney",env))) return 0;
        if(!objectp(stomach=present("stomach",env))) return 0;
        if(!objectp(heart=present("heart",env))) return 0;
                
        inv = all_inventory(liver);
        if( sizeof(inv) != 1) return 0;
        green = inv[0];
        if((string)green->query("name") != "绿玉") return 0;
        
        inv = all_inventory(kidney);
        if( sizeof(inv) != 1) return 0;
        black = inv[0];
        if((string)black->query("name") != "黑玉") return 0;
        
        inv = all_inventory(stomach);
        if( sizeof(inv) != 1) return 0;
        yellow= inv[0];
        if((string)yellow->query("name") != "黄玉") return 0;
        
        inv = all_inventory(heart);
        if( sizeof(inv) != 1) return 0;
        red= inv[0];
        if((string)red->query("name") != "红玉") return 0;
        
        
// now we have everything, let's open path! and reset this room;
        red->move(env); destruct(red);
        green->move(env); destruct(green);
        yellow->move(env); destruct(yellow);
        white->move(env); destruct(white);
        black->move(env); destruct(black);
        return 1;
} 
int do_touch(string arg)
{
        object me,env;
        if( !arg ) return 0;
        if( arg != "缺口" && arg != "hole") return 0;
        me = this_player();
        message_vision("$N运起内力向石门推去。\n",me);
        if (me->query("force")<500)
                return notify_fail("你的内力不够。\n");
        
        if(me->query("m_success/入恶人窟" || check_needles()) {
                if(!me->query("m_success/入恶人窟"))
                {
                        me->set("m_success/入恶人窟",1);
                        me->add("score",300);
                } 
                me->add("force",-500);
                env = environment(this_object());
                message("vision","石门嘎嘎地动了起来，露出了身后一个黑漆漆的入口。\n",env);
           message_vision("$N一纵身进了暗道，石门在$N身后又合上了。\n",me);
                me->move("/d/eren/cavein");
                return 1;
        }       else
                message_vision("石门吱吱地响了几下，纹丝不动。\n",me);
        return 1;
}
*/    
