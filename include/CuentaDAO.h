#ifndef CUENTADAO_H
#define CUENTADAO_H
#include "sqlite3.h"
#include <vector>
#include <cstdint>
class Cuenta;


class CuentaDAO {

public:
    static void guardar(sqlite3* db, Cuenta &cuenta);
    static void eliminar(sqlite3* db, int64_t id);
    static void actualizar(sqlite3* db,Cuenta &cuenta);
    static void cargarCuentas(sqlite3* db, std::vector<Cuenta> &cuentas);
    static std::vector<Cuenta*> cargarTodas(sqlite3* db);
};

#endif
