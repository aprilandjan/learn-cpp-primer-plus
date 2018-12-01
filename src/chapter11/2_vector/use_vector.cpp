//
// Created by May on 2018/12/1.
//

#include <iostream>
#include <cmath>

#include "use_vector.h"
#include "./Vector.h"

// C++标准库里并没有预先定义PI...
// https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c
//const double PI = 4 * std::atan(1.);

void use_vector() {
    using namespace L11_2;

    const double PI = 4 * std::atan(1.);

    std::cout << PI << std::endl;
    Vector v1(3, 4);
    std::cout << "v1: ";
    v1.show();
    v1.show(Vector::POL);

    Vector v2(5, 5);
    std::cout << "v2: ";
    v2.show();
    v2.show(Vector::POL);

    Vector v3(5 * std::sqrt(2), PI / 4, Vector::MODE::POL);
    std::cout << "v3: ";
    v3.show();
    v3.show(Vector::POL);

    Vector v4 = v3 + v2;
    v4.show();

    (5 * v4).show();

    std::cout << Vector(100, 20) << "\n";
}
