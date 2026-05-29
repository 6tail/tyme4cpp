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
    const vector<string> RabByungElement::NAMES = {
        "木", "火", "土", "铁", "水"
    };

    RabByungElement RabByungElement::from_index(const int index) {
        return RabByungElement(index);
    }

    RabByungElement RabByungElement::from_name(const string &name) {
        return RabByungElement(name);
    }

    RabByungElement RabByungElement::next(const int n) const {
        return from_index(next_index(n));
    }

    bool RabByungElement::equals(const RabByungElement &other) const {
        return to_string() == other.to_string();
    }

    RabByungElement RabByungElement::get_reinforce() const {
        return next(1);
    }

    RabByungElement RabByungElement::get_restrain() const {
        return next(2);
    }

    RabByungElement RabByungElement::get_reinforced() const {
        return next(-1);
    }

    RabByungElement RabByungElement::get_restrained() const {
        return next(-2);
    }

    void RabByungYear::validate(const int year) {
        if (year < 1027 || year > 9999) {
            throw invalid_argument("rab-byung year: " + std::to_string(year));
        }
    }

    RabByungYear RabByungYear::from_sixty_cycle(const int rab_byung_index, const SixtyCycle& sixty_cycle) {
        return RabByungYear(rab_byung_index, sixty_cycle.get_heaven_stem().get_element().get_index(), sixty_cycle.get_earth_branch().get_zodiac().get_index());
    }

    RabByungYear RabByungYear::from_element_zodiac(const int rab_byung_index, const RabByungElement& element, const Zodiac& zodiac) {
        return RabByungYear(rab_byung_index, element.get_index(), zodiac.get_index());
    }

    RabByungYear RabByungYear::from_year(const int year) {
        validate(year);
        return from_sixty_cycle((year - 1024) / 60, SixtyCycle::from_index(year - 4));
    }

    int RabByungYear::get_rab_byung_index() const {
        return rab_byung_index;
    }

    SixtyCycle RabByungYear::get_sixty_cycle() const {
        return SixtyCycle::from_index(6 * (element_index * 2 + zodiac_index % 2) - 5 * zodiac_index);
    }

    Zodiac RabByungYear::get_zodiac() const {
        return Zodiac::from_index(zodiac_index);
    }

    RabByungElement RabByungYear::get_element() const {
        return RabByungElement::from_index(element_index);
    }

    string RabByungYear::get_name() const {
        int n = rab_byung_index + 1;
        string s;
        int pos = 0;
        while (n > 0) {
            const string digits[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
            if (const int digit = n % 10; digit > 0) {
                const string units[] = {"", "十", "百"};
                s.insert(0, digits[digit] + units[pos]);
            } else if (!s.empty()) {
                s.insert(0, digits[digit]);
            }
            n /= 10;
            pos++;
        }
        if (s.rfind("一十", 0) == 0) {
            const string target = "一";
            s.erase(0, target.length());
        }
        return "第" + s + "饶迥" + get_element().to_string() + get_zodiac().to_string() + "年";
    }

    RabByungYear RabByungYear::next(const int n) const {
        return from_year(get_year() + n);
    }

    int RabByungYear::get_year() const {
        return 1024 + rab_byung_index * 60 + get_sixty_cycle().get_index();
    }

    int RabByungYear::get_leap_month() const {
        int y = 1;
        int m = 4;
        int t = 1;
        const int current_year = get_year();
        while (y < current_year) {
            const int i = m + 31 + t;
            y += 2;
            m = i - 23;
            if (i > 35) {
                y += 1;
                m -= 12;
            }
            t = 1 - t;
        }
        return y == current_year ? m : 0;
    }

    SolarYear RabByungYear::get_solar_year() const {
        return SolarYear::from_year(get_year());
    }

    int RabByungYear::get_month_count() const {
        return get_leap_month() < 1 ? 12 : 13;
    }

    RabByungMonth RabByungYear::get_first_month() const {
        return RabByungMonth(get_year(), 1);
    }

    vector<RabByungMonth> RabByungYear::get_months() const {
        auto l = vector<RabByungMonth>();
        const int leap_month = get_leap_month();
        const int y = get_year();
        for (int i = 1; i < 13; i++) {
            l.emplace_back(y, i);
            if (i == leap_month) {
                l.emplace_back(y, -i);
            }
        }
        return l;
    }

    std::map<int, vector<int>> RabByungMonth::DAYS = std::map<int, vector<int>>();

    const vector<string> RabByungMonth::ALIAS = {
        "神变月", "苦行月", "具香月", "萨嘎月", "作净月", "明净月", "具醉月", "具贤月", "天降月", "持众月", "庄严月", "满意月"
    };

    void RabByungMonth::validate(const int year, const int month) {
        if (month == 0 || month > 12 || month < -12) {
            throw invalid_argument("illegal rab-byung month: " + std::to_string(month));
        }
        if (year < 1950 || year > 2050) {
            throw invalid_argument("rab-byung year " + std::to_string(year) + " must between 1950 and 2050");
        }
        const bool leap = month < 0;
        const int m = abs(month);
        if (year == 1950 && m < 12) {
            throw invalid_argument("month " + std::to_string(month) + " must be 12 in rab-byung year " + std::to_string(year));
        }
        if (leap && m != RabByungYear::from_year(year).get_leap_month()) {
            throw invalid_argument("illegal leap month " + std::to_string(m) + " in rab-byung year " + std::to_string(year));
        }
    }

    RabByungMonth RabByungMonth::from_ym(const int year, const int month) {
        return RabByungMonth(year, month);
    }

    RabByungYear RabByungMonth::get_rab_byung_year() const {
        return RabByungYear::from_year(year);
    }

    int RabByungMonth::get_month_with_leap() const {
        return leap ? -month : month;
    }

    int RabByungMonth::get_index_in_year() const {
        int index = month - 1;
        if (leap) {
            index += 1;
        } else {
            if (const int leap_month = get_rab_byung_year().get_leap_month(); leap_month > 0 && month > leap_month) {
                index += 1;
            }
        }
        return index;
    }

    bool RabByungMonth::is_leap() const {
        return leap;
    }

    string RabByungMonth::get_name() const {
        return (leap ? "闰" : "") + LunarMonth::NAMES[month - 1];
    }

    string RabByungMonth::get_alias() const {
        return (leap ? "闰" : "") + ALIAS[month - 1];
    }

    string RabByungMonth::to_string() const {
        return get_rab_byung_year().to_string() + get_name();
    }

    RabByungMonth RabByungMonth::next(const int n) const {
        if (n == 0) {
            return from_ym(get_year(), get_month_with_leap());
        }
        int m = get_index_in_year() + 1 + n;
        RabByungYear y = get_rab_byung_year();
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
        return from_ym(y.get_year(), is_leap ? -m : m);
    }

    int RabByungMonth::get_day_count() const {
        return 30 + static_cast<int>(get_leap_days().size()) - static_cast<int>(get_miss_days().size());
    }

    vector<int> RabByungMonth::get_special_days() const {
        if (const auto it = DAYS.find(get_year() * 13 + get_index_in_year()); it != DAYS.end()) {
            return it->second;
        }
        return {};
    }

    vector<int> RabByungMonth::get_leap_days() const {
        auto l = vector<int>();
        const auto days = get_special_days();
        for (const int d : days) {
            if (d > 0) {
                l.push_back(d);
            }
        }
        return l;
    }

    vector<int> RabByungMonth::get_miss_days() const {
        auto l = vector<int>();
        const auto days = get_special_days();
        for (const int d : days) {
            if (d < 0) {
                l.push_back(-d);
            }
        }
        return l;
    }

    bool RabByungMonth::equals(const RabByungMonth &other) const {
        return to_string() == other.to_string();
    }

    RabByungDay RabByungMonth::get_first_day() const {
        return RabByungDay(get_year(), get_month_with_leap(), 1);
    }

    vector<RabByungDay> RabByungMonth::get_days() const {
        auto l = vector<RabByungDay>();
        auto miss_days = get_miss_days();
        auto leap_days = get_leap_days();
        const int y = get_year();
        const int m = get_month_with_leap();
        for (int i = 1; i < 31; i++) {
            if (find(miss_days.begin(), miss_days.end(), i) != miss_days.end()) {
                continue;
            }
            l.emplace_back(y, m, i);
            if (find(leap_days.begin(), leap_days.end(), i) != leap_days.end()) {
                l.emplace_back(y, m, -i);
            }
        }
        return l;
    }

    const vector<string> RabByungDay::NAMES = {
        "初一", "初二", "初三", "初四", "初五", "初六", "初七", "初八", "初九", "初十", "十一", "十二", "十三", "十四", "十五", "十六", "十七", "十八", "十九", "二十", "廿一", "廿二", "廿三", "廿四", "廿五", "廿六", "廿七", "廿八", "廿九", "三十"
    };

    void RabByungDay::validate(const int year, const int month, const int day) {
        if (day == 0 || day < -30 || day > 30) {
            throw invalid_argument("illegal day " + std::to_string(day) + " in " + std::to_string(month));
        }
        const RabByungMonth m = RabByungMonth::from_ym(year, month);
        const bool leap = day < 0;
        const int d = abs(day);
        if (leap) {
            if (vector<int> l = m.get_leap_days(); find(l.begin(), l.end(), d) == l.end()) {
                throw invalid_argument("illegal leap day " + std::to_string(d) + " in " + m.to_string());
            }
        }
        if (!leap) {
            if (vector<int> l = m.get_miss_days(); find(l.begin(), l.end(), d) != l.end()) {
                throw invalid_argument("illegal day " + std::to_string(d) + " in " + m.to_string());
            }
        }
    }

    RabByungDay RabByungDay::from_ymd(const int year, const int month, const int day) {
        return RabByungDay(year, month, day);
    }

    RabByungDay RabByungDay::from_solar_day(const SolarDay& solar_day) {
        int days = solar_day.subtract(SolarDay::from_ymd(1951, 1, 8));
        RabByungMonth m = RabByungMonth::from_ym(1950, 12);
        int count = m.get_day_count();
        while (days >= count) {
            days -= count;
            m = m.next(1);
            count = m.get_day_count();
        }
        int day = days + 1;
        for (const int d : m.get_special_days()) {
            if (d < 0) {
                if (day >= -d) {
                    day++;
                }
            } else if (d > 0) {
                if (day == d + 1) {
                    day = -d;
                    break;
                }
                if (day > d + 1) {
                    day--;
                }
            }
        }
        return RabByungDay(m.get_year(), m.get_month_with_leap(), day);
    }

    RabByungMonth RabByungDay::get_rab_byung_month() const {
        return RabByungMonth::from_ym(year, month);
    }

    bool RabByungDay::is_leap() const {
        return leap;
    }

    int RabByungDay::get_day_with_leap() const {
        return leap ? -day : day;
    }

    string RabByungDay::get_name() const {
        return (leap ? "闰" : "") + NAMES[day - 1];
    }

    string RabByungDay::to_string() const {
        return get_rab_byung_month().to_string() + get_name();
    }

    int RabByungDay::subtract(const RabByungDay& target) const {
        return get_solar_day().subtract(target.get_solar_day());
    }

    SolarDay RabByungDay::get_solar_day() const {
        RabByungMonth m = RabByungMonth::from_ym(1950, 12);
        const RabByungMonth cm = get_rab_byung_month();
        int n = 0;
        while (!m.equals(cm)) {
            n += m.get_day_count();
            m = m.next(1);
        }
        int t = day;
        for (const int d : m.get_special_days()) {
            if (d < 0) {
                if (t > -d) {
                    t--;
                }
            } else if (d > 0) {
                if (t > d) {
                    t++;
                }
            }
        }
        if (leap) {
            t++;
        }
        return SolarDay::from_ymd(1951, 1, 7).next(n + t);
    }

    RabByungDay RabByungDay::next(const int n) const {
        return get_solar_day().next(n).get_rab_byung_day();
    }
}
