 inherit ROOM;
void create()
{
        set("short", "���׷���");
        set("long", @LONG
����һ���ķ��˲�֪�����������ַ�������û�ں��ݺ������У����б�������
����һ����̳(Altar)�����������Ѿ���������Ϊ���ǵļң����ɽ����š�
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zues5",
]));
	set("objects", ([
		"/d/palace/npc/fish" : 1,
        	"/d/palace/npc/shrimp" : 1,
       		__DIR__"obj/altar" : 1,
       	]) );
       	set("item_desc", ([
//                "altar": "����һ������Ŵ�����ļ�̳�����ƺ�������������Ը��wish)��\n",
//                "��̳": "����һ������Ŵ�����ļ�̳�����ƺ�������������Ը��wish)��\n",
        ]) );
        
        set("indoors", "residence"); 
        set("coor/x",-20);
        set("coor/y",2040);
        set("coor/z",0);
        setup();
}
void init()
{
    add_action("do_wish", "wish");
}

int do_wish(){
        object me, room;
   	me = this_player();
        message_vision("$N������ĬĬ����һ��Ը��\n", me);
        room = find_object("/p/residence/zues3");
        if(!objectp(room)){
            room = load_object("/p/residence/zues3");
                }
                me->move("/p/residence/zues3");
        return 1;       
} 