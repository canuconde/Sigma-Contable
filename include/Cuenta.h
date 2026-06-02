#ifndef CUENTA_H
#define CUENTA_H
#include <string>
#include <cstdint>
class Cuenta {
private:
    std::string nombre;
    std::string descripcion;
    std::string rubro;
    int64_t numero; // este es el nº elegido por el usuario NO ID
    int64_t id;
public:
    Cuenta(int64_t id,std::string nombre, std::string descripcion,std::string rubro, int64_t numero);
    std::string getNombre();
    std::string getDescripcion();
    std::string getRubro();
    int64_t getId();
    int64_t getNumero();
    void setNumero(int64_t numero);
    void setId(int64_t id);
};

#endif
