//
// Created by May on 2019/5/1.
//

#include "use_rtti.h"

#include <iostream>
//  provide std::rand
#include <cstdlib>
#include <ctime>

namespace L15_5 {
    using std::cout;
    class Grand {
    private:
        int _hold;
    public:
        Grand(int h = 0): _hold(h) {};
        virtual void speak() const {
            cout << "I am a grand class!\n";
        }
        virtual int get_value() const {
            return _hold;
        }
    };

    class Superb: public Grand {
    public:
        Superb(int h = 0): Grand(h) {};
        void speak() const {
            cout << "I am a superb class!\n";
        }
        virtual void say() const {
            cout << "I hold the superb value of " << this->get_value() << "!\n";
        }
    };

    class Magnificent: public Superb {
    private:
        char _ch;
    public:
        Magnificent(int h = 0, char c = 'A'): Superb(h), _ch(c) {};
        void speak() const {
            cout << "I aam a magnificent class!!!\n";
        }
        void say() const {
            cout << "I hold the character " << _ch << " and the integer " << this->get_value() << "!\n";
        }
    };
}

L15_5::Grand * get_one();

void use_rtti() {
    std::cout << "rtti:\n";

    using namespace L15_5;
    using std::cout;
    using std::endl;
    using std::rand;

    Grand * pg;
    Superb * ps;
    for(int i = 0; i < 5; i++) {
        std::cout << i << ":\t\n";
        pg = get_one();
        //  pg certainly have 'speak'
        pg->speak();
        //  check if it is able to cast to derived class pointer
        if (ps = dynamic_cast<Superb *>(pg)) {
            ps->say();
            cout << "\n";
        } else {
            cout << "I am not able to say...\n\n";
        }
    }
}

L15_5::Grand * get_one() {
    using namespace L15_5;

    //  a pointer points to the base class
    Grand * p;
    //  int between 0 and RAND_MAX
    switch(std::rand() % 3) {
        case 0:
            p = new Grand(std::rand() % 100);
            break;
        case 1:
            p = new Superb(std::rand() % 100);
            break;
        case 2:
            p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
            break;
    }

    //  a base-class pointer may actually points to derived class
    return p;
}