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
//        T items[MAX];
        T * items;
        int limit;
        int count;
    public:
        explicit Stack(int lim = MAX);
        Stack(const Stack & s);
        ~Stack() {
            delete [] items;
        }
        bool is_empty() const;
        bool is_full() const;
        bool push(const T & item);
        bool pop(T & item);

        //  赋值运算符函数
        Stack & operator=(const Stack & s);
    };

    // the specialization must included in same file...
    // each implementation must be started with template usage
    template <class T>
    Stack<T>::Stack(int lim) {
        limit = lim;
        count = 0;
        items = new T[limit];
    }

    template <class T>
    Stack<T>::Stack(const Stack<T> &s) {
        limit = s.limit;
        count = s.count;
        items = new T[limit];
        //  copy value
        for (int i = 0; i < count; i++) {
            items[i] = s.items[i];
        }
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

    template <class T>
    Stack<T>& Stack<T>::operator=(const Stack<T> &s) {
        if (this == &s) {
            //  this: a address
            // *this: get the value at the address, I.E. a reference
            return *this;
        }
        delete [] items;
        limit = s.limit;
        count = s.count;
        items = new T[limit];
        //  copy value
        for (int i = 0; i < count; i++) {
            items[i] = s.items[i];
        }
        return *this;
    }
}

#endif //LEARN_STACK_H
