#ifndef TYME_DOG_H
#define TYME_DOG_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 三伏
     */
    class Dog : public LoopTyme {
    public:
        ~Dog() override = default;

        static const vector<string> NAMES;

        explicit Dog(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Dog(const string &name) : LoopTyme(NAMES, name) {
        }

        static Dog from_index(int index);

        static Dog from_name(const string &name);

        Dog next(int n) const;
    };

    /**
     * @brief 三伏天
     */
    class DogDay : public AbstractCulture {
    public:
        ~DogDay() override = default;

        explicit DogDay(const Dog& dog, const int day_index) : dog(dog), day_index(day_index) {
        }

        Dog get_dog() const;

        int get_day_index() const;

        string to_string() const override;

        string get_name() const override;
    protected:
        /**
         * @brief 三伏
         */
        Dog dog;

        /**
         * @brief 天索引
         */
        int day_index;
    };
}
#endif
