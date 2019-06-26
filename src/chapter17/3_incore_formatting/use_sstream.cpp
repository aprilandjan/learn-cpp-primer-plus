//
// Created by May on 2019/6/26.
//

#include "use_sstream.h"
#include <sstream>
#include <string>
#include <iostream>

void use_sstream() {
    using namespace std;

    //  something similar to cout
    ostringstream out_str;

    string str;

    cout << "Input name:\n";
    //  read one whole line(space included) until \n
    getline(cin, str);

    int money;
    cout << "Input money:\n";
    cin >> money;

    out_str << "The guy who's name is " << str << " has " << money << " bucks.\n";
    string p = out_str.str();
    cout << p;

    istringstream in_str(p);

    string word;
    while(in_str >> word) { //  read a word a time. '>> read until blank or \n'
        cout << word << endl;
    }
}