//
// Created by May on 2018/12/18.
//

#include <iostream>
#include "Account.h"

namespace L13_3 {
    using std::cout;
    using std::endl;
    using std::string;

    //  class implementation
    //  although A-B-C cannot be initialized directly, can still add implementation.
    Account::Account(const std::string &name, long number, double balance) {
        _name = name;
        _number = number;
        _balance = balance;
    }
    void Account::deposit(double amount) {
        if (amount < 0) {
            cout << "Deposit failed. negative value(" << amount << ") not allowed.\n";
            return;
        }
        _balance += amount;
    }
    void Account::withdraw(double amount) {
        if (amount < 0) {
            cout << "Withdraw failed. negative value(" << amount << ") not allowed.\n";
            return;
        }
        if (amount > _balance) {
            cout << "Withdraw failed. not enough remaining balance.\n";
            return;
        }
        _balance -= amount;
    }
    Account::Formatting Account::save_format() const {
        Formatting f;
        f.flag = cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        f.precision = cout.precision(2);
        return f;
    }
    void Account::restore_format(Formatting &f) const {
        cout.setf(f.flag, std::ios_base::floatfield);
        cout.precision(f.precision);
    }
}