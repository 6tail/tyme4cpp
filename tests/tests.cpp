#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../tyme/tyme.h"

using namespace tyme;

TEST_CASE("constellation_test0") {
    REQUIRE("白羊" == SolarDay::from_ymd(2020, 3, 21).get_constellation().get_name());
    REQUIRE("白羊" == SolarDay::from_ymd(2020, 4, 19).get_constellation().get_name());
}

TEST_CASE("constellation_test1") {
    REQUIRE("金牛" == SolarDay::from_ymd(2020, 4, 20).get_constellation().get_name());
    REQUIRE("金牛" == SolarDay::from_ymd(2020, 5, 20).get_constellation().get_name());
}

TEST_CASE("constellation_test2") {
    REQUIRE("双子" == SolarDay::from_ymd(2020, 5, 21).get_constellation().get_name());
    REQUIRE("双子" == SolarDay::from_ymd(2020, 6, 21).get_constellation().get_name());
}

TEST_CASE("direction_test0") {
    REQUIRE("东南" == SolarDay::from_ymd(2021, 11, 13).get_lunar_day().get_sixty_cycle().get_heaven_stem().get_mascot_direction().get_name());
}

TEST_CASE("dog_day_test0") {
    const DogDay d = SolarDay::from_ymd(2011, 7, 14).get_dog_day().value();
    REQUIRE("初伏" == d.get_name());
    REQUIRE("初伏" == d.get_dog().to_string());
    REQUIRE("初伏第1天" == d.to_string());
}

TEST_CASE("duty_test_0") {
    REQUIRE("闭" == SolarDay::from_ymd(2023, 10, 30).get_lunar_day().get_duty().get_name());
}

TEST_CASE("earthly_branch_test_0") {
    REQUIRE("子" == EarthBranch::from_index(0).get_name());
}

TEST_CASE("ecliptic_test_0") {
    TwelveStar star = SolarDay::from_ymd(2023, 10, 30).get_lunar_day().get_twelve_star();
    REQUIRE("天德" == star.get_name());
    REQUIRE("黄道" == star.get_ecliptic().get_name());
    REQUIRE("吉" == star.get_ecliptic().get_luck().get_name());

    star = SolarDay::from_ymd(2023, 10, 30).get_sixty_cycle_day().get_twelve_star();
    REQUIRE("天德" == star.get_name());
    REQUIRE("黄道" == star.get_ecliptic().get_name());
    REQUIRE("吉" == star.get_ecliptic().get_luck().get_name());
}

TEST_CASE("lunar_year_test_0") {
    REQUIRE("农历癸卯年" == LunarYear::from_year(2023).get_name());
}

