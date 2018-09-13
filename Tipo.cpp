#include "include/Tipo.hpp"

namespace ArvoreNaria{
    Tipo::Tipo(const unsigned int v){
        this->valor = v;
    }

    Tipo::Tipo(const Tipo& t){
        this->valor = t.valor;
    }

    int Tipo::compareTo(Tipo t) throw(char*){
        if (t.valor == this->valor)
            return 0;
        else if (t.valor < this->valor)
            return 1;
        else
            return -1;
    }

    int Tipo::getValor() const
    {
        return this->valor;
    }
}
