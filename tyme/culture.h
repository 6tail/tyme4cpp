#ifndef TYME_CULTURE_H
#define TYME_CULTURE_H
#include "base.h"

namespace tyme {
    /**
     * @brief 二十八宿
     */
    class TwentyEightStar;

    /**
     * @brief 动物
     */
    class Animal : public LoopTyme {
    public:
        ~Animal() override = default;

        static const vector<string> NAMES;

        explicit Animal(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Animal(const string &name) : LoopTyme(NAMES, name) {
        }

        static Animal from_index(int index);

        static Animal from_name(const string &name);

        Animal next(int n) const;

        /**
         * @brief 二十八宿
         * @return 二十八宿
         */
        TwentyEightStar get_twenty_eight_star() const;
    };

    /**
     * @brief 星座
     */
    class Constellation : public LoopTyme {
    public:
        ~Constellation() override = default;

        static const vector<string> NAMES;

        explicit Constellation(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Constellation(const string &name) : LoopTyme(NAMES, name) {
        }

        static Constellation from_index(int index);

        static Constellation from_name(const string &name);

        Constellation next(int n) const;
    };

    /**
     * @brief 方位
     */
    class Direction;

    /**
     * @brief 五行
     */
    class Element : public LoopTyme {
    public:
        ~Element() override = default;

        static const vector<string> NAMES;

        explicit Element(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Element(const string &name) : LoopTyme(NAMES, name) {
        }

        explicit Element(const vector<string> &names, const int index) : LoopTyme(names, index) {
        }

        explicit Element(const vector<string> &names, const string &name) : LoopTyme(names, name) {
        }

        static Element from_index(int index);

        static Element from_name(const string &name);

        Element next(int n) const;

        bool equals(const Element &other) const;

        /**
         * @brief 我生者
         * @return 五行
         */
        Element get_reinforce() const;

        /**
         * @brief 我克者
         * @return 五行
         */
        Element get_restrain() const;

        /**
         * @brief 生我者
         * @return 五行
         */
        Element get_reinforced() const;

        /**
         * @brief 克我者
         * @return 五行
         */
        Element get_restrained() const;

        /**
         * @brief 方位
         * @return 方位
         */
        Direction get_direction() const;
    };

    /**
     * @brief 九野
     */
    class Land : public LoopTyme {
    public:
        ~Land() override = default;

        static const vector<string> NAMES;

        explicit Land(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Land(const string &name) : LoopTyme(NAMES, name) {
        }

        static Land from_index(int index);

        static Land from_name(const string &name);

        Land next(int n) const;

        /**
         * 方位
         * @return 方位
         */
        Direction get_direction() const;
    };

    /**
     * @brief 方位
     */
    class Direction : public LoopTyme {
    public:
        ~Direction() override = default;

        static const vector<string> NAMES;

        explicit Direction(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Direction(const string &name) : LoopTyme(NAMES, name) {
        }

        static Direction from_index(int index);

        static Direction from_name(const string &name);

        Direction next(int n) const;

        /**
         * @brief 九野
         * @return 九野
         */
        Land get_land() const;

        /**
         * @brief 五行
         * @return 五行
         */
        Element get_element() const;
    };

    /**
     * @brief 建除十二值神
     */
    class Duty : public LoopTyme {
    public:
        ~Duty() override = default;

        static const vector<string> NAMES;

        explicit Duty(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Duty(const string &name) : LoopTyme(NAMES, name) {
        }

        static Duty from_index(int index);

        static Duty from_name(const string &name);

        Duty next(int n) const;
    };

    /**
     * @brief 吉凶
     */
    class Luck : public LoopTyme {
    public:
        ~Luck() override = default;

        static const vector<string> NAMES;

        explicit Luck(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Luck(const string &name) : LoopTyme(NAMES, name) {
        }

        static Luck from_index(int index);

        static Luck from_name(const string &name);

        Luck next(int n) const;
    };

    /**
     * @brief 元（60年=1元）
     */
    class Sixty : public LoopTyme {
    public:
        ~Sixty() override = default;

