//
// Created by May on 2018/11/25.
//

#ifndef LEARN_STACK_H
#define LEARN_STACK_H

//  定义 Item 为 unsigned long
typedef unsigned long Item;

namespace L10_3 {
    class Stack {
    private:
        enum {MAX = 10};
        Item items[MAX];
        int count;
    public:
        Stack();
        bool is_empty() const;
        bool is_full() const;
        bool push(const Item & item);
        bool pop(Item & item);
    };
}


#endif //LEARN_STACK_H
