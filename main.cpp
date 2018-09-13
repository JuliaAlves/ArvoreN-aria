#include "include/Arvore.hpp"
using namespace ArvoreNaria;

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    Arvore a(3);
    Tipo* n = new Tipo(20);
    a.add(n);
    a.add(new Tipo(19));
    a.add(new Tipo(18));
    a.add(new Tipo(17));
    a.add(new Tipo(16));
    a.add(new Tipo(15));
    a.add(new Tipo(14));
    a.add(new Tipo(13));
    a.add(new Tipo(12));
    a.add(new Tipo(11));
    a.add(new Tipo(10));
    a.add(new Tipo(9));
    a.add(new Tipo(8));
    a.add(new Tipo(7));
    a.add(new Tipo(6));
    a.add(new Tipo(5));
    a.add(new Tipo(4));
    a.add(new Tipo(3));
    a.add(new Tipo(2));
    a.add(new Tipo(1));

    std::cout << a << "\n \n";

    a.del(new Tipo(7));
    std::cout << a << "\n \n";


    return 0;
}
