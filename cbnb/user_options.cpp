#include "user_options.h"

UserOptionsController::UserOptionsController(){
    ur_controller = new UserRegistrationController();
    sr_controller = new ServiceRegistrationController();
    ua_controller = new UserAuthenticationController();
    sa_controller = new ServiceAuthenticationController();

    ur_controller->SetController(sr_controller);
    ua_controller->SetController(sa_controller);
}

UserOptionsController::~UserOptionsController(){
    delete ur_controller;
    delete sr_controller;
    delete ua_controller;
    delete sa_controller;
    ur_controller = NULL;
    sr_controller = NULL;
    ua_controller = NULL;
    sa_controller = NULL;
}

void UserOptionsController::ShowLogin(){
    int user_option;
    bool valid_registration;
    Identifier user_id;
    do{
        cout << "Aircnc" << endl;
        cout << "[1] LogIn" << endl;
        cout << "[2] SignIn" << endl;
        cout << "[3] Exit" << endl;
        cout << "-> ";
        cin >> user_option;
        cin.ignore();

        switch(user_option){
        case 1:
            try{
                user_id.SetCode(ua_controller->Authenticate());
                ShowMainMenu(user_id);
            } catch (const runtime_error &exp) {
                cout << "Authentication failed" << endl;
            }
            break;

        case 2:
            valid_registration = ur_controller->RegisterUser();
            if(valid_registration)
                cout << "Registered successfully" << endl;
            else
                cout << "Registration failed" << endl;
            break;

        case 3:
            break;

        default:
            system("cls");
            cout << "Type one of the options above" << endl;
            break;
        }
    }while(user_option != 3);
}

void UserOptionsController::ShowMainMenu(const Identifier &user_id){
    cout << "main menu" << endl;
}
