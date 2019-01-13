//
// Created by May on 2019/1/12.
//

#include "HasFriend.h"

void use_friend_in_template() {
    using namespace L14_4;

    cout << "When no object declared: ";
    counts<int>();

    HasFriend<int> hf1(10);
    cout << "After hf1 declared: ";
    counts<int>();

    HasFriend<int> hf2(30);
    cout << "After hf2 declared: ";
    counts<int>();

    HasFriend<double> hf3(2.61);
    cout << "After hf3 declared: ";
    counts<double>();

    reports(hf1);
    reports(hf2);
    reports(hf3);
}

