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
    SolarTime ChildLimitInfo::get_start_time() const {
        return start_time;
    }

    SolarTime ChildLimitInfo::get_end_time() const {
        return end_time;
    }

    int ChildLimitInfo::get_year_count() const {
        return year_count;
    }

    int ChildLimitInfo::get_month_count() const {
        return month_count;
    }

    int ChildLimitInfo::get_day_count() const {
        return day_count;
    }

    int ChildLimitInfo::get_hour_count() const {
        return hour_count;
    }

    int ChildLimitInfo::get_minute_count() const {
        return minute_count;
    }

    bool ChildLimit::get_forward(const EightChar &ec, const Gender g) {
        // 阳男阴女顺推，阴男阳女逆推
        const bool yang = YinYang::YANG == ec.get_year().get_heaven_stem().get_yin_yang();
        const bool man = Gender::MAN == g;
        return (yang && man) || (!yang && !man);
    }

    ChildLimitProvider* ChildLimit::provider = new DefaultChildLimitProvider();

    ChildLimitInfo ChildLimit::get_info(const SolarTime &birth_time, const bool f) {
        SolarTerm term = birth_time.get_term();
        if (!term.is_jie()) {
            term = term.next(-1);
        }
        if (f) {
            term = term.next(2);
        }
        return provider->get_info(birth_time, term);
    }

    Fortune Fortune::from_child_limit(const ChildLimit& child_limit, const int index) {
        return Fortune(child_limit, index);
    }

    int Fortune::get_age() const {
        return child_limit.get_end_sixty_cycle_year().get_year() - child_limit.get_start_sixty_cycle_year().get_year() + 1 + index;
    }

    SixtyCycleYear Fortune::get_sixty_cycle_year() const {
        return child_limit.get_end_sixty_cycle_year().next(index);
    }

    SixtyCycle Fortune::get_sixty_cycle() const {
        const int n = get_age();
        return child_limit.get_eight_char().get_hour().next(child_limit.is_forward() ? n: -n);
    }

    string Fortune::get_name() const {
        return get_sixty_cycle().get_name();
    }

    Fortune Fortune::next(const int n) const {
        return from_child_limit(child_limit, index + n);
    }

    DecadeFortune DecadeFortune::from_child_limit(const ChildLimit& child_limit, const int index) {
        return DecadeFortune(child_limit, index);
    }

    int DecadeFortune::get_start_age() const {
        return child_limit.get_end_sixty_cycle_year().get_year() - child_limit.get_start_sixty_cycle_year().get_year() + 1 + index * 10;
    }

    int DecadeFortune::get_end_age() const {
        return get_start_age() + 9;
    }

    SixtyCycle DecadeFortune::get_sixty_cycle() const {
        return child_limit.get_eight_char().get_month().next(child_limit.is_forward() ? index + 1 : -index - 1);
    }

    SixtyCycleYear DecadeFortune::get_start_sixty_cycle_year() const {
        return child_limit.get_end_sixty_cycle_year().next(index * 10);
    }

    SixtyCycleYear DecadeFortune::get_end_sixty_cycle_year() const {
        return get_start_sixty_cycle_year().next(9);
    }

    string DecadeFortune::get_name() const {
        return get_sixty_cycle().get_name();
    }

    DecadeFortune DecadeFortune::next(const int n) const {
        return from_child_limit(child_limit, index + n);
    }

    Fortune DecadeFortune::get_start_fortune() const {
        return Fortune::from_child_limit(child_limit, index * 10);
    }

    ChildLimit ChildLimit::from_solar_time(const SolarTime& birth_time, const Gender gender) {
        return ChildLimit(birth_time, gender);
    }

    EightChar ChildLimit::get_eight_char() const {
        return eight_char;
    }

    Gender ChildLimit::get_gender() const {
        return gender;
    }

    bool ChildLimit::is_forward() const {
        return forward;
    }

    int ChildLimit::get_year_count() const {
        return info.get_year_count();
    }

    int ChildLimit::get_month_count() const {
        return info.get_month_count();
    }

    int ChildLimit::get_day_count() const {
        return info.get_day_count();
    }

    int ChildLimit::get_hour_count() const {
        return info.get_hour_count();
    }

    int ChildLimit::get_minute_count() const {
        return info.get_minute_count();
    }

    SolarTime ChildLimit::get_start_time() const {
        return info.get_start_time();
    }

    SolarTime ChildLimit::get_end_time() const {
        return info.get_end_time();
    }

    DecadeFortune ChildLimit::get_start_decade_fortune() const {
        return DecadeFortune::from_child_limit(*this, 0);
    }

    DecadeFortune ChildLimit::get_decade_fortune() const {
        return DecadeFortune::from_child_limit(*this, -1);
    }

    Fortune ChildLimit::get_start_fortune() const {
        return Fortune::from_child_limit(*this, 0);
    }

    SixtyCycleYear ChildLimit::get_start_sixty_cycle_year() const {
        return SixtyCycleYear::from_year(get_start_time().get_year());
    }

    SixtyCycleYear ChildLimit::get_end_sixty_cycle_year() const {
        return SixtyCycleYear::from_year(get_end_time().get_year());
    }

    int ChildLimit::get_start_age() const {
        return 1;
    }

    int ChildLimit::get_end_age() const {
        if (const int n = get_end_sixty_cycle_year().get_year() - get_start_sixty_cycle_year().get_year(); n > 1) {
            return n;
        }
        return 1;
    }

    ChildLimitInfo AbstractChildLimitProvider::next(const SolarTime& birth_time, const int add_year, const int add_month, const int add_day, const int add_hour, const int add_minute, const int add_second) const {
        int d = birth_time.get_day() + add_day;
        int h = birth_time.get_hour() + add_hour;
        int mi = birth_time.get_minute() + add_minute;
        int s = birth_time.get_second() + add_second;
        mi += s / 60;
        s %= 60;
        h += mi / 60;
        mi %= 60;
        d += h / 24;
        h %= 24;

        SolarMonth sm = SolarMonth::from_ym(birth_time.get_year() + add_year, birth_time.get_month()).next(add_month);

        int dc = sm.get_day_count();
        while (d > dc) {
            d -= dc;
            sm = sm.next(1);
            dc = sm.get_day_count();
        }

        return ChildLimitInfo(birth_time, SolarTime::from_ymd_hms(sm.get_year(), sm.get_month(), d, h, mi, s), add_year, add_month, add_day, add_hour, add_minute);
    }

    ChildLimitInfo DefaultChildLimitProvider::get_info(const SolarTime birth_time, const SolarTerm term) const {
        // 出生时刻和节令时刻相差的秒数
        int seconds = abs(term.get_julian_day().get_solar_time().subtract(birth_time));
        // 3天 = 1年，3天=60*60*24*3秒=259200秒 = 1年
        const int year = seconds / 259200;
        seconds %= 259200;
        // 1天 = 4月，1天=60*60*24秒=86400秒 = 4月，85400秒/4=21600秒 = 1月
        const int month = seconds / 21600;
        seconds %= 21600;
        // 1时 = 5天，1时=60*60秒=3600秒 = 5天，3600秒/5=720秒 = 1天
        const int day = seconds / 720;
        seconds %= 720;
        // 1分 = 2时，60秒 = 2时，60秒/2=30秒 = 1时
        const int hour = seconds / 30;
        seconds %= 30;
        // 1秒 = 2分，1秒/2=0.5秒 = 1分
        const int minute = seconds * 2;

        return next(birth_time, year, month, day, hour, minute, 0);
    }

    ChildLimitInfo China95ChildLimitProvider::get_info(const SolarTime birth_time, const SolarTerm term) const {
        // 出生时刻和节令时刻相差的分钟数
        int minutes = abs(term.get_julian_day().get_solar_time().subtract(birth_time)) / 60;
        const int year = minutes / 4320;
        minutes %= 4320;
        const int month = minutes / 360;
        minutes %= 360;
        const int day = minutes / 12;

        return next(birth_time, year, month, day, 0, 0, 0);
    }

    ChildLimitInfo LunarSect1ChildLimitProvider::get_info(const SolarTime birth_time, const SolarTerm term) const {
        const SolarTime term_time = term.get_julian_day().get_solar_time();
        SolarTime end = term_time;
        SolarTime start = birth_time;
        if (birth_time.is_after(term_time)) {
            end = birth_time;
            start = term_time;
        }
        const int end_time_zhi_index = end.get_hour() == 23 ? 11 : end.get_lunar_hour().get_index_in_day();
        const int start_time_zhi_index = start.get_hour() == 23 ? 11 : start.get_lunar_hour().get_index_in_day();
        // 时辰差
        int hour_diff = end_time_zhi_index - start_time_zhi_index;
        // 天数差
        int day_diff = end.get_solar_day().subtract(start.get_solar_day());
        if (hour_diff < 0) {
            hour_diff += 12;
            day_diff--;
        }
        const int month_diff = hour_diff * 10 / 30;
        int month = day_diff * 4 + month_diff;
        const int day = hour_diff * 10 - month_diff * 30;
        const int year = month / 12;
        month = month - year * 12;

        return next(birth_time, year, month, day, 0, 0, 0);
    }

    ChildLimitInfo LunarSect2ChildLimitProvider::get_info(const SolarTime birth_time, const SolarTerm term) const {
        // 出生时刻和节令时刻相差的分钟数
        int minutes = abs(term.get_julian_day().get_solar_time().subtract(birth_time)) / 60;
        const int year = minutes / 4320;
        minutes %= 4320;
        const int month = minutes / 360;
        minutes %= 360;
        const int day = minutes / 12;
        minutes %= 12;
        const int hour = minutes * 2;

        return next(birth_time, year, month, day, hour, 0, 0);
    }
}
