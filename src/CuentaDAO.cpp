#include "CuentaDAO.h"
#include "Cuenta.h"
#include <sqlite3.h>

//INSERT
void CuentaDAO::guardar(sqlite3* db, Cuenta &cuenta)
{
    sqlite3_stmt* stmt;
    //Preparamos el SQL
    // Reemplazo string por char pointer porque así esta en la documentación (¿por compatibilidad con C ?)
    const char* sql = "INSERT INTO cuentas(nombre,descripcion,rubro,numero) VALUES( ? , ? , ? , ? );";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    //Asosiamos
    sqlite3_bind_text(stmt, 1, cuenta.getNombre().data(),-1,NULL);
    sqlite3_bind_text(stmt, 2, cuenta.getDescripcion().data(),-1,NULL);
    sqlite3_bind_text(stmt, 3, cuenta.getRubro().data(),-1,NULL);
    sqlite3_bind_int64(stmt, 4, cuenta.getNumero());
    //Ejecutamos
    sqlite3_step(stmt);
    //Obtenemosel ID
    int64_t id = sqlite3_last_insert_rowid(db);
    //Y lo asigamos al vector
    cuenta.setId(id);
    sqlite3_finalize(stmt);
}
//SELECT
void CuentaDAO::cargarCuentas(sqlite3* db, std::vector<Cuenta> &cuentas)
{
    //Preparamos
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db,"SELECT id, nombre, descripcion, rubro, numero FROM cuentas ORDER BY rubro ASC", -1, &stmt, nullptr );
    //deberiamos vaciar el vector antes de continuar
    cuentas.clear();

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int64_t id =  sqlite3_column_int64(stmt, 0);
        std::string nombre =(char*)sqlite3_column_text(stmt, 1);
        std::string descripcion =(char*)sqlite3_column_text(stmt, 2);
        std::string rubro =(char*)sqlite3_column_text(stmt, 3);
        int numero =  sqlite3_column_int64(stmt, 4);
        cuentas.push_back(Cuenta(id, nombre,descripcion,rubro, numero));
    }

    sqlite3_finalize(stmt);
}

//UPDATE
void CuentaDAO::actualizar(sqlite3* db, Cuenta &cuenta)
{

    sqlite3_stmt* stmt;
    const char* sql = "UPDATE cuentas SET nombre = ?, descripcion = ?, rubro = ?, numero = ? WHERE id = ?;";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, cuenta.getNombre().data(),-1,NULL);
    sqlite3_bind_text(stmt, 2, cuenta.getDescripcion().data(),-1,NULL);
    sqlite3_bind_text(stmt, 3, cuenta.getRubro().data(),-1,NULL);
    sqlite3_bind_int64(stmt, 4, cuenta.getNumero());
    sqlite3_bind_int64(stmt, 5, cuenta.getId());

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    //return rc == SQLITE_DONE;
}

//DELETE Aca no necesitamos el id. Podriamos recibir la cuenta a eliminar.
void CuentaDAO::eliminar(sqlite3* db, int64_t id)
{
    //Preparamos el SQL
    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM cuentas WHERE id = ? ;";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    //Ejecutamos
    sqlite3_bind_int64(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    //return rc == SQLITE_DONE;
}
