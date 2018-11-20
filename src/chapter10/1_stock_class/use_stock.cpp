//
// Created by May on 2018/11/20.
//

#include <iostream>

#include "use_stock.h"
#include "stock.h"

void use_stock() {
    Stock merlin;
    merlin.acquire("Apple", 20, 30);
    merlin.show();
    merlin.buy(30, 50);
    merlin.show();
    merlin.sell(1000, 12.45);
    merlin.show();
    merlin.buy(30000, 58.3);
    merlin.show();
    merlin.sell(30000, 0.125);
    merlin.show();
}