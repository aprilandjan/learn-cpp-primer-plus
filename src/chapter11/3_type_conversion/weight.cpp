//
// Created by May on 2018/12/3.
//

#include <iostream>
#include "weight.h"

namespace L11_3 {
    Weight::Weight() {
        std::cout << "init without param\n";
        stone = pounds = pds_left = 0;
    }
    /**
     * 磅数，转换为石头数量，计算不足1块石头的部分
     * @param lbs
     */
    Weight::Weight(double lbs) {
        std::cout << "init with a double param\n";
        stone = lbs / LB_PER_STN;
        //  % 只能用于整形？...
        pds_left = int(lbs) % LB_PER_STN + lbs - int(lbs);
        pounds = lbs;
    }
    /**
     * 根据石头数，剩下的磅数，算总重
     * @param stn
     * @param lbs
     */
    Weight::Weight(int stn, double lbs) {
        std::cout << "init with two params\n";
        stone = stn;
        pds_left = lbs;
        pounds = stn * LB_PER_STN + lbs;
    }
    Weight::~Weight() {}
    void Weight::show() const {
        std::cout << stone << " stones, " << pds_left << " pounds\n";
    }
    //  转换函数的实现. 不能加返回类型的定义
    Weight::operator int() const {
        std::cout << "transform int: " << stone << " ";
        return stone;
    }
    Weight::operator double() const {
        std::cout << "transform double: " << pounds << " ";
        return pounds;
    }
}