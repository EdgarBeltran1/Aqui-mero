#ifndef CUENTA_H
#define CUENTA_H
#include "Cliente.h"
#include<string>
#include<iostream>

using namespace std;

class Cuenta
{
    private:
        static long numCuenta;
        Cliente Titular;
        float saldo;

    public:
        Cuenta(Cliente, long, float);

        virtual ~Cuenta();

        long getNumCuenta();
        void setNumCuenta(long);

        Cliente getTitular();
        void setTitular(Cliente val);

        float getSaldo();
        void setSaldo(float);

        float retiro(float);
        float deposito(float);
        void consulta(float);
        void consultaCuenta(float, long);

    protected:

};

#endif // CUENTA_H
