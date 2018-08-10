#include "include/No.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace ArvoreNaria
{
    No::No(unsigned int n){
        this->n = n;
        this->qtdInf = 0;
        this->vetInfo = new int*[n-1];
        this->vetPtr = new No*[n];
        for(int i=0; i < n ; i++)
            this->vetPtr[i] = 0;
    };

    bool No::isFull() const{
        return n-1 <= this->qtdInf;
    };

    void No::addInfo(int n) throw(char*){
        int i;
        for(i = 0; i < (this->qtdInf-1); i++)
            if(*(this->vetInfo[i]) > n)
                break;

        if (this->qtdInf > 0 && *(this->vetInfo[i]) == n)
            throw("Informação já existe");

        if(i == this->qtdInf-1 && *(this->vetInfo[qtdInf-1]) < n)
            i++;

        if (!this->isFull()) {
            for(int j = (this->qtdInf-1); j >= i; j--)
                this->vetInfo[j+1] = this->vetInfo[j];

            this->vetInfo[i] = new int(n);
            this->qtdInf++;
        }
        else
        {
            if (this->vetPtr[i] == 0){
                this->vetPtr[i] = new No(this->n);
            }

            this->vetPtr[i]->addInfo(n);
        }

    }

    ostream& operator<<(ostream& os, const No& no){
        os << "(";
        for(int i = 0; i < no.qtdInf; i++){
            if(no.vetPtr[i])
                os << *(no.vetPtr[i]) << ", ";

            os << *(no.vetInfo[i]) << ", ";
        }
        if(no.vetPtr[no.qtdInf])
            os << *(no.vetPtr[no.qtdInf]);
        os << ")";
        return os;
    }

};
