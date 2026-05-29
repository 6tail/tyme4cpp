#ifndef TYME_LUNAR_H
#define TYME_LUNAR_H
#include "solar.h"

namespace tyme {
    class KitchenGodSteed;
    class FetusDay;
    class LunarFestival;
    class ThreePillars;

    /**
     * @brief 农历季节
     */
    class LunarSeason : public LoopTyme {
    public:
        ~LunarSeason() override = default;

        static const vector<string> NAMES;

        explicit LunarSeason(const int index) : LoopTyme(NAMES, index) {
        }

        explicit LunarSeason(const string &name) : LoopTyme(NAMES, name) {
        }

        LunarSeason(const LunarSeason &other) = default;

        static LunarSeason from_index(int index);

        static LunarSeason from_name(const string &name);

        LunarSeason next(int n) const;
    };

    /**
     * @brief 逐月胎神
     */
    class FetusMonth;

    /**
     * @brief 农历月
     */
    class LunarMonth;

    /**
     * @brief 农历周
     */
    class LunarWeek;

    /**
     * @brief 农历日
     */
    class LunarDay;

    /**
     * @brief 农历年
     */
    class LunarYear : public YearUnit {
    public:
        ~LunarYear() override = default;

        static vector<vector<int> > LEAP;

        explicit LunarYear(const int year) : YearUnit(year) {
            static once_flag flag;
            call_once(flag, [] {
                string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_@";
                string months[] = {
                    "080b0r0j0j0j0C0j0j0C0j0j0j0C0j0C0j0C0F0j0V0V0V0u0j0j0C0j0j0j0j0V0C0j1v0u0C0V1v0C0b080u110u0C0j0C1v9K1v2z0j1vmZbl1veN3s1v0V0C2S1v0V0C2S2o0C0j1Z1c2S1v0j1c0j2z1v0j1c0j392H0b2_2S0C0V0j1c0j2z0C0C0j0j1c0j0N250j0C0j0b081n080b0C0C0C1c0j0N",
                    "0r1v1c1v0V0V0F0V0j0C0j0C0j0V0j0u1O0j0C0V0j0j0j0V0b080u0r0u080b0j0j0C0V0C0V0j0b080V0u080b0j0j0u0j1v0u080b1c0j080b0j0V0j0j0V0C0N1v0j1c0j0j1v2g1v420j1c0j2z1v0j1v5Q9z1v4l0j1vfn1v420j9z4l1v1v2S1c0j1v2S3s1v0V0C2S1v1v2S1c0j1v2S2_0b0j2_2z0j1c0j",
                    "0z0j0j0j0C0j0j0C0j0j0j0C0j0C0j0j0j0j0m0j0C0j0j0C0j0j0j0j0b0V0j0j0C0j0j0j0j0V0j0j0j0V0b0V0V0C0V0C0j0j0b080u110u0V0C0j0N0j0b080b080b0j0r0b0r0b0j0j0j0j0C0j0b0r0C0j0b0j0C0C0j0j0j0j0j0j0j0j0j0b110j0b0j0j0j0C0j0C0j0j0j0j0b080b080b0V080b080b0j0j0j0j0j0j0V0j0j0u1v0j0j0j0C0j0j0j0V0C0N1c0j0C0C0j0j0j1n080b0j0V0C0j0C0C2g0j1c0j0j1v2g1v0j0j1v7N0j1c0j3L0j0j1v5Q1Z5Q1v4lfn1v420j1v5Q1Z5Q1v4l1v2z1v",
                    "0H140r0N0r140r0u0r0V171c11140C0j0u110j0u0j1v0j0C0j0j0j0b080V0u080b0C1v0j0j0j0C0j0b080V0j0j0b080b0j0j0j0j0b080b0C080j0b080b0j0j0j0j0j0j0b080j0b080C0b080b080b080b0j0j0j0j080b0j0C0j0j0j0b0j0j080C0b0j0j0j0j0j0j0b08080b0j0C0j0j0j0b0j0j0K0b0j0C0j0j0j0b080b080j0C0b0j080b080b0j0j0j0j080b0j0b0r0j0j0j0b0j0C0r0b0j0j0j0j0j0j0j0b080j0b0r0C0j0b0j0j0j0r0b0j0C0j0j0j0u0r0b0C0j080b0j0j0j0j0j0j0j1c0j0b0j0j0j0C0j0j0j0j0j0j0j0b080j1c0u0j0j0j0C0j1c0j0u0j1c0j0j0j0j0j0j0j0j1c0j0u1v0j0j0V0j0j2g0j0j0j0C1v0C1G0j0j0V0C1Z1O0j0V0j0j2g1v0j0j0V0C2g5x1v4l1v421O7N0V0C4l1v2S1c0j1v2S2_",
                    "050b080C0j0j0j0C0j0j0C0j0j0j0C0j0C0j0C030j0j0j0j0j0j0j0j0j0C0j0b080u0V080b0j0j0V0j0j0j0j0j0j0j0j0j0V0N0j0C0C0j0j0j0j0j0j0j0j1c0j0u0j1v0j0j0j0j0j0b080b080j0j0j0b080b080b080b080b0j0j0j080b0j0b080j0j0j0j0b080b0j0j0r0b080b0b080j0j0j0j0b080b080j0b080j0b080b080b080b080b0j0j0r0b0j0b080j0j0j0j0b080b0j0j0C080b0b080j0j0j0j0j0j0j0b080u080j0j0b0j0j0j0C0j0b080j0j0j0j0b080b080b080b0C080b080b080b0j0j0j0j0j0j0b0C080j0j0b0j0j0j0C0j0b080j0j0C0b080b080j0b0j0j0C080b0j0j0j0j0j0j0b0j0j080C0b0j080b0j0j0j0j0j0j0j0C0j0j0j0b0j0j0C080b0j0j0j0j0j0j0b080b080b0K0b080b080b0j0j0j0j0j0j0j0C0j0j0u0j0j0V0j080b0j0C0j0j0j0b0j0r0C0b0j0j0j0j0j0j0j0j0j0C0j0b080b080b0j0C0C0j0C0j0j0j0u110u0j0j0j0j0j0j0j0j0C0j0j0u0j1c0j0j0j0j0j0j0j0j0V0C0u0j0C0C0V0C1Z0j0j0j0C0j0j0j1v0u0j1c0j0j0j0C0j0j2g0j1c1v0C1Z0V0j4l0j0V0j0j2g0j1v0j1v2S1c7N1v",
                    "0w0j1c0j0V0j0j0V0V0V0j0m0V0j0C1c140j0j0j0C0V0C0j1v0j0N0j0C0j0j0j0V0j0j1v0N0j0j0V0j0j0j0j0j0j080b0j0j0j0j0j0j0j080b0j0C0j0j0j0b0j0j080u080b0j0j0j0j0j0j0b080b080b080C0b0j080b080b0j0j0j0j080b0j0C0j0j0j0b0j0j080u080b0j0j0j0j0j0j0b080b080b080b0r0b0j080b080b0j0j0j0j080b0j0b0r0j0j0b080b0j0j080b0j080b0j080b080b0j0j0j0j0j0b080b0r0C0b080b0j0j0j0j080b0b080b080j0j0j0b080b080b080b0j0j0j0j080b0j0b080j0j0j0j0b080b0j0j0r0b080b0j0j0j0j0j0b080b080j0b0r0b080j0b080b0j0j0j0j080b0j0b080j0j0j0j0b080b0j080b0r0b0j080b080b0j0j0j0j0j0b080b0r0C0b080b0j0j0j0j0j0j0b080j0j0j0b080b080b080b0j0j0j0r0b0j0b080j0j0j0j0b080b0r0b0r0b0j080b080b0j0j0j0j0j0j0b0r0j0j0j0b0j0j0j0j080b0j0b080j0j0j0j0b080b080b0j0r0b0j080b0j0j0j0j0j0j0j0b0r0C0b0j0j0j0j0j0j0j080b0j0C0j0j0j0b0j0C0r0b0j0j0j0j0j0j0b080b080u0r0b0j080b0j0j0j0j0j0j0j0b0r0C0u0j0j0j0C0j080b0j0C0j0j0j0u110b0j0j0j0j0j0j0j0j0j0C0j0b080b0j0j0C0C0j0C0j0j0j0b0j1c0j080b0j0j0j0j0j0j0V0j0j0u0j1c0j0j0j0C0j0j2g0j0j0j0C0j0j0V0j0b080b1c0C0V0j0j2g0j0j0V0j0j1c0j1Z0j0j0C0C0j1v",
                    "160j0j0V0j1c0j0C0j0C0j1f0j0V0C0j0j0C0j0j0j1G080b080u0V080b0j0j0V0j1v0j0u0j1c0j0j0j0C0j0j0j0C0C0j1D0b0j080b0j0j0j0j0C0j0b0r0C0j0b0j0C0C0j0j0j0j0j0j0j0j0j0b0r0b0r0j0b0j0j0j0C0j0b0r0j0j0j0b080b080j0b0C0j080b080b0j0j0j0j0j0j0b0C080j0j0b0j0j0j0C0j0b080j0j0j0j0b080b080j0b0C0r0j0b0j0j0j0j0j0j0b0C080j0j0b0j0j0j0C0j0j0j0j0C0j0j0b080b0j0j0C080b0j0j0j0j0j0j0b080b080b080C0b080b080b080b0j0j0j0j0j0b080C0j0j0b080b0j0j0C080b0j0j0j0j0j0j0b080j0b0C080j0j0b0j0j0j0j0j0j0b080j0b080C0b080b080b080b0j0j0j0j080b0j0C0j0j0b080b0j0j0C080b0j0j0j0j0j0j0b080j0b080u080j0j0b0j0j0j0j0j0j0b080C0j0j0b080b0j0j0C0j0j080b0j0j0j0j0j0b080b0C0r0b080b0j0j0j0j0j0j0b080j0b080u080b080b080b0j0j0j0C0j0b080j0j0j0j0b0j0j0j0C0j0j080b0j0j0j0j0j0b080b0C0r0b080b0j0j0j0j0j0j0b080j0b0r0b080b080b080b0j0j0j0r0b0j0b0r0j0j0j0b0j0j0j0r0b0j080b0j0j0j0j0j0j0j0b0r0C0b0j0j0j0j0j0j0j0b080j0C0u080b080b0j0j0j0r0b0j0C0C0j0b0j110b0j080b0j0j0j0j0j0j0u0r0C0b0j0j0j0j0j0j0j0j0j0C0j0j0j0b0j1c0j0C0j0j0j0b0j0814080b080b0j0j0j0j0j0j1c0j0u0j0j0V0j0j0j0j0j0j0j0u110u0j0j0j",
                    "020b0r0C0j0j0j0C0j0j0V0j0j0j0j0j0C0j1f0j0C0j0V1G0j0j0j0j0V0C0j0C1v0u0j0j0j0V0j0j0C0j0j0j1v0N0C0V0j0j0j0K0C250b0C0V0j0j0V0j0j2g0C0V0j0j0C0j0j0b081v0N0j0j0V0V0j0j0u0j1c0j080b0j0j0j0j0j0j0V0j0j0u0j0j0V0j0j0j0C0j0b080b080V0b0j080b0j0j0j0j0j0j0j0b0r0C0j0b0j0j0j0C0j080b0j0j0j0j0j0j0u0r0C0u0j0j0j0j0j0j0b080j0C0j0b080b080b0j0C0j080b0j0j0j0j0j0j0b080b110b0j0j0j0j0j0j0j0j0j0b0r0j0j0j0b0j0j0j0r0b0j0b080j0j0j0j0b080b080b080b0r0b0j080b080b0j0j0j0j0j0j0b0r0C0b080b0j0j0j0j080b0j0b080j0j0j0j0b080b080b0j0j0j0r0b0j0j0j0j0j0j0b080b0j080C0b0j080b080b0j0j0j0j080b0j0b0r0C0b080b0j0j0j0j080b0j0j0j0j0j0b080b080b080b0j0j080b0r0b0j0j0j0j0j0j0b0j0j080C0b0j080b080b0j0j0j0j0j0b080C0j0j0b080b0j0j0C0j0b080j0j0j0j0b080b080b080b0C0C080b0j0j0j0j0j0j0b0C0C080b080b080b0j0j0j0j0j0j0b0C080j0j0b0j0j0j0C0j0b080j0b080j0j0b080b080b080b0C0r0b0j0j0j0j0j0j0b080b0r0b0r0b0j080b080b0j0j0j0j0j0j0b0r0C0j0b0j0j0j0j0j0j0b080j0C0j0b080j0b0j0j0K0b0j0C0j0j0j0b080b0j0K0b0j080b0j0j0j0j0j0j0V0j0j0b0j0j0j0C0j0j0j0j",
                    "0l0C0K0N0r0N0j0r1G0V0m0j0V1c0C0j0j0j0j1O0N110u0j0j0j0C0j0j0V0C0j0u110u0j0j0j0C0j0j0j0C0C0j250j1c2S1v1v0j5x2g0j1c0j0j1c2z0j1c0j0j1c0j0N1v0V0C1v0C0b0C0V0j0j0C0j0C1v0u0j0C0C0j0j0j0C0j0j0j0u110u0j0j0j0C0j0C0C0C0b080b0j0C0j080b0j0C0j0j0j0u110u0j0j0j0C0j0j0j0C0j0j0j0u0C0r0u0j0j0j0j0j0j0b0r0b0V080b080b0j0C0j0j0j0V0j0j0b0j0j0j0C0j0j0j0j0j0j0j0b080j0b0C0r0j0b0j0j0j0C0j0b0r0b0r0j0b080b080b0j0C0j0j0j0j0j0j0j0j0b0j0C0r0b0j0j0j0j0j0j0b080b080j0b0r0b0r0j0b0j0j0j0j080b0j0b0r0j0j0j0b080b080b0j0j0j0j080b0j0j0j0j0j0j0b0j0j0j0r0b0j0j0j0j0j0j0b080b080b080b0r0C0b080b0j0j0j0j0j0b080b0r0C0b080b080b080b0j0j0j0j080b0j0C0j0j0j0b0j0j0C080b0j0j0j0j0j0j0b080j0b0C080j0j0b0j0j0j0j0j0j0b0r0b080j0j0b080b080b0j0j0j0j0j0j0b080j0j0j0j0b0j0j0j0r0b0j0b080j0j0j0j0j0b080b080b0C0r0b0j0j0j0j0j0j0b080b080j0C0b0j080b080b0j0j0j0j0j0j",
                    "0a0j0j0j0j0C0j0j0C0j0C0C0j0j0j0j0j0j0j0m0C0j0j0j0j0u080j0j0j1n0j0j0j0j0C0j0j0j0V0j0j0j1c0u0j0C0V0j0j0V0j0j1v0N0C0V2o1v1O2S2o141v0j1v4l0j1c0j1v2S2o0C0u1v0j0C0C2S1v0j1c0j0j1v0N251c0j1v0b1c1v1n1v0j0j0V0j0j1v0N1v0C0V0j0j1v0b0C0j0j0V1c0j0u0j1c0j0j0j0j0j0j0j0j1c0j0u0j0j0V0j0j0j0j0j0j0b080u110u0j0j0j0j0j0j1c0j0b0j080b0j0C0j0j0j0V0j0j0u0C0V0j0j0j0C0j0b080j1c0j0b0j0j0j0C0j0C0j0j0j0b080b080b0j0C0j080b0j0j0j0j0j0j0j0b0C0r0u0j0j0j0j0j0j0b080j0b0r0C0j0b0j0j0j0r0b0j0b0r0j0j0j0b080b080b0j0r0b0j080b0j0j0j0j0j0j0b0j0r0C0b0j0j0j0j0j0j0b080j0j0C0j0j0b080b0j0j0j0j0j0j0j0j0j0j0b080b080b080b0C0j0j080b0j0j0j0j0j0j0b0j0j0C080b0j0j0j0j0j0j0j0j0b0C080j0j0b0j0j0j0j0j",
                    "0n0Q0j1c14010q0V1c171k0u0r140V0j0j1c0C0N1O0j0V0j0j0j1c0j0u110u0C0j0C0V0C0j0j0b671v0j1v5Q1O2S2o2S1v4l1v0j1v2S2o0C1Z0j0C0C1O141v0j1c0j2z1O0j0V0j0j1v0b2H390j1c0j0V0C2z0j1c0j1v2g0C0V0j1O0b0j0j0V0C1c0j0u0j1c0j0j0j0j0j0j0j0j1c0N0j0j0V0j0j0C0j0j0b081v0u0j0j0j0C0j1c0N0j0j0C0j0j0j0C0j0j0j0u0C0r0u0j0j0j0C0j0b080j1c0j0b0j0C0C0j0C0C0j0b080b080u0C0j080b0j0C0j0j0j0u110u0j0j0j0j0j0j0j0j0C0C0j0b0j0j0j0C0j0C0C0j0b080b080b0j0C0j080b0j0C0j0j0j0b0j110b0j0j0j0j0j",
                    "0B0j0V0j0j0C0j0j0j0C0j0C0j0j0C0j0m0j0j0j0j0C0j0C0j0j0u0j1c0j0j0C0C0j0j0j0j0j0j0j0j0u110N0j0j0V0C0V0j0b081n080b0CrU1O5e2SbX2_1Z0V2o141v0j0C0C0j2z1v0j1c0j7N1O420j1c0j1v2S1c0j1v2S2_0b0j0V0j0j1v0N1v0j0j1c0j1v140j0V0j0j0C0C0b080u1v0C0V0u110u0j0j0j0C0j0j0j0C0C0N0C0V0j0j0C0j0j0b080u110u0C0j0C0u0r0C0u080b0j0j0C0j0j0j"
                };
                for (const string &m: months) {
                    int n = 0;
                    const int size = static_cast<int>(m.length()) / 2;
                    vector<int> l;
                    for (int y = 0; y < size; y++) {
                        const int z = y * 2;
                        int t = 0;
                        int c = 1;
                        for (int x = 1; x > -1; x--) {
                            t += c * static_cast<int>(chars.find(m.substr(z + x, 1)));
                            c *= 64;
                        }
                        n += t;
                        l.push_back(n);
                    }
                    LEAP.push_back(l);
                }
            });
            validate(year);
        }

