#include "RegistroDAO.h"
#include "Registro.h"
#include <sqlite3.h>

//INSERT
void RegistroDAO::guardar(sqlite3* db, Registro& registro) {
    //Preparamos el SQL
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO registros(cuenta_id, asiento_id,nota,debe,haber) VALUES( ?, ?, ?, ?, ?);";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    //Asociamos
    sqlite3_bind_int64(stmt, 1, registro.getCuentaId());
    sqlite3_bind_int64(stmt, 2, registro.getAsientoId());
    sqlite3_bind_text(stmt, 3, registro.getNotas().data(),-1,NULL);
    sqlite3_bind_int64(stmt, 4, registro.getDebe());
    sqlite3_bind_int64(stmt, 5, registro.getHaber());
    //Ejecutamos
    sqlite3_step(stmt);
    //Obtenemosel ID
    int64_t id = sqlite3_last_insert_rowid(db);
    //Y lo asigamos al vector
    registro.setId(id);
}
//SELECT
void RegistroDAO::cargarRegistros(sqlite3* db, std::vector<Registro> &registros){

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db,"SELECT id, cuenta_id, asiento_id, nota, debe, haber FROM registros ORDER BY asiento_id ASC", -1, &stmt, nullptr );
    //deberiamos vaciar el vector antes de continuar
    registros.clear();

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int64_t id =  sqlite3_column_int(stmt, 0);
        int64_t cuentaId =  sqlite3_column_int(stmt, 1);
        int64_t asientoId =  sqlite3_column_int(stmt, 2);
        std::string nota =(char*)sqlite3_column_text(stmt, 3);
        int64_t debe =sqlite3_column_double(stmt, 4);
        int64_t haber = sqlite3_column_double(stmt, 5);
        registros.push_back(Registro(id, cuentaId,asientoId,nota,debe,haber));
    }

    sqlite3_finalize(stmt);
}

//UPDATE
void RegistroDAO::actualizar(sqlite3* db, Registro& registro)
{
    //Preparamos
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE registros SET cuenta_id = ?, asiento_id = ?, nota = ?, debe = ?, haber = ? WHERE id = ?;";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    //asosiamos
    sqlite3_bind_int64(stmt, 1, registro.getCuentaId());
    sqlite3_bind_int64(stmt, 2, registro.getAsientoId());
    sqlite3_bind_text(stmt, 3, registro.getNotas().data(),-1,NULL);
    sqlite3_bind_int64(stmt, 4, registro.getDebe());
    sqlite3_bind_int64(stmt, 5, registro.getHaber());
    sqlite3_bind_int64(stmt, 6, registro.getId());
    //ejecutamos
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    //return rc == SQLITE_DONE;
}

//DELETE
void RegistroDAO::eliminar(sqlite3* db, int64_t id) {
    //Preparamos el SQL
    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM registros WHERE id = ? ;";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    //Ejecutamos
    sqlite3_bind_int64(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    //return rc == SQLITE_DONE;
}
