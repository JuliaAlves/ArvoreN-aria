namespace ArvoreNaria
{
    class Tipo
    {
        private:
            int valor;

        public:
            Tipo(const unsigned int);
            Tipo(const Tipo&);
            int compareTo(Tipo) throw(char*);
            int getValor() const;
    };
};
