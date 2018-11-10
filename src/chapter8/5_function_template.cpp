//
// Created by May on 2018/11/10.
//

#include "5_function_template.h"
#include "iostream"

// 定义函数模板原型
template <typename T>
void Swap(T & a, T & b);

void template_swap() {
    using namespace std;
    int i = 100;
    int j = 200;
    cout << "i = " << i << "; j = " << j << ".\n";
    cout << "using compiler generated int swapper: \n";
    Swap(i, j);
    cout << "now, i = " << i << "; j = " << j << ".\n";

    char a = 'u';
    char b = 'v';
    cout << "Before: a = " << a << "; b = " << b << ".\n";
    Swap(a, b);
    cout << "After: a = " << a << "; b = " << b << ".\n";
}

template <typename T>
//  a, b 都是 reference
void Swap(T & a, T & b) {
    //  直接使用泛型 T 定义临时变量
    T temp = a;
    a = b;
    b = temp;
}