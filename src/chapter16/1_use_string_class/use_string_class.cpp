//
// Created by May on 2019/5/3.
//

#include "use_string_class.h"
#include <iostream>
//  provide string class
#include <string>

void use_string_class() {
    using namespace std;

    // 1
    string one("Lottery winner!");

    //  has already some operator overloading...
    cout << one << endl;

    // 2. similar to Array(n).fill('x').join(''), lol
    string two(20, '$');
    cout << two << endl;

    // 3. copy constructor
    string three(one);
    cout << three << endl;

    one += " Oops!";
    cout << one << endl;

    two = "That is too bad...";
    three[0] = '$';

    // 4
    string four;
    four = two + three;
    cout << four << endl;

    //  5. similar to str = string.substr(0, n)
    //  for array, it is actually addresses...
    char list[] = "All I need is rest...";
    string five(list, 20);
    cout << five << endl;

    string five1(list, 5);
    cout << five1 << endl;

    // 6. similar to str = string.substr(a, b)
    string six(list + 6, list + 10);
    cout << six << endl;

    // five is string class, its operator[] is overloaded.
    string six1(&five[6], &five[10]);
    cout << six1 << endl;

    // 7. also string.substr(a, b)
    string seven(four, 7, 16);
    cout << seven << endl;
}