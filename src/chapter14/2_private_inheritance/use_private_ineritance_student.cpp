//
// Created by May on 2018/12/25.
//

#include "use_private_ineritance_student.h"
#include "Student.h"

void set_student(L14_2::Student & stu, int n) {
    std::cout << "Please enter the student name:\n";

    //  调用 student 类中定义的友元函数
    getline(std::cin, stu);

    std::cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++) {
        //  先通过 operator[i] 拿到 double 值，再调用 double 的 friend operator>> 赋值
        std::cin >> stu[i];
    }
    while (std::cin.get() != '\n') {
        continue;
    }
}

void use_private_inheritance_student() {
    using namespace L14_2;

    //  seems that the included header files already include iostream, etc
    std::cout << "Private Inheritance Example\n";

    const int num_student = 2;
    const int num_quiz = 3;

    Student list[num_student] = {
            Student(num_quiz),
            Student(num_quiz),
    };
    int i = 0;
    for (i = 0; i < num_student; i++) {
        set_student(list[i], num_quiz);
    }

    std::cout << "\nResult:\n";
    for (i = 0; i < num_student; i++) {
        std::cout << std::endl << list[i];
        std::cout << "average: " << list[i].get_average() << std::endl;
    }
    std::cout << "Done!\n";
}