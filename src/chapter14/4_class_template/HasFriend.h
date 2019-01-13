//
// Created by May on 2019/1/12.
//

#ifndef LEARN_HASFRIEND_H
#define LEARN_HASFRIEND_H

#include <iostream>

namespace L14_4 {
    using std::cout;
    using std::endl;

    //  template prototypes
    template <typename T> void counts();
    template <typename T> void reports(T &);

    template <typename T>
    class HasFriend {
    private:
        T item;
        //  seems like "instance count"?
        //  not shared by different specialization
        static int _count;
    public:
        HasFriend(const T & i): item(i) {
            _count ++;
        }

        ~HasFriend() {
            _count --;
        }

        // it is just friend for some certain specialized class
        friend void counts<T>();
        //  use template params
        friend void reports<>(HasFriend<T> &);
    };

    //  implementation
    template <typename T>
    int HasFriend<T>::_count = 0;

    template <typename T>
    void counts() {
//        cout << "int count: " << HasFriend<int>::_count << ";\n";
//        cout << "double count: " << HasFriend<double>::_count << ";\n\n";
        cout << "template size: " << sizeof(HasFriend<T>) << ";\n";
        //  because it is friend of HasFriend<T>, it can access private member
        cout << "template counts(): " << HasFriend<T>::_count << ";\n\n";
    }

    template <typename T>
    void reports(T & hf) {
        cout << hf.item << endl;
    }

//    void reports(HasFriend<int> & hf) {
//        cout << "HasFriend<int>: " << hf.item << endl;
//    }
//
//    void reports(HasFriend<double> & hf) {
//        cout << "HasFriend<double>: " << hf.item << endl;
//    }
}

#endif //LEARN_HASFRIEND_H
