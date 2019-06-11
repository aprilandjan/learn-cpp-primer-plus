//
// Created by May on 2019/6/11.
//

#include "use_cout_write.h"

#include <iostream>
#include <cstring>

void use_cout_write() {
    using namespace std;

    const char * state1 = "April";
    const char * state2 = "May";
    const char * state3 = "June";

    int length = std::strlen(state2);

    cout << "Increasing loop index:\n";
    int i;
    for(i = 1; i <= length; i++) {
        //  location, and size
        cout.write(state2, i);
        cout << endl;
    }

    cout << "Decreasing loop index:\n";
    for(i = length; i > 0; i--) {
        cout.write(state2, i);
        cout << endl;
    }

    cout << "Exceeding string length:\n";
    //  some strange memory data
    cout.write(state2, length + 5000) << endl;

    cout << "\n ok...\n";
}