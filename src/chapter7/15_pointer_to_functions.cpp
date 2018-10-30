//
// Created by May on 2018/10/30.
//

#include "15_pointer_to_functions.h"
#include "cmath"
#include "iostream"


double alpha_solve(int count) {
    return count * count;
}

double beta_solve(int count) {
    return std::sqrt(count);
}

double gamma_solve(int count) {
    return count;
}

//  函数指针定义
double estimate(int count, double (*p)(int)) {
    return (*p)(count);
}

int estimate_time_multiways () {
    int count;
    std::cout << "How many lines do you want to test?\n";
    std::cin >> count;
    std::cout << "alpha solve:" << estimate(count, alpha_solve) << std::endl;
    std::cout << "beta solve:" << estimate(count, beta_solve) << std::endl;
    std::cout << "gamma solve:" << estimate(count, gamma_solve) << std::endl;
};
