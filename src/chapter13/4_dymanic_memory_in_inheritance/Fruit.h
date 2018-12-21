//
// Created by May on 2018/12/21.
//

#ifndef LEARN_DIMENSION_H
#define LEARN_DIMENSION_H

#include <iostream>

namespace L13_4 {
    class Fruit {
    private:
        char * _name;
    public:
        Fruit(const char * name = "null");
        Fruit(const Fruit & d);
        virtual ~Fruit();
        Fruit &operator=(const Fruit & d);
        friend std::ostream &operator<<(std::ostream & os, const Fruit & d);
    };

    //  derived class without dynamic memory
    class Apple: public Fruit {
    private:
        enum  {
            COL_LEN = 40,
        };
        char _color[COL_LEN];
    public:
        Apple(const char * name = "null", const char * color = "red");
        Apple(const Fruit & f, const char * color);
        friend std::ostream &operator<<(std::ostream & os, const Apple & d);
    };

    //  derived class with dynamic memory
    class Banana: public Fruit {
    private:
        char * _style;
    public:
        Banana(const char * name, const char * style = "none");
        Banana(const Fruit & f, const char * style = "none");
        Banana(const Banana & b);
        virtual ~Banana();
        Banana &operator=(const Banana & b);
        friend std::ostream &operator<<(std::ostream & os, const Banana & b);
    };
}


#endif //LEARN_DIMENSION_H
