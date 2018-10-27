//
// Created by May on 2018/10/27.
//

#include "11_struct_as_param.h"
#include <iostream>


/* 计算两个结构和 */
const int MIN_PER_HOUR = 60;

struct travel_time {
    int hours;
    int mins;
};

//  结构 作为参数传递及返回
travel_time combine_travel_time(travel_time tt1, travel_time tt2) {
    travel_time total;
    total.mins = (tt1.mins + tt2.mins) % MIN_PER_HOUR;
    //  不用手动取整
    total.hours = (tt1.hours + tt2.hours) + (tt1.mins + tt2.mins) / MIN_PER_HOUR;
    //  尝试修改一下一个入参
    tt1.hours = 100;
    tt2.hours = 100;
    //  并不会改变实际入参的值
    return total;
}

int show_travel_time() {
    using namespace std;
    //  struct 结构初始化方法
    const travel_time tt1 = {5, 45};
    const travel_time tt2 = {1, 30};
    const travel_time total = combine_travel_time(tt1, tt2);
    cout << "Day1: " << tt1.hours << " hours, " << tt1.mins << " minutes\n";
    cout << "Day2: " << tt2.hours << " hours, " << tt2.mins << " minutes\n";
    cout << "The total time spent is: " << total.hours << " hours, " << total.mins << " minutes\n";
};