        LunarYear(const LunarYear &other) : YearUnit(other.year) {
        }

        LunarYear &operator=(const LunarYear &other);

        static void validate(int year);

        static LunarYear from_year(int year);

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        /**
         * @brief 天数
         * @return 天数
         */
        int get_day_count() const;

        /**
         * @brief 月数
         * @return 月数
         */
        int get_month_count() const;

        string get_name() const override;

        LunarYear next(int n) const;

        /**
         * @brief 运
         * @return 运
         */
        Twenty get_twenty() const;

        /**
         * @brief 九星
         * @return 九星
         */
        NineStar get_nine_star() const;

        /**
         * @brief 太岁方位
         * @return 方位
         */
        Direction get_jupiter_direction() const;

        /**
         * @brief 闰月
         * @return 闰月数字，1代表闰1月，0代表无闰月
         */
        int get_leap_month() const;

        /**
         * @brief 灶马头
         * @return 灶马头
         */
        KitchenGodSteed get_kitchen_god_steed() const;

        /**
         * @brief 首月（农历月，即一月，俗称正月）
         * @return 农历月
         */
        LunarMonth get_first_month() const;

        /**
         * @brief 农历月列表
         * @return 农历月列表
         */
        vector<LunarMonth> get_months() const;
    };

    /**
     * @brief 农历月
     */
    class LunarMonth : public MonthUnit {
    public:
        ~LunarMonth() override = default;

