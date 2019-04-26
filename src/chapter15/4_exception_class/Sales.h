//
// Created by May on 2019/2/18.
//

#ifndef LEARN_SALES_H
#define LEARN_SALES_H

#include <stdexcept>
#include <string>

namespace L15_4 {
    class Sales {
    public:
        enum {
            MONTHS = 12,
        };
        //  declare a type of exception, extends from logic_error
        class BadIndex: public std::logic_error {
        private:
            int _bad_value;
        public:
            explicit BadIndex(int ix, const std::string & s = "Index Error in Sales Object\n");
            int get_bad_value() const {
                return _bad_value;
            }
            // Todo: what does "throw" mean? throwable?
            // virual: ALLOW runtime polymorphism. so destructor call will be on correct class method
            virtual ~BadIndex() throw() {};
        };
        explicit Sales(int y = 0);
        Sales(int y, const double * gr, int n);
        virtual ~Sales(){};
        int get_year() const {
            return _year;
        }
        //  数组取值
        virtual double operator[](int i) const;
        //  数组设置值（实际是取地址，因此可以对地址处赋值）
        virtual double &operator[](int i);
    private:
        double _gross[MONTHS];
        int _year;
    };

    //  sub class
    class LabeledSales: public Sales {
    public:
        class NBadIndex: public Sales::BadIndex {
        private:
            std::string _lbl;
        public:
            NBadIndex(const std::string & lb, int ix, const std::string & s = "Index Error in LabeledSales Object\n");
            const std::string & get_label_value() const {
                return _lbl;
            }
            virtual ~NBadIndex() throw() {};
        };
        explicit LabeledSales(const std::string & lb = "none", int y = 0);
        LabeledSales(const std::string & lb, int y, const double * gr, int n);
        virtual ~LabeledSales() {};
        const std::string & get_label() const {
            return _label;
        }
        //  数组形式取值 & 设置值
        virtual double operator[](int i) const;
        virtual double &operator[](int i);
    private:
        std::string _label;
    };
}


#endif //LEARN_SALES_H
