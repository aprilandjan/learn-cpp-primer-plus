//
// Created by May on 2019/2/18.
//

#include "Sales.h"
using std::string;

namespace L15_4 {
    //====== Sales =====//
    Sales::BadIndex::BadIndex(int ix, const std::string &s): _bad_value(ix), std::logic_error(s) {
        // direct init
    }

    // Sales class
    Sales::Sales(int y) {
        _year = y;
        for (int i = 0; i < MONTHS; ++i) {
            _gross[i] = 0;
        }
    }

    Sales::Sales(int y, const double * gr, int n) {
        _year = y;
        int limit = (n < MONTHS) ? n : MONTHS;
        int i;
        for (i = 0; i < limit; i++) {
            //  gr is pointer to double array, gr[i] is i-th pointer in this array
            _gross[i] = gr[i];
        }
        // else
        for(;i < MONTHS; i++) {
            _gross[i] = 0;
        }
    }

    //  数组取值
    double Sales::operator[](int i) const {
        if (i < 0 || i > MONTHS) {
            throw BadIndex(i);
        }
        return _gross[i];
    }

    //  取的是地址，因此能赋值
    double & Sales::operator[](int i) {
        if (i < 0 || i > MONTHS) {
            throw BadIndex(i);
        }
        return _gross[i];
    }
    //==== LabeledSales ====//
    LabeledSales::NBadIndex::NBadIndex(const std::string & lb, int ix, const std::string &s): Sales::BadIndex(ix, s) {
    };

    LabeledSales::LabeledSales(const std::string & lb, int y): Sales(y) {
        _label = lb;
    };

    LabeledSales::LabeledSales(const std::string & lb, int y, const double *gr, int n): Sales(y, gr, n) {
        _label = lb;
    };


}