        static const vector<string> NAMES;

        LunarMonth(const LunarMonth &other): MonthUnit(other.year, other.month), leap(other.leap) {
        }

        LunarMonth &operator=(const LunarMonth &other);

        explicit LunarMonth(const int year, const int month) : MonthUnit(year, abs(month)), leap(month < 0) {
            validate(year, month);
        }

        static void validate(int year, int month);

        static LunarMonth from_ym(int year, int month);

        /**
         * @brief 农历年
         * @return 农历年
         */
        LunarYear get_lunar_year() const;

        /**
         * @brief 月
         * @return 月，当月为闰月时，返回负数
         */
        int get_month_with_leap() const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        /**
         * @brief 天数
         * @return 天数
         */
        int get_day_count() const;

        /**
         * @brief 位于当年的索引(0-12)
         * @return 索引
         */
        int get_index_in_year() const;

        string get_name() const override;

        string to_string() const override;

        LunarMonth next(int n) const;

        /**
         * @brief 农历季节
         * @return 农历季节
         */
        LunarSeason get_season() const;

        /**
         * @brief 初一的儒略日
         * @return 儒略日
         */
        JulianDay get_first_julian_day() const;

        /**
         * @brief 是否闰月
         * @return true/false
         */
        bool is_leap() const;

        /**
         * @brief 周数
         * @param start 起始星期，1234560分别代表星期一至星期天
         * @return 周数
         */
        int get_week_count(int start) const;

