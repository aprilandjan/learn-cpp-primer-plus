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

#include <vector>
#include <functional>

void outputDouble(double v) {
    std::cout.widen(6);
    std::cout << v << ' ';
}

/**
 * use pre-defined functors in 'functional'
 */
void use_defined_functor() {
    using namespace std;

    const int LIM = 6;

    double arr1[LIM] = {
            29, 32, 10, 59, 42, 11,
    };

    double arr2[LIM] = {
            150, 42, 11, 450, 0, 90,
    };

    vector<double> gr8(arr1, arr1 + LIM);

    vector<double> m8(arr2, arr2 + LIM);

    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), outputDouble);
    cout << endl << endl;
    cout << "m8:\t";
    for_each(m8.begin(), m8.end(), outputDouble);
    cout << endl << endl;

    vector<double> sum(LIM);
    //  similar to 'array.map()' in javascript
    //  (gr8 + m8) in each index
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), outputDouble);
    cout << endl << endl;

    vector<double> prod(LIM);
    //  bind1st: make 'binary' into 'unary', curring
    //  (gr8 * 2.5) in each index
    transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), outputDouble);
    cout << endl << endl;
}