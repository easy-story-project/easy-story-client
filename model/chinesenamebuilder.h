#ifndef CHINESENAMEBUILDER_H
#define CHINESENAMEBUILDER_H

#include <QObject>
#include <QVector>
#include <QMap>

class ChineseNameBuilder : public QObject
{
    Q_OBJECT

public:
    explicit ChineseNameBuilder(bool singleX, bool singleName);

    const QString build();

signals:

public slots:

private:
    bool singleXing;
    bool singleName;

    QMap<QString, QString> doubleWordName[2];

    const QString NAMES[2] = {"伟勇军磊涛斌强鹏杰峰超波辉刚健明亮俊飞凯浩华平鑫毅林洋宇敏宁建兵旭雷锋彬龙翔阳剑东博威海巍晨炜帅岩江松文云力成琦进昊\
宏欣坤冰锐震楠佳忠庆杨新骏君栋青帆静荣立虎哲晖玮瑞光钢丹坚振晓祥良春晶猛星政智琪永迪冬琳胜康彪乐诚志维卫睿捷群森洪扬科奇铭航利鸣恒源聪凡颖欢昕武雄洁川清义\
滨皓达民跃越兴正靖曦璐挺淼泉程韬冲硕远昆瑜晔煜红权征雨野慧萌山丰珂彤悦朋钧彦然枫嘉峥寅烨铮卓畅钊金可昱爽盛路晋谦克方闯耀奎一晟勤豪安尧全琛腾队鸿玉泽凌渊蕾\
广顺莹英峻攀宾驰燕霖喆椒国恺潇琨轶芳吉亚梁焱侃臻嵩岳炯艳宝岗斐啸元辰萍柯羽培通天麟晗菲雪铁贺钰戈灿琼锦生原洲炎丽勋奕艺中德轩京标旺南黎禹莉蔚总益祺骥沛汉真\
非鹤升蒙城钦锴骁壮罡键瑶虹石展翼为灏玲放娜露赞娟倩懿劲婷策魁霄冉敬卿均治迅臣桦镇骞河希瑾鹰舟丁涵弘纲泳理福俭乾纯双屹涌根怡果田岭昭飚勃嵘熙贤申琰宽鼎滔昌璞\
逸贵喜昂柳韶瑛伦茂景柱岚实珏霞园学惠衡风玺赫桐寒圣陈旋礼霆月侠密堃富薇仁浪津垒齐炼瀚泓灵朝夏严意银璇鲲易行品垄靓苏澄赛思旗淳雯继友和革延能菁叶隽烽昶笑裕鲁\
铎昀骅高翀润熠锟望卡微拓名秋冶雁开定想舒庚蓉牧重孟澎信郁珉钟盼恩周潮季烈魏奔承玎来桥尚增婧茜前琴麒竞童舜会柏冠佩游珊融满添咏响珩杉韧梅乔同梦树杭念遥苗胤榕\
耿崇湘里疆旻启烁楷才仲隆媛晴章舰璟桔李影亭珺言笛弛营宪渝发逊运豹翊研登炳蕊鉴妍焰颂闻桢镭特曙盟贝千保功竹印玥夭冀阔圆湛澍争众肖祯默珍煌余准忱宸普韦舸创芸彭\
泰心廷其业水焕炬韵裙干唯轲陆陶将骋战歆朔耕崴操幸向葵潜凤兰仪沙胡璋秦珑朗举列蓓纬垚歌献或见多谊迎州声婕栩男衍洵犇颢照辛有育甲禄起淮弋坦量楚熹劫勉典诺溪显毓\
稳甫羿端旦焘辑宣宙岑存迁万煦渤沁甜日翰淦劼庭徽豫锬铸蚵也好颉雍怀北西耘秀肠玄令蓬联斯霁朕箭坡澜馨瀛港岱宗闽励飙琥谷异嵬垣年尉习格锨桑讳丛淞领深赢宜律朴龚卉\
化陵庄财墨直煊欧棋孝子弢冕傲劭丞如燃铖畏崧汀弦墩溢崎容锁韩曼汽地芬上佶连郑兆纪盾相翌盈慰戟植晏任农",
                              "静敏燕艳丽娟莉芳萍玲娜丹洁红颖琳霞婷慧莹晶华倩英佳梅雪蕾琴璐伟云蓉青薇欣琼宁平媛虹杰婧雯茜楠洋君辉菲琦妍阳波俊鑫磊军\
爽兰晨冰瑶瑾岩瑛悦群玮欢瑜蕊宇明珊涛荣超琪玉怡文岚杨婕旭凤健芬芸晓萌飞露菁惠宏瑞蓓林璇珍月利勤清帆迪微斌娇影巍朋莎彬峰昕乐星新烨晖卉晴曼越靖维晔艺睿芹淼黎\
畅椒鹏春彦柳梦毅博妮坤翠然钰蔚曦茹凌扬凡美彤园炜捷亮雁叶苗菊勇锐雨力翔庆方琰聪潇威甜帅进琛花雅立姣馨珏秀亚珂思哲冉骊双娅胡培斐嘉莲莺佩剑娴玥真凯裙源奕靓侠\
枫洪姝敬希锦姗昱卓建兵冬强卫香焱容鸣硕浩纯韵玫婵巧笑俐羽舒盼涵峥雷可会航懿晗铭滢盈鸿茵灿程灵征金琨江贞路东煜圆贺一苹秋鹤珺南榕桦轶昊夏迎光智臻恒景吉银铮成\
松娣锋旋辰远樱糊坚苏喆沁霜霖皓刚晋田筠珠元湘嫣卿蒙京泓媚跃隽泉赛弘妹婉原环攀澜鹰音昆冲川芝娥贤昀野奇歌鸽竹璟苑诚滨萱霄嵘沙念汉岑桃骏谦安寅贝钦熙幸科如沛意\
果寒政柯芮鹃心海焕荔逸津渊尧天震瓤溪炎研颜赞营兴郑瑗益韶密歆易舟菡风笛龙爱民唯乔丰康渝驰葡祯郁蕴延俏恬毓腾杉岭诺峻缨永玎恋杏斯义俭漫正森丛漪昭硼蕙亭理铃咏\
岳桐璞非祺放炯焰葵依彩蝶筱戈苓为蔷展良想志总耘淳泽好妤妙翼羚竞品伶伊子烁鸥仙净格山忠肖麟默齐润淑轩蔓葳皎西绮沫桢童言禹涓严韬映赫翎玺霏达宜钧蜜泳纳忱熠振碧\
素珉情荟侃谊忆屹知旻珩秦飒赢或鹭霓韦桔荷吟仪励栋多炼嫒澄诗苇胜男艾习弦茗育曝石翊频蓝遥丁谨屏囡优顺鹂盟晏讳宾旎满游季楚俪凝劲礼曾眉盛颧衡辛融骅啸氛杭李娉萃\
芊朗痴耀克余响闻浪墩钥祥望朦嫚宝全芯陈洲行钊昂学栩仁咪连千冶旖姬晟肠稳霁恺桂茂台闽宪迅书勉霆革箐砚端旦蝴颂垄垚桥溢骞裕玄粼颍颉殷胤妲菱也典均缘梓旗煦赉飚灏\
郡玢键朝豫朔钢肪瑕勋刘前荃运嫱嵩牧来娓陶琚武雄筝恩堃单含绚淋添日殉孟尚照朵姿妃暖衍矫麒实骁信茉郦劫汀瀛猛城争芄勃喜女引获簧申韧晰禾翻醒鲲魏徽闪伦业尔熹戎桑\
绷冠颇白韫璜珑颢颐策虎联翀弛汇拉忻愉尤欧纬骥喻劼予翌繁珣慈豪彧允队令若洵汝娆权枚惟国滔奎尉夭闯俞鲁"};

