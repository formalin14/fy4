#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "�鱦��",
                "quest_type":           "ɱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "�������",
                "quest_type":           "Ѱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "����ս��",
                "quest_type":           "Ѱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                HIR"��ӧ"NOR + "��ǹ"NOR,
                "quest_type":           "Ѱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "�λ���ʦ",
                "quest_type":           "ɱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "�һ�����",
                "quest_type":           "ɱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                HIW"����"NOR,
                "quest_type":           "ɱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "��ȱ���º� ",
                "quest_type":           "Ѱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "�ؽ�뿪����ɴ˿��",
                "quest_type":           "Ѱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            75,
        ]),
        ([      "quest":                "����Ѫ�ĺڲ���",
                "quest_type":           "Ѱ",
                "exp_bonus":            75,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}       
