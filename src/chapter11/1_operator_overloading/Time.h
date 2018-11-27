//
// Created by May on 2018/11/27.
//

#ifndef LEARN_TIME_H
#define LEARN_TIME_H

namespace L11_1 {
    class Time {
    private:
        int hour;
        int minute;
    public:
        //  多种构造函数
        Time();
        Time(int h, int m = 0);
        void addMin(int h);
        void addHour(int m);
        void reset(int h = 0, int m = 0);
        //  声明以下类方法不会修改该实例
        Time sum(const Time & t) const;
        void show() const;
        //  运算符重载的原型
        Time operator+(const Time & t) const;
    };
}


#endif //LEARN_TIME_H
