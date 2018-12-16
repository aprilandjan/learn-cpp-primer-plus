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

/**
 * 使用指向基类的实例列表
 */
void use_bank_account_list() {
    //
    using namespace L13_2;
    using std::cout;
    using std::cin;
    using std::endl;

    const int SIZE = 4;

    //  使用列表存储
    BankAccount * list[SIZE];

    std::string temp_name;
    long temp_number;
    long temp_balance;
    char type;
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter client's name: ";
//        cin.getline(cin);
        std::getline(cin, temp_name);
        cout << "Enter client's account number: ";
        cin >> temp_number;
        cout << "Enter his/her balance: ";
        cin >> temp_balance;
        cout << "Enter 1 for basic account or 2 for Plus account: ";
        while(cin >> type && (type != '1' && type != '2')) {
            cout << "Enter either 1 or 2: ";
        }
        if (type == '1') {
            //  使用 new 运算符创建的，得到的都是地址
            list[i] = new BankAccount(temp_name, temp_number, temp_balance);
        } else {
            double temp_max_loan, temp_rate;
            cout << "Enter the loan limit: $";
            cin >> temp_max_loan;
            cout << "Enter the rate as a decimal fraction: ";
            cin >> temp_rate;
            list[i] = new BankAccountPlus(temp_name, temp_number, temp_balance, temp_max_loan, temp_rate);
        }
        while(cin.get() != '\n') {
            continue;
        }
    }

    cout << endl;
    for(int i = 0; i < SIZE; i++) {
        //  这里由虚函数定义的方法就能根据实际指向的对象类型切换了...
        list[i]->view();
        cout << endl;
    }

    //  释放内存
    for(int i = 0; i < SIZE; i++) {
        //  在 delete 的时候，调用了“虚析构函数”
        delete list[i];
    }
    cout << "Done...\n";
}