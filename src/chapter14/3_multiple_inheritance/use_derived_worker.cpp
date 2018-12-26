//
// Created by May on 2018/12/26.
//

#include <iostream>

#include "use_derived_worker.h"
#include "Worker.h"

void use_derived_worker() {
    using namespace L14_3;

//    Singer julia;
//    julia.set();
//    julia.show();
//

    const int SIZE = 4;

    Waiter bob("Bob Jason", 324, "King's fall");
    Singer Emily("Emily Grill", 999, 3);

    Waiter a;
    Singer b;

    Worker *pw[SIZE] = {&bob, &Emily, &a, &b};

    int i;
    //  set the a & b
    for(i = 2; i < SIZE; i++) {
        pw[i]->set();
    }
    for(i = 0; i < SIZE; i++) {
        pw[i]->show();
    }
    std::cout << std::endl;
}