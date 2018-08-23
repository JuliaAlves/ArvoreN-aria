#include <iostream>

using namespace std;
namespace ArvoreNaria
{
    class No
    {
        private:
            int ** vetInfo;
            No ** vetPtr;
            int n;
            int qtdInf;
            int galhos;

        public:
            No(unsigned int);
            bool isFull() const;
            void addInfo(int) throw(char*);
            friend ostream& operator<<(ostream& os, const No& dt);
            int findMaior() const;
            int findMenor() const;
            void deleteInfo(int) throw(char*);
    };
};
