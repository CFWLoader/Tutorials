//
// Created by Exia on 2015/8/27.
//

#ifndef POINTER_TO_DATA_MEMBER_POINT_H
#define POINTER_TO_DATA_MEMBER_POINT_H

#include <cstdio>

class Point1D
{
public:
    Point1D(double xValue) : x(xValue)
    {}
protected:
    double x;
};

class Point2D : public Point1D
{
public:
    Point2D(double x, double yValue) : Point1D(x), y(yValue)
    {}

protected:
    double y;
};

class Point3D : public Point2D
{
public:
    Point3D(double x, double y, double zValue) : Point2D(x, y), z(zValue)
    {}

    static void showDataMemberMemoryLayout()
    {
        printf("&Point3D::x = %p.\n", &Point3D::x);
        printf("&Point3D::y = %p.\n", &Point3D::y);
        printf("&Point3D::z = %p.\n", &Point3D::z);
    }

    static void showInstanceDataMemberMemoryLayout()
    {
        printf("&Point3D::origin::x = %p.\n", &Point3D::origin.x);
        printf("&Point3D::origin::y = %p.\n", &Point3D::origin.y);
        printf("&Point3D::origin::z = %p.\n", &Point3D::origin.z);
    }

protected:

    static Point3D origin;

    double z;
};


#endif //POINTER_TO_DATA_MEMBER_POINT_H
