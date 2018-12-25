//
// Created by May on 2018/12/25.
//

#include "Student.h"

namespace L14_2 {
    double Student::get_average() const {
        // use Base class method to get value
        if(NumberArray::size() > 0) {
            return NumberArray::sum() / NumberArray::size();
        }
        return 0;
    }
    const std::string& Student::get_name() const {
        //  use force-type-cast to get reference of string
        // this: address
        // *this: the instance at the address
        // const std::string &: declare as "const string reference"
        return (const std::string &)*this;
    }
    double Student::operator[](int i) const {
        return NumberArray::operator[](i);
    }
    double& Student::operator[](int i) {
        return NumberArray::operator[](i);
    }

    //  private
    std::ostream& Student::output(std::ostream &os) const {
        int i;
        int size = NumberArray::size();
        if (size > 0) {
            for (i = 0; i < size; i++) {
                os << NumberArray::operator[](i) << " ";
                if (i % 5 == 4) {
                    os << std::endl;
                }
            }
            if (i % 5 != 0) {
                os << std::endl;
            }
        } else {
            os << "empty array ";
        }
        return os;
    }
    //  friends
    std::istream& operator>>(std::istream &is, Student &stu) {
        is >> (std::string &)stu;
        return is;
    }
    //  使用 string 类里的友元函数 getline
    std::istream& getline(std::istream &is, Student &stu) {
        //  where is get line?
        getline(is, (std::string &)stu);
        return is;
    }
    std::ostream& operator<<(std::ostream &os, const Student &stu) {
        os << "Scores for " << (std::string &)stu << ":\n";
        stu.output(os);
        return os;
    }
}