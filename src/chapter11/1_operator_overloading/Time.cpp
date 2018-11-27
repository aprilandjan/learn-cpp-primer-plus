//
// Created by May on 2018/11/27.
//

#include <iostream>
#include "Time.h"

using namespace L11_1;

Time::Time() {
    hour = 0;
    minute = 0;
}

Time::Time(int h, int m) {
//    hour = h;
//    minute = m;
    reset(h, m);
}

void Time::addHour(int h) {
    hour += h;
}

void Time::addMin(int m) {
    int tm = m + minute;
    int h = tm / 60;
    int rm = tm % 60;
    addHour(h);
    minute = rm;
}

void Time::reset(int h, int m) {
    hour = 0;
    minute = 0;
    addHour(h);
    addMin(m);
}

//  返回新的实例，不修改当前实例
Time Time::sum(const Time &t) const {
    Time total;
    total.reset(hour, minute);
    total.addHour(t.hour);
    total.addMin(t.minute);
    return total;
}

//  仅打印，不修改实例
void Time::show() const {
    std::cout<< "Time [hour=" << hour << ", minute=" << minute << "]\n";
}