#include "CuentaDAO.h"
#include "Cuenta.h"

#include <sqlite3.h>

//INSERT
void CuentaDAO::guardar(sqlite3* db, Cuenta* cuenta) {
    //Preparamos el SQL
    std::string sql = "INSERT INTO cuentas(nombre,descripcion,rubro,numero) VALUES('"+ cuenta->getNombre()+ "','"+ cuenta->getDescripcion()+ "','" + cuenta->getRubro() + "','" + std::to_string(cuenta->getNumero()) + "');";
    //Ejecutamos
    sqlite3_exec(db,sql.c_str(),nullptr, nullptr, nullptr);
    //Obtenemosel ID
    int id = sqlite3_last_insert_rowid(db);
    //Y lo asigamos al vector
    cuenta->setId(id);
}
//SELECT
void CuentaDAO::cargarCuentas(sqlite3* db, std::vector<Cuenta*> &cuentas){
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db,"SELECT id, nombre, descripcion, rubro, numero FROM cuentas", -1, &stmt, nullptr );

    //deberiamos vaciar el vector antes de continuar

    cuentas.clear();

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        int64_t id =  sqlite3_column_int(stmt, 0);

        std::string nombre =(char*)sqlite3_column_text(stmt, 1);

        std::string descripcion =(char*)sqlite3_column_text(stmt, 2);

        std::string rubro =(char*)sqlite3_column_text(stmt, 3);

        int numero =  sqlite3_column_int(stmt, 4);

        cuentas.push_back(new Cuenta(id, nombre,descripcion,rubro, numero));
    }

    sqlite3_finalize(stmt);

}
//UPDATE
void CuentaDAO::actualizar(sqlite3* db, Cuenta* cuenta){

    sqlite3_stmt* stmt;

    const char* sql =
    "UPDATE cuentas SET nombre = ?, descripcion = ?, rubro = ?, numero = ? WHERE id = ?;";

    sqlite3_prepare_v2(
        db,
        sql,
        -1,
        &stmt,
        nullptr
    );

    sqlite3_bind_text(stmt, 1, cuenta->getNombre().data(),sizeof(cuenta->getNombre().data()),NULL);
    sqlite3_bind_text(stmt, 2, cuenta->getDescripcion().data(),sizeof(cuenta->getDescripcion().data()),NULL);
    sqlite3_bind_text(stmt, 3, cuenta->getRubro().data(),sizeof(cuenta->getRubro().data()),NULL);
    sqlite3_bind_int(stmt, 4, cuenta->getNumero());
    sqlite3_bind_int(stmt, 5, cuenta->getId());

    int rc = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    //return rc == SQLITE_DONE;

}
//DELETE
void CuentaDAO::eliminar(sqlite3* db, int64_t id) {
    char *zErrMsg = 0;
        int rc;
    //Preparamos el SQL
    std::string sql = "DELETE FROM cuentas WHERE id='"+ std::to_string(id) +"';";
    //Ejecutamos
    rc=sqlite3_exec(db,sql.c_str(),nullptr, nullptr, nullptr);
    if( rc!=SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
            }
}
