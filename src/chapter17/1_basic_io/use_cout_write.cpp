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

#include <cmath>

void use_setf() {
    using std::cout;
    using std::endl;
    using std::ios_base;

    int temperature = 63;
    cout << "water temperature: ";
    //  show '+' before number
    cout.setf(ios_base::showpos);
    cout << temperature << endl;

    cout << "For programming, that's\n";
    //  show as hex, similar to num.toString(16)
    cout << std::hex << temperature << endl;
    cout.setf(ios_base::uppercase); // uppercase for hex
    cout.setf(ios_base::showbase); //   hex starts with '0x'
    cout << "or\n" << temperature << endl;

    //  true also hexed
    cout << "True: " << true << endl;
    cout.setf(ios_base::boolalpha);
    cout << "also " << true << endl;

    //======
    //  set back to decimal
    cout << std::dec;
    cout.setf(ios_base::left, ios_base::adjustfield); // align: left
    cout.setf(ios_base::showpos); // +
    cout.setf(ios_base::showpoint); // .
    cout.precision(3);

    //  scientific numbering
    ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << "left justification:\n";

    long n;
    for(n = 1; n <= 41;n+= 10) {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << std::sqrt(double(n)) << "|\n";
    }

    cout.setf(ios_base::internal, ios_base::adjustfield);
    //  set back
    cout.setf(old, ios_base::floatfield);

    cout << "Internal justification:\n";
    for(n = 1; n <= 41;n+= 10) {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << std::sqrt(double(n)) << "|\n";
    }

    cout.setf(ios_base::right, ios_base::adjustfield);
    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "Right justification:\n";
    for(n = 1; n <= 41;n+= 10) {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << std::sqrt(double(n)) << "|\n";
    }
}
