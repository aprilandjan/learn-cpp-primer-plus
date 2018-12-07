//
// Created by May on 2018/12/7.
//

#include "String.h"
#include <iostream>
#include <cstring>

namespace L12_1 {
    String::String() {
        //  空字符串是 '\0'
        _length = 0;
        _p_str = new char[_length + 1];
        _p_str[0] = '\0';
    }
    String::String(const char *ps) {
        _length = std::strlen(ps);
        _p_str = new char[_length + 1];
        std::strcpy(_p_str, ps);
    }
    String::~String() {
        //  free memory
        delete [] _p_str;
    }
    /**
     * get string length
     * @return
     */
    int String::length() const {
        return _length;
    }
    std::ostream& operator<<(std::ostream &os, const String &str) {
        os << str._p_str;
        return os;
    }
}