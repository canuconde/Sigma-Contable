#ifndef LIBROCONTABLE_H
#define LIBROCONTABLE_H
#include <string>
#include <vector>
#include "Registro.h"
#include "Cuenta.h"
#include "Asiento.h"

class sqlite3;

class LibroContable
{
    public:
        LibroContable(std::string nombreDB);
        virtual ~LibroContable();
        sqlite3* db;
        void actualizar();
        std::vector<Cuenta*> cuentas;
        std::vector<Registro*> registros;
        std::vector<Asiento*> asientos;
        std::string getNombreCuenta(int cuentaId);
    protected:

    private:
        std::string nombreDB;
};

#endif // LIBROCONTABLE_H
