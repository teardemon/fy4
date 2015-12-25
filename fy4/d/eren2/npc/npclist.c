 inherit SKILL;
mapping *npctype = ({
        ([      
                "group":                "fighter_w",
                "npc":                  "diesword",
                "name":                 "蝶舞",
                "class":                "legend",
                "gender":               "女性",
                "skill_type_w":         "sword/diesword",
                "skill_type_u":         "qidaoforce",
                "u_adjust":             20,
                "skill_type_d":         "fall-steps",
                "d_adjust":             50,
                "unarmed":              "qidaoforce",
                "sword":                "diesword",
                "force":                "qidaoforce",
                "parry":                "diesword",
                "blade":                "shortsong-blade",
                "dodge":                "fall-steps",
                "others1":              "meihua-shou",
                "others2":              "enmeiryu",
                "others3":              "xisui",
                "others4":              "three-sword",
                "perform_weapon_attack":"legend/sword/diesword/caidiekuangwu",
                "perform_weapon_attack2":"legend/blade/shortsong-blade/duangechangmeng",
                "perform_unarmed_attack":"bat/unarmed/luoriquan/luori",
                "perform_unarmed_attack2":"ninja/unarmed/enmeiryu/mukuha",
                "perform_busy_d":       "legend/dodge/fall-steps/luoyeqiufeng",
                "perform_busy_u":       "legend/unarmed/meihua-shou/meihai",
                "perform_busy_w":       "wudang/sword/three-sword/nianzijue",
                "set_temp1":            "qidaoforce_juqi",           
        ]),  
        ([      
                "group":                "fighter_w",
                "npc":                  "shortsong-blade",
                "name":                 "秋风",
                "class":                "legend",
                "gender":               "男性",
                "skill_type_w":         "blade/shortsong-blade",
                "skill_type_u":         "qidaoforce",
               "skill_type_d":             "fall-steps",
                "d_adjust":             50,
                "unarmed":              "qidaoforce",
                "blade":                "shortsong-blade",
                "force":                "qidaoforce",
                "parry":                "shortsong-blade",
                "dodge":                "fall-steps",
                "others1":              "meihua-shou",
                "perform_weapon_attack":"legend/blade/shortsong-blade/duangechangmeng",
                "perform_busy_d":       "legend/dodge/fall-steps/luoyeqiufeng",
                "perform_busy_u":       "legend/unarmed/meihua-shou/meihai",
                "set_temp1":            "qidaoforce_juqi",           
        ]),  
        ([      
                "group":                "fighter_w",
                "npc":                  "feixian-sword",
                "name":                 "飞仙",
                "class":                "baiyun",
                "gender":               "男性",
                "skill_type_w":         "sword/feixian-sword",
                "skill_type_u":         "calligraphy",
                "skill_type_d":         "feixian-steps",
                "unarmed":              "calligraphy",
                "sword":                "feixian-sword",
                "force":                "painting",
                "parry":                "feixian-sword",
                "dodge":                "feixian-steps",
                "others1":              "chess",
                "others2":              "dabei-strike",
                "others3":              "music",
                "perform_weapon_attack":"baiyun/sword/feixian-sword/tianwaifeixian",
                "perform_busy_u":       "shaolin/unarmed/dabei-strike/qianshouqianbian",
        ]),  
        ([      
                "group":                "fighter_w",
                "npc":                  "shenji-blade",
                "name":                 "神机刀",
                "class":                "bat",
                "gender":               "男性",
                "skill_type_w":            "blade/shenji-blade",
                "skill_type_u":         "luoriquan",
                "skill_type_d":         "shenji-steps",
                "u_adjust":             50,
                "unarmed":              "luoriquan",
                "blade":                "shenji-blade",
                "parry":                "shenji-blade",
                "dodge":                "shenji-steps",
                "others1":              "enmeiryu",
                "perform_weapon_attack":"bat/blade/shenji-blade/jichulianhuan",
                "perform_weapon_attack2":"npc/blade/wind-blade/leitingpili",
                "perform_unarmed_attack":"bat/unarmed/luoriquan/luori",
                "perform_unarmed_attack2":"ninja/unarmed/enmeiryu/mukuha",
                "perform_busy_d":       "bat/dodge/shenji-steps/shenjimiaosuan",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "bat-blade",
                "name":                 "蝙蝠刀",
                "class":                "bat",
                "gender":               "男性",
                "skill_type_w":         "blade/bat-blade",
                "skill_type_u":         "luoriquan",
                "skill_type_d":         "meng-steps",
                "u_adjust":             50,
                "unarmed":              "luoriquan",
                "blade":                "bat-blade",
                "parry":                "bat-blade",
                "dodge":                "meng-steps",
                "others1":              "enmeiryu",
                "perform_weapon_attack":"bat/blade/bat-blade/shiwanshenmo",
                "perform_weapon_attack2":"npc/blade/wind-blade/leitingpili",
                "perform_unarmed_attack":"bat/unarmed/luoriquan/luori",
                "perform_unarmed_attack2":"ninja/unarmed/enmeiryu/mukuha",
                "perform_busy_d":       "bat/dodge/meng-steps/huanyinqianchong",
        ]), 
        ([    
                "group":                "fighter_w",
                "npc":                  "sharen-sword",
                "name":                    "杀人剑",
                "class":                "assassin",
                "gender":               "男性",
                "skill_type_w":         "sword/sharen-sword",
                "skill_type_u":         "flame-strike",
                "skill_type_d":         "jinhong-steps",
                "d_adjust":             50,
                "w_adjust":             20,
                "unarmed":              "flame-strike",
                "sword":                "sharen-sword",
                "force":                "jingxing",
                "parry":                "lefthand-sword",
                "dodge":                "jinhong-steps",
                "others1":              "lefthand-sword",
                "perform_weapon_attack":"assassin/sword/sharen-sword/sharenruma",
                "perform_busy_d":       "assassin/dodge/jinhong-steps/canglongzhaxian",
        ]),  
        ([      
                "group":                "fighter_w",
                "npc":                  "dagou-stick",
                "name":                 "天下无狗",
                "class":                "beggar",
                "gender":               "男性",
                "skill_type_w":         "staff/dagou-stick",
                "skill_type_u":         "dragonstrike",
                "u_adjust":             50,
                "skill_type_d":         "doggiesteps",
                "d_adjust":             100,
                "unarmed":              "dragonstrike",
                "staff":                "dagou-stick",
                "force":                "huntunforce",
                "parry":                "dagou-stick",
                "dodge":                "doggiesteps",
                "perform_weapon_attack":"beggar/staff/dagou-stick/tianxiawugou",
                "perform_unarmed_attack":"beggar/unarmed/dragonstrike/xianglongwuhui",
                "perform_busy_u":       "beggar/unarmed/dragonstrike/xianglongwuhui",
                "perform_busy_w":       "beggar/staff/dagou-stick/banzijue", 
        ]),  
        ([      
           "group":                "fighter_w",
                "npc":                  "yue-spear",
                "name":                 "无聊",
                "class":                "official",
                "gender":               "女性",
                "skill_type_w":         "spear/yue-spear",
                "skill_type_u":         "changquan",
                "u_adjust":             50,
                "skill_type_d":         "fall-steps",
                "d_adjust":             50,
                "unarmed":              "changquan",
                "spear":                "yue-spear",
                "force":                "manjianghong",
                "parry":                "yue-spear",
                "dodge":                "fall-steps",
                "others1":              "bloodystrike",
                "perform_weapon_attack":"official/spear/yue-spear/zonghengtianxia",
                "perform_unarmed_attack":"official/unarmed/changquan/yuhuan",
                "perform_busy_d":       "legend/dodge/fall-steps/luoyeqiufeng",
                "perform_busy_u":       "lama/unarmed/bloodystrike/fefawubian",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "yue-spear2",
                "name":                 "土土",
                "class":                "official",
                "gender":               "女性",
                "skill_type_w":         "spear/yue-spear",
                "skill_type_u":         "changquan",
                "u_adjust":             50,
                "skill_type_d":         "puti-steps",
                "d_adjust":             50,
                "unarmed":              "changquan",
                "spear":                "yue-spear",
                "force":                "manjianghong",
                "parry":                "yue-spear",
                "dodge":                "puti-steps",
                "others1":              "bloodystrike",
                "perform_weapon_attack":"official/spear/yue-spear/zonghengtianxia",
           "perform_unarmed_attack":"official/unarmed/changquan/yuhuan",
                "perform_busy_u":       "lama/unarmed/bloodystrike/fefawubian",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "taiji-sword",
                "name":                 "绵绵不绝",
                "class":                "wudang",
                "gender":               "女性",
                "skill_type_w":         "sword/taiji-sword",
                "skill_type_u":         "taiji",
                "w_adjust":             80,
                "skill_type_d":         "five-steps",
                "unarmed":              "taiji",
                "sword":                "taiji-sword",
                "force":                "taijiforce",
                "parry":                "taiji-sword",
                "dodge":                "five-steps",
                "perform_weapon_attack":        "wudang/sword/taiji-sword/chanzijue",        
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "nine-moon-sword",
                "name":                 "冰冻",
                "class":                "shenshui",
                "gender":               "女性",
                "skill_type_w":         "sword/nine-moon-sword",
                "skill_type_u":         "nine-moon-claw",
                "skill_type_d":         "nine-moon-steps",
                "d_adjust":             50,
                "w_adjust":             80,
                "unarmed":              "nine-moon-claw",
                "sword":                "nine-moon-sword",
                "force":                "nine-moon-force",
                "parry":                "qingpingsword",
                "dodge":                "nine-moon-steps",
                "others1":              "nine-moon-spirit",
                "others2":              "qingpingsword",
                "perform_weapon_attack":"shenshui/sword/nine-moon-sword/shuanglengcanxia",
           "perform_busy_d":       "shenshui/dodge/nine-moon-steps/lianhuanbu",
                "perform_busy_w":       "shenshui/sword/qingpingsword/fengzijue",
                "set_temp1":            "nine-moon-force_poison",           
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "nine-moon-sword2",
                "name":                 "冰冻二号",
                "class":                "shenshui",
                "gender":               "女性",
                "skill_type_w":         "sword/nine-moon-sword",
                "skill_type_u":         "nine-moon-claw",
                "skill_type_d":         "nine-moon-steps",
                "d_adjust":             50,
                "w_adjust":             80,
                "unarmed":              "nine-moon-claw",
                "sword":                "nine-moon-sword",
                "force":                "nine-moon-force",
                "parry":                "qingpingsword",
                "dodge":                "nine-moon-steps",
                "others1":              "nine-moon-spirit",
                "others2":              "qingpingsword",
                "perform_weapon_attack":"shenshui/sword/nine-moon-sword/shuanglengcanxia",
                "perform_busy_w":       "shenshui/sword/qingpingsword/fengzijue",
                "set_temp1":            "nine-moon-force_poison",           
        ]),         
        ([      
                "group":                "fighter_w",
                "npc":                  "longfenghuan",
                "name":                 "双飞燕",
                "class":                "assassin",
                "gender":               "女性",
                "skill_type_w":         "hammer/longfenghuan",
                "skill_type_u":         "flame-strike",
                "u_adjust":             20,
                "skill_type_d":         "jinhong-steps",
                "d_adjust":             50,
                "unarmed":              "flame-strike",
                "hammer":               "longfenghuan",
                "force":           "jingxing",
                "parry":                "longfenghuan",
                "dodge":                "jinhong-steps",
                "others1":              "meihua-shou",
                "perform_weapon_attack":"assassin/hammer/longfenghuan/longfengshuangfei",
                "perform_busy_u":       "legend/unarmed/meihua-shou/meihai",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "cloudstaff",
                "name":                 "浮云写意",
                "class":                "bonze",
                "gender":               "男性",
                "skill_type_w":         "staff/cloudstaff",
                "skill_type_u":         "dabei-strike",
                "skill_type_d":         "fengyu-piaoxiang",
                "d_adjust":             50,
                "unarmed":              "dabei-strike",
                "staff":                "cloudstaff",
                "force":                "lotusforce",
                "parry":                "cloudstaff",
                "dodge":                "fengyu-piaoxiang",
                "magic":                "essencemagic",
                "perform_weapon_attack":"bonze/staff/cloudstaff/longxianyuye",
                "perform_busy_d":       "bat/dodge/fengyu-piaoxiang/zonghengsihai",
                "perform_busy_u":       "bonze/unarmed/dabei-strike/qianshouqianbian",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "mind-sense",
                "name":                 "惊魂",
                "class":                "bonze",
                "gender":               "男性",
                "skill_type_w":         "staff/cloudstaff",
                "skill_type_u":         "dabei-strike",
                "skill_type_d":         "fengyu-piaoxiang",
                "d_adjust":             50,
                "unarmed":              "dabei-strike",
                "staff":                "cloudstaff",
                "force":           "lotusforce",
                "parry":                "cloudstaff",
                "dodge":                "fengyu-piaoxiang",
                "magic":                "essencemagic",
                "perform_weapon_attack":"bonze/staff/cloudstaff/npc_mind_sense",
                "perform_busy_d":       "bat/dodge/fengyu-piaoxiang/zonghengsihai",
                "perform_busy_u":       "bonze/unarmed/dabei-strike/qianshouqianbian",
      ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "doomsword",
                "name":                 "湘西一剑",
                "class":                "fighter",
                "gender":               "女性",
                "skill_type_w":         "sword/doomsword",
                "skill_type_u":         "doomstrike",
                "u_adjust":             30,
                "skill_type_d":         "doomsteps",
                "d_adjust":             30,
                "unarmed":              "doomstrike",
                "sword":                "doomsword",
                "force":                "doomforce",
                "parry":                "doomsword",
                "dodge":                "doomsteps",
                "others1":              "meihua-shou",
                "others2":              "dugu-sword",
                "perform_weapon_attack":"fighter/sword/doomsword/hunranyijian",
                "perform_weapon_attack2":"fighter/sword/dugu-sword/npc_sword_poqi",
                "perform_unarmed_attack":"fighter/unarmed/doomstrike/hantian",
//              "perform_busy_u":       "legend/unarmed/meihua-shou/meihai",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "softsword",
                "name":                 "剑痴",
                "class":                "swordsman",
                "gender":               "女性",
                "skill_type_w":         "sword/softsword",
                "skill_type_u":         "dabei-strike",
                "u_adjust":                20,
                "skill_type_d":         "shadowsteps",
                "d_adjust":             50,
                "unarmed":              "dabei-strike",
                "sword":                "softsword",
                "force":                "cloudforce",
                "iron-cloth":           "xisui",
                "parry":                "softsword",
                "dodge":                "shadowsteps",
                "others1":              "dugu-sword",
                "perform_weapon_attack":"swordsman/sword/softsword/npc_sword_muyu",
                "perform_weapon_attack2":"swordsman/sword/softsword/changtianluodian",
                "perform_weapon_attack3":"swordsman/sword/dugu-sword/npc_sword_poqi",
                "perform_busy_u":       "shaolin/unarmed/dabei-strike/qianshouqianbian",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "xuezhan-spear",
                "name":                 "血枪",
                "class":                "fugui",
                "gender":               "男性",
                "skill_type_w":         "spear/xuezhan-spear",
                "skill_type_u":         "eagle-claw",
                "u_adjust":             50,
                "w_adjust":             -20,
                "skill_type_d":         "hawk-steps",
                "unarmed":              "eagle-claw",
                "spear":                "xuezhan-spear",
                "force":                "skyforce",
                "parry":                "xuezhan-spear",
                "dodge":                "hawk-steps",
                "iron-cloth":           "henglian",
                "others1":              "yue-spear",
                "others2":              "manjianghong",
                "perform_weapon_attack":"fugui/spear/xuezhan-spear/yutianbigao",
                "perform_weapon_attack2":"fugui/spear/xuezhan-spear/bafangfengyu",
                "perform_weapon_attack3":"official/spear/yue-spear/zonghengtianxia",
                "perform_busy_d":       "fugui/dodge/hawk-steps/yingjichangkong",
        ]),         
   ([      
                "group":                "fighter_w",
                "npc":                  "liuquan-steps",
                "name":                 "流泉",
                "class":                "huangshan",
                "gender":               "女性",
                "skill_type_w":         "sword/siqi-sword",
                "skill_type_u":         "yunwu-strike",
                "skill_type_d":         "liuquan-steps",
                "unarmed":              "yunwu-strike",
                "sword":                "siqi-sword",
                "force":                "xianjing",
                "parry":                "siqi-sword",
                "dodge":                "liuquan-steps",
                "perform_busy_d":       "huangshan/dodge/liuquan-steps/liushuichanchan",
                "perform_busy_u":       "huangshan/unarmed/yunwu-strike/miwu",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "siqi-sword",
                "name":                 "四奇",
                "class":                "huangshan",
                "gender":               "女性",
                "skill_type_w":         "sword/siqi-sword",
                "skill_type_u":         "yunwu-strike",
                "skill_type_d":         "liuquan-steps",
                "unarmed":              "yunwu-strike",
                "sword":                "siqi-sword",
                "force":                "xianjing",
                "parry":                "siqi-sword",
                "dodge":                "liuquan-steps",
                "perform_weapon_attack":"huangshan/sword/siqi-sword/siqi",
                "perform_busy_u":       "huangshan/unarmed/yunwu-strike/miwu",     
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "qiusheng-blade",
                "name":                 "秋声",
                "class":                "huangshan",
                "gender":          "男性",
                "skill_type_w":         "blade/qiusheng-blade",
                "skill_type_u":         "yunwu-strike",
                "skill_type_d":         "liuquan-steps",
                "unarmed":              "yunwu-strike",
                "blade":                "qiusheng-blade",
                "force":                "xianjing",
                "parry":                "qiusheng-blade",
                "dodge":                "liuquan-steps",
                "perform_weapon_attack":"huangshan/blade/qiusheng-blade/jingsheng",
                "perform_busy_u":       "huangshan/unarmed/yunwu-strike/miwu",     
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "qingfeng-sword",
                "name":                 "清风",
                "class":                "huashan",
                "gender":               "女性",
                "skill_type_w":         "sword/qingfeng-sword",
                "skill_type_u":         "zhaixin-claw",
                "skill_type_d":         "cloud-dance",
                "unarmed":              "zhaixin-claw",
                "sword":                "qingfeng-sword",
                "force":                "hanmei-force",
                "parry":                "qingfeng-sword",
                "dodge":                "cloud-dance",
                "iron-cloth":           "spring-water",
                "others1":              "dugu-sword",
                "perform_weapon_attack":"huashan/sword/dugu-sword/npc_sword_poqi",
                "perform_busy_d":       "huashan/dodge/cloud-dance/yexuechuji",
        ]), 
        ([      
                "group":                "fighter_w",
                "npc":                  "tanzhi-shentong",
                "name":                 "千手观音",
                "class":                "huashan",
                "gender":               "女性",
                "skill_type_w":         "throwing/tanzhi-shentong",
                "skill_type_u":         "zhaixin-claw",
                "skill_type_d":            "cloud-dance",
                "unarmed":              "zhaixin-claw",
                "sword":                "qingfeng-sword",
                "force":                "hanmei-force",
                "parry":                "qingfeng-sword",
                "dodge":                "cloud-dance",
                "throwing":             "tanzhi-shentong",
                "iron-cloth":           "spring-water",
                "others1":              "dugu-sword",
                "perform_weapon_attack":"huashan/throwing/tanzhi-shentong/mantianhuayu",
                "perform_busy_d":       "huashan/dodge/cloud-dance/yexuechuji",
        ]),         
        ([      
                "group":                "fighter_w",
                "npc":                  "xuanyuan-axe",
                "name":                 "霹雳斧",
                "class":                "knight",
                "gender":               "男性",
                "skill_type_w":         "axe/xuanyuan-axe",
                "skill_type_u":         "hanshan-strike",
                "u_adjust":             100,
                "skill_type_d":         "windy-steps",
                "unarmed":              "hanshan-strike",
                "axe":                  "xuanyuan-axe",
                "force":                "longlife-force",
                "parry":                "xuanyuan-axe",
                "dodge":                "windy-steps",
                "perform_weapon_attack":"knight/axe/xuanyuan-axe/guifushengong",
                "perform_weapon_attack2":"knight/axe/xuanyuan-axe/jiuqipoxiao",
                "perform_unarmed_attack":"knight/unarmed/hanshan-strike/zhangjian",
                "perform_busy_d":       "knight/dodge/windy-steps/fengliu",
        ]),  
});  
mapping query_npc(string group_name, string npc_name, int special){
        
        int total,i,x,n;
        string npc;
        
        total=sizeof(npctype);
   n=1;
        
        if (npc_name=="random") {
                if (group_name=="random") x=random(total);
                else while(n) {
                        x=random(total);
                        if (npctype[x]["group"]==group_name) n=0;
                        }
        } else {
                for (i=0;i<total;i++) {
                        if (npctype[i]["npc"]==npc_name) {
                                x=i; break;             
                        }
                } 
        }       
        return npctype[x];
}   
