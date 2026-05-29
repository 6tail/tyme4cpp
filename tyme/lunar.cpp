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
    vector<vector<int>> LunarYear::LEAP = vector<vector<int>>();

    void LunarYear::validate(const int year) {
        if (year < -1 || year > 9999) {
            throw invalid_argument("illegal lunar year: " + std::to_string(year));
        }
    }

    LunarYear LunarYear::from_year(const int year) {
        return LunarYear(year);
    }

    LunarYear& LunarYear::operator=(const LunarYear &other) {
        year = other.year;
        return *this;
    }

    SixtyCycle LunarYear::get_sixty_cycle() const {
        return SixtyCycle::from_index(year - 4);
    }

    int LunarYear::get_day_count() const {
        int n = 0;
        for (const LunarMonth& m: get_months()) {
            n += m.get_day_count();
        }
        return n;
    }

    int LunarYear::get_month_count() const {
        if (get_leap_month() < 1) {
            return 12;
        }
        return 13;
    }

    string LunarYear::get_name() const {
        return "农历" + get_sixty_cycle().to_string() + "年";
    }

    Twenty LunarYear::get_twenty() const {
        return Twenty::from_index(static_cast<int>(floor((year - 1864) / 20.0)));
    }

    NineStar LunarYear::get_nine_star() const {
        return NineStar::from_index(63 + get_twenty().get_sixty().get_index() * 3 - get_sixty_cycle().get_index());
    }

    Direction LunarYear::get_jupiter_direction() const {
        const int indices[] = {0, 7, 7, 2, 3, 3, 8, 1, 1, 6, 0, 0};
        return Direction::from_index(indices[get_sixty_cycle().get_earth_branch().get_index()]);
    }

    LunarYear LunarYear::next(const int n) const {
        return from_year(year + n);
    }

    int LunarYear::get_leap_month() const {
        if (year == -1) {
            return 11;
        }
        for (int i = 0; i < 12; i++) {
            if (vector<int> l = LEAP[i]; find(l.begin(), l.end(), year) != l.end()) {
                return i + 1;
            }
        }
        return 0;
    }

    KitchenGodSteed LunarYear::get_kitchen_god_steed() const {
        return KitchenGodSteed::from_lunar_year(year);
    }

    LunarMonth LunarYear::get_first_month() const {
        return LunarMonth::from_ym(year, 1);
    }

    vector<LunarMonth> LunarYear::get_months() const {
        auto l = vector<LunarMonth>();
        const int leap_month = get_leap_month();
        LunarMonth m = get_first_month();
        for (int i = 0; i < 13; i++) {
            l.push_back(LunarMonth::from_ym(year, i));
            if (i == leap_month) {
                l.push_back(LunarMonth::from_ym(year, -i));
            }
        }
        return l;
    }

    const vector<string> LunarSeason::NAMES = {"孟春", "仲春", "季春", "孟夏", "仲夏", "季夏", "孟秋", "仲秋", "季秋", "孟冬", "仲冬", "季冬"};

    LunarSeason LunarSeason::from_index(const int index) {
        return LunarSeason(index);
    }

    LunarSeason LunarSeason::from_name(const string &name) {
        return LunarSeason(name);
    }

    LunarSeason LunarSeason::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> LunarMonth::NAMES = {"正月", "二月", "三月", "四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月"};

    void LunarMonth::validate(const int year, const int month) {
        if (month == 0 || month > 12 || month < -12) {
            throw invalid_argument(&"illegal lunar month: "[month]);
        }
        if (month < 0 && -month != LunarYear::from_year(year).get_leap_month()) {
            throw invalid_argument("illegal leap month " + std::to_string(-month) + " in lunar year" + std::to_string(year));
        }
    }


    LunarMonth LunarMonth::from_ym(const int year, const int month) {
        return LunarMonth(year, month);
    }

    LunarMonth &LunarMonth::operator=(const LunarMonth &other) {
        year = other.year;
        month = other.month;
        leap = other.leap;
        return *this;
    }

    double LunarMonth::get_new_moon() const {
        // 冬至
        const double dong_zhi_jd = SolarTerm::from_index(year, 0).get_cursory_julian_day();

        // 冬至前的初一，今年首朔的日月黄经差
        double w = ShouXingUtil::calc_shuo(dong_zhi_jd);
        if (w > dong_zhi_jd) {
            w -= 29.53;
        }

        // 正常情况正月初一为第3个朔日，但有些特殊的
        int offset = 2;
        if (year > 8 && year < 24) {
            offset = 1;
        } else if (LunarYear::from_year(year - 1).get_leap_month() > 10 && year != 239 && year != 240) {
            offset = 3;
        }

        // 本月初一
        return w + 29.5306 * (offset + get_index_in_year());
    }


    LunarYear LunarMonth::get_lunar_year() const {
        return LunarYear::from_year(year);
    }

    int LunarMonth::get_month_with_leap() const {
        if (leap) {
            return -month;
        }
        return month;
    }

    int LunarMonth::get_day_count() const {
        const double w = get_new_moon();
        // 本月天数 = 下月初一 - 本月初一
        return static_cast<int>(ShouXingUtil::calc_shuo(w + 29.5306) - ShouXingUtil::calc_shuo(w));
    }

    int LunarMonth::get_index_in_year() const {
        int index = month - 1;
        if (leap) {
            index += 1;
        } else {
            if (const int leap_month = get_lunar_year().get_leap_month(); leap_month > 0 && month > leap_month) {
                index += 1;
            }
        }
        return index;
    }

    LunarSeason LunarMonth::get_season() const {
        return LunarSeason::from_index(month - 1);
    }

    JulianDay LunarMonth::get_first_julian_day() const {
        return JulianDay::from_julian_day(JulianDay::J2000 + ShouXingUtil::calc_shuo(get_new_moon()));
    }

    bool LunarMonth::is_leap() const {
        return leap;
    }

    int LunarMonth::get_week_count(const int start) const {
        return static_cast<int>(ceil((index_of(get_first_julian_day().get_week().get_index() - start, 7) + get_day_count()) / 7.0));
    }

    string LunarMonth::get_name() const {
        string s = NAMES[month - 1];
        if (leap) {
            return "闰" + s;
        }
        return s;
    }

    string LunarMonth::to_string() const {
        return get_lunar_year().to_string() + get_name();
    }

    LunarMonth LunarMonth::next(const int n) const {
        if (n == 0) {
            return from_ym(year, get_month_with_leap());
        }
        int m = get_index_in_year() + 1 + n;
        LunarYear y = get_lunar_year();
        if (n > 0) {
            int month_count = y.get_month_count();
            while (m > month_count) {
                m -= month_count;
                y = y.next(1);
                month_count = y.get_month_count();
            }
        } else {
            while (m <= 0) {
                y = y.next(-1);
                m += y.get_month_count();
            }
        }
        bool is_leap = false;
        if (const int leap_month = y.get_leap_month(); leap_month > 0) {
            if (m == leap_month + 1) {
                is_leap = true;
            }
            if (m > leap_month) {
                m--;
            }
        }
        if (is_leap) {
            m = -m;
        }
        return from_ym(y.get_year(), m);
    }

    SixtyCycle LunarMonth::get_sixty_cycle() const {
        return SixtyCycle::from_index(year * 12 + month - 47);
    }

    NineStar LunarMonth::get_nine_star() const {
        int index = get_sixty_cycle().get_earth_branch().get_index();
        if (index < 2) {
            index += 3;
        }
        return NineStar::from_index(27 - get_lunar_year().get_sixty_cycle().get_earth_branch().get_index() % 3 * 3 - index);
    }

    Direction LunarMonth::get_jupiter_direction() const {
        const SixtyCycle sixty_cycle = get_sixty_cycle();
        constexpr int indices[] = {7, -1, 1, 3};
        if (const int n = indices[sixty_cycle.get_earth_branch().next(-2).get_index() % 4]; n != -1) {
            return Direction::from_index(n);
        }
        return sixty_cycle.get_heaven_stem().get_direction();
    }

    optional<FetusMonth> LunarMonth::get_fetus() const {
        return FetusMonth::from_lunar_month(*this);
    }

    MinorRen LunarMonth::get_minor_ren() const {
        return MinorRen::from_index((month - 1) % 6);
    }

    vector<LunarWeek> LunarMonth::get_weeks(const int start) const {
        const int size = get_week_count(start);
        const int m = get_month_with_leap();
        auto l = vector<LunarWeek>();
        for (int i = 0; i < size; i++) {
            l.push_back(LunarWeek::from_ym(year, m, i, start));
        }
        return l;
    }

    vector<LunarDay> LunarMonth::get_days() const {
        const int size = get_day_count();
        const int m = get_month_with_leap();
        auto l = vector<LunarDay>();
        for (int i = 1; i <= size; i++) {
            l.push_back(LunarDay::from_ymd(year, m, i));
        }
        return l;
    }

    LunarDay LunarMonth::get_first_day() const {
        return LunarDay::from_ymd(year, get_month_with_leap(), 1);
    }

    void LunarWeek::validate(const int year, const int month, const int index, const int start) {
        WeekUnit::validate(index, start);
        if (const LunarMonth m = LunarMonth::from_ym(year, month); index >= m.get_week_count(start)) {
            throw invalid_argument("illegal lunar week index: " + std::to_string(index) + " in month: " + m.to_string());
        }
    }

    LunarWeek LunarWeek::from_ym(const int year, const int month, const int index, const int start) {
        return LunarWeek(year, month, index, start);
    }

    LunarMonth LunarWeek::get_lunar_month() const {
        return LunarMonth::from_ym(year, month);
    }

    string LunarWeek::get_name() const {
        return NAMES[index];
    }

    string LunarWeek::to_string() const {
        return get_lunar_month().to_string() + get_name();
    }

    LunarWeek LunarWeek::next(const int n) const {
        int d = index + n;
        LunarMonth m = get_lunar_month();
        if (n > 0) {
            int weekCount = m.get_week_count(start);
            while (d >= weekCount) {
                d -= weekCount;
                m = m.next(1);
                if (m.get_first_day().get_week().get_index() != start) {
                    d += 1;
                }
                weekCount = m.get_week_count(start);
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
        return from_ym(m.get_year(), m.get_month_with_leap(), d, start);
    }

    LunarDay LunarWeek::get_first_day() const {
        const LunarDay first_day = LunarDay::from_ymd(year, month, 1);
        return first_day.next(index * 7 - index_of(first_day.get_week().get_index() - start, 7));
    }

    vector<LunarDay> LunarWeek::get_days() const {
        auto l = vector<LunarDay>();
        const LunarDay d = get_first_day();
        l.push_back(d);
        for (int i = 1; i < 7; i++) {
            l.push_back(d.next(i));
        }
        return l;
    }

    bool LunarWeek::equals(const LunarWeek &other) const {
        return get_first_day().equals(other.get_first_day());
    }

    const vector<string> LunarDay::NAMES = {
        "初一", "初二", "初三", "初四", "初五", "初六", "初七", "初八", "初九", "初十", "十一", "十二", "十三", "十四", "十五", "十六", "十七", "十八", "十九", "二十", "廿一", "廿二", "廿三", "廿四", "廿五", "廿六", "廿七", "廿八", "廿九", "三十"
    };

    void LunarDay::validate(const int year, const int month, const int day) {
        if (day < 1) {
            throw invalid_argument("illegal lunar day: " + std::to_string(day));
        }
        if (const LunarMonth m = LunarMonth::from_ym(year, month); day > m.get_day_count()) {
            throw invalid_argument("illegal day " + std::to_string(day) + " in " + m.to_string());
        }
    }

    LunarDay LunarDay::from_ymd(const int year, const int month, const int day) {
        return LunarDay(year, month, day);
    }

    LunarMonth LunarDay::get_lunar_month() const {
        return LunarMonth::from_ym(year, month);
    }

    string LunarDay::get_name() const {
        return NAMES[day - 1];
    }

    string LunarDay::to_string() const {
        return get_lunar_month().to_string() + get_name();
    }

    LunarDay LunarDay::next(const int n) const {
        return get_solar_day().next(n).get_lunar_day();
    }

    bool LunarDay::equals(const LunarDay& other) const {
        return to_string() == other.to_string();
    }

    bool LunarDay::is_before(const LunarDay& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            const int t = abs(other.month);
            return month == t || abs(month) < t;
        }
        return day < other.day;
    }

    bool LunarDay::is_after(const LunarDay& other) const {
        if (year != other.year) {
            return year > other.year;
        }
        if (month != other.month) {
            const int t = abs(month);
            return t == other.month || t > abs(other.month);
        }
        return day > other.day;
    }

    Week LunarDay::get_week() const {
        return get_solar_day().get_week();
    }

    SixtyCycle LunarDay::get_sixty_cycle() const {
        return SixtyCycle::from_index(static_cast<int>(get_lunar_month().get_first_julian_day().next(day - 12).get_day()));
    }

    Duty LunarDay::get_duty() const {
        return get_sixty_cycle_day().get_duty();
    }

    TwelveStar LunarDay::get_twelve_star() const {
        return get_sixty_cycle_day().get_twelve_star();
    }

    NineStar LunarDay::get_nine_star() const {
        return get_solar_day().get_nine_star();
    }

    Direction LunarDay::get_jupiter_direction() const {
        if (const int index = get_sixty_cycle().get_index(); index % 12 < 6) {
            return Element::from_index(index / 12).get_direction();
        }
        return get_lunar_month().get_lunar_year().get_jupiter_direction();
    }

    FetusDay LunarDay::get_fetus_day() const {
        return FetusDay::from_lunar_day(*this);
    }

    PhaseDay LunarDay::get_phase_day() const {
        const SolarDay today = get_solar_day();
        const LunarMonth m = get_lunar_month().next(1);
        Phase p = Phase::from_index(m.get_year(), m.get_month_with_leap(), 0);
        SolarDay d = p.get_solar_day();
        while (d.is_after(today)) {
            p = p.next(-1);
            d = p.get_solar_day();
        }
        return PhaseDay(p, today.subtract(d));
    }

    Phase LunarDay::get_phase() const {
        return get_phase_day().get_phase();
    }

    SixStar LunarDay::get_six_star() const {
        return SixStar::from_index((abs(month) + day - 2) % 6);
    }

    SolarDay LunarDay::get_solar_day() const {
        return get_lunar_month().get_first_julian_day().next(day - 1).get_solar_day();
    }

    SixtyCycleDay LunarDay::get_sixty_cycle_day() const {
        return get_solar_day().get_sixty_cycle_day();
    }

    TwentyEightStar LunarDay::get_twenty_eight_star() const {
        const int indices[] = {10, 18, 26, 6, 14, 22, 2};
        return TwentyEightStar::from_index(indices[get_solar_day().get_week().get_index()]).next(-7 * get_sixty_cycle().get_earth_branch().get_index());
    }

    vector<God> LunarDay::get_gods() const {
        return get_sixty_cycle_day().get_gods();
    }

    vector<Taboo> LunarDay::get_recommends() const {
        return get_sixty_cycle_day().get_recommends();
    }

    vector<Taboo> LunarDay::get_avoids() const {
        return get_sixty_cycle_day().get_avoids();
    }

    MinorRen LunarDay::get_minor_ren() const {
        return get_lunar_month().get_minor_ren().next(day - 1);
    }

    optional<LunarFestival> LunarDay::get_festival() const {
        return LunarFestival::from_ymd(year, month, day);
    }

    ThreePillars LunarDay::get_three_pillars() const {
        return get_sixty_cycle_day().get_three_pillars();
    }
}
