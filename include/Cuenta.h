#ifndef CUENTA_H
#define CUENTA_H
#include <string>

class Cuenta {
private:
    std::string nombre;
    std::string descripcion;
    std::string rubro;
    int numero; // este es el nº elegido por el usuario NO ID
    int id;
public:
    Cuenta(int id,std::string nombre, std::string descripcion,std::string rubro, int numero);
    std::string getNombre();
    std::string getDescripcion();
    std::string getRubro();
    int getId();
    int getNumero();
    void setNumero(int numero);
    void setId(int id);
};

#endif
