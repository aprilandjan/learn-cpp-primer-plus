//
// Created by May on 2018/1/28.
//

#include "use_cctypes.h"
#include <iostream>
#include <cctype>

int use_ccytpes () {
    using namespace std;
    cout << "Please input text for analysis, and type @ to terminate.\n";

    char ch;
    int count_whitespace = 0;
    int count_digit = 0;
    int count_chars = 0;
    int count_punct = 0;
    int count_others = 0;

    do {
        cin.get(ch);
        if (isalpha(ch)) {
            //  字母
            count_chars++;
        } else if (isspace(ch)) {
            //  空格
            count_whitespace++;
        } else if (ispunct(ch)) {
            //  标点
            count_punct++;
        } else if (isdigit(ch)) {
            //  数字
            count_digit++;
        } else {
            count_others++;
        }
    } while (ch != '@');

    cout << count_chars << "letters, ";
    cout << count_whitespace << " whitespaces, ";
    cout << count_digit << " digits, ";
    cout << count_punct << " punctuations and " << count_others << "other chars";

    return 0;
}