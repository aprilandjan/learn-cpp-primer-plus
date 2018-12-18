//
// Created by May on 2018/12/18.
//

#ifndef LEARN_ACCOUNT_H
#define LEARN_ACCOUNT_H

#include <iostream>
#include <string>

namespace L13_3 {
    //  define an abstract-base-class
    class Account {
    private:
        std::string _name;
        long _number;
        double _balance;
    protected:
        struct Formatting {
            std::ios_base::fmtflags flag;
            std::streamsize precision;
        };
        const std::string & get_name() const {
            return _name;
        }
        long get_number() const {
            return _number;
        }
        //  save & restore format
        //  much like context2d save() & restore()
        Formatting save_format() const;
        void restore_format(Formatting & f) const;
    public:
        Account(const std::string & name = "none", long number = -1, double balance = 0);
        double get_balance() const {
            return _balance;
        }
        void deposit(double amount);
        //  = 0， stands for "Pure Virtual function", and this make this class abstract
        virtual void withdraw(double amount) = 0;
        virtual void view() const = 0;
        virtual ~Account(){};
    };

    //  derived class of an abstract-base-class
    class BankAccount: Account {
    public:
        BankAccount(const std::string & name = "none", long number = -1, double balance = 0): Account(name, number, balance){};
        //  must be re-declare virtual functions
        virtual void withdraw(double amount);
        virtual void view() const;
        virtual ~BankAccount(){};
    };

    class BankAccountPlus: Account {
    private:
        /** 最大信用额度 */
        double _max_loan;
        /** 利率 */
        double _rate;
        /** 使用的信用额 */
        double _loan;
    public:
        BankAccountPlus(const std::string & name = "none", long number = -1, double balance = 0, double max_loan = 500, double _rate = 0.015);
        BankAccountPlus(const BankAccount & ba, double max_loan = 500, double _rate = 0.015);
        virtual void withdraw(double amount);
        virtual void view() const;
        virtual ~BankAccountPlus(){};
        void set_max_loan(double max_loan = 500) {
            _max_loan = max_loan;
        }
        void set_rate(double rate = 0.015) {
            _rate = rate;
        }
        void set_loan(double loan = 0) {
            _loan = loan;
        }
    };
}

#endif //LEARN_ACCOUNT_H
