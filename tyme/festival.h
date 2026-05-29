#ifndef TYME_FESTIVAL_H
#define TYME_FESTIVAL_H
#include "childlimit.h"

namespace tyme {
    /**
     * @brief 法定假日（自2001-12-29起）
     */
    class LegalHoliday : public AbstractCulture {
    public:
        ~LegalHoliday() override = default;

        static const vector<string> NAMES;
        static string DATA;

        explicit LegalHoliday(const int year, const int month, const int day, const string &data): day(SolarDay::from_ymd(year, month, day)), name(NAMES[data[9] - '0']), work(data[8] == '0'), target(compute_target(data)) {
        }

        static optional<LegalHoliday> from_ymd(int year, int month, int day);

        SolarDay get_day() const;

        SolarDay get_target() const;

        bool is_work() const;

        optional<LegalHoliday> next(int n) const;

        string to_string() const override;

        string get_name() const override;

    protected:
        /**
         * @brief 公历日
         */
        SolarDay day;

        /**
         * @brief 名称
         */
        string name;

        /**
         * @brief 是否上班
         */
        bool work;

        /**
         * @brief 节假日当天的公历日
         */
        SolarDay target;

    private:
        SolarDay compute_target(const string &data) const;
    };

    /**
     * @brief 事件构造器
     */
    class EventBuilder;

    /**
     * @brief 事件
     */
    class Event : public AbstractCulture {
    public:
        ~Event() override = default;

        explicit Event(string name, const string& data): name(std::move(name)), data(data) {
            validate(data);
        }

        static void validate(const string &data);

        static EventBuilder builder();

        static optional<Event> from_name(const string &name);

        /**
         * @brief 指定公历日的事件列表
         * @param d 公历日
         * @return 事件列表
         */
        static vector<Event> from_solar_day(const SolarDay &d);

        /**
         * @brief 所有事件
         * @return 事件列表
         */
        static vector<Event> all();

        int get_value(int index) const;

        array<int, 2> get_month(int year) const;

        /**
         * @brief 事件类型
         * @return 事件类型
         */
        EventType get_type() const;

        /**
         * @brief 名称
         * @return 名称
         */
        string get_name() const override;

        /**
         * @brief 数据
         * @return 数据
         */
        string get_data() const;

        /**
         * @brief 起始年
         * @return 年
         */
        int get_start_year() const;

        /**
         * @brief 公历日
         * @param year 年
         * @return 公历日，如果当年没有该事件，返回nullopt
         */
        optional<SolarDay> get_solar_day(int year) const;

    protected:
        friend class EventBuilder;

        int get_char_index(int index) const;

        optional<SolarDay> get_solar_day_by_solar_day(int year) const;

        optional<SolarDay> get_solar_day_by_lunar_day(int year) const;

        optional<SolarDay> get_solar_day_by_week(int year) const;

        optional<SolarDay> get_solar_day_by_term(int year) const;

        optional<SolarDay> get_solar_day_by_term_heaven_stem(int year) const;

        optional<SolarDay> get_solar_day_by_term_earth_branch(int year) const;

        /**
         * @brief 名称
         */
        string name;

        /**
         * @brief 数据
         */
        string data;
    };

    /**
     * @brief 事件构造器
     */
    class EventBuilder {
    public:
        EventBuilder() = default;

        EventBuilder name(const string &name);

        /**
         * @brief 公历日
         * @param solar_month 公历月（1至12）
         * @param solar_day 公历日（1至31）
         * @param delay_days 顺延天数，例如生日在2月29，非闰年没有2月29，是+1天，还是-1天（最远支持-31至31天）
         * @return 事件构建器
         */
        EventBuilder solar_day(int solar_month, int solar_day, int delay_days);

        /**
         * @brief 农历日
         * @param lunar_month 农历月（-12至-1，1至12，闰月为负）
         * @param lunar_day 农历日（1至30）
         * @param delay_days 顺延天数，例如生日在某月的三十，但下一年当月可能只有29天，是+1天，还是-1天（最远支持-31至31天）
         * @return 事件构建器
         */
        EventBuilder lunar_day(int lunar_month, int lunar_day, int delay_days);

        /**
         * @brief 公历第几个星期几
         * @param solar_month 公历月（1至12）
         * @param week_index 第几个星期（1为第1个星期，-1为倒数第1个星期）
         * @param week 星期几（0至6，0代表星期天，1代表星期一）
         * @return 事件构建器
         */
        EventBuilder solar_week(int solar_month, int week_index, int week);

