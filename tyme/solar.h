#ifndef TYME_SOLAR_H
#define TYME_SOLAR_H
#include "sixtycycle.h"

namespace tyme {
    class JulianDay;
    class SolarDay;
    class SolarTime;
    class LunarDay;
    class LunarMonth;
    class LunarYear;
    class LunarHour;
    class DogDay;
    class NineDay;
    class PlumRainDay;
    class Phenology;
    class PhenologyDay;
    class RabByungDay;
    class SolarFestival;
    class Phase;
    class PhaseDay;
    class SixtyCycleHour;

    /**
     * @brief 节气
     */
    class SolarTerm : public LoopTyme {
    public:
        ~SolarTerm() override = default;

        static const vector<string> NAMES;

        explicit SolarTerm(const int year, const int index) : LoopTyme(NAMES, index) {
            const int size = get_size();
            init_by_year((year * size + index) / size, get_index());
        }

        explicit SolarTerm(const int year, const string &name) : LoopTyme(NAMES, name) {
            init_by_year(year, index);
        }

        static SolarTerm from_index(int year, int index);

        static SolarTerm from_name(int year, const string &name);

        SolarTerm next(int n) const;

        /**
         * @brief 是否节令
         * @return true/false
         */
        bool is_jie() const;

        /**
         * @brief 是否气令
         * @return true/false
         */
        bool is_qi() const;

        /**
         * @brief 儒略日（精确到秒）
         * @return 儒略日
         */
        JulianDay get_julian_day() const;

        /**
         * @brief 公历日（用于日历）
         * @return 公历日
         */
        SolarDay get_solar_day() const;

        /**
         * @brief 年
         * @return 年
         */
        int get_year() const;

        /**
         * @brief 儒略日（用于日历，只精确到日中午12:00）
         * @return 儒略日数
         */
        double get_cursory_julian_day() const;

    protected:
        /**
         * @brief 年
         */
        int year = 0;

        /**
         * @brief 儒略日（用于日历，只精确到日中午12:00）
         */
        double cursory_julian_day = 0;

        void init_by_year(int y, int offset);
    };

    /**
     * @brief 儒略日
     */
    class JulianDay : public AbstractCulture {
    public:
        ~JulianDay() override = default;

        /**
         * @brief 2000年儒略日数(2000-1-1 12:00:00 UTC)
         */
        static const double J2000;

        explicit JulianDay(const double day) : AbstractCulture() {
            this->day = day;
        }

        static JulianDay from_julian_day(double day);

        static JulianDay from_ymd_hms(int year, int month, int day, int hour, int minute, int second);

        /**
         * @brief 儒略日
         * @return 儒略日
         */
        double get_day() const;

        string get_name() const override;

        JulianDay next(int n) const;

        /**
         * @brief 星期
         * @return 星期
         */
        Week get_week() const;

        /**
         * @brief 儒略日相减
         * @param target 儒略日
         * @return 差
         */
        double subtract(const JulianDay &target) const;

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
         * @brief 儒略日
         */
        double day;
    };

    /**
     * @brief 节气第几天
     */
    class SolarTermDay : public AbstractCulture {
    public:
        ~SolarTermDay() override = default;

        explicit SolarTermDay(const SolarTerm &solar_term, const int day_index) : solar_term(solar_term), day_index(day_index) {
        }

        SolarTerm get_solar_term() const;

        int get_day_index() const;

        string to_string() const override;

        string get_name() const override;
    protected:
        /**
         * @brief 节气
         */
        SolarTerm solar_term;

        /**
         * @brief 天索引
         */
        int day_index;
    };

    /**
     * @brief 公历周
     */
    class SolarWeek;

    /**
     * @brief 公历月
     */
    class SolarMonth;

    /**
     * @brief 公历季度
     */
    class SolarSeason;

    /**
     * @brief 公历半年
     */
    class SolarHalfYear;

    /**
     * @brief 公历年
     */
    class SolarYear : public YearUnit {
    public:
        ~SolarYear() override = default;

        explicit SolarYear(const int year) : YearUnit(year) {
            validate(year);
        }

        static void validate(int year);

        static SolarYear from_year(int year);

        /**
         * @brief 天数（1582年355天，平年365天，闰年366天）
         * @return 天数
         */
        int get_day_count() const;

        /**
         * @brief 是否闰年(1582年以前，使用儒略历，能被4整除即为闰年。以后采用格里历，四年一闰，百年不闰，四百年再闰。)
         * @return true/false
         */
        bool is_leap() const;

        string get_name() const override;

        SolarYear next(int n) const;

        /**
         * @brief 月份列表，1年有12个月。
         * @return 月份列表
         */
        vector<SolarMonth> get_months() const;

        /**
         * @brief 季度列表，1年有4个季度。
         * @return 季度列表
         */
        vector<SolarSeason> get_seasons() const;

        /**
         * @brief 半年列表，1年有2个半年。
         * @return 半年列表
         */
        vector<SolarHalfYear> get_half_years() const;
    };

