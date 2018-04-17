#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <iostream>

using namespace std;

class Cliente
{

    private:
        static long ID;
        string nombre;
        string direccion;
        string RFC;

    public:
        Cliente(string, string, string);
        Cliente();
        virtual ~Cliente();
        friend class Cuenta;
        long GetID();
        void SetID(long);

        string Getnombre();
        void Setnombre(string);

        string Getdireccion();
        void Setdireccion(string);

        string GetRFC();
        void SetRFC(string);

       void verInformacion();

    protected:



};

#endif // CLIENTE_H