    const QString XINGS[2] = {"欧阳,上官,皇甫,司徒,令狐,诸葛,司马,宇文,申屠,南宫,夏侯",
                              "王,李,张,刘,陈,杨,黄,吴,赵,周,徐,孙,马,朱,胡,林,郭,何,高,罗,郑,梁,谢,宋,唐,许,邓,冯,韩,曹,\
    曾,彭,萧,蔡,潘,田,董,袁,于,余,叶,蒋,杜,苏,魏,程,吕,丁,沈,任,姚,卢,傅,钟,姜,崔,谭,廖,范,汪,陆,金,石,戴,贾,韦,夏,邱,方,侯,邹,熊,孟,秦,白,江,阎,薛,尹,段,\
    雷,黎,史,龙,陶,贺,顾,毛,郝,龚,邵,万,钱,严,赖,覃,洪,武,莫,孔,汤,向,常,温,康,施,文,牛,樊,葛,邢,安,齐,易,乔,伍,庞,颜,倪,庄,聂,章,鲁,岳,翟,殷,詹,申,欧,耿,\
    关,兰,焦,俞,左,柳,甘,祝,包,宁,尚,符,舒,阮,柯,纪,梅,童,凌,毕,单,季,裴,霍,涂,成,苗,谷,盛,曲,翁,冉,骆,蓝,路,游,辛,靳,管,柴,蒙,鲍,华,喻,祁,蒲,房,滕,屈,\
    饶,解,牟,艾,尤,阳,时,穆,农,司,卓,古,吉,缪,简,车,项,连,芦,麦,褚,娄,窦,戚,岑,景,党,宫,费,卜,冷,晏,席,卫,米,柏,宗,瞿,桂,全,佟,应,臧,闵,苟,邬,边,卞,姬,师,\
    和,仇,栾,隋,商,刁,沙,荣,巫,寇,桑,郎,甄,丛,仲,虞,敖,巩,明,佘,池,查,麻,苑,迟,邝,官,封,谈,匡,鞠,惠,荆,乐,冀,郁,胥,南,班,储,原,栗,燕,楚,鄢,劳,谌,奚,皮,粟,\
    冼,蔺,楼,盘,满,闻,位,厉,伊,仝,区,郜,海,阚,花,权,强,帅,屠,豆,朴,盖,练,廉,禹,井,祖,漆,巴,丰,支,卿,国,狄,平,计,索,宣,晋,相,初,门,云,容,敬,来,扈,晁,芮,都,\
    普,阙,浦,戈,伏,鹿,薄,邸,雍,辜,羊,阿,乌,母,裘,亓,修,邰,赫,杭,况,那,宿,鲜,印,逯,隆,茹,诸,战,慕,危,玉,银,亢,嵇,公,哈,湛,宾,戎,勾,茅,利,於,呼,居,揭,干,但,\
    尉,冶,斯,元,束,檀,衣,信,展,阴,昝,智,幸,奉,植,衡,富,尧,闭,由"};
};

#endif // CHINESENAMEBUILDER_H