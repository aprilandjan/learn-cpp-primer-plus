//
// Created by May on 2019/1/24.
//

#ifndef LEARN_USE_ABORT_H
#define LEARN_USE_ABORT_H

void use_abort();
void use_no_abort();
void use_try_catch();
void use_try_catch_exception_instance();

#include <iostream>

namespace L15_3 {
    class BadMeanArgumentException {
    private:
        double _a;
        double _b;
    public:
        BadMeanArgumentException(double a = 0, double b = 0): _a(a), _b(b) {};
        void msg() const;
    };

    inline void BadMeanArgumentException::msg() const {
        std::cout << "Mean argument(" << _a << ", " << _b << ") invalid.\n";
    };
}

#endif //LEARN_USE_ABORT_H
