#ifndef TYME_SEASONAL_H
#define TYME_SEASONAL_H
#include "lunar.h"

namespace tyme {
    /**
     * @brief 干支日（立春换年，节令换月）
     */
    class SixtyCycleDay : public AbstractCulture {
    public:
        ~SixtyCycleDay() override = default;

        SixtyCycleDay(const SixtyCycleDay &other): solar_day(other.solar_day), month(other.month), day(other.day) {
        }

        SixtyCycleDay &operator=(const SixtyCycleDay &other);

        explicit SixtyCycleDay(const SolarDay &solar_day, const SixtyCycleMonth &month, const SixtyCycle &day) : AbstractCulture(), solar_day(solar_day), month(month), day(day) {
        }

        explicit SixtyCycleDay(const SolarDay &solar_day) : AbstractCulture(), solar_day(solar_day) {
            const int solar_year = solar_day.get_year();
            const SolarDay spring_solar_day = SolarTerm::from_index(solar_year, 3).get_solar_day();
            const LunarDay lunar_day = solar_day.get_lunar_day();
            LunarYear lunar_year = lunar_day.get_lunar_month().get_lunar_year();
            if (lunar_year.get_year() == solar_year) {
                if (solar_day.is_before(spring_solar_day)) {
                    lunar_year = lunar_year.next(-1);
                }
            } else if (lunar_year.get_year() < solar_year) {
                if (!solar_day.is_before(spring_solar_day)) {
                    lunar_year = lunar_year.next(1);
                }
            }
            const SolarTerm term = solar_day.get_term();
            int index = term.get_index() - 3;
            if (index < 0 && term.get_solar_day().is_after(spring_solar_day)) {
                index += 24;
            }
            this->month = SixtyCycleMonth(SixtyCycleYear::from_year(lunar_year.get_year()), LunarMonth::from_ym(solar_year, 1).get_sixty_cycle().next(static_cast<int>(floor(index * 1.0 / 2))));
            this->day = lunar_day.get_sixty_cycle();
        }

        static SixtyCycleDay from_solar_day(const SolarDay &solar_day);

        /**
         * @brief 公历日
         * @return 公历日
         */
        SolarDay get_solar_day() const;

        /**
         * @brief 干支月
         * @return 干支月
         */
        SixtyCycleMonth get_sixty_cycle_month() const;

        /**
         * @brief 年柱
         * @return 年柱
         */
        SixtyCycle get_year() const;

        /**
         * @brief 月柱
         * @return 月柱
         */
        SixtyCycle get_month() const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        string get_name() const override;

        string to_string() const override;

        /**
         * @brief 推移
         * @param n 推移天数
         * @return 干支日
         */
        SixtyCycleDay next(int n) const;

        /**
         * @brief 建除十二值神
         * @return 建除十二值神
         */
        Duty get_duty() const;

        /**
         * @brief 黄道黑道十二神
         * @return 黄道黑道十二神
         */
        TwelveStar get_twelve_star() const;

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
         * @brief 逐日胎神
         * @return 逐日胎神
         */
        FetusDay get_fetus_day() const;

        /**
         * @brief 二十八宿
         * @return 二十八宿
         */
        TwentyEightStar get_twenty_eight_star() const;

        /**
         * @brief 神煞列表(吉神宜趋，凶神宜忌)
         * @return 神煞列表
         */
        vector<God> get_gods() const;

        /**
         * @brief 宜
         * @return 宜忌列表
         */
        vector<Taboo> get_recommends() const;

        /**
         * @brief 忌
         * @return 宜忌列表
         */
        vector<Taboo> get_avoids() const;

        /**
         * @brief 干支时辰列表
         * @return 干支时辰列表
         */
        vector<SixtyCycleHour> get_hours() const;

        /**
         * @brief 三柱
         * @return 三柱
         */
        ThreePillars get_three_pillars() const;

    protected:
        /**
         * @brief 公历日
         */
        SolarDay solar_day;

