//
// Created by May on 2018/12/16.
//

#ifndef LEARN_BANKACCOUNT_H
#define LEARN_BANKACCOUNT_H

#include <iostream>

namespace L13_2 {
    class BankAccount {
    private:
        /**
         * 用户名
         */
        std::string _username;
        /**
         * 卡号
         */
        long _number;
        /** 余额 */
        double _balance;
    public:
        BankAccount(const std::string & username = "none", long number = 0, double balance = 0);
        /** 查看账号详情. 后续要重新定义，使用“虚函数” */
        virtual void view() const;
        /** 取出. 后续要重新定义，使用“虚函数” */
        virtual void withdraw(double amount);
        /** 存入 */
        void deposit(double amount);
        double get_balance() const {
            return _balance;
        };
    };

    /**
     * 继承自 BankAccount
     */
    class BankAccountPlus: public BankAccount {
    private:
        /** 最大信用额度 */
        double _max_loan;
        /** 利率 */
        double _rate;
        /** 使用的信用额 */
        double _loan;
    public:
        BankAccountPlus(const std::string & username = "none", long number = 0, double balance = 0, double max_loan = 500, double rate = 0.11125);
        BankAccountPlus(const BankAccount & ba, double max_loan = 500, double rate = 0.11125);
        virtual void view() const;
        virtual void withdraw(double amount);
        void set_max_loan(double max_loan = 500) {
            _max_loan = max_loan;
        }
        void set_rate(double rate = 0.11125) {
            _rate = rate;
        }
        void set_loan(double loan = 0) {
            _loan = loan;
        }
    };
}

#endif //LEARN_BANKACCOUNT_H
