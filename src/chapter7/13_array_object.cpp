//
// Created by May on 2018/10/29.
//

#include "13_array_object.h"

#include "iostream"
#include "string"
#include "array"

const int SEASON_COUNT = 4;
//  定于由 字符串对象 构成的 数组对象
const std::array<std::string, SEASON_COUNT> SEASONS = {
        "Spring",
        "Summer",
        "Autumn",
        "Winter"
};

//  要修改某个数组内成员的值，必须要传地址
void fill_array(std::array<double, SEASON_COUNT> * p) {
    // *p 是地址处的值，指向生声明的数组对象
    for (int i = 0; i < SEASON_COUNT; i++) {
        std::cout << "Please input expanse in " << SEASONS[i] << std::endl;
        std::cin >> (*p)[i];
    }
}

//  不修改原数组，复制一份局部参数
double output_array(std::array<double, SEASON_COUNT> s) {
    double total = 0;
    for(int i = 0; i < SEASON_COUNT; i++) {
        std::cout << SEASONS[i] << " : " << s[i] << std::endl;
        total += s[i];
    }
    std::cout << "Total spend: " << total << std::endl;
    return total;
}

int input_and_output_arrays() {
    std::array<double, SEASON_COUNT> expense;
    fill_array(&expense);
    output_array(expense);
}