//
// Created by May on 2019/5/3.
//

#include "use_string_class.h"
#include <iostream>
//  provide string class
#include <string>

void string_constructors() {
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

#include <cstdlib>
#include <fstream>

void string_files() {
    using namespace std;

    //  input file stream instance
    ifstream file_input;
    file_input.open("tobuy.txt");

    if (file_input.is_open() == false) {
        //  similar to "console.error" ?
        cerr << "Cannot open file...\n";
        exit(EXIT_FAILURE); // process.exit(x)
    } else {
        //  must create the file manually...
        cout << "open file successfully...\n";
    }

    string item;
    int count = 0;
    getline(file_input, item, ':');
    while(file_input) {
        ++count; // line count, split by ':' (by default it is '\n')
        cout << count << ": " << item << endl;
        //  can this turned to "do {} while" ?
        getline(file_input, item, ':');
    }

    cout << "Done!\n";
    file_input.close();
}

void string_capacity(){
    using namespace std;
    string empty;
    string small = "bit";
    string larger = "Today is friday and a weekend is coming.";

    cout << "Sizes:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;

    //  string.capacity: returns the actual memory block size allocated for this string instance
    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;

    //  manually reserve memory block size
    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;
}