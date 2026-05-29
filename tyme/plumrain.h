#ifndef TYME_PLUMRAIN_H
#define TYME_PLUMRAIN_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 梅雨
     */
    class PlumRain : public LoopTyme {
    public:
        ~PlumRain() override = default;

        static const vector<string> NAMES;

        explicit PlumRain(const int index) : LoopTyme(NAMES, index) {
        }

        explicit PlumRain(const string &name) : LoopTyme(NAMES, name) {
        }

        static PlumRain from_index(int index);

        static PlumRain from_name(const string &name);

        PlumRain next(int n) const;
    };

    /**
     * @brief 梅雨天
     */
    class PlumRainDay : public AbstractCulture {
    public:
        ~PlumRainDay() override = default;

        explicit PlumRainDay(const PlumRain &plum_rain, const int day_index) : plum_rain(plum_rain), day_index(day_index) {
        }

        PlumRain get_plum_rain() const;

        int get_day_index() const;

        string to_string() const override;

        string get_name() const override;
    protected:
        /**
         * @brief 梅雨
         */
        PlumRain plum_rain;

        /**
         * @brief 天索引
         */
        int day_index;
    };
}
#endif
