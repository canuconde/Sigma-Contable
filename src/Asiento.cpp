#include "Asiento.h"

Asiento::Asiento(int64_t id, std::string fecha, std::string comentarios){
    this->id=id;
    this->fecha=fecha;
    this->comentarios=comentarios;
}

int64_t Asiento::getId(){
    return id;
}

std::string Asiento::getFecha(){
    return fecha;
}

std::string Asiento::getComentarios(){
    return comentarios;
}

void Asiento::setId(int64_t id){
    this->id=id;
}
