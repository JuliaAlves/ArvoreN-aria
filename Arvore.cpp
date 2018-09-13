#include "include/Arvore.hpp"
#include <iostream>

using namespace std;

namespace ArvoreNaria{
    Arvore::Arvore(unsigned int n){
        this->n = n;
        this->raiz = new No(n);
    }

    void Arvore::add(Tipo* n){
        this-> raiz->addInfo(n);
    }

    void Arvore::del(Tipo* n){
        this-> raiz->deleteInfo(n);
    }

    ostream& operator<<(ostream& os, const Arvore& arv){
        os << *(arv.raiz);
        return os;
    }
}
