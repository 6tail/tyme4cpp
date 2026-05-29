#ifndef TYME_STAR_H
#define TYME_STAR_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 北斗九星
     */
    class Dipper : public LoopTyme {
    public:
        ~Dipper() override = default;

        static const vector<string> NAMES;

        explicit Dipper(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Dipper(const string &name) : LoopTyme(NAMES, name) {
        }

        static Dipper from_index(int index);

        static Dipper from_name(const string &name);

        Dipper next(int n) const;
    };

    /**
     * @brief 九星
     */
    class NineStar : public LoopTyme {
    public:
        ~NineStar() override = default;

        static const vector<string> NAMES;

        static const vector<string> COLORS;

        explicit NineStar(const int index) : LoopTyme(NAMES, index) {
        }

        explicit NineStar(const string &name) : LoopTyme(NAMES, name) {
        }

        static NineStar from_index(int index);

        static NineStar from_name(const string &name);

        NineStar next(int n) const;

        /**
         * @brief 颜色
         * @return 颜色
         */
        string get_color() const;

        /**
         * @brief 五行
         * @return 五行
         */
        Element get_element() const;

        /**
         * @brief 北斗九星
         * @return 北斗九星
         */
        Dipper get_dipper() const;

        /**
         * @brief 方位
         * @return 方位
         */
        Direction get_direction() const;

        string to_string() const override;
    };

    /**
     * @brief 七曜（七政、七纬、七耀）
     */
    class SevenStar : public LoopTyme {
    public:
        ~SevenStar() override = default;

        static const vector<string> NAMES;

        explicit SevenStar(const int index) : LoopTyme(NAMES, index) {
        }

        explicit SevenStar(const string &name) : LoopTyme(NAMES, name) {
        }

        static SevenStar from_index(int index);

        static SevenStar from_name(const string &name);

        SevenStar next(int n) const;

        /**
         * @brief 星期
         * @return 星期
         */
        Week get_week() const;
    };

    /**
     * @brief 六曜（孔明六曜星）
     */
    class SixStar : public LoopTyme {
    public:
        ~SixStar() override = default;

        static const vector<string> NAMES;

        explicit SixStar(const int index) : LoopTyme(NAMES, index) {
        }

        explicit SixStar(const string &name) : LoopTyme(NAMES, name) {
        }

        static SixStar from_index(int index);

        static SixStar from_name(const string &name);

        SixStar next(int n) const;
    };

    /**
     * @brief 十神
     */
    class TenStar : public LoopTyme {
    public:
        ~TenStar() override = default;

        static const vector<string> NAMES;

        explicit TenStar(const int index) : LoopTyme(NAMES, index) {
        }

        explicit TenStar(const string &name) : LoopTyme(NAMES, name) {
        }

        static TenStar from_index(int index);

        static TenStar from_name(const string &name);

        TenStar next(int n) const;
    };

    /**
     * @brief 黄道黑道
     */
    class Ecliptic : public LoopTyme {
    public:
        ~Ecliptic() override = default;

        static const vector<string> NAMES;

        explicit Ecliptic(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Ecliptic(const string &name) : LoopTyme(NAMES, name) {
        }

        static Ecliptic from_index(int index);

        static Ecliptic from_name(const string &name);

        Ecliptic next(int n) const;

        /**
         * @brief 吉凶
         * @return 吉凶
         */
        Luck get_luck() const;
    };

    /**
    * @brief 黄道黑道十二神
    */
    class TwelveStar : public LoopTyme {
    public:
        ~TwelveStar() override = default;

        static const vector<string> NAMES;

        explicit TwelveStar(const int index) : LoopTyme(NAMES, index) {
        }

        explicit TwelveStar(const string &name) : LoopTyme(NAMES, name) {
        }

        static TwelveStar from_index(int index);

        static TwelveStar from_name(const string &name);

        TwelveStar next(int n) const;

        /**
         * @brief 黄道黑道
         * @return 黄道黑道
         */
        Ecliptic get_ecliptic() const;
    };

    /**
     * @brief 二十八宿
     */
    class TwentyEightStar : public LoopTyme {
    public:
        ~TwentyEightStar() override = default;

        static const vector<string> NAMES;

        explicit TwentyEightStar(const int index) : LoopTyme(NAMES, index) {
        }

        explicit TwentyEightStar(const string &name) : LoopTyme(NAMES, name) {
        }

        static TwentyEightStar from_index(int index);

        static TwentyEightStar from_name(const string &name);

        TwentyEightStar next(int n) const;

        /**
         * @brief 七曜
         * @return 七曜
         */
        SevenStar get_seven_star() const;

        /**
         * @brief 九野
         * @return 九野
         */
        Land get_land() const;

        /**
         * @brief 宫
         * @return 宫
         */
        Zone get_zone() const;

        /**
         * @brief 动物
         * @return 动物
         */
        Animal get_animal() const;

        /**
         * @brief 吉凶
         * @return 吉凶
         */
        Luck get_luck() const;
    };
}
#endif
