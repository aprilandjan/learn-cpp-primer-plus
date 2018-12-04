//
// Created by May on 2018/12/4.
//

#include <iostream>
#include "use_string.h"
#include "./StringBad.h"

void use_string_bad() {
    using namespace std;
    using namespace L12_1;

    StringBad a("abc");
    cout << a << "\n";
}