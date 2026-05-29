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
    const double JulianDay::J2000 = 2451545;

    JulianDay JulianDay::from_julian_day(const double day) {
        return JulianDay(day);
    }

    JulianDay JulianDay::from_ymd_hms(const int year, const int month, const int day, const int hour, const int minute, const int second) {
        int y = year;
        int m = month;
        const double d = day + ((second * 1.0 / 60 + minute) / 60 + hour) / 24;
        int n = 0;
        const bool g = y * 372 + m * 31 + static_cast<int>(d) >= 588829;
        if (m <= 2) {
            m += 12;
            y--;
        }
        if (g) {
            n = static_cast<int>(y * 0.01);
            n = 2 - n + static_cast<int>(n * 0.25);
        }
        return from_julian_day(static_cast<int>(365.25 * (y + 4716)) + static_cast<int>(30.6001 * (m + 1)) + d + n - 1524.5);
    }

    double JulianDay::get_day() const {
        return day;
    }

    string JulianDay::get_name() const {
        return std::to_string(day);
    }

    JulianDay JulianDay::next(const int n) const {
        return from_julian_day(day + n);
    }

    Week JulianDay::get_week() const {
        return Week::from_index(static_cast<int>(floor(day + 0.5)) + 7000001);
    }

    double JulianDay::subtract(const JulianDay &target) const {
        return day - target.get_day();
    }

    SolarTime JulianDay::get_solar_time() const {
        int d = static_cast<int>(floor(day + 0.5));
        double f = day + 0.5 - d;

        if (d >= 2299161) {
            const int c = static_cast<int>((d - 1867216.25) / 36524.25);
            d += 1 + c - static_cast<int>(c * 0.25);
        }
        d += 1524;
        int y = static_cast<int>((d - 122.1) / 365.25);
        d -= static_cast<int>(365.25 * y);
        int m = static_cast<int>(d / 30.601);
        d -= static_cast<int>(30.601 * m);
        if (m > 13) {
            m -= 12;
        } else {
            y -= 1;
        }
        m -= 1;
        y -= 4715;
        f *= 24;
        const int hour = static_cast<int>(f);

        f -= hour;
        f *= 60;
        const int minute = static_cast<int>(f);

        f -= minute;
        f *= 60;
        const int second = static_cast<int>(round(f));
        if (second < 60) {
            return SolarTime::from_ymd_hms(y, m, d, hour, minute, second);
        }
        return SolarTime::from_ymd_hms(y, m, d, hour, minute, second - 60).next(60);
    }

    SolarDay JulianDay::get_solar_day() const {
        return get_solar_time().get_solar_day();
    }
    const vector<string> SolarTerm::NAMES = {
        "冬至", "小寒", "大寒", "立春", "雨水", "惊蛰", "春分", "清明", "谷雨", "立夏", "小满", "芒种", "夏至", "小暑", "大暑", "立秋", "处暑", "白露", "秋分", "寒露", "霜降", "立冬", "小雪", "大雪"
    };

    void SolarTerm::init_by_year(const int y, const int offset) {
        const double jd = floor((y - 2000) * 365.2422 + 180);
        // 355是2000.12冬至，得到较靠近jd的冬至估计值
        double w = floor((jd - 355 + 183) / 365.2422) * 365.2422 + 355;
        if (ShouXingUtil::calc_qi(w) > jd) {
            w -= 365.2422;
        }
        this->year = y;
        cursory_julian_day = ShouXingUtil::calc_qi(w + 15.2184 * offset);
    }

    SolarTerm SolarTerm::from_index(const int year, const int index) {
        return SolarTerm(year, index);
    }

    SolarTerm SolarTerm::from_name(const int year, const string &name) {
        return SolarTerm(year, name);
    }

    SolarTerm SolarTerm::next(const int n) const {
        const int size = get_size();
        const int i = index + n;
        return from_index((year * size + i) / size, index_of(i));
    }

    bool SolarTerm::is_jie() const {
        return index % 2 == 1;
    }

    bool SolarTerm::is_qi() const {
        return index % 2 == 0;
    }

    JulianDay SolarTerm::get_julian_day() const {
        return JulianDay::from_julian_day(ShouXingUtil::qi_accurate2(cursory_julian_day) + JulianDay::J2000);
    }

    SolarDay SolarTerm::get_solar_day() const {
        return JulianDay::from_julian_day(cursory_julian_day + JulianDay::J2000).get_solar_day();
    }

    int SolarTerm::get_year() const {
        return year;
    }

    double SolarTerm::get_cursory_julian_day() const {
        return cursory_julian_day;
    }

    SolarTerm SolarTermDay::get_solar_term() const {
        return solar_term;
    }

    int SolarTermDay::get_day_index() const {
        return day_index;
    }

    string SolarTermDay::get_name() const {
        return solar_term.get_name();
    }

    string SolarTermDay::to_string() const {
        return solar_term.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }
    void SolarYear::validate(const int year) {
        if (year < 1 || year > 9999) {
            throw invalid_argument("illegal solar year: " + std::to_string(year));
        }
    }

    SolarYear SolarYear::from_year(const int year) {
        return SolarYear(year);
    }

    int SolarYear::get_day_count() const {
        if (1582 == year) {
            return 355;
        }
        if (is_leap()) {
            return 366;
        }
        return 365;
    }

    bool SolarYear::is_leap() const {
        if (year < 1600) {
            return year % 4 == 0;
        }
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    string SolarYear::get_name() const {
        return std::to_string(year) + "年";
    }

    SolarYear SolarYear::next(const int n) const {
        return from_year(year + n);
    }

    vector<SolarMonth> SolarYear::get_months() const {
        auto l = vector<SolarMonth>();
        for (int i = 1; i < 13; i++) {
            l.push_back(SolarMonth::from_ym(year, i));
        }
        return l;
    }

    vector<SolarSeason> SolarYear::get_seasons() const {
        auto l = vector<SolarSeason>();
        for (int i = 0; i < 4; i++) {
            l.push_back(SolarSeason::from_index(year, i));
        }
        return l;
    }

    vector<SolarHalfYear> SolarYear::get_half_years() const {
        auto l = vector<SolarHalfYear>();
        for (int i = 0; i < 2; i++) {
            l.push_back(SolarHalfYear::from_index(year, i));
        }
        return l;
    }

    const vector<string> SolarHalfYear::NAMES = {
        "上半年", "下半年"
    };

    void SolarHalfYear::validate(const int year, const int index) {
        if (index < 0 || index > 1) {
            throw invalid_argument("illegal solar half year index: " + std::to_string(index));
        }
        SolarYear::validate(year);
    }


    SolarHalfYear SolarHalfYear::from_index(const int year, const int index) {
        return SolarHalfYear(year, index);
    }

    SolarYear SolarHalfYear::get_solar_year() const {
        return SolarYear::from_year(year);
    }

    int SolarHalfYear::get_index() const {
        return index;
    }

    string SolarHalfYear::get_name() const {
        return NAMES[index];
    }

    string SolarHalfYear::to_string() const {
        return get_solar_year().to_string() + get_name();
    }

    SolarHalfYear SolarHalfYear::next(const int n) const {
        const int i = index + n;
        return from_index((year * 2 + i) / 2, index_of(i, 2));
    }

    vector<SolarSeason> SolarHalfYear::get_seasons() const {
        auto l = vector<SolarSeason>();
        for (int i = 0; i < 2; i++) {
            l.push_back(SolarSeason::from_index(year, index * 2 + i));
        }
        return l;
    }

    vector<SolarMonth> SolarHalfYear::get_months() const {
        auto l = vector<SolarMonth>();
        for (int i = 1; i < 7; i++) {
            l.push_back(SolarMonth::from_ym(year, index * 6 + i));
        }
        return l;
    }

    const vector<string> SolarSeason::NAMES = {
        "一季度", "二季度", "三季度", "四季度"
    };

    void SolarSeason::validate(const int year, const int index) {
        if (index < 0 || index > 3) {
            throw invalid_argument("illegal solar season index: " + std::to_string(index));
        }
        SolarYear::validate(year);
    }

    SolarSeason SolarSeason::from_index(const int year, const int index) {
        return SolarSeason(year, index);
    }

    SolarYear SolarSeason::get_solar_year() const {
        return SolarYear::from_year(year);
    }

    int SolarSeason::get_index() const {
        return index;
    }

    string SolarSeason::get_name() const {
        return NAMES[index];
    }

    string SolarSeason::to_string() const {
        return get_solar_year().to_string() + get_name();
    }

    SolarSeason SolarSeason::next(const int n) const {
        const int i = index + n;
        return from_index((year * 4 + i) / 4, index_of(i, 4));
    }

    vector<SolarMonth> SolarSeason::get_months() const {
        auto l = vector<SolarMonth>();
        for (int i = 1; i < 4; i++) {
            l.push_back(SolarMonth::from_ym(year, index * 3 + i));
        }
        return l;
    }

    const vector<string> SolarMonth::NAMES = {
        "1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月"
    };

    const int SolarMonth::DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    void SolarMonth::validate(const int year, const int month) {
        if (month < 1 || month > 12) {
            throw invalid_argument("illegal solar month: " + std::to_string(month));
        }
        SolarYear::validate(year);
    }

    SolarMonth SolarMonth::from_ym(const int year, const int month) {
        return SolarMonth(year, month);
    }

    SolarYear SolarMonth::get_solar_year() const {
        return SolarYear::from_year(year);
    }

    int SolarMonth::get_day_count() const {
        if (1582 == year && 10 == month) {
            return 21;
        }
        int d = DAYS[get_index_in_year()];
        //公历闰年2月多一天
        if (2 == month && get_solar_year().is_leap()) {
            d++;
        }
        return d;
    }

    int SolarMonth::get_index_in_year() const {
        return month - 1;
    }

    SolarSeason SolarMonth::get_season() const {
        return SolarSeason::from_index(year, get_index_in_year() / 3);
    }

    int SolarMonth::get_week_count(const int start) const {
        return static_cast<int>(ceil((index_of(SolarDay::from_ymd(year, month, 1).get_week().get_index() - start, 7) + get_day_count()) / 7.0));
    }

    string SolarMonth::get_name() const {
        return NAMES[get_index_in_year()];
    }

    string SolarMonth::to_string() const {
        return get_solar_year().to_string() + get_name();
    }

    SolarMonth SolarMonth::next(const int n) const {
        const int i = month - 1 + n;
        return from_ym((year * 12 + i) / 12, index_of(i, 12) + 1);
    }

    vector<SolarWeek> SolarMonth::get_weeks(const int start) const {
        const int size = get_week_count(start);
        auto l = vector<SolarWeek>();
        for (int i = 0; i < size; i++) {
            l.push_back(SolarWeek::from_ym(year, month, i, start));
        }
        return l;
    }

    vector<SolarDay> SolarMonth::get_days() const {
        const int size = get_day_count();
        auto l = vector<SolarDay>();
        for (int i = 1; i <= size; i++) {
            l.push_back(SolarDay::from_ymd(year, month, i));
        }
        return l;
    }

    SolarDay SolarMonth::get_first_day() const {
        return SolarDay::from_ymd(year, month, 1);
    }

    void SolarWeek::validate(const int year, const int month, const int index, const int start) {
        WeekUnit::validate(index, start);
        if (const SolarMonth m = SolarMonth::from_ym(year, month); index >= m.get_week_count(start)) {
            throw invalid_argument("illegal solar week index: " + std::to_string(index) + " in month: " + m.to_string());
        }
    }

    SolarWeek SolarWeek::from_ym(const int year, const int month, const int index, const int start) {
        return SolarWeek(year, month, index, start);
    }

    SolarMonth SolarWeek::get_solar_month() const {
        return SolarMonth::from_ym(year, month);
    }

    int SolarWeek::get_index_in_year() const {
        int i = 0;
        const SolarDay first_day = get_first_day();
        // 今年第1周
        SolarWeek w = from_ym(year, 1, 0, start);
        while (!w.get_first_day().equals(first_day)) {
            w = w.next(1);
            i++;
        }
        return i;
    }

    string SolarWeek::get_name() const {
        return NAMES[index];
    }

    string SolarWeek::to_string() const {
        return get_solar_month().to_string() + get_name();
    }

    SolarWeek SolarWeek::next(const int n) const {
        int d = index + n;
        SolarMonth m = get_solar_month();
        if (n > 0) {
            int week_count = m.get_week_count(start);
            while (d >= week_count) {
                d -= week_count;
                m = m.next(1);
                if (m.get_first_day().get_week().get_index() != start) {
                    d += 1;
                }
                week_count = m.get_week_count(start);
            }
        } else if (n < 0) {
            while (d < 0) {
                if (m.get_first_day().get_week().get_index() != start) {
                    d -= 1;
                }
                m = m.next(-1);
                d += m.get_week_count(start);
            }
        }
        return from_ym(m.get_year(), m.get_month(), d, start);
    }

    SolarDay SolarWeek::get_first_day() const {
        const SolarDay first_day = SolarDay::from_ymd(year, month, 1);
        return first_day.next(index * 7 - index_of(first_day.get_week().get_index() - start, 7));
    }

    vector<SolarDay> SolarWeek::get_days() const {
        auto l = vector<SolarDay>();
        const SolarDay d = get_first_day();
        l.push_back(d);
        for (int i = 1; i < 7; i++) {
            l.push_back(d.next(i));
        }
        return l;
    }

    bool SolarWeek::equals(const SolarWeek &other) const {
        return get_first_day().equals(other.get_first_day());
    }

    const vector<string> SolarDay::NAMES = {
        "1日", "2日", "3日", "4日", "5日", "6日", "7日", "8日", "9日", "10日", "11日", "12日", "13日", "14日", "15日", "16日", "17日", "18日", "19日", "20日", "21日", "22日", "23日", "24日", "25日", "26日", "27日", "28日", "29日", "30日", "31日"
    };

    void SolarDay::validate(const int year, const int month, int day) {
        if (day < 1) {
            throw invalid_argument("illegal solar day: " + std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day));
        }
        if (1582 == year && 10 == month) {
            if ((day > 4 && day < 15) || day > 31) {
                throw invalid_argument("illegal solar day: " + std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day));
            }
        } else if (day > SolarMonth::from_ym(year, month).get_day_count()) {
            throw invalid_argument("illegal solar day: " + std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day));
        }
    }

    SolarDay SolarDay::from_ymd(const int year, const int month, const int day) {
        return SolarDay(year, month, day);
    }

    SolarMonth SolarDay::get_solar_month() const {
        return SolarMonth::from_ym(year, month);
    }

    Week SolarDay::get_week() const {
        return get_julian_day().get_week();
    }

    Constellation SolarDay::get_constellation() const {
        const int y = month * 100 + day;
        int i = 8;
        if (y > 1221 || y < 120) {
            i = 9;
        } else if (y < 219) {
            i = 10;
        } else if (y < 321) {
            i = 11;
        } else if (y < 420) {
            i = 0;
        } else if (y < 521) {
            i = 1;
        } else if (y < 622) {
            i = 2;
        } else if (y < 723) {
            i = 3;
        } else if (y < 823) {
            i = 4;
        } else if (y < 923) {
            i = 5;
        } else if (y < 1024) {
            i = 6;
        } else if (y < 1123) {
            i = 7;
        }
        return Constellation::from_index(i);
    }

    string SolarDay::get_name() const {
        return NAMES[day - 1];
    }

    string SolarDay::to_string() const {
        return get_solar_month().to_string() + get_name();
    }

    JulianDay SolarDay::get_julian_day() const {
        return JulianDay::from_ymd_hms(year, month, day, 0, 0, 0);
    }

    SolarDay SolarDay::next(const int n) const {
        return get_julian_day().next(n).get_solar_day();
    }

    bool SolarDay::is_before(const SolarDay &other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }

    bool SolarDay::is_after(const SolarDay &other) const {
        if (year != other.year) {
            return year > other.year;
        }
        if (month != other.month) {
            return month > other.month;
        }
        return day > other.day;
    }

    SolarTerm SolarDay::get_term() const {
        return get_term_day().get_solar_term();
    }

    SolarTermDay SolarDay::get_term_day() const {
        int y = year;
        int i = month * 2;
        if (i == 24) {
            y += 1;
            i = 0;
        }
        SolarTerm term = SolarTerm::from_index(y, i + 1);
        SolarDay d = term.get_solar_day();
        while (is_before(d)) {
            term = term.next(-1);
            d = term.get_solar_day();
        }
        return SolarTermDay(term, subtract(d));
    }

    SolarWeek SolarDay::get_solar_week(const int start) const {
        return SolarWeek::from_ym(year, month, static_cast<int>(ceil((day + from_ymd(year, month, 1).get_week().next(-start).get_index()) / 7.0)) - 1, start);
    }

    Phenology SolarDay::get_phenology() const {
        return get_phenology_day().get_phenology();
    }

    PhenologyDay SolarDay::get_phenology_day() const {
        const SolarTermDay d = get_term_day();
        const int day_index = d.get_day_index();
        int index = day_index / 5;
        if (index > 2) {
            index = 2;
        }
        const SolarTerm term = d.get_solar_term();
        return PhenologyDay(Phenology::from_index(term.get_year(), term.get_index() * 3 + index), day_index - index * 5);
    }

    optional<DogDay> SolarDay::get_dog_day() const {
        // 初伏，夏至后第3个庚日
        const SolarDay d0 = Event::builder().term_heaven_stem(12, 6, 20).build().get_solar_day(year).value();
        // 中伏，夏至后第4个庚日
        const SolarDay d1 = Event::builder().term_heaven_stem(12, 6, 30).build().get_solar_day(year).value();
        // 末伏，立秋后第1个庚日
        const SolarDay d2 = Event::builder().term_heaven_stem(15, 6, 0).build().get_solar_day(year).value();
        if (is_before(d0) || is_after(d2.next(9))) {
            return nullopt;
        }
        if (!is_before(d2)) {
            return DogDay(Dog::from_index(2), subtract(d2));
        }
        return is_before(d1) ? DogDay(Dog::from_index(0), subtract(d0)) : DogDay(Dog::from_index(1), subtract(d1));
    }

    optional<NineDay> SolarDay::get_nine_day() const {
        SolarDay start = SolarTerm::from_index(year + 1, 0).get_solar_day();
        if (is_before(start)) {
            start = SolarTerm::from_index(year, 0).get_solar_day();
        }
        if (const SolarDay end = start.next(81); is_before(start) || !is_before(end)) {
            return nullopt;
        }
        const int days = subtract(start);
        return NineDay(Nine::from_index(days / 9), days % 9);
    }

    optional<PlumRainDay> SolarDay::get_plum_rain_day() const {
        // 入梅，芒种后第1个丙日
        const SolarDay start = Event::builder().term_heaven_stem(11, 2, 0).build().get_solar_day(year).value();
        // 出梅，小暑后第1个未日
        const SolarDay end = Event::builder().term_earth_branch(13, 7, 0).build().get_solar_day(year).value();
        if (is_before(start) || is_after(end)) {
            return nullopt;
        }
        return equals(end) ? PlumRainDay(PlumRain::from_index(1), 0) : PlumRainDay(PlumRain::from_index(0), subtract(start));
    }

    HideHeavenStemDay SolarDay::get_hide_heaven_stem_day() const {
        SolarTerm term = get_term();
        if (term.is_qi()) {
            term = term.next(-1);
        }
        int day_index = subtract(term.get_solar_day());
        const int start_index = (term.get_index() - 1) * 3;
        string data = "93705542220504xx1513904541632524533533105544806564xx7573304542018584xx95";
        data = data.substr(start_index, 6);
        int days = 0;
        int heaven_stem_index = 0;
        int type_index = 0;
        while (type_index < 3) {
            const int i = type_index * 2;
            string d = data.substr(i, 1);
            int count = 0;
            if (d != "x") {
                const int day_counts[] = {3, 5, 7, 9, 10, 30};
                heaven_stem_index = stoi(d);
                count = day_counts[stoi(data.substr(i + 1, 1))];
                days += count;
            }
            if (day_index <= days) {
                day_index -= days - count;
                break;
            }
            type_index++;
        }
        HideHeavenStemType type;
        switch (type_index) {
            case 1:
                type = HideHeavenStemType::MIDDLE;
                break;
            case 2:
                type = HideHeavenStemType::MAIN;
                break;
            default:
                type = HideHeavenStemType::RESIDUAL;
        }
        return HideHeavenStemDay(HideHeavenStem(heaven_stem_index, type), day_index);
    }

    int SolarDay::get_index_in_year() const {
        return subtract(from_ymd(year, 1, 1));
    }

    int SolarDay::subtract(const SolarDay &other) const {
        return static_cast<int>(get_julian_day().subtract(other.get_julian_day()));
    }

    bool SolarDay::equals(const SolarDay &other) const {
        return to_string() == other.to_string();
    }

    LunarDay SolarDay::get_lunar_day() const {
        LunarMonth m = LunarMonth::from_ym(year, month);
        int days = subtract(m.get_first_julian_day().get_solar_day());
        while (days < 0) {
            m = m.next(-1);
            days += m.get_day_count();
        }
        return LunarDay::from_ymd(m.get_year(), m.get_month_with_leap(), days + 1);
    }

    SixtyCycleDay SolarDay::get_sixty_cycle_day() const {
        return SixtyCycleDay::from_solar_day(*this);
    }

    RabByungDay SolarDay::get_rab_byung_day() const {
        return RabByungDay::from_solar_day(*this);
    }

    optional<SolarFestival> SolarDay::get_festival() const {
        return SolarFestival::from_ymd(year, month, day);
    }

    PhaseDay SolarDay::get_phase_day() const {
        const LunarMonth m = get_lunar_day().get_lunar_month().next(1);
        Phase p = Phase::from_index(m.get_year(), m.get_month_with_leap(), 0);
        SolarDay d = p.get_solar_day();
        while (d.is_after(*this)) {
            p = p.next(-1);
            d = p.get_solar_day();
        }
        return PhaseDay(p, subtract(d));
    }

    Phase SolarDay::get_phase() const {
        return get_phase_day().get_phase();
    }

    NineStar SolarDay::get_nine_star() const {
        const int y = get_year();
        const SolarDay winter_solstice = SolarTerm::from_index(y, 0).get_solar_day();
        const SolarDay summer_solstice = SolarTerm::from_index(y, 12).get_solar_day();
        const SolarDay next_winter_solstice =SolarTerm::from_index(y + 1, 0).get_solar_day();
        // 距冬至最近的甲子日
        const SolarDay w = winter_solstice.next(winter_solstice.get_lunar_day().get_sixty_cycle().steps_close_to(0));
        // 距夏至最近的甲子日
        const SolarDay s = summer_solstice.next(summer_solstice.get_lunar_day().get_sixty_cycle().steps_close_to(0));
        // 距下个冬至最近的甲子日
        const SolarDay n = next_winter_solstice.next(next_winter_solstice.get_lunar_day().get_sixty_cycle().steps_close_to(0));
        // 43210012345678876543210012345
        //      w        s        n
        //     冬至     夏至      冬至
        if (is_before(w)) {
            return NineStar::from_index(w.subtract(*this) - 1);
        }
        if (is_before(s)) {
            return NineStar::from_index(subtract(w));
        }
        return NineStar::from_index(is_before(n) ? n.subtract(*this) - 1 : subtract(n));
    }

    SolarTime &SolarTime::operator=(const SolarTime &other) {
        year = other.year;
        month = other.month;
        day = other.day;
        hour = other.hour;
        minute = other.minute;
        second = other.second;
        return *this;
    }

    void SolarTime::validate(int year, int month, int day, int hour, int minute, int second) {
        SecondUnit::validate(hour, minute, second);
        SolarDay::validate(year, month, day);
    }

    SolarTime SolarTime::from_ymd_hms(const int year, const int month, const int day, const int hour, const int minute, const int second) {
        return SolarTime(year, month, day, hour, minute, second);
    }

    SolarDay SolarTime::get_solar_day() const {
        return SolarDay::from_ymd(year, month, day);
    }

    string SolarTime::get_name() const {
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hour, minute, second);
        return {buffer};
    }

    string SolarTime::to_string() const {
        return get_solar_day().to_string() + " " + get_name();
    }

    SolarTime SolarTime::next(const int n) const {
        if (n == 0) {
            return from_ymd_hms(year, month, day, hour, minute, second);
        }
        int ts = second + n;
        int tm = minute + ts / 60;
        ts %= 60;
        if (ts < 0) {
            ts += 60;
            tm -= 1;
        }
        int th = hour + tm / 60;
        tm %= 60;
        if (tm < 0) {
            tm += 60;
            th -= 1;
        }
        int td = th / 24;
        th %= 24;
        if (th < 0) {
            th += 24;
            td -= 1;
        }

        const SolarDay d = get_solar_day().next(td);
        return from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), th, tm, ts);
    }

    bool SolarTime::is_before(const SolarTime &other) const {
        const SolarDay a_day = get_solar_day();
        if (const SolarDay bDay = other.get_solar_day(); !a_day.equals(bDay)) {
            return a_day.is_before(bDay);
        }
        if (hour != other.hour) {
            return hour < other.hour;
        }
        if (minute != other.minute) {
            return minute < other.minute;
        }
        return second < other.second;
    }

    bool SolarTime::is_after(const SolarTime &other) const {
        const SolarDay a_day = get_solar_day();
        if (const SolarDay bDay = other.get_solar_day(); !a_day.equals(bDay)) {
            return a_day.is_after(bDay);
        }
        if (hour != other.hour) {
            return hour > other.hour;
        }
        if (minute != other.minute) {
            return minute > other.minute;
        }
        return second > other.second;
    }

    SolarTerm SolarTime::get_term() const {
        SolarTerm term = get_solar_day().get_term();
        if (is_before(term.get_julian_day().get_solar_time())) {
            term = term.next(-1);
        }
        return term;
    }

    Phenology SolarTime::get_phenology() const {
        Phenology p = get_solar_day().get_phenology();
        if (is_before(p.get_julian_day().get_solar_time())) {
            p = p.next(-1);
        }
        return p;
    }

    JulianDay SolarTime::get_julian_day() const {
        return JulianDay::from_ymd_hms(year, month, day, hour, minute, second);
    }

    int SolarTime::subtract(const SolarTime &other) const {
        int days = get_solar_day().subtract(other.get_solar_day());
        const int cs = hour * 3600 + minute * 60 + second;
        const int ts = other.get_hour() * 3600 + other.get_minute() * 60 + other.get_second();
        int seconds = cs - ts;
        if (seconds < 0) {
            seconds += 86400;
            days--;
        }
        seconds += days * 86400;
        return seconds;
    }

    bool SolarTime::equals(const SolarTime &other) const {
        return to_string() == other.to_string();
    }

    SixtyCycleHour SolarTime::get_sixty_cycle_hour() const {
        return SixtyCycleHour::from_solar_time(*this);
    }

    LunarHour SolarTime::get_lunar_hour() const {
        const LunarDay d = get_solar_day().get_lunar_day();
        return LunarHour::from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), hour, minute, second);
    }

    Phase SolarTime::get_phase() const {
        const LunarMonth month = get_lunar_hour().get_lunar_day().get_lunar_month().next(1);
        Phase p = Phase::from_index(month.get_year(), month.get_month_with_leap(), 0);
        while (p.get_solar_time().is_after(*this)) {
            p = p.next(-1);
        }
        return p;
    }
}
