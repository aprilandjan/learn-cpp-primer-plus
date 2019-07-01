//
// Created by May on 2019/7/1.
//

#include "use_move_semantics.h"

namespace L18_1 {
    using namespace std;

    //  class interface
    class Useless {
    private:
        int n;
        char * pc;
        static int count;
        void showObject() const;
    public:
        Useless();
        explicit Useless(int k);
        Useless(int k, char ch);
        Useless(const Useless & f); // copy reference constructor
        Useless(Useless && f); // move constructor, Useless x(u)?;
        ~Useless();
        Useless operator+(const Useless & f) const;     // u1 + u2
        void showData() const;
    };

    //  class implementation
}

void test_useless() {
    using namespace L18_1;
}