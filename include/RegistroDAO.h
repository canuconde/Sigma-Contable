#ifndef REGISTRODAO_H
#define REGISTRODAO_H
#include "sqlite3.h"
#include <vector>
#include <cstdint>

class Registro;
class sqlite3;

class RegistroDAO {

public:
    static void guardar(sqlite3* db, Registro &registros);
    static void eliminar(sqlite3* db, int64_t id);
    static void actualizar(sqlite3* db, Registro &registro);
    static void cargarRegistros(sqlite3* db, std::vector<Registro> &registros);
    static std::vector<Registro*> cargarTodas(sqlite3* db);
};

#endif
