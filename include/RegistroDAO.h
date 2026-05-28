#ifndef REGISTRODAO_H
#define REGISTRODAO_H

#include <vector>

class Registro;
class sqlite3;

class RegistroDAO {

public:
    static void guardar(sqlite3* db, Registro* registros);
    static void eliminar(sqlite3* db, int id);
    static void actualizar(sqlite3* db,int id);
    static void cargarRegistros(sqlite3* db, std::vector<Registro*> &registros);
    static std::vector<Registro*> cargarTodas(sqlite3* db);
};

#endif