        /**
         * @brief 干支月
         */
        optional<SixtyCycleMonth> month;

        /**
         * @brief 日柱
         */
        optional<SixtyCycle> day;
    };

    /**
     * @brief 干支时辰（立春换年，节令换月，23点换日）
     */
    class SixtyCycleHour : public AbstractCulture {
    public:
        ~SixtyCycleHour() override = default;

        explicit SixtyCycleHour(const SolarTime &solar_time) : AbstractCulture(), solar_time(solar_time) {
            const int solar_year = solar_time.get_year();
            const SolarTime spring_solar_time = SolarTerm::from_index(solar_year, 3).get_julian_day().get_solar_time();
            const LunarHour lunar_hour = solar_time.get_lunar_hour();
            const LunarDay lunar_day = lunar_hour.get_lunar_day();
            LunarYear lunar_year = lunar_day.get_lunar_month().get_lunar_year();
            if (lunar_year.get_year() == solar_year) {
                if (solar_time.is_before(spring_solar_time)) {
                    lunar_year = lunar_year.next(-1);
                }
            } else if (lunar_year.get_year() < solar_year) {
                if (!solar_time.is_before(spring_solar_time)) {
                    lunar_year = lunar_year.next(1);
                }
            }

            SolarTerm term = solar_time.get_term();
            int index = term.get_index() - 3;
            if (index < 0 && term.get_julian_day().get_solar_time().is_after(SolarTerm::from_index(solar_year, 3).get_julian_day().get_solar_time())) {
                index += 24;
            }
            SixtyCycle d = lunar_day.get_sixty_cycle();
            if (solar_time.get_hour() >= 23) {
                d = d.next(1);
            }
            day = SixtyCycleDay(solar_time.get_solar_day(), SixtyCycleMonth(SixtyCycleYear::from_year(lunar_year.get_year()), LunarMonth::from_ym(solar_year, 1).get_sixty_cycle().next(static_cast<int>(floor(index * 0.5)))), d);
            hour = lunar_hour.get_sixty_cycle();
        }

        static SixtyCycleHour from_solar_time(const SolarTime &solar_time);

        /**
         * @brief 年柱
         * @return 年柱
         */
        SixtyCycle get_year() const;

        /**
         * @brief 月柱
         * @return 月柱
         */
        SixtyCycle get_month() const;

        /**
         * @brief 日柱
         * @return 日柱
         */
        SixtyCycle get_day() const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        /**
         * @brief 干支日
         * @return 干支日
         */
        SixtyCycleDay get_sixty_cycle_day() const;

        /**
         * @brief 公历时刻
         * @return 公历时刻
         */
        SolarTime get_solar_time() const;

        string get_name() const override;

        string to_string() const override;

        SixtyCycleHour next(int n) const;

        /**
         * @brief 位于当天的索引
         * @return 索引
         */
        int get_index_in_day() const;

        /**
         * @brief 九星
         * @return 九星
         */
        NineStar get_nine_star() const;

        /**
         * @brief 黄道黑道十二神
         * @return 黄道黑道十二神
         */
        TwelveStar get_twelve_star() const;

        /**
         * @brief 宜
         * @return 宜忌列表
         */
        vector<Taboo> get_recommends() const;

        /**
         * @brief 忌
         * @return 宜忌列表
         */
        vector<Taboo> get_avoids() const;

        /**
         * @brief 八字
         * @return 八字
         */
        EightChar get_eight_char() const;

    protected:
        /**
         * @brief 公历时刻
         */
        SolarTime solar_time;

        /**
         * @brief 干支日
         */
        optional<SixtyCycleDay> day;

        /**
         * @brief 时柱
         */
        optional<SixtyCycle> hour;
    };

    /**
     * @brief 灶马头(灶神的坐骑)
     */
    class KitchenGodSteed : public AbstractCulture {
    public:
        ~KitchenGodSteed() override = default;

        static const vector<string> NUMBERS;

