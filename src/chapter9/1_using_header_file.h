//
// Created by May on 2018/11/16.
//

#ifndef LEARN_1_USING_HEADER_FILE_H
#define LEARN_1_USING_HEADER_FILE_H

//  类型声明
struct n_polar {
    double distance;
    double angle;
};

struct n_rect {
    double x;
    double y;
};

//  原型
n_polar rect_to_polar(n_rect pos);
void show_polar(n_polar pos);

void input_and_show_polar();

#endif //LEARN_1_USING_HEADER_FILE_H
