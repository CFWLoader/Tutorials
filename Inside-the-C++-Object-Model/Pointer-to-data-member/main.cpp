#include <iostream>

#include "Point.hpp"

using namespace std;

/**
class Point3D
{
public:
    Point3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

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

private:
    static Point3D origin;

    double x, y, z;
};
 */

Point3D Point3D::origin(0, 0, 0);

int main()
{
    Point3D::showDataMemberMemoryLayout();

    Point3D::showInstanceDataMemberMemoryLayout();

    return 0;
}