//
// Created by May on 2019/1/10.
//

#ifndef LEARN_PARAM_H
#define LEARN_PARAM_H

#include "iostream"

namespace L14_4 {
    //  use template as template param
    template <template <typename T> typename K>
    class Param {
    private:
        K<int> s1;
        K<double> s2;
    public:
        Param() {};
        //  assume that K has push/pop method
        //  can we really do such assumption???
        bool push(int a, double x) {
            return s1.push(a) && s2.push(x);
        }
        bool pop(int  & a, double & x) {
            return s1.pop(a) && s2.pop(x);
        }
    };
}

#endif //LEARN_PARAM_H
