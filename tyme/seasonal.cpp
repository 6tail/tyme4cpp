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
    const vector<string> Phase::NAMES = {
        "新月", "蛾眉月", "上弦月", "盈凸月", "满月", "亏凸月", "下弦月", "残月"
    };

    Phase Phase::from_index(const int lunar_year, const int lunar_month, const int index) {
        return Phase(lunar_year, lunar_month, index);
    }

    Phase Phase::from_name(const int lunar_year, const int lunar_month, const string &name) {
        return Phase(lunar_year, lunar_month, name);
    }

    Phase Phase::next(const int n) const {
        const int size = get_size();
        int i = index + n;
        if (i < 0) {
            i -= size;
        }
        i /= size;
        LunarMonth m = LunarMonth::from_ym(lunar_year, lunar_month);
        if (i != 0) {
            m = m.next(i);
        }
        return from_index(m.get_year(), m.get_month_with_leap(), next_index(n));
    }

    SolarTime Phase::get_start_solar_time() const {
        const int n = static_cast<int>(floor((lunar_year - 2000) * 365.2422 / 29.53058886));
        int i = 0;
        const SolarDay d = LunarDay::from_ymd(lunar_year, lunar_month, 1).get_solar_day();
        const double jd = JulianDay::J2000 + ShouXingUtil::ONE_THIRD;
        while (true) {
            if (const double t = ShouXingUtil::msa_lon_t((n + i) * ShouXingUtil::PI_2) * 36525; !JulianDay::from_julian_day(jd + t - ShouXingUtil::dt_t(t)).get_solar_day().is_before(d)) {
                break;
            }
            i++;
        }
        constexpr int r[] = {0, 90, 180, 270};
        const int deg = r[index / 2];
        const double t = ShouXingUtil::msa_lon_t((n + i + deg / 360.0) * ShouXingUtil::PI_2) * 36525;
        return JulianDay::from_julian_day(jd + t - ShouXingUtil::dt_t(t)).get_solar_time();
    }

    SolarTime Phase::get_solar_time() const {
        const SolarTime t = get_start_solar_time();
        return index % 2 == 1 ? t.next(1) : t;
    }

    SolarDay Phase::get_solar_day() const {
        const SolarDay d = get_start_solar_time().get_solar_day();
        return index % 2 == 1 ? d.next(1) : d;
    }

    int PhaseDay::get_day_index() const {
        return day_index;
    }

    string PhaseDay::get_name() const {
        return phase.get_name();
    }

    Phase PhaseDay::get_phase() const {
        return phase;
    }

    string PhaseDay::to_string() const {
        return phase.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }
    const vector<string> KitchenGodSteed::NUMBERS = {
        "一", "二", "三", "四", "五", "六", "七", "八", "九", "十", "十一", "十二"
    };

    KitchenGodSteed KitchenGodSteed::from_lunar_year(const int lunar_year) {
        return KitchenGodSteed(lunar_year);
    }

    string KitchenGodSteed::by_heaven_stem(const int n) const {
        return NUMBERS[first_day_sixty_cycle.get_heaven_stem().steps_to(n)];
    }

    string KitchenGodSteed::by_earth_branch(int n) const {
        return NUMBERS[first_day_sixty_cycle.get_earth_branch().steps_to(n)];
    }

    string KitchenGodSteed::get_mouse() const {
        return by_earth_branch(0) + "鼠偷粮";
    }

    string KitchenGodSteed::get_grass() const {
        return "草子" + by_earth_branch(0) + "分";
    }

    string KitchenGodSteed::get_cattle() const {
        return by_earth_branch(1) + "牛耕田";
    }

    string KitchenGodSteed::get_flower() const {
        return "花收" + by_earth_branch(3) + "分";
    }

    string KitchenGodSteed::get_dragon() const {
        return by_earth_branch(4) + "龙治水";
    }

    string KitchenGodSteed::get_horse() const {
        return by_earth_branch(6) + "马驮谷";
    }

    string KitchenGodSteed::get_chicken() const {
        return by_earth_branch(9) + "鸡抢米";
    }

    string KitchenGodSteed::get_silkworm() const {
        return by_earth_branch(9) + "姑看蚕";
    }

    string KitchenGodSteed::get_pig() const {
        return by_earth_branch(11) + "屠共猪";
    }

    string KitchenGodSteed::get_field() const {
        return "甲田" + by_heaven_stem(0) + "分";
    }

    string KitchenGodSteed::get_cake() const {
        return by_heaven_stem(2) + "人分饼";
    }

    string KitchenGodSteed::get_gold() const {
        return by_heaven_stem(7) + "日得金";
    }

    string KitchenGodSteed::get_people_cakes() const {
        return by_earth_branch(2) + "人" + by_heaven_stem(2) + "丙";
    }

    string KitchenGodSteed::get_people_hoes() const {
        return by_earth_branch(2) + "人" + by_heaven_stem(3) + "锄";
    }

    string KitchenGodSteed::get_name() const {
        return "灶马头";
    }

    SixtyCycleDay &SixtyCycleDay::operator=(const SixtyCycleDay &other) {
        solar_day = other.solar_day;
        month = other.month;
        day = other.day;
        return *this;
    }

    SixtyCycleDay SixtyCycleDay::from_solar_day(const SolarDay &solar_day) {
        return SixtyCycleDay(solar_day);
    }

    SolarDay SixtyCycleDay::get_solar_day() const {
        return solar_day;
    }

    SixtyCycleMonth SixtyCycleDay::get_sixty_cycle_month() const {
        return month.value();
    }

    SixtyCycle SixtyCycleDay::get_year() const {
        return get_sixty_cycle_month().get_year();
    }

    SixtyCycle SixtyCycleDay::get_month() const {
        return month.value().get_sixty_cycle();
    }

    SixtyCycle SixtyCycleDay::get_sixty_cycle() const {
        return day.value();
    }

    string SixtyCycleDay::get_name() const {
        return get_sixty_cycle().to_string() + "日";
    }

    string SixtyCycleDay::to_string() const {
        return month.value().to_string() + get_name();
    }

    Duty SixtyCycleDay::get_duty() const {
        return Duty::from_index(get_sixty_cycle().get_earth_branch().get_index() - get_month().get_earth_branch().get_index());
    }

    TwelveStar SixtyCycleDay::get_twelve_star() const {
        return TwelveStar::from_index(get_sixty_cycle().get_earth_branch().get_index() + (8 - get_month().get_earth_branch().get_index() % 6) * 2);
    }

    NineStar SixtyCycleDay::get_nine_star() const {
        return solar_day.get_nine_star();
    }

    Direction SixtyCycleDay::get_jupiter_direction() const {
        if (const int index = get_sixty_cycle().get_index(); index % 12 < 6) {
            return Element::from_index(index / 12).get_direction();
        }
        return get_sixty_cycle_month().get_sixty_cycle_year().get_jupiter_direction();
    }

    FetusDay SixtyCycleDay::get_fetus_day() const {
        return FetusDay::from_sixty_cycle_day(*this);
    }

    TwentyEightStar SixtyCycleDay::get_twenty_eight_star() const {
        const int indices[] = {10, 18, 26, 6, 14, 22, 2};
        return TwentyEightStar::from_index(indices[solar_day.get_week().get_index()]).next(-7 * get_sixty_cycle().get_earth_branch().get_index());
    }

    vector<God> SixtyCycleDay::get_gods() const {
        return God::get_day_gods(get_month(), get_sixty_cycle());
    }

    vector<Taboo> SixtyCycleDay::get_recommends() const {
        return Taboo::get_day_recommends(get_month(), get_sixty_cycle());
    }

    vector<Taboo> SixtyCycleDay::get_avoids() const {
        return Taboo::get_day_avoids(get_month(), get_sixty_cycle());
    }

    SixtyCycleDay SixtyCycleDay::next(int n) const {
        return from_solar_day(solar_day.next(n));
    }

    vector<SixtyCycleHour> SixtyCycleDay::get_hours() const {
        auto l = vector<SixtyCycleHour>();
        const SolarDay d = solar_day.next(-1);
        SixtyCycleHour h = SixtyCycleHour::from_solar_time(SolarTime::from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), 23, 0, 0));
        l.push_back(h);
        for (int i = 0; i < 11; i++) {
            h = h.next(7200);
            l.push_back(h);
        }
        return l;
    }

    ThreePillars SixtyCycleDay::get_three_pillars() const {
        return ThreePillars(get_year(), get_month(), get_sixty_cycle());
    }

    SixtyCycleHour SixtyCycleHour::from_solar_time(const SolarTime &solar_time) {
        return SixtyCycleHour(solar_time);
    }

    SixtyCycle SixtyCycleHour::get_year() const {
        return get_sixty_cycle_day().get_year();
    }

    SixtyCycle SixtyCycleHour::get_month() const {
        return get_sixty_cycle_day().get_month();
    }

    SixtyCycle SixtyCycleHour::get_day() const {
        return get_sixty_cycle_day().get_sixty_cycle();
    }

    SixtyCycle SixtyCycleHour::get_sixty_cycle() const {
        return hour.value();
    }

    SixtyCycleDay SixtyCycleHour::get_sixty_cycle_day() const {
        return day.value();
    }

    SolarTime SixtyCycleHour::get_solar_time() const {
        return solar_time;
    }

    string SixtyCycleHour::get_name() const {
        return get_sixty_cycle().to_string() + "时";
    }

    string SixtyCycleHour::to_string() const {
        return get_sixty_cycle_day().to_string() + get_name();
    }

    int SixtyCycleHour::get_index_in_day() const {
        int h = solar_time.get_hour();
        if (h == 23) {
            return 0;
        }
        return (h + 1) / 2;
    }

    NineStar SixtyCycleHour::get_nine_star() const {
        const SolarDay solar = solar_time.get_solar_day();
        const SolarTerm dong_zhi = SolarTerm::from_index(solar.get_year(), 0);
        const SolarTerm xia_zhi = dong_zhi.next(12);
        const int earth_branch_index = get_index_in_day() % 12;
        constexpr int indices[] = {8, 5, 2};
        int index = indices[get_day().get_earth_branch().get_index() % 3];
        if (!solar.is_before(dong_zhi.get_julian_day().get_solar_day()) && solar.is_before(xia_zhi.get_julian_day().get_solar_day())) {
            index = 8 + earth_branch_index - index;
        } else {
            index -= earth_branch_index;
        }
        return NineStar::from_index(index);
    }

    TwelveStar SixtyCycleHour::get_twelve_star() const {
        return TwelveStar::from_index(get_sixty_cycle().get_earth_branch().get_index() + (8 - get_day().get_earth_branch().get_index() % 6) * 2);
    }

    vector<Taboo> SixtyCycleHour::get_recommends() const {
        return Taboo::get_hour_recommends(get_day(), get_sixty_cycle());
    }

    vector<Taboo> SixtyCycleHour::get_avoids() const {
        return Taboo::get_hour_avoids(get_day(), get_sixty_cycle());
    }

    SixtyCycleHour SixtyCycleHour::next(const int n) const {
        return from_solar_time(solar_time.next(n));
    }

    EightChar SixtyCycleHour::get_eight_char() const {
        return EightChar(get_year(), get_month(), get_day(), get_sixty_cycle());
    }
}
