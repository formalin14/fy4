 inherit ROOM;
void create()
{
        set("short", "Ʈ�㻨��");
        set("long", @LONG
��������ô���꣬�����ƺ�һ�㶼û�иı䣬�����������ϡ�δ��˴�������
�Ļ�����������Ƣ�����и���������������Ŀ�������������֡����Ͳ��ָߵ͹����
�������������Ц����ӭ��������е������˶�ϲ�����������������һ���һ���
�ή�������ϡ���������ϰ�˵����Ʈ�㻨���ɵ���Ե�Ѳ���ʤ�������ſں�ֽ
�����Ÿ�ʾ��������
LONG
        );
        set("exits", ([
                "west" : __DIR__"nwind2",
        ]));
        set("objects", ([
                __DIR__"npc/flowerseller": 1,
        ]) );
        set("item_desc", ([
                "sign": @TEXT
             �ع���𣚣�ں�֮�ޡ�
             ����Ů�����Ӻ��ϡ�
�������ɸ����ݹˣ�������¡����ȱ���������ͻ����أ� 
delivery     ���������У��ͻ���ָ����ͣ���������
             ��Ԥ������һ����
deposit      ��ɸô��ͻ��󣬿������������ѯ��ȡ
             �ض���ask huaman about deposit��
cancel       ���������ԭ���޷���ɽ���֮�𣬿�ȡ
             ���������cancel delivery)��
TEXT
        ]) );
        set("no_fight",1);
        set("no_magic",1);
        set("NONPC", 1);
        set("coor/x",1);
        set("coor/y",20);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}      