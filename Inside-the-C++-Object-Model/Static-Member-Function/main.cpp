#include <iostream>

using namespace std;

class HasFunctionMember
{
public:
    HasFunctionMember()
    {
        cout << "Construtor is called." << endl;
    }

    int fun()
    {
        cout << "This is a non-static member function." << endl;
    }
private:
};

int main()
{
    // In the age of C++ class hasn't static member function, programmers simulate static member function in this way.
    ((HasFunctionMember*)0)->fun();

    // New C++ style cast.
    static_cast<HasFunctionMember*>(0)->fun();

    return 0;
}