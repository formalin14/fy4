 inherit ROOM;
int check_container(object ob);
void create()
{
    set("short", "千金楼外");
    set("long", @LONG
此楼虽不在京都，但却是中原最有名的青楼。这里有最贵的酒，也是最好的酒；
这里有最贵的女人，也是最有味儿的女人；这里有最贵的服务，也是最好的服务。
朱红大门上牌（ｓｉｇｎ）一块，又高悬一块御赐金匾：
                        春色无边
LONG
    );
    set("exits", ([
        "east" : AREA_FY"swind4",
        "west" : __DIR__"pingfeng",
        ]));
    set("item_desc", ([
        "sign": @TEXT
千金楼楼规：
１．不可夹带任何兵器入楼。
２．以防您被千金楼小姐误认为没有消费能力，
　　不可夹带任何食物，酒水入楼。
３．大家出门在外是朋友，相互给点面子，
　　打架，闹事者楼规处置。
４．＂赏头＂给得越多，您受的伺侯越好。
TEXT
        ]) );
    
    set("outdoors","fengyun");
    set("NONPC",1);
    set("objects", ([
        __DIR__"npc/guinu" : 2,
        ]) );
    set("coor/x",-10);
    set("coor/y",-40);
    set("coor/z",0);
    set("coor/x",-10);
    set("coor/y",-40);
    set("coor/z",0);
    setup();
}
        
int valid_leave(object me, string dir)
{
    object *inv, ob;
    int i, dayPhase;
    
    if(dir == "west") {
            if(!ob = present("guinu",this_object())) {
                ob = new(__DIR__"npc/guinu");
                if(ob) {
                        ob->move(this_object());
                        message_vision("一个龟奴从千金楼里迎了出来。\n", me);
                }       
            }
            dayPhase = NATURE_D->get_current_day_phase();
        if(dayPhase > 0 && dayPhase < 6) {
                message_vision("龟奴望望天，对$N笑着说：时辰尚早，姑娘们还在睡，您．．．\n", me);
                return notify_fail("忍耐一下吧！\n");
        }
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if(((int)inv[i]->query("weapon_prop")) ||
                                        ((int)inv[i]->query("food_remaining") != 0) ||
                                        ((int)inv[i]->query("liquid/remaining") !=0) ||
                                        ((int)inv[i]->is_container()))
                        return notify_fail("龟奴向你笑道：千金楼有千金楼的楼规，您请看牌．\n");
                }
                me->set("food",0);
                me->set("water",0);
        }
    return 1;
}   
