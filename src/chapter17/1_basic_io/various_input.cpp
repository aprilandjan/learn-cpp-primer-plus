//
// Created by May on 2019/6/16.
//

#include "various_input.h"
#include <iostream>

void use_get_and_getline() {
    using std::cout;
    using std::cin;
    using std::endl;

    const int LIMIT = 255;

    char input[LIMIT];

    cout << "Enter strings for getline() processing:\n";
    //  '#' is what separate the line
    cin.getline(input, LIMIT, '#');
    cout << "You input:\n" << input << "\n";

    char ch;
    //  read next char. getline() abandon the '#'
    cin.get(ch);

    cout << "The following input char is " << ch << endl;
    if (ch != '\n') {
        //  read and ignore next 'LIMIT' input, util met '\n'
        cin.ignore(LIMIT, '\n');
    }

    cout << "Enter a string for get() processing:\n";
    cin.get(input, LIMIT, '#');
    cout << "You input:\n" << input << "\n";

    //  read next char. get() not abandon '#'
    cin.get(ch);
    cout << "The next input char is " << ch << endl;
}