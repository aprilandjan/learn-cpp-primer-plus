//
// Created by May on 2018/11/10.
//

#include "5_function_template.h"
#include "iostream"

// 定义函数模板原型
template <typename T>
void Swap(T & a, T & b);

// 模版重载, 用以支持数组
template <typename T>
void Swap(T a[], T b[], int n);

void outputArray(int arr[], int size) {
    std::cout << "[";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i != size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

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

    const int SIZE = 8;
    int listA[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    int listB[SIZE] = {11, 22, 33, 44, 55, 66, 77, 88};
    cout << "Before: listA = ";
    outputArray(listA, SIZE);
    cout << ", listB = ";
    outputArray(listB, SIZE);
    cout << "...\n";

    Swap(listA, listB, SIZE);
    cout << "After: listA = ";
    outputArray(listA, SIZE);
    cout << ", listB = ";
    outputArray(listB, SIZE);
    cout << "...\n";
}

template <typename T>
//  a, b 都是 reference
void Swap(T & a, T & b) {
    //  直接使用泛型 T 定义临时变量
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n) {
    //  定义临时数组
    T temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i];
        a[i] = b[i];
        b[i] = temp[i];
    }
}