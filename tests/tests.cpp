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

TEST_CASE("constellation_test3") {
    REQUIRE("巨蟹" == SolarDay::from_ymd(2020, 6, 22).get_constellation().get_name());
    REQUIRE("巨蟹" == SolarDay::from_ymd(2020, 7, 22).get_constellation().get_name());
}

TEST_CASE("constellation_test4") {
    REQUIRE("狮子" == SolarDay::from_ymd(2020, 7, 23).get_constellation().get_name());
    REQUIRE("狮子" == SolarDay::from_ymd(2020, 8, 22).get_constellation().get_name());
}

TEST_CASE("constellation_test5") {
    REQUIRE("处女" == SolarDay::from_ymd(2020, 8, 23).get_constellation().get_name());
    REQUIRE("处女" == SolarDay::from_ymd(2020, 9, 22).get_constellation().get_name());
}

TEST_CASE("constellation_test6") {
    REQUIRE("天秤" == SolarDay::from_ymd(2020, 9, 23).get_constellation().get_name());
    REQUIRE("天秤" == SolarDay::from_ymd(2020, 10, 23).get_constellation().get_name());
}

TEST_CASE("constellation_test7") {
    REQUIRE("天蝎" == SolarDay::from_ymd(2020, 10, 24).get_constellation().get_name());
    REQUIRE("天蝎" == SolarDay::from_ymd(2020, 11, 22).get_constellation().get_name());
}

TEST_CASE("constellation_test8") {
    REQUIRE("射手" == SolarDay::from_ymd(2020, 11, 23).get_constellation().get_name());
    REQUIRE("射手" == SolarDay::from_ymd(2020, 12, 21).get_constellation().get_name());
}

TEST_CASE("constellation_test9") {
    REQUIRE("摩羯" == SolarDay::from_ymd(2020, 12, 22).get_constellation().get_name());
    REQUIRE("摩羯" == SolarDay::from_ymd(2021, 1, 19).get_constellation().get_name());
}

TEST_CASE("constellation_test10") {
    REQUIRE("水瓶" == SolarDay::from_ymd(2021, 1, 20).get_constellation().get_name());
    REQUIRE("水瓶" == SolarDay::from_ymd(2021, 2, 18).get_constellation().get_name());
}

TEST_CASE("constellation_test11") {
    REQUIRE("双鱼" == SolarDay::from_ymd(2021, 2, 19).get_constellation().get_name());
    REQUIRE("双鱼" == SolarDay::from_ymd(2021, 3, 20).get_constellation().get_name());
}

TEST_CASE("direction_test0") {
    REQUIRE("东南" == SolarDay::from_ymd(2021, 11, 13).get_lunar_day().get_sixty_cycle().get_heaven_stem().get_mascot_direction().get_name());
}

TEST_CASE("direction_test1") {
    REQUIRE("东南" == SolarDay::from_ymd(2024, 1, 1).get_lunar_day().get_sixty_cycle().get_heaven_stem().get_mascot_direction().get_name());
}

TEST_CASE("direction_test2") {
    REQUIRE("东" == SolarDay::from_ymd(2023, 11, 6).get_lunar_day().get_jupiter_direction().get_name());
}

TEST_CASE("dog_day_test0") {
    const DogDay d = SolarDay::from_ymd(2011, 7, 14).get_dog_day().value();
    REQUIRE("初伏" == d.get_name());
    REQUIRE("初伏" == d.get_dog().to_string());
    REQUIRE("初伏第1天" == d.to_string());
}

TEST_CASE("dog_day_test1") {
    const DogDay d = SolarDay::from_ymd(2011, 7, 23).get_dog_day().value();
    REQUIRE("初伏" == d.get_name());
    REQUIRE("初伏第10天" == d.to_string());
}

TEST_CASE("dog_day_test2") {
    const DogDay d = SolarDay::from_ymd(2011, 7, 24).get_dog_day().value();
    REQUIRE("中伏" == d.get_name());
    REQUIRE("中伏第1天" == d.to_string());
}

TEST_CASE("dog_day_test3") {
    const DogDay d = SolarDay::from_ymd(2011, 8, 12).get_dog_day().value();
    REQUIRE("中伏" == d.get_name());
    REQUIRE("中伏第20天" == d.to_string());
}

TEST_CASE("dog_day_test4") {
    const DogDay d = SolarDay::from_ymd(2011, 8, 13).get_dog_day().value();
    REQUIRE("末伏" == d.get_name());
    REQUIRE("末伏第1天" == d.to_string());
}

TEST_CASE("dog_day_test5") {
    const DogDay d = SolarDay::from_ymd(2011, 8, 22).get_dog_day().value();
    REQUIRE("末伏" == d.get_name());
    REQUIRE("末伏第10天" == d.to_string());
}

TEST_CASE("dog_day_test6") {
    REQUIRE_FALSE(SolarDay::from_ymd(2011, 7, 13).get_dog_day().has_value());
}

TEST_CASE("dog_day_test7") {
    REQUIRE_FALSE(SolarDay::from_ymd(2011, 8, 23).get_dog_day().has_value());
}

TEST_CASE("dog_day_test8") {
    const DogDay d = SolarDay::from_ymd(2012, 7, 18).get_dog_day().value();
    REQUIRE("初伏" == d.get_name());
    REQUIRE("初伏第1天" == d.to_string());
}

TEST_CASE("dog_day_test9") {
    const DogDay d = SolarDay::from_ymd(2012, 8, 5).get_dog_day().value();
    REQUIRE("中伏" == d.get_name());
    REQUIRE("中伏第9天" == d.to_string());
}

TEST_CASE("dog_day_test10") {
    const DogDay d = SolarDay::from_ymd(2012, 8, 8).get_dog_day().value();
    REQUIRE("末伏" == d.get_name());
    REQUIRE("末伏第2天" == d.to_string());
}

TEST_CASE("duty_test_0") {
    REQUIRE("闭" == SolarDay::from_ymd(2023, 10, 30).get_lunar_day().get_duty().get_name());
    REQUIRE("闭" == SolarDay::from_ymd(2023, 10, 30).get_sixty_cycle_day().get_duty().get_name());
}

TEST_CASE("duty_test_1") {
    REQUIRE("建" == SolarDay::from_ymd(2023, 10, 19).get_lunar_day().get_duty().get_name());
    REQUIRE("建" == SolarDay::from_ymd(2023, 10, 19).get_sixty_cycle_day().get_duty().get_name());
}

TEST_CASE("duty_test_2") {
    REQUIRE("除" == SolarDay::from_ymd(2023, 10, 7).get_lunar_day().get_duty().get_name());
    REQUIRE("除" == SolarDay::from_ymd(2023, 10, 7).get_sixty_cycle_day().get_duty().get_name());
}

TEST_CASE("duty_test_3") {
    REQUIRE("除" == SolarDay::from_ymd(2023, 10, 8).get_lunar_day().get_duty().get_name());
    REQUIRE("除" == SolarDay::from_ymd(2023, 10, 8).get_sixty_cycle_day().get_duty().get_name());
}

TEST_CASE("earthly_branch_test_0") {
    REQUIRE("子" == EarthBranch::from_index(0).get_name());
}

TEST_CASE("earthly_branch_test_1") {
    REQUIRE(0 == EarthBranch::from_name("子").get_index());
}

TEST_CASE("earthly_branch_test_2") {
    REQUIRE("午" == EarthBranch::from_name("子").get_opposite().get_name());
    REQUIRE("辰" == EarthBranch::from_name("戌").get_opposite().get_name());
}

TEST_CASE("earthly_branch_test_3") {
    REQUIRE("丑" == EarthBranch::from_name("子").get_combine().get_name());
    REQUIRE("巳" == EarthBranch::from_name("申").get_combine().get_name());
}

TEST_CASE("earthly_branch_test_4") {
    REQUIRE("寅" == EarthBranch::from_name("巳").get_harm().get_name());
    REQUIRE("亥" == EarthBranch::from_name("申").get_harm().get_name());
}

