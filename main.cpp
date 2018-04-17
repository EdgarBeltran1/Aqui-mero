#include "Cuenta.h"
#include "Cliente.h"
#include<string>

using namespace std;

int main(){
    string nombre;
    string RFC;
    string direccion;
    long numero;
    float dinero;
    float &actual=dinero;


    cout<<"Ingrese el numero de cuenta del titular: "<<endl;
    cin>>numero;
    cin.ignore();
    cout<<"\nIngrese el nombre del titular de la cuenta: "<<endl;
    getline(cin, nombre);
    cout<<"\nIngrese el saldo que desea tener: "<<endl;
    cin>>dinero;
    cout<<"\nIngrese su RFC "<<endl;
    getline(cin, RFC);
    cout<<"\nIngrese su direccion: "<<endl;
    getline(cin, direccion);


    Cuenta cuenta(Cliente(nombre, direccion, RFC), numero, dinero);
    cuenta.consultaCuenta(dinero, numero);

    int opcion=0;

    while(opcion!=5){
        cout<<"\nQue desea hacer? Ingrese el numero de la opcion \n1-Retiro \n2-Deposito \n3-Consulta de saldo "/*\n4-Consulta de Informacion */"\n4-Salir"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                actual=cuenta.retiro(dinero);
                break;
            case 2:
                actual=cuenta.deposito(dinero);
                break;
            case 3:
                cuenta.consulta(dinero);
                break;
                /*
            case 4:
                cuenta.consultaCuenta(dinero, numero, titular);
                break;
                */
            case 4:
                continue;
        }
    }

    opcion=0;

    cout<<"Ingrese el numero de cuenta del titular: "<<endl;
    cin>>numero;
    cin.ignore();
    cout<<"\nIngrese el nombre del titular de la cuenta: "<<endl;
    getline(cin, nombre);
    cout<<"\nIngrese el saldo que desea tener: "<<endl;
    cin>>dinero;
    cout<<"\nIngrese su RFC "<<endl;
    getline(cin, RFC);
    cout<<"\nIngrese su direccion: "<<endl;
    getline(cin, direccion);


    Cuenta cuenta2(Cliente(nombre, direccion, RFC), numero, dinero);
    cuenta2.consultaCuenta(dinero, numero);


    while(opcion!=5){
        cout<<"\nQue desea hacer? Ingrese el numero de la opcion \n1-Retiro \n2-Deposito \n3-Consulta de saldo "/*\n4-Consulta de Informacion */"\n4-Salir"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                actual=cuenta.retiro(dinero);
                break;
            case 2:
                actual=cuenta.deposito(dinero);
                break;
            case 3:
                cuenta.consulta(dinero);
                break;
                /*
            case 4:
                cuenta.consultaCuenta(dinero, numero, titular);
                break;
                */
            case 4:
                continue;
        }
    }
}
