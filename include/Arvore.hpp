#include "No.hpp"
#include <iostream>

using namespace std;

namespace ArvoreNaria
{
    class Arvore
    {
        private:
            int n;
            No* raiz;

        public:
            Arvore(unsigned int);
            void add(Tipo*);
            void del(Tipo*);
            friend ostream& operator<<(ostream& os, const Arvore& dt);
    };
};
