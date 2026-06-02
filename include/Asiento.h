#ifndef ASIENTO_H
#define ASIENTO_H
#include <string>
#include <cstdint>
class Asiento {
private:
    std::string fecha;
    std::string comentarios;
    int64_t id;
public:
    Asiento(int64_t id, std::string fecha,std::string comentarios);
    int64_t getId();
    std::string getFecha();
    std::string getComentarios();
    void setId(int64_t id);
};

#endif
