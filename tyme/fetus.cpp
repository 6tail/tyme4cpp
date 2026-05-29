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
    FetusDay::FetusDay(const SixtyCycle &sixty_cycle) : AbstractCulture(), fetus_heaven_stem(FetusHeavenStem(sixty_cycle.get_heaven_stem().get_index() % 5)), fetus_earth_branch(FetusEarthBranch(sixty_cycle.get_earth_branch().get_index() % 6)) {
        constexpr int indices[] = {3, 3, 8, 8, 8, 8, 8, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, -9, -9, -9, -9, -9, -5, -5, -1, -1, -1, -3, -7, -7, -7, -7, -5, 7, 7, 7, 7, 7, 7, 2, 2, 2, 2, 2, 3, 3, 3, 3};
        const int index = indices[sixty_cycle.get_index()];
        side = index < 0 ? Side::IN : Side::OUT;
        direction = Direction::from_index(index);
    }

    FetusDay::FetusDay(const SixtyCycleDay &sixty_cycle_day) : FetusDay(sixty_cycle_day.get_sixty_cycle()) {
    }

    FetusDay::FetusDay(const LunarDay &lunar_day) : FetusDay(lunar_day.get_sixty_cycle()) {
    }

    const vector<string> FetusHeavenStem::NAMES = {
        "门", "碓磨", "厨灶", "仓库", "房床"
    };

    FetusHeavenStem FetusHeavenStem::from_index(const int index) {
        return FetusHeavenStem(index);
    }

    FetusHeavenStem FetusHeavenStem::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> FetusEarthBranch::NAMES = {
        "碓", "厕", "炉", "门", "栖", "床"
    };

    FetusEarthBranch FetusEarthBranch::from_index(const int index) {
        return FetusEarthBranch(index);
    }

    FetusEarthBranch FetusEarthBranch::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> FetusMonth::NAMES = {
        "占房床", "占户窗", "占门堂", "占厨灶", "占房床", "占床仓", "占碓磨", "占厕户", "占门房", "占房床", "占灶炉", "占房床"
    };

    optional<FetusMonth> FetusMonth::from_lunar_month(const LunarMonth& lunar_month) {
        if (!lunar_month.is_leap()) {
            return FetusMonth(lunar_month.get_month() - 1);
        }
        return nullopt;
    }

    FetusMonth FetusMonth::next(const int n) const {
        return FetusMonth(next_index(n));
    }

    FetusDay FetusDay::from_sixty_cycle_day(const SixtyCycleDay& sixty_cycle_day) {
        return FetusDay(sixty_cycle_day);
    }

    FetusDay FetusDay::from_lunar_day(const LunarDay &lunar_day) {
        return FetusDay(lunar_day);
    }

    string FetusDay::get_name() const {
        string s = fetus_heaven_stem.get_name() + fetus_earth_branch.get_name();
        string door = "门";
        if ("门门" == s) {
            s = "占大门";
        } else if ("碓磨碓" == s) {
            s = "占碓磨";
        } else if ("房床床" == s) {
            s = "占房床";
        } else if (s.compare(0, door.size(), door) == 0) {
            s = "占" + s;
        }

        s += " ";

        s += Side::IN == side ? "房内" : "外";

        string ds = "北南西东";
        string direction_name = direction.get_name();
        if (Side::OUT == side && ds.find(direction_name) != string::npos) {
            s += "正";
        }
        s += direction_name;
        return s;
    }

    Side FetusDay::get_side() const {
        return side;
    }

    Direction FetusDay::get_direction() const {
        return direction;
    }

    FetusHeavenStem FetusDay::get_fetus_heaven_stem() const {
        return fetus_heaven_stem;
    }

    FetusEarthBranch FetusDay::get_fetus_earth_branch() const {
        return fetus_earth_branch;
    }
}
