//
// Created by May on 2018/11/16.
//

// using "" in include: find it from current project lib
#include "1_using_header_file.h"

//  using <> in include: find it from system lib path
#include <iostream>
#include <cmath>

n_polar rect_to_polar(n_rect r) {
    n_polar p;
    p.distance = sqrt(r.x * r.x + r.y * r.y);
    p.angle = atan2(r.y, r.x);
    return p;
}

void input_and_show_polar() {
    n_rect r;
    n_polar p;
    std::cout << "Please input a rect position:\n";
    while(std::cin >> r.x >> r.y) {
        p = rect_to_polar(r);
        std::cout << "rect[x=" << r.x << ",y=" << r.y << "] => polar[distance=" << p.distance << ",angle=" << p.angle << "]\n";
        std::cout << "Next input(q to quit):\n";
    }
    std::cout << "Bye!\n";
}