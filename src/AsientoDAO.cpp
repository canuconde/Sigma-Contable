#include "AsientoDAO.h"
#include "Asiento.h"
#include <sqlite3.h>

//INSERT
void AsientoDAO::guardar(sqlite3* db, Asiento* asiento) {
    //Preparamos el SQL
    std::string sql = "INSERT INTO asientos(fecha,comentarios) VALUES('"+ asiento->getFecha()+ "','"+ asiento->getComentarios()+ "');";
    //Ejecutamos
    sqlite3_exec(db,sql.c_str(),nullptr, nullptr, nullptr);
    //Obtenemosel ID
    int id = sqlite3_last_insert_rowid(db);
    //Y lo asigamos al vector
    asiento->setId(id);
}
//SELECT
void AsientoDAO::cargarAsientos(sqlite3* db, std::vector<Asiento*> &asientos){
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db,"SELECT id, fecha, comentarios FROM asientos", -1, &stmt, nullptr );

    //deberiamos vaciar el vector antes de continuar

    asientos.clear();

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        int id =  sqlite3_column_int(stmt, 0);

        std::string fecha =(char*)sqlite3_column_text(stmt, 1);

        std::string comentarios =(char*)sqlite3_column_text(stmt, 2);

        asientos.push_back(new Asiento(id, fecha, comentarios));
    }

    sqlite3_finalize(stmt);

}
//DELETE
void AsientoDAO::eliminar(sqlite3* db, int id) {
    char *zErrMsg = 0;
    int rc;
    //Preparamos el SQL
    std::string sql = "DELETE FROM asientos WHERE id='"+ std::to_string(id) +"';";
    //Ejecutamos
    rc=sqlite3_exec(db,sql.c_str(),nullptr, nullptr, nullptr);
    if( rc!=SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}
