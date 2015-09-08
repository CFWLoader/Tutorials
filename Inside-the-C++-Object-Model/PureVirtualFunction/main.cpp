#include <iostream>

#include "ConcreteDerived.h"

using namespace std;

int main()
{

    ConcreteDerived concreteDerived("Hello.");

    concreteDerived.interface();

    cout << concreteDerived.mumble() << endl;

    return 0;
}