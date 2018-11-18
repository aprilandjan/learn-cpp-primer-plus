//
// Created by May on 2018/11/18.
//

#include <iostream>

#include "index.h"
#include "person_debt.h"

void other() {
    using namespace std;

    //  debts 里使用了 pers, 因此自动导入了 pers 的定义和方法
    using namespace debts;

    Person nc = {
            "Nicolas",
            "Cage",
    };
    showPerson(nc);
    cout << endl;
    Debt zippy[3];
    int i;
    for (i = 0; i < 3; i++) {
        getDebt(zippy[i]);
    }
    for (i = 0; i < 3; i++) {
        showDebt(zippy[i]);
    }
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
}

void try_namespace() {
    //
    using namespace std;
    using debts::Debt;
    Debt golf = {
            {
                    "Benny",
                    "Goatsniff"
            },
            120.0
    };
    debts::showDebt(golf);

    other();
}
