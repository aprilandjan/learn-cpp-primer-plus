//
// Created by May on 2019/1/24.
//

#include <iostream>
#include <cstdlib>
#include "capture_exception.h"

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

double get_harmonic_mean_safely(double x, double y) {
    if (x == -y) {
        throw "Invalid arguments: x = -y is not allowed";
    }
    return 2.0 * x * y / (x + y);
}

void use_try_catch() {
    double x, y, z;
    std::cout << "Enter two numbers: ";
    while(std::cin >> x >> y) {
        try {
            z = get_harmonic_mean_safely(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
        } catch(const char * s) {   //  catch what throwed?..
            std::cout << "Invali set, Please try again!\n";
            continue;
        }
        std::cout << "Enter next set(q to quit): ";
    }
}

//  try catch with exception instance
double get_harmonic_mean_with_possible_exception(double x, double y) {
    using namespace L15_3;
    if (x == -y) {
        //  throw should not "new" error(which is actually a pointer)
        throw BadMeanArgumentException(x, y);
    }
    return 2.0 * x * y / (x + y);
}

void use_try_catch_exception_instance() {
    using namespace L15_3;

    double x, y, z;
    std::cout << "Enter two numbers: ";
    while(std::cin >> x >> y) {
        try {
            z = get_harmonic_mean_with_possible_exception(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
        } catch(const BadMeanArgumentException & e) {
            e.msg();
//            continue;
        }
        std::cout << "Enter next set(q to quit): ";
    }
}