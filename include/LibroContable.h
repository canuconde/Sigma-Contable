#ifndef LIBROCONTABLE_H
#define LIBROCONTABLE_H
#include <string>
#include <vector>
#include <cstdint>
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
        int GuardarAsiento(std::string fecha, std::string comentarios);
        int GuardarRegistro(int64_t cuentaId, int64_t asientoId, std::string nota,int64_t debe, int64_t haber);
    protected:

    private:
        std::string nombreDB;
};

#endif // LIBROCONTABLE_H
