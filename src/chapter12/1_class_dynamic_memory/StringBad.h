//
// Created by May on 2018/12/4.
//

#ifndef LEARN_STRINGBAD_H
#define LEARN_STRINGBAD_H

#include <iostream>

namespace L12_1 {
    class StringBad {
    private:
        char * str;
        int len;
        //  类的静态属性. 这里只能声明（说明*如何*分配内存），而不能直接赋值（*实际*分配内存）
        static int num_strings;
    public:
        StringBad(const char * s);
        StringBad();
        ~StringBad();
        //  friend function
        friend std::ostream & operator<<(std::ostream & os, const StringBad & str);
    };
}

#endif //LEARN_STRINGBAD_H
