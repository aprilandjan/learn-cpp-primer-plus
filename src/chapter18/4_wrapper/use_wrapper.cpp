//
// Created by May on 2019/7/9.
//

#include "use_wrapper.h"
#include <iostream>
#include <functional>

double twice(double x) {
    return 2.0 * x;
}

double pow2(double x) {
    return x * x;
}

void wrapper_of_callable() {
    using namespace L18_4;
    using namespace std;

    double y = 1.21;

    cout << "Function pointer twice:\n";
    cout << "\t" << use_f(y, twice) << endl;
    cout << "Function pointer square:\n";
    cout << "\t" << use_f(y, pow2) << endl;

    //  Fp & Fq are functor classes
    //  &count changed?...
    cout << "Function object Fp:\n";
    cout << "\t" << use_f(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << "\t" << use_f(y, Fq(5.0)) << endl;

    //  try lambda instead
    //  &count changed again?...
    cout << "Lambda expression 1:\n";
    cout << "\t" << use_f(y, [](double x){
        return x * x;
    }) << endl;
    cout << "Lambda expression 2:\n";
    cout << "\t" << use_f(y, [](double x){
        return x + x / 2.0;
    }) << endl;


    cout << "------------------\n";

    //  the template function use_f initialized 5 instances...
    //  use wrapper function to prevent this
    function<double(double)> fw1 = twice;
    function<double(double)> fw2 = pow2;
    function<double(double)> fw3 = Fp(5.0);
    function<double(double)> fw4 = Fq(5.0);
    function<double(double)> fw5 = [](double x){return x * x;};
    function<double(double)> fw6 = [](double x){return x + x / 2.0;};

    cout << "Function pointer twice:\n";
    cout << "\t" << use_f(y, fw1) << endl;
    cout << "Function pointer square:\n";
    cout << "\t" << use_f(y, fw2) << endl;

    cout << "Function object Fp:\n";
    cout << "\t" << use_f(y, fw3) << endl;
    cout << "Function object Fq:\n";
    cout << "\t" << use_f(y, fw4) << endl;

    cout << "Lambda expression 1:\n";
    cout << "\t" << use_f(y, fw5) << endl;
    cout << "Lambda expression 2:\n";
    cout << "\t" << use_f(y, fw6) << endl;

    cout << "----------\n";

    //  use only one function wrapper
    typedef function<double(double)> fw;
    cout << "\t" << use_f(y, fw(pow2)) << endl;
    cout << "\t" << use_f(y, fw(Fp(5.0))) << endl;

    cout << "----------\n";

    //  improve use_f
    //  ...ignore that
}