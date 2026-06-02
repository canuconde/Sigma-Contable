#include "Cuenta.h"

Cuenta::Cuenta(int64_t id,std::string nombre, std::string descripcion,std::string rubro , int64_t numero){
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

int64_t Cuenta::getId(){
    return id;
}

void Cuenta::setId(int64_t id){
    this->id=id;
}

int64_t Cuenta::getNumero(){
    return numero;
}

void Cuenta::setNumero(int64_t numero){
    this->numero=numero;
}
