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

