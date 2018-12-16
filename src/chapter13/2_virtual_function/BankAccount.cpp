//
// Created by May on 2018/12/16.
//

#include <iostream>
#include "BankAccount.h"

namespace L13_2 {
    using std::cout;
    using std::endl;
    using std::string;

    //  定义 alias
    typedef std::ios_base::fmtflags format;
    typedef std::streamsize precis;

    format set_format();
    void reset_format(format f, precis p);

    format set_format() {
        // ###.## format
        return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    }

    void reset_format(format f, precis p) {
        cout.setf(f, std::ios_base::floatfield);
        cout.precision(p);
    }

    //  class implementation
    BankAccount::BankAccount(const std::string &username, long number, double balance) {
        _username = username;
        _number = number;
        _balance = balance;
    }
    void BankAccount::view() const {
        format initState = set_format();
        precis initPrec = cout.precision(2);

        cout << "[BankAccount] Client: " << _username << endl;
        cout << "[BankAccount] Account Number: " << _number << endl;
        cout << "[BankAccount] Balance: $" << _balance << endl;

        reset_format(initState, initPrec);
    }
    void BankAccount::deposit(double amount) {
        if (amount < 0) {
            cout << "Deposit failed. negative value(" << amount << ") not allowed.\n";
            return;
        }
        _balance += amount;
    }
    void BankAccount::withdraw(double amount) {
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

    //  sub class implementation
    BankAccountPlus::BankAccountPlus(const std::string &username, long number, double balance, double max_loan,
                                     double rate): BankAccount(username, number, balance) {
        _max_loan = max_loan;
        _rate = rate;
        _loan = 0;
    }
    //  隐式复制构造函数
    BankAccountPlus::BankAccountPlus(const BankAccount &ba, double max_loan, double rate): BankAccount(ba) {
        _max_loan = max_loan;
        _rate = rate;
        _loan = 0;
    }
    //  多态, 覆盖base class里的定义
    void BankAccountPlus::view() const {
        format initState = set_format();
        precis initPrec = cout.precision(2);

        //  Todo:
        BankAccount::view();
        cout << "[BankAccountPlus] Maximum loan: $" << _max_loan << endl;
        cout << "[BankAccountPlus] Current loan: $" << _loan << endl;
        cout.precision(3); // ###.###
        cout << "[BankAccountPlus] Rate: " << 100 * _rate << "%\n";

        reset_format(initState, initPrec);
    }
    //  多态，覆盖base class里的定义
    void BankAccountPlus::withdraw(double amount) {
        format initState = set_format();
        precis initPrec = cout.precision(2);

        //  当前余额
        double balance = get_balance();
        if (amount < balance) {
            BankAccount::withdraw(amount);
        } else if (amount < balance + _max_loan - _loan) {
            //  取款同时进行信用贷款
            double loan = amount - balance;
            _loan += loan * (1.0 + _rate);
            cout << "credit loan amount: $" << loan << endl;
            cout << "credit loan charge: $" << loan * _rate << endl;
            //  先把不够的部分存进去
            deposit(loan);
            //  再取出来总的借贷额
            BankAccount::withdraw(amount);
        } else {
            cout << "Credit limit exceeded, Transaction aborted.\n";
        }

        reset_format(initState, initPrec);
    }
}