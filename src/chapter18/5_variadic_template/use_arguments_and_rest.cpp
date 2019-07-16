//
// Created by May on 2019/7/13.
//

#include "use_arguments_and_rest.h"
#include <iostream>
#include <string>
//#include "boost/lexical_cast.cpp"

void show_list() {
    //  just an empty implementation to prevent infinite recursive calling
    std::cout << "\n";
};

//  an implementation of one param, to prevent redundant ',' at the end
//  also stop recursive calling
template <typename T>
void show_list(const T & value) { //  pass by reference
    std::cout << value << "\n";
}

//  template param pack
template <typename T, typename ...Args>
//  'const &' is a must
void show_list(const T & value, const Args & ...args) { // unpack params pack, and apply 'const &' pattern
    std::cout << value << ", ";
    //  recursive calling this function, each time to decrease one arg
    show_list(args...);
}

void use_parameter_pack() {
    int n = 12;
    double pi = 3.1415926;
    std::string str = "Just a piece of string...";
    show_list(n, pi);
    show_list(pi * pi, 'a', 12, str);
}
