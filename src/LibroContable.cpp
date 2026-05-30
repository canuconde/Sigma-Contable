#include "LibroContable.h"
#include "Database.h"
#include "Registro.h"
#include "Cuenta.h"
#include "Asiento.h"
#include "RegistroDAO.h"
#include "CuentaDAO.h"
#include "AsientoDAO.h"


using namespace std;

LibroContable::LibroContable(string nombreDB): nombreDB(nombreDB)
{
    actualizar();
}

LibroContable::~LibroContable()
{
    //dtor
}
/**< Actualizamos desde la bd */
void LibroContable::actualizar(){

    db = new Database(nombreDB);
    CuentaDAO::cargarCuentas(db->getDB(),cuentas);
    RegistroDAO::cargarRegistros(db->getDB(),registros);
    AsientoDAO::cargarAsientos(db->getDB(),asientos);
}

/**< Esto es ineficiente. El nombre de cuenta deberia ser accesible desde Registro */
std::string LibroContable::getNombreCuenta(int cuentaId){
    for(Cuenta* c : cuentas){
        if(c->getId()==cuentaId) return c->getNombre();
    }
    return "";
}
//Guardamos una cuenta
int LibroContable::GuardarCuenta(std::string nombre, std::string desc, std::string rubro, int numero){
    int id;
    Cuenta* nueva = new Cuenta(0,nombre,desc,rubro,numero);
    cuentas.push_back(nueva);
    CuentaDAO::guardar(db->getDB(),cuentas.back());
    delete nueva;
    id=cuentas.back()->getId();
    //si no se puede guardar lo sacamos del vector
    if(id==0) cuentas.pop_back();
    return id;
}

