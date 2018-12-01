//
// Created by May on 2018/12/1.
//

#include <cmath>
#include <iostream>
#include "Vector.h"

namespace L11_2 {
    Vector::Vector() {
        this->_x = 0;
        _y = 0;
        _radian = 0;
        _radius = 0;
    }
    Vector::Vector(double arg1, double arg2, MODE mode) {
        reset(arg1, arg2, mode);
    }
    Vector::~Vector() {
        std::cout << "Vector[x=" << _x << ", y=" << _y << "] destroyed\n";
    }
    void Vector::reset(double arg1, double arg2, MODE mode) {
        if (mode == MODE::RECT) {
            _x = arg1;
            _y = arg2;
            _radius = std::sqrt(_x * _x + _y * _y);
            _radian = std::atan2(_y, _x);
        } else {
            _radius = arg1;
            _radian = arg2;
            _x = _radius * std::cos(_radian);
            _y = _radius * std::sin(_radian);
        }
    }
    void Vector::show(MODE mode) const {
        if (mode == MODE::RECT) {
            std::cout << "Vector[x=" << _x << ", y=" << _y << "]\n";
        } else {
            std::cout << "Vector[radius=" << _radius << ", y=" << _radian << "]\n";
        }
    }
    //  私有 setter...
    void Vector::set_x(double x) {
        reset(x, _y, MODE::RECT);
    }
    void Vector::set_y(double y) {
        reset(_x, y, MODE::RECT);
    }
    void Vector::set_radius(double radius) {
        reset(radius, _radian, MODE::POL);
    }
    void Vector::set_radian(double rad) {
        reset(_radius, rad, MODE::POL);
    }
    //  operator overloading
    Vector Vector::operator+(const Vector & v) const {
        //  实际上返回了该局部变量的拷贝供函数外使用，原本局部变量被删除
        //  如果返回局部变量的引用，则可能导致程序崩溃
        return Vector(_x + v._x, _y + v._y);
    }
    //  friend, not member function of class Vector
    Vector operator*(double n, const Vector & v) {
        return Vector(n * v._x, n * v._y);
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v) {
        os << "Vector[x=" << v._x << ", y=" << v._y << "]";
    }
}
