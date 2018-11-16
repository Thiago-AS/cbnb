#include "registration.h"

void UserRegistrationController::SetController(ServiceRegistrationInterface *sr_controller){
    this->sr_controller = sr_controller;
}

bool UserRegistrationController::Register() throw(runtime_error){
    Name user_name;
    Identifier user_identifier;
    Password user_password;
    bool valid_registration, valid_data = false;
    string user_entry;

    while(!valid_data){
        try{
            cout << "Type your name: "
            getline(cin, user_entry);
            user_name.SetCode(user_entry);
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
    valid_registration = sr_controller->Register(user_name, user_identifier, user_password);
    if(!valid_registration)
        cout << endl << "Authentication failed" << endl;

    return valid_registration;
}
