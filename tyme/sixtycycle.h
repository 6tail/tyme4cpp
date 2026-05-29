#ifndef TYME_SIXTYCYCLE_H
#define TYME_SIXTYCYCLE_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 天干（天元）
     */
    class HeavenStem : public LoopTyme {
    public:
        ~HeavenStem() override = default;

        static const vector<string> NAMES;

        explicit HeavenStem(const int index) : LoopTyme(NAMES, index) {
        }

        explicit HeavenStem(const string &name) : LoopTyme(NAMES, name) {
        }

        static HeavenStem from_index(int index);

        static HeavenStem from_name(const string &name);

        HeavenStem next(int n) const;

        /**
         * @brief 五行
         * @return 五行
         */
        Element get_element() const;

        /**
         * @brief 阴阳
         * @return 阴阳
         */
        YinYang get_yin_yang() const;

        /**
         * @brief 十神（生我者，正印偏印。我生者，伤官食神。克我者，正官七杀。我克者，正财偏财。同我者，劫财比肩。）
         * @param target 天干
         * @return 十神
         */
        TenStar get_ten_star(const HeavenStem &target) const;

        /**
         * @brief 方位
         * @return 方位
         */
        Direction get_direction() const;

        /**
         * @brief 喜神方位（《喜神方位歌》甲己在艮乙庚乾，丙辛坤位喜神安。丁壬只在离宫坐，戊癸原在在巽间。）
         * @return 方位
         */
        Direction get_joy_direction() const;

        /**
         * @brief 阳贵神方位（《阳贵神歌》甲戊坤艮位，乙己是坤坎，庚辛居离艮，丙丁兑与乾，震巽属何日，壬癸贵神安。）
         * @return 方位
         */
        Direction get_yang_direction() const;

        /**
         * @brief 阴贵神方位（《阴贵神歌》甲戊见牛羊，乙己鼠猴乡，丙丁猪鸡位，壬癸蛇兔藏，庚辛逢虎马，此是贵神方。）
         * @return 方位
         */
        Direction get_yin_direction() const;

        /**
         * @brief 财神方位（《财神方位歌》甲乙东北是财神，丙丁向在西南寻，戊己正北坐方位，庚辛正东去安身，壬癸原来正南坐，便是财神方位真。）
         * @return 方位
         */
        Direction get_wealth_direction() const;

        /**
         * @brief 福神方位（《福神方位歌》甲乙东南是福神，丙丁正东是堪宜，戊北己南庚辛坤，壬在乾方癸在西。）
         * @return 方位
         */
        Direction get_mascot_direction() const;

        /**
         * @brief 天干彭祖百忌
         * @return 天干彭祖百忌
         */
        PengZuHeavenStem get_peng_zu_heaven_stem() const;

        /**
         * @brief 地势(长生十二神)
         * @param earth_branch 地支
         * @return 地势(长生十二神)
         */
        Terrain get_terrain(const EarthBranch &earth_branch) const;

        /**
         * @brief 五合（甲己合，乙庚合，丙辛合，丁壬合，戊癸合）
         * @return 天干
         */
        HeavenStem get_combine() const;

        /**
         * @brief 合化（甲己合化土，乙庚合化金，丙辛合化水，丁壬合化木，戊癸合化火）
         * @param target 天干
         * @return 五行，如果无法合化，返回nullopt
         */
        optional<Element> combine(const HeavenStem &target) const;

        bool equals(const HeavenStem &other) const;
    };

    /**
     * @brief 藏干（即人元，司令取天干，分野取天干的五行）
     */
    class HideHeavenStem : public AbstractCulture {
    public:
        ~HideHeavenStem() override = default;

        string get_name() const override;

        explicit HideHeavenStem(const HeavenStem &heaven_stem, const HideHeavenStemType type) : heaven_stem(heaven_stem), type(type) {
        }

        explicit HideHeavenStem(const string &heaven_stem_name, const HideHeavenStemType type) : heaven_stem(HeavenStem::from_name(heaven_stem_name)), type(type) {
        }

        explicit HideHeavenStem(const int heaven_stem_index, const HideHeavenStemType type) : heaven_stem(HeavenStem::from_index(heaven_stem_index)), type(type) {
        }

        /**
         * @brief 天干
         * @return 天干
         */
        HeavenStem get_heaven_stem() const;

        /**
         * @brief 藏干类型
         * @return 藏干类型
         */
        HideHeavenStemType get_type() const;

    protected:
        /**
         * @brief 天干
         */
        HeavenStem heaven_stem;

        /**
         * @brief 藏干类型
         */
        HideHeavenStemType type;
    };

    /**
     * @brief 人元司令分野（地支藏干+天索引）
     */
    class HideHeavenStemDay : public AbstractCulture {
    public:
        ~HideHeavenStemDay() override = default;

        explicit HideHeavenStemDay(const HideHeavenStem &hide_heaven_stem, const int day_index) : hide_heaven_stem(hide_heaven_stem), day_index(day_index) {
        }

        HideHeavenStem get_hide_heaven_stem() const;

        int get_day_index() const;

        string to_string() const override;

        string get_name() const override;
    protected:
        /**
         * @brief 藏干
         */
        HideHeavenStem hide_heaven_stem;

        /**
         * @brief 天索引
         */
        int day_index;
    };

    /**
     * @brief 地支（地元）
     */
    class EarthBranch : public LoopTyme {
    public:
        ~EarthBranch() override = default;

        static const vector<string> NAMES;

        explicit EarthBranch(const int index) : LoopTyme(NAMES, index) {
        }

        explicit EarthBranch(const string &name) : LoopTyme(NAMES, name) {
        }

        static EarthBranch from_index(int index);

        static EarthBranch from_name(const string &name);

        EarthBranch next(int n) const;

        /**
         * @brief 五行
         * @return 五行
         */
        Element get_element() const;

        /**
         * @brief 阴阳
         * @return 阴阳
         */
        YinYang get_yin_yang() const;

        /**
         * @brief 藏干之本气
         * @return 天干
         */
        HeavenStem get_hide_heaven_stem_main() const;

        /**
         * @brief 藏干之中气，无中气返回nullopt
         * @return 天干
         */
        optional<HeavenStem> get_hide_heaven_stem_middle() const;

        /**
         * @brief 藏干之余气，无余气返回nullopt
         * @return 天干
         */
        optional<HeavenStem> get_hide_heaven_stem_residual() const;

        /**
         * @brief 藏干列表
         * @return 藏干列表
         */
        vector<HideHeavenStem> get_hide_heaven_stems() const;

        /**
         * @brief 生肖
         * @return 生肖
         */
        Zodiac get_zodiac() const;

        /**
         * @brief 方位
         * @return 方位
         */
        Direction get_direction() const;

        /**
         * @brief 煞（逢巳日、酉日、丑日必煞东；亥日、卯日、未日必煞西；申日、子日、辰日必煞南；寅日、午日、戌日必煞北。）
         * @return 方位
         */
        Direction get_ominous() const;

        /**
         * @brief 地支彭祖百忌
         * @return 地支彭祖百忌
         */
        PengZuEarthBranch get_peng_zu_earth_branch() const;

        /**
         * @brief 六冲（子午冲，丑未冲，寅申冲，辰戌冲，卯酉冲，巳亥冲）
         * @return 地支
         */
        EarthBranch get_opposite() const;

        /**
         * @brief 六合（子丑合，寅亥合，卯戌合，辰酉合，巳申合，午未合）
         * @return 地支
         */
        EarthBranch get_combine() const;

        /**
         * @brief 六害（子未害、丑午害、寅巳害、卯辰害、申亥害、酉戌害）
         * @return 地支
         */
        EarthBranch get_harm() const;

        /**
         * @brief 合化（子丑合化土，寅亥合化木，卯戌合化火，辰酉合化金，巳申合化水，午未合化土）
         * @param target 地支
         * @return 五行，如果无法合化，返回nullopt
         */
        optional<Element> combine(const EarthBranch &target) const;
    };

    /**
     * @brief 彭祖百忌
     */
    class PengZu;

    /**
     * @brief 干支月
     */
    class SixtyCycleMonth;

    /**
     * @brief 干支日
     */
    class SixtyCycleDay;

    /**
     * @brief 六十甲子(六十干支周)
     */
    class SixtyCycle : public LoopTyme {
    public:
        ~SixtyCycle() override = default;

        static const vector<string> NAMES;

        explicit SixtyCycle(const int index) : LoopTyme(NAMES, index) {
        }

        explicit SixtyCycle(const string &name) : LoopTyme(NAMES, name) {
        }

        static SixtyCycle from_index(int index);

        static SixtyCycle from_name(const string &name);

        SixtyCycle next(int n) const;

        /**
         * @brief 天干
         * @return 天干
         */
        HeavenStem get_heaven_stem() const;

        /**
         * @brief 地支
         * @return 地支
         */
        EarthBranch get_earth_branch() const;

        /**
         * @brief 纳音
         * @return 纳音
         */
        Sound get_sound() const;

        /**
         * @brief 彭祖百忌
         * @return 彭祖百忌
         */
        PengZu get_peng_zu() const;

        /**
         * @brief 旬
         * @return 旬
         */
        Ten get_ten() const;

        /**
         * @brief 旬空(空亡)，因地支比天干多2个，旬空则为每一轮干支一一配对后多出来的2个地支
         * @return 旬空(空亡)
         */
        vector<EarthBranch> get_extra_earth_branches() const;
    };

    /**
     * @brief 神煞
     */
    class God : public LoopTyme {
    public:
        ~God() override = default;

        static const vector<string> NAMES;

        explicit God(const int index) : LoopTyme(NAMES, index) {
        }

        explicit God(const string &name) : LoopTyme(NAMES, name) {
        }

        static God from_index(int index);

        static God from_name(const string &name);

        static vector<God> get_day_gods(const SixtyCycle &month, const SixtyCycle &day);

        God next(int n) const;

        /**
         * @brief 吉凶
         * @return 吉凶
         */
        Luck get_luck() const;

    protected:
        static const vector<string> DAY_GODS;
    };

    /**
     * @brief 宜忌
     */
    class Taboo : public LoopTyme {
    public:
        ~Taboo() override = default;

        static const vector<string> NAMES;

        explicit Taboo(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Taboo(const string &name) : LoopTyme(NAMES, name) {
        }

        static Taboo from_index(int index);

        static Taboo from_name(const string &name);

        Taboo next(int n) const;

        /**
         * @brief 日宜
         * @param month 月干支
         * @param day 日干支
         * @return 宜忌列表
         */
        static vector<Taboo> get_day_recommends(const SixtyCycle &month, const SixtyCycle &day);

        /**
         * @brief 日忌
         * @param month 月干支
         * @param day 日干支
         * @return 宜忌列表
         */
        static vector<Taboo> get_day_avoids(const SixtyCycle &month, const SixtyCycle &day);

        /**
         * @brief 时辰宜
         * @param day 日干支
         * @param hour 时辰干支
         * @return 宜忌列表
         */
        static vector<Taboo> get_hour_recommends(const SixtyCycle &day, const SixtyCycle &hour);

        /**
         * @brief 时辰忌
         * @param day 日干支
         * @param hour 时辰干支
         * @return 宜忌列表
         */
        static vector<Taboo> get_hour_avoids(const SixtyCycle &day, const SixtyCycle &hour);

    protected:
        static const vector<string> DAY_TABOO;
        static const vector<string> HOUR_TABOO;

    private:
        static vector<Taboo> get_taboos(vector<string> data, int sup_index, int sub_index, int index);
    };

    /**
     * @brief 干支年
     */
    class SixtyCycleYear : public AbstractCulture {
    public:
        ~SixtyCycleYear() override = default;

        explicit SixtyCycleYear(const int year) : AbstractCulture() {
            if (year < -1 || year > 9999) {
                throw invalid_argument("illegal sixty cycle year: " + std::to_string(year));
            }
            this->year = year;
        }

        static SixtyCycleYear from_year(int year);

        /**
         * @brief 年
         * @return 年
         */
        int get_year() const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        string get_name() const override;

        SixtyCycleYear next(int n) const;

        /**
         * @brief 运
         * @return 运
         */
        Twenty get_twenty() const;

        /**
         * @brief 九星
         * @return 九星
         */
        NineStar get_nine_star() const;

        /**
         * @brief 太岁方位
         * @return 太岁方位
         */
        Direction get_jupiter_direction() const;

        /**
         * @brief 首月（五虎遁：甲己之年丙作首，乙庚之岁戊为头，丙辛必定寻庚起，丁壬壬位顺行流，若问戊癸何方发，甲寅之上好追求。）
         * @return 干支月
         */
        SixtyCycleMonth get_first_month() const;

        /**
         * @brief 干支月列表
         * @return 干支月列表
         */
        vector<SixtyCycleMonth> get_months() const;

    protected:
        /**
         * @brief 年
         */
        int year;
    };

    /**
     * @brief 干支月
     */
    class SixtyCycleMonth : public AbstractCulture {
    public:
        ~SixtyCycleMonth() override = default;

        explicit SixtyCycleMonth(const SixtyCycleYear &year, const SixtyCycle &month) : AbstractCulture(), year(year), month(month) {
        }

        static SixtyCycleMonth from_index(int year, int index);

        /**
         * @brief 干支年
         * @return 干支年
         */
        SixtyCycleYear get_sixty_cycle_year() const;

        /**
         * @brief 年柱
         * @return 年柱
         */
        SixtyCycle get_year() const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        string get_name() const override;

        string to_string() const override;

        SixtyCycleMonth next(int n) const;

        /**
         * @brief 位于当年的索引(0-11)，寅月为0，依次类推
         * @return 索引
         */
        int get_index_in_year() const;

        /**
         * @brief 九星
         * @return 九星
         */
        NineStar get_nine_star() const;

        /**
         * @brief 太岁方位
         * @return 方位
         */
        Direction get_jupiter_direction() const;

        /**
         * @brief 首日（节令当天）
         * @return 干支日
         */
        SixtyCycleDay get_first_day() const;

        /**
         * @brief 本月的干支日列表
         * @return 干支日列表
         */
        vector<SixtyCycleDay> get_days() const;

    protected:
        /**
         * @brief 干支年
         */
        SixtyCycleYear year;

        /**
         * @brief 月柱
         */
        SixtyCycle month;
    };
}
#endif
