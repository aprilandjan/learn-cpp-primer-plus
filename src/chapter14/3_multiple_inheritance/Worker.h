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
    protected:
        virtual void show_data() const;
        virtual void set_data();
    public:
        Worker(): _name("none"), _id(0){};
        Worker(const std::string & name, long id): _name(name), _id(id){};
        //  pure virtual destructor, make this an ABC
        virtual ~Worker() = 0;
        //  these two functions must be set as = 0, why????
        virtual void set() = 0;
        virtual void show() const = 0;
    };

    //  virtual base class, which make it possible for MI
    class Waiter: virtual public Worker {
    private:
        std::string _restaurant;
    protected:
        void show_data() const;
        void set_data();
    public:
        Waiter(): Worker(), _restaurant("no where") {};
        Waiter(const std::string & name, long id, const std::string & restaurant): Worker(name, id), _restaurant(restaurant){};
        Waiter(const Worker & worker, const std::string & restaurant): Worker(worker), _restaurant(restaurant) {};

        void set();
        void show() const;
    };

    class Singer: virtual public Worker {
    protected:
        enum {other, alto, contralto, soprano, bass};
        enum {VoiceType = 5};
    private:
        //  该静态私有成员只声明但未初始化
        static char *pv[VoiceType];
        int _voice;
    protected:
        void show_data() const;
        void set_data();
    public:
        Singer(): Worker(), _voice(other){};
        Singer(const std::string & name, long id, int voice): Worker(name, id), _voice(voice){};
        Singer(const Worker & worker, int voice): Worker(worker), _voice(voice){};

        void set();
        void show() const;
    };

    //  MI class
    class SingerWaiter: public Waiter, public Singer {
    protected:
        void show_data() const;
        void set_data();
    public:
        //  ... this is tooooooooo redundant and complex for coding
        SingerWaiter() {};
        SingerWaiter(const std::string & name, long id, const std::string & restaurant, int voice = other):
                Worker(name, id), Waiter(name, id, restaurant), Singer(name, id, voice) {};
        SingerWaiter(const Worker & worker, const std::string & restaurant, int voice = other):
                Worker(worker), Waiter(worker, restaurant), Singer(worker, voice) {};
        SingerWaiter(const Waiter & waiter, int voice = other):
                Worker(waiter), Waiter(waiter), Singer(waiter, voice) {};
        SingerWaiter(const Singer & singer, const std::string restaurant):
                Worker(singer), Waiter(singer, restaurant), Singer(singer) {};

        void set();
        void show() const;
    };
}

#endif //LEARN_WORKER_H
