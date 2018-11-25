//
// Created by May on 2018/11/25.
//

#include "stack.h"

using namespace L10_3;

Stack::Stack() {
    count = 0;
}

bool Stack::is_empty() const {
    return count == 0;
}

bool Stack::is_full() const {
    return count == MAX;
}

bool Stack::push(const Item &item) {
    if (is_full()) {
        return false;
    }
    items[count++] = item;
    return true;
}

bool Stack::pop(Item &item) {
    if (is_empty()) {
        return false;
    }
    //  相当于给引用地址赋值...
    item = items[--count];
    return true;
}