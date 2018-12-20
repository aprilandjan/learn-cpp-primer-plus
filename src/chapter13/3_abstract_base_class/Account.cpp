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

    //  sub class method
    void BankAccount::withdraw(double amount) {
        if (amount < 0) {
            cout << "Withdraw failed. negative value(" << amount << ") not allowed.\n";
            return;
        }
        if (amount > get_balance()) {
            cout << "Withdraw failed. not enough remaining balance.\n";
            return;
        }
        //  call ABC method
        Account::withdraw(amount);
    }
    void BankAccount::view() const {
        Formatting f = Account::save_format();

        cout << "[BankAccount] Client: " << get_name() << endl;
        cout << "[BankAccount] Account Number: " << get_number() << endl;
        cout << "[BankAccount] Balance: $" << get_balance() << endl;

        Account::restore_format(f);
    }

    //  another sub class method
    BankAccountPlus::BankAccountPlus(const std::string &name, long number, double balance, double max_loan,
                                          double rate): Account(name, number, balance) {
        _max_loan = max_loan;
        _rate = rate;
        _loan = 0;
    }
    //  调用 Account "隐式复制构造函数"
    BankAccountPlus::BankAccountPlus(const BankAccount &ba, double max_loan, double rate): Account(ba) {
        _max_loan = max_loan;
        _rate = rate;
        _loan = 0;
    }
    void BankAccountPlus::withdraw(double amount) {
        Formatting f = Account::save_format();

        //  当前余额
//        double balance = get_balance();
        //  access through protected member
        double balance = Account::get_balance();
        if (amount < balance) {
            Account::withdraw(amount);
        } else if (amount < balance + _max_loan - _loan) {
            //  取款同时进行信用贷款
            double loan = amount - balance;
            _loan += loan * (1.0 + _rate);
            cout << "credit loan amount: $" << loan << endl;
            cout << "credit loan charge: $" << loan * _rate << endl;
            //  先把不够的部分存进去
            deposit(loan);
            //  再取出来总的借贷额
            Account::withdraw(amount);
        } else {
            cout << "Credit limit exceeded, Transaction aborted.\n";
        }

        Account::restore_format(f);
    }
    void BankAccountPlus::view() const {
        Formatting f = Account::save_format();

        cout << "[BankAccountPlus] Client: " << get_name() << endl;
        cout << "[BankAccountPlus] Account Number: " << get_number() << endl;
        cout << "[BankAccountPlus] Balance: $" << get_balance() << endl;
        cout << "[BankAccountPlus] Maximum loan: $" << _max_loan << endl;
        cout << "[BankAccountPlus] Current loan: $" << _loan << endl;
        cout.precision(3); // ###.###
        cout << "[BankAccountPlus] Rate: " << 100 * _rate << "%\n";

        Account::restore_format(f);
    }
}