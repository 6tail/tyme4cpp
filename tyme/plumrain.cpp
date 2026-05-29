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
    const vector<string> PlumRain::NAMES = {
        "入梅", "出梅"
    };

    PlumRain PlumRain::from_index(const int index) {
        return PlumRain(index);
    }

    PlumRain PlumRain::from_name(const string &name) {
        return PlumRain(name);
    }

    PlumRain PlumRain::next(const int n) const {
        return from_index(next_index(n));
    }

    PlumRain PlumRainDay::get_plum_rain() const {
        return plum_rain;
    }

    int PlumRainDay::get_day_index() const {
        return day_index;
    }

    string PlumRainDay::get_name() const {
        return plum_rain.get_name();
    }

    string PlumRainDay::to_string() const {
        return get_plum_rain().get_index() == 0 ? plum_rain.to_string() + "第" + std::to_string(day_index + 1) + "天" : get_name();
    }
}
