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
    const vector<string> Dog::NAMES = {
        "初伏", "中伏", "末伏"
    };

    Dog Dog::from_index(const int index) {
        return Dog(index);
    }

    Dog Dog::from_name(const string &name) {
        return Dog(name);
    }

    Dog Dog::next(const int n) const {
        return from_index(next_index(n));
    }

    Dog DogDay::get_dog() const {
        return dog;
    }

    int DogDay::get_day_index() const {
        return day_index;
    }

    string DogDay::get_name() const {
        return dog.get_name();
    }

    string DogDay::to_string() const {
        return dog.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }
}
