//
// Created by May on 2018/7/30.
//

#include "6_arr_func_2.h"
#include "iostream"

const int ArSize = 8;
int sum_arr_2(int arr[], int n);

int arr_func_2 ()
{
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    std::cout << cookies << " = array address\n";
    std::cout << sizeof cookies << " = sizeof cookies\n";
    int sum = sum_arr_2(cookies, ArSize);
    std::cout << "Total cookies eaten:" << sum << std::endl;
    sum = sum_arr_2(cookies, 3);
    std::cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr_2(cookies + 4, 4);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";
}

int sum_arr_2 (int arr[], int n)
{
    //  arr 是什么？
    int total = 0;
    std::cout << arr << " = arr, ";
    std::cout << sizeof arr << " = sizeof arr\n";
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
}
