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
    const vector<string> MinorRen::NAMES = {
        "大安", "留连", "速喜", "赤口", "小吉", "空亡"
    };

    MinorRen MinorRen::from_index(const int index) {
        return MinorRen(index);
    }

    MinorRen MinorRen::from_name(const string &name) {
        return MinorRen(name);
    }

    MinorRen MinorRen::next(const int n) const {
        return from_index(next_index(n));
    }

    Luck MinorRen::get_luck() const {
        return Luck::from_index(index % 2);
    }

    Element MinorRen::get_element() const {
        const int indices[6] = {0, 4, 1, 3, 0, 2};
        return Element::from_index(indices[index]);
    }
}
