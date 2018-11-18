//
// Created by May on 2018/11/18.
//

#include <string>

#ifndef LEARN_PERSON_DEBT_H
#define LEARN_PERSON_DEBT_H

namespace pers {
    struct Person {
        std::string fname;
        std::string lname;
    };
    void getPerson(Person &);
    void showPerson(const Person &);
}

namespace debts {
    using namespace pers;
    struct Debt {
        pers::Person name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
}

#endif //LEARN_PERSON_DEBT_H
