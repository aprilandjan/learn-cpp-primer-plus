//
// Created by May on 2018/11/16.
//

#include <iostream>

//  warming 是来自 index.cpp 的变量
extern double warming;
//  那是否可以用此次编译中的其他变量(chapter8/3_default_params.cpp, ArSize)呢？
//  ...seems can't
extern const int ArSize ;

//  define prototype
void update(double dt);
void local();

//  单独使用 std 里的某个方法？...
using std::cout;
void update(double dt) {
    //  声明使用来自全局的 warming 变量, redundant
//    extern double warming;
    warming += dt;
    cout << "Update global warming to " << warming;
    cout << " degrees.\n";
//    cout << "===> ArSize = " << ArSize << std::endl;
}

void local()
{
    //  using local variable
    double warming = 0.5;

    cout << "Local warming = " << warming << " degrees.\n";
    //  使用 scope resolution operator 获取全局的变量
    cout << "But global warming = " << ::warming << " degrees.\n";
//    cout << "===> ArSize = " << ::ArSize << std::endl;
}

int temp_now = 300;

void remote_access() {
    cout << "remote access() reports the following address:\n";
    cout << "&warming=" << &warming << std::endl;
    cout << "&temp_now=" << &temp_now << std::endl;
}
