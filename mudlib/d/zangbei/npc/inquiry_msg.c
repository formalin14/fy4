 mapping inquiry_msg = ([
        "陆漫天"                                : "陆漫天和易潜海，是老伯在中原的两大得力助手。",
        "易潜海"                                : "陆漫天和易潜海，是老伯在中原的两大得力助手。",
        "孙剑"                                  : "孙剑的名字本来是孙剑如，他是老伯唯一的儿子，也是他最忠实的部下。",
        "韩棠"                                  : "没有人知道韩棠的来历，只知道他每年会去拜见老伯一次。",
        "律相川"                                : "律相川年轻有为，据说老伯已经把他视为自己的儿子。",
        "菊花园"                                : "菊花园在二郎山中，是老伯居住的地方。",
        "快活林"                                : "快活林在雪山脚下，是高老大的地盘。",
        "老伯"                                  : "老伯就是孙玉伯，没有人真正知道他究竟是个怎么样的人？究竟能做什么事。",
        "孙玉伯"                                : "老伯就是孙玉伯，没有人真正知道他究竟是个怎么样的人？究竟能做什么事。",
        "高老大"                                : "高老大并不是大哥，是大姬，她是快活林的主人。 ",
        "叶翔"                                  : "叶翔是快活林高老大的手下，不过，他现在除了喝酒什么也不能干了。",
        "小何"                                  : "小何是快活林高老大的手下，他一直认为高老大是他一个人的老大。",
        "石群"                                  : "石群是快活林高老大的手下，他最近到西北办事去了。",
        "孟星魂"                                : "孟星魂是快活林高老大的手下，没有人知道他在哪里。",
]);  
string query_inquiry_msg(string arg) {
        string *msg;
        int i;  
        msg=keys(inquiry_msg);
        for (i=0;i<sizeof(msg);i++) 
                if (msg[i]==arg) return inquiry_msg[msg[i]];
        return 0;
}        
