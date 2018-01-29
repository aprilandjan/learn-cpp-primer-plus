//
// Created by May on 2018/1/28.
//

#include "cin_fish.h"
#include <iostream>

const int MAX = 5;

int cin_fish () {
    using namespace std;

    double fish[MAX];

    cout << "Please enter the weight of your fish:\n";
    cout << "You may enter up to " << MAX << " fishes <q to terminate>.\n";
    cout << "fish #1: ";

    int i = 0;
    //  cin 读取返回 bool
    while ( i < MAX && cin >> fish[i]) {
        if (++i < MAX) {
            cout << "fish #" << i + 1 << ": ";
        }
    }

    // calculate average
    double total = 0;
    for (int j = 0; j < i; j++) {
        total += fish[j];
    }

    if (i == 0) {
        cout << "No fish...\n";
    } else {
        cout << "The average(" << i << "): " << total / i << ".\n";
    }

    return 0;
}
