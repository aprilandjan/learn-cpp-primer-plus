//
// Created by May on 2018/11/20.
//

#include <iostream>

#include "./stock.h"

using namespace L10_2;

//Stock::Stock() {
//    //
//    std::cout << "Default constructor called...\n";
//}

//  implement constructor here...
Stock::Stock(const std::string &co, long n, double pr) {
    std::cout << "Constructor using " << co << " called.\n";
//    company = co;
    //  直接在构造函数里调用 acquire 了...
    acquire(co, n, pr);
}

//  implement destructor here...
Stock::~Stock() {
    std::cout << "...bye, " << company << "!\n";
}

//  持有股票的实现
void Stock::acquire(const std::string &co, long n, double pr) {
    company = co;
    if (n < 0) {
        std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares= 0 ;
    } else {
        shares = n;
    }
    share_val = pr;
    //  设置 total 值
    set_tot();
}

//  买入股票
void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares purchased can't be negative. Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using namespace std;
    if (num < 0) {
        cout << "Number of shares sold can't be negative. Transaction is aborted.\n";
    } else if (num > shares) {
        cout << "Cannot sell more than you have! Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() {
    //  设置输出格式
    //  使用定点表示法，避免科学记数法
    std::ios_base::fmtflags origin_flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::streamsize precision = std::cout.precision(3);

    std::cout << "Company: " << company << " Shares: " << shares << "\n";
    std::cout << " Shares Price: $" << share_val << " Total worth: $" << total_val << '\n';

    //  恢复之前设置的输出格式
    std::cout.setf(origin_flag, std::ios_base::floatfield);
    std::cout.precision(precision);
}

inline void Stock::set_tot_1() {
    std::cout << "Just another inline implementation...\n";
}