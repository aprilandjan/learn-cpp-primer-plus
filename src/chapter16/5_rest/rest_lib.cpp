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

#include <initializer_list>

double get_sum(const std::initializer_list<double> & list) {
    double s = 0;
    for(auto p = list.begin(); p != list.end(); p++) {
        s += *p;
    }
    return s;
}

double get_avg(const std::initializer_list<double> & list) {
    double s = 0;
    int n = list.size();
    double a = 0;
    if (n > 0) {
        for(auto p = list.begin(); p != list.end(); p++) {
            s += *p;
        }
        a = s / n;
    }
    return a;
}

void use_initializer_list() {
    using namespace std;

    cout << "List 1: sum = " << get_sum({2, 3, 4});
    cout << ", avg = " << get_avg({2, 3, 4}) << "\n";

    initializer_list<double> list = {
            1.1, 2.2, 3.3, 4.4, 5.5
    };

    cout << "List 2: sum = " << get_sum(list);
    cout << ", avg = " << get_avg(list) << "\n";

    list = {
            12.3, 4.5, 6.7
    };

    cout << "List 3: sum = " << get_sum(list);
    cout << ", avg = " << get_avg(list) << "\n";
}