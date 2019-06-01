//
// Created by May on 2019/6/1.
//

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

#include "functor.h"

template<class T>
class GreaterThan {
private:
    T _threshold;
public:
    GreaterThan(const T & t): _threshold(t) {};
    //  make instance 'functor'
    bool operator()(const T & v) {
        return v > _threshold;
    }
};

void outputInt(int n) {
    std::cout << n << " ";
}

void use_functor() {
    using namespace std;

    // IMPORTANT: this is very like the function curry in javascript
    GreaterThan<int> gt_100(100);
    int vals[10] = {
            30,
            100,
            50,
            120,
            590,
            21,
            785,
            0,
            99,
            311,
    };

    //  range constructor. insert array into container, in order to use 'algorithm'
    list<int> a(vals, vals + 10);
    list<int> b(vals, vals + 10);

    cout << "Origin list:\n";
    for_each(a.begin(), a.end(), outputInt);
    cout << endl << endl;

    for_each(b.begin(), b.end(), outputInt);
    cout << endl << endl;

    //  use a existing functor instance
    a.remove_if(gt_100);
    //  construct a function object
    b.remove_if(GreaterThan<int>(200));

    cout << "Trimmed list:\n";
    for_each(a.begin(), a.end(), outputInt);
    cout << endl << endl;

    for_each(b.begin(), b.end(), outputInt);
    cout << endl << endl;
}