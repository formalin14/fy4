#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "�ڹ�",
                "quest_type":           "ɱ",
                "time":                 840,
                "exp_bonus":            55,
        ]),
        ([      "quest":                "ͭǮ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "���Ѹ�",
                "quest_type":           "ɱ",
                "time":                 840,
                "exp_bonus":            55,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "���ɮ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��ɮ",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "�Ϸ�",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��ɫ�̷�",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "���Ƹ�",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��ɫ�̷�",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            45,
        ]),
        ([      "quest":                "����ʫ��",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "ѩ����֬��",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "ţƤ����",
                "quest_type":           "Ѱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            45,
        ]),
        ([      "quest":                "ɮ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            45,
        ]),
        ([      "quest":                "½�崨",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "��ɫׯ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����ī��",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "��Ǯ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����������",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "��ɫ��װ",
                "quest_type":           "Ѱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "��Ʊ",
                "quest_type":           "Ѱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 840,
                "exp_bonus":            45,
        ]),
        ([      "quest":                "�ڹھ���",
                "quest_type":           "ɱ",
                "time":                 840,
                "exp_bonus":            50,
        ]),
        ([      "quest":                "���ο�",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "���ο�",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "��ɧ����",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]), 
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}    