        /**
         * @brief 九星
         * @return 九星
         */
        NineStar get_nine_star() const;

        /**
         * @brief 太岁方位
         * @return 方位
         */
        Direction get_jupiter_direction() const;

        /**
         * @brief 逐月胎神
         * @return 逐月胎神
         */
        optional<FetusMonth> get_fetus() const;

        /**
         * @brief 小六壬
         * @return 小六壬
         */
        MinorRen get_minor_ren() const;

        /**
         * @brief 本月的农历周列表
         * @param start 星期几作为一周的开始，1234560分别代表星期一至星期天
         * @return 农历周列表
         */
        vector<LunarWeek> get_weeks(int start) const;

        /**
         * @brief 本月的农历日列表
         * @return 农历日列表
         */
        vector<LunarDay> get_days() const;

        /**
         * @brief 初一
         * @return 农历日
         */
        LunarDay get_first_day() const;

    protected:
        /**
         * @brief 是否闰月
         */
        bool leap;

        double get_new_moon() const;
    };

    /**
     * @brief 农历周
     */
    class LunarWeek : public WeekUnit {
    public:
        ~LunarWeek() override = default;

        explicit LunarWeek(const int year, const int month, const int index, const int start) : WeekUnit(year, month, index, start) {
            validate(year, month, index, start);
        }

