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
    /**
     * 允许取`常量` str[i] 取值. 返回一个字符的引用(char &)
     * @param i
     * @return
     */
    const char& String::operator[](int i) const {
        return _p_str[i];
    }
    /**
     * 非常量版本，因此拿到字符引用后，可以通过地址赋值写入
     * @param i
     * @return
     */
    char& String::operator[](int i) {
        return _p_str[i];
    }
    /**
     * 按字符的字母顺序进行字符串比较
     * @param s1
     * @param s2
     * @return
     */
    bool operator<(const String &s1, const String &s2) {
//        if (std::strcmp(s1._p_str, s2._p_str) < 0) {
//            return true;
//        } else {
//            return false;
//        }
        return std::strcmp(s1._p_str, s2._p_str) < 0;
    }
    bool operator>(const String &s1, const String &s2) {
        //  直接用上面定义的另一个友元重载
        return s2 < s1;
    }
    bool operator==(const String &s1, const String &s2) {
        return std::strcmp(s1._p_str, s2._p_str) == 0;
    }
}