        /**
         * @brief 节气
         * @param term_index 节气索引（0至23）
         * @param delay_days 顺延天数（最远支持-31至31天）
         * @return 事件构建器
         */
        EventBuilder term_day(int term_index, int delay_days);

        /**
         * @brief 节气天干
         * @param term_index 节气索引（0至23）
         * @param heaven_stem_index 天干索引（0至9）
         * @param delay_days 顺延天数（最远支持-31至31天）
         * @return 事件构建器
         */
        EventBuilder term_heaven_stem(int term_index, int heaven_stem_index, int delay_days);

        /**
         * @brief 节气地支
         * @param term_index 节气索引（0至23）
         * @param earth_branch_index 地支索引（0至11）
         * @param delay_days 顺延天数（最远支持-31至31天）
         * @return 事件构建器
         */
        EventBuilder term_earth_branch(int term_index, int earth_branch_index, int delay_days);

        /**
         * @brief 起始年
         * @param year 年
         * @return 事件构造器
         */
        EventBuilder start_year(int year);

        /**
         * @brief 偏移天数
         * @param days 天数（最远支持-31至31天）
         * @return 事件构造器
         */
        EventBuilder offset(int days);

        /**
         * @brief 生成事件
         * @return 事件
         */
        Event build() const;

    protected:
        static char get_char(int index);

        EventBuilder &set_value(int index, int n);

        EventBuilder &content(EventType type, int a, int b, int c);

        /**
         * @brief 编码事件类型
         * @param type 事件类型
         * @return 编码
         */
        static char encode_type(const EventType &type);

        /**
         * @brief 事件名称
         */
        string _name;

        /**
         * @brief 事件数据
         */
        array<char, 9> data = {'@', '_', '_', '_', '_', '_', '0', '0', '0'};
    };

    /**
     * @brief 事件管理器
     */
    class EventManager {
    public:
        /**
         * @brief 有效字符
         */
        static const string CHARS;

        /**
         * @brief 数据匹配的正则表达式
         */
        static const string REGEX;

        /**
         * @brief 全量事件数据
         */
        static string DATA;

        /**
         * @brief 删除事件
         * @param name 名称
         */
        static void remove(const string &name);

        /**
         * @brief 新增或更新事件
         * @param name 名称
         * @param event 事件
         */
        static void update(const string &name, const Event &event);

        /**
         * @brief 新增或更新事件
         * @param name 名称
         * @param data 事件数据
         */
        static void update_data(const string &name, const string &data);

    protected:
        static void save_or_update(const string &name, const string &data);
    };

    /**
     * @brief 节日抽象
     */
    class AbstractFestival : public AbstractCulture {
    public:
        ~AbstractFestival() override = default;

        explicit AbstractFestival(const int index, const Event& event, const DayUnit& day): index(index), event(event), day(day) {
        }

        /**
         * @brief 索引
         * @return 索引
         */
        int get_index() const;

        /**
         * @brief 日
         * @return 日
         */
        DayUnit get_day() const;

        string get_name() const override;
    protected:
        /**
         * @brief 索引
         */
        int index;

        /**
         * @brief 事件
         */
        Event event;

        /**
         * @brief 日
         */
        DayUnit day;
    };

    /**
     * @brief 公历现代节日
     */
    class SolarFestival : public AbstractFestival {
    public:
        ~SolarFestival() override = default;

        static const vector<string> NAMES;
        static string DATA;

        explicit SolarFestival(const int index, const Event& event, const SolarDay& day) : AbstractFestival(index, event, day) {
        }

        static optional<SolarFestival> from_index(int year, int index);

        static optional<SolarFestival> from_ymd(int year, int month, int day);

        SolarDay get_day() const;

        int get_start_year() const;

        optional<SolarFestival> next(int n) const;

        string to_string() const override;
    };

    /**
     * @brief 农历传统节日（依据国家标准《农历的编算和颁行》GB/T 33661-2017）
     */
    class LunarFestival : public AbstractFestival {
    public:
        ~LunarFestival() override = default;

        static const vector<string> NAMES;
        static string DATA;

        explicit LunarFestival(const int index, const Event& event, const LunarDay& day) : AbstractFestival(index, event, day) {
        }

        static optional<LunarFestival> from_index(int year, int index);

        static optional<LunarFestival> from_ymd(int year, int month, int day);

        LunarDay get_day() const;

        optional<SolarTerm> get_solar_term() const;

        optional<LunarFestival> next(int n) const;

        string to_string() const override;
    };
}
#endif
