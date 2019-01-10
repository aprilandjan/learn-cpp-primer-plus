//
// Created by merlin.ye on 2019/1/5.
//

#include <iostream>
#include "use_template_recursively.h"
#include "ArrayTP.h"

void use_template_recursively() {
    using namespace L14_4;
    ArrayTP<int, 10> sumList;
    ArrayTP<double, 10> averageList;

    //  a nested template usage
    ArrayTP<ArrayTP<int, 5>, 10> numbers;

    int i = 0, j = 0;
    for (i = 0; i < 10; i++) {
        int sum = 0;
        for(j = 0; j < 5; j++) {
            numbers[i][j] = (i + 1) * (j + 1);
            sum += numbers[i][j];
        }
        //  int / int 是 int 类型的除法，得到的也是 int。 因此需要强制类型转换为 double
        // https://stackoverflow.com/questions/36266370/division-in-c
        double average = (double) sum / 5;
        sumList[i] = sum;
        averageList[i] = average;
    }

    //  output
    for (i = 0; i < 10; i++) {
        for(j = 0; j < 5; j++) {
            //  cout.width: 确保输出数字至少占据一定的输出长度
            std::cout.width(2);
            std::cout << numbers[i][j] << " ";
        }
        std::cout.width(3);
        std::cout << ", sum = " << sumList[i] << ", average = " << averageList[i] << std::endl;
    }

    std::cout << "Done.\n";
};

#include "Nested.h"

void use_nested_template() {
    using namespace L14_4;

    Nested<double> obj(3.5, 3);
    cout << "T was set to double\n";
    cout << "K was set to T, which is double, then K was set to int\n";
    obj.show();

    //  this is very likely to Typescript Type inference...
    cout << "\nK was set to int:\n";
    cout << obj.output(10, 3.2) << endl;

    cout << "\nthen, K set to double:\n";
    cout << obj.output(10.0, 3.2) << endl;

    cout << "done...\n";
}

#include "Param.h"
#include "Stack.h"

void use_param_template() {
    using namespace L14_4;

    //  use ArrayTP as param for template
    Param<Stack> param;

    int ni;
    double nd;

    cout << "Enter int double pairs, such as 4 3.5(0 0 to end):\n";
    while(std::cin >> ni >> nd && ni > 0 && nd > 0) {
        if (!param.push(ni, nd)) {
            break;
        }
    }

    while(param.pop(ni, nd)) {
        cout << ni << ", " << nd << endl;
    }

    cout << "Done.\n";
}