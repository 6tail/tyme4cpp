#ifndef TYME_EIGHT_CHAR_H
#define TYME_EIGHT_CHAR_H
#include "lunar.h"

namespace tyme {
    /**
     * @brief 三柱（年柱、月柱、日柱）
     */
    class ThreePillars : public AbstractCulture {
    public:
        ~ThreePillars() override = default;

        explicit ThreePillars(const SixtyCycle &year, const SixtyCycle &month, const SixtyCycle &day) : AbstractCulture(), year(year), month(month), day(day) {
        }

        explicit ThreePillars(const string &year, const string &month, const string &day) : AbstractCulture(), year(SixtyCycle(year)), month(SixtyCycle(month)), day(SixtyCycle(day)) {
        }

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
         * @brief 公历日列表
         * @param start_year 开始年(含)，支持1-9999年
         * @param end_year 结束年(含)，支持1-9999年
         * @return 公历日列表
         */
        vector<SolarDay> get_solar_days(int start_year, int end_year) const;

        string get_name() const override;

    protected:
        /**
         * @brief 年柱
         */
        SixtyCycle year;

        /**
         * @brief 月柱
         */
        SixtyCycle month;

        /**
         * @brief 日柱
         */
        SixtyCycle day;
    };

    /**
     * @brief 八字
     */
    class EightChar : public AbstractCulture {
    public:
        ~EightChar() override = default;

        explicit EightChar(const SixtyCycle &year, const SixtyCycle &month, const SixtyCycle &day, const SixtyCycle &hour) : AbstractCulture(), three_pillars(ThreePillars(year, month, day)), hour(hour) {
        }

        explicit EightChar(const string &year, const string &month, const string &day, const string &hour) : AbstractCulture(), three_pillars(ThreePillars(year, month, day)), hour(SixtyCycle(hour)) {
        }

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
         * @brief 时柱
         * @return 时柱
         */
        SixtyCycle get_hour() const;

        /**
         * @brief 胎元
         * @return 胎元
         */
        SixtyCycle get_fetal_origin() const;

        /**
         * @brief 胎息
         * @return 胎息
         */
        SixtyCycle get_fetal_breath() const;

        /**
         * @brief 命宫
         * @return 命宫
         */
        SixtyCycle get_own_sign() const;

        /**
         * @brief 身宫
         * @return 身宫
         */
        SixtyCycle get_body_sign() const;

        /**
         * @brief 公历时刻列表
         * @param start_year 开始年(含)，支持1-9999年
         * @param end_year 结束年(含)，支持1-9999年
         * @return 公历时刻列表
         */
        vector<SolarTime> get_solar_times(int start_year, int end_year) const;

        string get_name() const override;

    protected:
        /**
         * @brief 三柱
         */
        ThreePillars three_pillars;

        /**
         * @brief 时柱
         */
        SixtyCycle hour;
    };

    /**
     * @brief 八字计算接口
     */
    class EightCharProvider {
    public:
        virtual ~EightCharProvider() = default;

        /**
         * @brief 八字
         * @param hour 农历时辰
         * @return 八字
         */
        virtual EightChar get_eight_char(LunarHour hour) const = 0;
    };

    /**
     * @brief 默认的八字计算（晚子时日柱算第二天）
     */
    class DefaultEightCharProvider : public EightCharProvider {
    public:
        EightChar get_eight_char(LunarHour hour) const override;
    };

    /**
     * @brief Lunar流派2的八字计算（晚子时日柱算当天）
     */
    class LunarSect2EightCharProvider : public EightCharProvider {
    public:
        EightChar get_eight_char(LunarHour hour) const override;
    };

    /**
     * @brief 干支时辰
     */
    class SixtyCycleHour;

    /**
     * @brief 农历时辰
     */
    class LunarHour : public SecondUnit {
    public:
        ~LunarHour() override = default;

        /**
         * @brief 八字计算接口
         */
        static EightCharProvider *provider;

        explicit LunarHour(const int year, const int month, const int day, const int hour, const int minute, const int second) : SecondUnit(year, month, day, hour, minute, second) {
            validate(year, month, day, hour, minute, second);
        }

        static void validate(int year, int month, int day, int hour, int minute, int second);

        static LunarHour from_ymd_hms(int year, int month, int day, int hour, int minute, int second);

        /**
         * @brief 农历日
         * @return 农历日
         */
        LunarDay get_lunar_day() const;

        string get_name() const override;

        string to_string() const override;

        LunarHour next(int n) const;

        /**
         * @brief 位于当天的索引
         * @return 索引
         */
        int get_index_in_day() const;

        /**
         * @brief 是否在指定农历时辰之前
         * @param other 农历时辰
         * @return true/false
         */
        bool is_before(const LunarHour &other) const;

        /**
         * @brief 是否在指定农历时辰之后
         * @param other 农历时辰
         * @return true/false
         */
        bool is_after(const LunarHour &other) const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

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
         * @brief 公历时刻
         * @return 公历时刻
         */
        SolarTime get_solar_time() const;

        /**
         * @brief 干支时辰
         * @return 干支时辰
         */
        SixtyCycleHour get_sixty_cycle_hour() const;

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
         * @brief 小六壬
         * @return 小六壬
         */
        MinorRen get_minor_ren() const;

        /**
         * @brief 八字
         * @return 八字
         */
        EightChar get_eight_char() const;
    };
}
#endif
