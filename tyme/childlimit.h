#ifndef TYME_CHILD_LIMIT_H
#define TYME_CHILD_LIMIT_H
#include "eightchar.h"

namespace tyme {
    /**
     * @brief 童限信息
     */
    class ChildLimitInfo {
    public:
        ~ChildLimitInfo() = default;

        explicit ChildLimitInfo(const SolarTime &start_time, const SolarTime &end_time, const int year_count, const int month_count, const int day_count, const int hour_count, const int minute_count): start_time(start_time), end_time(end_time), year_count(year_count), month_count(month_count), day_count(day_count), hour_count(hour_count), minute_count(minute_count) {
        }

        /**
         * @brief 开始(即出生)的公历时刻
         * @return 开始(即出生)的公历时刻
         */
        SolarTime get_start_time() const;

        /**
         * @brief 结束(即开始起运)的公历时刻
         * @return 结束(即开始起运)的公历时刻
         */
        SolarTime get_end_time() const;

        /**
         * @brief 年数
         * @return 年数
         */
        int get_year_count() const;

        /**
         * @brief 月数
         * @return 月数
         */
        int get_month_count() const;

        /**
         * @brief 日数
         * @return 日数
         */
        int get_day_count() const;

        /**
         * @brief 小时数
         * @return 小时数
         */
        int get_hour_count() const;

        /**
         * @brief 分钟数
         * @return 分钟数
         */
        int get_minute_count() const;

    protected:
        /**
         * @brief 开始(即出生)的公历时刻
         */
        SolarTime start_time;

        /**
         * @brief 结束(即开始起运)的公历时刻
         */
        SolarTime end_time;

        /**
         * @brief 年数
         */
        int year_count;

        /**
         * @brief 月数
         */
        int month_count;

        /**
         * @brief 日数
         */
        int day_count;

        /**
         * @brief 小时数
         */
        int hour_count;

        /**
         * @brief 分钟数
         */
        int minute_count;
    };

    /**
     * @brief 童限计算接口
     */
    class ChildLimitProvider {
    public:
        virtual ~ChildLimitProvider() = default;

        /**
         * @brief 童限信息
         * @param birth_time 出生公历时刻
         * @param term 节令
         * @return 童限信息
         */
        virtual ChildLimitInfo get_info(SolarTime birth_time, SolarTerm term) const = 0;
    };

    /**
     * @brief 童限计算抽象
     */
    class AbstractChildLimitProvider : public ChildLimitProvider {
    public:
        ChildLimitInfo next(const SolarTime &birth_time, int add_year, int add_month, int add_day, int add_hour, int add_minute, int add_second) const;
    };

    /**
     * @brief 默认的童限计算
     */
    class DefaultChildLimitProvider : public AbstractChildLimitProvider {
    public:
        ChildLimitInfo get_info(SolarTime birth_time, SolarTerm term) const override;
    };

    /**
     * @brief 元亨利贞的童限计算
     */
    class China95ChildLimitProvider : protected AbstractChildLimitProvider {
    public:
        ChildLimitInfo get_info(SolarTime birth_time, SolarTerm term) const override;
    };

    /**
     * @brief Lunar的流派1童限计算（按天数和时辰数计算，3天1年，1天4个月，1时辰10天）
     */
    class LunarSect1ChildLimitProvider : protected AbstractChildLimitProvider {
    public:
        ChildLimitInfo get_info(SolarTime birth_time, SolarTerm term) const override;
    };

    /**
     * @brief Lunar的流派2童限计算（按分钟数计算）
     */
    class LunarSect2ChildLimitProvider : protected AbstractChildLimitProvider {
    public:
        ChildLimitInfo get_info(SolarTime birth_time, SolarTerm term) const override;
    };

    /**
     * @brief 大运
     */
    class DecadeFortune;

    /**
     * @brief 小运
     */
    class Fortune;

    /**
     * @brief 童限
     */
    class ChildLimit {
    public:
        /**
         * @brief 童限计算接口
         */
        static ChildLimitProvider *provider;

        ~ChildLimit() = default;

        explicit ChildLimit(const SolarTime &birth_time, const Gender gender): eight_char(birth_time.get_lunar_hour().get_eight_char()), gender(gender), forward(get_forward(eight_char, gender)), info(get_info(birth_time, forward)) {
        }

