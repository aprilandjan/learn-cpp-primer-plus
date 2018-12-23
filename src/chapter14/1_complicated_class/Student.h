//
// Created by May on 2018/12/22.
//

#ifndef LEARN_STUDENT_H
#define LEARN_STUDENT_H

#include <iostream>
#include <string>
#include <valarray>

namespace L14_1 {
//    typedef std::valarray<double> NumberArray;
    class Student {
    private:
        //  声明类型放在 private 里，类外不能使用
        typedef std::valarray<double> NumberArray;
        std::string _name;
        NumberArray _scores;
        //  打印的方法
        std::ostream & output(std::ostream & os) const;
    public:
        Student(): _name("none"), _scores() {};
        //  explicit 约束， 避免隐式 stu = 5
        explicit Student(const std::string & name): _name(name), _scores() {};
        explicit Student(int size): _name("null"), _scores(size) {};
        Student(const std::string & name, int size): _name(name), _scores(size) {};
        Student(const std::string & name, const NumberArray & list): _name(name), _scores(list) {};
        Student(const char * str, const double * pd, int size): _name(str), _scores(pd, size) {};

        ~Student() {};
        double get_average() const;
        const std::string & get_name() const;
        //  operator overload
        //  Todo: ??
        double & operator[](int i);
        //  取 scores 里的值
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
