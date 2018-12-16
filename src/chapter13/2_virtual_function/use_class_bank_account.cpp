//
// Created by May on 2018/12/16.
//

#include <iostream>

#include "use_class_bank_account.h"
#include "BankAccount.h"

void use_class_bank_account() {
    //
    using namespace L13_2;
    using std::cout;
    using std::endl;

    BankAccount a0("Jerry", 31526, 3000);
    a0.view();

    BankAccountPlus b0("Stein", 421923, 5000, 2000);
    b0.view();

    //  非虚函数，根据引用类型决定要调用哪个方法
    //  虚函数，根据实际的对象类型决定要调用哪个方法
    BankAccount & ra = a0;
    BankAccount & rb = b0;
    ra.view();
    rb.view();

    cout << endl;
    a0.deposit(1000);
    a0.view();

    cout << endl;
    cout << "Stein try to withdraw $6000:\n";
    b0.withdraw(6000);
    b0.view();
}