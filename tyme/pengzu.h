#ifndef TYME_PENGZU_H
#define TYME_PENGZU_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 天干彭祖百忌
     */
    class PengZuHeavenStem : public LoopTyme {
    public:
        ~PengZuHeavenStem() override = default;

        static const vector<string> NAMES;

        explicit PengZuHeavenStem(const int index) : LoopTyme(NAMES, index) {
        }

        explicit PengZuHeavenStem(const string &name) : LoopTyme(NAMES, name) {
        }

        static PengZuHeavenStem from_index(int index);

        static PengZuHeavenStem from_name(const string &name);

        PengZuHeavenStem next(int n) const;
    };

    /**
     * @brief 地支彭祖百忌
     */
    class PengZuEarthBranch : public LoopTyme {
    public:
        ~PengZuEarthBranch() override = default;

        static const vector<string> NAMES;

        explicit PengZuEarthBranch(const int index) : LoopTyme(NAMES, index) {
        }

        explicit PengZuEarthBranch(const string &name) : LoopTyme(NAMES, name) {
        }

        static PengZuEarthBranch from_index(int index);

        static PengZuEarthBranch from_name(const string &name);

        PengZuEarthBranch next(int n) const;
    };

    /**
     * @brief 六十甲子
     */
    class SixtyCycle;

    /**
     * @brief 彭祖百忌
     */
    class PengZu : public AbstractCulture {
    public:
        ~PengZu() override = default;

        explicit PengZu(const SixtyCycle &sixty_cycle);

        static PengZu from_sixty_cycle(const SixtyCycle &sixty_cycle);

        string get_name() const override;

        /**
         * @brief 天干彭祖百忌
         * @return 天干彭祖百忌
         */
        PengZuHeavenStem get_peng_zu_heaven_stem() const;

        /**
         * @brief 地支彭祖百忌
         * @return 地支彭祖百忌
         */
        PengZuEarthBranch get_peng_zu_earth_branch() const;

    protected:
        /**
         * @brief 天干彭祖百忌
         */
        PengZuHeavenStem peng_zu_heaven_stem;

        /**
         * @brief 地支彭祖百忌
         */
        PengZuEarthBranch peng_zu_earth_branch;
    };
}
#endif
