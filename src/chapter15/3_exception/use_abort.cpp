//
// Created by May on 2019/1/24.
//

#include <iostream>
#include <cstdlib>
#include "use_abort.h"

/**
 * 计算调和平均数
 * @param a
 * @param b
 * @return
 */
double get_harmonic_mean(double a, double b) {
    if (a == -b) {
        std::cout << "unsuitable arguments to calc harmonic mean!\n";
        std::abort();
    }

    //  must use float 2.0
    return 2.0 * a * b / (a + b);
}

void use_abort() {
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while(std::cin >> x >> y) {
        z = get_harmonic_mean(x, y);
        std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
        std::cout << "Enter next set(q to quit): ";
    }
    std::cout << "Bye!\n";
}


/**
 * 安全的计算调和平均数...
 * @param a
 * @param b
 * @param c
 * @return
 */
bool get_harmonic_mean_safe(double a, double b, double * c) {
    if (a == -b) {
        return false;
    }

    //  pass function result via pointer param...
    *c = 2.0 * a * b / (a + b);
    std::cout << "result = " << *c << std::endl;
    return true;
}

void use_no_abort() {
    double x, y, z;

    //  pointer must be initialized in c++, so do not use that pattern
//    double * r;
//    *r = 12.3;

    std::cout << "Enter two numbers: ";
    while(std::cin >> x >> y) {
        if (!get_harmonic_mean_safe(x, y, &z)) {
            std::cout << "Invalid number set to calc harmonic mean!\n";
//            std::exit(-1);
        } else {
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
        }
        std::cout << "Enter next set(q to quit): ";
    }
    std::cout << "Bye!\n";
}