//
// Created by merlin.ye on 2018/12/30.
//

#ifndef LEARN_STACK_H
#define LEARN_STACK_H

namespace L14_4 {
    /**
     * 栈：数据存入栈顶，先进后出
     */
     // define class template T, same as typescript generic
    template <class T>
    class Stack {
    private:
        enum {MAX = 10};
        T items[MAX];
        int count;
    public:
        Stack();
        bool is_empty() const;
        bool is_full() const;
        bool push(const T & item);
        bool pop(T & item);
    };

    // the specialization must included in same file...
    // each implementation must be started with template usage
    template <class T>
    Stack<T>::Stack() {
        count = 0;
    }

    template <class T>
    bool Stack<T>::is_empty() const {
        return count == 0;
    }

    template <class T>
    bool Stack<T>::is_full() const {
        return count == MAX;
    }

    template <class T>
    bool Stack<T>::push(const T &item) {
        if (is_full()) {
            return false;
        }
        items[count++] = item;
        return true;
    }

    template <class T>
    bool Stack<T>::pop(T &item) {
        if (is_empty()) {
            return false;
        }
        //  相当于给引用地址赋值...
        item = items[--count];
        return true;
    }
}

#endif //LEARN_STACK_H
