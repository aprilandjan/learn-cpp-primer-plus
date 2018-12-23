//
// Created by May on 2018/12/22.
//

#include <iostream>
#include "Student.h"

namespace L14_1 {
    double Student::get_average() const {
        if (_scores.size() > 0) {
            return _scores.sum() / _scores.size();
        } else {
            return 0;
        }
    }
    const std::string& Student::get_name() const {
        return _name;
    }
    //  拿到数字的值
    double Student::operator[](int i) const {
        //  使用了 valarray 已有的方法
        return _scores[i];
    }
    //  拿到数字的引用
    double& Student::operator[](int i) {
        return _scores[i];
    }

    //  private
    std::ostream& Student::output(std::ostream &os) const {
        int i = 0;
        int size = _scores.size();
        if (size > 0) {
            for  (i = 0; i < size; i++) {
                os << _scores[i] << " ";
                //  每行最多显示5个数字
                if (i % 5 == 4) {
                    os << std::endl;
                }
            }
        } else {
            os << "empty array";
        }
        return os;
    }

    //  friends
    std::istream& operator>>(std::istream &is, Student &stu) {
        is >> stu._name;
        return is;
    }
    //  使用 string 类里的友元函数 getline
    std::istream& getline(std::istream &is, Student &stu) {
        //  where is get line?
        getline(is, stu._name);
        return is;
    }
    std::ostream& operator<<(std::ostream &os, const Student &stu) {
        os << "Scores for " << stu._name << ":\n";
        stu.output(os);
        return os;
    }
}