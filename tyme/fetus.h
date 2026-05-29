#ifndef TYME_FETUS_H
#define TYME_FETUS_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 六十甲子
     */
    class SixtyCycle;

    /**
     * @brief 干支日
     */
    class SixtyCycleDay;

    /**
     * @brief 农历月
     */
    class LunarMonth;

    /**
     * @brief 农历日
     */
    class LunarDay;

    /**
     * @brief 天干六甲胎神（《天干六甲胎神歌》甲己之日占在门，乙庚碓磨休移动。丙辛厨灶莫相干，丁壬仓库忌修弄。戊癸房床若移整，犯之孕妇堕孩童。）
     */
    class FetusHeavenStem : public LoopTyme {
    public:
        ~FetusHeavenStem() override = default;

        static const vector<string> NAMES;

        explicit FetusHeavenStem(const int index) : LoopTyme(NAMES, index) {
        }

        static FetusHeavenStem from_index(int index);

        FetusHeavenStem next(int n) const;
    };

    /**
     * @brief 地支六甲胎神（《地支六甲胎神歌》子午二日碓须忌，丑未厕道莫修移。寅申火炉休要动，卯酉大门修当避。辰戌鸡栖巳亥床，犯着六甲身堕胎。）
     */
    class FetusEarthBranch : public LoopTyme {
    public:
        ~FetusEarthBranch() override = default;

        static const vector<string> NAMES;

        explicit FetusEarthBranch(const int index) : LoopTyme(NAMES, index) {
        }

        static FetusEarthBranch from_index(int index);

        FetusEarthBranch next(int n) const;
    };

    /**
     * @brief 逐月胎神（正十二月在床房，二三九十门户中，四六十一灶勿犯，五甲七子八厕凶。）
     */
    class FetusMonth : public LoopTyme {
    public:
        ~FetusMonth() override = default;

        static const vector<string> NAMES;

        explicit FetusMonth(const int index) : LoopTyme(NAMES, index) {
        }

        static optional<FetusMonth> from_lunar_month(const LunarMonth &lunar_month);

        FetusMonth next(int n) const;
    };

    /**
     * @brief 逐日胎神
     */
    class FetusDay : public AbstractCulture {
    public:
        ~FetusDay() override = default;

        explicit FetusDay(const SixtyCycle &sixty_cycle);

        explicit FetusDay(const SixtyCycleDay &sixty_cycle_day);

        explicit FetusDay(const LunarDay &lunar_day);

        static FetusDay from_sixty_cycle_day(const SixtyCycleDay &sixty_cycle_day);

        static FetusDay from_lunar_day(const LunarDay &lunar_day);

        string get_name() const override;

        /**
         * @brief 内外
         * @return 内外
         */
        Side get_side() const;

        /**
         * @brief 方位
         * @return 方位
         */
        Direction get_direction() const;

        /**
         * @brief 天干六甲胎神
         * @return 天干六甲胎神
         */
        FetusHeavenStem get_fetus_heaven_stem() const;

        /**
         * @brief 地支六甲胎神
         * @return 地支六甲胎神
         */
        FetusEarthBranch get_fetus_earth_branch() const;

    protected:
        /**
         * @brief 天干六甲胎神
         */
        FetusHeavenStem fetus_heaven_stem;

        /**
         * @brief 地支六甲胎神
         */
        FetusEarthBranch fetus_earth_branch;

        /**
         * @brief 内外
         */
        Side side;

        /**
         * @brief 方位
         */
        Direction direction = Direction::from_index(0);
    };
}
#endif
