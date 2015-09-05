#include <iostream>

class Base
{
public:
    void call()
    {
        this->function();
    }

    virtual void function()
    {
        std::cout << "Base::function()" << std::endl;
    }
private:
};

class Derived : public Base
{
public:

    virtual void function()
    {
        std::cout << "Derived::function()" << std::endl;
    }

};


using namespace std;

int main() {

    Base b;

    Derived d;

    Base* pb = new Derived();

    b.call();

    d.call();

    pb->call();

    delete pb;

    return 0;
}