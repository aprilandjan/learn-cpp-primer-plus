//
// Created by May on 2018/10/31.
//

#include "1_inline_functions.h"
#include "iostream"

inline double square(double x) {
    return x * x;
}

int inline_square() {
    double a = 12;
    double b = 3.14;
    std::cout << "square of " << a << " is: " << square(a) << std::endl;
    std::cout << "square of " << b << " is: " << square(b) << std::endl;
    std::cout << "square of " << a + b << " is: " << square(a + b) << std::endl;
}