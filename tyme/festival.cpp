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
    const vector<string> LegalHoliday::NAMES = {
        "元旦", "春节", "清明节", "劳动节", "端午节", "中秋节", "国庆节", "国庆中秋", "抗战胜利日"
    };

    string LegalHoliday::DATA = "2001122900+032001123000+022002010110+002002010210-012002010310-022002020901+032002021001+022002021211+002002021311-012002021411-022002021511-032002021611-042002021711-052002021811-062002042703+042002042803+032002050113+002002050213-012002050313-022002050413-032002050513-042002050613-052002050713-062002092806+032002092906+022002100116+002002100216-012002100316-022002100416-032002100516-042002100616-052002100716-062003010110+002003020111+002003020211-012003020311-022003020411-032003020511-042003020611-052003020711-062003020801-072003020901-082003042603+052003042703+042003050113+002003050213-012003050313-022003050413-032003050513-042003050613-052003050713-062003092706+042003092806+032003100116+002003100216-012003100316-022003100416-032003100516-042003100616-052003100716-062004010110+002004011701+052004011801+042004012211+002004012311-012004012411-022004012511-032004012611-042004012711-052004012811-062004050113+002004050213-012004050313-022004050413-032004050513-042004050613-052004050713-062004050803-072004050903-082004100116+002004100216-012004100316-022004100416-032004100516-042004100616-052004100716-062004100906-082004101006-092005010110+002005010210-012005010310-022005020501+042005020601+032005020911+002005021011-012005021111-022005021211-032005021311-042005021411-052005021511-062005043003+012005050113+002005050213-012005050313-022005050413-032005050513-042005050613-052005050713-062005050803-072005100116+002005100216-012005100316-022005100416-032005100516-042005100616-052005100716-062005100806-072005100906-082005123100+012006010110+002006010210-012006010310-022006012801+012006012911+002006013011-012006013111-022006020111-032006020211-042006020311-052006020411-062006020501-072006042903+022006043003+012006050113+002006050213-012006050313-022006050413-032006050513-042006050613-052006050713-062006093006+012006100116+002006100216-012006100316-022006100416-032006100516-042006100616-052006100716-062006100806-072006123000+022006123100+012007010110+002007010210-012007010310-022007021701+012007021811+002007021911-012007022011-022007022111-032007022211-042007022311-052007022411-062007022501-072007042803+032007042903+022007050113+002007050213-012007050313-022007050413-032007050513-042007050613-052007050713-062007092906+022007093006+012007100116+002007100216-012007100316-022007100416-032007100516-042007100616-052007100716-062007122900+032007123010+022007123110+012008010110+002008020201+042008020301+032008020611+002008020711-012008020811-022008020911-032008021011-042008021111-052008021211-062008040412+002008040512-012008040612-022008050113+002008050213-012008050313-022008050403-032008060714+012008060814+002008060914-012008091315+012008091415+002008091515-012008092706+042008092806+032008092916+022008093016+012008100116+002008100216-012008100316-022008100416-032008100516-042009010110+002009010210-012009010310-022009010400-032009012401+012009012511+002009012611-012009012711-022009012811-032009012911-042009013011-052009013111-062009020101-072009040412+002009040512-012009040612-022009050113+002009050213-012009050313-022009052814+002009052914-012009053014-022009053104-032009092706+042009100116+002009100216-012009100316-022009100416-032009100515-022009100615-032009100715-042009100815-052009101005-072010010110+002010010210-012010010310-022010021311+002010021411-012010021511-022010021611-032010021711-042010021811-052010021911-062010022001-072010022101-082010040312+022010040412+012010040512+002010050113+002010050213-012010050313-022010061204+042010061304+032010061414+022010061514+012010061614+002010091905+032010092215+002010092315-012010092415-022010092505-032010092606+052010100116+002010100216-012010100316-022010100416-032010100516-042010100616-052010100716-062010100906-082011010110+002011010210-012011010310-022011013001+042011020211+012011020311+002011020411-012011020511-022011020611-032011020711-042011020811-052011021201-092011040202+032011040312+022011040412+012011040512+002011043013+012011050113+002011050213-012011060414+022011060514+012011060614+002011091015+022011091115+012011091215+002011100116+002011100216-012011100316-022011100416-032011100516-042011100616-052011100716-062011100806-072011100906-082011123100+012012010110+002012010210-012012010310-022012012101+022012012211+012012012311+002012012411-012012012511-022012012611-032012012711-042012012811-052012012901-062012033102+042012040102+032012040212+022012040312+012012040412+002012042803+032012042913+022012043013+012012050113+002012050203-012012062214+012012062314+002012062414-012012092905+012012093015+002012100116+002012100216-012012100316-022012100416-032012100516-042012100616-052012100716-062012100806-072013010110+002013010210-012013010310-022013010500-042013010600-052013020911+012013021011+002013021111-012013021211-022013021311-032013021411-042013021511-052013021601-062013021701-072013040412+002013040512-012013040612-022013042703+042013042803+032013042913+022013043013+012013050113+002013060804+042013060904+032013061014+022013061114+012013061214+002013091915+002013092015-012013092115-022013092205-032013092906+022013100116+002013100216-012013100316-022013100416-032013100516-042013100616-052013100716-062014010110+002014012601+052014013111+002014020111-012014020211-022014020311-032014020411-042014020511-052014020611-062014020801-082014040512+002014040612-012014040712-022014050113+002014050213-012014050313-022014050403-032014053114+022014060114+012014060214+002014090615+022014090715+012014090815+002014092806+032014100116+002014100216-012014100316-022014100416+002014100516-042014100616-052014100716-062014101106-102015010110+002015010210-012015010310-022015010400-032015021501+042015021811+012015021911+002015022011-012015022111-022015022211-032015022311-042015022411-052015022801-092015040412+012015040512+002015040612-012015050113+002015050213-012015050313-022015062014+002015062114-012015062214-022015090318+002015090418-012015090518-022015090608-032015092615+012015092715+002015100116+002015100216-012015100316-022015100416+002015100516-042015100616-052015100716-062015101006-092016010110+002016010210-012016010310-022016020601+022016020711+012016020811+002016020911-012016021011-022016021111-032016021211-042016021311-052016021401-062016040212+022016040312+012016040412+002016043013+012016050113+002016050213-012016060914+002016061014-012016061114-022016061204-032016091515+002016091615-012016091715-022016091805-032016100116+002016100216-012016100316-022016100416-032016100516-042016100616-052016100716-062016100806-072016100906-082016123110+012017010110+002017010210-012017012201+062017012711+012017012811+002017012911-012017013011-022017013111-032017020111-042017020211-052017020401-072017040102+032017040212+022017040312+012017040412+002017042913+022017043013+012017050113+002017052704+032017052814+022017052914+012017053014+002017093006+012017100116+002017100216-012017100316-022017100415+002017100516-042017100616-052017100716-062017100816-072017123010+022017123110+012018010110+002018021101+052018021511+012018021611+002018021711-012018021811-022018021911-032018022011-042018022111-052018022401-082018040512+002018040612-012018040712-022018040802-032018042803+032018042913+022018043013+012018050113+002018061614+022018061714+012018061814+002018092215+022018092315+012018092415+002018092906+022018093006+012018100116+002018100216-012018100316-022018100416-032018100516-042018100616-052018100716-062018122900+032018123010+022018123110+012019010110+002019020201+032019020301+022019020411+012019020511+002019020611-012019020711-022019020811-032019020911-042019021011-052019040512+002019040612-012019040712-022019042803+032019050113+002019050213-012019050313-022019050413-032019050503-042019060714+002019060814-012019060914-022019091315+002019091415-012019091515-022019092906+022019100116+002019100216-012019100316-022019100416-032019100516-042019100616-052019100716-062019101206-112020010110+002020011901+062020012411+012020012511+002020012611-012020012711-022020012811-032020012911-042020013011-052020013111-062020020111-072020020211-082020040412+002020040512-012020040612-022020042603+052020050113+002020050213-012020050313-022020050413-032020050513-042020050903-082020062514+002020062614-012020062714-022020062804-032020092707+042020100117+002020100216-012020100316-022020100416-032020100516-042020100616-052020100716-062020100816-072020101006-092021010110+002021010210-012021010310-022021020701+052021021111+012021021211+002021021311-012021021411-022021021511-032021021611-042021021711-052021022001-082021040312+012021040412+002021040512-012021042503+062021050113+002021050213-012021050313-022021050413-032021050513-042021050803-072021061214+022021061314+012021061414+002021091805+032021091915+022021092015+012021092115+002021092606+052021100116+002021100216-012021100316-022021100416-032021100516-042021100616-052021100716-062021100906-082022010110+002022010210-012022010310-022022012901+032022013001+022022013111+012022020111+002022020211-012022020311-022022020411-032022020511-042022020611-052022040202+032022040312+022022040412+012022040512+002022042403+072022043013+012022050113+002022050213-012022050313-022022050413-032022050703-062022060314+002022060414-012022060514-022022091015+002022091115-012022091215-022022100116+002022100216-012022100316-022022100416-032022100516-042022100616-052022100716-062022100806-072022100906-082022123110+012023010110+002023010210-012023012111+012023012211+002023012311-012023012411-022023012511-032023012611-042023012711-052023012801-062023012901-072023040512+002023042303+082023042913+022023043013+012023050113+002023050213-012023050313-022023050603-052023062214+002023062314-012023062414-022023062504-032023092915+002023093016+012023100116+002023100216-012023100316-022023100416-032023100516-042023100616-052023100706-062023100806-072023123010+022023123110+012024010110+002024020401+062024021011+002024021111-012024021211-022024021311-032024021411-042024021511-052024021611-062024021711-072024021801-082024040412+002024040512-012024040612-022024040702-032024042803+032024050113+002024050213-012024050313-022024050413-032024050513-042024051103-102024060814+022024060914+012024061014+002024091405+032024091515+022024091615+012024091715+002024092906+022024100116+002024100216-012024100316-022024100416-032024100516-042024100616-052024100716-062024101206-112025010110+002025012601+032025012811+012025012911+002025013011-012025013111-022025020111-032025020211-032025020311-042025020411-052025020801-092025040412+002025040512-012025040612-022025042703+042025050113+002025050213-012025050313-022025050413-032025050513-042025053114+002025060114-012025060214-022025092807+032025100117+002025100217-012025100317-022025100417-032025100517-042025100617-052025100717-062025100817-072025101107-102026010110+002026010210-012026010310-022026010400-032026021401+032026021511+022026021611+012026021711+002026021811-012026021911-022026022011-032026022111-042026022211-052026022311-062026022801-112026040412+012026040512+002026040612-012026050113+002026050213-012026050313-022026050413-032026050513-042026050903-082026061914+002026062014-012026062114-022026092006+112026092515+002026092615-012026092715-022026100116+002026100216-012026100316-022026100416-032026100516-042026100616-052026100716-062026101006-09";

    SolarDay LegalHoliday::compute_target(const string &data) const {
        const int offset = stoi(data.substr(data.length()-2));
        return day.next('-' == data[10] ? -offset : offset);
    }

    optional<LegalHoliday> LegalHoliday::from_ymd(const int year, const int month, const int day) {
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%04d%02d%02d", year, month, day);
        const string needle(buffer);
        size_t pos = 0;
        while ((pos = DATA.find(needle, pos)) != string::npos) {
            if (pos + 13 <= DATA.size()) {
                const string data = DATA.substr(pos, 13);
                if ((data[8] == '0' || data[8] == '1') &&
                    (data[9] >= '0' && data[9] <= '8') &&
                    (data[10] == '+' || data[10] == '-') &&
                    isdigit(data[11]) && isdigit(data[12])) {
                    return LegalHoliday(year, month, day, data);
                }
            }
            pos += needle.length();
        }
        return nullopt;
    }

    SolarDay LegalHoliday::get_day() const {
        return day;
    }

    SolarDay LegalHoliday::get_target() const {
        return target;
    }

    bool LegalHoliday::is_work() const {
        return work;
    }

    string LegalHoliday::get_name() const {
        return name;
    }

    string LegalHoliday::to_string() const {
        return day.to_string() + " " + name + "(" + (work ? "班" : "休") + ")";
    }

    static vector<string> find_year_entries(const string& data, int y) {
        char buf[5];
        snprintf(buf, sizeof(buf), "%04d", y);
        const string year_str(buf);
        vector<string> result;
        size_t pos = 0;
        while ((pos = data.find(year_str, pos)) != string::npos) {
            if (pos + 13 <= data.size()) {
                const string entry = data.substr(pos, 13);
                if ((entry[8] == '0' || entry[8] == '1') &&
                    (entry[9] >= '0' && entry[9] <= '8') &&
                    (entry[10] == '+' || entry[10] == '-') &&
                    isdigit(entry[11]) && isdigit(entry[12])) {
                    result.push_back(entry);
                }
            }
            pos += year_str.length();
        }
        return result;
    }

    optional<LegalHoliday> LegalHoliday::next(int n) const {
        int year = day.get_year();
        int month = day.get_month();
        if (n == 0) {
            return from_ymd(year, month, day.get_day()).value();
        }
        auto data = find_year_entries(DATA, year);
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%04d%02d%02d", year, month, day.get_day());
        auto today = string(buffer);
        int index = -1;
        int size = static_cast<int>(data.size());
        for (int i = 0; i < size; i++) {
            if (equal(today.begin(), today.end(), data[i].begin())) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return nullopt;
        }
        index += n;
        int y = year;
        if (n > 0) {
            while (index >= size) {
                index -= size;
                y += 1;
                data = find_year_entries(DATA, y);
                size = static_cast<int>(data.size());
                if (size < 1) {
                    return nullopt;
                }
            }
        } else {
            while (index < 0) {
                y -= 1;
                data = find_year_entries(DATA, y);
                size = static_cast<int>(data.size());
                if (size < 1) {
                    return nullopt;
                }
                index += size;
            }
        }
        string d = data[index];
        return LegalHoliday(stoi(d.substr(0, 4)), stoi(d.substr(4, 2)), stoi(d.substr(6, 2)), d);
    }
    int AbstractFestival::get_index() const {
        return index;
    }

    DayUnit AbstractFestival::get_day() const {
        return day;
    }

    string AbstractFestival::get_name() const {
        return event.get_name();
    }

    const vector<string> SolarFestival::NAMES = {
        "元旦", "妇女节", "植树节", "劳动节", "青年节", "儿童节", "建党节", "建军节", "教师节", "国庆节"
    };

    string SolarFestival::DATA = "0VV__0Ux0Xc__0Ux0Xg__0_Q0ZV__0Ux0ZY__0Ux0aV__0Ux0bV__0Uo0cV__0Ug0de__0_V0eV__0Ux";

    optional<SolarFestival> SolarFestival::from_index(const int year, const int index) {
        if (index < 0 || static_cast<size_t>(index) >= NAMES.size()) {
            return nullopt;
        }
        const int start = index * 8;
        const auto e = Event(NAMES[index], "@" + DATA.substr(start, 8));
        if (year < e.get_start_year()) {
            return nullopt;
        }
        return SolarFestival(index, e, SolarDay::from_ymd(year, e.get_value(2), e.get_value(3)));
    }

    optional<SolarFestival> SolarFestival::from_ymd(const int year, const int month, const int day) {
        const SolarDay d = SolarDay::from_ymd(year, month, day);
        const int size = static_cast<int>(NAMES.size());
        for (int i = 0; i < size; i++) {
            const int start = i * 8;
            if (const auto e = Event(NAMES[i], "@" + DATA.substr(start, 8)); d.get_year() >= e.get_start_year() && d.get_month() == e.get_value(2) && d.get_day() == e.get_value(3)) {
                return SolarFestival(i, e, d);
            }
        }
        return nullopt;
    }

    optional<SolarFestival> SolarFestival::next(const int n) const {
        const int size = static_cast<int>(NAMES.size());
        const int i = index + n;
        return from_index((day.get_year() * size + i) / size, index_of(i, size));
    }

    SolarDay SolarFestival::get_day() const {
        return SolarDay::from_ymd(day.get_year(), day.get_month(), day.get_day());
    }

    int SolarFestival::get_start_year() const {
        return event.get_start_year();
    }

    string SolarFestival::to_string() const {
        return get_day().to_string() + " " + get_name();
    }

    const vector<string> LunarFestival::NAMES = {
        "春节", "元宵节", "龙头节", "上巳节", "清明节", "端午节", "七夕节", "中元节", "中秋节", "重阳节", "冬至节", "腊八节", "除夕"
    };

    string LunarFestival::DATA = "2VV__0002Vj__0002WW__0002XX__0003b___0002ZZ__0002bb__0002bj__0002cj__0002dd__0003s___0002gc__0002hV_U000";

    optional<LunarFestival> LunarFestival::from_index(const int year, const int index) {
        if (index < 0 || static_cast<size_t>(index) >= NAMES.size()) {
            return nullopt;
        }
        const int start = index * 8;
        const auto e = Event(NAMES[index], "@" + DATA.substr(start, 8));
        const EventType t = e.get_type();
        if (t == EventType::LUNAR_DAY) {
            const array<int, 2> m = e.get_month(year);
            const LunarDay d = LunarDay::from_ymd(m[0], m[1], e.get_value(3));
            const int offset = e.get_value(5);
            return LunarFestival(index, e, 0 == offset ? d : d.next(offset));
        }
        if (t == EventType::TERM_DAY) {
            return LunarFestival(index, e, SolarTerm::from_index(year, e.get_value(2)).get_solar_day().get_lunar_day());
        }
        return nullopt;
    }

    optional<LunarFestival> LunarFestival::from_ymd(int year, int month, int day) {
        const LunarDay d = LunarDay::from_ymd(year, month, day);
        const int size = static_cast<int>(NAMES.size());
        for (int i = 0; i < size; i++) {
            const int start = i * 8;
            const auto e = Event(NAMES[i], "@" + DATA.substr(start, 8));
            const EventType t = e.get_type();
            if (t == EventType::LUNAR_DAY) {
                if (const int offset = e.get_value(5); 0 == offset) {
                    if (d.get_month() == e.get_value(2) && d.get_day() == e.get_value(3)) {
                        return LunarFestival(i, e, d);
                    }
                } else {
                    array<int, 2> m = e.get_month(d.get_year());
                    if (LunarDay next = d.next(-offset); next.get_year() == m[0] && next.get_month() == m[1] && next.get_day() == e.get_value(3)) {
                        return LunarFestival(i, e, d);
                    }
                }
            }
            if (t == EventType::TERM_DAY) {
                if (SolarTermDay term = d.get_solar_day().get_term_day(); term.get_day_index() == 0 && term.get_solar_term().get_index() == e.get_value(2) % 24) {
                    return LunarFestival(i, e, d);
                }
            }
        }
        return nullopt;
    }

    optional<LunarFestival> LunarFestival::next(const int n) const {
        const int size = static_cast<int>(NAMES.size());
        const int i = index + n;
        return from_index((day.get_year() * size + i) / size, index_of(i, size));
    }

    LunarDay LunarFestival::get_day() const {
        return LunarDay::from_ymd(day.get_year(), day.get_month(), day.get_day());
    }

    optional<SolarTerm> LunarFestival::get_solar_term() const {
        if (const SolarTermDay t = get_day().get_solar_day().get_term_day(); t.get_day_index() == 0) {
            return t.get_solar_term();
        }
        return nullopt;
    }

    string LunarFestival::to_string() const {
        return get_day().to_string() + " " + get_name();
    }
    int Event::get_char_index(const int index) const {
        return static_cast<int>(EventManager::CHARS.find(data[index]));
    }

    int Event::get_value(const int index) const {
        return get_char_index(index) - 31;
    }

    array<int, 2> Event::get_month(const int year) const {
        int y = year;
        int m = get_value(2);
        if (m > 12) {
            m = 1;
            y += 1;
        }
        return {y, m};
    }

    void Event::validate(const string &data) {
        if (data.empty()) {
            throw invalid_argument("illegal event data: empty");
        }
        if (data.length() != 9) {
            throw invalid_argument("illegal event data: " + data);
        }
    }

    EventBuilder Event::builder() {
        return {};
    }

    optional<Event> Event::from_name(const string &name) {
        size_t pos = EventManager::DATA.find(name);
        while (pos != string::npos) {
            if (pos >= 9 && EventManager::DATA[pos - 9] == '@') {
                const string code = EventManager::DATA.substr(pos - 9, 9);
                bool valid = true;
                for (int i = 1; i < 9 && valid; ++i) {
                    char c = code[i];
                    if (!isalnum(c) && c != '_') valid = false;
                }
                if (valid) {
                    return Event(name, code);
                }
            }
            pos = EventManager::DATA.find(name, pos + 1);
        }
        return nullopt;
    }

    vector<Event> Event::from_solar_day(const SolarDay &d) {
        vector<Event> l;
        for (const auto &e: all()) {
            if (auto t = e.get_solar_day(d.get_year()); t && d.equals(t.value())) {
                l.push_back(e);
            }
        }
        return l;
    }

    vector<Event> Event::all() {
        vector<Event> l;
        const string& data = EventManager::DATA;
        size_t pos = 0;
        while ((pos = data.find('@', pos)) != string::npos) {
            if (pos + 9 <= data.size()) {
                const string code = data.substr(pos, 9);
                bool valid = true;
                for (int i = 1; i < 9 && valid; ++i) {
                    char c = code[i];
                    if (!isalnum(c) && c != '_') valid = false;
                }
                if (valid) {
                    size_t name_start = pos + 9;
                    size_t name_end = data.find('@', name_start);
                    const string name = data.substr(name_start, name_end == string::npos ? string::npos : name_end - name_start);
                    if (!name.empty()) {
                        l.emplace_back(name, code);
                    }
                }
            }
            pos += 9;
        }
        return l;
    }

    EventType Event::get_type() const {
        switch (get_char_index(1)) {
            case 1:
                return EventType::SOLAR_WEEK;
            case 2:
                return EventType::LUNAR_DAY;
            case 3:
                return EventType::TERM_DAY;
            case 4:
                return EventType::TERM_HS;
            case 5:
                return EventType::TERM_EB;
            default: ;
        }
        return EventType::SOLAR_DAY;
    }

    string Event::get_name() const {
        return name;
    }

    string Event::get_data() const {
        return data;
    }

    int Event::get_start_year() const {
        int n = 0;
        const int size = static_cast<int>(EventManager::CHARS.length());
        for (int i = 0; i < 3; ++i) {
            n = n * size + get_char_index(6 + i);
        }
        return n;
    }

    optional<SolarDay> Event::get_solar_day(int year) const {
        if (year < get_start_year()) {
            return nullopt;
        }
        optional<SolarDay> d;
        switch (get_type()) {
            case EventType::SOLAR_DAY:
                d = get_solar_day_by_solar_day(year);
                break;
            case EventType::SOLAR_WEEK:
                d = get_solar_day_by_week(year);
                break;
            case EventType::LUNAR_DAY:
                d = get_solar_day_by_lunar_day(year);
                break;
            case EventType::TERM_DAY:
                d = get_solar_day_by_term(year);
                break;
            case EventType::TERM_HS:
                d = get_solar_day_by_term_heaven_stem(year);
                break;
            case EventType::TERM_EB:
                d = get_solar_day_by_term_earth_branch(year);
                break;
        }
        if (!d) {
            return nullopt;
        }
        const int offset = get_value(5);
        return offset == 0 ? d : d->next(offset);
    }

    optional<SolarDay> Event::get_solar_day_by_solar_day(const int year) const {
        const array<int, 2> month = get_month(year);
        const int y = month[0];
        const int m = month[1];
        const int d = get_value(3);
        const int delay = get_value(4);
        if (const int last_day = SolarMonth::from_ym(y, m).get_day_count(); d > last_day) {
            if (delay == 0) {
                return nullopt;
            }
            if (delay < 0) {
                return SolarDay::from_ymd(y, m, d + delay);
            }
            return SolarDay::from_ymd(y, m, last_day).next(delay);
        }
        return SolarDay::from_ymd(y, m, d);
    }

    optional<SolarDay> Event::get_solar_day_by_lunar_day(const int year) const {
        const array<int, 2> month = get_month(year);
        const int y = month[0];
        const int m = month[1];
        const int d = get_value(3);
        const int delay = get_value(4);
        if (const int last_day = LunarMonth::from_ym(y, m).get_day_count(); d > last_day) {
            if (delay == 0) {
                return nullopt;
            }
            if (delay < 0) {
                return LunarDay::from_ymd(y, m, d + delay).get_solar_day();
            }
            return LunarDay::from_ymd(y, m, last_day).get_solar_day().next(delay);
        }
        return LunarDay::from_ymd(y, m, d).get_solar_day();
    }

    optional<SolarDay> Event::get_solar_day_by_week(const int year) const {
        // 第几个星期
        const int n = get_value(3);
        if (n == 0) {
            return nullopt;
        }
        const SolarMonth m = SolarMonth::from_ym(year, get_value(2));
        // 星期几
        const int w = get_value(4);
        if (n > 0) {
            const SolarDay d = m.get_first_day();
            return d.next(d.get_week().steps_to(w) + 7 * n - 7);
        }
        const SolarDay d = SolarDay::from_ymd(year, m.get_month(), m.get_day_count());
        return d.next(d.get_week().steps_back_to(w) + 7 * n + 7);
    }

    optional<SolarDay> Event::get_solar_day_by_term(const int year) const {
        const SolarDay d = SolarTerm::from_index(year, get_value(2)).get_solar_day();
        const int offset = get_value(4);
        return offset == 0 ? d : d.next(offset);
    }

    optional<SolarDay> Event::get_solar_day_by_term_heaven_stem(const int year) const {
        const auto d = get_solar_day_by_term(year);
        if (!d) return nullopt;
        return d->next(d->get_lunar_day().get_sixty_cycle().get_heaven_stem().steps_to(get_value(3)));
    }

    optional<SolarDay> Event::get_solar_day_by_term_earth_branch(const int year) const {
        const auto d = get_solar_day_by_term(year);
        if (!d) return nullopt;
        return d->next(d->get_lunar_day().get_sixty_cycle().get_earth_branch().steps_to(get_value(3)));
    }

    EventBuilder EventBuilder::name(const string &name) {
        this->_name = name;
        return *this;
    }

    char EventBuilder::get_char(const int index) {
        return EventManager::CHARS[index];
    }

    EventBuilder &EventBuilder::set_value(const int index, const int n) {
        data[index] = EventManager::CHARS[31 + n];
        return *this;
    }

    char EventBuilder::encode_type(const EventType &type) {
        int i = 0;
        switch (type) {
            case EventType::SOLAR_WEEK:
                i = 1;
                break;
            case EventType::LUNAR_DAY:
                i = 2;
                break;
            case EventType::TERM_DAY:
                i = 3;
                break;
            case EventType::TERM_HS:
                i = 4;
                break;
            case EventType::TERM_EB:
                i = 5;
                break;
            default: ;
        }
        return get_char(i);
    }

    EventBuilder &EventBuilder::content(const EventType type, const int a, const int b, const int c) {
        data[1] = encode_type(type);
        return set_value(2, a).set_value(3, b).set_value(4, c);
    }

    EventBuilder EventBuilder::solar_day(const int solar_month, const int solar_day, const int delay_days) {
        return content(EventType::SOLAR_DAY, solar_month, solar_day, delay_days);
    }

    EventBuilder EventBuilder::lunar_day(const int lunar_month, const int lunar_day, const int delay_days) {
        return content(EventType::LUNAR_DAY, lunar_month, lunar_day, delay_days);
    }

    EventBuilder EventBuilder::solar_week(const int solar_month, const int week_index, const int week) {
        return content(EventType::SOLAR_WEEK, solar_month, week_index, week);
    }

    EventBuilder EventBuilder::term_day(const int term_index, const int delay_days) {
        return content(EventType::TERM_DAY, term_index, 0, delay_days);
    }

    EventBuilder EventBuilder::term_heaven_stem(const int term_index, const int heaven_stem_index,
                                                 const int delay_days) {
        return content(EventType::TERM_HS, term_index, heaven_stem_index, delay_days);
    }

    EventBuilder EventBuilder::term_earth_branch(const int term_index, const int earth_branch_index,
                                                  const int delay_days) {
        return content(EventType::TERM_EB, term_index, earth_branch_index, delay_days);
    }

    EventBuilder EventBuilder::start_year(const int year) {
        const int size = static_cast<int>(EventManager::CHARS.length());
        int n = year;
        for (int i = 0; i < 3; ++i) {
            data[8 - i] = get_char(n % size);
            n /= size;
        }
        return *this;
    }

    EventBuilder EventBuilder::offset(const int days) {
        return set_value(5, days);
    }

    Event EventBuilder::build() const {
        return Event(_name, string(data.data(), data.size()));
    }

    const string EventManager::CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTU_VWXYZabcdefghijklmnopqrstuvwxyz";
    const string EventManager::REGEX = "(@[0-9A-Za-z_]{8})";
    string EventManager::DATA;

    void EventManager::remove(const string &name) {
        size_t pos = DATA.find(name);
        while (pos != string::npos) {
            if (pos >= 9 && DATA[pos - 9] == '@') {
                const string code = DATA.substr(pos - 9, 9);
                bool valid = true;
                for (int i = 1; i < 9 && valid; ++i) {
                    char c = code[i];
                    if (!isalnum(c) && c != '_') valid = false;
                }
                if (valid) {
                    DATA.erase(pos - 9, 9 + name.length());
                    return;
                }
            }
            pos = DATA.find(name, pos + 1);
        }
    }

    void EventManager::save_or_update(const string &name, const string &data) {
        size_t pos = DATA.find(name);
        while (pos != string::npos) {
            if (pos >= 9 && DATA[pos - 9] == '@') {
                const string code = DATA.substr(pos - 9, 9);
                bool valid = true;
                for (int i = 1; i < 9 && valid; ++i) {
                    char c = code[i];
                    if (!isalnum(c) && c != '_') valid = false;
                }
                if (valid) {
                    DATA.replace(pos - 9, 9 + name.length(), data);
                    return;
                }
            }
            pos = DATA.find(name, pos + 1);
        }
        DATA += data;
    }

    void EventManager::update(const string &name, const Event &event) {
        const string data = event.get_data() + (event.get_name().empty() ? name : event.get_name());
        save_or_update(name, data);
    }

    void EventManager::update_data(const string &name, const string &data) {
        Event::validate(data);
        save_or_update(name, data);
    }
}
