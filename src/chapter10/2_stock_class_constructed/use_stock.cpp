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