    /**
     * @brief 公历半年
     */
    class SolarHalfYear : public YearUnit {
    public:
        ~SolarHalfYear() override = default;

        static const vector<string> NAMES;

        explicit SolarHalfYear(const int year, const int index) : YearUnit(year) {
            validate(year, index);
            this->index = index;
        }

        static void validate(int year, int index);

        static SolarHalfYear from_index(int year, int index);

        /**
         * @brief 公历年
         * @return 公历年
         */
        SolarYear get_solar_year() const;

        /**
         * @brief 索引
         * @return 索引，0-1
         */
        int get_index() const;

        string get_name() const override;

        string to_string() const override;

        SolarHalfYear next(int n) const;

        /**
         * @brief 季度列表，半年有2个季度。
         * @return 季度列表
         */
        vector<SolarSeason> get_seasons() const;

        /**
         * @brief 月份列表，半年有6个月。
         * @return 月份列表
         */
        vector<SolarMonth> get_months() const;

    protected:
        /**
         * @brief 索引，0-1
         */
        int index;
    };

    /**
     * @brief 公历季度
     */
    class SolarSeason : public YearUnit {
    public:
        ~SolarSeason() override = default;

        static const vector<string> NAMES;

        explicit SolarSeason(const int year, const int index) : YearUnit(year) {
            validate(year, index);
            this->index = index;
        }

        static void validate(int year, int index);

        static SolarSeason from_index(int year, int index);

        /**
         * @brief 公历年
         * @return 公历年
         */
        SolarYear get_solar_year() const;

        /**
         * @brief 索引
         * @return 索引，0-3
         */
        int get_index() const;

        string get_name() const override;

        string to_string() const override;

        SolarSeason next(int n) const;

        /**
         * @brief 月份列表，1季度有3个月。
         * @return 月份列表
         */
        vector<SolarMonth> get_months() const;

    protected:
        /**
         * @brief 索引，0-3
         */
        int index;
    };

    /**
     * @brief 公历月
     */
    class SolarMonth : public MonthUnit {
    public:
        ~SolarMonth() override = default;

        static const vector<string> NAMES;
        static const int DAYS[];

        explicit SolarMonth(const int year, const int month) : MonthUnit(year, month) {
            validate(year, month);
        }

        static void validate(int year, int month);

        static SolarMonth from_ym(int year, int month);

        /**
         * @brief 公历年
         * @return 公历年
         */
        SolarYear get_solar_year() const;

        /**
         * @brief 天数（1582年10月只有21天)
         * @return 天数
         */
        int get_day_count() const;

        /**
         * @brief 位于当年的索引(0-11)
         * @return 索引
         */
        int get_index_in_year() const;

        /**
         * @brief 公历季度
         * @return 公历季度
         */
        SolarSeason get_season() const;

        /**
         * @brief 周数
         * @param start 起始星期，1234560分别代表星期一至星期天
         * @return 周数
         */
        int get_week_count(int start) const;

        string get_name() const override;

        string to_string() const override;

        SolarMonth next(int n) const;

        /**
         * @brief 本月的公历周列表
         * @param start 星期几作为一周的开始，1234560分别代表星期一至星期天
         * @return 公历周列表
         */
        vector<SolarWeek> get_weeks(int start) const;

        /**
         * @brief 本月的公历日列表
         * @return 公历日列表
         */
        vector<SolarDay> get_days() const;

        /**
         * @brief 本月第1天
         * @return 公历日
         */
        SolarDay get_first_day() const;
    };

    /**
     * @brief 公历日
     */
    class SolarDay : public DayUnit {
    public:
        ~SolarDay() override = default;

        static const vector<string> NAMES;

        explicit SolarDay(const int year, const int month, const int day) : DayUnit(year, month, day) {
            validate(year, month, day);
        }

        static void validate(int year, int month, int day);

        static SolarDay from_ymd(int year, int month, int day);

        /**
         * @brief 公历月
         * @return 公历月
         */
        SolarMonth get_solar_month() const;

        /**
         * @brief 星期
         * @return 星期
         */
        Week get_week() const;

        /**
         * @brief 星座
         * @return 星座
         */
        Constellation get_constellation() const;

        string get_name() const override;

        string to_string() const override;

        SolarDay next(int n) const;

        /**
         * @brief 是否在指定公历日之前
         * @param other 公历日
         * @return true/false
         */
        bool is_before(const SolarDay &other) const;

        /**
         * @brief 是否在指定公历日之后
         * @param other 公历日
         * @return true/false
         */
        bool is_after(const SolarDay &other) const;

        bool equals(const SolarDay &other) const;

        /**
         * @brief 节气
         * @return 节气
         */
        SolarTerm get_term() const;

        /**
         * @brief 节气第几天
         * @return 节气第几天
         */
        SolarTermDay get_term_day() const;

        /**
         * @brief 公历周
         * @param start 起始星期，1234560分别代表星期一至星期天
         * @return 公历周
         */
        SolarWeek get_solar_week(int start) const;

