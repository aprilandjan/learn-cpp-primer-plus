//
// Created by May on 2019/1/10.
//

#ifndef LEARN_NESTED_H
#define LEARN_NESTED_H

#include <iostream>

namespace L14_4 {
    using std::cout;
    using std::endl;

    template <class T>
    class Nested {
    private:
        //  nested template class member
        template <class K>
                class Target {
                private:
                    K val;
                public:
                    Target(K v = 0): val(v) {};
                    void show() const {
                        cout << val << endl;
                    }
                    K get_value() const {
                        return val;
                    }
                };
        Target<T> q;
        Target<int> n;
    public:
        Nested(T t, int i): q(t), n(i) {};
        //  another template method
        template <class K>
        K output(K k, T t) {
            return (n.get_value() + q.get_value()) * k / t;
        }
        void show() const {
            q.show();
            n.show();
        }
    };
}


#endif //LEARN_NESTED_H
