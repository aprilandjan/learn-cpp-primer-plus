//
// Created by May on 2019/6/7.
//

#include "rest_lib.h"
#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

void use_valarray() {
    using namespace std;
    vector<double> data;
    double temp;

    cout << "Enter numbers (<0 to quit):\n";
    while(cin >> temp && temp >= 0) {
        data.push_back(temp);
    }

    sort(data.begin(), data.end());

    int size = data.size();

    // had to decide size
    valarray<double> numbers(size);
    int i = 0;
    for(i = 0; i < size; i++) {
        numbers[i] = data[i];
    }
    valarray<double> sqrt_num(size);
    sqrt_num = sqrt(numbers);

    valarray<double> results(size);
    //  must be 'T' * valarray<T>
    results = numbers + 2.0 * sqrt_num;
    cout.setf(ios_base::fixed);
    cout.precision(4);
    for(i = 0; i < size; i++) {
        cout.width(8);
        cout << numbers[i] << ": ";
        cout.width(8);
        cout << results[i] << endl;
    }
}