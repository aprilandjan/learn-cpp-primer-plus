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

    //
    Sales sales;
    sales[1] = 100;
    std::cout << "2018 sales: " << sales[1] << std::endl;

    //  allocate a pointer, points to 'sales' actual location
    Sales *ps = &sales;
    std::cout << "2018 ps: " << (*ps)[1] << std::endl;
}
