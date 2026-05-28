#include "Cuenta.h"

Cuenta::Cuenta(int id,std::string nombre, std::string descripcion,std::string rubro , int numero){
        this->nombre=nombre;
        this->descripcion=descripcion;
        this->id=id;
        this->numero=numero;
        this->rubro=rubro;
}
//CANTIDAD DE GETTERS INNECESARIOS ¿Por que no pongo los atributos en publico?
std::string Cuenta::getNombre(){
    return nombre;
}

std::string Cuenta::getDescripcion(){
    return descripcion;
}

std::string Cuenta::getRubro(){
    return rubro;
}

int Cuenta::getId(){
    return id;
}

void Cuenta::setId(int id){
    this->id=id;
}

int Cuenta::getNumero(){
    return numero;
}

void Cuenta::setNumero(int numero){
    this->numero=numero;
}
