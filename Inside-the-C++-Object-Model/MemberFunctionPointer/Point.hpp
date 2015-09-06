//
// Created by cfwloader on 9/6/15.
//

#ifndef MEMBERFUNCTIONPOINTER_POINT_H
#define MEMBERFUNCTIONPOINTER_POINT_H

#include <iostream>

// All models are the prototype from Inside the C++ Object Model.
class Point {
public:

    explicit Point(double x = 0.0) : x_(x){}

    double x() const
    {
        return x_;
    }

    void x(double xValue)
    {
        x_ = xValue;
    }

    virtual double y() const
    {
        return 0.0;
    }

    virtual void y(double yValue)
    {
        return;
    }

    virtual double z() const
    {
        return 0.0;
    }

    virtual void z(double zValue)
    {
        return;
    }

private:

    double x_;
};

class Point2D : public Point
{
public:

    explicit Point2D(double x = 0.0, double y = 0.0) : Point(x), y_(y) {}

    double y() const
    {
        return y_;
    }

    void y(double yValue)
    {
        y_ = yValue;
    }

private:

    double y_;

};

class Point3D : public Point2D
{
public:

    explicit Point3D(double x = 0.0, double y = 0.0, double z = 0.0) : Point2D(x, y), z_(z) {}

    double z() const
    {
        return z_;
    }

    void z(double zValue)
    {
        z_ = zValue;
    }

    static Point3D origin_;

private:

    double z_;

};

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "X: " << point.x() << " Y: " << point.y() << " Z: " << point.z();
}

Point3D Point3D::origin_(0.0, 0.0, 0.0);


#endif //MEMBERFUNCTIONPOINTER_POINT_H
