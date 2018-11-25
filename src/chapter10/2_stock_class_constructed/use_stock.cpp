//
// Created by May on 2018/11/20.
//

#include <iostream>

#include "use_stock.h"
#include "stock.h"

void use_stock_with_constructor() {
    using namespace L10_2;

    //  call constructor explicitly
    Stock merlin = Stock("Apple", 20, 30);
//    merlin.acquire("Apple", 20, 30);
    merlin.show();
    merlin.buy(30, 50);
    merlin.show();
    merlin.sell(1000, 12.45);
    merlin.show();
    merlin.buy(30000, 58.3);
    merlin.show();
    merlin.sell(30000, 0.125);
    merlin.show();

    //  call constructor implicitly
    Stock aaj("Microsoft", 20, 30);
    aaj.show();

    //  create with *new*， without a name, but holding it with a pointer
    Stock * p_stock = new Stock("Google", 30, 50);
    p_stock->show();

    Stock w_w("Oracle", 300, 20);
    w_w.show();

    std::cout << "----> re assign to exist stock:\n";
    //  创建临时实例，并复制到目标对象中，再将临时实例丢弃
    w_w = Stock("Facebook");
    w_w.show();
//    merlin = Stock("Oracle", 300, 20);

    const Stock qs("Ali");
    qs.show();

    //  比较并获取引用，不生成新的
    const Stock higher = merlin.compare(aaj);
    higher.show();
}

/**
 * 类实例组成数组
 */
void class_instance_in_array() {
    using namespace L10_2;
    const int SIZE = 4;
    //  数组初始化
    Stock stocks[SIZE] = {
            Stock("Apple", 20, 30),
            Stock("Microsoft", 30, 50),
            Stock("Google", 10, 50),
            Stock("Facebook", 30, 30)
    };
    std::cout << "Stocks current holding:\n";
    int n;
    for (n = 0; n < SIZE; n++) {
        stocks[n].show();
    }

    //  top 地址指向数组里第一个元素
    const Stock * top = &stocks[0];
    for(n = 1; n < SIZE; n++) {
        // top 本来就是一个地址，地址访问其实例方法使用 ->
//        top->show();
        //  compare 返回了一个 stock 引用，对其再取地址
        top = &top->compare(stocks[n]);
    }
    std::cout << "Top valuabe holding:\n",
    top->show();
}