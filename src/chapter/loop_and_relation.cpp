//
// Created by May on 2018/1/15.
//

#include "loop_and_relation.h"
#include <iostream>
#include <string>
#include <ctime>

int nested_array () {
    using namespace std;
    //  cities 是 char 类型组成的数组，*cities 是数组指针指向的值
    //  指针数组
    char * cities[5] = {
            "Beijing",
            "Shanghai",
            "Guangzhou",
            "Shenzhen",
            "Hangzhou"
    };

    //  cout 自动的把数组[index]取成了实际的值 0.0?
    cout << cities << ' ' << cities[0] << endl;

    int maxtemps[4][5] = {
            {1, 2, 3, 4, 5},
            {11, 22, 33, 44, 55},
            {111, 222, 3, 41, 52},
            {1, 23, 3444, 42, 1115}
    };

    cout << "Max Temperatures are as followed:\n";
    for (int i = 0; i < 5; i++) {
        //  这里用到了 \t 制表符
        cout << cities[i] << ":\t";
        for (int j = 0; j < 4; j++) {
            cout << maxtemps[j][i] << "\t";
        }
        cout << endl;
    }

    return 0;
}


int textinput () {
    using namespace std;

    char ch;
    int count = 0;

//    cout << "Enter something, enter # to stop:\n";
//    cout << "Enter something:\n";
    cin >> ch;
    //  cin.get() 可以获取空格、换行
    cin.get(ch);

    //  检测EOF： cin.fail() == true
    while (cin.fail() == false) {
        cout << ch;
        ++count;
//        cin >> ch;
        cin.get(ch);
    }

    cout << "\n" << count << " charactors readed.";

    return 0;
}

int waiting () {
    using namespace std;
    cout << "Enter the delay time, in seconds:";
    float secs;
    cin >> secs;
    //  CLOCK_PER_SEC: 每秒的系统时间单位
    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting...\a\n";
    clock_t start = clock();
    //  利用 while 循环做等待...
    while (clock() - start < delay)
        ;

    cout << "done!\a\n";

    return 0;
}

const int ArSize = 16;

int formore () {
    long long factorials[ArSize];
    factorials[1] = factorials[0] = 1LL;

    for (int i = 2; i < ArSize; i++) {
        factorials[i] = i * factorials[i - 1];
    }

    for (int i = 0; i < ArSize; i++) {
        std::cout << i << "! = " << factorials[i] << std::endl;
    }

    return 0;
}

int string_compare () {
    using namespace std;
    string word = "?ate";
    for (char ch = 'a'; word != "mate"; ch++) {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word << endl;
    return 0;
}