//
// Created by May on 2019/6/29.
//

#include "use_right_value_reference.h"
#include <iostream>

double f(double input) {
    return 5.0 * (input - 32.0) / 9.0;
}

void use_right_value_reference() {
    using namespace std;

    double v = 3.5;

    //  right value reference: a reference holding a right value
    //  what's the difference?
    double && v1 = 7.11;
    double && v2 = v * 2.5 - 32;
    double && v3 = f(v2);

    //  seems no difference...
    cout << "v value and address: " << v << ", " << & v << endl;
    cout << "v1 value and address: " << v1 << ", " << & v1 << endl;
    cout << "v2 value and address: " << v2 << ", " << & v2 << endl;
    cout << "v3 value and address: " << v3 << ", " << & v3 << endl;
}