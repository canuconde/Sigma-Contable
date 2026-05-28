#ifndef ASIENTO_H
#define ASIENTO_H
#include <string>

class Asiento {
private:
    std::string fecha;
    std::string comentarios;
    int id;
public:
    Asiento(int id, std::string fecha,std::string comentarios);
    int getId();
    std::string getFecha();
    std::string getComentarios();
    void setId(int id);
};

#endif
