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

void use_peek() {
    using namespace std;

    char ch;
    while(cin.get(ch)) {    //  stop when EOF
        if (ch != '#') {
            cout << ch << "-";
        } else {
            //  make '#' back into stream
            cin.putback(ch);
            break;
        }
    }

    if (!cin.eof()) {
        cin.get(ch);    // always '#'
        cout << endl << ch << " is the next char.\n";
    } else {
        cout << "EOF reached.\n";
        exit(0);
    }

    //  read until meet '#'
    while(cin.peek() != '#') {
        cin.get(ch);
        cout << ch;
    }
    if (!cin.eof()) {
        cin.get(ch);    //  always '#'
        cout << endl << ch << " is the next char.\n";
    } else {
        cout << "EOF reached.\n";
    }
}