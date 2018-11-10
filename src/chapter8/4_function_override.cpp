//
// Created by May on 2018/11/8.
//

#include "4_function_override.h"
#include "iostream"

//  多态声名
unsigned long do_left(unsigned long num, unsigned ct);
char * do_left(const char * str, unsigned ct = 1);  //  原型上使用了一下默认参数

/** 获取数字或字符串的前几位 */
void beginning_of_value() {
    using namespace std;

    // define string
    const char * str = "ABCDEFG, HIJKPLMN";
    // define number
    unsigned long n = 12345678;

    int i;

    cout << "Origin number: " << n << endl;
    for (i = 0; i <= 10; i++) {
        cout << "First " << i << " bit is: " << do_left(n, i) << endl;
    }

    //  专门构造的临时变量，用完释放内存
    char * temp;
    cout << "\nOrigin string: " << str << endl;
    for (i = 0; i <= 10; i++) {
        temp = do_left(str, i);
        cout << "First " << i << " bit is: " << temp << endl;
        delete [] temp;
    }
}

//  for number
unsigned long do_left(unsigned long num, unsigned ct) {
    unsigned digit = 1;
    unsigned long n  = num;
    if (num == 0 || ct == 0) {
        return 0;
    }
    //  获取原数字长度位数
    while (n /= 10) {
        digit ++;
    }
    //  截取前 ct 位, 需要进行几次操作
    unsigned cn = digit - ct;
    //  cn 是无符号的，如果 digit - cn < 0, 赋值给 unsigned 会溢出. sizeof(unsigned)=4, 4byte=32bit, 结果会变成 2^32 - cn
//    std::cout << "cn is: " << cn << "; " << sizeof(unsigned)  << "\n";
    if (cn > 0) {
        while(cn --) {
            num  /= 10;
        }
    }
    return num;
}

//  for string
char * do_left(const char * str, unsigned ct) {
    char * result = new char[ct + 1];// prepare last \0
    int i = 0;
    for (i; i < ct; i++) {
        result[i] = str[i];
    }
    while(i <= ct) {
        result[i++] = '\0';
    }
    return result;
}