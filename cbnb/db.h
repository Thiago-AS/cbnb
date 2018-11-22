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
             db_name = "test.db";
        }
        void execute() throw (DBError);
};

class InsertNewUser:public SQLCommand {
public:
        InsertNewUser(User);
};

class GetUserPassword:public SQLCommand {
public:
    GetUserPassword(Identifier);
    string GetPassword() throw (DBError);
};

class InsertNewCreditCard:public SQLCommand {
public:
    InsertNewCreditCard(Identifier, CreditCard);
};

class InsertNewCheckingAccount:public SQLCommand {
public:
    InsertNewCheckingAccount(Identifier, CheckingAccount);
};

class InsertNewAccommodation:public SQLCommand {
public:
    InsertNewAccommodation(Identifier, Accommodation);
};

class InsertNewAvailability:public SQLCommand {
public:
    InsertNewAvailability(Identifier, Date, Date);
};

class InsertUserReservation:public SQLCommand{
public:
    InsertUserReservation(Identifier, int);
};

class SearchMyAccommodations:public SQLCommand {
public:
    SearchMyAccommodations(Identifier);
    vector<pair<string, string>> GetMyAccommodations() throw(DBError);
};

class SearchMyAvailability:public SQLCommand{
public:
    SearchMyAvailability(Identifier);
    vector<pair<string, string>> GetMyAvailabilities() throw(DBError);
};

class SearchAllAvaibleAvailabilities:public SQLCommand{
public:
    SearchAllAvaibleAvailabilities();
    vector<pair<string, string>> GetAllAvaibleAvailabilities() throw(DBError);
};

class SearchMyReservations:public SQLCommand{
public:
    SearchMyReservations(Identifier);
    vector<pair<string, string>> GetMyReservations() throw(DBError);
};

class DeleteMyAccommodation:public SQLCommand {
public:
    DeleteMyAccommodation(Identifier);
};

class DeleteAccommodationAvailability:public SQLCommand{
public:
    DeleteAccommodationAvailability(Identifier, Date, Date);
};

#endif
