//
// Created by May on 2018/12/7.
//

#include "String.h"
#include <iostream>
#include <cstring>

namespace L12_1 {
    //  init private static const
    int String::num_strings = 0;

    //  static method. can visit private static class variable
    int String::getInstanceCount() {
        return num_strings;
    }

    //  member method
    String::String() {
        //  空字符串是 '\0'
        _length = 0;
        _p_str = new char[_length + 1];
        _p_str[0] = '\0';

        std::cout << "init as default...";
        num_strings++;
    }
    String::String(const char *ps) {
        _length = std::strlen(ps);
        _p_str = new char[_length + 1];
        std::strcpy(_p_str, ps);

        std::cout << "init from char *...";
        num_strings++;
    }
    String::String(const String & s) {
        _length = s.length();
        _p_str = new char[_length + 1];
        std::strcpy(_p_str, s._p_str);

        std::cout << "init from another String...";
        num_strings++;
    }
    String::~String() {
        std::cout << "[" << _p_str << "] disposed. remaining: " << num_strings - 1 << ".\n";
        //  free memory
        delete [] _p_str;

        num_strings--;
    }
    /**
     * get string length
     * @return
     */
    int String::length() const {
        return _length;
    }
    /**
     * explicit override assign operator to char *
     *  String a;
     *  a = "abcd"
     * @param ps
     * @return
     */
    String& String::operator=(char *ps) {
        //  先把之前可能的内存值删掉
        delete [] _p_str;

        _length = strlen(ps);
        _p_str = new char[_length + 1];
        std::strcpy(_p_str, ps);
    }
    /**
     * explicit override assign operator to String reference
     * @return
     */
    String& String::operator=(const String & s) {
        delete [] _p_str;

        _length = s.length();
        _p_str = new char[_length + 1];
        std::strcpy(_p_str, s._p_str);
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