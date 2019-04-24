//
// Created by May on 2019/4/24.
//

#include <iostream>
#include "use_sales.h"
#include "Sales.h"

void use_sales() {
    //
    using namespace L15_4;
//    using namespace std;

    Sales sales;
//    *sales = Sales(2018);
    sales[1] = 100;

    std::cout << "2018 sales: " << sales[1] << std::endl;
}
