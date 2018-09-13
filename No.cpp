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
        this->vetInfo = new Tipo*[n-1];
        this->vetPtr = new No*[n];
        for(int i=0; i < n ; i++)
            this->vetPtr[i] = 0;
    };

    bool No::isFull() const{
        return n-1 <= this->qtdInf;
    };

    void No::addInfo(Tipo* n) throw(char*){
        int i;
        for(i = 0; i < (this->qtdInf-1); i++)
            if(this->vetInfo[i]->compareTo(*n) >= 1)
                break;

        if (this->qtdInf > 0 && this->vetInfo[i]->compareTo(*n) == 0)
            throw("Informação já existe");

        if(i == this->qtdInf-1 && this->vetInfo[qtdInf-1]->compareTo(*n) <= -1)
            i++;

        if (!this->isFull()) {
            for(int j = (this->qtdInf-1); j >= i; j--)
                this->vetInfo[j+1] = this->vetInfo[j];

            this->vetInfo[i] = new Tipo(*n);
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

    Tipo* No::findMaior() const{
        return this->vetInfo[this->qtdInf-1];
    }

    Tipo* No::findMenor() const{
        return this->vetInfo[0];
    }

    void No::deleteInfo(Tipo* n) throw(char*){
        int i;
        for(i = 0; i < this->qtdInf; i++)
            if(this->vetInfo[i]->compareTo(*n) >= 1 || this->vetInfo[i]->compareTo(*n) == 0)
                break;

        if (n->compareTo(*this->vetInfo[i]) < 0){
            this->vetPtr[i]->deleteInfo(n);
            return;
        } else if (n->compareTo(*this->vetInfo[i]) > 0){
            this->vetPtr[i + 1]->deleteInfo(n);
            return;
        }

        if(this->vetInfo[i]->compareTo(*n) > 1){
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
        else {
            bool frente = false;
            int j = 0;
            for(j = i; j < this->n; j++)
                if (this->vetPtr[j] != 0){
                    frente = true;
                    break;
                }

            if (frente){
                int j = 0;
                for(j = i; j < this->qtdInf; j++)
                    if(this->vetPtr[j+1] == 0 && this->vetPtr[j] == 0)
                        this->vetInfo[j] = new Tipo(*this->vetInfo[j+1]);
                    else
                        break;

                if(this->vetPtr[j]){
                    Tipo* maior = this->vetPtr[j]->findMaior();
                    this->vetPtr[j]->deleteInfo(maior);
                    this->vetInfo[j] = new Tipo(*maior);
                    if(this->vetPtr[j]->qtdInf == 0){
                        delete this->vetPtr[j];
                        this->vetPtr[j] = 0;
                        this->galhos--;
                    }
                } else if(this->vetPtr[j+1]){
                    Tipo* menor = this->vetPtr[j+1]->findMenor();
                    this->vetPtr[j+1]->deleteInfo(menor);
                    this->vetInfo[j] = new Tipo(*menor);
                    if(this->vetPtr[j+1]->qtdInf == 0){
                        delete this->vetPtr[j+1];
                        this->vetPtr[j+1] = 0;
                        this->galhos--;
                    }
                }
            }
            else {
                int j = 0;
                for(j = i; j > 0; j--)
                    if(this->vetPtr[j] == 0 && this->vetPtr[j+1] == 0)
                        this->vetInfo[j] = new Tipo(*this->vetInfo[j-1]);
                    else
                        break;

                if(this->vetPtr[j]){
                    Tipo* maior = this->vetPtr[j]->findMaior();
                    this->vetPtr[j]->deleteInfo(maior);
                    this->vetInfo[j] = new Tipo(*maior);
                    if(this->vetPtr[j]->qtdInf == 0){
                        this->vetPtr[j] = 0;
                        delete this->vetPtr[j];
                        this->galhos--;
                    }
                } else if(this->vetPtr[j+1]){
                    Tipo* menor = this->vetPtr[j]->findMenor();
                    this->vetPtr[j+1]->deleteInfo(menor);
                    this->vetInfo[j+1] = new Tipo(*menor);
                    if(this->vetPtr[j+1]->qtdInf == 0){
                        delete this->vetPtr[j+1];
                        this->vetPtr[j+1] = 0;
                        this->galhos--;
                    }
                }
            }
        }
    }

    ostream& operator<<(ostream& os, const No& no){
        os << "( ";
        for(int i = 0; i < no.qtdInf; i++){
            if(no.vetPtr[i])
                os <<*(no.vetPtr[i]) << " ";

            os << no.vetInfo[i]->getValor() << " ";
        }
        if(no.vetPtr[no.qtdInf])
            os << *(no.vetPtr[no.qtdInf]);
        os << ") ";
        return os;
    }

};
