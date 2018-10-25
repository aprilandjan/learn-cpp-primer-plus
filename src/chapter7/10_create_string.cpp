//
// Created by May on 2018/10/25.
//

#include "10_create_string.h"
#include <iostream>

char * create_by_char(char ch, int size)
{
    //  使用 new 创建指定长度字符串，最后一位填充为 '\0'
    char *str = new char[size + 1];
    for(int i = 0; i <= size; i++) {
        if (i < size) {
            // 每个字符指向的地址
            str[i] = ch;
        } else {
            str[i] = '\0';
        }
    }
    //  返回指针
    return str;
}

int create_string()
{
    using namespace std;
    const char ch = 'x';
    const int size = 10;
    const char * str_x = create_by_char(ch, size);
    //  str_x => xxxxxxxxxxxx, str 是一个 char 数组，
    //  * str_x => x, *str 是 char 数组的第一个元素的地址
    cout << size << " of " << ch << " is: " << str_x << endl;
    delete [] str_x;
    //  清掉之该地址处的值随机变化了
    cout << "After delete: " << str_x << endl;
}