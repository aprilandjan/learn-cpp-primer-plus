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