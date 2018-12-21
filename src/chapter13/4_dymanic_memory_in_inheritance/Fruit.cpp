//
// Created by May on 2018/12/21.
//

#include <cstring>
#include "Fruit.h"

namespace L13_4 {
    Fruit::Fruit(const char *name) {
        //  name 指向某个通过 new 申请的堆内存(heap)地址
        _name = new char[std::strlen(name) + 1];
        std::strcpy(_name, name);
    }
    Fruit::Fruit(const Fruit &d) {
        //  虽然 d 是另外一个 Fruit 里的实例，但是在这个实例里，一样能访问其私有成员？？？
        _name = new char[std::strlen(d._name) + 1];
        std::strcpy(_name, d._name);
    }
    Fruit::~Fruit() {
        delete [] _name;
    }
    Fruit& Fruit::operator=(const Fruit &d) {
        //  地址相当
        if (this == &d) {
            return *this;
        }
        delete [] _name;
        _name = new char[std::strlen(d._name) + 1];
        std::strcpy(_name, d._name);
        return *this;
    }
    std::ostream& operator<<(std::ostream &os, const Fruit &d) {
        os << "Name: " << d._name << std::endl;
        return os;
    }

    //  Apple implementation
    Apple::Apple(const char *name, const char *color): Fruit(name) {
        std::strncpy(_color, color, Apple::COL_LEN - 1);
        _color[Apple::COL_LEN - 1] = '\0';
    }
    Apple::Apple(const Fruit &f, const char *color) {
        std::strncpy(_color, color, Apple::COL_LEN - 1);
        _color[Apple::COL_LEN - 1] = '\0';
    }
    std::ostream& operator<<(std::ostream &os, const Apple &d) {
        //  指针既可以指向衍生类，也能指向基类
        os << (const Fruit &) d;
        os << "Color: " << d._color << std::endl;
        return os;
    }

    // Banana implementation
    Banana::Banana(const char *name, const char *style):Fruit(name) {
        _style = new char[std::strlen(style) + 1];
        std::strcpy(_style, style);
    }
    Banana::Banana(const Fruit &f, const char *style):Fruit(f) {
        _style = new char[std::strlen(style) + 1];
        std::strcpy(_style, style);
    }
    Banana::Banana(const Banana &b):Fruit(b) {
        _style = new char[std::strlen(b._style) + 1];
        std::strcpy(_style, b._style);
    }
    Banana::~Banana() {
        delete [] _style;
    }
    Banana& Banana::operator=(const Banana &b) {
        if (this == &b) {
            return *this;
        }
        //  这里需要调用一下基类的 重载赋值运算符
        Fruit::operator=(b);
        delete [] _style;
        _style = new char[std::strlen(b._style) + 1];
        std::strcpy(_style, b._style);
        return *this;
    }
    std::ostream& operator<<(std::ostream &os, const Banana &b) {
        os << (const Fruit &) b;
        os << "Style: " << b._style << std::endl;
        return os;
    }
}