        explicit KitchenGodSteed(const int lunar_year) : AbstractCulture(), first_day_sixty_cycle(LunarDay::from_ymd(lunar_year, 1, 1).get_sixty_cycle()) {
        }

        static KitchenGodSteed from_lunar_year(int lunar_year);

        /**
         * @brief 几鼠偷粮
         * @return 几鼠偷粮
         */
        string get_mouse() const;

        /**
         * @brief 草子几分
         * @return 草子几分
         */
        string get_grass() const;

        /**
         * @brief 几牛耕田（正月第一个丑日是初几，就是几牛耕田）
         * @return 几牛耕田
         */
        string get_cattle() const;

        /**
         * @brief 花收几分
         * @return 花收几分
         */
        string get_flower() const;

        /**
         * @brief 几龙治水（正月第一个辰日是初几，就是几龙治水）
         * @return 几龙治水
         */
        string get_dragon() const;

        /**
         * @brief 几马驮谷
         * @return 几马驮谷
         */
        string get_horse() const;

        /**
         * @brief 几鸡抢米
         * @return 几鸡抢米
         */
        string get_chicken() const;

        /**
         * @brief 几姑看蚕
         * @return 几姑看蚕
         */
        string get_silkworm() const;

        /**
         * @brief 几屠共猪
         * @return 几屠共猪
         */
        string get_pig() const;

        /**
         * @brief 甲田几分
         * @return 甲田几分
         */
        string get_field() const;

        /**
         * @brief 几人分饼（正月第一个丙日是初几，就是几人分饼）
         * @return 几人分饼
         */
        string get_cake() const;

        /**
         * @brief 几日得金（正月第一个辛日是初几，就是几日得金）
         * @return 几日得金
         */
        string get_gold() const;

        /**
         * @brief 几人几丙
         * @return 几人几丙
         */
        string get_people_cakes() const;

        /**
         * @brief 几人几锄
         * @return 几人几锄
         */
        string get_people_hoes() const;

        string get_name() const override;

    protected:
        /**
         * @brief 正月初一的干支
         */
        SixtyCycle first_day_sixty_cycle;

        string by_heaven_stem(int n) const;

        string by_earth_branch(int n) const;
    };

    /**
     * @brief 月相
     */
    class Phase : public LoopTyme {
    public:
        ~Phase() override = default;

        static const vector<string> NAMES;

        explicit Phase(const int lunar_year, const int lunar_month, const int index) : LoopTyme(NAMES, index) {
            const LunarMonth m = LunarMonth::from_ym(lunar_year, lunar_month).next(index / static_cast<int>(NAMES.size()));
            this->lunar_year = m.get_year();
            this->lunar_month = m.get_month_with_leap();
        }

        explicit Phase(const int lunar_year, const int lunar_month, const string &name) : LoopTyme(NAMES, name), lunar_year(lunar_year), lunar_month(lunar_month) {
        }

        static Phase from_index(int lunar_year, int lunar_month, int index);

        static Phase from_name(int lunar_year, int lunar_month, const string &name);

        Phase next(int n) const;

        /**
         * @brief 公历时刻
         * @return 公历时刻
         */
        SolarTime get_solar_time() const;

        /**
         * @brief 公历日
         * @return 公历日
         */
        SolarDay get_solar_day() const;
    protected:
        /**
         * @brief 农历年
         */
        int lunar_year;

        /**
         * @brief 农历月
         */
        int lunar_month;

        SolarTime get_start_solar_time() const;
    };

    /**
     * @brief 月相第几天
     */
    class PhaseDay : public AbstractCulture {
    public:
        ~PhaseDay() override = default;

        explicit PhaseDay(const Phase& phase, const int day_index) : phase(phase), day_index(day_index) {
        }

        Phase get_phase() const;

        int get_day_index() const;

        string to_string() const override;

        string get_name() const override;
    protected:
        /**
         * @brief 月相
         */
        Phase phase;

        /**
         * @brief 天索引
         */
        int day_index;
    };
}
#endif