        static ChildLimit from_solar_time(const SolarTime &birth_time, Gender gender);

        /**
         * @brief 八字
         * @return 八字
         */
        EightChar get_eight_char() const;

        /**
         * @brief 性别
         * @return 性别
         */
        Gender get_gender() const;

        /**
         * @brief 是否顺推
         * @return true/false
         */
        bool is_forward() const;

        /**
         * @brief 年数
         * @return 年数
         */
        int get_year_count() const;

        /**
         * @brief 月数
         * @return 月数
         */
        int get_month_count() const;

        /**
         * @brief 日数
         * @return 日数
         */
        int get_day_count() const;

        /**
         * @brief 小时数
         * @return 小时数
         */
        int get_hour_count() const;

        /**
         * @brief 分钟数
         * @return 分钟数
         */
        int get_minute_count() const;

        /**
         * @brief 开始(即出生)的公历时刻
         * @return 公历时刻
         */
        SolarTime get_start_time() const;

        /**
         * @brief 结束(即开始起运)的公历时刻
         * @return 公历时刻
         */
        SolarTime get_end_time() const;

        /**
         * @brief 起运大运
         * @return 大运
         */
        DecadeFortune get_start_decade_fortune() const;

        /**
         * @brief 所属大运
         * @return 大运
         */
        DecadeFortune get_decade_fortune() const;

        /**
         * @brief 小运
         * @return 小运
         */
        Fortune get_start_fortune() const;

        /**
         * @brief 开始(即出生)干支年
         * @return 干支年
         */
        SixtyCycleYear get_start_sixty_cycle_year() const;

        /**
         * @brief 结束(即起运)干支年
         * @return 干支年
         */
        SixtyCycleYear get_end_sixty_cycle_year() const;

        /**
         * @brief 开始年龄
         * @return 开始年龄
         */
        int get_start_age() const;

        /**
         * @brief 结束年龄
         * @return 结束年龄
         */
        int get_end_age() const;

    protected:
        /**
         * @brief 八字
         */
        EightChar eight_char;

        /**
         * @brief 性别
         */
        Gender gender;

        /**
         * @brief 顺逆
         */
        bool forward;

        /**
         * @brief 童限信息
         */
        ChildLimitInfo info;

    private:
        bool get_forward(const EightChar &ec, Gender g);

        ChildLimitInfo get_info(const SolarTime &birth_time, bool f);
    };

    /**
     * @brief 小运
     */
    class Fortune : public AbstractCulture {
    public:
        ~Fortune() override = default;

        explicit Fortune(const ChildLimit &child_limit, const int index): child_limit(child_limit), index(index) {
        }

        static Fortune from_child_limit(const ChildLimit &child_limit, int index);

        /**
         * @brief 年龄
         * @return 年龄
         */
        int get_age() const;

        /**
         * @brief 干支年
         * @return 干支年
         */
        SixtyCycleYear get_sixty_cycle_year() const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        string get_name() const override;

        Fortune next(int n) const;

    protected:
        /**
         * @brief 童限
         */
        ChildLimit child_limit;

        /**
         * @brief 序号
         */
        int index;
    };

    /**
     * @brief 大运
     */
    class DecadeFortune : public AbstractCulture {
    public:
        ~DecadeFortune() override = default;

        explicit DecadeFortune(const ChildLimit &child_limit, int index): child_limit(child_limit), index(index) {
        }

        static DecadeFortune from_child_limit(const ChildLimit &child_limit, int index);

        /**
         * @brief 开始年龄
         * @return 开始年龄
         */
        int get_start_age() const;

        /**
         * @brief 结束年龄
         * @return 结束年龄
         */
        int get_end_age() const;

        /**
         * @brief 开始干支年
         * @return 干支年
         */
        SixtyCycleYear get_start_sixty_cycle_year() const;

        /**
         * @brief 结束干支年
         * @return 干支年
         */
        SixtyCycleYear get_end_sixty_cycle_year() const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        string get_name() const override;

        DecadeFortune next(int n) const;

        /**
         * @brief 开始小运
         * @return 小运
         */
        Fortune get_start_fortune() const;

    protected:
        /**
         * @brief 童限
         */
        ChildLimit child_limit;

        /**
         * @brief 序号
         */
        int index;
    };
}
#endif
