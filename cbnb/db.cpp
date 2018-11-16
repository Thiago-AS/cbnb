#include "db.h"

vector<pair<string, string>> SQLCommand::result_list;

DBError::DBError(string message){
        this->message = message;
}

string DBError::what() {
        return message;
}

void SQLCommand::connect() throw (DBError) {
      rc = sqlite3_open(db_name.c_str(), &db);
      if( rc != SQLITE_OK )
        throw DBError("Erro na conexao ao banco de dados");
}

void SQLCommand::disconnect() throw (DBError) {
      rc =  sqlite3_close(db);
      if( rc != SQLITE_OK )
        throw DBError("Erro na desconexao ao banco de dados");
}

void SQLCommand::execute() throw (DBError) {
        connect();
        rc = sqlite3_exec(db, command.c_str(), callback, 0, &err_message);
        if(rc != SQLITE_OK){
                if (err_message)
                        sqlite3_free(err_message);
                throw DBError("Erro na execucao do comando SQL");
        }
        disconnect();
}

int SQLCommand::callback(void *NotUsed, int argc, char **col_value, char **col_name){
      NotUsed=0;
      for(int i=0; i<argc; i++){
        pair<string, string> pair_value(col_name[i], (col_value[i] ? col_value[i]: "NULL"));
        result_list.push_back(pair_value);
      }
      return 0;
}
