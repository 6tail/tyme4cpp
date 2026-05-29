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
    LunarHour LunarHour::from_ymd_hms(const int year, const int month, const int day, const int hour, const int minute, const int second) {
        return LunarHour(year, month, day, hour, minute, second);
    }

    void LunarHour::validate(int year, int month, int day, int hour, int minute, int second) {
        SecondUnit::validate(hour, minute, second);
        LunarDay::validate(year, month, day);
    }

    LunarDay LunarHour::get_lunar_day() const {
        return LunarDay::from_ymd(year, month, day);
    }

    string LunarHour::get_name() const {
        return EarthBranch::from_index(get_index_in_day()).get_name() + "时";
    }

    string LunarHour::to_string() const {
        return get_lunar_day().to_string() + get_sixty_cycle().get_name() + "时";
    }

    int LunarHour::get_index_in_day() const {
        return (hour + 1) / 2;
    }

    LunarHour LunarHour::next(const int n) const {
        if (n == 0) {
            return from_ymd_hms(year, month, day, hour, minute, second);
        }
        const int hours = hour + n * 2;
        int diff = 1;
        if (hours < 0) {
            diff = -1;
        }
        int h = abs(hours);
        int days = h / 24 * diff;
        h = h % 24 * diff;
        if (h < 0) {
            h += 24;
            days--;
        }
        const LunarDay d = get_lunar_day().next(days);
        return from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), h, minute, second);
    }

    bool LunarHour::is_before(const LunarHour &other) const {
        const LunarDay a_day = get_lunar_day();
        if (const LunarDay b_day = other.get_lunar_day(); !a_day.equals(b_day)) {
            return a_day.is_before(b_day);
        }
        if (hour != other.hour) {
            return hour < other.hour;
        }
        if (minute != other.minute) {
            return minute < other.minute;
        }
        return second < other.second;
    }

    bool LunarHour::is_after(const LunarHour &other) const {
        const LunarDay a_day = get_lunar_day();
        if (const LunarDay b_day = other.get_lunar_day(); !a_day.equals(b_day)) {
            return a_day.is_after(b_day);
        }
        if (hour != other.hour) {
            return hour > other.hour;
        }
        if (minute != other.minute) {
            return minute > other.minute;
        }
        return second > other.second;
    }

    SixtyCycle LunarHour::get_sixty_cycle() const {
        int e = get_index_in_day();
        HeavenStem h = get_lunar_day().get_sixty_cycle().get_heaven_stem();
        if (hour >= 23) {
            h = h.next(1);
            e = 0;
        }
        return SixtyCycle::from_index(h.get_index() * 12 + e);
    }

    TwelveStar LunarHour::get_twelve_star() const {
        return TwelveStar::from_index(get_sixty_cycle().get_earth_branch().get_index() + (8 - get_sixty_cycle_hour().get_day().get_earth_branch().get_index() % 6) * 2);
    }

    NineStar LunarHour::get_nine_star() const {
        const LunarDay d = get_lunar_day();
        const SolarDay solar = d.get_solar_day();
        const SolarTerm dong_zhi = SolarTerm::from_index(solar.get_year(), 0);
        const int earth_branch_index = get_index_in_day() % 12;
        constexpr int indices[] = {8, 5, 2};
        int index = indices[d.get_sixty_cycle().get_earth_branch().get_index() % 3];
        if (!solar.is_before(dong_zhi.get_julian_day().get_solar_day()) && solar.is_before(dong_zhi.next(12).get_julian_day().get_solar_day())) {
            index = 8 + earth_branch_index - index;
        } else {
            index -= earth_branch_index;
        }
        return NineStar::from_index(index);
    }

    SolarTime LunarHour::get_solar_time() const {
        const SolarDay d = get_lunar_day().get_solar_day();
        return SolarTime::from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), hour, minute, second);
    }

    SixtyCycleHour LunarHour::get_sixty_cycle_hour() const {
        return get_solar_time().get_sixty_cycle_hour();
    }

    vector<Taboo> LunarHour::get_recommends() const {
        return Taboo::get_hour_recommends(get_sixty_cycle_hour().get_day(), get_sixty_cycle());
    }

    vector<Taboo> LunarHour::get_avoids() const {
        return Taboo::get_hour_avoids(get_sixty_cycle_hour().get_day(), get_sixty_cycle());
    }

    MinorRen LunarHour::get_minor_ren() const {
        return get_lunar_day().get_minor_ren().next(get_index_in_day());
    }

    EightChar LunarHour::get_eight_char() const {
        return provider->get_eight_char(*this);
    }

    EightCharProvider* LunarHour::provider = new DefaultEightCharProvider();
    SixtyCycle ThreePillars::get_year() const {
        return year;
    }

    SixtyCycle ThreePillars::get_month() const {
        return month;
    }

    SixtyCycle ThreePillars::get_day() const {
        return day;
    }

    vector<SolarDay> ThreePillars::get_solar_days(const int start_year, const int end_year) const {
        auto l = vector<SolarDay>();
        // 月地支距寅月的偏移值
        int m = month.get_earth_branch().next(-2).get_index();
        // 月天干要一致
        if (!HeavenStem::from_index((year.get_heaven_stem().get_index() + 1) * 2 + m).equals(month.get_heaven_stem())) {
            return l;
        }
        // 1年的立春是辛酉，序号57
        int y = year.next(-57).get_index() + 1;
        // 节令偏移值
        m *= 2;
        if (const int base_year = start_year - 1; base_year > y) {
            y += 60 * static_cast<int>(ceil((base_year - y) / 60.0));
        }
        while (y <= end_year) {
            // 立春为寅月的开始
            SolarTerm term = SolarTerm::from_index(y, 3);
            // 节令推移，年干支和月干支就都匹配上了
            if (m > 0) {
                term = term.next(m);
            }
            if (SolarDay solar_day = term.get_solar_day(); solar_day.get_year() >= start_year) {
                // 日干支和节令干支的偏移值
                int d = day.next(-solar_day.get_lunar_day().get_sixty_cycle().get_index()).get_index();
                if (d > 0) {
                    // 从节令推移天数
                    solar_day = solar_day.next(d);
                }
                // 验证一下
                if (solar_day.get_sixty_cycle_day().get_three_pillars().equals(this)) {
                    l.push_back(solar_day);
                }
            }
            y += 60;
        }
        return l;
    }

    string ThreePillars::get_name() const {
        return year.to_string() + " " + month.to_string() + " " + day.to_string();
    }

    SixtyCycle EightChar::get_year() const {
        return three_pillars.get_year();
    }

    SixtyCycle EightChar::get_month() const {
        return three_pillars.get_month();
    }

    SixtyCycle EightChar::get_day() const {
        return three_pillars.get_day();
    }

    SixtyCycle EightChar::get_hour() const {
        return hour;
    }

    SixtyCycle EightChar::get_fetal_origin() const {
        const SixtyCycle m = get_month();
        return SixtyCycle::from_index(m.get_heaven_stem().next(1).get_index() * 6 - m.get_earth_branch().next(3).get_index() * 5);
    }

    SixtyCycle EightChar::get_fetal_breath() const {
        const SixtyCycle d = get_day();
        return SixtyCycle::from_index(d.get_heaven_stem().next(5).get_index() * 6 + d.get_earth_branch().get_index() * 5 - 65);
    }

    SixtyCycle EightChar::get_own_sign() const {
        return SixtyCycle::from_index(get_year().get_heaven_stem().get_index() * 12 + (27 - get_month().get_earth_branch().get_index() - hour.get_earth_branch().get_index()) % 12 + 2);
    }

    SixtyCycle EightChar::get_body_sign() const {
        return SixtyCycle::from_index(get_year().get_heaven_stem().get_index() * 12 + (11 + get_month().get_earth_branch().get_index() + hour.get_earth_branch().get_index()) % 12 + 2);
    }

    vector<SolarTime> EightChar::get_solar_times(const int start_year, const int end_year) const {
        const SixtyCycle year = get_year();
        const SixtyCycle month = get_month();
        const SixtyCycle day = get_day();
        auto l = vector<SolarTime>();
        // 月地支距寅月的偏移值
        int m = month.get_earth_branch().next(-2).get_index();
        // 月天干要一致
        if (!HeavenStem::from_index((year.get_heaven_stem().get_index() + 1) * 2 + m).equals(month.get_heaven_stem())) {
            return l;
        }
        // 1年的立春是辛酉，序号57
        int y = year.next(-57).get_index() + 1;
        // 节令偏移值
        m *= 2;
        // 时辰地支转时刻
        const int h = hour.get_earth_branch().get_index() * 2;
        // 兼容子时多流派
        auto hours = vector<int>();
        hours.push_back(h);
        if (h == 0) {
            hours.push_back(23);
        }
        if (const int base_year = start_year - 1; base_year > y) {
            y += 60 * static_cast<int>(ceil((base_year - y) / 60.0));
        }
        while (y <= end_year) {
            // 立春为寅月的开始
            SolarTerm term = SolarTerm::from_index(y, 3);
            // 节令推移，年干支和月干支就都匹配上了
            if (m > 0) {
                term = term.next(m);
            }
            if (SolarTime solar_time = term.get_julian_day().get_solar_time(); solar_time.get_year() >= start_year) {
                // 日干支和节令干支的偏移值
                SolarDay solar_day = solar_time.get_solar_day();
                const int d = day.next(-solar_day.get_lunar_day().get_sixty_cycle().get_index()).get_index();
                if (d > 0) {
                    // 从节令推移天数
                    solar_day = solar_day.next(d);
                }
                for (const int hr: hours) {
                    int mi = 0;
                    int s = 0;
                    // 如果正好是节令当天，且小时和节令的小时数相等的极端情况，把分钟和秒钟带上
                    if (d == 0 && hr == solar_time.get_hour()) {
                        mi = solar_time.get_minute();
                        s = solar_time.get_second();
                    }
                    SolarTime time = SolarTime::from_ymd_hms(solar_day.get_year(), solar_day.get_month(), solar_day.get_day(), hr, mi, s);
                    if (d == 30) {
                        time = time.next(-3600);
                    }
                    // 验证一下
                    if (time.get_lunar_hour().get_eight_char().equals(this)) {
                        l.push_back(time);
                    }
                }
            }
            y += 60;
        }
        return l;
    }

    string EightChar::get_name() const {
        return three_pillars.to_string() + " " + hour.to_string();
    }

    EightChar DefaultEightCharProvider::get_eight_char(const LunarHour hour) const {
        return hour.get_sixty_cycle_hour().get_eight_char();
    }

    EightChar LunarSect2EightCharProvider::get_eight_char(const LunarHour hour) const {
        const SixtyCycleHour h = hour.get_sixty_cycle_hour();
        return EightChar(h.get_year(), h.get_month(), hour.get_lunar_day().get_sixty_cycle(), h.get_sixty_cycle());
    }
}
