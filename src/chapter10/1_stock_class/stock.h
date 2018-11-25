//
// Created by May on 2018/11/20.
//

#ifndef LEARN_STOCK_H
#define LEARN_STOCK_H

#include <string>

namespace L10_1 {
    class Stock {
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() {
            //  直接将该私有函数实现放在了头文件里？...
            //  类声明中的函数自动成为内联函数
            total_val = shares * share_val;
        }
        void set_tot_1();
    public:
        void acquire(const std::string & co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
    };
}

#endif //LEARN_STOCK_H
