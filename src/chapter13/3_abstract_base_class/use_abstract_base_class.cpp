//
// Created by May on 2018/12/20.
//

#include <iostream>
#include <string>
#include "use_abstract_base_class.h"
#include "Account.h"

void use_abstract_base_class() {
    using namespace L13_3;
    using std::cout;
    using std::cin;
    using std::endl;

    const int SIZE = 4;
    Account * account_list[SIZE];

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
            account_list[i] = new BankAccount(temp_name, temp_number, temp_balance);
        } else {
            double temp_max_loan, temp_rate;
            cout << "Enter the loan limit: $";
            cin >> temp_max_loan;
            cout << "Enter the rate as a decimal fraction: ";
            cin >> temp_rate;
            account_list[i] = new BankAccountPlus(temp_name, temp_number, temp_balance, temp_max_loan, temp_rate);
        }
        while(cin.get() != '\n') {
            continue;
        }
    }

    cout << endl;
    for(int i = 0; i < SIZE; i++) {
        //  这里由虚函数定义的方法就能根据实际指向的对象类型切换了...
        account_list[i]->view();
        cout << endl;
    }

    //  释放内存
    for(int i = 0; i < SIZE; i++) {
        //  在 delete 的时候，调用了“虚析构函数”
        delete account_list[i];
    }
    cout << "Done...\n";
}
