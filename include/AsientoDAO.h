#ifndef ASIENTODAO_H
#define ASIENTODAO_H
#include "sqlite3.h"
#include <vector>

class Asiento;


class AsientoDAO {

public:
    static void guardar(sqlite3* db, Asiento* asiento);
    static void eliminar(sqlite3* db, int id);
    static void actualizar(sqlite3* db,int id);
    static void cargarAsientos(sqlite3* db, std::vector<Asiento*> &Asientos);
    static std::vector<Asiento*> cargarTodas(sqlite3* db);
};

#endif
