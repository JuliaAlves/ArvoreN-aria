#include "include/Arvore.hpp"
using namespace ArvoreNaria;

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    Arvore a(3);

    a.add(10);
    a.add(1);
    a.add(5);
    a.add(30);
    a.add(2);
    a.add(15);

    std::cout << a;

    return 0;
}
