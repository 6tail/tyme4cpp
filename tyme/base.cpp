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
    bool AbstractCulture::equals(const Culture *o) const {
        return o && o->to_string() == to_string();
    }

    string AbstractCulture::get_name() const {
        return "";
    }

    string AbstractCulture::to_string() const {
        return get_name();
    }

    int AbstractCulture::index_of(const int index, const int size) {
        const int i = index % size;
        return i < 0 ? i + size : i;
    }

    int YearUnit::get_year() const {
        return year;
    }

    int MonthUnit::get_month() const {
        return month;
    }

    int DayUnit::get_day() const {
        return day;
    }

    const vector<string> WeekUnit::NAMES = {
        "第一周", "第二周", "第三周", "第四周", "第五周", "第六周"
    };

    int WeekUnit::get_index() const {
        return index;
    }

    int WeekUnit::get_start() const {
        return start;
    }

    void WeekUnit::validate(const int index, const int start) {
        if (index < 0 || index > 5) {
            throw invalid_argument("illegal week index: " + std::to_string(index));
        }
        if (start < 0 || start > 6) {
            throw invalid_argument("illegal week start: " + std::to_string(start));
        }
    }

    int SecondUnit::get_hour() const {
        return hour;
    }

    int SecondUnit::get_minute() const {
        return minute;
    }

    int SecondUnit::get_second() const {
        return second;
    }

    void SecondUnit::validate(const int hour, const int minute, const int second) {
        if (hour < 0 || hour > 23) {
            throw invalid_argument("illegal hour: " + std::to_string(hour));
        }
        if (minute < 0 || minute > 59) {
            throw invalid_argument("illegal minute: " + std::to_string(minute));
        }
        if (second < 0 || second > 59) {
            throw invalid_argument("illegal second: " + std::to_string(second));
        }
    }

    int LoopTyme::get_index() const {
        return index;
    }

    int LoopTyme::get_size() const {
        return static_cast<int>(names.size());
    }

    string LoopTyme::get_name() const {
        return names[index];
    }

    int LoopTyme::index_of(const string &name) const {
        for (int i = 0, j = get_size(); i < j; i++) {
            if (name == names[i]) {
                return i;
            }
        }
        throw invalid_argument("illegal name: " + name);
    }

    int LoopTyme::index_of(const int i) const {
        return AbstractCulture::index_of(i, get_size());
    }

    int LoopTyme::next_index(const int n) const {
        return index_of(index + n);
    }

    int LoopTyme::steps_to(const int target_index) const {
        return index_of(target_index - index);
    }

    int LoopTyme::steps_back_to(const int target_index) const {
        const int n = get_size();
        return -((index - target_index + n) % n);
    }

    int LoopTyme::steps_close_to(const int target_index) const {
        const int d1 = steps_to(target_index);
        const int d2 = steps_back_to(target_index);
        return d1 <= abs(d2) ? d1 : d2;
    }
}
