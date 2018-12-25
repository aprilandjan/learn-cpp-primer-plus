//
// Created by May on 2018/12/25.
//

#ifndef LEARN_STUDENT_H
#define LEARN_STUDENT_H

#include <iostream>
#include <string>
#include <valarray>

namespace L14_2 {
    //  private inheritance
    class Student: private std::string, private std::valarray<double> {
    private:
        typedef std::valarray<double> NumberArray;
        //  no more needed these private properties...
//        std::string _name;
//        NumberArray _scores;
        //  打印的方法
        std::ostream & output(std::ostream & os) const;
    public:
        //  because of private inheritance, here call base class constructor
        Student(): std::string("none"), NumberArray() {};
        explicit Student(const std::string & name): std::string(name), NumberArray() {};
        explicit Student(int size): std::string("null"), NumberArray(size) {};
        Student(const std::string & name, int size): std::string(name), NumberArray(size) {};
        Student(const std::string & name, const NumberArray & list): std::string(name), NumberArray(list) {};
        Student(const char * str, const double * pd, int size): std::string(str), NumberArray(pd, size) {};

        ~Student() {};
        double get_average() const;
        const std::string & get_name() const;
        //  operator overload
        double & operator[](int i);
        //  取 scores 里的值, 不改变对象
        double operator[](int i) const;

        //  friend
        //  >> stu
        friend std::istream & operator>>(std::istream & is, Student & stu);
        //  make std::getline suitable for stu instance
        friend std::istream & getline(std::istream & is, Student & stu);
        //  << stu
        friend std::ostream &operator<<(std::ostream & os, const Student & stu);
    };
}

#endif //LEARN_STUDENT_H
