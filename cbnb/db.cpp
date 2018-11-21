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

InsertNewCreditCard::InsertNewCreditCard(Identifier user_identifier, CreditCard credit_card){
        command = "INSERT INTO CreditCard VALUES (";
        command += "'" + credit_card.GetNumber().GetCode() + "', ";
        command += "'" + credit_card.GetExpirationDate().GetValue() + "', ";
        command += "'" + user_identifier.GetCode() + "')";
}

InsertNewCheckingAccount::InsertNewCheckingAccount(Identifier user_identifier, CheckingAccount checking_account) {
        command = "INSERT INTO CheckingAccount VALUES (";
        command += "'" + checking_account.GetNumber().GetCode() + "', ";
        command += "'" + checking_account.GetAgency().GetCode() + "', ";
        command += "'" + checking_account.GetBank().GetCode() + "', ";
        command += "'" + user_identifier.GetCode() + "')";
}

InsertNewAccommodation::InsertNewAccommodation(Identifier user_identifier, Accommodation accommodation) {
        command = "INSERT INTO Accommodation VALUES (";
        command += "'" + accommodation.GetIdentifier().GetCode() + "', ";
        command += "'" + accommodation.GetType().GetCode() + "', ";
        command += to_string(accommodation.GetCapacity().GetAmount()) + ", ";
        command += "'" + accommodation.GetCity().GetCode() + "', ";
        command += "'" + accommodation.GetState().GetCode() + "', ";
        command += to_string(accommodation.GetDailyFee().GetValue()) + ", ";
        command += "'" + user_identifier.GetCode() + "')";
}

InsertNewAvailability::InsertNewAvailability(Identifier accommodation_id, Date initial_date, Date end_date) {
        command = "INSERT INTO Availability(InitialDate, EndDate, AccommodationId) VALUES (";
        command += "'" + initial_date.GetValue() + "', ";
        command += "'" + end_date.GetValue() + "', ";
        command += "'" + accommodation_id.GetCode() + "')";
}

SearchMyAccommodations::SearchMyAccommodations(Identifier user_id) {
        command = "SELECT Identifier, Type, Capacity, City, State, Fee FROM Accommodation WHERE HostId = '";
        command += user_id.GetCode() + "'";
}

vector<pair<string, string>> SearchMyAccommodations::GetMyAccommodations() throw(DBError){
    vector<pair<string, string>> my_accommodations;
    if(result_list.empty())
        throw DBError("No registered accommodation");

    int result_list_size = result_list.size();
    for(int i = 0; i < result_list_size; i++){
        my_accommodations.push_back(result_list.back());
        result_list.pop_back();
    }
    return my_accommodations;
}

DeleteMyAccommodation::DeleteMyAccommodation(Identifier accommodation_id){
    command = "DELETE FROM Accommodation WHERE Identifier = '";
    command += accommodation_id.GetCode() + "'";
}
