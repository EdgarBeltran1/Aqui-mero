#include "Cuenta.h"
#include<string>

using namespace std;

long Cuenta::numCuenta=10000;

    Cuenta::Cuenta(Cliente Titular, long numCuenta, float saldo){
        Titular=Cliente(Titular);
        numCuenta=numCuenta;
        saldo=saldo;
    }

    void Cuenta::setNumCuenta(long numCuenta){
        numCuenta++;
    }

    long Cuenta::getNumCuenta(){
        return numCuenta;
    }

    Cliente Cuenta::getTitular(){
        return Titular;
    }

    void Cuenta::setTitular(Cliente titular) {
        Titular = titular;
    }

    float Cuenta::getSaldo() {
        return saldo;
    }

    void Cuenta::setSaldo(float saldo) {
        saldo = saldo;
    }

    float Cuenta::retiro(float saldo){
        int cantidad;
        cout<<"\nCuanto desea retirar? "<<endl;
        cin>>cantidad;
        if(cantidad>saldo){
            cout<<"No tiene suficiente dinero"<<endl;
        }else{
            saldo=saldo-cantidad;
        }
        return saldo;
    }
    float Cuenta::deposito(float saldo){
        int cantidad;
        cout<<"\nCuanto desea depositar? "<<endl;
        cin>>cantidad;
        saldo=saldo+cantidad;
        return saldo;
    }

    void Cuenta::consulta(float saldo){
        cout<<"\nSu saldo es de: "<<saldo<<endl;
    }

    void Cuenta::consultaCuenta(float saldo, long numCuenta){
        Titular.verInformacion();
        cout<<"\nNumero de cuenta: "<<numCuenta<<"\nSaldo disponible: "<<saldo<<endl;
    }

Cuenta::~Cuenta()
{
    //dtor
}
