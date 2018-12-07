//
// Created by May on 2018/12/7.
//

#ifndef LEARN_STRING_H
#define LEARN_STRING_H

#include <iostream>

namespace L12_1 {
    class String {
    private:
        //  字符串长度
        int _length;
        //  存储在堆中的字符串地址
        char * _p_str;
    public:
        String();
        ~String();
        String(const char * ps);
        //  获取长度
        int length() const;
        //  friend function, allow `cout << str`
        friend std::ostream & operator<<(std::ostream & os, const String & str);
        //  allow `cin >> str`
        friend operator>>(std::istream is, String &str);
        //  allow compare
        friend bool operator>(const String &s1, const String &s2);
        friend bool operator<(const String &s1, const String &s2);
        //  allow [x]
        char & operator[](int i);
        const char & operator[](int i) const;
    };
}

#endif //LEARN_STRING_H
