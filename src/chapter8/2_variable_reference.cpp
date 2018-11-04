//
// Created by May on 2018/11/1.
//

#include "2_variable_reference.h"

#include "iostream"

void try_reference() {
    using namespace std;
    int rat = 100;
    //  define a reference refer to specific int "rat"
    int & mice = rat;

    cout << "rat = " << rat << "; mice = " << mice << endl;
    mice ++;
    cout << "after mice + 1:\n";
    cout << "rat = " << rat << "; mice = " << mice << endl;
    cout << "compare address:\n";
    //  totally the same
    cout << "rat -> " << &rat << "; &mice = " << &mice << endl;

    int bug = 50;
    mice = bug;
    cout << "After try re-assign reference:\n";
    cout << "bug = " << bug << "; mice = " << mice << endl;

    cout << "compare address:\n";
    //  totally the same
    cout << "rat -> " << &rat << "; &mice = " << &mice << "; &bug = " << &bug << endl;
}

/* swap */
//  使用指针（p1, p2 是地址值）
void swap_by_pointer (int * p1, int * p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//  使用引用（r1, r2 是函数外变量的引用）
void swap_by_reference(int & r1, int & r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}


void swap_variables() {
    using namespace std;
    int a = 3;
    int b = 4;
    cout << "Before swap, a = " << a << "; b = " << b << endl;
    //  pass a, b's location
    swap_by_pointer(&a, &b);
    cout << "After swap by pointer, a = " << a << "; b = " << b << endl;
    //  直接传递原变量，自动为它创建一份作用在函数体内的引用？
    swap_by_reference(a, b);
    cout << "After swap by reference, a = " << a << "; b = " << b << endl;
}

/* reference of structure*/
#include <string>

struct dota_record {
    std::string name;
    int played;
    int win;
    float rate;
};

//  show the players dota-play-record, use *const* in params
void display_record (const dota_record & r) {
    std::cout << "Player [" << r.name << "] win [" << r.win << "] games in [" << r.played << "] plays at a rate of [" << r.rate << "%].\n";
}

//
void update_record(dota_record & r) {
    if (r.played == 0) {
        r.rate = 0;
    } else {
        //  int / int = int, so had to turn it to float first.
        r.rate = 100.0f * float(r.win) / float(r.played);
    }
}

//  return a structure reference
dota_record & accumulate(dota_record & target, const dota_record & source) {
    //  first param is not const, so we can modify it.
    target.played += source.played;
    target.win += source.win;
    update_record(target);
    return target;
}


void structure_reference() {
    //  initialized records. Defaultly, the un-initial members are set to 0
    dota_record one = {
            "Albert",
            100,
            20,
    };
    dota_record two = {
            "Belly",
            21,
            1,
    };
    dota_record three = {
            "Carl",
            0,
            0,
    };
    dota_record total = {
            "TOTAL",
            0,
            0,
    };
    //  un-initialized record
    dota_record dump;

    display_record(one);
    update_record(one);
    display_record(one);

    update_record(two);
    display_record(two);

    update_record(three);
    display_record(three);

    display_record(total);

    //  accumulate;
    accumulate(total, one);
    display_record(total);
    display_record(accumulate(accumulate(total, two), three));

    //  test with the *dump* record
    std::cout << "---------- dump ----------\n";
    display_record(dump);
}

/* modify string using reference */
#include "string"
std::string mod_string_by_creating_temp(const std::string & s1, const std::string & s2) {
    std::string temp;
    temp = s2 + s1 + s2;
    //  返回一份 string 的复制
    return temp;
}

std::string & mod_string_by_change_input(std::string & s1, const std::string & s2) {
    //  直接修改原字符串, 并返回原字符串的引用
    s1 = s2 + s1 + s2;
    return s1;
}

std::string & mod_string_and_return_temp_ref(std::string & s1, const std::string & s2) {
    std::string temp;
    temp = s2 + s1 + s2;
    //  返回临时变量内的引用
    return temp;
}

void modify_string() {
    using namespace std;
    string input;
    cout << "Enter the string you want to modify:\n";
    getline(cin, input);
    cout << "You just entered: " << input << endl;

    string result;
    result = mod_string_by_creating_temp(input, "!!!");
    cout << "V1: mod by creating temp: " <<  result << ", the origin input: " << input << "\n";

    result = mod_string_by_change_input(input, "@@@");
    cout << "V2: mod by change input: " <<  result << ", the origin input: " << input << "\n";

    result = mod_string_and_return_temp_ref(input, "###");
    // 能看到预期的输出只是因为运气好，栈上的临时变量没有被干扰或者 wipe
    // https://stackoverflow.com/questions/2744264/returning-a-reference-to-a-local-or-temporary-variable
    cout << "V2: mod and return temp variable in function: " <<  result << ", the origin input: " << input << "\n";
}