        /**
         * @brief 候
         * @return 候
         */
        Phenology get_phenology() const;

        /**
         * @brief 七十二候
         * @return 七十二候
         */
        PhenologyDay get_phenology_day() const;

        /**
         * @brief 三伏天
         * @return 三伏天
         */
        optional<DogDay> get_dog_day() const;

        /**
         * @brief 数九天
         * @return 数九天
         */
        optional<NineDay> get_nine_day() const;

        /**
         * @brief 梅雨天（芒种后的第1个丙日入梅，小暑后的第1个未日出梅）
         * @return 梅雨天
         */
        optional<PlumRainDay> get_plum_rain_day() const;

        /**
         * @brief 人元司令分野
         * @return 人元司令分野
         */
        HideHeavenStemDay get_hide_heaven_stem_day() const;

        /**
         * @brief 位于当年的索引
         * @return 索引
         */
        int get_index_in_year() const;

        /**
         * @brief 公历日期相减，获得相差天数
         * @param other 公历日
         * @return 天数
         */
        int subtract(const SolarDay &other) const;

        /**
         * @brief 儒略日
         * @return 儒略日
         */
        JulianDay get_julian_day() const;

        /**
         * @brief 农历日
         * @return 农历日
         */
        LunarDay get_lunar_day() const;

        /**
         * @brief 干支日
         * @return 干支日
         */
        SixtyCycleDay get_sixty_cycle_day() const;

        /**
         * @brief 藏历日
         * @return 藏历日
         */
        RabByungDay get_rab_byung_day() const;

        /**
         * @brief 公历节日
         * @return 公历节日
         */
        optional<SolarFestival> get_festival() const;

        /**
         * @brief 月相第几天
         * @return 月相第几天
         */
        PhaseDay get_phase_day() const;

        /**
         * @brief 月相
         * @return 月相
         */
        Phase get_phase() const;

        /**
         * @brief 九星
         * @return 九星
         */
        NineStar get_nine_star() const;
    };

    /**
     * @brief 公历周
     */
    class SolarWeek : public WeekUnit {
    public:
        ~SolarWeek() override = default;

        explicit SolarWeek(const int year, const int month, const int index, const int start) : WeekUnit(year, month, index, start) {
            validate(year, month, index, start);
        }

        static void validate(int year, int month, int index, int start);

        static SolarWeek from_ym(int year, int month, int index, int start);

        /**
         * @brief 公历月
         * @return 公历月
         */
        SolarMonth get_solar_month() const;

        /**
         * @brief 位于当年的索引
         * @return 索引
         */
        int get_index_in_year() const;

        string get_name() const override;

        string to_string() const override;

        SolarWeek next(int n) const;

        bool equals(const SolarWeek &other) const;

        /**
         * @brief 本周第1天
         * @return 公历日
         */
        SolarDay get_first_day() const;

        /**
         * @brief 本周公历日列表
         * @return 公历日列表
         */
        vector<SolarDay> get_days() const;
    };

    /**
     * @brief 公历时刻
     */
    class SolarTime : public SecondUnit {
    public:
        ~SolarTime() override = default;

        SolarTime(const SolarTime &other) : SecondUnit(other.year, other.month, other.day, other.hour, other.minute, other.second) {
        }

        SolarTime &operator=(const SolarTime &other);

        explicit SolarTime(const int year, const int month, const int day, const int hour, const int minute, const int second) : SecondUnit(year, month, day, hour, minute, second) {
            validate(year, month, day, hour, minute, second);
        }

        static void validate(int year, int month, int day, int hour, int minute, int second);

        static SolarTime from_ymd_hms(int year, int month, int day, int hour, int minute, int second);

        /**
         * @brief 公历日
         * @return 公历日
         */
        SolarDay get_solar_day() const;

        string get_name() const override;

        string to_string() const override;

        SolarTime next(int n) const;

        /**
         * @brief 是否在指定公历日之前
         * @param other 公历日
         * @return true/false
         */
        bool is_before(const SolarTime &other) const;

        /**
         * @brief 是否在指定公历日之后
         * @param other 公历日
         * @return true/false
         */
        bool is_after(const SolarTime &other) const;

        bool equals(const SolarTime &other) const;

        /**
         * @brief 节气
         * @return 节气
         */
        SolarTerm get_term() const;

        /**
         * @brief 候
         * @return 候
         */
        Phenology get_phenology() const;

        /**
         * @brief 公历时刻相减，获得相差秒数
         * @param other 公历时刻
         * @return 秒数
         */
        int subtract(const SolarTime &other) const;

        /**
         * @brief 儒略日
         * @return 儒略日
         */
        JulianDay get_julian_day() const;

        /**
         * @brief 干支时辰
         * @return 干支时辰
         */
        SixtyCycleHour get_sixty_cycle_hour() const;

        /**
         * @brief 农历时辰
         * @return 农历时辰
         */
        LunarHour get_lunar_hour() const;

        /**
         * @brief 月相
         * @return 月相
         */
        Phase get_phase() const;
    };
}
#endif
