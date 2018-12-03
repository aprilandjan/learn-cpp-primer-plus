//
// Created by May on 2018/12/3.
//

#include <iostream>
#include "use_type_conversion.h"
#include "./weight.h"

void display(const L11_3::Weight & w, int n = 2) {
    for (int i = 0; i < n; i++) {
        std::cout << "Wow! ";
        w.show();
    }
}

void use_type_conversion() {
    using namespace std;
    using namespace L11_3;

    //  根据构造函数定义，int 隐式转换
    Weight a = 275;
    a.show();

    Weight b = Weight(345.5, 12);
    b.show();

    //  准确匹配一种构造函数原型
    Weight c(21.5);
    c.show();

    //  15 => double 15 => Weight(double)
    display(15);

    //  尝试使用转换函数
    int b_int = b;
    cout << "transform b to int: " << b_int << "\n";
    double b_double = b;
    cout << "transform b to double: " << b_double << "\n";
}
