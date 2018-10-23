//
// Created by May on 2018/10/23.
//

#include "8_arr_func_range.h"
#include <iostream>
const int ArSize = 8;
int sum_arr_by_range(const int * begin, const int * end)
{
    const int * pt;
    int total = 0;
    //  [a, b) range
    for (pt = begin; pt != end; pt ++) {
        total = total += *pt;
    }
    return total;
}

int arr_func_range() {
    using namespace std;
    int cookies[ArSize] = {1, 2, 4,  8, 16, 32, 64, 128};

    cout << "Yeah, let's start!" << endl;
    // cookies are actually *address*
    int sum = sum_arr_by_range(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr_by_range(cookies, cookies + 3);
    cout << "First three eaters ate " << sum << " cookies " << endl;
    sum = sum_arr_by_range(cookies + 4, cookies + 8);
    cout << "Last four eaters ate " << sum << " cookies " << endl;
    return 0;
};
