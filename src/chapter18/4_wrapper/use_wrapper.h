//
// Created by May on 2019/7/9.
//

#ifndef LEARN_USE_WRAPPER_H
#define LEARN_USE_WRAPPER_H

void wrapper_of_callable();

namespace L18_4 {
    #include <iostream>

    template<typename T, typename F>
    T use_f(T v, F f) {
        static int count = 0;
        count ++;
        std::cout << " use_f count = " << count << ", &count = " << &count << std::endl;
        return f(v);
    }

    class Fp {
    private:
        double _z;
    public:
        Fp(double z = 1.0): _z(z) {};
        double operator()(double p) {
            return _z * p;
        }
    };

    class Fq {
    private:
        double _z;
    public:
        Fq(double z = 1.0): _z(z) {};
        double operator()(double q){
            return _z * q;
        }
    };
}
#endif //LEARN_USE_WRAPPER_H
