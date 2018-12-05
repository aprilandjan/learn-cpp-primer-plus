//
// Created by May on 2018/12/4.
//

#include <cstring>
#include <iostream>
#include "StringBad.h"


namespace L12_1 {
    //  必须在头文件外初始化类的静态成员...WTF
    //  https://stackoverflow.com/questions/185844/how-to-initialize-private-static-members-in-c
    int StringBad::num_strings = 0;
    StringBad::StringBad() {
        len = 4;
        //  动态内存分配, 把字符串保存在 “heap” 中
        str = new char[4];
        std::strcpy(str, "C++");
        num_strings++;
        std::cout << "\"" << str << "\" default object created." << num_strings << " total.\n";
    }

    StringBad::StringBad(const char *s) {
        len = std::strlen(s);
        str = new char[len + 1];
        std::strcpy(str, s);
        num_strings++;
        std::cout << "\"" << str << "\" object created." << num_strings << " total.\n";
    }

    StringBad::~StringBad() {
        std::cout << "\"" << str << "\" object deleted. " << num_strings - 1 << " left.\n";
        num_strings--;
        //  清掉动态分配的内存
        delete [] str;
    }

    //  友元重载必须是两个参数的，并且不是类的成员方法
    std::ostream& operator<<(std::ostream &os, const StringBad &str) {
        os << str.str;
        return os;
    }
}