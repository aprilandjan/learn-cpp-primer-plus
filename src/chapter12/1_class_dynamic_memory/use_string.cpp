//
// Created by May on 2018/12/4.
//

#include <iostream>
#include "use_string.h"
#include "./StringBad.h"
#include "./String.h"

void pass_string_by_reference(L12_1::StringBad & s) {
    std::cout << "String passed by reference:\n" << s << "\n";
}

void pass_string_by_value(L12_1::StringBad s) {
    std::cout << "String passed by value:\n" << s << "\n";
}

void use_string_bad() {
    using namespace std;
    using namespace L12_1;

    StringBad a("abc");
    cout << a << "\n";
    StringBad b("Just Another ordinary day...");
    StringBad c("Yesterday once more");
    cout << b << " " << c << "\n";

    pass_string_by_reference(b);
    cout << "b: " << b << "\n";

    pass_string_by_value(c);
    cout << "c: " << c << "\n";

    cout << "------------------\n";
    //  此处相当于 String d = String(b), 使用了编译器自动生成的*复制构造函数*，跳过了初始化的计数
    //  复制构造函数把成员对象按值复制（包括指针），因此在析构中释放指针地址内存后，被复制者指针指向被回收地址
    StringBad d = b;
    cout << "d: " << d << "\n";

    //  手动调用“复制构造函数”
    StringBad e("EEEEEEE");
    StringBad f(e);
    cout << "e: " << e << "\n";
    cout << "f: " << f << "\n";
}

void use_string() {
    using namespace std;
    using namespace L12_1;

    String a("ABCDEFG");
    cout << a << ", length=" << a.length() << endl;

    String b("HIJKLMN");
    cout << b << ", a < b ? " << (a < b) << "; b < a ? " << (b < a) << endl;

    String c;
    cout << c << ", length=" << c.length() << endl;

    String d("ASDF");
    cout << d[0] << d[1] << d[2] << d[3] << d[4] << endl;
    d[1] = 'Q';
    cout << d[1] << "," << d << endl;

    String e = "Direct string assignment";
    cout << e << "; length=" << e.length() << endl;

    String f(e);
    cout << f << endl;

    const int TEMP_SIZE = 81;
    char temp[TEMP_SIZE];

    cout << "Please input your line of string:\n";
    cin.get(temp, TEMP_SIZE);
//    while(cin && cin.get() != '\n') {
//
//    }
    String g;
    //  在下面的赋值语句中 temp 被隐式转换为了一个 String 对象
    //  如果不重载赋值方法（=），则会进行隐式的对象值 copy
    g = temp;
    cout << "g: " << g << endl;

    cout << "-----> " << String::getInstanceCount() << " instance now <-----\n";
}