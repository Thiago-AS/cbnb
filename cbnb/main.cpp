#include <iostream>
#include "domain.h"
#include "tests_domain.h"
#include "entity.h"
#include "db.h"

int main() {

    sqlite3 *db;
    int rc = sqlite3_open("test.db", &db);
      if( rc != SQLITE_OK )
        throw DBError("Erro na conexao ao banco de dados");

    return 0;
}
