#ifndef DB_H_INCLUDED
#define DB_H_INCLUDED

#include "domain.h"
#include "entity.h"
#include "sqlite3.h"

#include <vector>

using namespace std;

class DBError {
private:
        string message;
public:
        DBError(string);
        string what();
};

class SQLCommand {
private:
        string db_name;
        sqlite3 *db;
        char *err_message;
        int rc;
        void connect() throw (DBError);
        void disconnect() throw (DBError);
        static int callback(void *, int, char **, char **);

protected:
        static vector<pair<string, string>> result_list;
        string command;
public:
        SQLCommand() {
             db_name = "test";
        }
        void execute() throw (DBError);
};

#endif