        static void validate(int year, int month, int index, int start);

        static LunarWeek from_ym(int year, int month, int index, int start);

        /**
         * @brief 农历月
         * @return 农历月
         */
        LunarMonth get_lunar_month() const;

        string get_name() const override;

        string to_string() const override;

        LunarWeek next(int n) const;

        bool equals(const LunarWeek &other) const;

        /**
         * @brief 本周第1天
         * @return 农历日
         */
        LunarDay get_first_day() const;

        /**
         * @brief 本周农历日列表
         * @return 农历日列表
         */
        vector<LunarDay> get_days() const;
    };

    /**
     * @brief 农历日
     */
    class LunarDay : public DayUnit {
    public:
        ~LunarDay() override = default;

        static const vector<string> NAMES;

        explicit LunarDay(const int year, const int month, const int day) : DayUnit(year, month, day) {
            validate(year, month, day);
        }

        static void validate(int year, int month, int day);

        static LunarDay from_ymd(int year, int month, int day);

        /**
         * @brief 农历月
         * @return 农历月
         */
        LunarMonth get_lunar_month() const;

        string get_name() const override;

        string to_string() const override;

        LunarDay next(int n) const;

        bool equals(const LunarDay &other) const;

        /**
         * @brief 是否在指定农历日之前
         * @param other 农历日
         * @return true/false
         */
        bool is_before(const LunarDay &other) const;

