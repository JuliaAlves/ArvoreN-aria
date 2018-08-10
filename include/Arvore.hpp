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
            void add(int);
            friend ostream& operator<<(ostream& os, const Arvore& dt);
    };
};