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
    for(Cuenta c : cuentas){
        if(c.getId()==cuentaId) return c.getNombre();
    }
    return "";
}
//Guardamos una cuenta
int LibroContable::GuardarCuenta(std::string nombre, std::string desc, std::string rubro, int numero){
    int id;
    Cuenta nueva = Cuenta(0,nombre,desc,rubro,numero);
    cuentas.push_back(nueva);
    CuentaDAO::guardar(db->getDB(),cuentas.back());

    id=cuentas.back().getId();
    //si no se puede guardar lo sacamos del vector
    if(id==0) cuentas.pop_back();
    return id;
    //BUG Corregido el delete nueva; eliminaba tambien la direccion en cuentas.
    //No hacemos delete nueva; esto lo hacemos en LibroContable
}
//
int LibroContable::GuardarAsiento(std::string fecha, std::string comentarios){
    int id;
    Asiento nuevo = Asiento(0,fecha,comentarios);
    asientos.push_back(nuevo);
    AsientoDAO::guardar(db->getDB(),asientos.back());

    id=asientos.back().getId();
    //si no se puede guardar lo sacamos del vector
    if(id==0) asientos.pop_back();
    return id;
}
//
int LibroContable::GuardarRegistro(int64_t cuentaId, int64_t asientoId, std::string nota,int64_t debe, int64_t haber){
    int id;
    Registro nuevo = Registro(0,cuentaId,asientoId,nota,debe,haber);
    registros.push_back(nuevo);
    RegistroDAO::guardar(db->getDB(),registros.back());

    id=registros.back().getId();
    //si no se puede guardar lo sacamos del vector
    if(id==0) registros.pop_back();
    return id;
}
