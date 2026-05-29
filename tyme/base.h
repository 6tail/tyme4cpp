#ifndef TYME_BASE_H
#define TYME_BASE_H
#include "tymeconfig.h"

namespace tyme {
    /**
     * @brief 性别
     */
    enum class Gender {
        WOMAN = 0,
        MAN = 1
    };

    /**
     * @brief 藏干类型
     */
    enum class HideHeavenStemType {
        RESIDUAL = 0,
        MIDDLE = 1,
        MAIN = 2
    };

    /**
     * @brief 内外
     */
    enum class Side {
        IN = 0,
        OUT = 1
    };

    /**
     * @brief 阴阳
     */
    enum class YinYang {
        YIN = 0,
        YANG = 1
    };

    /**
     * @brief 事件类型
     */
    enum class EventType {
        SOLAR_DAY = 0,
        SOLAR_WEEK = 1,
        LUNAR_DAY = 2,
        TERM_DAY = 3,
        TERM_HS = 4,
        TERM_EB = 5
    };

    /**
     * @brief 传统文化(民俗)
     */
    class Culture {
    public:
        virtual ~Culture() = default;

        /**
         * @brief 名称
         * @return 名称
         */
        virtual string get_name() const = 0;

        /**
         * @brief 描述
         * @return 描述
         */
        virtual string to_string() const = 0;
    };

    /**
     * @brief 传统文化抽象
     */
    class AbstractCulture : public Culture {
    public:
        ~AbstractCulture() override = default;

        bool equals(const Culture *o) const;

        /**
         * @brief 名称
         * @return 名称
         */
        string get_name() const override;

        /**
         * @brief 描述
         * @return 描述
         */
        string to_string() const override;

        /**
         * @brief 转换为不超范围的索引
         * @param index 索引
         * @param size 数量
         * @return 索引，从0开始
         */
        static int index_of(int index, int size);
    };

    /**
     * @brief 年
     */
    class YearUnit : public AbstractCulture {
    public:
        ~YearUnit() override = default;

        explicit YearUnit(const int year) : AbstractCulture() {
            this->year = year;
        }

        /**
         * @brief 年
         * @return 年
         */
        int get_year() const;
    protected:
        /**
         * @brief 年
         */
        int year;
    };

    /**
     * @brief 月
     */
    class MonthUnit : public YearUnit {
    public:
        ~MonthUnit() override = default;

        explicit MonthUnit(const int year, const int month) : YearUnit(year) {
            this->month = month;
        }

        /**
         * @brief 月
         * @return 月
         */
        int get_month() const;
    protected:
        /**
         * @brief 月
         */
        int month;
    };

    /**
     * @brief 日
     */
    class DayUnit : public MonthUnit {
    public:
        ~DayUnit() override = default;

        explicit DayUnit(const int year, const int month, const int day) : MonthUnit(year, month) {
            this->day = day;
        }

        /**
         * @brief 日
         * @return 日
         */
        int get_day() const;
    protected:
        /**
         * @brief 日
         */
        int day;
    };

    /**
     * @brief 周
     */
    class WeekUnit : public MonthUnit {
    public:
        ~WeekUnit() override = default;

        static const vector<string> NAMES;

        explicit WeekUnit(const int year, const int month, const int index, const int start) : MonthUnit(year, month) {
            this->index = index;
            this->start = start;
        }

        static void validate(int index, int start);

        /**
         * @brief 索引
         * @return 索引，0-5
         */
        int get_index() const;

        /**
         * @brief 起始星期
         * @return 起始星期，1234560分别代表星期一至星期天
         */
        int get_start() const;
    protected:
        /**
         * @brief 索引，0-5
         */
        int index;

        /**
         * @brief 起始星期，1234560分别代表星期一至星期天
         */
        int start;
    };

    /**
     * @brief 秒
     */
    class SecondUnit : public DayUnit {
    public:
        ~SecondUnit() override = default;

        explicit SecondUnit(const int year, const int month, const int day, const int hour, const int minute, const int second) : DayUnit(year, month, day) {
            this->hour = hour;
            this->minute = minute;
            this->second = second;
        }

        static void validate(int hour, int minute, int second);

        /**
         * @brief 时
         * @return 时
         */
        int get_hour() const;

        /**
         * @brief 分
         * @return 分
         */
        int get_minute() const;

        /**
         * @brief 秒
         * @return 秒
         */
        int get_second() const;
    protected:
        /**
         * @brief 时
         */
        int hour;

        /**
         * @brief 分
         */
        int minute;

        /**
         * @brief 秒
         */
        int second;
    };

    /**
     * @brief 可轮回的Tyme
     */
    class LoopTyme : public AbstractCulture {
    public:
        ~LoopTyme() override = default;

        /**
         * @brief 通过索引初始化
         * @param names 名称列表
         * @param index 索引，支持负数，自动轮转
         */
        LoopTyme(const vector<string> &names, const int index) : names(names), index(index_of(index)) {
        }

        /**
         * @brief 通过名称初始化
         * @param names 名称列表
         * @param name 名称
         */
        LoopTyme(const vector<string> &names, const string &name) : names(names), index(index_of(name)) {
        }

        LoopTyme(const LoopTyme &other) {
            names = other.names;
            index = other.get_index();
        }

        LoopTyme& operator=(const LoopTyme &other) {
            if (this != &other) {
                names = other.names;
                index = other.get_index();
            }
            return *this;
        }

        /**
         * @brief 索引
         * @return 索引，从0开始
         */
        int get_index() const;

        /**
         * @brief 数量
         * @return 数量
         */
        int get_size() const;

        /**
         * @brief 名称
         * @return 名称
         */
        string get_name() const override;

        /**
         * @brief 名称对应的索引
         * @param name 名称
         * @return 索引，从0开始
         */
        int index_of(const string &name) const;

        /**
         * @brief 转换为不超范围的索引
         * @param i 索引
         * @return 索引，从0开始
         */
        int index_of(int i) const;

        /**
         * @brief 推移后的索引
         * @param n 推移步数
         * @return 索引，从0开始
         */
        int next_index(int n) const;

        /**
         * @brief 到目标索引的步数（从左往右顺序）
         * @param target_index 目标索引
         * @return 步数（>=0）
         */
        int steps_to(int target_index) const;

        /**
         * @brief 到目标索引的步数（从右往左逆序）
         * @param target_index 目标索引
         * @return 步数（<=0）
         */
        int steps_back_to(int target_index) const;

        /**
         * @brief 到目标索引的最少步数
         * @param target_index 目标索引
         * @return 步数（从左往右顺序>=0，从右往左逆序<=0）
         */
        int steps_close_to(int target_index) const;

    protected:
        /**
         * @brief 名称列表
         */
        vector<string> names;

        /**
         * @brief 索引，从0开始
         */
        int index;
    };
}
#endif
