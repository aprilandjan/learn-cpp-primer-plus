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

struct job {
    char name[40];
    double salary;
    int floor;
};

//  explicit specialization 针对特定类型(job)的显式具体化
template <> void Swap<job>(job & a, job & b);

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

void outputJob(job & j) {
    std::cout << "Job: name=" << j.name << "; salary=" << j.salary << "; floor=" << j.floor << std::endl;
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

    job ja = {
            "Coder",
            30000,
            15,
    };

    job jb = {
            "Artist",
            50000,
            24,
    };

    cout << "\nBefore swap:\n";
    outputJob(ja);
    outputJob(jb);
    Swap(ja, jb);
    cout << "After swap:\n";
    outputJob(ja);
    outputJob(jb);
}

//  模板
template <typename T>
//  a, b 都是 reference
void Swap(T & a, T & b) {
    //  直接使用泛型 T 定义临时变量
    T temp = a;
    a = b;
    b = temp;
}

//  模板重载
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

//  显式具体化的实现函数
template <> void Swap<job>(job & a, job & b) {
    double temp_salary = a.salary;
    int temp_floor = a.floor;
    a.salary = b.salary;
    a.floor = b.floor;
    b.salary = temp_salary;
    b.floor = temp_floor;
}
