//
// Created by May on 2018/11/17.
//

#include <iostream>

//  定位 new 运算符需要的
#include <new>

#include "3_new_placement.h"

const int BUFF = 512;
const int N = 5;
//  开辟一块静态内存区域
char buffer[BUFF];

void try_placement_new() {
    using namespace std;

    double * pd1, * pd2;
    int i;
    cout << "Calling new and placement new:\n";
    //  new 关键字自动在堆 heap 找一块可用内存区域
    pd1 = new double(N);
    //  placement new 指定所使用的内存区块
    pd2 = new (buffer) double(N);

    cout << "Memory address:\n";
    //  buffer 是 char 数组指针
    cout << "  heap: " << pd1 << "\n  static: " << (void *) buffer << "\n";

    for(i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 20 * i;
    }
    cout << "Memory content:\n";
    for(i = 0; i < N; i++) {
        cout << " heap " << i << ": " << pd1[i] << " at " << & pd1[i] << ";\n";
        cout << " static " <<  i << ": " << pd2[i] << " at " << & pd2[i] << ";\n";
    }

    cout << "Calling second time:\n";
    double *pd3, *pd4;
    pd3 = new double(N);
    //  手动指定内存地址
    pd4 = new (buffer + N * sizeof(double)) double(N);

    for(i = 0; i < N; i++) {
        pd3[i] = pd4[i] = 2700 + 20 * i;
    }
    cout << "Memory content:\n";
    for(i = 0; i < N; i++) {
        cout << " heap " << i << ": " << pd3[i] << " at " << & pd3[i] << ";\n";
        cout << " static " <<  i << ": " << pd4[i] << " at " << & pd4[i] << ";\n";
    }
    //  delete 只能删除常规 new 分配的 heap memory
    delete [] pd1;
    delete [] pd3;
}