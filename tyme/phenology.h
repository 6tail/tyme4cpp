#ifndef TYME_PHENOLOGY_H
#define TYME_PHENOLOGY_H
#include "culture.h"

namespace tyme {
    /**
     * @brief 儒略日
     */
    class JulianDay;

    /**
     * @brief 三候
     */
    class ThreePhenology : public LoopTyme {
    public:
        ~ThreePhenology() override = default;

        static const vector<string> NAMES;

        explicit ThreePhenology(const int index) : LoopTyme(NAMES, index) {
        }

        explicit ThreePhenology(const string &name) : LoopTyme(NAMES, name) {
        }

        static ThreePhenology from_index(int index);

        static ThreePhenology from_name(const string &name);

        ThreePhenology next(int n) const;
    };

    /**
     * @brief 候
     */
    class Phenology : public LoopTyme {
    public:
        ~Phenology() override = default;

        static const vector<string> NAMES;

        explicit Phenology(const int year, const int index) : LoopTyme(NAMES, index) {
            this->year = year;
        }

        explicit Phenology(const int year, const string &name) : LoopTyme(NAMES, name) {
            const int size = get_size();
            this->year = (year * size + index) / size;
        }

        static Phenology from_index(int year, int index);

        static Phenology from_name(int year, const string &name);

        Phenology next(int n) const;

        /**
         * @brief 年
         * @return 年
         */
        int get_year() const;

        /**
         * @brief 三候
         * @return 三候
         */
        ThreePhenology get_three_phenology() const;

        /**
         * @brief 儒略日
         * @return 儒略日
         */
        JulianDay get_julian_day() const;

    protected:
        /**
         * @brief 年
         */
        int year;
    };

    /**
     * @brief 七十二候
     */
    class PhenologyDay : public AbstractCulture {
    public:
        ~PhenologyDay() override = default;

        explicit PhenologyDay(const Phenology &phenology, const int day_index) : phenology(phenology), day_index(day_index) {
        }

        Phenology get_phenology() const;

        int get_day_index() const;

        string to_string() const override;

        string get_name() const override;
    protected:
        /**
         * @brief 候
         */
        Phenology phenology;

        /**
         * @brief 天索引
         */
        int day_index;
    };
}
#endif
