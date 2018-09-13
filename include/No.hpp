#include <iostream>
#include "Tipo.hpp"

using namespace std;
namespace ArvoreNaria
{
    class No
    {
        private:
            Tipo ** vetInfo;
            No ** vetPtr;
            int n;
            int qtdInf;
            int galhos;

        public:
            No(unsigned int);
            bool isFull() const;
            void addInfo(Tipo*) throw(char*);
            friend ostream& operator<<(ostream& os, const No& dt);
            Tipo* findMaior() const;
            Tipo* findMenor() const;
            void deleteInfo(Tipo*) throw(char*);
    };
};
