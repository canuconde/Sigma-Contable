#include "Database.h"

#include <iostream>

// CONSTRUCTOR chequeamos si existe la db y sino la creamos
Database::Database(const std::string& nombreDB) {

    if (sqlite3_open(nombreDB.c_str(), &db)) {
        std::cout << "Error al abrir DB\n";
    }
    //Creamos las tablas si no existen
    Database::ejecutarSql(
        "CREATE TABLE IF NOT EXISTS cuentas (id INTEGER PRIMARY KEY AUTOINCREMENT,nombre TEXT, descripcion TEXT,rubro TEXT, numero INTEGER);"
    );
    Database::ejecutarSql(
        "CREATE TABLE IF NOT EXISTS asientos (id INTEGER PRIMARY KEY AUTOINCREMENT,fecha TEXT, comentarios TEXT);"
    );
    Database::ejecutarSql(
        "CREATE TABLE IF NOT EXISTS registros (id INTEGER PRIMARY KEY AUTOINCREMENT,cuenta_id INTEGER,asiento_id INTEGER,nota TEXT, debe INTEGER, haber INTEGER);"
    );
}

Database::~Database() {

    sqlite3_close(db);
}

sqlite3* Database::getDB() {

    return db;
}

//PROBAR ESTO
void Database::ejecutarSql(const std::string& sql) {

    char* errMsg = nullptr;

    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg)
        != SQLITE_OK) {

        std::cout << "Error SQL: " << errMsg << std::endl;

    sqlite3_free(errMsg);
        }
}
