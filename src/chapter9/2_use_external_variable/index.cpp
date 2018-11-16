//
// Created by May on 2018/11/16.
//

#include <iostream>
#include "support.h"

using namespace std;

//  定义全局变量 warming
double warming = 0.3;

//  定义仅文件内可访问的变量
static double temp_now = 100;

//  以下两个声明, 如果引入了 support.h, 可以省略
//void update(double dt);
//void local();

int use_external() {
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    local();
    cout << "Global warming is " << warming << " degrees.\n";

    cout << "in use_external(), address of variables:\n";
    cout << "&warming=" << &warming << endl;
    cout << "&temp_now=" << &temp_now << endl;
    remote_access();

    return 0;
}
