//
// Created by May on 2018/12/10.
//

#ifndef LEARN_QUEUE_H
#define LEARN_QUEUE_H

#include "./Item.h"

namespace L12_2 {
    class Queue {
        //  单向*链表*的节点
        struct Node {
            Item item;
            //  下一个节点(node)的地址
            struct Node * next;
        };
        enum {
            DEFAULT_SIZE = 10
        };
    private:
        //  第一个以及最后一个节点
        Node * _first;
        Node * _last;
        //  当前队列里的节点数
        int _size;
        //  最大允许的节点数
        const int _max_size;
        //  put them in "private" field to prevent implicit calling.
        Queue(const Queue & q): _max_size(0) {
            //  just to prevent Queue q(anotherQ)
        };
        Queue &operator=(const Queue & q) {
            //  just to prevent re-assign queue: q = anotherQ
            return *this;
        };
    public:
        Queue(int max_size = DEFAULT_SIZE);
        ~Queue();
        bool is_empty() const;
        bool is_full() const;
        bool enqueue(const Item &item);
        bool dequeue(const Item &item);
    };
}

#endif //LEARN_QUEUE_H