TEST_CASE("earthly_branch_test_5") {
    REQUIRE("火" == EarthBranch::from_name("卯").combine(EarthBranch::from_name("戌")).value().get_name());
    REQUIRE("火" == EarthBranch::from_name("戌").combine(EarthBranch::from_name("卯")).value().get_name());
    REQUIRE_FALSE(EarthBranch::from_name("卯").combine(EarthBranch::from_name("子")).has_value());
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

TEST_CASE("ecliptic_test_1") {
    TwelveStar star = SolarDay::from_ymd(2023, 10, 19).get_lunar_day().get_twelve_star();
    REQUIRE("白虎" == star.get_name());
    REQUIRE("黑道" == star.get_ecliptic().get_name());
    REQUIRE("凶" == star.get_ecliptic().get_luck().get_name());

    star = SolarDay::from_ymd(2023, 10, 19).get_sixty_cycle_day().get_twelve_star();
    REQUIRE("白虎" == star.get_name());
    REQUIRE("黑道" == star.get_ecliptic().get_name());
    REQUIRE("凶" == star.get_ecliptic().get_luck().get_name());
}

TEST_CASE("ecliptic_test_2") {
    TwelveStar star = SolarDay::from_ymd(2023, 10, 7).get_lunar_day().get_twelve_star();
    REQUIRE("天牢" == star.get_name());
    REQUIRE("黑道" == star.get_ecliptic().get_name());
    REQUIRE("凶" == star.get_ecliptic().get_luck().get_name());

    star = SolarDay::from_ymd(2023, 10, 7).get_sixty_cycle_day().get_twelve_star();
    REQUIRE("天牢" == star.get_name());
    REQUIRE("黑道" == star.get_ecliptic().get_name());
    REQUIRE("凶" == star.get_ecliptic().get_luck().get_name());
}

TEST_CASE("ecliptic_test_3") {
    TwelveStar star = SolarDay::from_ymd(2023, 10, 8).get_lunar_day().get_twelve_star();
    REQUIRE("玉堂" == star.get_name());
    REQUIRE("黄道" == star.get_ecliptic().get_name());
    REQUIRE("吉" == star.get_ecliptic().get_luck().get_name());

    star = SolarDay::from_ymd(2023, 10, 8).get_sixty_cycle_day().get_twelve_star();
    REQUIRE("玉堂" == star.get_name());
    REQUIRE("黄道" == star.get_ecliptic().get_name());
    REQUIRE("吉" == star.get_ecliptic().get_luck().get_name());
}

TEST_CASE("lunar_year_test_0") {
    REQUIRE("农历癸卯年" == LunarYear::from_year(2023).get_name());
}

TEST_CASE("lunar_year_test_1") {
    REQUIRE("农历戊申年" == LunarYear::from_year(2023).next(5).get_name());
}

TEST_CASE("lunar_year_test_2") {
    REQUIRE("农历戊戌年" == LunarYear::from_year(2023).next(-5).get_name());
}

TEST_CASE("lunar_year_test_3") {
    REQUIRE("庚子" == LunarYear::from_year(2020).get_sixty_cycle().get_name());
}

TEST_CASE("lunar_year_test_4") {
    REQUIRE("虎" == LunarYear::from_year(1986).get_sixty_cycle().get_earth_branch().get_zodiac().get_name());
}

TEST_CASE("lunar_year_test_5") {
    REQUIRE(12 == LunarYear::from_year(151).get_leap_month());
}

TEST_CASE("lunar_year_test_6") {
    REQUIRE(1 == LunarYear::from_year(2357).get_leap_month());
}

TEST_CASE("lunar_year_test_7") {
    const LunarYear y = LunarYear::from_year(2023);
    REQUIRE("癸卯" == y.get_sixty_cycle().get_name());
    REQUIRE("兔" == y.get_sixty_cycle().get_earth_branch().get_zodiac().get_name());
}

TEST_CASE("lunar_year_test_8") {
    REQUIRE("上元" == LunarYear::from_year(1864).get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_year_test_9") {
    REQUIRE("上元" == LunarYear::from_year(1923).get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_year_test_10") {
    REQUIRE("中元" == LunarYear::from_year(1924).get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_year_test_11") {
    REQUIRE("中元" == LunarYear::from_year(1983).get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_year_test_12") {
    REQUIRE("下元" == LunarYear::from_year(1984).get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_year_test_13") {
    REQUIRE("下元" == LunarYear::from_year(2043).get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_year_test_14") {
    REQUIRE("一运" == LunarYear::from_year(1864).get_twenty().get_name());
}

TEST_CASE("lunar_year_test_15") {
    REQUIRE("一运" == LunarYear::from_year(1883).get_twenty().get_name());
}

TEST_CASE("lunar_year_test_16") {
    REQUIRE("二运" == LunarYear::from_year(1884).get_twenty().get_name());
}

TEST_CASE("lunar_year_test_17") {
    REQUIRE("二运" == LunarYear::from_year(1903).get_twenty().get_name());
}

TEST_CASE("lunar_year_test_18") {
    REQUIRE("三运" == LunarYear::from_year(1904).get_twenty().get_name());
}

TEST_CASE("lunar_year_test_19") {
    REQUIRE("三运" == LunarYear::from_year(1923).get_twenty().get_name());
}

TEST_CASE("lunar_year_test_20") {
    REQUIRE("八运" == LunarYear::from_year(2004).get_twenty().get_name());
}

TEST_CASE("lunar_year_test_21") {
    const LunarYear year = LunarYear::from_year(1);
    REQUIRE("六运" == year.get_twenty().get_name());
    REQUIRE("中元" == year.get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_year_test_22") {
    const LunarYear year = LunarYear::from_year(1863);
    REQUIRE("九运" == year.get_twenty().get_name());
    REQUIRE("下元" == year.get_twenty().get_sixty().get_name());
}

TEST_CASE("lunar_month_test_0") {
    REQUIRE("七月" == LunarMonth::from_ym(2359, 7).get_name());
}

TEST_CASE("lunar_month_test_2") {
    REQUIRE(29 == LunarMonth::from_ym(2023, 6).get_day_count());
}

TEST_CASE("lunar_month_test_3") {
    REQUIRE(30 == LunarMonth::from_ym(2023, 7).get_day_count());
}

TEST_CASE("lunar_month_test_4") {
    REQUIRE(30 == LunarMonth::from_ym(2023, 8).get_day_count());
}

TEST_CASE("lunar_month_test_5") {
    REQUIRE(29 == LunarMonth::from_ym(2023, 9).get_day_count());
}

TEST_CASE("lunar_month_test_6") {
    REQUIRE("2023年10月15日" == LunarMonth::from_ym(2023, 9).get_first_julian_day().get_solar_day().to_string());
}

TEST_CASE("lunar_month_test_7") {
    REQUIRE("甲寅" == LunarMonth::from_ym(2023, 1).get_sixty_cycle().get_name());
}

TEST_CASE("lunar_month_test_8") {
    REQUIRE("乙卯" == LunarMonth::from_ym(2023, -2).get_sixty_cycle().get_name());
}

TEST_CASE("lunar_month_test_9") {
    REQUIRE("丙辰" == LunarMonth::from_ym(2023, 3).get_sixty_cycle().get_name());
}

TEST_CASE("lunar_month_test_10") {
    REQUIRE("丙寅" == LunarMonth::from_ym(2024, 1).get_sixty_cycle().get_name());
}

TEST_CASE("lunar_month_test_11") {
    REQUIRE("乙丑" == LunarMonth::from_ym(2023, 12).get_sixty_cycle().get_name());
}

TEST_CASE("lunar_month_test_12") {
    REQUIRE("壬寅" == LunarMonth::from_ym(2022, 1).get_sixty_cycle().get_name());
}

TEST_CASE("lunar_month_test_13") {
    REQUIRE("闰十二月" == LunarMonth::from_ym(37, -12).get_name());
}

TEST_CASE("lunar_month_test_14") {
    REQUIRE("闰十二月" == LunarMonth::from_ym(5552, -12).get_name());
}

TEST_CASE("lunar_month_test_15") {
    REQUIRE("农历戊子年十二月" == LunarMonth::from_ym(2008, 11).next(1).to_string());
}

TEST_CASE("lunar_month_test_16") {
    REQUIRE("农历己丑年正月" == LunarMonth::from_ym(2008, 11).next(2).to_string());
}

TEST_CASE("lunar_month_test_17") {
    REQUIRE("农历己丑年五月" == LunarMonth::from_ym(2008, 11).next(6).to_string());
}

TEST_CASE("lunar_month_test_18") {
    REQUIRE("农历己丑年闰五月" == LunarMonth::from_ym(2008, 11).next(7).to_string());
}

TEST_CASE("lunar_month_test_19") {
    REQUIRE("农历己丑年六月" == LunarMonth::from_ym(2008, 11).next(8).to_string());
}

TEST_CASE("lunar_month_test_20") {
    REQUIRE("农历庚寅年正月" == LunarMonth::from_ym(2008, 11).next(15).to_string());
}

TEST_CASE("lunar_month_test_21") {
    REQUIRE("农历戊子年十一月" == LunarMonth::from_ym(2008, 12).next(-1).to_string());
}

TEST_CASE("lunar_month_test_22") {
    REQUIRE("农历戊子年十一月" == LunarMonth::from_ym(2009, 1).next(-2).to_string());
}

TEST_CASE("lunar_month_test_23") {
    REQUIRE("农历戊子年十一月" == LunarMonth::from_ym(2009, 5).next(-6).to_string());
}

TEST_CASE("lunar_month_test_24") {
    REQUIRE("农历戊子年十一月" == LunarMonth::from_ym(2009, -5).next(-7).to_string());
}

TEST_CASE("lunar_month_test_25") {
    REQUIRE("农历戊子年十一月" == LunarMonth::from_ym(2009, 6).next(-8).to_string());
}

TEST_CASE("lunar_month_test_26") {
    REQUIRE("农历戊子年十一月" == LunarMonth::from_ym(2010, 1).next(-15).to_string());
}

TEST_CASE("lunar_month_test_27") {
    REQUIRE(29 == LunarMonth::from_ym(2012, -4).get_day_count());
}

TEST_CASE("lunar_month_test_28") {
    REQUIRE("壬戌" == LunarMonth::from_ym(2023, 9).get_sixty_cycle().to_string());
}

TEST_CASE("lunar_month_test_29") {
    const SolarDay solar_day = SolarDay::from_ymd(2023, 10, 7);
    const LunarDay lunar_day = solar_day.get_lunar_day();
    REQUIRE("辛酉" == lunar_day.get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("辛酉" == lunar_day.get_sixty_cycle_day().get_month().to_string());
    REQUIRE("辛酉" == solar_day.get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_30") {
    const SolarDay solar_day = SolarDay::from_ymd(2023, 10, 8);
    const LunarDay lunar_day = solar_day.get_lunar_day();
    REQUIRE("辛酉" == lunar_day.get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("壬戌" == lunar_day.get_sixty_cycle_day().get_month().to_string());
    REQUIRE("壬戌" == solar_day.get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_31") {
    const SolarDay solar_day = SolarDay::from_ymd(2023, 10, 15);
    const LunarDay lunar_day = solar_day.get_lunar_day();
    REQUIRE("九月" == lunar_day.get_lunar_month().get_name());
    REQUIRE("壬戌" == lunar_day.get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("壬戌" == lunar_day.get_sixty_cycle_day().get_month().to_string());
    REQUIRE("壬戌" == solar_day.get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_32") {
    const SolarDay solar_day = SolarDay::from_ymd(2023, 11, 7);
    const LunarDay lunar_day = solar_day.get_lunar_day();
    REQUIRE("壬戌" == lunar_day.get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("壬戌" == lunar_day.get_sixty_cycle_day().get_month().to_string());
    REQUIRE("壬戌" == solar_day.get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_33") {
    const SolarDay solar_day = SolarDay::from_ymd(2023, 11, 8);
    const LunarDay lunar_day = solar_day.get_lunar_day();
    REQUIRE("壬戌" == lunar_day.get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("癸亥" == lunar_day.get_sixty_cycle_day().get_month().to_string());
    REQUIRE("癸亥" == solar_day.get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_34") {
    const LunarMonth m = LunarMonth::from_ym(2023, 12);
    REQUIRE("农历癸卯年十二月" == m.to_string());
    REQUIRE("农历癸卯年十一月" == m.next(-1).to_string());
    REQUIRE("农历癸卯年十月" == m.next(-2).to_string());
}

TEST_CASE("lunar_month_test_35") {
    const LunarMonth m = LunarMonth::from_ym(2023, 3);
    REQUIRE("农历癸卯年三月" == m.to_string());
    REQUIRE("农历癸卯年闰二月" == m.next(-1).to_string());
    REQUIRE("农历癸卯年二月" == m.next(-2).to_string());
    REQUIRE("农历癸卯年正月" == m.next(-3).to_string());
    REQUIRE("农历壬寅年十二月" == m.next(-4).to_string());
    REQUIRE("农历壬寅年十一月" == m.next(-5).to_string());
}

TEST_CASE("lunar_month_test_36") {
    const SolarDay solar_day = SolarDay::from_ymd(1983, 2, 15);
    const LunarDay lunar_day = solar_day.get_lunar_day();
    REQUIRE("甲寅" == lunar_day.get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("甲寅" == lunar_day.get_sixty_cycle_day().get_month().to_string());
    REQUIRE("甲寅" == solar_day.get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_37") {
    const SolarDay solar_day = SolarDay::from_ymd(2023, 10, 30);
    const LunarDay lunar_day = solar_day.get_lunar_day();
    REQUIRE("壬戌" == lunar_day.get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("壬戌" == lunar_day.get_sixty_cycle_day().get_month().to_string());
    REQUIRE("壬戌" == solar_day.get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_38") {
    const SolarDay solar_day = SolarDay::from_ymd(2023, 10, 19);
    const LunarDay lunar_day = solar_day.get_lunar_day();
    REQUIRE("壬戌" == lunar_day.get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("壬戌" == lunar_day.get_sixty_cycle_day().get_month().to_string());
    REQUIRE("壬戌" == solar_day.get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_39") {
    const LunarMonth m = LunarMonth::from_ym(2023, 11);
    REQUIRE("农历癸卯年十一月" == m.to_string());
    REQUIRE("甲子" == m.get_sixty_cycle().to_string());
}

TEST_CASE("lunar_month_test_40") {
    REQUIRE("己未" == LunarDay::from_ymd(2018, 6, 26).get_lunar_month().get_sixty_cycle().to_string());
    REQUIRE("庚申" == LunarDay::from_ymd(2018, 6, 26).get_sixty_cycle_day().get_month().to_string());
}

TEST_CASE("lunar_month_test_41") {
    REQUIRE("辛丑" == LunarMonth::from_ym(1991, 12).get_sixty_cycle().to_string());
}

TEST_CASE("lunar_month_test_42") {
    REQUIRE("速喜" == LunarMonth::from_ym(1991, 3).get_minor_ren().get_name());
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

TEST_CASE("eight_char_test_2") {
    const auto eight_char = EightChar("丙寅", "癸巳", "癸酉", "己未");
    const SixtyCycle year = eight_char.get_year();
    const SixtyCycle month = eight_char.get_month();
    const SixtyCycle day = eight_char.get_day();
    const SixtyCycle hour = eight_char.get_hour();
    const HeavenStem me = day.get_heaven_stem();
    REQUIRE("沐浴" == me.get_terrain(year.get_earth_branch()).get_name());
    REQUIRE("胎" == me.get_terrain(month.get_earth_branch()).get_name());
    REQUIRE("病" == me.get_terrain(day.get_earth_branch()).get_name());
    REQUIRE("墓" == me.get_terrain(hour.get_earth_branch()).get_name());
}

TEST_CASE("eight_char_test_3") {
    const auto eight_char = EightChar("癸卯", "辛酉", "己亥", "癸酉");
    const SixtyCycle tai_yuan = eight_char.get_fetal_origin();
    REQUIRE("壬子" == tai_yuan.get_name());
    REQUIRE("桑柘木" == tai_yuan.get_sound().get_name());
}

TEST_CASE("eight_char_test_4") {
    const auto eight_char = EightChar("癸卯", "辛酉", "己亥", "癸酉");
    const SixtyCycle tai_xi = eight_char.get_fetal_breath();
    REQUIRE("甲寅" == tai_xi.get_name());
    REQUIRE("大溪水" == tai_xi.get_sound().get_name());
}

TEST_CASE("eight_char_test_5") {
    const auto eight_char = EightChar("癸卯", "辛酉", "己亥", "癸酉");
    const SixtyCycle ming_gong = eight_char.get_own_sign();
    REQUIRE("癸亥" == ming_gong.get_name());
    REQUIRE("大海水" == ming_gong.get_sound().get_name());
}

TEST_CASE("eight_char_test_6") {
    const auto eight_char = EightChar("癸卯", "辛酉", "己亥", "癸酉");
    const SixtyCycle shen_gong = eight_char.get_body_sign();
    REQUIRE("己未" == shen_gong.get_name());
    REQUIRE("天上火" == shen_gong.get_sound().get_name());
}

TEST_CASE("eight_char_test_7") {
    const auto eight_char = EightChar("乙酉", "戊子", "辛巳", "壬辰");
    const HeavenStem me = eight_char.get_day().get_heaven_stem();
    REQUIRE("临官" == me.get_terrain(eight_char.get_year().get_earth_branch()).get_name());
    REQUIRE("长生" == me.get_terrain(eight_char.get_month().get_earth_branch()).get_name());
    REQUIRE("死" == me.get_terrain(eight_char.get_day().get_earth_branch()).get_name());
    REQUIRE("墓" == me.get_terrain(eight_char.get_hour().get_earth_branch()).get_name());
}

TEST_CASE("eight_char_test_8") {
    const EightChar eight_char = SolarTime::from_ymd_hms(2005, 12, 23, 8, 37, 0).get_lunar_hour().get_eight_char();
    REQUIRE("乙酉" == eight_char.get_year().get_name());
    REQUIRE("戊子" == eight_char.get_month().get_name());
    REQUIRE("辛巳" == eight_char.get_day().get_name());
    REQUIRE("壬辰" == eight_char.get_hour().get_name());
}

TEST_CASE("eight_char_test_9") {
    const EightChar eight_char = SolarTime::from_ymd_hms(1988, 2, 15, 23, 30, 0).get_lunar_hour().get_eight_char();
    REQUIRE("戊辰" == eight_char.get_year().get_name());
    REQUIRE("甲寅" == eight_char.get_month().get_name());
    REQUIRE("辛丑" == eight_char.get_day().get_name());
    REQUIRE("戊子" == eight_char.get_hour().get_name());
}

TEST_CASE("eight_char_test_10") {
    const EightChar eight_char = SolarTime::from_ymd_hms(1986, 5, 29, 13, 37, 0).get_lunar_hour().get_eight_char();
    REQUIRE("丙寅 癸巳 癸酉 己未" == eight_char.to_string());
    REQUIRE("癸巳" == eight_char.get_own_sign().get_name());
    REQUIRE("辛丑" == eight_char.get_body_sign().get_name());
    REQUIRE("甲申" == eight_char.get_fetal_origin().get_name());
    REQUIRE("戊辰" == eight_char.get_fetal_breath().get_name());
}

TEST_CASE("eight_char_test_11") {
    const EightChar eight_char = SolarTime::from_ymd_hms(1994, 12, 6, 2, 0, 0).get_lunar_hour().get_eight_char();
    REQUIRE("甲戌 乙亥 丙寅 己丑" == eight_char.to_string());
    REQUIRE("己巳" == eight_char.get_own_sign().get_name());
    REQUIRE("丁丑" == eight_char.get_body_sign().get_name());
    REQUIRE("丙寅" == eight_char.get_fetal_origin().get_name());
    REQUIRE("辛亥" == eight_char.get_fetal_breath().get_name());
}

TEST_CASE("eight_char_test_12") {
    REQUIRE("己亥" == EightChar("丙寅", "庚寅", "辛卯", "壬辰").get_own_sign().get_name());
    REQUIRE("乙未" == EightChar("丙寅", "庚寅", "辛卯", "壬辰").get_body_sign().get_name());
}

TEST_CASE("eight_char_test_13") {
    REQUIRE("丁丑" == EightChar("己丑", "戊辰", "戊辰", "甲子").get_own_sign().get_name());
}

TEST_CASE("eight_char_test_14") {
    REQUIRE("乙卯" == EightChar("戊戌", "庚申", "丁亥", "丙午").get_own_sign().get_name());
}

TEST_CASE("eight_char_test_15") {
    REQUIRE("辛卯" == EightChar("辛亥", "丁酉", "丙午", "癸巳").get_own_sign().get_name());
}

TEST_CASE("eight_char_test_16") {
    REQUIRE("乙巳" == EightChar("壬子", "辛亥", "壬戌", "乙巳").get_body_sign().get_name());
}

TEST_CASE("eight_char_test_17") {
    REQUIRE("辛酉 丙申 丙戌 戊子" == SolarTime::from_ymd_hms(1981, 9, 5, 0, 0, 0).get_lunar_hour().get_eight_char().to_string());
}

TEST_CASE("eight_char_test_18") {
    REQUIRE("壬申" == EightChar("甲辰", "丙寅", "己亥", "辛未").get_own_sign().get_name());
}

TEST_CASE("eight_char_test_19") {
    const EightChar eight_char = SolarTime::from_ymd_hms(1980, 6, 15, 12, 30, 30).get_lunar_hour().get_eight_char();
    REQUIRE("辛巳" == eight_char.get_own_sign().get_name());
    REQUIRE("己丑" == eight_char.get_body_sign().get_name());
    REQUIRE("癸酉" == eight_char.get_fetal_origin().get_name());
    REQUIRE("甲午" == eight_char.get_fetal_breath().get_name());
}

TEST_CASE("eight_char_test_20") {
    REQUIRE("长生" == HeavenStem::from_name("丙").get_terrain(EarthBranch::from_name("寅")).get_name());
}

TEST_CASE("element_test_0") {
    REQUIRE(Element::from_name("木").equals(Element::from_name("金").get_restrain()));
}

TEST_CASE("element_test_1") {
    REQUIRE(Element::from_name("土").equals(Element::from_name("火").get_reinforce()));
}

TEST_CASE("element_test_2") {
    REQUIRE("火" == HeavenStem::from_name("丙").get_element().get_name());
}

TEST_CASE("element_test_3") {
    REQUIRE("木" == EarthBranch::from_name("寅").get_element().get_name());
    REQUIRE(Element::from_name("火").equals(EarthBranch::from_name("寅").get_element().get_reinforce()));
}

TEST_CASE("element_test_4") {
    REQUIRE(Element::from_name("火").equals(Element::from_name("土").get_reinforced()));
}

TEST_CASE("fetus_test_0") {
    REQUIRE("碓磨厕 外东南" == SolarDay::from_ymd(2021, 11, 13).get_lunar_day().get_fetus_day().get_name());
}

TEST_CASE("fetus_test_1") {
    REQUIRE("占门碓 外东南" == SolarDay::from_ymd(2021, 11, 12).get_lunar_day().get_fetus_day().get_name());
}

TEST_CASE("fetus_test_2") {
    REQUIRE("厨灶厕 外西南" == SolarDay::from_ymd(2011, 11, 12).get_lunar_day().get_fetus_day().get_name());
}

TEST_CASE("julian_day_test_0") {
    REQUIRE("2023年1月1日" == SolarDay::from_ymd(2023, 1, 1).get_julian_day().get_solar_day().to_string());
}

TEST_CASE("kitchen_god_steed_test_0") {
    REQUIRE("二龙治水" == KitchenGodSteed::from_lunar_year(2017).get_dragon());
    REQUIRE("二龙治水" == KitchenGodSteed::from_lunar_year(2018).get_dragon());
    REQUIRE("八龙治水" == KitchenGodSteed::from_lunar_year(2019).get_dragon());
    REQUIRE("三龙治水" == KitchenGodSteed::from_lunar_year(5).get_dragon());
}

TEST_CASE("kitchen_god_steed_test_1") {
    REQUIRE("二人分饼" == KitchenGodSteed::from_lunar_year(2017).get_cake());
    REQUIRE("八人分饼" == KitchenGodSteed::from_lunar_year(2018).get_cake());
    REQUIRE("一人分饼" == KitchenGodSteed::from_lunar_year(5).get_cake());
}

TEST_CASE("kitchen_god_steed_test_2") {
    REQUIRE("十一牛耕田" == KitchenGodSteed::from_lunar_year(2021).get_cattle());
}

TEST_CASE("kitchen_god_steed_test_3") {
    REQUIRE("三日得金" == KitchenGodSteed::from_lunar_year(2018).get_gold());
}

TEST_CASE("legal_holiday_test_0") {
    const LegalHoliday d = LegalHoliday::from_ymd(2011, 5, 1).value();
    REQUIRE("2011年5月1日 劳动节(休)" == d.to_string());

    REQUIRE("2011年5月2日 劳动节(休)" == d.next(1).value().to_string());
    REQUIRE("2011年6月4日 端午节(休)" == d.next(2).value().to_string());
    REQUIRE("2011年4月30日 劳动节(休)" == d.next(-1).value().to_string());
    REQUIRE("2011年4月5日 清明节(休)" == d.next(-2).value().to_string());
}

TEST_CASE("legal_holiday_test_1") {
    REQUIRE(LegalHoliday::from_ymd(2010, 1, 1).has_value());
}

TEST_CASE("legal_holiday_test_3") {
    const LegalHoliday d = LegalHoliday::from_ymd(2001, 12, 29).value();
    REQUIRE("2001年12月29日 元旦(班)" == d.to_string());
    REQUIRE_FALSE(d.next(-1).has_value());
}

TEST_CASE("legal_holiday_test_4") {
    const LegalHoliday d = LegalHoliday::from_ymd(2022, 10, 5).value();
    REQUIRE("2022年10月5日 国庆节(休)" == d.to_string());
    REQUIRE("2022年10月4日 国庆节(休)" == d.next(-1).value().to_string());
    REQUIRE("2022年10月6日 国庆节(休)" == d.next(1).value().to_string());
}

TEST_CASE("lunar_day_test_0") {
    REQUIRE("1年1月1日" == LunarDay::from_ymd(0, 11, 18).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_1") {
    REQUIRE("9999年12月31日" == LunarDay::from_ymd(9999, 12, 2).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_2") {
    REQUIRE("1905年2月4日" == LunarDay::from_ymd(1905, 1, 1).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_3") {
    REQUIRE("2039年1月23日" == LunarDay::from_ymd(2038, 12, 29).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_4") {
    REQUIRE("1500年1月31日" == LunarDay::from_ymd(1500, 1, 1).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_5") {
    REQUIRE("1501年1月18日" == LunarDay::from_ymd(1500, 12, 29).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_6") {
    REQUIRE("1582年10月4日" == LunarDay::from_ymd(1582, 9, 18).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_7") {
    REQUIRE("1582年10月15日" == LunarDay::from_ymd(1582, 9, 19).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_8") {
    REQUIRE("2020年1月6日" == LunarDay::from_ymd(2019, 12, 12).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_9") {
    REQUIRE("2033年12月22日" == LunarDay::from_ymd(2033, -11, 1).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_10") {
    REQUIRE("己亥" == LunarDay::from_ymd(2023, 8, 24).get_sixty_cycle().to_string());
}

TEST_CASE("lunar_day_test_11") {
    REQUIRE("癸酉" == LunarDay::from_ymd(1653, 1, 6).get_sixty_cycle().to_string());
}

TEST_CASE("lunar_day_test_12") {
    REQUIRE("农历庚寅年二月初二" == LunarDay::from_ymd(2010, 1, 1).next(31).to_string());
}

TEST_CASE("lunar_day_test_13") {
    REQUIRE("农历壬辰年闰四月初一" == LunarDay::from_ymd(2012, 3, 1).next(60).to_string());
}

TEST_CASE("lunar_day_test_14") {
    REQUIRE("农历壬辰年闰四月廿九" == LunarDay::from_ymd(2012, 3, 1).next(88).to_string());
}

TEST_CASE("lunar_day_test_15") {
    REQUIRE("农历壬辰年五月初一" == LunarDay::from_ymd(2012, 3, 1).next(89).to_string());
}

TEST_CASE("lunar_day_test_16") {
    REQUIRE("2020年4月23日" == LunarDay::from_ymd(2020, 4, 1).get_solar_day().to_string());
}

TEST_CASE("lunar_day_test_17") {
    REQUIRE("甲辰" == LunarDay::from_ymd(2024, 1, 1).get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());
}

TEST_CASE("lunar_day_test_18") {
    REQUIRE("癸卯" == LunarDay::from_ymd(2023, 12, 30).get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());
}

TEST_CASE("lunar_day_test_19") {
    const LunarDay d = LunarDay::from_ymd(2020, 4, 13);
    const TwentyEightStar star = d.get_twenty_eight_star();
    REQUIRE("南" == star.get_zone().get_name());
    REQUIRE("朱雀" == star.get_zone().get_beast().get_name());
    REQUIRE("翼" == star.get_name());
    REQUIRE("火" == star.get_seven_star().get_name());
    REQUIRE("蛇" == star.get_animal().get_name());
    REQUIRE("凶" == star.get_luck().get_name());
    REQUIRE("阳天" == star.get_land().get_name());
    REQUIRE("东南" == star.get_land().get_direction().get_name());
}

TEST_CASE("lunar_day_test_20") {
    const LunarDay d = LunarDay::from_ymd(2023, 9, 28);
    const TwentyEightStar star = d.get_twenty_eight_star();
    REQUIRE("南" == star.get_zone().get_name());
    REQUIRE("朱雀" == star.get_zone().get_beast().get_name());
    REQUIRE("柳" == star.get_name());
    REQUIRE("土" == star.get_seven_star().get_name());
    REQUIRE("獐" == star.get_animal().get_name());
    REQUIRE("凶" == star.get_luck().get_name());
    REQUIRE("炎天" == star.get_land().get_name());
    REQUIRE("南" == star.get_land().get_direction().get_name());
}

TEST_CASE("lunar_day_test_21") {
    const LunarDay lunar = LunarDay::from_ymd(2005, 11, 23);
    REQUIRE("戊子" == lunar.get_lunar_month().get_sixty_cycle().get_name());
    REQUIRE("戊子" == lunar.get_sixty_cycle_day().get_month().get_name());
}

TEST_CASE("lunar_day_test_22") {
    const LunarDay lunar = LunarDay::from_ymd(2024, 1, 1);
    REQUIRE("农历甲辰年二月初三" == lunar.next(31).to_string());
}

TEST_CASE("lunar_day_test_23") {
    const LunarDay lunar = LunarDay::from_ymd(2024, 3, 5);
    REQUIRE("大安" == lunar.get_minor_ren().get_name());
}

TEST_CASE("lunar_day_test_24") {
    const LunarDay lunar = SolarDay::from_ymd(2026, 2, 5).get_lunar_day();
    REQUIRE("己丑" == lunar.get_lunar_month().get_sixty_cycle().get_name());
}

TEST_CASE("lunar_day_test_25") {
    const LunarDay d0 = LunarDay::from_ymd(2028, 4, 2);
    const LunarDay d1 = LunarDay::from_ymd(2028, 5, 2);
    const LunarDay d2 = LunarDay::from_ymd(2028, -5, 2);
    const LunarDay d3 = LunarDay::from_ymd(2028, 6, 2);
    REQUIRE(d0.is_before(d1));
    REQUIRE(d0.is_before(d2));
    REQUIRE(d0.is_before(d3));
    REQUIRE(d1.is_before(d2));
    REQUIRE(d1.is_before(d3));
    REQUIRE(d2.is_before(d3));
    REQUIRE_FALSE(d3.is_before(d2));
    REQUIRE_FALSE(d3.is_before(d1));
    REQUIRE_FALSE(d3.is_before(d0));
    REQUIRE_FALSE(d2.is_before(d1));
    REQUIRE_FALSE(d2.is_before(d0));
    REQUIRE_FALSE(d1.is_before(d0));
}

TEST_CASE("lunar_day_test_26") {
    const LunarDay d0 = LunarDay::from_ymd(2028, 4, 2);
    const LunarDay d1 = LunarDay::from_ymd(2028, 5, 2);
    const LunarDay d2 = LunarDay::from_ymd(2028, -5, 2);
    const LunarDay d3 = LunarDay::from_ymd(2028, 6, 2);
    REQUIRE(d3.is_after(d2));
    REQUIRE(d3.is_after(d1));
    REQUIRE(d3.is_after(d0));
    REQUIRE(d2.is_after(d1));
    REQUIRE(d2.is_after(d0));
    REQUIRE(d1.is_after(d0));
    REQUIRE_FALSE(d0.is_after(d1));
    REQUIRE_FALSE(d0.is_after(d2));
    REQUIRE_FALSE(d0.is_after(d3));
    REQUIRE_FALSE(d1.is_after(d2));
    REQUIRE_FALSE(d1.is_after(d3));
    REQUIRE_FALSE(d2.is_after(d3));
}

TEST_CASE("lunar_festival_test_2") {
    const LunarFestival f = LunarFestival::from_index(2023, 0).value();
    REQUIRE("农历癸卯年正月初一 春节" == f.to_string());
    REQUIRE("农历癸卯年十一月初十 冬至节" == f.next(10).value().to_string());
    REQUIRE("农历甲辰年正月初一 春节" == f.next(13).value().to_string());
    REQUIRE("农历壬寅年十一月廿九 冬至节" == f.next(-3).value().to_string());
}

TEST_CASE("lunar_festival_test_3") {
    const LunarFestival f = LunarFestival::from_index(2023, 0).value();
    REQUIRE("农历壬寅年三月初五 清明节" == f.next(-9).value().to_string());
}

TEST_CASE("lunar_festival_test_4") {
    const LunarFestival f = LunarDay::from_ymd(2010, 1, 15).get_festival().value();
    REQUIRE("农历庚寅年正月十五 元宵节" == f.to_string());
}

TEST_CASE("lunar_festival_test_5") {
    const LunarFestival f = LunarDay::from_ymd(2021, 12, 29).get_festival().value();
    REQUIRE("农历辛丑年十二月廿九 除夕" == f.to_string());
}

TEST_CASE("lunar_festival_test_6") {
    const LunarFestival f = SolarDay::from_ymd(2025, 12, 21).get_lunar_day().get_festival().value();
    REQUIRE("农历乙巳年十一月初二 冬至节" == f.to_string());
}

TEST_CASE("lunar_festival_test_7") {
    const LunarFestival f = LunarDay::from_ymd(2025, 5, 5).get_festival().value();
    REQUIRE("农历乙巳年五月初五 端午节" == f.to_string());
}

TEST_CASE("lunar_hour_test_0") {
    const LunarHour h = LunarHour::from_ymd_hms(2020, -4, 5, 23, 0, 0);
    REQUIRE("子时" == h.get_name());
    REQUIRE("农历庚子年闰四月初五戊子时" == h.to_string());
}

TEST_CASE("lunar_hour_test_1") {
    const LunarHour h = LunarHour::from_ymd_hms(2020, -4, 5, 0, 59, 0);
    REQUIRE("子时" == h.get_name());
    REQUIRE("农历庚子年闰四月初五丙子时" == h.to_string());
}

TEST_CASE("lunar_hour_test_2") {
    const LunarHour h = LunarHour::from_ymd_hms(2020, -4, 5, 1, 0, 0);
    REQUIRE("丑时" == h.get_name());
    REQUIRE("农历庚子年闰四月初五丁丑时" == h.to_string());
}

TEST_CASE("lunar_hour_test_3") {
    const LunarHour h = LunarHour::from_ymd_hms(2020, -4, 5, 21, 30, 0);
    REQUIRE("亥时" == h.get_name());
    REQUIRE("农历庚子年闰四月初五丁亥时" == h.to_string());
}

TEST_CASE("lunar_hour_test_4") {
    const LunarHour h = LunarHour::from_ymd_hms(2020, -4, 2, 23, 30, 0);
    REQUIRE("子时" == h.get_name());
    REQUIRE("农历庚子年闰四月初二壬子时" == h.to_string());
}

TEST_CASE("lunar_hour_test_5") {
    const LunarHour h = LunarHour::from_ymd_hms(2020, 4, 28, 23, 30, 0);
    REQUIRE("子时" == h.get_name());
    REQUIRE("农历庚子年四月廿八甲子时" == h.to_string());
}

TEST_CASE("lunar_hour_test_6") {
    const LunarHour h = LunarHour::from_ymd_hms(2020, 4, 29, 0, 0, 0);
    REQUIRE("子时" == h.get_name());
    REQUIRE("农历庚子年四月廿九甲子时" == h.to_string());
}

TEST_CASE("lunar_hour_test_7") {
    const LunarHour h = LunarHour::from_ymd_hms(2023, 11, 14, 23, 0, 0);
    const SixtyCycleHour sixty_cycle_hour = h.get_sixty_cycle_hour();
    REQUIRE("甲子" == h.get_sixty_cycle().get_name());
    REQUIRE("己未" == sixty_cycle_hour.get_day().get_name());
    REQUIRE("戊午" == h.get_lunar_day().get_sixty_cycle().get_name());
    REQUIRE("农历癸卯年十一月十四" == h.get_lunar_day().to_string());
    REQUIRE("甲子" == sixty_cycle_hour.get_month().get_name());
    REQUIRE("农历癸卯年十一月" == h.get_lunar_day().get_lunar_month().to_string());
    REQUIRE("甲子" == h.get_lunar_day().get_lunar_month().get_sixty_cycle().get_name());
    REQUIRE("癸卯" == sixty_cycle_hour.get_year().get_name());
    REQUIRE("农历癸卯年" == h.get_lunar_day().get_lunar_month().get_lunar_year().to_string());
    REQUIRE("癸卯" == h.get_lunar_day().get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());
}

TEST_CASE("lunar_hour_test_8") {
    const LunarHour h = LunarHour::from_ymd_hms(2023, 11, 14, 6, 0, 0);
    const SixtyCycleHour sixty_cycle_hour = h.get_sixty_cycle_hour();
    REQUIRE("乙卯" == h.get_sixty_cycle().get_name());
    REQUIRE("戊午" == sixty_cycle_hour.get_day().get_name());
    REQUIRE("戊午" == h.get_lunar_day().get_sixty_cycle().get_name());
    REQUIRE("农历癸卯年十一月十四" == h.get_lunar_day().to_string());
    REQUIRE("甲子" == sixty_cycle_hour.get_month().get_name());
    REQUIRE("农历癸卯年十一月" == h.get_lunar_day().get_lunar_month().to_string());
    REQUIRE("甲子" == h.get_lunar_day().get_lunar_month().get_sixty_cycle().get_name());
    REQUIRE("癸卯" == sixty_cycle_hour.get_year().get_name());
    REQUIRE("农历癸卯年" == h.get_lunar_day().get_lunar_month().get_lunar_year().to_string());
    REQUIRE("癸卯" == h.get_lunar_day().get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());
}

TEST_CASE("lunar_hour_test_9") {
    const LunarHour h = LunarHour::from_ymd_hms(2024, 9, 7, 10, 0, 0);
    REQUIRE("留连" == h.get_minor_ren().get_name());
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

TEST_CASE("nine_day_test_1") {
    const NineDay d = SolarDay::from_ymd(2020, 12, 22).get_nine_day().value();
    REQUIRE("一九" == d.get_name());
    REQUIRE("一九第2天" == d.to_string());
}

TEST_CASE("nine_day_test_2") {
    const NineDay d = SolarDay::from_ymd(2020, 1, 7).get_nine_day().value();
    REQUIRE("二九" == d.get_name());
    REQUIRE("二九第8天" == d.to_string());
}

TEST_CASE("nine_day_test_3") {
    const NineDay d = SolarDay::from_ymd(2021, 1, 6).get_nine_day().value();
    REQUIRE("二九" == d.get_name());
    REQUIRE("二九第8天" == d.to_string());
}

TEST_CASE("nine_day_test_4") {
    const NineDay d = SolarDay::from_ymd(2021, 1, 8).get_nine_day().value();
    REQUIRE("三九" == d.get_name());
    REQUIRE("三九第1天" == d.to_string());
}

TEST_CASE("nine_day_test_5") {
    const NineDay d = SolarDay::from_ymd(2021, 3, 5).get_nine_day().value();
    REQUIRE("九九" == d.get_name());
    REQUIRE("九九第3天" == d.to_string());
}

TEST_CASE("nine_day_test_6") {
    REQUIRE_FALSE(SolarDay::from_ymd(2021, 7, 5).get_nine_day().has_value());
}

TEST_CASE("nine_star_test_0") {
    const NineStar nine_star = LunarYear::from_year(1985).get_nine_star();
    REQUIRE("六" == nine_star.get_name());
    REQUIRE("六白金" == nine_star.to_string());
}

TEST_CASE("nine_star_test_1") {
    const NineStar nine_star = LunarYear::from_year(2022).get_nine_star();
    REQUIRE("五黄土" == nine_star.to_string());
    REQUIRE("玉衡" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_2") {
    const NineStar nine_star = LunarYear::from_year(2033).get_nine_star();
    REQUIRE("三碧木" == nine_star.to_string());
    REQUIRE("天玑" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_3") {
    const NineStar nine_star = LunarMonth::from_ym(1985, 2).get_nine_star();
    REQUIRE("四绿木" == nine_star.to_string());
    REQUIRE("天权" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_5") {
    const NineStar nine_star = LunarMonth::from_ym(2022, 1).get_nine_star();
    REQUIRE("二黑土" == nine_star.to_string());
    REQUIRE("天璇" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_6") {
    const NineStar nine_star = LunarMonth::from_ym(2033, 1).get_nine_star();
    REQUIRE("五黄土" == nine_star.to_string());
    REQUIRE("玉衡" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_7") {
    const NineStar nine_star = SolarDay::from_ymd(1985, 2, 19).get_lunar_day().get_nine_star();
    REQUIRE("五黄土" == nine_star.to_string());
    REQUIRE("玉衡" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_8") {
    const NineStar nine_star = LunarDay::from_ymd(2022, 1, 1).get_nine_star();
    REQUIRE("四绿木" == nine_star.to_string());
    REQUIRE("天权" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_9") {
    const NineStar nine_star = LunarDay::from_ymd(2033, 1, 1).get_nine_star();
    REQUIRE("一白水" == nine_star.to_string());
    REQUIRE("天枢" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_10") {
    const NineStar nine_star = LunarHour::from_ymd_hms(2033, 1, 1, 12, 0, 0).get_nine_star();
    REQUIRE("七赤金" == nine_star.to_string());
    REQUIRE("摇光" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_11") {
    const NineStar nine_star = LunarHour::from_ymd_hms(2011, 5, 3, 23, 0, 0).get_nine_star();
    REQUIRE("七赤金" == nine_star.to_string());
    REQUIRE("摇光" == nine_star.get_dipper().to_string());
}

TEST_CASE("nine_star_test_12") {
    REQUIRE("四绿木" == LunarMonth::from_ym(2024, 11).get_nine_star().to_string());
    REQUIRE("三碧木" == LunarMonth::from_ym(2024, 12).get_nine_star().to_string());
}

TEST_CASE("nine_star_test_13") {
    REQUIRE("九紫火" == SolarDay::from_ymd(2026, 6, 19).get_lunar_day().get_nine_star().to_string());
}

TEST_CASE("nine_star_test_14") {
    REQUIRE("一白水" == SolarDay::from_ymd(2026, 12, 16).get_lunar_day().get_nine_star().to_string());
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

TEST_CASE("phenology_test_1") {
    const SolarDay solar_day = SolarDay::from_ymd(2021, 12, 26);
    const PhenologyDay phenology = solar_day.get_phenology_day();
    const ThreePhenology three_phenology = phenology.get_phenology().get_three_phenology();
    REQUIRE("冬至" == solar_day.get_term().get_name());
    REQUIRE("2021年12月21日" == solar_day.get_term().get_julian_day().get_solar_day().to_string());
    REQUIRE("二候" == three_phenology.get_name());
    REQUIRE("麋角解" == phenology.get_name());
    REQUIRE("2021年12月26日" == phenology.get_phenology().get_julian_day().get_solar_day().to_string());
    REQUIRE("2021年12月26日 21:48:55" == phenology.get_phenology().get_julian_day().get_solar_time().to_string());
    REQUIRE(0 == phenology.get_day_index());
}

TEST_CASE("phenology_test_2") {
    const Phenology p = Phenology::from_index(2026, 1);
    const JulianDay jd = p.get_julian_day();
    REQUIRE("麋角解" == p.get_name());
    REQUIRE("2025年12月26日" == jd.get_solar_day().to_string());
    REQUIRE("2025年12月26日 20:49:56" == jd.get_solar_time().to_string());
}

TEST_CASE("phenology_test_3") {
    const Phenology p = SolarDay::from_ymd(2025, 12, 26).get_phenology();
    const JulianDay jd = p.get_julian_day();
    REQUIRE("麋角解" == p.get_name());
    REQUIRE("2025年12月26日" == jd.get_solar_day().to_string());
    REQUIRE("2025年12月26日 20:49:56" == jd.get_solar_time().to_string());
}

TEST_CASE("phenology_test_4") {
    REQUIRE("蚯蚓结" == SolarTime::from_ymd_hms(2025, 12, 26, 20, 49, 38).get_phenology().get_name());
    REQUIRE("麋角解" == SolarTime::from_ymd_hms(2025, 12, 26, 20, 49, 56).get_phenology().get_name());
}

TEST_CASE("plum_rain_day_test_0") {
    REQUIRE_FALSE(SolarDay::from_ymd(2024, 6, 10).get_plum_rain_day().has_value());
}

TEST_CASE("plum_rain_day_test_1") {
    PlumRainDay d = SolarDay::from_ymd(2024, 6, 11).get_plum_rain_day().value();
    REQUIRE("入梅" == d.get_name());
    REQUIRE("入梅" == d.get_plum_rain().to_string());
    REQUIRE("入梅第1天" == d.to_string());
}

TEST_CASE("plum_rain_day_test_2") {
    PlumRainDay d = SolarDay::from_ymd(2024, 7, 6).get_plum_rain_day().value();
    REQUIRE("出梅" == d.get_name());
    REQUIRE("出梅" == d.get_plum_rain().to_string());
    REQUIRE("出梅" == d.to_string());
}

TEST_CASE("plum_rain_day_test_3") {
    PlumRainDay d = SolarDay::from_ymd(2024, 7, 5).get_plum_rain_day().value();
    REQUIRE("入梅" == d.get_name());
    REQUIRE("入梅第25天" == d.to_string());
}

TEST_CASE("six_star_test_0") {
    REQUIRE("佛灭" == SolarDay::from_ymd(2020, 4, 23).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("six_star_test_1") {
    REQUIRE("友引" == SolarDay::from_ymd(2021, 1, 15).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("six_star_test_2") {
    REQUIRE("先胜" == SolarDay::from_ymd(2017, 1, 5).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("six_star_test_3") {
    REQUIRE("友引" == SolarDay::from_ymd(2020, 4, 10).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("six_star_test_4") {
    REQUIRE("大安" == SolarDay::from_ymd(2020, 6, 11).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("six_star_test_5") {
    REQUIRE("先胜" == SolarDay::from_ymd(2020, 6, 1).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("six_star_test_6") {
    REQUIRE("先负" == SolarDay::from_ymd(2020, 12, 8).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("six_star_test_7") {
    REQUIRE("赤口" == SolarDay::from_ymd(2020, 12, 11).get_lunar_day().get_six_star().get_name());
}

TEST_CASE("sixty_cycle_day_test_0") {
    REQUIRE("乙巳年戊寅月癸卯日" == SixtyCycleDay::from_solar_day(SolarDay::from_ymd(2025, 2, 3)).to_string());
}

TEST_CASE("sixty_cycle_day_test_1") {
    REQUIRE("甲辰年丁丑月壬寅日" == SixtyCycleDay::from_solar_day(SolarDay::from_ymd(2025, 2, 2)).to_string());
}

TEST_CASE("sixty_cycle_hour_test_0") {
    const SixtyCycleHour hour = SolarTime::from_ymd_hms(2025, 2, 3, 23, 0, 0).get_sixty_cycle_hour();
    REQUIRE("乙巳年戊寅月甲辰日甲子时" == hour.to_string());
    const SixtyCycleDay day = hour.get_sixty_cycle_day();
    REQUIRE("乙巳年戊寅月甲辰日" == day.to_string());
    REQUIRE("2025年2月3日" == day.get_solar_day().to_string());
}

TEST_CASE("sixty_cycle_hour_test_1") {
    const SixtyCycleHour hour = SolarTime::from_ymd_hms(2025, 2, 3, 4, 0, 0).get_sixty_cycle_hour();
    REQUIRE("甲辰年丁丑月癸卯日甲寅时" == hour.to_string());
    const SixtyCycleDay day = hour.get_sixty_cycle_day();
    REQUIRE("甲辰年丁丑月癸卯日" == day.to_string());
    REQUIRE("2025年2月3日" == day.get_solar_day().to_string());
}

TEST_CASE("sixty_cycle_hour_test_2") {
    const SixtyCycleHour hour = SolarTime::from_ymd_hms(2025, 2, 3, 22, 30, 0).get_sixty_cycle_hour();
    REQUIRE("乙巳年戊寅月癸卯日癸亥时" == hour.to_string());
    const SixtyCycleDay day = hour.get_sixty_cycle_day();
    REQUIRE("乙巳年戊寅月癸卯日" == day.to_string());
    REQUIRE("2025年2月3日" == day.get_solar_day().to_string());
}

TEST_CASE("sixty_cycle_hour_test_3") {
    const EightChar eight_char = SolarTime::from_ymd_hms(1988, 2, 15, 23, 30, 0).get_sixty_cycle_hour().get_eight_char();
    REQUIRE("戊辰" == eight_char.get_year().get_name());
    REQUIRE("甲寅" == eight_char.get_month().get_name());
    REQUIRE("辛丑" == eight_char.get_day().get_name());
    REQUIRE("戊子" == eight_char.get_hour().get_name());
}

TEST_CASE("sixty_cycle_month_test_0") {
    const SixtyCycleMonth month = SixtyCycleMonth::from_index(2025, 0);
    REQUIRE("乙巳年戊寅月" == month.to_string());
    REQUIRE("乙巳年己卯月" == month.next(1).to_string());
    REQUIRE("甲辰年丁丑月" == month.next(-1).to_string());
}

TEST_CASE("sixty_cycle_month_test_1") {
    const SixtyCycleMonth month = SixtyCycleMonth::from_index(1150, 0);
    REQUIRE("庚午年戊寅月" == month.to_string());
    REQUIRE("庚午年戊寅月戊寅日" == month.get_first_day().to_string());
}

TEST_CASE("sixty_cycle_test_0") {
    REQUIRE("丁丑" == SixtyCycle::from_index(13).get_name());
}

TEST_CASE("sixty_cycle_test_1") {
    REQUIRE(13 == SixtyCycle::from_name("丁丑").get_index());
}

TEST_CASE("sixty_cycle_test_2") {
    REQUIRE("石榴木" == SixtyCycle::from_name("辛酉").get_sound().get_name());
    REQUIRE("剑锋金" == SixtyCycle::from_name("癸酉").get_sound().get_name());
    REQUIRE("平地木" == SixtyCycle::from_name("己亥").get_sound().get_name());
}

TEST_CASE("sixty_cycle_test_3") {
    REQUIRE("甲子" == SixtyCycle::from_name("甲子").get_ten().get_name());
    REQUIRE("甲寅" == SixtyCycle::from_name("乙卯").get_ten().get_name());
    REQUIRE("甲申" == SixtyCycle::from_name("癸巳").get_ten().get_name());
}

TEST_CASE("sixty_cycle_test_4") {
    const auto ab1 = SixtyCycle::from_name("甲子").get_extra_earth_branches();
    REQUIRE(2 == ab1.size());
    REQUIRE("戌" == ab1[0].get_name());
    REQUIRE("亥" == ab1[1].get_name());

    const auto ab2 = SixtyCycle::from_name("乙卯").get_extra_earth_branches();
    REQUIRE(2 == ab2.size());
    REQUIRE("子" == ab2[0].get_name());
    REQUIRE("丑" == ab2[1].get_name());

    const auto ab3 = SixtyCycle::from_name("癸巳").get_extra_earth_branches();
    REQUIRE(2 == ab3.size());
    REQUIRE("午" == ab3[0].get_name());
    REQUIRE("未" == ab3[1].get_name());
}

TEST_CASE("sixty_cycle_test_5") {
    REQUIRE("长生" == HeavenStem::from_name("丙").get_terrain(EarthBranch::from_name("寅")).get_name());
    REQUIRE("沐浴" == HeavenStem::from_name("辛").get_terrain(EarthBranch::from_name("亥")).get_name());
}

TEST_CASE("sixty_cycle_year_test_0") {
    REQUIRE("癸卯年" == SixtyCycleYear::from_year(2023).get_name());
}

TEST_CASE("sixty_cycle_year_test_1") {
    REQUIRE("戊申年" == SixtyCycleYear::from_year(2023).next(5).get_name());
}

TEST_CASE("sixty_cycle_year_test_2") {
    REQUIRE("戊戌年" == SixtyCycleYear::from_year(2023).next(-5).get_name());
}

TEST_CASE("sixty_cycle_year_test_3") {
    REQUIRE("庚子" == SixtyCycleYear::from_year(2020).get_sixty_cycle().get_name());
}

TEST_CASE("sixty_cycle_year_test_4") {
    REQUIRE("虎" == SixtyCycleYear::from_year(1986).get_sixty_cycle().get_earth_branch().get_zodiac().get_name());
}

TEST_CASE("sixty_cycle_year_test_5") {
    REQUIRE("庚子年" == SixtyCycleYear::from_year(2025).next(-5).get_name());
}

TEST_CASE("sixty_cycle_year_test_7") {
    const SixtyCycleYear y = SixtyCycleYear::from_year(2023);
    REQUIRE("癸卯" == y.get_sixty_cycle().get_name());
    REQUIRE("兔" == y.get_sixty_cycle().get_earth_branch().get_zodiac().get_name());
}

TEST_CASE("sixty_cycle_year_test_8") {
    REQUIRE("上元" == SixtyCycleYear::from_year(1864).get_twenty().get_sixty().get_name());
}

TEST_CASE("sixty_cycle_year_test_9") {
    REQUIRE("上元" == SixtyCycleYear::from_year(1923).get_twenty().get_sixty().get_name());
}

TEST_CASE("sixty_cycle_year_test_10") {
    REQUIRE("中元" == SixtyCycleYear::from_year(1924).get_twenty().get_sixty().get_name());
}

TEST_CASE("sixty_cycle_year_test_11") {
    REQUIRE("中元" == SixtyCycleYear::from_year(1983).get_twenty().get_sixty().get_name());
}

TEST_CASE("sixty_cycle_year_test_12") {
    REQUIRE("下元" == SixtyCycleYear::from_year(1984).get_twenty().get_sixty().get_name());
}

TEST_CASE("sixty_cycle_year_test_13") {
    REQUIRE("下元" == SixtyCycleYear::from_year(2043).get_twenty().get_sixty().get_name());
}

TEST_CASE("sixty_cycle_year_test_14") {
    REQUIRE("一运" == SixtyCycleYear::from_year(1864).get_twenty().get_name());
}

TEST_CASE("sixty_cycle_year_test_15") {
    REQUIRE("一运" == SixtyCycleYear::from_year(1883).get_twenty().get_name());
}

TEST_CASE("sixty_cycle_year_test_16") {
    REQUIRE("二运" == SixtyCycleYear::from_year(1884).get_twenty().get_name());
}

TEST_CASE("sixty_cycle_year_test_17") {
    REQUIRE("二运" == SixtyCycleYear::from_year(1903).get_twenty().get_name());
}

TEST_CASE("sixty_cycle_year_test_18") {
    REQUIRE("三运" == SixtyCycleYear::from_year(1904).get_twenty().get_name());
}

TEST_CASE("sixty_cycle_year_test_19") {
    REQUIRE("三运" == SixtyCycleYear::from_year(1923).get_twenty().get_name());
}

TEST_CASE("sixty_cycle_year_test_20") {
    REQUIRE("八运" == SixtyCycleYear::from_year(2004).get_twenty().get_name());
}

TEST_CASE("sixty_cycle_year_test_21") {
    const SixtyCycleYear year = SixtyCycleYear::from_year(1);
    REQUIRE("六运" == year.get_twenty().get_name());
    REQUIRE("中元" == year.get_twenty().get_sixty().get_name());
}

TEST_CASE("sixty_cycle_year_test_22") {
    const SixtyCycleYear year = SixtyCycleYear::from_year(1863);
    REQUIRE("九运" == year.get_twenty().get_name());
    REQUIRE("下元" == year.get_twenty().get_sixty().get_name());
}

TEST_CASE("sixty_cycle_year_test_23") {
    const SixtyCycleYear year = SixtyCycleYear::from_year(2025);
    REQUIRE("戊寅月" == year.get_first_month().get_name());
}

TEST_CASE("solar_day_test_0") {
    REQUIRE("1日" == SolarDay::from_ymd(2023, 1, 1).get_name());
    REQUIRE("2023年1月1日" == SolarDay::from_ymd(2023, 1, 1).to_string());
}

TEST_CASE("solar_day_test_1") {
    REQUIRE("29日" == SolarDay::from_ymd(2000, 2, 29).get_name());
    REQUIRE("2000年2月29日" == SolarDay::from_ymd(2000, 2, 29).to_string());
}

TEST_CASE("solar_day_test_2") {
    REQUIRE(0 == SolarDay::from_ymd(2023, 1, 1).get_index_in_year());
    REQUIRE(364 == SolarDay::from_ymd(2023, 12, 31).get_index_in_year());
    REQUIRE(365 == SolarDay::from_ymd(2020, 12, 31).get_index_in_year());
}

TEST_CASE("solar_day_test_3") {
    REQUIRE(0 == SolarDay::from_ymd(2023, 1, 1).subtract(SolarDay::from_ymd(2023, 1, 1)));
    REQUIRE(1 == SolarDay::from_ymd(2023, 1, 2).subtract(SolarDay::from_ymd(2023, 1, 1)));
    REQUIRE(-1 == SolarDay::from_ymd(2023, 1, 1).subtract(SolarDay::from_ymd(2023, 1, 2)));
    REQUIRE(31 == SolarDay::from_ymd(2023, 2, 1).subtract(SolarDay::from_ymd(2023, 1, 1)));
    REQUIRE(-31 == SolarDay::from_ymd(2023, 1, 1).subtract(SolarDay::from_ymd(2023, 2, 1)));
    REQUIRE(365 == SolarDay::from_ymd(2024, 1, 1).subtract(SolarDay::from_ymd(2023, 1, 1)));
    REQUIRE(-365 == SolarDay::from_ymd(2023, 1, 1).subtract(SolarDay::from_ymd(2024, 1, 1)));
    REQUIRE(1 == SolarDay::from_ymd(1582, 10, 15).subtract(SolarDay::from_ymd(1582, 10, 4)));
}

TEST_CASE("solar_day_test_4") {
    REQUIRE("1582年10月4日" == SolarDay::from_ymd(1582, 10, 15).next(-1).to_string());
}

TEST_CASE("solar_day_test_5") {
    REQUIRE("2000年3月1日" == SolarDay::from_ymd(2000, 2, 28).next(2).to_string());
}

TEST_CASE("solar_day_test_6") {
    REQUIRE("农历庚子年闰四月初二" == SolarDay::from_ymd(2020, 5, 24).get_lunar_day().to_string());
}

TEST_CASE("solar_day_test_7") {
    REQUIRE(31 == SolarDay::from_ymd(2020, 5, 24).subtract(SolarDay::from_ymd(2020, 4, 23)));
}

TEST_CASE("solar_day_test_8") {
    REQUIRE("农历丙子年十一月十二" == SolarDay::from_ymd(16, 11, 30).get_lunar_day().to_string());
}

TEST_CASE("solar_day_test_9") {
    REQUIRE("霜降" == SolarDay::from_ymd(2023, 10, 27).get_term().to_string());
}

TEST_CASE("solar_day_test_10") {
    REQUIRE("豺乃祭兽第4天" == SolarDay::from_ymd(2023, 10, 27).get_phenology_day().to_string());
}

TEST_CASE("solar_day_test_11") {
    REQUIRE("初候" == SolarDay::from_ymd(2023, 10, 27).get_phenology_day().get_phenology().get_three_phenology().to_string());
}

TEST_CASE("solar_day_test_22") {
    REQUIRE("甲辰" == SolarDay::from_ymd(2024, 2, 10).get_lunar_day().get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());
}

TEST_CASE("solar_day_test_23") {
    REQUIRE("癸卯" == SolarDay::from_ymd(2024, 2, 9).get_lunar_day().get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());
}

TEST_CASE("solar_day_test_24") {
    const SolarDay prev = LunarDay::from_ymd(2025, 1, 1).get_solar_day();
    const SolarDay next = LunarDay::from_ymd(2026, 1, 1).get_solar_day();
    const SolarDay today = SolarDay::from_ymd(2025, 2, 17);
    REQUIRE("2025年1月29日" == prev.to_string());
    REQUIRE("2026年2月17日" == next.to_string());
    REQUIRE(384 == next.subtract(prev));
    REQUIRE(365 == next.subtract(today));
}

TEST_CASE("solar_festival_test_2") {
    const SolarFestival f = SolarFestival::from_index(2023, 0).value();
    REQUIRE("2024年5月1日 劳动节" == f.next(13).value().to_string());
    REQUIRE("2022年8月1日 建军节" == f.next(-3).value().to_string());
}

TEST_CASE("solar_festival_test_3") {
    const SolarFestival f = SolarFestival::from_index(2023, 0).value();
    REQUIRE("2022年3月8日 妇女节" == f.next(-9).value().to_string());
}

TEST_CASE("solar_festival_test_4") {
    const SolarFestival f = SolarDay::from_ymd(2010, 1, 1).get_festival().value();
    REQUIRE("2010年1月1日 元旦" == f.to_string());
}

TEST_CASE("solar_festival_test_5") {
    const SolarFestival f = SolarDay::from_ymd(2021, 5, 4).get_festival().value();
    REQUIRE("2021年5月4日 青年节" == f.to_string());
}

TEST_CASE("solar_festival_test_6") {
    REQUIRE_FALSE(SolarDay::from_ymd(1939, 5, 4).get_festival().has_value());
}

TEST_CASE("solar_half_year_test_0") {
    REQUIRE("上半年" == SolarHalfYear::from_index(2023, 0).get_name());
    REQUIRE("2023年上半年" == SolarHalfYear::from_index(2023, 0).to_string());
}

TEST_CASE("solar_half_year_test_1") {
    REQUIRE("下半年" == SolarHalfYear::from_index(2023, 1).get_name());
    REQUIRE("2023年下半年" == SolarHalfYear::from_index(2023, 1).to_string());
}

TEST_CASE("solar_half_year_test_2") {
    REQUIRE("下半年" == SolarHalfYear::from_index(2023, 0).next(1).get_name());
    REQUIRE("2023年下半年" == SolarHalfYear::from_index(2023, 0).next(1).to_string());
}

TEST_CASE("solar_half_year_test_3") {
    REQUIRE("上半年" == SolarHalfYear::from_index(2023, 0).next(2).get_name());
    REQUIRE("2024年上半年" == SolarHalfYear::from_index(2023, 0).next(2).to_string());
}

TEST_CASE("solar_half_year_test_4") {
    REQUIRE("上半年" == SolarHalfYear::from_index(2023, 0).next(-2).get_name());
    REQUIRE("2022年上半年" == SolarHalfYear::from_index(2023, 0).next(-2).to_string());
}

TEST_CASE("solar_half_year_test_5") {
    REQUIRE("2021年上半年" == SolarHalfYear::from_index(2023, 0).next(-4).to_string());
    REQUIRE("2021年下半年" == SolarHalfYear::from_index(2023, 0).next(-3).to_string());
}

TEST_CASE("solar_month_test_0") {
    const SolarMonth m = SolarMonth::from_ym(2019, 5);
    REQUIRE("5月" == m.get_name());
    REQUIRE("2019年5月" == m.to_string());
}

TEST_CASE("solar_month_test_1") {
    const SolarMonth m = SolarMonth::from_ym(2023, 1);
    REQUIRE(5 == m.get_week_count(0));
    REQUIRE(6 == m.get_week_count(1));
    REQUIRE(6 == m.get_week_count(2));
    REQUIRE(5 == m.get_week_count(3));
    REQUIRE(5 == m.get_week_count(4));
    REQUIRE(5 == m.get_week_count(5));
    REQUIRE(5 == m.get_week_count(6));
}

TEST_CASE("solar_month_test_2") {
    const SolarMonth m = SolarMonth::from_ym(2023, 2);
    REQUIRE(5 == m.get_week_count(0));
    REQUIRE(5 == m.get_week_count(1));
    REQUIRE(5 == m.get_week_count(2));
    REQUIRE(4 == m.get_week_count(3));
    REQUIRE(5 == m.get_week_count(4));
    REQUIRE(5 == m.get_week_count(5));
    REQUIRE(5 == m.get_week_count(6));
}

TEST_CASE("solar_month_test_3") {
    const SolarMonth m = SolarMonth::from_ym(2023, 10).next(1);
    REQUIRE("11月" == m.get_name());
    REQUIRE("2023年11月" == m.to_string());
}

TEST_CASE("solar_month_test_4") {
    const SolarMonth m = SolarMonth::from_ym(2023, 10);
    REQUIRE("2023年12月" == m.next(2).to_string());
    REQUIRE("2024年1月" == m.next(3).to_string());
    REQUIRE("2023年5月" == m.next(-5).to_string());
    REQUIRE("2023年1月" == m.next(-9).to_string());
    REQUIRE("2022年12月" == m.next(-10).to_string());
    REQUIRE("2025年10月" == m.next(24).to_string());
    REQUIRE("2021年10月" == m.next(-24).to_string());
}

TEST_CASE("solar_season_test_0") {
    const SolarSeason season = SolarSeason::from_index(2023, 0);
    REQUIRE("2023年一季度" == season.to_string());
    REQUIRE("2021年四季度" == season.next(-5).to_string());
}

TEST_CASE("solar_term_test_0") {
    const SolarTerm dong_zhi = SolarTerm::from_name(2023, "冬至");
    REQUIRE("冬至" == dong_zhi.get_name());
    REQUIRE(0 == dong_zhi.get_index());
    REQUIRE("2022年12月22日" == dong_zhi.get_julian_day().get_solar_day().to_string());
    REQUIRE("2022年12月22日" == dong_zhi.get_solar_day().to_string());

    const SolarTerm da_xue = dong_zhi.next(23);
    REQUIRE("大雪" == da_xue.get_name());
    REQUIRE(23 == da_xue.get_index());
    REQUIRE("2023年12月7日" == da_xue.get_julian_day().get_solar_day().to_string());
    REQUIRE("2023年12月7日" == da_xue.get_solar_day().to_string());

    const SolarTerm xiao_xue = dong_zhi.next(-2);
    REQUIRE("小雪" == xiao_xue.get_name());
    REQUIRE(22 == xiao_xue.get_index());
    REQUIRE("2022年11月22日" == xiao_xue.get_julian_day().get_solar_day().to_string());
    REQUIRE("2022年11月22日" == xiao_xue.get_solar_day().to_string());

    const SolarTerm dong_zhi2 = dong_zhi.next(24);
    REQUIRE("冬至" == dong_zhi2.get_name());
    REQUIRE(0 == dong_zhi2.get_index());
    REQUIRE("2023年12月22日" == dong_zhi2.get_julian_day().get_solar_day().to_string());
    REQUIRE("2023年12月22日" == dong_zhi2.get_solar_day().to_string());
}

TEST_CASE("solar_term_test_1") {
    const SolarTerm jq = SolarTerm::from_name(2023, "大雪");
    REQUIRE("大雪" == jq.get_name());
    REQUIRE(23 == jq.get_index());
    REQUIRE("2023年12月7日" == jq.get_julian_day().get_solar_day().to_string());
    REQUIRE("2023年12月7日" == jq.get_solar_day().to_string());
    REQUIRE("农历癸卯年十月廿五" == jq.get_julian_day().get_solar_day().get_lunar_day().to_string());
    REQUIRE("雨水" == jq.next(5).get_name());
}

TEST_CASE("solar_term_test_2") {
    // 公历2023年的雨水，2023-02-19 06:34:16
    const SolarTerm jq = SolarTerm::from_name(2023, "雨水");
    REQUIRE("雨水" == jq.get_name());
    REQUIRE(4 == jq.get_index());
}

TEST_CASE("solar_term_test_3") {
    REQUIRE("寒露" == SolarDay::from_ymd(2023, 10, 10).get_term().get_name());
}

TEST_CASE("solar_term_test_4") {
    REQUIRE("大雪第1天" == SolarDay::from_ymd(2023, 12, 7).get_term_day().to_string());
    REQUIRE(0 == SolarDay::from_ymd(2023, 12, 7).get_term_day().get_day_index());
    REQUIRE("大雪第2天" == SolarDay::from_ymd(2023, 12, 8).get_term_day().to_string());
    REQUIRE("大雪第15天" == SolarDay::from_ymd(2023, 12, 21).get_term_day().to_string());
    REQUIRE("冬至第1天" == SolarDay::from_ymd(2023, 12, 22).get_term_day().to_string());
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

TEST_CASE("solar_term_test_7") {
    REQUIRE("立春" == SolarDay::from_ymd(1150, 1, 30).get_term().to_string());
}

TEST_CASE("solar_term_test_8") {
    REQUIRE("1008年1月31日" == SolarTerm::from_name(1008, "立春").get_solar_day().to_string());
    REQUIRE("1008年1月30日" == SolarTerm::from_name(1008, "立春").get_julian_day().get_solar_day().to_string());
    REQUIRE("1008年1月30日 01:55:22" == SolarTerm::from_name(1008, "立春").get_julian_day().get_solar_time().to_string());
}

TEST_CASE("solar_time_test_0") {
    SolarTime time = SolarTime::from_ymd_hms(2023, 1, 1, 13, 5, 20);
    REQUIRE("13:05:20" == time.get_name());
    REQUIRE("13:04:59" == time.next(-21).get_name());
}

TEST_CASE("solar_time_test_1") {
    SolarTime time = SolarTime::from_ymd_hms(2023, 1, 1, 13, 5, 20);
    REQUIRE("13:05:20" == time.get_name());
    REQUIRE("14:06:01" == time.next(3641).get_name());
}

TEST_CASE("solar_year_test_0") {
    REQUIRE("2023年" == SolarYear::from_year(2023).get_name());
}

TEST_CASE("solar_year_test_1") {
    REQUIRE_FALSE(SolarYear::from_year(2023).is_leap());
}

TEST_CASE("solar_year_test_2") {
    REQUIRE(SolarYear::from_year(1500).is_leap());
}

TEST_CASE("solar_year_test_3") {
    REQUIRE_FALSE(SolarYear::from_year(1700).is_leap());
}

TEST_CASE("solar_year_test_4") {
    REQUIRE(365 == SolarYear::from_year(2023).get_day_count());
}

TEST_CASE("solar_year_test_5") {
    REQUIRE("2028年" == SolarYear::from_year(2023).next(5).get_name());
}

TEST_CASE("solar_year_test_6") {
    REQUIRE("2018年" == SolarYear::from_year(2023).next(-5).get_name());
}

TEST_CASE("week_test_0") {
    REQUIRE("一" == SolarDay::from_ymd(1582, 10, 1).get_week().get_name());
}

TEST_CASE("week_test_1") {
    REQUIRE("五" == SolarDay::from_ymd(1582, 10, 15).get_week().get_name());
}

TEST_CASE("week_test_2") {
    REQUIRE(2 == SolarDay::from_ymd(2023, 10, 31).get_week().get_index());
}

TEST_CASE("week_test_3") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 0, 0);
    REQUIRE("第一周" == w.get_name());
    REQUIRE("2023年10月第一周" == w.to_string());
}

TEST_CASE("week_test_5") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 4, 0);
    REQUIRE("第五周" == w.get_name());
    REQUIRE("2023年10月第五周" == w.to_string());
}

TEST_CASE("week_test_6") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 5, 1);
    REQUIRE("第六周" == w.get_name());
    REQUIRE("2023年10月第六周" == w.to_string());
}

TEST_CASE("week_test_7") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 0, 0).next(4);
    REQUIRE("第五周" == w.get_name());
    REQUIRE("2023年10月第五周" == w.to_string());
}

TEST_CASE("week_test_8") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 0, 0).next(5);
    REQUIRE("第二周" == w.get_name());
    REQUIRE("2023年11月第二周" == w.to_string());
}

TEST_CASE("week_test_9") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 0, 0).next(-1);
    REQUIRE("第五周" == w.get_name());
    REQUIRE("2023年9月第五周" == w.to_string());
}

TEST_CASE("week_test_10") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 0, 0).next(-5);
    REQUIRE("第一周" == w.get_name());
    REQUIRE("2023年9月第一周" == w.to_string());
}

TEST_CASE("week_test_11") {
    SolarWeek w = SolarWeek::from_ym(2023, 10, 0, 0).next(-6);
    REQUIRE("第四周" == w.get_name());
    REQUIRE("2023年8月第四周" == w.to_string());
}

TEST_CASE("week_test_12") {
    REQUIRE(1 == SolarDay::from_ymd(1582, 10, 1).get_week().get_index());
}

TEST_CASE("week_test_13") {
    REQUIRE(5 == SolarDay::from_ymd(1582, 10, 15).get_week().get_index());
}

TEST_CASE("week_test_14") {
    REQUIRE(0 == SolarDay::from_ymd(1129, 11, 17).get_week().get_index());
}

TEST_CASE("week_test_15") {
    REQUIRE(5 == SolarDay::from_ymd(1129, 11, 1).get_week().get_index());
}

TEST_CASE("week_test_16") {
    REQUIRE(4 == SolarDay::from_ymd(8, 11, 1).get_week().get_index());
}

TEST_CASE("week_test_17") {
    REQUIRE(0 == SolarDay::from_ymd(1582, 9, 30).get_week().get_index());
}

TEST_CASE("week_test_18") {
    REQUIRE(1 == SolarDay::from_ymd(1582, 1, 1).get_week().get_index());
}

TEST_CASE("week_test_19") {
    REQUIRE(6 == SolarDay::from_ymd(1500, 2, 29).get_week().get_index());
}

TEST_CASE("week_test_20") {
    REQUIRE(3 == SolarDay::from_ymd(9865, 7, 26).get_week().get_index());
}

TEST_CASE("week_test_21") {
    const LunarWeek week = LunarWeek::from_ym(2023, 1, 0, 2);
    REQUIRE("农历癸卯年正月第一周" == week.to_string());
    REQUIRE("农历壬寅年十二月廿六" == week.get_first_day().to_string());
}

TEST_CASE("week_test_22") {
    const SolarWeek week = SolarWeek::from_ym(2023, 1, 0, 2);
    REQUIRE("2023年1月第一周" == week.to_string());
    REQUIRE("2022年12月27日" == week.get_first_day().to_string());
}

TEST_CASE("week_test_24") {
    const int start = 0;
    SolarWeek week = SolarWeek::from_ym(2024, 2, 2, start);
    REQUIRE("2024年2月第三周" == week.to_string());
    REQUIRE(6 == week.get_index_in_year());

    week = SolarDay::from_ymd(2024, 2, 11).get_solar_week(start);
    REQUIRE("2024年2月第三周" == week.to_string());

    week = SolarDay::from_ymd(2024, 2, 17).get_solar_week(start);
    REQUIRE("2024年2月第三周" == week.to_string());

    week = SolarDay::from_ymd(2024, 2, 10).get_solar_week(start);
    REQUIRE("2024年2月第二周" == week.to_string());

    week = SolarDay::from_ymd(2024, 2, 18).get_solar_week(start);
    REQUIRE("2024年2月第四周" == week.to_string());
}

TEST_CASE("week_test_25") {
    const LunarWeek week = LunarWeek::from_ym(2024, 6, 0, 0);
    REQUIRE("农历甲辰年六月第一周" == week.to_string());
    REQUIRE("农历甲辰年六月第三周" == week.next(2).to_string());
    REQUIRE("农历甲辰年七月第一周" == week.next(5).to_string());
    REQUIRE("农历甲辰年五月第四周" == week.next(-1).to_string());
    REQUIRE("农历甲辰年五月第一周" == week.next(-4).to_string());
}

TEST_CASE("week_test_26") {
    const SolarWeek week = SolarDay::from_ymd(2025, 3, 6).get_solar_week(0);
    REQUIRE("2025年3月第二周" == week.to_string());
    REQUIRE("2025年3月2日" == week.get_first_day().to_string());
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

TEST_CASE("rab_byung_year_test_2") {
    REQUIRE("第十七饶迥铁虎年" == RabByungYear::from_year(2010).get_name());
}

TEST_CASE("rab_byung_year_test_3") {
    REQUIRE(5 == RabByungYear::from_year(2043).get_leap_month());
    REQUIRE(0 == RabByungYear::from_year(2044).get_leap_month());
}

TEST_CASE("rab_byung_year_test_4") {
    REQUIRE("第十六饶迥铁牛年" == RabByungYear::from_year(1961).get_name());
}

TEST_CASE("rab_byung_year_test_5") {
    REQUIRE(1961 == RabByungYear::from_element_zodiac(15, RabByungElement::from_name("铁"), Zodiac::from_name("牛")).get_year());
}

TEST_CASE("rab_byung_month_test_0") {
    REQUIRE("第十六饶迥铁虎年十二月" == RabByungMonth::from_ym(1950, 12).to_string());
}

TEST_CASE("rab_byung_day_test_0") {
    REQUIRE("第十六饶迥铁虎年十二月初一" == SolarDay::from_ymd(1951, 1, 8).get_rab_byung_day().to_string());
    const RabByungYear y = RabByungYear::from_element_zodiac(15, RabByungElement::from_name("铁"), Zodiac::from_name("虎"));
    REQUIRE("1951年1月8日" == RabByungDay::from_ymd(y.get_year(), 12, 1).get_solar_day().to_string());
}

TEST_CASE("rab_byung_day_test_1") {
    REQUIRE("第十八饶迥铁马年十二月三十" == SolarDay::from_ymd(2051, 2, 11).get_rab_byung_day().to_string());
    const RabByungYear y = RabByungYear::from_element_zodiac(17, RabByungElement::from_name("铁"), Zodiac::from_name("马"));
    REQUIRE(2050 == y.get_year());
    const RabByungDay d = RabByungDay::from_ymd(y.get_year(), 12, 30);
    REQUIRE("第十八饶迥铁马年十二月三十" == d.to_string());
    REQUIRE("2051年2月11日" == d.get_solar_day().to_string());
}

TEST_CASE("rab_byung_day_test_2") {
    REQUIRE("第十七饶迥木蛇年二月廿五" == SolarDay::from_ymd(2025, 4, 23).get_rab_byung_day().to_string());
    const RabByungYear y = RabByungYear::from_element_zodiac(16, RabByungElement::from_name("木"), Zodiac::from_name("蛇"));
    REQUIRE(2025 == y.get_year());
    REQUIRE("2025年4月23日" == RabByungDay::from_ymd(y.get_year(), 2, 25).get_solar_day().to_string());
}

TEST_CASE("rab_byung_day_test_3") {
    REQUIRE("第十六饶迥铁兔年正月初二" == SolarDay::from_ymd(1951, 2, 8).get_rab_byung_day().to_string());
    const RabByungYear y = RabByungYear::from_element_zodiac(15, RabByungElement::from_name("铁"), Zodiac::from_name("兔"));
    REQUIRE("1951年2月8日" == RabByungDay::from_ymd(y.get_year(), 1, 2).get_solar_day().to_string());
}

TEST_CASE("rab_byung_day_test_4") {
    REQUIRE("第十六饶迥铁虎年十二月闰十六" == SolarDay::from_ymd(1951, 1, 24).get_rab_byung_day().to_string());
    const RabByungYear y = RabByungYear::from_element_zodiac(15, RabByungElement::from_name("铁"), Zodiac::from_name("虎"));
    REQUIRE("1951年1月24日" == RabByungDay::from_ymd(y.get_year(), 12, -16).get_solar_day().to_string());
}

TEST_CASE("rab_byung_day_test_5") {
    REQUIRE("第十六饶迥铁牛年五月十一" == SolarDay::from_ymd(1961, 6, 24).get_rab_byung_day().to_string());
    const RabByungYear y = RabByungYear::from_element_zodiac(15, RabByungElement::from_name("铁"), Zodiac::from_name("牛"));
    REQUIRE(1961 == y.get_year());
    REQUIRE("1961年6月24日" == RabByungDay::from_ymd(y.get_year(), 5, 11).get_solar_day().to_string());
}

TEST_CASE("rab_byung_day_test_6") {
    REQUIRE("第十六饶迥铁兔年十二月廿八" == SolarDay::from_ymd(1952, 2, 23).get_rab_byung_day().to_string());
    const RabByungYear y = RabByungYear::from_element_zodiac(15, RabByungElement::from_name("铁"), Zodiac::from_name("兔"));
    REQUIRE(1951 == y.get_year());
    REQUIRE("1952年2月23日" == RabByungDay::from_ymd(y.get_year(), 12, 28).get_solar_day().to_string());
}

TEST_CASE("rab_byung_day_test_7") {
    REQUIRE("第十七饶迥木蛇年二月廿九" == SolarDay::from_ymd(2025, 4, 26).get_rab_byung_day().to_string());
}

TEST_CASE("rab_byung_day_test_8") {
    REQUIRE("第十七饶迥木蛇年二月廿七" == SolarDay::from_ymd(2025, 4, 25).get_rab_byung_day().to_string());
}

TEST_CASE("rab_byung_element_test_0") {
    REQUIRE("西" == RabByungElement::from_name("铁").get_direction().to_string());
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

TEST_CASE("solar_festival_test_7") {
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
    REQUIRE("劳动节" == festival.value().get_name());

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

TEST_CASE("phase_test_0") {
    const Phase phase = Phase::from_name(2025, 7, "下弦月");
    REQUIRE("2025年9月14日 18:32:57" == phase.get_solar_time().to_string());
}

TEST_CASE("phase_test_1") {
    const Phase phase = Phase::from_index(2025, 7, 6);
    REQUIRE("2025年9月14日 18:32:57" == phase.get_solar_time().to_string());
}

TEST_CASE("phase_test_2") {
    const Phase phase = Phase::from_index(2025, 7, 8);
    REQUIRE("2025年9月22日 03:54:07" == phase.get_solar_time().to_string());
}

TEST_CASE("phase_test_3") {
    const Phase phase = SolarDay::from_ymd(2025, 9, 21).get_phase();
    REQUIRE("残月" == phase.to_string());
}

TEST_CASE("phase_test_4") {
    const Phase phase = LunarDay::from_ymd(2025, 7, 30).get_phase();
    REQUIRE("残月" == phase.to_string());
}

TEST_CASE("phase_test_5") {
    const Phase phase = SolarTime::from_ymd_hms(2025, 9, 22, 4, 0, 0).get_phase();
    REQUIRE("蛾眉月" == phase.to_string());
}

TEST_CASE("phase_test_6") {
    const Phase phase = SolarTime::from_ymd_hms(2025, 9, 22, 3, 0, 0).get_phase();
    REQUIRE("残月" == phase.to_string());
}

TEST_CASE("phase_test_7") {
    const PhaseDay d = SolarDay::from_ymd(2023, 9, 15).get_phase_day();
    REQUIRE("新月第1天" == d.to_string());
}

TEST_CASE("phase_test_8") {
    const PhaseDay d = SolarDay::from_ymd(2023, 9, 17).get_phase_day();
    REQUIRE("蛾眉月第2天" == d.to_string());
}

TEST_CASE("phase_test_9") {
    const Phase phase = SolarTime::from_ymd_hms(2025, 9, 22, 3, 54, 7).get_phase();
    REQUIRE("新月" == phase.to_string());
}

TEST_CASE("phase_test_10") {
    const Phase phase = SolarTime::from_ymd_hms(2025, 9, 22, 3, 54, 6).get_phase();
    REQUIRE("残月" == phase.to_string());
}

TEST_CASE("phase_test_11") {
    const Phase phase = SolarTime::from_ymd_hms(2025, 9, 22, 3, 54, 8).get_phase();
    REQUIRE("蛾眉月" == phase.to_string());
}

TEST_CASE("phase_test_12") {
    const Phase phase = LunarDay::from_ymd(2025, -6, 20).get_phase();
    REQUIRE("亏凸月" == phase.to_string());
}

TEST_CASE("phase_test_13") {
    const Phase phase = SolarDay::from_ymd(2025, 8, 13).get_phase();
    REQUIRE("亏凸月" == phase.to_string());
}

TEST_CASE("three_pillars_test_1") {
    REQUIRE("甲戌 甲戌 甲戌" == SolarDay::from_ymd(1034, 10, 2).get_sixty_cycle_day().get_three_pillars().get_name());
}

void init_events() {
    // 公历现代节日
    //EventManager::DATA = "@0VV__0Ux公历现代节日:元旦@0Xc__0Ux公历现代节日:妇女节@0Xg__0_Q公历现代节日:植树节@0ZV__0Ux公历现代节日:劳动节@0ZY__0Ux公历现代节日:青年节@0aV__0Ux公历现代节日:儿童节@0bV__0Uo公历现代节日:建党节@0cV__0Ug公历现代节日:建军节@0de__0_V公历现代节日:教师节@0eV__0Ux公历现代节日:国庆节";
    EventManager::update("公历现代节日:元旦", Event::builder().solar_day(1, 1, 0).start_year(1950).build());
    EventManager::update("公历现代节日:妇女节", Event::builder().solar_day(3, 8, 0).start_year(1950).build());
    EventManager::update("公历现代节日:植树节", Event::builder().solar_day(3, 12, 0).start_year(1979).build());
    EventManager::update("公历现代节日:劳动节", Event::builder().solar_day(5, 1, 0).start_year(1950).build());
    EventManager::update("公历现代节日:青年节", Event::builder().solar_day(5, 4, 0).start_year(1950).build());
    EventManager::update("公历现代节日:儿童节", Event::builder().solar_day(6, 1, 0).start_year(1950).build());
    EventManager::update("公历现代节日:建党节", Event::builder().solar_day(7, 1, 0).start_year(1941).build());
    EventManager::update("公历现代节日:建军节", Event::builder().solar_day(8, 1, 0).start_year(1933).build());
    EventManager::update("公历现代节日:教师节", Event::builder().solar_day(9, 10, 0).start_year(1985).build());
    EventManager::update("公历现代节日:国庆节", Event::builder().solar_day(10, 1, 0).start_year(1950).build());

    // 农历传统节日
    // EventManager::DATA = "@2VV__000农历传统节日:春节@2Vj__000农历传统节日:元宵节@2WW__000农历传统节日:龙头节@2XX__000农历传统节日:上巳节@3b___000农历传统节日:清明节@2ZZ__000农历传统节日:端午节@2bb__000农历传统节日:七夕节@2bj__000农历传统节日:中元节@2cj__000农历传统节日:中秋节@2dd__000农历传统节日:重阳节@3s___000农历传统节日:冬至节@2gc__000农历传统节日:腊八节@2hV_U000农历传统节日:除夕";
    EventManager::update("农历传统节日:春节", Event::builder().lunar_day(1, 1, 0).build());
    EventManager::update("农历传统节日:元宵节", Event::builder().lunar_day(1, 15, 0).build());
    EventManager::update("农历传统节日:龙头节", Event::builder().lunar_day(2, 2, 0).build());
    EventManager::update("农历传统节日:上巳节", Event::builder().lunar_day(3, 3, 0).build());
    EventManager::update("农历传统节日:清明节", Event::builder().term_day(7, 0).build());
    EventManager::update("农历传统节日:端午节", Event::builder().lunar_day(5, 5, 0).build());
    EventManager::update("农历传统节日:七夕节", Event::builder().lunar_day(7, 7, 0).build());
    EventManager::update("农历传统节日:中元节", Event::builder().lunar_day(7, 15, 0).build());
    EventManager::update("农历传统节日:中秋节", Event::builder().lunar_day(8, 15, 0).build());
    EventManager::update("农历传统节日:重阳节", Event::builder().lunar_day(9, 9, 0).build());
    EventManager::update("农历传统节日:冬至节", Event::builder().term_day(24, 0).build());
    EventManager::update("农历传统节日:腊八节", Event::builder().lunar_day(12, 8, 0).build());
    EventManager::update("农历传统节日:除夕", Event::builder().lunar_day(13, 1, 0).offset(-1).build());

    EventManager::update("情人节", Event::builder().solar_day(2, 14, 0).start_year(270).build());
    EventManager::update("国际消费者权益日", Event::builder().solar_day(3, 15, 0).start_year(1983).build());
    EventManager::update("愚人节", Event::builder().solar_day(4, 1, 0).start_year(1564).build());
    EventManager::update("万圣夜", Event::builder().solar_day(10, 31, 0).start_year(600).build());
    EventManager::update("万圣节", Event::builder().solar_day(11, 1, 0).start_year(600).build());
    EventManager::update("平安夜", Event::builder().solar_day(12, 24, 0).start_year(336).build());
    EventManager::update("圣诞节", Event::builder().solar_day(12, 25, 0).start_year(336).build());

    EventManager::update("全国中小学生安全教育日", Event::builder().solar_week(3, -1, 1).start_year(1996).build());
    EventManager::update("母亲节", Event::builder().solar_week(5, 2, 0).start_year(1914).build());
    EventManager::update("父亲节", Event::builder().solar_week(6, 3, 0).start_year(1972).build());
    EventManager::update("感恩节", Event::builder().solar_week(11, 4, 4).start_year(1941).build());

    // 清明前1天
    EventManager::update("寒食节", Event::builder().term_day(7, -1).build());
    // 立春后第5个戊日
    EventManager::update("春社", Event::builder().term_heaven_stem(3, 4, 30).offset(10).build());
    // 立秋后第5个戊日
    EventManager::update("秋社", Event::builder().term_heaven_stem(15, 4, 30).offset(10).build());

    // 夏至后第3个庚日
    EventManager::update("入伏", Event::builder().term_heaven_stem(12, 6, 20).build());
    // 夏至后第4个庚日
    EventManager::update("中伏", Event::builder().term_heaven_stem(12, 6, 30).build());
    // 立秋后第1个庚日
    EventManager::update("末伏", Event::builder().term_heaven_stem(15, 6, 0).build());

    // 芒种后第1个丙日
    EventManager::update("入梅", Event::builder().term_heaven_stem(11, 2, 0).build());
    // 小暑后第1个未日
    EventManager::update("出梅", Event::builder().term_earth_branch(13, 7, 0).build());

    // 如果没有2月29，则倒推1天
    EventManager::update("公历生日", Event::builder().solar_day(2, 29, -1).start_year(2004).build());

    EventManager::update("农历生日", Event::builder().lunar_day(4, 21, 0).start_year(1986).build());
}

TEST_CASE("event_test_1") {
    init_events();

    optional<Event> e = Event::from_name("公历生日");
    REQUIRE(e);

    optional<SolarDay> d = e.value().get_solar_day(2008);
    REQUIRE(e);
    REQUIRE("2008年2月29日" == d.value().to_string());

    // 2005年没有2月29，按最初设置的，没有就倒推1天
    d = e.value().get_solar_day(2005);
    REQUIRE(e);
    REQUIRE("2005年2月28日" == d.value().to_string());

    e = Event::from_name("农历生日");
    REQUIRE(e);

    d = e.value().get_solar_day(2026);
    REQUIRE(e);
    REQUIRE("2026年6月6日" == d.value().to_string());
}

TEST_CASE("event_test_2") {
    init_events();

    optional<Event> e = Event::from_name("国际消费者权益日");
    REQUIRE(e);

    optional<SolarDay> d = e.value().get_solar_day(2026);
    REQUIRE(e);
    REQUIRE("2026年3月15日" == d.value().to_string());
}

TEST_CASE("heavenly_stem_test_0") {
    REQUIRE("甲" == HeavenStem::from_index(0).get_name());
}

TEST_CASE("heavenly_stem_test_1") {
    REQUIRE(0 == HeavenStem::from_name("甲").get_index());
}

TEST_CASE("heavenly_stem_test_2") {
    REQUIRE(HeavenStem::from_name("丙").get_element().equals(HeavenStem::from_name("甲").get_element().get_reinforce()));
}

TEST_CASE("heavenly_stem_test_3") {
    vector<string> stems = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"};
    map<string, string> shi_shen = {
        {"甲甲", "比肩"}, {"甲乙", "劫财"}, {"甲丙", "食神"}, {"甲丁", "伤官"}, {"甲戊", "偏财"}, {"甲己", "正财"}, {"甲庚", "七杀"}, {"甲辛", "正官"}, {"甲壬", "偏印"}, {"甲癸", "正印"},
        {"乙乙", "比肩"}, {"乙甲", "劫财"}, {"乙丁", "食神"}, {"乙丙", "伤官"}, {"乙己", "偏财"}, {"乙戊", "正财"}, {"乙辛", "七杀"}, {"乙庚", "正官"}, {"乙癸", "偏印"}, {"乙壬", "正印"},
        {"丙丙", "比肩"}, {"丙丁", "劫财"}, {"丙戊", "食神"}, {"丙己", "伤官"}, {"丙庚", "偏财"}, {"丙辛", "正财"}, {"丙壬", "七杀"}, {"丙癸", "正官"}, {"丙甲", "偏印"}, {"丙乙", "正印"},
        {"丁丁", "比肩"}, {"丁丙", "劫财"}, {"丁己", "食神"}, {"丁戊", "伤官"}, {"丁辛", "偏财"}, {"丁庚", "正财"}, {"丁癸", "七杀"}, {"丁壬", "正官"}, {"丁乙", "偏印"}, {"丁甲", "正印"},
        {"戊戊", "比肩"}, {"戊己", "劫财"}, {"戊庚", "食神"}, {"戊辛", "伤官"}, {"戊壬", "偏财"}, {"戊癸", "正财"}, {"戊甲", "七杀"}, {"戊乙", "正官"}, {"戊丙", "偏印"}, {"戊丁", "正印"},
        {"己己", "比肩"}, {"己戊", "劫财"}, {"己辛", "食神"}, {"己庚", "伤官"}, {"己癸", "偏财"}, {"己壬", "正财"}, {"己乙", "七杀"}, {"己甲", "正官"}, {"己丁", "偏印"}, {"己丙", "正印"},
        {"庚庚", "比肩"}, {"庚辛", "劫财"}, {"庚壬", "食神"}, {"庚癸", "伤官"}, {"庚甲", "偏财"}, {"庚乙", "正财"}, {"庚丙", "七杀"}, {"庚丁", "正官"}, {"庚戊", "偏印"}, {"庚己", "正印"},
        {"辛辛", "比肩"}, {"辛庚", "劫财"}, {"辛癸", "食神"}, {"辛壬", "伤官"}, {"辛乙", "偏财"}, {"辛甲", "正财"}, {"辛丁", "七杀"}, {"辛丙", "正官"}, {"辛己", "偏印"}, {"辛戊", "正印"},
        {"壬壬", "比肩"}, {"壬癸", "劫财"}, {"壬甲", "食神"}, {"壬乙", "伤官"}, {"壬丙", "偏财"}, {"壬丁", "正财"}, {"壬戊", "七杀"}, {"壬己", "正官"}, {"壬庚", "偏印"}, {"壬辛", "正印"},
        {"癸癸", "比肩"}, {"癸壬", "劫财"}, {"癸乙", "食神"}, {"癸甲", "伤官"}, {"癸丁", "偏财"}, {"癸丙", "正财"}, {"癸己", "七杀"}, {"癸戊", "正官"}, {"癸辛", "偏印"}, {"癸庚", "正印"}
    };
    for (const auto &entry : shi_shen) {
        string gz = entry.first;
        REQUIRE(entry.second == HeavenStem::from_name(gz.substr(0, 3)).get_ten_star(HeavenStem::from_name(gz.substr(3, 3))).get_name());
    }
}

TEST_CASE("heavenly_stem_test_4") {
    REQUIRE("乙" == HeavenStem::from_name("庚").get_combine().get_name());
    REQUIRE("庚" == HeavenStem::from_name("乙").get_combine().get_name());
    REQUIRE("土" == HeavenStem::from_name("甲").combine(HeavenStem::from_name("己")).value().get_name());
    REQUIRE("土" == HeavenStem::from_name("己").combine(HeavenStem::from_name("甲")).value().get_name());
    REQUIRE("木" == HeavenStem::from_name("丁").combine(HeavenStem::from_name("壬")).value().get_name());
    REQUIRE("木" == HeavenStem::from_name("壬").combine(HeavenStem::from_name("丁")).value().get_name());
    REQUIRE(nullopt == HeavenStem::from_name("甲").combine(HeavenStem::from_name("乙")));
}

TEST_CASE("hide_heaven_stem_day_test_0") {
    HideHeavenStemDay d = SolarDay::from_ymd(2024, 12, 4).get_hide_heaven_stem_day();
    REQUIRE(HideHeavenStemType::MAIN == d.get_hide_heaven_stem().get_type());
    REQUIRE("壬" == d.get_hide_heaven_stem().get_heaven_stem().get_name());
    REQUIRE("壬" == d.get_hide_heaven_stem().get_name());
    REQUIRE("水" == d.get_hide_heaven_stem().get_heaven_stem().get_element().get_name());
    REQUIRE("壬水" == d.get_name());
    REQUIRE(15 == d.get_day_index());
    REQUIRE("壬水第16天" == d.to_string());
}

TEST_CASE("hide_heaven_stem_day_test_1") {
    HideHeavenStemDay d = SolarDay::from_ymd(2024, 11, 7).get_hide_heaven_stem_day();
    REQUIRE(HideHeavenStemType::RESIDUAL == d.get_hide_heaven_stem().get_type());
    REQUIRE("戊" == d.get_hide_heaven_stem().get_heaven_stem().get_name());
    REQUIRE("戊" == d.get_hide_heaven_stem().get_name());
    REQUIRE("土" == d.get_hide_heaven_stem().get_heaven_stem().get_element().get_name());
    REQUIRE("戊土" == d.get_name());
    REQUIRE(0 == d.get_day_index());
    REQUIRE("戊土第1天" == d.to_string());
}

TEST_CASE("god_test_0") {
    vector<God> gods = SolarDay::from_ymd(2004, 2, 16).get_sixty_cycle_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"天恩", "续世", "明堂"} == ji);
    REQUIRE(vector<string>{"月煞", "月虚", "血支", "天贼", "五虚", "土符", "归忌", "血忌"} == xiong);
}

TEST_CASE("god_test_1") {
    vector<God> gods = SolarDay::from_ymd(2029, 11, 16).get_sixty_cycle_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"天德合", "月空", "天恩", "益后", "金匮"} == ji);
    REQUIRE(vector<string>{"月煞", "月虚", "血支", "五虚"} == xiong);
}

TEST_CASE("god_test_2") {
    vector<God> gods = SolarDay::from_ymd(1954, 7, 16).get_sixty_cycle_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"民日", "天巫", "福德", "天仓", "不将", "续世", "除神", "鸣吠"} == ji);
    REQUIRE(vector<string>{"劫煞", "天贼", "五虚", "五离"} == xiong);
}

TEST_CASE("god_test_3") {
    vector<God> gods = SolarDay::from_ymd(2024, 12, 27).get_sixty_cycle_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"天恩", "四相", "阴德", "守日", "吉期", "六合", "普护", "宝光"} == ji);
    REQUIRE(vector<string>{"三丧", "鬼哭"} == xiong);
}

TEST_CASE("god_test_4") {
    vector<God> gods = SolarDay::from_ymd(2024, 9, 27).get_sixty_cycle_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"月空", "不将", "福生", "金匮", "鸣吠"} == ji);
    REQUIRE(vector<string>{"天罡", "大时", "大败", "咸池", "天贼", "九坎", "九焦"} == xiong);
}

TEST_CASE("god_test_5") {
    vector<God> gods = SolarDay::from_ymd(2004, 2, 16).get_lunar_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"天恩", "续世", "明堂"} == ji);
    REQUIRE(vector<string>{"月煞", "月虚", "血支", "天贼", "五虚", "土符", "归忌", "血忌"} == xiong);
}

TEST_CASE("god_test_6") {
    vector<God> gods = SolarDay::from_ymd(2029, 11, 16).get_lunar_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"天德合", "月空", "天恩", "益后", "金匮"} == ji);
    REQUIRE(vector<string>{"月煞", "月虚", "血支", "五虚"} == xiong);
}

TEST_CASE("god_test_7") {
    vector<God> gods = SolarDay::from_ymd(1954, 7, 16).get_lunar_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"民日", "天巫", "福德", "天仓", "不将", "续世", "除神", "鸣吠"} == ji);
    REQUIRE(vector<string>{"劫煞", "天贼", "五虚", "五离"} == xiong);
}

TEST_CASE("god_test_8") {
    vector<God> gods = SolarDay::from_ymd(2024, 12, 27).get_lunar_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"天恩", "四相", "阴德", "守日", "吉期", "六合", "普护", "宝光"} == ji);
    REQUIRE(vector<string>{"三丧", "鬼哭"} == xiong);
}

TEST_CASE("god_test_9") {
    vector<God> gods = SolarDay::from_ymd(2024, 9, 27).get_lunar_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"月空", "不将", "福生", "金匮", "鸣吠"} == ji);
    REQUIRE(vector<string>{"天罡", "大时", "大败", "咸池", "天贼", "九坎", "九焦"} == xiong);
}

TEST_CASE("god_test_10") {
    vector<God> gods = SolarDay::from_ymd(2025, 12, 15).get_lunar_day().get_gods();
    vector<string> ji;
    vector<string> xiong;
    for (const God &god : gods) {
        if ("吉" == god.get_luck().get_name()) {
            ji.push_back(god.get_name());
        }
        if ("凶" == god.get_luck().get_name()) {
            xiong.push_back(god.get_name());
        }
    }
    REQUIRE(vector<string>{"阳德", "六仪", "续世", "解神", "司命"} == ji);
    REQUIRE(vector<string>{"月破", "大耗", "灾煞", "天火", "厌对", "招摇", "五虚", "血忌"} == xiong);
}

TEST_CASE("taboo_test_0") {
    vector<Taboo> taboos = SolarDay::from_ymd(2024, 6, 26).get_sixty_cycle_day().get_recommends();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"嫁娶", "祭祀", "理发", "作灶", "修饰垣墙", "平治道涂", "整手足甲", "沐浴", "冠笄"} == names);
}

TEST_CASE("taboo_test_1") {
    vector<Taboo> taboos = SolarDay::from_ymd(2024, 6, 26).get_sixty_cycle_day().get_avoids();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"破土", "出行", "栽种"} == names);
}

TEST_CASE("taboo_test_2") {
    vector<Taboo> taboos = SolarTime::from_ymd_hms(2024, 6, 25, 4, 0, 0).get_sixty_cycle_hour().get_recommends();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(names.empty());
}

TEST_CASE("taboo_test_3") {
    vector<Taboo> taboos = SolarTime::from_ymd_hms(2024, 6, 25, 4, 0, 0).get_sixty_cycle_hour().get_avoids();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"诸事不宜"} == names);
}

TEST_CASE("taboo_test_4") {
    vector<Taboo> taboos = SolarTime::from_ymd_hms(2024, 4, 22, 0, 0, 0).get_sixty_cycle_hour().get_recommends();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"嫁娶", "交易", "开市", "安床", "祭祀", "求财"} == names);
}

TEST_CASE("taboo_test_5") {
    vector<Taboo> taboos = SolarTime::from_ymd_hms(2024, 4, 22, 0, 0, 0).get_sixty_cycle_hour().get_avoids();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"出行", "移徙", "赴任", "词讼", "祈福", "修造", "求嗣"} == names);
}

TEST_CASE("taboo_test_6") {
    vector<Taboo> taboos = SolarDay::from_ymd(2021, 3, 7).get_sixty_cycle_day().get_recommends();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"裁衣", "经络", "伐木", "开柱眼", "拆卸", "修造", "动土", "上梁", "合脊", "合寿木", "入殓", "除服", "成服", "移柩", "破土", "安葬", "启钻", "修坟", "立碑"} == names);
}

TEST_CASE("taboo_test_7") {
    vector<Taboo> taboos = SolarDay::from_ymd(2024, 6, 26).get_lunar_day().get_recommends();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"嫁娶", "祭祀", "理发", "作灶", "修饰垣墙", "平治道涂", "整手足甲", "沐浴", "冠笄"} == names);
}

TEST_CASE("taboo_test_8") {
    vector<Taboo> taboos = SolarDay::from_ymd(2024, 6, 26).get_lunar_day().get_avoids();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"破土", "出行", "栽种"} == names);
}

TEST_CASE("taboo_test_9") {
    vector<Taboo> taboos = SolarTime::from_ymd_hms(2024, 6, 25, 4, 0, 0).get_lunar_hour().get_recommends();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(names.empty());
}

TEST_CASE("taboo_test_10") {
    vector<Taboo> taboos = SolarTime::from_ymd_hms(2024, 6, 25, 4, 0, 0).get_lunar_hour().get_avoids();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"诸事不宜"} == names);
}

TEST_CASE("taboo_test_11") {
    vector<Taboo> taboos = SolarTime::from_ymd_hms(2024, 4, 22, 0, 0, 0).get_lunar_hour().get_recommends();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"嫁娶", "交易", "开市", "安床", "祭祀", "求财"} == names);
}

TEST_CASE("taboo_test_12") {
    vector<Taboo> taboos = SolarTime::from_ymd_hms(2024, 4, 22, 0, 0, 0).get_lunar_hour().get_avoids();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"出行", "移徙", "赴任", "词讼", "祈福", "修造", "求嗣"} == names);
}

TEST_CASE("taboo_test_13") {
    vector<Taboo> taboos = SolarDay::from_ymd(2021, 3, 7).get_lunar_day().get_recommends();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(vector<string>{"裁衣", "经络", "伐木", "开柱眼", "拆卸", "修造", "动土", "上梁", "合脊", "合寿木", "入殓", "除服", "成服", "移柩", "破土", "安葬", "启钻", "修坟", "立碑"} == names);
}

TEST_CASE("taboo_test_14") {
    vector<Taboo> taboos = SolarDay::from_ymd(2026, 1, 6).get_lunar_day().get_avoids();
    vector<string> names;
    for (const Taboo &t : taboos) {
        names.push_back(t.get_name());
    }
    REQUIRE(names.empty());
}

TEST_CASE("three_pillars_test_0") {
    vector<SolarDay> solarDays = ThreePillars("甲戌", "甲戌", "甲戌").get_solar_days(1, 2200);
    vector<string> actual;
    for (const SolarDay &solarDay : solarDays) {
        actual.push_back(solarDay.to_string());
    }
    vector<string> expected = {
        "14年10月17日", "194年11月1日", "254年10月17日", "434年11月1日",
        "494年10月17日", "674年11月1日", "734年10月17日", "794年10月2日",
        "974年10月17日", "1034年10月2日", "1214年10月17日", "1274年10月2日",
        "1454年10月17日", "1514年10月2日", "1694年10月27日", "1754年10月13日",
        "1934年10月30日", "1994年10月15日", "2174年10月31日"
    };
    REQUIRE(expected == actual);
}

TEST_CASE("eight_char_test_21") {
    ChildLimit childLimit = ChildLimit::from_solar_time(SolarTime::from_ymd_hms(2022, 3, 9, 20, 51, 0), Gender::MAN);
    REQUIRE(8 == childLimit.get_year_count());
    REQUIRE(9 == childLimit.get_month_count());
    REQUIRE(2 == childLimit.get_day_count());
    REQUIRE(10 == childLimit.get_hour_count());
    REQUIRE(28 == childLimit.get_minute_count());
    REQUIRE("2030年12月12日 07:19:00" == childLimit.get_end_time().to_string());
}

TEST_CASE("eight_char_test_22") {
    ChildLimit childLimit = ChildLimit::from_solar_time(SolarTime::from_ymd_hms(2018, 6, 11, 9, 30, 0), Gender::WOMAN);
    REQUIRE(1 == childLimit.get_year_count());
    REQUIRE(9 == childLimit.get_month_count());
    REQUIRE(10 == childLimit.get_day_count());
    REQUIRE(1 == childLimit.get_hour_count());
    REQUIRE(42 == childLimit.get_minute_count());
    REQUIRE("2020年3月21日 11:12:00" == childLimit.get_end_time().to_string());
}

TEST_CASE("eight_char_test_23") {
    ChildLimit childLimit = ChildLimit::from_solar_time(SolarTime::from_ymd_hms(1983, 2, 15, 20, 0, 0), Gender::WOMAN);
    REQUIRE("癸亥 甲寅 甲戌 甲戌" == childLimit.get_eight_char().to_string());
    REQUIRE(6 == childLimit.get_year_count());
    REQUIRE(2 == childLimit.get_month_count());
    REQUIRE(18 == childLimit.get_day_count());
    REQUIRE("1989年5月4日 18:24:00" == childLimit.get_end_time().to_string());
    REQUIRE("癸亥" == childLimit.get_start_time().get_lunar_hour().get_lunar_day().get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());
    REQUIRE("己巳" == childLimit.get_end_time().get_lunar_hour().get_lunar_day().get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());

    DecadeFortune decadeFortune = childLimit.get_start_decade_fortune();
    REQUIRE(7 == decadeFortune.get_start_age());
    REQUIRE(16 == decadeFortune.get_end_age());
    REQUIRE(1989 == decadeFortune.get_start_sixty_cycle_year().get_year());
    REQUIRE(1998 == decadeFortune.get_end_sixty_cycle_year().get_year());
    REQUIRE("乙卯" == decadeFortune.get_name());
    REQUIRE("丙辰" == decadeFortune.next(1).get_name());
    REQUIRE("甲寅" == decadeFortune.next(-1).get_name());
    REQUIRE("癸亥" == decadeFortune.next(8).get_name());

    Fortune fortune = childLimit.get_start_fortune();
    REQUIRE(7 == fortune.get_age());
    REQUIRE(1989 == fortune.get_sixty_cycle_year().get_year());
    REQUIRE("辛巳" == fortune.get_name());
    REQUIRE("己巳" == fortune.get_sixty_cycle_year().get_sixty_cycle().get_name());
}

TEST_CASE("eight_char_test_24") {
    ChildLimit childLimit = ChildLimit::from_solar_time(SolarTime::from_ymd_hms(1992, 2, 2, 12, 0, 0), Gender::MAN);
    REQUIRE("辛未 辛丑 戊申 戊午" == childLimit.get_eight_char().to_string());
    REQUIRE(9 == childLimit.get_year_count());
    REQUIRE(0 == childLimit.get_month_count());
    REQUIRE(9 == childLimit.get_day_count());
    REQUIRE("2001年2月11日 18:58:00" == childLimit.get_end_time().to_string());
    REQUIRE("辛未" == childLimit.get_start_time().get_lunar_hour().get_lunar_day().get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());
    REQUIRE("辛巳" == childLimit.get_end_time().get_lunar_hour().get_lunar_day().get_lunar_month().get_lunar_year().get_sixty_cycle().get_name());

    DecadeFortune decadeFortune = childLimit.get_start_decade_fortune();
    REQUIRE(10 == decadeFortune.get_start_age());
    REQUIRE(19 == decadeFortune.get_end_age());
    REQUIRE(2001 == decadeFortune.get_start_sixty_cycle_year().get_year());
    REQUIRE(2010 == decadeFortune.get_end_sixty_cycle_year().get_year());
    REQUIRE("庚子" == decadeFortune.get_name());
    REQUIRE("己亥" == decadeFortune.next(1).get_name());

    Fortune fortune = childLimit.get_start_fortune();
    REQUIRE(10 == fortune.get_age());
    REQUIRE(2001 == fortune.get_sixty_cycle_year().get_year());
    REQUIRE("戊申" == fortune.get_name());
    REQUIRE("丙午" == fortune.next(2).get_name());
    REQUIRE("庚戌" == fortune.next(-2).get_name());
    REQUIRE("辛巳" == fortune.get_sixty_cycle_year().get_sixty_cycle().get_name());
}

TEST_CASE("eight_char_test_25") {
    ChildLimit childLimit = ChildLimit::from_solar_time(SolarTime::from_ymd_hms(1990, 3, 15, 10, 30, 0), Gender::MAN);
    REQUIRE("庚午 己卯 己卯 己巳" == childLimit.get_eight_char().to_string());
    REQUIRE(6 == childLimit.get_year_count());
    REQUIRE(11 == childLimit.get_month_count());
    REQUIRE(23 == childLimit.get_day_count());
    REQUIRE("1997年3月11日 00:22:00" == childLimit.get_end_time().to_string());

    Fortune fortune = childLimit.get_start_fortune();
    REQUIRE(8 == fortune.get_age());
}

TEST_CASE("eight_char_test_26") {
    REQUIRE("丁丑" == EightChar("己丑", "戊辰", "戊辰", "甲子").get_own_sign().get_name());
}

TEST_CASE("eight_char_test_27") {
    REQUIRE("乙卯" == EightChar("戊戌", "庚申", "丁亥", "丙午").get_own_sign().get_name());
}

TEST_CASE("eight_char_test_28") {
    ChildLimit childLimit = ChildLimit::from_solar_time(SolarTime::from_ymd_hms(2024, 1, 29, 9, 33, 0), Gender::MAN);
    EightChar eightChar = childLimit.get_eight_char();
    REQUIRE("癸卯 乙丑 壬辰 乙巳" == eightChar.to_string());
    REQUIRE("癸亥" == eightChar.get_own_sign().get_name());
    REQUIRE("己未" == eightChar.get_body_sign().get_name());
}

TEST_CASE("eight_char_test_29") {
    REQUIRE("丙寅" == ChildLimit::from_solar_time(SolarTime::from_ymd_hms(1990, 1, 27, 0, 0, 0), Gender::MAN).get_eight_char().get_body_sign().get_name());
}

TEST_CASE("eight_char_test_30") {
    REQUIRE("甲戌" == ChildLimit::from_solar_time(SolarTime::from_ymd_hms(2019, 3, 7, 8, 0, 0), Gender::MAN).get_eight_char().get_own_sign().get_name());
}

TEST_CASE("eight_char_test_31") {
    REQUIRE("丁丑" == ChildLimit::from_solar_time(SolarTime::from_ymd_hms(2019, 3, 27, 2, 0, 0), Gender::MAN).get_eight_char().get_own_sign().get_name());
}

TEST_CASE("eight_char_test_32") {
    REQUIRE("丙寅" == LunarHour::from_ymd_hms(1994, 5, 20, 18, 0, 0).get_eight_char().get_own_sign().get_name());
}

TEST_CASE("eight_char_test_33") {
    EightChar eightChar = SolarTime::from_ymd_hms(1986, 5, 29, 13, 37, 0).get_lunar_hour().get_eight_char();
    REQUIRE("丙寅 癸巳 癸酉 己未" == eightChar.to_string());
    REQUIRE("癸巳" == eightChar.get_own_sign().get_name());
    REQUIRE("辛丑" == eightChar.get_body_sign().get_name());
    REQUIRE("甲申" == eightChar.get_fetal_origin().get_name());
    REQUIRE("戊辰" == eightChar.get_fetal_breath().get_name());
}

TEST_CASE("eight_char_test_34") {
    EightChar eightChar = SolarTime::from_ymd_hms(1994, 12, 6, 2, 0, 0).get_lunar_hour().get_eight_char();
    REQUIRE("甲戌 乙亥 丙寅 己丑" == eightChar.to_string());
    REQUIRE("己巳" == eightChar.get_own_sign().get_name());
    REQUIRE("丁丑" == eightChar.get_body_sign().get_name());
    REQUIRE("丙寅" == eightChar.get_fetal_origin().get_name());
    REQUIRE("辛亥" == eightChar.get_fetal_breath().get_name());
}

TEST_CASE("eight_char_test_35") {
    REQUIRE("辛卯" == EightChar("辛亥", "丁酉", "丙午", "癸巳").get_own_sign().get_name());
}

TEST_CASE("eight_char_test_36") {
    EightChar eightChar = EightChar("丙寅", "庚寅", "辛卯", "壬辰");
    REQUIRE("己亥" == eightChar.get_own_sign().get_name());
    REQUIRE("乙未" == eightChar.get_body_sign().get_name());
}

TEST_CASE("eight_char_test_37") {
    REQUIRE("乙巳" == EightChar("壬子", "辛亥", "壬戌", "乙巳").get_body_sign().get_name());
}

TEST_CASE("eight_char_test_38") {
    vector<SolarTime> solarTimes = EightChar("丙辰", "丁酉", "丙子", "甲午").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1916年10月6日 12:00:00", "1976年9月21日 12:00:00"} == actual);
}

TEST_CASE("eight_char_test_39") {
    vector<SolarTime> solarTimes = EightChar("壬寅", "庚戌", "己未", "乙亥").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"2022年11月2日 22:00:00"} == actual);
}

TEST_CASE("eight_char_test_40") {
    vector<SolarTime> solarTimes = EightChar("己卯", "辛未", "甲戌", "壬申").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1939年8月5日 16:00:00", "1999年7月21日 16:00:00"} == actual);
}

TEST_CASE("eight_char_test_41") {
    vector<SolarTime> solarTimes = EightChar("庚子", "戊子", "己卯", "庚午").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1901年1月1日 12:00:00", "1960年12月17日 12:00:00"} == actual);
}

TEST_CASE("eight_char_test_42") {
    vector<SolarTime> solarTimes = EightChar("庚子", "癸未", "乙丑", "丁亥").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1960年8月5日 22:00:00", "2020年7月21日 22:00:00"} == actual);
}

TEST_CASE("eight_char_test_43") {
    vector<SolarTime> solarTimes = EightChar("癸卯", "甲寅", "甲寅", "甲子").get_solar_times(1800, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1843年2月9日 00:00:00", "2023年2月25日 00:00:00"} == actual);
}

TEST_CASE("eight_char_test_44") {
    vector<SolarTime> solarTimes = EightChar("甲辰", "丙寅", "己亥", "戊辰").get_solar_times(1800, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1904年3月6日 07:00:00", "1964年2月20日 08:00:00", "2024年2月5日 08:00:00"} == actual);
}

TEST_CASE("eight_char_test_45") {
    vector<SolarTime> solarTimes = EightChar("己亥", "丁丑", "壬寅", "戊申").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1900年1月29日 16:00:00", "1960年1月15日 16:00:00"} == actual);
}

TEST_CASE("eight_char_test_46") {
    vector<SolarTime> solarTimes = EightChar("己亥", "丙子", "癸酉", "庚申").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1959年12月17日 16:00:00"} == actual);
}

TEST_CASE("eight_char_test_47") {
    vector<SolarTime> solarTimes = EightChar("丁丑", "癸卯", "癸丑", "辛酉").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1937年3月27日 18:00:00", "1997年3月12日 18:00:00"} == actual);
}

TEST_CASE("eight_char_test_48") {
    vector<SolarTime> solarTimes = EightChar("乙未", "己卯", "丁丑", "甲辰").get_solar_times(1900, 2024);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1955年3月17日 08:00:00"} == actual);
}

TEST_CASE("eight_char_test_49") {
    REQUIRE("壬申" == EightChar("甲辰", "丙寅", "己亥", "辛未").get_own_sign().get_name());
}

TEST_CASE("eight_char_test_50") {
    ChildLimit childLimit = ChildLimit::from_solar_time(SolarTime::from_ymd_hms(1989, 12, 31, 23, 7, 17), Gender::MAN);
    REQUIRE("1998年3月1日 19:47:17" == childLimit.get_end_time().to_string());
}

TEST_CASE("eight_char_test_51") {
    EightChar eightChar = SolarTime::from_ymd_hms(1980, 6, 15, 12, 30, 30).get_lunar_hour().get_eight_char();
    REQUIRE("辛巳" == eightChar.get_own_sign().get_name());
    REQUIRE("己丑" == eightChar.get_body_sign().get_name());
    REQUIRE("癸酉" == eightChar.get_fetal_origin().get_name());
    REQUIRE("甲午" == eightChar.get_fetal_breath().get_name());
}

TEST_CASE("eight_char_test_52") {
    vector<SolarTime> solarTimes = EightChar("壬申", "壬寅", "庚辰", "甲申").get_solar_times(1801, 2099);
    vector<string> actual;
    for (const SolarTime &st : solarTimes) {
        actual.push_back(st.to_string());
    }
    REQUIRE(vector<string>{"1812年2月18日 16:00:00", "1992年3月5日 15:00:00", "2052年2月19日 16:00:00"} == actual);
}

TEST_CASE("eight_char_test_53") {
    REQUIRE("辛酉 丙申 丙戌 戊子" == SolarTime::from_ymd_hms(1981, 9, 5, 0, 0, 0).get_lunar_hour().get_eight_char().to_string());
}

TEST_CASE("eight_char_test_54") {
    REQUIRE("戊寅 癸亥 庚申 甲申" == ChildLimit::from_solar_time(SolarTime::from_ymd_hms(198, 11, 26, 15, 13, 59), Gender::MAN).get_eight_char().to_string());
    REQUIRE("庚申 己丑 甲辰 壬申" == ChildLimit::from_solar_time(SolarTime::from_ymd_hms(1981, 1, 26, 15, 13, 59), Gender::MAN).get_eight_char().to_string());
}

TEST_CASE("lunar_festival_test_1") {
    optional<LunarFestival> f = LunarFestival::from_index(2023, 0);
    REQUIRE(f.has_value());
    vector<string> names = {"春节", "元宵节", "龙头节", "上巳节", "清明节", "端午节", "七夕节", "中元节", "中秋节", "重阳节", "冬至节", "腊八节", "除夕"};
    for (int i = 0; i < static_cast<int>(names.size()); i++) {
        REQUIRE(names[i] == f.value().next(i).value().get_name());
    }
}

TEST_CASE("solar_festival_test_0") {
    vector<string> names = {"元旦", "妇女节", "植树节", "劳动节", "青年节", "儿童节", "建党节", "建军节", "教师节", "国庆节"};
    for (int i = 0; i < static_cast<int>(names.size()); i++) {
        optional<SolarFestival> f = SolarFestival::from_index(2023, i);
        REQUIRE(f.has_value());
        REQUIRE(names[i] == f.value().get_name());
    }
}

TEST_CASE("solar_festival_test_1") {
    optional<SolarFestival> f = SolarFestival::from_index(2023, 0);
    REQUIRE(f.has_value());
    vector<string> names = {"元旦", "妇女节", "植树节", "劳动节", "青年节", "儿童节", "建党节", "建军节", "教师节", "国庆节"};
    for (int i = 0; i < static_cast<int>(names.size()); i++) {
        REQUIRE(names[i] == f.value().next(i).value().get_name());
    }
}
