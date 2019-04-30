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

    LabeledSales ls("abcd");
    std::cout << "abcd: " << ls[2] << std::endl;

    double val_s1[12] = {
            1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012
    };

    double val_s2[12] = {
            11, 22, 33, 44, 55, 66, 77, 88, 99, 109, 121, 202,
    };

    Sales sales1(2000, val_s1, 12);
    LabeledSales sales2("End of the world", 2012, val_s2, 12);

    std::cout << "First try block:\n";
    try {
        int i;
        std::cout << "Year = " << sales1.get_year() << std::endl;
        for (i = 0; i < sales1.MONTHS; i++) {
            std::cout << sales1[i] << ' ';
            if (i % 6 == 5) {
                std::cout << "\n";
            }
        }

        std::cout << "\n";

        std::cout << "Year = " << sales2.get_year() << std::endl;
        std::cout << "Label = " << sales2.get_label() << std::endl;
        for (i = 0; i <= sales2.MONTHS; i++) {
            std::cout << sales2[i] << ' ';
            if (i % 6 == 5) {
                std::cout << "\n";
            }
        }

        std::cout << "End of the try block 1\n";
    } catch(LabeledSales::NBadIndex & error) {
        //  error.what(): something like error.message in js?
        std::cout << "Catch NBadIndex:" << error.what();
        std::cout << "Company: " << error.get_label_value() << std::endl;
        std::cout << "Bad index: " << error.get_bad_value() << std::endl;
    } catch(Sales::BadIndex & error) {
        std::cout << error.what();
        std::cout << "Bad index: " << error.get_bad_value() << std::endl;
    }

    std::cout << "\nNext try block...\n";

    try {
        sales2[2] = 22222;
        sales1[20] = 202020;
        std::cout << "End of try block 2...\n";
    } catch(LabeledSales::NBadIndex & error) {
        //  error.what(): something like error.message in js?
        std::cout << "Catch NBadIndex:" << error.what();
        std::cout << "Company: " << error.get_label_value() << std::endl;
        std::cout << "Bad index: " << error.get_bad_value() << std::endl;
    } catch(Sales::BadIndex & error) {
        std::cout << error.what();
        std::cout << "Bad index: " << error.get_bad_value() << std::endl;
    }
}
