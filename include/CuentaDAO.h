#ifndef CUENTADAO_H
#define CUENTADAO_H

#include <vector>

class Cuenta;
class sqlite3;

class CuentaDAO {

public:
    static void guardar(sqlite3* db, Cuenta* cuenta);
    static void eliminar(sqlite3* db, int id);
    static void actualizar(sqlite3* db,Cuenta* cuenta);
    static void cargarCuentas(sqlite3* db, std::vector<Cuenta*> &cuentas);
    static std::vector<Cuenta*> cargarTodas(sqlite3* db);
};

#endif
