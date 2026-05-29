#ifndef TYME_REN_H
#define TYME_REN_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 小六壬
     */
    class MinorRen : public LoopTyme {
    public:
        ~MinorRen() override = default;

        static const vector<string> NAMES;

        explicit MinorRen(const int index) : LoopTyme(NAMES, index) {
        }

        explicit MinorRen(const string &name) : LoopTyme(NAMES, name) {
        }

        static MinorRen from_index(int index);

        static MinorRen from_name(const string &name);

        MinorRen next(int n) const;

        /**
         * @brief 吉凶
         * @return 吉凶
         */
        Luck get_luck() const;

        /**
         * @brief 五行
         * @return 五行
         */
        Element get_element() const;
    };
}
#endif