TEST_CASE("lunar_year_test_8") {
    REQUIRE("上元" == LunarYear::from_year(1864).get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_month_test_0") {
    REQUIRE("七月" == LunarMonth::from_ym(2359, 7).get_name());
}

TEST_CASE("eight_char_test_0") {
    // 八字
    const auto eight_char = EightChar("丙寅", "癸巳", "癸酉", "己未");

    // 年柱
    const SixtyCycle year = eight_char.get_year();
    // 月柱
    const SixtyCycle month = eight_char.get_month();
    // 日柱
    const SixtyCycle day = eight_char.get_day();
    // 时柱
    const SixtyCycle hour = eight_char.get_hour();

    // 日元(日主、日干)
    const HeavenStem me = day.get_heaven_stem();

    // 年柱天干十神
    REQUIRE("正财" == me.get_ten_star(year.get_heaven_stem()).get_name());
    // 月柱天干十神
    REQUIRE("比肩" == me.get_ten_star(month.get_heaven_stem()).get_name());
    // 时柱天干十神
    REQUIRE("七杀" == me.get_ten_star(hour.get_heaven_stem()).get_name());

    // 年柱地支十神（本气)
    REQUIRE("伤官" == me.get_ten_star(year.get_earth_branch().get_hide_heaven_stem_main()).get_name());
    // 年柱地支十神（中气)
    REQUIRE("正财" == me.get_ten_star(year.get_earth_branch().get_hide_heaven_stem_middle().value()).get_name());
    // 年柱地支十神（余气)
    REQUIRE("正官" == me.get_ten_star(year.get_earth_branch().get_hide_heaven_stem_residual().value()).get_name());

    // 日柱地支十神（本气)
    REQUIRE("偏印" == me.get_ten_star(day.get_earth_branch().get_hide_heaven_stem_main()).get_name());
    // 日柱地支藏干（中气)
    REQUIRE(nullopt == day.get_earth_branch().get_hide_heaven_stem_middle());
    // 日柱地支藏干（余气)
    REQUIRE(nullopt == day.get_earth_branch().get_hide_heaven_stem_residual());

    // 指定任意天干的十神
    REQUIRE("正财" == me.get_ten_star(HeavenStem::from_name("丙")).get_name());
}

TEST_CASE("eight_char_test_1") {
    REQUIRE("甲戌 癸酉 甲戌 甲戌" == SolarTime::from_ymd_hms(1034, 10, 2, 20, 0, 0).get_lunar_hour().get_eight_char().to_string());
}

TEST_CASE("element_test_0") {
    REQUIRE(Element::from_name("木").equals(Element::from_name("金").get_restrain()));
}

TEST_CASE("fetus_test_0") {
    REQUIRE("碓磨厕 外东南" == SolarDay::from_ymd(2021, 11, 13).get_lunar_day().get_fetus_day().get_name());
}

TEST_CASE("julian_day_test_0") {
    REQUIRE("2023年1月1日" == SolarDay::from_ymd(2023, 1, 1).get_julian_day().get_solar_day().to_string());
}

TEST_CASE("kitchen_god_steed_test_0") {
    REQUIRE("二龙治水" == KitchenGodSteed::from_lunar_year(2017).get_dragon());
}

TEST_CASE("legal_holiday_test_0") {
    const LegalHoliday d = LegalHoliday::from_ymd(2011, 5, 1).value();
    REQUIRE("2011年5月1日 劳动节(休)" == d.to_string());

    REQUIRE("2011年5月2日 劳动节(休)" == d.next(1).value().to_string());
    REQUIRE("2011年6月4日 端午节(休)" == d.next(2).value().to_string());
    REQUIRE("2011年4月30日 劳动节(休)" == d.next(-1).value().to_string());
    REQUIRE("2011年4月5日 清明节(休)" == d.next(-2).value().to_string());
}

TEST_CASE("lunar_day_test_0") {
    REQUIRE("1年1月1日" == LunarDay::from_ymd(0, 11, 18).get_solar_day().to_string());
}

TEST_CASE("lunar_festival_test_2") {
    const LunarFestival f = LunarFestival::from_index(2023, 0).value();
    REQUIRE("农历癸卯年正月初一 春节" == f.to_string());
    REQUIRE("农历癸卯年十一月初十 冬至节" == f.next(10).value().to_string());
    REQUIRE("农历甲辰年正月初一 春节" == f.next(13).value().to_string());
    REQUIRE("农历壬寅年十一月廿九 冬至节" == f.next(-3).value().to_string());
}

TEST_CASE("lunar_hour_test_0") {
    const LunarHour h = LunarHour::from_ymd_hms(2020, -4, 5, 23, 0, 0);
    REQUIRE("子时" == h.get_name());
    REQUIRE("农历庚子年闰四月初五戊子时" == h.to_string());
}

TEST_CASE("lunar_month_test_1") {
    REQUIRE("闰七月" == LunarMonth::from_ym(2359, -7).get_name());
}

TEST_CASE("nine_day_test_0") {
    const NineDay d = SolarDay::from_ymd(2020, 12, 21).get_nine_day().value();
    REQUIRE("一九" == d.get_name());
    REQUIRE("一九" == d.get_nine().to_string());
    REQUIRE("一九第1天" == d.to_string());
}

TEST_CASE("nine_star_test_0") {
    const NineStar nine_star = LunarYear::from_year(1985).get_nine_star();
    REQUIRE("六" == nine_star.get_name());
    REQUIRE("六白金" == nine_star.to_string());
}

TEST_CASE("phenology_test_0") {
    const SolarDay solar_day = SolarDay::from_ymd(2020, 4, 23);
    // 七十二候
    const PhenologyDay phenology = solar_day.get_phenology_day();
    // 三候
    const ThreePhenology three_phenology = phenology.get_phenology().get_three_phenology();
    REQUIRE("谷雨" == solar_day.get_term().get_name());
    REQUIRE("初候" == three_phenology.get_name());
    REQUIRE("萍始生" == phenology.get_name());
    REQUIRE("2020年4月19日" == phenology.get_phenology().get_julian_day().get_solar_day().to_string());
    REQUIRE("2020年4月19日 22:45:29" == phenology.get_phenology().get_julian_day().get_solar_time().to_string());
    // 该候的第5天
    REQUIRE(4 == phenology.get_day_index());
}

TEST_CASE("plum_rain_day_test_1") {
    PlumRainDay d = SolarDay::from_ymd(2024, 6, 11).get_plum_rain_day().value();
    REQUIRE("入梅" == d.get_name());
    REQUIRE("入梅" == d.get_plum_rain().to_string());
    REQUIRE("入梅第1天" == d.to_string());
}

TEST_CASE("six_star_test_0") {
    REQUIRE("佛灭" == SolarDay::from_ymd(2020, 4, 23).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("sixty_cycle_day_test_0") {
    REQUIRE("乙巳年戊寅月癸卯日" == SixtyCycleDay::from_solar_day(SolarDay::from_ymd(2025, 2, 3)).to_string());
}

TEST_CASE("sixty_cycle_hour_test_0") {
    const SixtyCycleHour hour = SolarTime::from_ymd_hms(2025, 2, 3, 23, 0, 0).get_sixty_cycle_hour();
    REQUIRE("乙巳年戊寅月甲辰日甲子时" == hour.to_string());
    const SixtyCycleDay day = hour.get_sixty_cycle_day();
    REQUIRE("乙巳年戊寅月甲辰日" == day.to_string());
    REQUIRE("2025年2月3日" == day.get_solar_day().to_string());
}

TEST_CASE("sixty_cycle_month_test_0") {
    const SixtyCycleMonth month = SixtyCycleMonth::from_index(2025, 0);
    REQUIRE("乙巳年戊寅月" == month.to_string());
}

TEST_CASE("sixty_cycle_test_0") {
    REQUIRE("丁丑" == SixtyCycle::from_index(13).get_name());
}

TEST_CASE("sixty_cycle_year_test_0") {
    REQUIRE("癸卯年" == SixtyCycleYear::from_year(2023).get_name());
}

TEST_CASE("solar_day_test_6") {
    REQUIRE("农历庚子年闰四月初二" == SolarDay::from_ymd(2020, 5, 24).get_lunar_day().to_string());
}

TEST_CASE("solar_festival_test_2") {
    const SolarFestival f = SolarFestival::from_index(2023, 0).value();
    REQUIRE("2024年5月1日 五一劳动节" == f.next(13).value().to_string());
    REQUIRE("2022年8月1日 八一建军节" == f.next(-3).value().to_string());
}

TEST_CASE("solar_half_year_test_0") {
    REQUIRE("上半年" == SolarHalfYear::from_index(2023, 0).get_name());
    REQUIRE("2023年上半年" == SolarHalfYear::from_index(2023, 0).to_string());
}

TEST_CASE("solar_month_test_3") {
    const SolarMonth m = SolarMonth::from_ym(2023, 10).next(1);
    REQUIRE("11月" == m.get_name());
    REQUIRE("2023年11月" == m.to_string());
}

TEST_CASE("solar_season_test_0") {
    const SolarSeason season = SolarSeason::from_index(2023, 0);
    REQUIRE("2023年一季度" == season.to_string());
    REQUIRE("2021年四季度" == season.next(-5).to_string());
}

TEST_CASE("solar_term_test_2") {
    // 公历2023年的雨水，2023-02-19 06:34:16
    const SolarTerm jq = SolarTerm::from_name(2023, "雨水");
    REQUIRE("雨水" == jq.get_name());
    REQUIRE(4 == jq.get_index());
}

TEST_CASE("solar_term_test_5") {
    REQUIRE("2024年1月6日 04:49:22" == SolarTerm::from_name(2024, "小寒").get_julian_day().get_solar_time().to_string());
    REQUIRE("2024年1月6日" == SolarTerm::from_name(2024, "小寒").get_solar_day().to_string());
}

TEST_CASE("solar_term_test_6") {
    REQUIRE("1034年10月1日" == SolarTerm::from_name(1034, "寒露").get_solar_day().to_string());
    REQUIRE("1034年10月3日" == SolarTerm::from_name(1034, "寒露").get_julian_day().get_solar_day().to_string());
    REQUIRE("1034年10月3日 06:02:28" == SolarTerm::from_name(1034, "寒露").get_julian_day().get_solar_time().to_string());
}

TEST_CASE("solar_time_test_0") {
    SolarTime time = SolarTime::from_ymd_hms(2023, 1, 1, 13, 5, 20);
    REQUIRE("13:05:20" == time.get_name());
    REQUIRE("13:04:59" == time.next(-21).get_name());
}

TEST_CASE("solar_year_test_0") {
    REQUIRE("2023年" == SolarYear::from_year(2023).get_name());
}

TEST_CASE("week_test_3") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 0, 0);
    REQUIRE("第一周" == w.get_name());
    REQUIRE("2023年10月第一周" == w.to_string());
}

TEST_CASE("rab_byung_year_test_0") {
    const RabByungYear y = RabByungYear::from_element_zodiac(0, RabByungElement::from_name("火"), Zodiac::from_name("兔"));
    REQUIRE("第一饶迥火兔年" == y.get_name());
    REQUIRE("1027年" == y.get_solar_year().get_name());
    REQUIRE("丁卯" == y.get_sixty_cycle().get_name());
    REQUIRE(10 == y.get_leap_month());
}

TEST_CASE("rab_byung_year_test_1") {
    REQUIRE("第一饶迥火兔年" == RabByungYear::from_year(1027).get_name());
}

TEST_CASE("rab_byung_month_test_0") {
    REQUIRE("第十六饶迥铁虎年十二月" == RabByungMonth::from_ym(1950, 12).to_string());
}

TEST_CASE("rab_byung_day_test_7") {
    REQUIRE("第十七饶迥木蛇年二月廿九" == SolarDay::from_ymd(2025, 4, 26).get_rab_byung_day().to_string());
}

TEST_CASE("lunar_festival_test_0") {
    // 测试春节
    auto festival = LunarDay::from_ymd(2023, 1, 1).get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("春节" == festival.value().get_name());

    // 测试元宵节
    festival = LunarDay::from_ymd(2023, 1, 15).get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("元宵节" == festival.value().get_name());

    // 测试端午节
    festival = LunarDay::from_ymd(2023, 5, 5).get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("端午节" == festival.value().get_name());

    // 测试中秋节
    festival = LunarDay::from_ymd(2023, 8, 15).get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("中秋节" == festival.value().get_name());

    // 测试非节日
    festival = LunarDay::from_ymd(2023, 2, 1).get_festival();
    REQUIRE_FALSE(festival.has_value());
}

TEST_CASE("solar_to_lunar_festival_test") {
    // 测试从公历日期获取农历节日

    // 测试端午节 - 公历2025年5月31日是农历五月初五(端午节)
    auto solar_day = SolarDay::from_ymd(2025, 5, 31);
    auto lunar_day = solar_day.get_lunar_day();
    auto festival = lunar_day.get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("端午节" == festival.value().get_name());

    // 测试春节 - 公历2025年1月29日是农历正月初一(春节)
    solar_day = SolarDay::from_ymd(2025, 1, 29);
    lunar_day = solar_day.get_lunar_day();
    festival = lunar_day.get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("春节" == festival.value().get_name());

    // 测试中秋节 - 公历2025年10月6日是农历八月十五(中秋节)
    solar_day = SolarDay::from_ymd(2025, 10, 6);
    lunar_day = solar_day.get_lunar_day();
    festival = lunar_day.get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("中秋节" == festival.value().get_name());
}

TEST_CASE("solar_festival_test_3") {
    // 测试从公历日期获取公历节日

    // 测试元旦节
    auto solar_day = SolarDay::from_ymd(2025, 1, 1);
    auto festival = solar_day.get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("元旦" == festival.value().get_name());

    // 测试劳动节
    solar_day = SolarDay::from_ymd(2025, 5, 1);
    festival = solar_day.get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("五一劳动节" == festival.value().get_name());

    // 测试国庆节
    solar_day = SolarDay::from_ymd(2025, 10, 1);
    festival = solar_day.get_festival();
    REQUIRE(festival.has_value());
    REQUIRE("国庆节" == festival.value().get_name());

    // 测试非节日
    solar_day = SolarDay::from_ymd(2025, 2, 1);
    festival = solar_day.get_festival();
    REQUIRE_FALSE(festival.has_value());
}

TEST_CASE("phase_test_8") {
    const PhaseDay d = SolarDay::from_ymd(2023, 9, 17).get_phase_day();
    REQUIRE("蛾眉月第2天" == d.to_string());
}

TEST_CASE("phase_test_11") {
    const Phase phase = SolarTime::from_ymd_hms(2025, 9, 22, 3, 54, 8).get_phase();
    REQUIRE("蛾眉月" == phase.to_string());
}

TEST_CASE("three_pillars_test_1") {
    REQUIRE("甲戌 甲戌 甲戌" == SolarDay::from_ymd(1034, 10, 2).get_sixty_cycle_day().get_three_pillars().get_name());
}
