//
// Created by May on 2018/12/22.
//

#include <iostream>
#include "use_fruit.h"
#include "Fruit.h"

void use_fruit() {
    //
    using namespace L13_4;
    using std::cout;
    using std::endl;

    Banana b("b0", "b0-class");
    //  默认是调用衍生类的友元重载运算符方法
    cout << b;

    //  只调用其基类的友元重载运算符方法
    cout << (const Fruit &)b;

    Banana c("C0", "C0-class");

    cout << c;

    c = b;

    cout << c;
}