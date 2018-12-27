//
// Created by May on 2018/12/26.
//

#include <iostream>
#include "Worker.h"

namespace L14_3 {
    //  必须要实现该纯虚函数
    Worker::~Worker() {};

    void Worker::data() const {
        std::cout << "Worker[name=" << _name << ", id=" << _id << "]\n";
    }

    void Worker::get() {
        getline(std::cin, _name);
        std::cout << "Enter worker'is id: \n";
        std::cin >> _id;

        //  wait until enter a '\n'
        while(std::cin.get() != '\n') {
            continue;
        }
    }

//    void Worker::set() {
//        std::cout << "Enter worker's name: \n";
//        getline(std::cin, _name);
//        std::cout << "Enter worker'is id: \n";
//        std::cin >> _id;
//        //  wait until enter a '\n'
//        while(std::cin.get() != '\n') {
//            continue;
//        }
//    }
//
//    void Worker::show() const {
//        std::cout << "Worker[name=" << _name << ", id=" << _id << "]\n";
//    }

    //  sub-class
    void Waiter::set() {
        Worker::set();
        std::cout << "Enter waiter's restaurant: \n";
        getline(std::cin, _restaurant);
        while(std::cin.get() != '\n') {
            continue;
        }
    }
    void Waiter::show() const {
        std::cout << "Waiter:\n";
        Worker::show();
        std::cout << "works at " << _restaurant << " restaurant.\n";
    }

    //  another sub-class

    //  设置静态私有成员的值
    char * Singer::pv[] = {
            "other",
            "alto",
            "contralto",
            "soprano",
            "bass",
    };

    void Singer::set() {
        Worker::set();
        std::cout << "Enter number for singer's vocal range:\n";
        //  output available vocals
        int i;
        for (i = 0; i < VoiceType; i++) {
            std::cout << i << ": " << pv[i] << " ";
            if (i % 4 == 3) {
                std::cout << std::endl;
            }
        }
        if (i % 4 != 0) {
            std::cout << std::endl;
        }
        //  只能输入 [0~VoiceType)范围内的数值
        while(std::cin >> _voice && (_voice < 0 || _voice >= VoiceType)) {
            std::cout << "Please enter a value in range [0, " << VoiceType << ");\n";
        }
        while(std::cin.get() != '\n') {
            continue;
        }
    }
    void Singer::show() const {
        std::cout << "Singer:\n";
        Worker::show();
        std::cout << "Vocal range: " << pv[_voice] << std::endl;
    }
}