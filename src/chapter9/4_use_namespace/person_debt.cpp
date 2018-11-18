//
// Created by May on 2018/11/18.
//

#include <iostream>

#include "person_debt.h"

namespace pers {
    using std::cout;
    using std::cin;
    using std::endl;

    //  Person 已在头文件中定义
    void getPerson(Person & person) {
        cout << "Enter first name: ";
        cin >> person.fname;
        cout << "Enter last name: ";
        cin >> person.lname;
    }

    void showPerson(const Person & person) {
        cout << person.lname << ", " << person.fname;
    }
}

namespace debts {
    //  Debt 已在头文件中定义
    void getDebt(Debt & rd) {
        getPerson(rd.name);
        std::cout << "Enter debt: ";
        std::cin >> rd.amount;
    }

    void showDebt(const Debt & rd) {
        showPerson(rd.name);
        std::cout << ": $" << rd.amount << std::endl;
    }

    double sumDebts(const Debt ar[], int n) {
        double total = 0;
        for (int i = 0; i < n; i++) {
            total += ar[i].amount;
        }
        return total;
    }
}