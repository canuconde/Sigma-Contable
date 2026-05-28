#include "RegistroDAO.h"
#include "Registro.h"

#include <sqlite3.h>

//INSERT
void RegistroDAO::guardar(sqlite3* db, Registro* registro) {
    //Preparamos el SQL
    std::string sql = "INSERT INTO registros(cuenta_id, asiento_id,nota,debe,haber) VALUES('"+ std::to_string(registro->getCuentaId())+ "','"+std::to_string(registro->getAsientoId())+ "','"+ registro->getNotas()+ "','" + std::to_string(registro->getDebe()) + "','" + std::to_string(registro->getHaber()) + "');";
    //Ejecutamos
    sqlite3_exec(db,sql.c_str(),nullptr, nullptr, nullptr);
    //Obtenemosel ID
    int id = sqlite3_last_insert_rowid(db);
    //Y lo asigamos al vector
    registro->setId(id);
}
//SELECT
void RegistroDAO::cargarRegistros(sqlite3* db, std::vector<Registro*> &registros){
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db,"SELECT id, cuenta_id, asiento_id, nota, debe, haber FROM registros", -1, &stmt, nullptr );

    //deberiamos vaciar el vector antes de continuar

    registros.clear();

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        int id =  sqlite3_column_int(stmt, 0);

        int cuentaId =  sqlite3_column_int(stmt, 1);

        int asientoId =  sqlite3_column_int(stmt, 2);

        std::string nota =(char*)sqlite3_column_text(stmt, 3);

        float debe =sqlite3_column_double(stmt, 4);

        float haber = sqlite3_column_double(stmt, 5);

        registros.push_back(new Registro(id, cuentaId,asientoId,nota,debe,haber));
    }

    sqlite3_finalize(stmt);

}
//FALTA UPDATE
//DELETE
void RegistroDAO::eliminar(sqlite3* db, int id) {
    char *zErrMsg = 0;
        int rc;
    //Preparamos el SQL
    std::string sql = "DELETE FROM registros WHERE id='"+ std::to_string(id) +"';";
    //Ejecutamos
    rc=sqlite3_exec(db,sql.c_str(),nullptr, nullptr, nullptr);
    if( rc!=SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
            }
}
