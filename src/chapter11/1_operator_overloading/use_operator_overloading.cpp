//
// Created by May on 2018/11/27.
//

#include <iostream>
#include "use_operator_overloading.h"
#include "./Time.h"

void use_operator_overloading() {
    using namespace L11_1;
    using namespace std;

    std::cout << "Monday:\n";
    Time monday(3, 29);
    monday.show();
    monday.addMin(135);
    monday.show();
    monday.addHour(1);
    monday.show();
    monday.reset(12, 100);
    monday.show();

    std::cout << "Tuesday:\n";
    //  new 返回的总是地址 0.0
    Time * tuesday = new Time(5, 129);
    tuesday->show();

    std::cout << "Sum of monday and tuesday:\n";
    const Time sumTime = monday.sum(* tuesday);
    sumTime.show();

    std::cout << "Try again use operator overloading:\n";
    const Time t1 = monday.operator+(*tuesday);
    t1.show();
    const Time t2 = monday + *tuesday;
    t2.show();

    std::cout << "\nTry diff between monday and tuesday:\n";
    Time d1 = monday - *tuesday;
    d1.show();
    std::cout << "Try diff between tuesday and monday:\n";
    Time d2 = *tuesday - monday;
    d2.show();

    std::cout << "\n Try multiple x:\n";
    (monday * 3.5).show();
}