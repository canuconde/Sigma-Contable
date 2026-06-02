#ifndef LIBROCONTABLE_H
#define LIBROCONTABLE_H
#include <string>
#include <vector>
#include "Registro.h"
#include "Cuenta.h"
#include "Asiento.h"
#include "Database.h"


class LibroContable
{
    public:
        LibroContable(std::string nombreDB);
        virtual ~LibroContable();
        Database* db;
        void actualizar();
        std::vector<Cuenta> cuentas;
        std::vector<Registro> registros;
        std::vector<Asiento> asientos;
        std::string getNombreCuenta(int cuentaId);

        int GuardarCuenta(std::string nombre, std::string desc, std::string rubro, int numero);
    protected:

    private:
        std::string nombreDB;
};

#endif // LIBROCONTABLE_H
