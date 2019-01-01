//
// Created by merlin.ye on 2019/1/1.
//

#ifndef LEARN_ARRAYTP_H
#define LEARN_ARRAYTP_H

#include <iostream>

namespace L14_4 {
    //  array with ** template arguments **
    template <class T, int n>
    class ArrayTP {
    private:
        T ar[n];
    public:
        ArrayTP(){};
        explicit ArrayTP(const T & v);
        /** 取某个元素的引用？*/
        virtual T &operator[](int i);
        /** 取某个元素并复制一份？ */
        virtual T operator[](int i) const;
    };

    //  implements
    template <class T, int n>
    ArrayTP<T, n>::ArrayTP(const T &v) {
        for(int i = 0; i < n; i++) {
            ar[i] = v;
        }
    }

    template <class T, int n>
    T &ArrayTP<T, n>::operator[](int i){
        if(i < 0 || i > n) {
            //  cerr: something link console.error?
            std::cerr << "Error in array limits: " << i << " is out of range\n";
            //  exit: something like process.exit()?
            std::exit(EXIT_FAILURE);
        }
        //  this return an address, I.E a reference
        return ar[i];
    }

    template <class T, int n>
    T ArrayTP<T, n>::operator[](int i) const {
        //  same as previous?
        if(i < 0 || i > n) {
            //  cerr: something link console.error?
            std::cerr << "Error in array limits: " << i << " is out of range\n";
            //  exit: something like process.exit()?
            std::exit(EXIT_FAILURE);
        }
        //  this return an address, I.E a reference
        return ar[i];
    }
}

#endif //LEARN_ARRAYTP_H
