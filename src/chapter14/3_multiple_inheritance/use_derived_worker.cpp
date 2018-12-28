//
// Created by May on 2018/12/26.
//

#include <iostream>

#include "use_derived_worker.h"
#include "Worker.h"

//void use_derived_worker() {
//    using namespace L14_3;
//
////    Singer julia;
////    julia.set();
////    julia.show();
////
//
//    const int SIZE = 4;
//
//    Waiter bob("Bob Jason", 324, "King's fall");
//    Singer Emily("Emily Grill", 999, 3);
//
//    Waiter a;
//    Singer b;
//
//    Worker *pw[SIZE] = {&bob, &Emily, &a, &b};
//
//    int i;
//    //  set the a & b
//    for(i = 2; i < SIZE; i++) {
//        pw[i]->set();
//    }
//    for(i = 0; i < SIZE; i++) {
//        pw[i]->show();
//    }
//    std::cout << std::endl;
//}

//  provide c-style string functions
#include <cstring>

void use_derived_worker() {
    using namespace L14_3;

    const int SIZE = 4;
    Worker *list[SIZE];

    int i = 0;
    for (i = 0; i < SIZE; i++) {
        char choice;
        std::cout << "Enter the employee category:\n";
        std::cout << "w: waiter; s: singer; t: singer-waiter; q: quit\n";
        std::cin >> choice;
        //  if input not included in "wstq", prompt again
        while(strchr("wstq", choice) == NULL) {
            std::cout << "Please enter w/s/t/q:\n";
            std::cin >> choice;
        }
        if (choice == 'q') {
            //  stop iteration
            break;
        }
        switch(choice) {
            case 'w':
                list[i] = new Waiter;
                break;
            case 's':
                list[i] = new Singer;
                break;
            case 't':
                list[i] = new SingerWaiter;
                break;
        }

        //  set the role
        list[i]->set();
    }

    std::cout << "Here is all of your staff:\n";
    int j = 0;
    for (j = 0; j < i; j++) {
        std::cout << "\n";
        list[j]->show();
        delete list[j];
    }
    std::cout << "Bye!\n";
    return;
}