#include "Asiento.h"

Asiento::Asiento(int id, std::string fecha, std::string comentarios){
    this->id=id;
    this->fecha=fecha;
    this->comentarios=comentarios;
}

int Asiento::getId(){
    return id;
}

std::string Asiento::getFecha(){
    return fecha;
}

std::string Asiento::getComentarios(){
    return comentarios;
}

void Asiento::setId(int id){
    this->id=id;
}
