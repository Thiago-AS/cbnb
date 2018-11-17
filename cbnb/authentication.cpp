#include "authentication.h"
#include "db.h"

void UserAuthenticationController::SetController(ServiceAuthenticationInterface *sa_controller){
    this->sa_controller = sa_controller;
}

bool UserAuthenticationController::Authenticate() throw(runtime_error){
    Identifier user_identifier;
    Password user_password;
    bool valid_user,valid_data = false;
    string user_entry;

    while(!valid_data){
        try{
            cout << "Type your identifier: ";
            getline(cin, user_entry);
            user_identifier.SetCode(user_entry);
            cout << "Type your password: ";
            getline(cin, user_entry);
            user_password.SetCode(user_entry);
            valid_data = true;
        } catch (const invalid_argument &exp) {
            cout << endl << "Wrong Format" << endl;
        }
    }
    valid_user = sa_controller->Authenticate(user_identifier, user_password);
    if(!valid_user)
        cout << endl << "Authentication failed" << endl;

    return valid_user;
}

bool ServiceAuthenticationController::Authenticate(const Identifier &user_identifier, const Password &user_password) throw(runtime_error){
    string correct_password;
    GetUserPassword sql_command(user_identifier);

    try {
        sql_command.execute();
    }
    catch (DBError exp) {
        cout << exp.what();
        return false;
    }

    try {
        correct_password = sql_command.GetPassword();
        if(user_password.GetCode() == correct_password)
            return true;
        else
            return false;
    } catch (DBError exp) {
        cout << exp.what();
        return false;
    }
}

