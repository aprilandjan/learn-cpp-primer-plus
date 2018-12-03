//
// Created by May on 2018/12/3.
//

#ifndef LEARN_WEIGHT_H
#define LEARN_WEIGHT_H

namespace L11_3 {
    class Weight {
    private:
        /** 每块石头有多重 */
        enum {LB_PER_STN = 14};
        /** 石头数量 */
        int stone;
        double pds_left;
        /** 总重，磅数 */
        double pounds;
    public:
        Weight(double lbs);
        Weight(int stn, double lbs);
        Weight();
        ~Weight();
        void show() const;
    };
};


#endif //LEARN_WEIGHT_H
