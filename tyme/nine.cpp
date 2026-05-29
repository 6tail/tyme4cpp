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
    const vector<string> Nine::NAMES = {
        "一九", "二九", "三九", "四九", "五九", "六九", "七九", "八九", "九九"
    };

    Nine Nine::from_index(const int index) {
        return Nine(index);
    }

    Nine Nine::from_name(const string &name) {
        return Nine(name);
    }

    Nine Nine::next(const int n) const {
        return from_index(next_index(n));
    }

    Nine NineDay::get_nine() const {
        return nine;
    }

    int NineDay::get_day_index() const {
        return day_index;
    }

    string NineDay::get_name() const {
        return nine.get_name();
    }

    string NineDay::to_string() const {
        return nine.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }
}
