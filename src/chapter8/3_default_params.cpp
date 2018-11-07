//
// Created by May on 2018/11/7.
//

#include "3_default_params.h"
#include "iostream"

const int ArSize = 80;

//  原型里可以添加默认参数
char * left_substr(const char * str, int n = 1);

void get_sub_string() {
    using namespace std;

    char sample[ArSize];

    cout << "Enter a string:\n";
    cin.get(sample, ArSize);

    char * p_sub1 = left_substr(sample);
    cout << "After substr default: " << p_sub1 << endl;

    delete p_sub1; // 释放字符数组内存

    char * p_sub2 = left_substr(sample, 3);
    cout << "After substr 3: " << p_sub2 << endl;

    delete p_sub2;
}

//  定义时不需要
char * left_substr(const char * str, int n) {
    if (n < 0) {
        n = 0;
    }
    //  指向 char 数组的指针
    char * p = new char[n + 1];
    int i = 0;
    for (i; i < n && str[i]; i++) {
        p[i] = str[i];
    }
    //  最后一位填充字符串结尾字符 \0
    p[n] = '\0';
    return p;
}