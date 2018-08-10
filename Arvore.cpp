#include "include/Arvore.hpp"
#include <iostream>

using namespace std;

namespace ArvoreNaria{
    Arvore::Arvore(unsigned int n){
        this->n = n;
        this->raiz = new No(n);
    }

    void Arvore::add(int n){
        this-> raiz->addInfo(n);
    }

    ostream& operator<<(ostream& os, const Arvore& arv){
        os << *(arv.raiz);
        return os;
    }
}
