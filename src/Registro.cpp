#include "Registro.h"

Registro::Registro(int64_t id, int64_t cuentaId, int64_t asientoId, std::string notas, int64_t debe, int64_t haber){
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

int64_t Registro::getId(){
    return id;
}

int64_t Registro::getCuentaId(){
    return cuentaId;
}

int64_t Registro::getAsientoId(){
    return asientoId;
}

void Registro::setId(int64_t id){
    this->id=id;
}

int64_t Registro::getDebe(){
    return debe;
}

int64_t Registro::getHaber(){
    return haber;
}
