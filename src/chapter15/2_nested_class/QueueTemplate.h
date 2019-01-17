//
// Created by May on 2019/1/17.
//

#ifndef LEARN_QUEUETEMPLATE_H
#define LEARN_QUEUETEMPLATE_H

namespace L15_2 {
    template <class T>
    class QueueTemplate {
    private:
        enum {
            LIMIT = 10
        };
        //  private nested class
        class Node {
        public:
            T item;
            Node * next;
            Node(const T & i): item(i), next(nullptr){};
        };
        Node * _first;
        Node * _last;
        int _size;
        int _limit;
        //  ...
        QueueTemplate(const QueueTemplate & q): _limit(0){};
        //  赋值构造函数
        QueueTemplate &operator=(const QueueTemplate & q) {
            return *this;
        };
    public:
        QueueTemplate(int limit = LIMIT);
        ~QueueTemplate();
        bool is_empty() const {
            return _size == 0;
        }
        bool is_full() const {
            return _size == _limit;
        }
        int get_size() const {
            return _size;
        }
        bool enqueue(const T & i);
        bool dequeue(T & i);
    };

    //  method
    template <class T>
    QueueTemplate<T>::QueueTemplate(int limit): _limit(limit) {
        _first = _last = nullptr;
        _size = 0;
    }

    template <class T>
    QueueTemplate<T>::~QueueTemplate() {
        Node * temp;
        while(_first != nullptr) {
            temp = _first;
            _first = _first->next;
            delete temp;
        }
    }

    template <class T>
    bool QueueTemplate<T>::enqueue(const T &i) {
        if (is_full()) {
            return false;
        }
        Node * add = new Node(i);
        _size++;
        if (_first == nullptr) {
            _first = add;
        } else {
            _last->next = add;
        }
        _last = add;
        return true;
    }

    template <class T>
    bool QueueTemplate<T>::dequeue(T &i) {  //  still quite confused why this "T & i" is needed...
        if (_first == nullptr) {
            return false;
        }
        _size--;
        Node * f = _first->next;
        delete _first;
        _first = f;
        if (_size == 0) {
            _last = nullptr;
        }
        return true;
    }
}

#endif //LEARN_QUEUETEMPLATE_H
