//
// Created by merlin.ye on 2018/12/31.
//

#include <iostream>
#include <string>
#include "Stack.h"
#include "use_template_class.h"

void use_template_class() {
    using namespace L14_4;

    // string stack
    Stack<std::string> ss;
    std::string str;

    std::cout << "Please add something to stack(q to quit):\n";
    while(std::cin >> str && str != "q" && !ss.is_full()) {
        ss.push(str);
        std::cout << "then again with stack(q to quit):\n";
    }
    if (ss.is_full()) {
        std::cout << "stack is full.\n";
    } else {
        std::cout << "ok, leave stack...\n";
    }
}