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

// rand(), srand()
#include <cstdlib>
// time()
#include <ctime>

void dynamic_stack_size() {
    using namespace L14_4;

    const int SIZE = 5;

    //  set random() seed?
    std::srand(std::time(0));
    std::cout << "Please enter stack limit:\n";
    int limit;
    std::cin >> limit;

    //
    Stack<const char *> st(limit);

    //  已创建好的指向数组的指针
    const char * in[SIZE] = {
            "1. Bach",
            "2. Mozart",
            "3. Beethoven",
            "4. Brahms",
            "5. Schubert",
    };

    const char *out[SIZE];

    int processed = 0;
    int next = 0;
    while(processed < SIZE) {
        if (st.is_empty()) {
            st.push(in[next++]);
        } else if (st.is_full()) {
            st.pop(out[processed++]);
        } else {
            int t = std::rand();
            if (t % 2 && next < SIZE) {
                st.push(in[next++]);
            } else {
                st.pop(out[processed++]);
            }
        }
    }

    for(int i = 0; i < SIZE; i++) {
        std::cout << out[i] << std::endl;
    }
    std::cout << "Bye!\n";
}