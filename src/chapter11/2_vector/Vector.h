//
// Created by May on 2018/12/1.
//

#ifndef LEARN_VECTOR_H
#define LEARN_VECTOR_H

namespace L11_2 {
    class Vector {
    public:
        enum MODE { RECT, POL };
    private:
        //  直角坐标
        double _x;
        double _y;
        //  极坐标
        double _radian;
        double _radius;
        //  setter?
        void set_x(double x);
        void set_y(double y);
        void set_radian(double rad);
        void set_radius(double radius);
    public:
        Vector();
        Vector(double arg1, double arg2, MODE mode = RECT);
        ~Vector();
        void reset(double arg1, double arg2, MODE mode = RECT);
        void show(MODE mode = RECT) const;
        //  getter?
        double get_x() const { return _x; };
        double get_y() const { return _y; };
        double get_radius() const { return _radius; };
        double get_radian() const { return _radian; };
    };
}

#endif //LEARN_VECTOR_H
