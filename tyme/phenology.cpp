#include <string>
#include <map>
#include <optional>
#include <cmath>
#include <array>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "tyme.h"

using namespace std;

namespace tyme {
    const vector<string> ThreePhenology::NAMES = {
        "初候", "二候", "三候"
    };

    ThreePhenology ThreePhenology::from_index(const int index) {
        return ThreePhenology(index);
    }

    ThreePhenology ThreePhenology::from_name(const string &name) {
        return ThreePhenology(name);
    }

    ThreePhenology ThreePhenology::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> Phenology::NAMES = {
        "蚯蚓结", "麋角解", "水泉动", "雁北乡", "鹊始巢", "雉始雊", "鸡始乳", "征鸟厉疾", "水泽腹坚", "东风解冻", "蛰虫始振", "鱼陟负冰", "獭祭鱼", "候雁北", "草木萌动", "桃始华", "仓庚鸣", "鹰化为鸠", "玄鸟至", "雷乃发声", "始电", "桐始华", "田鼠化为鴽", "虹始见", "萍始生", "鸣鸠拂其羽", "戴胜降于桑", "蝼蝈鸣", "蚯蚓出", "王瓜生", "苦菜秀", "靡草死", "麦秋至", "螳螂生", "鵙始鸣", "反舌无声", "鹿角解", "蜩始鸣", "半夏生", "温风至", "蟋蟀居壁", "鹰始挚", "腐草为萤", "土润溽暑", "大雨行时", "凉风至", "白露降", "寒蝉鸣", "鹰乃祭鸟", "天地始肃", "禾乃登", "鸿雁来", "玄鸟归", "群鸟养羞", "雷始收声", "蛰虫坯户", "水始涸", "鸿雁来宾", "雀入大水为蛤", "菊有黄花", "豺乃祭兽", "草木黄落", "蛰虫咸俯", "水始冰", "地始冻", "雉入大水为蜃", "虹藏不见", "天气上升地气下降", "闭塞而成冬", "鹖鴠不鸣", "虎始交", "荔挺出"
    };

    Phenology Phenology::from_index(const int year, const int index) {
        return Phenology(year, index);
    }

    Phenology Phenology::from_name(const int year, const string &name) {
        return Phenology(year, name);
    }

    Phenology Phenology::next(const int n) const {
        const int size = get_size();
        const int i = index + n;
        return from_index((year * size + i) / size, index_of(i));
    }

    int Phenology::get_year() const {
        return year;
    }

    JulianDay Phenology::get_julian_day() const {
        const double t = ShouXingUtil::sa_lon_t((year - 2000 + (index - 18) * 5.0 / 360 + 1) * 2 * M_PI);
        return JulianDay::from_julian_day(t * 36525 + JulianDay::J2000 + 8.0 / 24 - ShouXingUtil::dt_t(t * 36525));
    }

    ThreePhenology Phenology::get_three_phenology() const {
        return ThreePhenology::from_index(index % 3);
    }

    Phenology PhenologyDay::get_phenology() const {
        return phenology;
    }

    int PhenologyDay::get_day_index() const {
        return day_index;
    }

    string PhenologyDay::get_name() const {
        return phenology.get_name();
    }

    string PhenologyDay::to_string() const {
        return phenology.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }
}
