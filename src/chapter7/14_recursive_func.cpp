//
// Created by May on 2018/10/29.
//

#include "14_recursive_func.h"
#include "iostream"

/* 简单的递归调用 */
void count_down(int n) {
    std::cout << "now count " << n << " at: " << &n << std::endl;
    if (n > 0) {
        count_down(n - 1);
    }
    std::cout << "done at " << n << "(" << &n << ")" << std::endl;
}

int show_count_down() {
    count_down(5);
}


/* 使用递归绘图 */
const int LENGTH = 60;
const int DIVIDER = 6;

void init_ruler (char arr[]) {
    //  初始化
    int i = 0;
    for(i = 0; i < LENGTH - 2; i++) {
        arr[i] = ' ';
    }
    arr[LENGTH - 1] = '\0';

    int max = LENGTH - 2;
    int min = 0;
    arr[max] = arr[min] = '|';
}

void fill_section(char arr[], int div, int left, int right) {
    //  填充
    if (div == 0) {
        return;
    }
    int mid = (right + left) >> 1;
    arr[mid] = '|';
    fill_section(arr, div - 1, left, mid);
    fill_section(arr, div - 1, mid, right);
}

int draw_ruler () {
    char ruler[LENGTH];
    for (int i = 0; i < DIVIDER; i++) {
        init_ruler(ruler);
        fill_section(ruler, i, 0, LENGTH - 2);
        std::cout << ruler << std::endl;
    }
}
