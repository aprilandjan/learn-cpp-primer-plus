//
// Created by May on 2018/1/8.
//

#include "vector_and_array.h"
#include <vector>
#include <array>
#include <iostream>

int vector_and_array () {
    using namespace std;
    //  default array, in "stack"
    double a1[4] = {1.2, 2.4, 3.6, 4.8};

    //  vector, use "heap" to store data
    vector<double> a2(4);
    a2[0] = 1.1;
    a2[1] = 1.2;
    a2[2] = 1.3;
    a2[3] = 1.4;

    //  array in c++11, use "stack" to store data
    array<double, 4> a3 = {0.1, 0.2, 0.3, 0.4};
    array<double, 4> a4 = a3;

    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    //  danger operation
    a1[-2] = 11.3;

    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    return 0;
}