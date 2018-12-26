//
// Created by May on 2018/12/26.
//

#ifndef LEARN_WORKER_H
#define LEARN_WORKER_H

//  this provide *string* class
// https://stackoverflow.com/questions/12824595/difference-between-cstring-and-string
#include <string>

namespace L14_3 {
    //  abstract base class
    class Worker {
    private:
        std::string _name;
        long _id;
    public:
        Worker(): _name("none"), _id(0){};
        Worker(const std::string & name, long id): _name(name), _id(id){};
        //  pure virtual destructor, make this an ABC
        virtual ~Worker() = 0;
        virtual void set();
        virtual void show() const;
    };

    class Waiter: public Worker {
    private:
        std::string _restaurant;
    public:
        Waiter(): Worker(), _restaurant("no where") {};
        Waiter(const std::string & name, long id, const std::string & restaurant): Worker(name, id), _restaurant(restaurant){};
        Waiter(const Worker & worker, const std::string & restaurant): Worker(worker), _restaurant(restaurant) {};

        void set();
        void show() const;
    };

    class Singer: public Worker {
    protected:
        enum {other, alto, contralto, soprano, bass};
        enum {VoiceType = 5};
    private:
        //  该静态私有成员只声明但未初始化
        static char *pv[VoiceType];
        int _voice;
    public:
        Singer(): Worker(), _voice(other){};
        Singer(const std::string & name, long id, int voice): Worker(name, id), _voice(voice){};
        Singer(const Worker & worker, int voice): Worker(worker), _voice(voice){};

        void set();
        void show() const;
    };
}

#endif //LEARN_WORKER_H
