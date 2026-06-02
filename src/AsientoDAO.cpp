#include "AsientoDAO.h"
#include "Asiento.h"
#include <sqlite3.h>

//INSERT
void AsientoDAO::guardar(sqlite3* db, Asiento &asiento) {
    //Preparamos el SQL
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO asientos(fecha,comentarios) VALUES( ? , ? );";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    //Asociamos
    sqlite3_bind_text(stmt, 1, asiento.getFecha().data(),-1,NULL);
    sqlite3_bind_text(stmt, 2, asiento.getComentarios().data(),-1,NULL);
    //Ejecutamos
    sqlite3_step(stmt);
    //Obtenemosel ID
    int64_t id = sqlite3_last_insert_rowid(db);
    //Y lo asigamos al vector
    asiento.setId(id);
    sqlite3_finalize(stmt);
}

//SELECT
void AsientoDAO::cargarAsientos(sqlite3* db, std::vector<Asiento> &asientos){

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db,"SELECT id, fecha, comentarios FROM asientos", -1, &stmt, nullptr );
    //deberiamos vaciar el vector antes de continuar
    asientos.clear();

    while (sqlite3_step(stmt) == SQLITE_ROW) {
       int64_t id =  sqlite3_column_int(stmt, 0);
       std::string fecha =(char*)sqlite3_column_text(stmt, 1);
       std::string comentarios =(char*)sqlite3_column_text(stmt, 2);
       asientos.push_back(Asiento(id, fecha, comentarios));
    }
    sqlite3_finalize(stmt);
}

//UPDATE
void AsientoDAO::actualizar(sqlite3* db, Asiento &asiento)
{
    //Preparamos
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE asientos SET fecha = ? , comentarios = ? WHERE id = ?;";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    //asosiamos
    sqlite3_bind_text(stmt, 1, asiento.getFecha().data(),-1,NULL);
    sqlite3_bind_text(stmt, 2, asiento.getComentarios().data(),-1,NULL);
    sqlite3_bind_int64(stmt, 3, asiento.getId());
    //ejecutamos
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    //return rc == SQLITE_DONE;
}

//DELETE
void AsientoDAO::eliminar(sqlite3* db, int64_t id) {
    //Preparamos el SQL
    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM asientos WHERE id = ? ;";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    //Ejecutamos
    sqlite3_bind_int64(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
     //return rc == SQLITE_DONE;
}
