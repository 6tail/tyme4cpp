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
    const vector<string> Animal::NAMES = {
        "蛟", "龙", "貉", "兔", "狐", "虎", "豹", "獬", "牛", "蝠", "鼠", "燕", "猪", "獝", "狼", "狗", "彘", "鸡", "乌", "猴", "猿", "犴", "羊", "獐", "马", "鹿", "蛇", "蚓"
    };

    Animal Animal::from_index(const int index) {
        return Animal(index);
    }

    Animal Animal::from_name(const string &name) {
        return Animal(name);
    }

    Animal Animal::next(const int n) const {
        return from_index(next_index(n));
    }

    TwentyEightStar Animal::get_twenty_eight_star() const {
        return TwentyEightStar::from_index(index);
    }

    const vector<string> Beast::NAMES = {
        "青龙", "玄武", "白虎", "朱雀"
    };

    Beast Beast::from_index(const int index) {
        return Beast(index);
    }

    Beast Beast::from_name(const string &name) {
        return Beast(name);
    }

    Beast Beast::next(const int n) const {
        return from_index(next_index(n));
    }

    Zone Beast::get_zone() const {
        return Zone::from_index(index);
    }

    const vector<string> Constellation::NAMES = {
        "白羊", "金牛", "双子", "巨蟹", "狮子", "处女", "天秤", "天蝎", "射手", "摩羯", "水瓶", "双鱼"
    };

    Constellation Constellation::from_index(const int index) {
        return Constellation(index);
    }

    Constellation Constellation::from_name(const string &name) {
        return Constellation(name);
    }

    Constellation Constellation::next(const int n) const {
        return from_index(next_index(n));
    }

    /**
     * @brief 依据后天八卦排序（0坎北, 1坤西南, 2震东, 3巽东南, 4中, 5乾西北, 6兑西, 7艮东北, 8离南）
     */
    const vector<string> Direction::NAMES = {
        "北", "西南", "东", "东南", "中", "西北", "西", "东北", "南"
    };

    Direction Direction::from_index(const int index) {
        return Direction(index);
    }

    Direction Direction::from_name(const string &name) {
        return Direction(name);
    }

    Direction Direction::next(const int n) const {
        return from_index(next_index(n));
    }

    Land Direction::get_land() const {
        return Land::from_index(index);
    }

    Element Direction::get_element() const {
        const int indices[9] = {4, 2, 0, 0, 2, 3, 3, 2, 1};
        return Element::from_index(indices[index]);
    }

    const vector<string> Duty::NAMES = {
        "建", "除", "满", "平", "定", "执", "破", "危", "成", "收", "开", "闭"
    };

    Duty Duty::from_index(const int index) {
        return Duty(index);
    }

    Duty Duty::from_name(const string &name) {
        return Duty(name);
    }

    Duty Duty::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> Element::NAMES = {
        "木", "火", "土", "金", "水"
    };

    Element Element::from_index(const int index) {
        return Element(index);
    }

    Element Element::from_name(const string &name) {
        return Element(name);
    }

    Element Element::next(const int n) const {
        return from_index(next_index(n));
    }

    bool Element::equals(const Element &other) const {
        return to_string() == other.to_string();
    }


    Element Element::get_reinforce() const {
        return next(1);
    }

    Element Element::get_restrain() const {
        return next(2);
    }

    Element Element::get_reinforced() const {
        return next(-1);
    }

    Element Element::get_restrained() const {
        return next(-2);
    }

    Direction Element::get_direction() const {
        const int indices[5] = {2, 8, 4, 6, 0};
        return Direction::from_index(indices[index]);
    }

    const vector<string> Land::NAMES = {
        "玄天", "朱天", "苍天", "阳天", "钧天", "幽天", "颢天", "变天", "炎天"
    };

    Land Land::from_index(const int index) {
        return Land(index);
    }

    Land Land::from_name(const string &name) {
        return Land(name);
    }

    Land Land::next(const int n) const {
        return from_index(next_index(n));
    }

    Direction Land::get_direction() const {
        return Direction::from_index(index);
    }

    const vector<string> Luck::NAMES = {
        "吉", "凶"
    };

    Luck Luck::from_index(const int index) {
        return Luck(index);
    }

    Luck Luck::from_name(const string &name) {
        return Luck(name);
    }

    Luck Luck::next(const int n) const {
        return from_index(next_index(n));
    }
    const vector<string> Sixty::NAMES = {
        "上元", "中元", "下元"
    };

    Sixty Sixty::from_index(const int index) {
        return Sixty(index);
    }

    Sixty Sixty::from_name(const string &name) {
        return Sixty(name);
    }

    Sixty Sixty::next(const int n) const {
        return from_index(next_index(n));
    }
    const vector<string> Sound::NAMES = {
        "海中金", "炉中火", "大林木", "路旁土", "剑锋金", "山头火", "涧下水", "城头土", "白蜡金", "杨柳木", "泉中水", "屋上土", "霹雳火", "松柏木", "长流水", "沙中金", "山下火", "平地木", "壁上土", "金箔金", "覆灯火", "天河水", "大驿土", "钗钏金", "桑柘木", "大溪水", "沙中土", "天上火", "石榴木", "大海水"
    };

    Sound Sound::from_index(const int index) {
        return Sound(index);
    }

    Sound Sound::from_name(const string &name) {
        return Sound(name);
    }

    Sound Sound::next(const int n) const {
        return from_index(next_index(n));
    }
    const vector<string> Ten::NAMES = {
        "甲子", "甲戌", "甲申", "甲午", "甲辰", "甲寅"
    };

    Ten Ten::from_index(const int index) {
        return Ten(index);
    }

    Ten Ten::from_name(const string &name) {
        return Ten(name);
    }

    Ten Ten::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> Terrain::NAMES = {
        "长生", "沐浴", "冠带", "临官", "帝旺", "衰", "病", "死", "墓", "绝", "胎", "养"
    };

    Terrain Terrain::from_index(const int index) {
        return Terrain(index);
    }

    Terrain Terrain::from_name(const string &name) {
        return Terrain(name);
    }

    Terrain Terrain::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> Twenty::NAMES = {
        "一运", "二运", "三运", "四运", "五运", "六运", "七运", "八运", "九运"
    };

    Twenty Twenty::from_index(const int index) {
        return Twenty(index);
    }

    Twenty Twenty::from_name(const string &name) {
        return Twenty(name);
    }

    Twenty Twenty::next(const int n) const {
        return from_index(next_index(n));
    }

    Sixty Twenty::get_sixty() const {
        return Sixty::from_index(index / 3);
    }

    const vector<string> Week::NAMES = {
        "日", "一", "二", "三", "四", "五", "六"
    };

    Week Week::from_index(const int index) {
        return Week(index);
    }

    Week Week::from_name(const string &name) {
        return Week(name);
    }

    Week Week::next(const int n) const {
        return from_index(next_index(n));
    }

    SevenStar Week::get_seven_star() const {
        return SevenStar::from_index(index);
    }

    const vector<string> Zodiac::NAMES = {
        "鼠", "牛", "虎", "兔", "龙", "蛇", "马", "羊", "猴", "鸡", "狗", "猪"
    };

    Zodiac Zodiac::from_index(const int index) {
        return Zodiac(index);
    }

    Zodiac Zodiac::from_name(const string &name) {
        return Zodiac(name);
    }

    Zodiac Zodiac::next(const int n) const {
        return from_index(next_index(n));
    }

    bool Zodiac::equals(const Zodiac &other) const {
        return to_string() == other.to_string();
    }

    EarthBranch Zodiac::get_earth_branch() const {
        return EarthBranch::from_index(index);
    }

    const vector<string> Zone::NAMES = {
        "东", "北", "西", "南"
    };

    Zone Zone::from_index(const int index) {
        return Zone(index);
    }

    Zone Zone::from_name(const string &name) {
        return Zone(name);
    }

    Zone Zone::next(const int n) const {
        return from_index(next_index(n));
    }

    Direction Zone::get_direction() const {
        return Direction::from_name(get_name());
    }

    Beast Zone::get_beast() const {
        return Beast::from_index(index);
    }
}
