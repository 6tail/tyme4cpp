#ifndef TYME_NINE_H
#define TYME_NINE_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 数九
     */
    class Nine : public LoopTyme {
    public:
        ~Nine() override = default;

        static const vector<string> NAMES;

        explicit Nine(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Nine(const string &name) : LoopTyme(NAMES, name) {
        }

        static Nine from_index(int index);

        static Nine from_name(const string &name);

        Nine next(int n) const;
    };

    /**
     * @brief 数九天
     */
    class NineDay : public AbstractCulture {
    public:
        ~NineDay() override = default;

        explicit NineDay(const Nine &nine, const int day_index) : nine(nine), day_index(day_index) {
        }

        Nine get_nine() const;

        int get_day_index() const;

        string to_string() const override;

        string get_name() const override;
    protected:
        /**
         * @brief 数九
         */
        Nine nine;

        /**
         * @brief 天索引
         */
        int day_index;
    };
}
#endif