        /**
         * @brief 是否在指定农历日之后
         * @param other 农历日
         * @return true/false
         */
        bool is_after(const LunarDay &other) const;

        /**
         * @brief 星期
         * @return 星期
         */
        Week get_week() const;

        /**
         * @brief 干支
         * @return 干支
         */
        SixtyCycle get_sixty_cycle() const;

        /**
         * @brief 建除十二值神
         * @return 建除十二值神
         */
        Duty get_duty() const;

        /**
         * @brief 黄道黑道十二神
         * @return 黄道黑道十二神
         */
        TwelveStar get_twelve_star() const;

        /**
         * @brief 九星
         * @return 九星
         */
        NineStar get_nine_star() const;

        /**
         * @brief 太岁方位
         * @return 方位
         */
        Direction get_jupiter_direction() const;

        /**
         * @brief 逐日胎神
         * @return 逐日胎神
         */
        FetusDay get_fetus_day() const;

        /**
         * @brief 月相第几天
         * @return 月相第几天
         */
        PhaseDay get_phase_day() const;

        /**
         * @brief 月相
         * @return 月相
         */
        Phase get_phase() const;

        /**
         * @brief 六曜
         * @return 六曜
         */
        SixStar get_six_star() const;

        /**
         * @brief 公历日
         * @return 公历日
         */
        SolarDay get_solar_day() const;

        /**
         * @brief 干支日
         * @return 干支日
         */
        SixtyCycleDay get_sixty_cycle_day() const;

        /**
         * @brief 二十八宿
         * @return 二十八宿
         */
        TwentyEightStar get_twenty_eight_star() const;

        /**
         * @brief 神煞列表(吉神宜趋，凶神宜忌)
         * @return 神煞列表
         */
        vector<God> get_gods() const;

        /**
         * @brief 宜
         * @return 宜忌列表
         */
        vector<Taboo> get_recommends() const;

        /**
         * @brief 忌
         * @return 宜忌列表
         */
        vector<Taboo> get_avoids() const;

        /**
         * @brief 小六壬
         * @return 小六壬
         */
        MinorRen get_minor_ren() const;

        /**
         * @brief 农历传统节日
         * @return 农历传统节日，如果没有则返回空
         */
        optional<LunarFestival> get_festival() const;

        /**
         * @brief 三柱
         * @return 三柱
         */
        ThreePillars get_three_pillars() const;
    };

    /**
     * @brief 农历时辰
     */
    class LunarHour;
}
#endif