        static const vector<string> NAMES;

        explicit Sixty(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Sixty(const string &name) : LoopTyme(NAMES, name) {
        }

        static Sixty from_index(int index);

        static Sixty from_name(const string &name);

        Sixty next(int n) const;
    };

    /**
     * @brief 纳音
     */
    class Sound : public LoopTyme {
    public:
        ~Sound() override = default;

        static const vector<string> NAMES;

        explicit Sound(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Sound(const string &name) : LoopTyme(NAMES, name) {
        }

        static Sound from_index(int index);

        static Sound from_name(const string &name);

        Sound next(int n) const;
    };

    /**
     * @brief 旬
     */
    class Ten : public LoopTyme {
    public:
        ~Ten() override = default;

        static const vector<string> NAMES;

        explicit Ten(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Ten(const string &name) : LoopTyme(NAMES, name) {
        }

        static Ten from_index(int index);

        static Ten from_name(const string &name);

        Ten next(int n) const;
    };

    /**
     * @brief 地势(长生十二神)
     */
    class Terrain : public LoopTyme {
    public:
        ~Terrain() override = default;

        static const vector<string> NAMES;

        explicit Terrain(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Terrain(const string &name) : LoopTyme(NAMES, name) {
        }

        static Terrain from_index(int index);

        static Terrain from_name(const string &name);

        Terrain next(int n) const;
    };

    /**
     * @brief 运（20年=1运，3运=1元）
     */
    class Twenty : public LoopTyme {
    public:
        ~Twenty() override = default;

        static const vector<string> NAMES;

        explicit Twenty(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Twenty(const string &name) : LoopTyme(NAMES, name) {
        }

        static Twenty from_index(int index);

        static Twenty from_name(const string &name);

        Twenty next(int n) const;

        /**
         * @brief 元
         */
        Sixty get_sixty() const;
    };

    /**
     * @brief 七曜（七政、七纬、七耀）
     */
    class SevenStar;

    /**
     * @brief 星期
     */
    class Week : public LoopTyme {
    public:
        ~Week() override = default;

        static const vector<string> NAMES;

        explicit Week(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Week(const string &name) : LoopTyme(NAMES, name) {
        }

        static Week from_index(int index);

        static Week from_name(const string &name);

        Week next(int n) const;

        /**
         * @brief 七曜
         * @return 七曜
         */
        SevenStar get_seven_star() const;
    };

    /**
     * @brief 地支
     */
    class EarthBranch;

    /**
     * @brief 生肖
     */
    class Zodiac : public LoopTyme {
    public:
        ~Zodiac() override = default;

        static const vector<string> NAMES;

        explicit Zodiac(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Zodiac(const string &name) : LoopTyme(NAMES, name) {
        }

        static Zodiac from_index(int index);

        static Zodiac from_name(const string &name);

        Zodiac next(int n) const;

        bool equals(const Zodiac &other) const;

        /**
         * @brief 地支
         * @return 地支
         */
        EarthBranch get_earth_branch() const;
    };

    /**
     * @brief 神兽
     */
    class Beast;

    /**
     * @brief 宫
     */
    class Zone : public LoopTyme {
    public:
        ~Zone() override = default;

        static const vector<string> NAMES;

        explicit Zone(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Zone(const string &name) : LoopTyme(NAMES, name) {
        }

        static Zone from_index(int index);

        static Zone from_name(const string &name);

        Zone next(int n) const;

        /**
         * @brief 方位
         * @return 方位
         */
        Direction get_direction() const;

        /**
         * @brief 神兽
         * @return 神兽
         */
        Beast get_beast() const;
    };

    /**
     * @brief 神兽
     */
    class Beast : public LoopTyme {
    public:
        ~Beast() override = default;

        static const vector<string> NAMES;

        explicit Beast(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Beast(const string &name) : LoopTyme(NAMES, name) {
        }

        static Beast from_index(int index);

        static Beast from_name(const string &name);

        Beast next(int n) const;

        /**
         * @brief 宫
         * @return 宫
         */
        Zone get_zone() const;
    };
}
#endif
