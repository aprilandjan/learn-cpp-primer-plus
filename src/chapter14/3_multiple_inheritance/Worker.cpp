//
// Created by May on 2018/12/26.
//

#include <iostream>
#include "Worker.h"

namespace L14_3 {
    //  必须要实现该纯虚函数
    Worker::~Worker() {};

    void Worker::set_data() {
        getline(std::cin, _name);
        std::cout << "Enter worker'is id: \n";
        std::cin >> _id;

        //  wait until enter a '\n'
        while(std::cin.get() != '\n') {
            continue;
        }
        std::cout << "done...";
    }

    void Worker::show_data() const {
        std::cout << "Worker[name=" << _name << ", id=" << _id << "]\n";
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
    //  implement protected method
    void Waiter::set_data() {
        std::cout << "Enter waiter's restaurant: \n";
        getline(std::cin, _restaurant);
        while(std::cin.get() != '\n') {
            continue;
        }
    }

    void Waiter::show_data() const {
        std::cout << "works at " << _restaurant << " restaurant.\n";
    }

    void Waiter::set() {
        std::cout << "Enter waiter's name:\n";
        Worker::set_data();
        set_data();
    }
    void Waiter::show() const {
        std::cout << "Waiter:\n";
        //  call base class data method
        Worker::show_data();
        show_data();
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

    void Singer::show_data() const {
        std::cout << "Vocal range: " << pv[_voice] << std::endl;
    }

    void Singer::set_data() {
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
        std::cin >> _voice;
        while(std::cin.get() != '\n') {
            continue;
        }
    }

    void Singer::set() {
        std::cout << "Enter singer's name:\n";
        Worker::set_data();
        set_data();
    }
    void Singer::show() const {
        std::cout << "Singer:\n";
        Worker::show_data();
        show_data();
    }

    // ==== MI class ====
    void SingerWaiter::show_data() const {
        Singer::show_data();
        Waiter::show_data();
    }

    void SingerWaiter::set_data() {
        Singer::set_data();
        Waiter::set_data();
    }

    void SingerWaiter::set() {
        std::cout << "Enter a singer-waiter's name:\n";
        Worker::set_data();
        set_data();
    }

    void SingerWaiter::show() const {
        std::cout << "SingerWaiter:\n";
        Worker::show_data();
        show_data();
    }
}