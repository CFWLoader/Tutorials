#include <iostream>

#include "Point.hpp"

using namespace std;

int main() {

    // Function Pointer.Notice that the pointer points to Point::z();
    double (Point::*pmf)() const = &Point::z;

    // The instance's dynamic type is Point3D.
    Point* ptr = new Point3D(2.0415, 5184.058414, 894.11814);

    // I tried to extract the offset value of destructor but failed.
    /*
    void (Point::*dtor)() = &Point::~Point;
    cout << "The Point::~Point() is virtual and the its offset in virtual table is " << static_cast<int>(dtor) << endl;
     */

    cout << "The value of pmf: " << pmf << endl;

    cout << ptr->z() << endl;

    // Invoking the derived virtual function.
    cout << (ptr->*pmf)() << endl;

    /*
    cout << Point3D::origin_ << endl;

    Point3D point3D(1.03, 2.04, 3.011);

    cout << point3D << endl;
     */

    return 0;
}