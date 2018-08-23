#include "include/No.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace ArvoreNaria
{
    No::No(unsigned int n){
        this->n = n;
        this->galhos = 0;
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
                this->galhos++;

            }

            this->vetPtr[i]->addInfo(n);
        }

    }

    int No::findMaior() const{
        return *(this->vetInfo[this->qtdInf-1]);
    }

    int No::findMenor() const{
        return *(this->vetInfo[0]);
    }

    void No::deleteInfo(int n) throw(char*){
        int i;
        for(i = 0; i < this->qtdInf; i++)
            if(*(this->vetInfo[i]) >= n)
                break;

        if (i == this->qtdInf){
            this->vetPtr[i]->deleteInfo(n);
            return;
        }

        if(*(this->vetInfo[i]) > n){
            this->vetPtr[i]->deleteInfo(n);
            if(this->vetPtr[i]->qtdInf == 0)
                this->vetPtr[i] = 0;
            return;
        }

        if (this->galhos == 0){
            for(int j = this->qtdInf-1; j > i ; j--)
                this->vetInfo[j-1] = this->vetInfo[j];

            this->vetInfo[this->qtdInf] = 0;
            this->qtdInf--;
        }
        else{
            if(this->vetPtr[i] != 0){
                int maior = this->vetPtr[i]->findMaior();
                this->vetPtr[i]->deleteInfo(maior);
                if(this->vetPtr[i]->qtdInf == 0){
                    this->vetPtr[i] = 0;
                    this->galhos--;
                }


                *(this->vetInfo[i]) = maior;
            } else if(this->vetPtr[i+1] != 0){
                int menor = this->vetPtr[i+1]->findMenor();
                this->vetPtr[i+1]->deleteInfo(menor);
                if(this->vetPtr[i+1]->qtdInf == 0){
                    this->vetPtr[i+1] = 0;
                    this->galhos--;
                }

                *(this->vetInfo[i]) = menor;
            } else {
                int j = 0;
                for(j = this->qtdInf-1; j > i ; j--)
                    if(this->vetPtr[j+1] == 0 && this->vetPtr[j] == 0)
                        this->vetInfo[j-1] = this->vetInfo[j];
                    else
                        break;

                if(!this->vetPtr[j]){
                    int maior = this->vetPtr[j]->findMaior();
                    this->vetPtr[j]->deleteInfo(maior);
                    *(this->vetInfo[j]) = maior;
                    if(this->vetPtr[j]->qtdInf == 0){
                        this->vetPtr[j] = 0;
                        this->galhos--;
                    }
                } else if(!this->vetPtr[j+1]){
                    int menor = this->vetPtr[j+1]->findMenor();
                    this->vetPtr[j+1]->deleteInfo(menor);
                    if(this->vetPtr[j+1]->qtdInf == 0){
                        this->vetPtr[j+1] = 0;
                        this->galhos--;
                    }
                    *(this->vetInfo[j]) = menor;

                }
            }
        }
    }

    ostream& operator<<(ostream& os, const No& no){
        os << "( ";
        for(int i = 0; i < no.qtdInf; i++){
            if(no.vetPtr[i])
                os <<*(no.vetPtr[i]) << " ";

            os << *(no.vetInfo[i]) << " ";
        }
        if(no.vetPtr[no.qtdInf])
            os << *(no.vetPtr[no.qtdInf]);
        os << ") ";
        return os;
    }

};
