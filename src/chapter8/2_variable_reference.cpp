//
// Created by May on 2018/11/1.
//

#include "2_variable_reference.h"

#include "iostream"

int try_reference() {
    using namespace std;
    int rat = 100;
    //  define a reference refer to specific int "rat"
    int & mice = rat;

    cout << "rat = " << rat << "; mice = " << mice << endl;
    mice ++;
    cout << "after mice + 1:\n";
    cout << "rat = " << rat << "; mice = " << mice << endl;
    cout << "compare address:\n";
    //  totally the same
    cout << "rat -> " << &rat << "; &mice = " << &mice << endl;

    int bug = 50;
    mice = bug;
    cout << "After try re-assign reference:\n";
    cout << "bug = " << bug << "; mice = " << mice << endl;

    cout << "compare address:\n";
    //  totally the same
    cout << "rat -> " << &rat << "; &mice = " << &mice << "; &bug = " << &bug << endl;
}

/* swap */
//  使用指针（p1, p2 是地址值）
void swap_by_pointer (int * p1, int * p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//  使用引用（r1, r2 是函数外变量的引用）
void swap_by_reference(int & r1, int & r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

int swap_variables() {
    using namespace std;
    int a = 3;
    int b = 4;
    cout << "Before swap, a = " << a << "; b = " << b << endl;
    //  pass a, b's location
    swap_by_pointer(&a, &b);
    cout << "After swap by pointer, a = " << a << "; b = " << b << endl;
    //  直接传递原变量，自动为它创建一份作用在函数体内的引用？
    swap_by_reference(a, b);
    cout << "After swap by reference, a = " << a << "; b = " << b << endl;
}

