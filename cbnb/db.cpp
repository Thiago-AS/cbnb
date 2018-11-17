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
        throw DBError("Data base connection error");
}

void SQLCommand::disconnect() throw (DBError) {
      rc =  sqlite3_close(db);
      if( rc != SQLITE_OK )
        throw DBError("Data base disconnection error");
}

void SQLCommand::execute() throw (DBError) {
        string error("Data base execution error (");
        error = error + command + ") : ";
        connect();
        rc = sqlite3_exec(db, command.c_str(), callback, 0, &err_message);
        if(rc != SQLITE_OK){
            if (err_message){
                error += err_message;
                sqlite3_free(err_message);
            }
            throw DBError(error);
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

InsertNewUser::InsertNewUser(User user) {
        command = "INSERT INTO User VALUES (";
        command += "'" + user.GetName().GetCode() + "', ";
        command += "'" + user.GetIdentifier().GetCode() + "', ";
        command += "'" + user.GetPassword().GetCode() + "')";
}

GetUserPassword::GetUserPassword(Identifier user_identifier) {
        command = "SELECT Password FROM User WHERE Identifier = '";
        command += user_identifier.GetCode();
        command += "'";
}

string GetUserPassword::GetPassword() throw(DBError){
    pair<string, string> column;
    if(result_list.empty())
        throw DBError("No match found");

    column = result_list.back();
    result_list.pop_back();
    return column.second;
}
