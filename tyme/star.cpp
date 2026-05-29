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
    const vector<string> Dipper::NAMES = {
        "天枢", "天璇", "天玑", "天权", "玉衡", "开阳", "摇光", "洞明", "隐元"
    };

    Dipper Dipper::from_index(const int index) {
        return Dipper(index);
    }

    Dipper Dipper::from_name(const string &name) {
        return Dipper(name);
    }

    Dipper Dipper::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> NineStar::NAMES = {
        "一", "二", "三", "四", "五", "六", "七", "八", "九"
    };

    const vector<string> NineStar::COLORS = {
        "白", "黑", "碧", "绿", "黄", "白", "赤", "白", "紫"
    };

    NineStar NineStar::from_index(const int index) {
        return NineStar(index);
    }

    NineStar NineStar::from_name(const string &name) {
        return NineStar(name);
    }

    NineStar NineStar::next(const int n) const {
        return from_index(next_index(n));
    }

    string NineStar::get_color() const {
        return COLORS[index];
    }

    Element NineStar::get_element() const {
        return get_direction().get_element();
    }

    Dipper NineStar::get_dipper() const {
        return Dipper::from_index(index);
    }

    Direction NineStar::get_direction() const {
        return Direction::from_index(index);
    }

    string NineStar::to_string() const {
        return get_name() + get_color() + get_element().to_string();
    }

    const vector<string> SevenStar::NAMES = {
        "日", "月", "火", "水", "木", "金", "土"
    };

    SevenStar SevenStar::from_index(const int index) {
        return SevenStar(index);
    }

    SevenStar SevenStar::from_name(const string &name) {
        return SevenStar(name);
    }

    SevenStar SevenStar::next(const int n) const {
        return from_index(next_index(n));
    }

    Week SevenStar::get_week() const {
        return Week::from_index(index);
    }

    const vector<string> SixStar::NAMES = {
        "先胜", "友引", "先负", "佛灭", "大安", "赤口"
    };

    SixStar SixStar::from_index(const int index) {
        return SixStar(index);
    }

    SixStar SixStar::from_name(const string &name) {
        return SixStar(name);
    }

    SixStar SixStar::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> TenStar::NAMES = {
        "比肩", "劫财", "食神", "伤官", "偏财", "正财", "七杀", "正官", "偏印", "正印"
    };

    TenStar TenStar::from_index(const int index) {
        return TenStar(index);
    }

    TenStar TenStar::from_name(const string &name) {
        return TenStar(name);
    }

    TenStar TenStar::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> Ecliptic::NAMES = {
        "黄道", "黑道"
    };

    Ecliptic Ecliptic::from_index(const int index) {
        return Ecliptic(index);
    }

    Ecliptic Ecliptic::from_name(const string &name) {
        return Ecliptic(name);
    }

    Ecliptic Ecliptic::next(const int n) const {
        return from_index(next_index(n));
    }

    Luck Ecliptic::get_luck() const {
        return Luck::from_index(index);
    }

    const vector<string> TwelveStar::NAMES = {
        "青龙", "明堂", "天刑", "朱雀", "金匮", "天德", "白虎", "玉堂", "天牢", "玄武", "司命", "勾陈"
    };

    TwelveStar TwelveStar::from_index(const int index) {
        return TwelveStar(index);
    }

    TwelveStar TwelveStar::from_name(const string &name) {
        return TwelveStar(name);
    }

    TwelveStar TwelveStar::next(const int n) const {
        return from_index(next_index(n));
    }

    Ecliptic TwelveStar::get_ecliptic() const {
        const int indices[12] = {0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1};
        return Ecliptic::from_index(indices[index]);
    }

    const vector<string> TwentyEightStar::NAMES = {
        "角", "亢", "氐", "房", "心", "尾", "箕", "斗", "牛", "女", "虚", "危", "室", "壁", "奎", "娄", "胃", "昴", "毕", "觜", "参", "井", "鬼", "柳", "星", "张", "翼", "轸"
    };

    TwentyEightStar TwentyEightStar::from_index(const int index) {
        return TwentyEightStar(index);
    }

    TwentyEightStar TwentyEightStar::from_name(const string &name) {
        return TwentyEightStar(name);
    }

    TwentyEightStar TwentyEightStar::next(const int n) const {
        return from_index(next_index(n));
    }

    SevenStar TwentyEightStar::get_seven_star() const {
        return SevenStar::from_index(index % 7 + 4);
    }

    Land TwentyEightStar::get_land() const {
        const int indices[28] = {4, 4, 4, 2, 2, 2, 7, 7, 7, 0, 0, 0, 0, 5, 5, 5, 6, 6, 6, 1, 1, 1, 8, 8, 8, 3, 3, 3};
        return Land::from_index(indices[index]);
    }

    Zone TwentyEightStar::get_zone() const {
        return Zone::from_index(index / 7);
    }

    Animal TwentyEightStar::get_animal() const {
        return Animal::from_index(index);
    }

    Luck TwentyEightStar::get_luck() const {
        const int indices[28] = {0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
        return Luck::from_index(indices[index]);
    }
}
