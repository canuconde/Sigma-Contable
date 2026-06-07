#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>
#include <cstdint>
class Registro {
private:
    std::string notas;
    int64_t cuentaId;
    int64_t asientoId;
    int64_t id;
    int64_t debe,haber;
public:
    Registro(int64_t id, int64_t cuentaId, int64_t asientoId, std::string nota,int64_t debe, int64_t haber);
    int64_t getCuentaId();
    int64_t getAsientoId();
    std::string getNotas();
    int64_t getId();
    int64_t getDebe();
    int64_t getHaber();
    void setDebe();
    void setHaber();
    void setId(int64_t id);
};

#endif
