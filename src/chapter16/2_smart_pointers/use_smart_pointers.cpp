//
// Created by May on 2019/5/4.
//

#include "use_smart_pointers.h"

#include <iostream>
#include <string>

//  provide smart pointer declarations
#include <memory>

namespace L16_1 {
    using namespace std;

    class Report {
    private:
        string _str;
    public:
        //  call std::string copy-constructor
        Report(const string s): _str(s) {
            cout << "Object created!\n";
        }
        ~Report() {
            cout << "Object deleted...\n";
        }
        void comment() const {
            cout << _str << "\n";
        }
    };
}

void use_smart_pointers() {
    using namespace L16_1;
    using namespace std;

    {
        auto_ptr<Report> ps(new Report("I'm using auto pointer!"));
        //  ps is actually an object. it override operator->
        ps->comment();
    }

    {
        shared_ptr<Report> ps(new Report("I'm using shared pointer!"));
        ps->comment();
    }

    {
        unique_ptr<Report> ps(new Report("I'm using unique pointer!"));
        //  same as above...
        ps->comment();
    }

    {
        //  this is auto variable, it is on stack, NOT heap
        string s("Just curious about c++...");

        //  use address on heap, when destruct, will cause 'delete xxx', that is actually an error
        shared_ptr<string> ps(&s);

        cout << "s: " << s;
    }
}

void why_not_use_auto_pointer() {
    using namespace std;

    auto_ptr<string> films[5] = {
            auto_ptr<string>(new string("The Iron Man")),
            auto_ptr<string>(new string("The amazing four")),
            auto_ptr<string>(new string("Capital America")),
            auto_ptr<string>(new string("The spiderman")),
            auto_ptr<string>(new string("The superman")),
    };

    //  when dispose, these two auto pointer will both try to free same memory on heap
    auto_ptr<string> pwin;
    pwin = films[2];  // film[2] lose owner ship， point to a null pointer

    std::cout << "The mavel movies are:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << *films[i] << std::endl;
    }
    std::cout << "The winner is " << *pwin << "!\n";
//    cin.get();
}

// C++ 11 support shared pointer
void use_shared_pointer() {
    using namespace std;

    shared_ptr<string> films[5] = {
            shared_ptr<string>(new string("The Iron Man")),
            shared_ptr<string>(new string("The amazing four")),
            shared_ptr<string>(new string("Capital America")),
            shared_ptr<string>(new string("The spiderman")),
            shared_ptr<string>(new string("The superman")),
    };

    shared_ptr<string> pwin;
    //  point to same string, reference count ++
    pwin = films[2];

    std::cout << "The mavel movies are:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << *films[i] << std::endl;
    }
    std::cout << "The winner is " << *pwin << "!\n";
//    cin.get();
}

void use_unique_pointer() {
    using namespace std;

    unique_ptr<string> films[5] = {
            unique_ptr<string>(new string("The Iron Man")),
            unique_ptr<string>(new string("The amazing four")),
            unique_ptr<string>(new string("Capital America")),
            unique_ptr<string>(new string("The spiderman")),
            unique_ptr<string>(new string("The superman")),
    };

    unique_ptr<string> pwin;
    //  unique pointer cannot be rvalue when assign directly
//    pwin = films[2];
    //  when use std::move to pass ownership, it will be like auto_ptr
    pwin = std::move(films[2]);

    std::cout << "The mavel movies are:\n";
    for (int i = 0; i < 5; i++) {
        if (films[i] != nullptr) {
            std::cout << *films[i] << std::endl;
        } else {
            std::cout << i << " is empty" << std::endl;
        }
    }
    std::cout << "The winner is " << *pwin << "!\n";
}