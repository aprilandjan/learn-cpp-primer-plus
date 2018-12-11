//
// Created by May on 2018/12/10.
//

//  provide std::rand()
#include <cstdlib>
#include "Queue.h"

namespace L12_2 {
    //============================
    //          Queue
    //============================
    //  为了能初始化私有常量(const), 必须使用 "成员初始化列表" member initializer list
    Queue::Queue(int size): _max_size(size), _first(nullptr), _last(nullptr), _size(0) {
        //  do nothing because "member initializer list"
    }
    Queue::~Queue() {
        // 确保链表中的节点都被清掉了
        Node * temp;
        //  只要它存在
        while(_first != nullptr) {
            temp = _first;
            _first = _first->next;
            delete temp;
        }
    }
    /**
     * 队列是否是空的
     * @return
     */
    bool Queue::is_empty() const {
        return _size == 0;
    }
    /**
     * 队列是否是满的
     * @return
     */
    bool Queue::is_full() const {
        return _size == _max_size;
    }
    /**
     * 获取当前队列长度
     * @return
     */
    int Queue::get_size() const {
        return _size;
    }
    /**
     * 取队列里的第一个存储的东西
     * @return
     */
    const Item& Queue::first() const {
        return _first->item;
    }
    /**
     * 推入队列, push
     * @param item
     * @return
     */
    bool Queue::enqueue(const Item &item) {
        if (is_full()) {
            return false;
        }
        //  create a new node
        Node * node = new Node;
        node->item = item;
        node->next = nullptr;
        //  空队列
        if (_size == 0) {
            _first = _last = node;
        } else {
            _last->next = node;
            _last = node;
        }
        _size++;
        return true;
    }
    /**
     * 从队列删除第一个，shift
     * @return
     */
    bool Queue::dequeue(const Item &item) {
        if (is_empty()) {
            return false;
        }
        Node * temp = _first;
        if (temp == nullptr) {
            _first = _last = nullptr;
        } else {
            _first = _first->next;
        }
        //  因为在 enqueue 时通过 new 新建了节点，此时需要删掉
        delete temp;
        _size--;
        return true;
    }

    //========================
    //      Customer
    //========================
    void Customer::init(long arrive_time) {
        //  std::rand() => 0 ~ RAND_MAX
        _process_time = std::rand() % 3 + 1;
        _arrive_time = arrive_time;
    }
}