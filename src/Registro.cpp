#include "Registro.h"

Registro::Registro(int id, int cuentaId, int asientoId, std::string notas, float debe, float haber){
        this->notas=notas;
        this->cuentaId=cuentaId;
        this->id=id;
        this->debe=debe;
        this->haber=haber;
        this->asientoId=asientoId;
}
//CANTIDAD DE GETTERS INNECESARIOS ¿Por que no pongo los atributos en publico?
std::string Registro::getNotas(){
    return notas;
}

int Registro::getId(){
    return id;
}

int Registro::getCuentaId(){
    return cuentaId;
}

int Registro::getAsientoId(){
    return asientoId;
}

void Registro::setId(int id){
    this->id=id;
}

float Registro::getDebe(){
    return debe;
}

float Registro::getHaber(){
    return haber;
}
