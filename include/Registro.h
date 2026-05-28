#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>

class Registro {
private:
    std::string notas;
    int cuentaId;
    int asientoId;
    int id;
    float debe,haber;
public:
    Registro(int id, int cuentaId, int asientoId, std::string nota,float debe, float haber);
    int getCuentaId();
    int getAsientoId();
    std::string getNotas();
    int getId();
    float getDebe();
    float getHaber();
    void setDebe();
    void setHaber();
    void setId(int id);
};

#endif
