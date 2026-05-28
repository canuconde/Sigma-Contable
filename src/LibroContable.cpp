#include "LibroContable.h"
#include "Database.h"
#include "Registro.h"
#include "Cuenta.h"
#include "Asiento.h"
#include "RegistroDAO.h"
#include "CuentaDAO.h"
#include "AsientoDAO.h"


using namespace std;

LibroContable::LibroContable(string nombreDB)
{
    Database* db = new Database(nombreDB);
    CuentaDAO::cargarCuentas(db->getDB(),cuentas);
    RegistroDAO::cargarRegistros(db->getDB(),registros);
    AsientoDAO::cargarAsientos(db->getDB(),asientos);
}

LibroContable::~LibroContable()
{
    //dtor
}
