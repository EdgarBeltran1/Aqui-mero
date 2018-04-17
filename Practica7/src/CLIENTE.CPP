#include "Cliente.h"

long Cliente::ID=1000;

Cliente::Cliente(string nombre, string direccion, string RFC){
    nombre=nombre;
    direccion=direccion;
    RFC=RFC;
}

long Cliente::GetID(){
    return ID;
}

void Cliente::SetID(long ID){
    ID++;
}

string Cliente::Getnombre(){
    return nombre;
}

void Cliente::Setnombre(string nombre){
    nombre=nombre;
}

string Cliente::Getdireccion(){
    return direccion;
}

void Cliente::Setdireccion(string direccion){
    direccion=direccion;
}

string Cliente::GetRFC(){
    return RFC;
}

void Cliente::SetRFC(string RFC){
    RFC=RFC;
}

void verInformacion(){
    cout<<"Su nombre es: "<<nombre<<endl;
    cout<<"Su ID es: "<<ID<<endl;
    cout<<"Su direccion es: "<<direccion<<endl;
}



Cliente::~Cliente()
{
    //dtor
}
