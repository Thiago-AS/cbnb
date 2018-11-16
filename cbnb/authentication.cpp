#include "authentication.h"

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
