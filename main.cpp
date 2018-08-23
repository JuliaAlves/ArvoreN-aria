#include "include/Arvore.hpp"
using namespace ArvoreNaria;

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    Arvore a(4);

    a.add(10);
    a.add(1);
    a.add(5);
    a.add(30);
    a.add(2);
    a.add(15);
    a.add(3);
    a.add(20);
    a.add(7);
    a.add(8);

    std::cout << a << "\n \n";

    a.del(1);
    std::cout << a << "\n \n";
    a.del(3);
    std::cout << a << "\n \n";
    a.del(10);
    std::cout << a << "\n \n";
    a.del(20);
    std::cout << a << "\n \n";
    a.del(7);
    std::cout << a << "\n \n";

    return 0;
}
