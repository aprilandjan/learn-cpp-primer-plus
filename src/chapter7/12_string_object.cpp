//
// Created by May on 2018/10/28.
//

#include "12_string_object.h"
// 使用字符串对象的头文件
#include <string>
#include <iostream>

const int SIZE = 5;

// 数组作为参数，需要带上长度
void display_all_strings(const std::string list[], int n) {
    for(int i = 0; i < n; i++) {
        std::cout << i + 1 << " : " << list[i] << std::endl;
    }
}

int input_and_output_lines () {
    using namespace std;
    string list[SIZE];
    cout << "Enter your " << SIZE << " favorite fruit name: \n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " :";
        //  从输入流 CIN 中取一行，写入字符串地址
        getline(cin, list[i]);
    }
    cout << "Here's what you input:\n";
    display_all_strings(list, SIZE);
}