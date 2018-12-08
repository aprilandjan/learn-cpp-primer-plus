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
        //  私有的静态成员常量
        static int num_strings;
        //  cin 的输入限制
        static const int CIN_LIMIT = 80;
    public:
        String();
        ~String();
        String(const char * ps);
        String(const String &);
        //  获取长度
        int length() const;
        //  allow String = String, 否则 implicit instance copy
        String & operator=(const String &);
        //  allow String = char *
        String & operator=(char * ps);
        //  friend function, allow `cout << str`
        friend std::ostream & operator<<(std::ostream & os, const String & str);
        //  allow `cin >> str`
        friend std::istream & operator>>(std::istream is, String &str);
        //  allow compare
        friend bool operator>(const String &s1, const String &s2);
        friend bool operator<(const String &s1, const String &s2);
        friend bool operator==(const String &s1, const String &s2);
        //  allow [x]
        char & operator[](int i);
        const char & operator[](int i) const;

        // public static method
        static int getInstanceCount();
    };
}

#endif //LEARN_STRING_H
