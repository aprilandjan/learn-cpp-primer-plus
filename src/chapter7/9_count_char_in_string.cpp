//
// Created by May on 2018/10/25.
//

#include "9_count_char_in_string.h"
#include <iostream>

//  str 是地址
int count_char(const char * str, char ch)
{
    int count = 0;
    //  *str 是地址处的字符
    while(*str) {
        std::cout << "===>" << *str << std::endl;
        if (*str == ch) {
            count++;
        }
        //  地址+1，指向下一个字符
        str++;
    }
    return count;
}

int count_char_in_string()
{
    using namespace std;
    const char * str_a = "abcabcabcdef";
    const char str_b[10] = "b1b2b3b4b";
    const char search_char = 'b';

    cout << "Char " << search_char << " in string "  << * str_a << " is: " << count_char(str_a, search_char) << "! " << endl;
    cout << "Char " << search_char << " in string "  << str_b << " is: " << count_char(str_b, search_char) << "! " << endl;
}
