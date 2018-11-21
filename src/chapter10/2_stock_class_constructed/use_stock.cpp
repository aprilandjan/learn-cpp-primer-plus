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
}