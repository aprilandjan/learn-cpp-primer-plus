//
// Created by May on 2019/7/1.
//

#include "use_move_semantics.h"
#include <iostream>

namespace L18_1 {
    using namespace std;

    //  class interface
    //  a class uses dynamic memory allocation
    class Useless {
    private:
        int n;
        char * pc;
        static int count;   //  track instance count
        void showObject() const;
    public:
        Useless();
        explicit Useless(int k);
        Useless(int k, char ch);
        Useless(const Useless & f); // copy reference constructor, Useless(u)
        Useless(Useless && f); // move constructor, Useless(u + v);
        ~Useless();
        Useless operator+(const Useless & f) const;     // u + v
        void showData() const;
    };

    //  this is the proper way to init a 'private static member in class'
    //  Clion gives no hint
    int Useless::count = 0;

    //  class implementation
    Useless::Useless() {
        count++;
        n = 0;
        pc = nullptr;
        cout << "Default constructor called, number of instance: " << count << endl;

        showObject();
    }

    Useless::Useless(int k): n(k) {
        count++;
        cout << "int constructor called, number of instance: " << count << endl;
        //  allocate array of char, without filling anything into it
        pc = new char[n];
        showObject();
    }

    Useless::Useless(int k, char ch): n(k) {
        count++;
        cout << "int and char constructor called, number of instance: " << count << endl;

        //  allocate array of char, and fill with ch
        pc = new char[n];
        for(int i = 0; i < n; i++) {
            pc[i] = ch;
        }
        showObject();
    }

    Useless::Useless(const L18_1::Useless &f): n(f.n) {
        count++;
        cout << "copy const constructor called, number of instance: " << count << endl;

        //  allocate array of char, and copy from f.pc
        pc = new char[n];
        for(int i = 0; i < n; i++) {
            pc[i] = f.pc[i];
        }
        showObject();
    }

    Useless::Useless(L18_1::Useless && f) {
        count++;
        cout << "move constructor called, number of instance: " << count << endl;

        pc = f.pc;  //  just steal address, not allocate new address
        f.pc = nullptr; //  this make f.pc hold nothing
        f.n = 0;
        showObject();
    }

    Useless::~Useless() {
        cout << "\ndestructor called, instance left: " << --count << endl;
        cout << "deleted one: \n";
        showObject();
        delete [] pc;   //  delete the one created by 'new'

        cout << endl;
    }

    //  returns a temp reference of right-value
    Useless Useless::operator+(const L18_1::Useless &f) const {
        cout << "Entering operator+()\n";
        //  concat the two, manually
        Useless temp = Useless(n + f.n);
        for(int i = 0; i < n; i++) {
            temp.pc[i] = pc[i];
        }
        for(int i = n; i < temp.n; i++) {
            temp.pc[i] = f.pc[i - n];
        }
        cout << "temp object: \n";
        cout << "Leaving operator+()\n";
        return temp;
    }

    void Useless::showObject() const {
        cout << "list size: " << n << ", data address: " << (void *) pc << endl;
    }

    void Useless::showData() const {
        cout << "Address: " << (void *) pc << " ; ";
        if (n == 0) {
            cout << "(instance empty)";
        } else {
            for(int i = 0; i < n; i++) {
                cout << pc[i];
            }
        }
        cout << endl;
    }
}

void test_useless() {
    using namespace L18_1;
//    using namespace std;

    //  10 x 'x'
    Useless one(10, 'x');
    Useless two = one;  //  calls 'copy constructor'
    Useless three(20, 'o');
    //  first, '+'
    //  then, 'copy constructor?'
    //  the mingw compiler doesn't call 'move constructor', but still transfer ownership of 'temp'...
    Useless four(one + three);

    cout << "\nOne: \n";
    one.showData();
    cout << "\nTwo: \n";
    two.showData();
    cout << "\nThree: \n";
    three.showData();
    cout << "\nFour: \n";
    four.showData();
}