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
    PengZu::PengZu(const SixtyCycle &sixty_cycle) : peng_zu_heaven_stem(PengZuHeavenStem::from_index(sixty_cycle.get_heaven_stem().get_index())), peng_zu_earth_branch(PengZuEarthBranch::from_index(sixty_cycle.get_earth_branch().get_index())) {
    }

    const vector<string> PengZuHeavenStem::NAMES = {
        "甲不开仓财物耗散", "乙不栽植千株不长", "丙不修灶必见灾殃", "丁不剃头头必生疮", "戊不受田田主不祥", "己不破券二比并亡", "庚不经络织机虚张", "辛不合酱主人不尝", "壬不泱水更难提防", "癸不词讼理弱敌强"
    };

    PengZuHeavenStem PengZuHeavenStem::from_index(const int index) {
        return PengZuHeavenStem(index);
    }

    PengZuHeavenStem PengZuHeavenStem::from_name(const string &name) {
        return PengZuHeavenStem(name);
    }

    PengZuHeavenStem PengZuHeavenStem::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> PengZuEarthBranch::NAMES = {
        "子不问卜自惹祸殃", "丑不冠带主不还乡", "寅不祭祀神鬼不尝", "卯不穿井水泉不香", "辰不哭泣必主重丧", "巳不远行财物伏藏", "午不苫盖屋主更张", "未不服药毒气入肠", "申不安床鬼祟入房", "酉不会客醉坐颠狂", "戌不吃犬作怪上床", "亥不嫁娶不利新郎"
    };

    PengZuEarthBranch PengZuEarthBranch::from_index(const int index) {
        return PengZuEarthBranch(index);
    }

    PengZuEarthBranch PengZuEarthBranch::from_name(const string &name) {
        return PengZuEarthBranch(name);
    }

    PengZuEarthBranch PengZuEarthBranch::next(const int n) const {
        return from_index(next_index(n));
    }

    PengZu PengZu::from_sixty_cycle(const SixtyCycle &sixty_cycle) {
        return PengZu(sixty_cycle);
    }

    string PengZu::get_name() const {
        return peng_zu_heaven_stem.to_string() + " " + peng_zu_earth_branch.to_string();
    }

    PengZuHeavenStem PengZu::get_peng_zu_heaven_stem() const {
        return peng_zu_heaven_stem;
    }

    PengZuEarthBranch PengZu::get_peng_zu_earth_branch() const {
        return peng_zu_earth_branch;
    }
}
