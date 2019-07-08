//
// Created by May on 2019/7/6.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "use_lambda.h"

const long SIZE_1 = 39L;
const long SIZE_2 = 100 * SIZE_1;
const long SIZE_3 = 100 * SIZE_2;

bool d3(int x) {
    return x % 3 == 0;
}

bool d13(int x) {
    return x % 13 == 0;
}

void use_lambda_expressions() {
    using namespace std;

    vector<int> numbers(SIZE_1);
    //  init random seed
    srand(time(0));
    //  fill vector with randomized value
    generate(numbers.begin(), numbers.end(), rand);

//    cout << "numbers: " << numbers << endl;

    //  normal function
    cout << "Sample size = " << SIZE_1 << endl;
    int count_3 = count_if(numbers.begin(), numbers.end(), d3);
    cout << "count of numbers dividable by 3: " << count_3 << endl;

    int count_13 = count_if(numbers.begin(), numbers.end(), d13);
    cout << "count of numbers dividable by 13: " << count_13 << endl;

    numbers.resize(SIZE_2);
    generate(numbers.begin(), numbers.end(), rand);
    cout << "Sample size = " << SIZE_1 << endl;

    //  use class functor
    class divider {
    private:
        int _dv;
    public:
        divider(int v = 1): _dv(v) {};
        bool operator() (int x) {
            return x % _dv == 0;
        }
    };

    count_3 = count_if(numbers.begin(), numbers.end(), divider(3));
    cout << "count of numbers dividable by 3: " << count_3 << endl;

    count_13 = count_if(numbers.begin(), numbers.end(), divider(13));
    cout << "count of numbers dividable by 13: " << count_13 << endl;

    //  use lambda expression
    numbers.resize(SIZE_3);
    generate(numbers.begin(), numbers.end(), rand);
    cout << "Sample size = " << SIZE_1 << endl;

    count_3 = count_if(numbers.begin(), numbers.end(), [](int x){
        return x % 3 == 0;
    });
    cout << "count of numbers dividable by 3: " << count_3 << endl;

    count_13 = count_if(numbers.begin(), numbers.end(), [](int x){
        return x % 13 == 0;
    });
    cout << "count of numbers dividable by 13: " << count_13 << endl;
}

#include <ctime>    //  provide time()

void lambda_with_captured_vars() {
    using std::cout;
    const long SIZE = 390000L;

    std::vector<int> numbers(SIZE);
    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << SIZE << '\n';

    //  use lambda
    int count3 = std::count_if(numbers.begin(), numbers.end(), [](int x){
       return x % 3 == 0;
    });
    cout << "Count of numbers dividable by 3: " << count3 << '\n';

    //  use captured variable
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(), [&count13](int x){
        count13 += (x % 13 == 0 ? 1 : 0);
    });
    cout << "Count of numbers dividable by 13: " << count13 << '\n';

    //  using a single lambda to count these two
    count3 = count13 = 0;
    //  [&]: get all references of auto variables here...
    std::for_each(numbers.begin(), numbers.end(), [&](int x){
        count3 += (x % 3 == 0 ? 1 : 0);
        count13 += (x % 13 == 0 ? 1 : 0);
    });
    cout << "Count of numbers dividable by 3: " << count3 << '\n';
    cout << "Count of numbers dividable by 13: " << count13 << '\n';
}