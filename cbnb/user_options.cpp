#include "user_options.h"
#include "db.h"

UserOptionsController::UserOptionsController(){
    ur_controller = new UserRegistrationController();
    sr_controller = new ServiceRegistrationController();
    ua_controller = new UserAuthenticationController();
    sa_controller = new ServiceAuthenticationController();
    ue_controller = new UserExclusionController();
    se_controller = new ServiceExeclusionController();

    ur_controller->SetController(sr_controller);
    ua_controller->SetController(sa_controller);
    ue_controller->SetController(se_controller);
}

UserOptionsController::~UserOptionsController(){
    delete ur_controller;
    delete sr_controller;
    delete ua_controller;
    delete sa_controller;
    delete ue_controller;
    delete se_controller;
    ur_controller = NULL;
    sr_controller = NULL;
    ua_controller = NULL;
    sa_controller = NULL;
    ue_controller = NULL;
    se_controller = NULL;
}

void UserOptionsController::ShowLogin(){
    system("cls");
    int user_option;
    bool valid_registration;
    Identifier user_id;
    do{
        cout << "Aircnc" << endl;
        cout << "[1] LogIn" << endl;
        cout << "[2] SignIn" << endl;
        cout << "[0] Exit" << endl << endl;
        cout << "-> ";
        cin >> user_option;
        cin.ignore();

        switch(user_option){
        case 1:
            try{
                system("cls");
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

        case 0:
            break;

        default:
            system("cls");
            cout << "Type one of the options above" << endl;
            break;
        }
    }while(user_option != 0);
}

void UserOptionsController::ShowMainMenu(const Identifier &user_id){
    system("cls");
    int user_option;
    do{
        cout << "[1] Accommodations" << endl;
        cout << "[2] Availabilities" << endl;
        cout << "[3] Reservations" << endl;
        cout << "[4] Account settings" << endl;
        cout << "[0] LogOut" << endl << endl;
        cout << "-> ";
        cin >> user_option;
        cin.ignore();

        switch(user_option){
        case 1:
            ShowAccommodationMenu(user_id);
            break;

        case 2:
            ShowAvailabilitiesMenu(user_id);
            break;

        case 3:
            ShowReservationMenu(user_id);
            break;

        case 4:
            ShowAccountSettingsMenu(user_id);
            break;

        case 0:
            system("cls");
            break;

        default:
            system("cls");
            cout << "Type one of the options above" << endl;
            break;
        }
    }while(user_option != 0);
}

void UserOptionsController::ShowAccommodationMenu(const Identifier &user_id){
    system("cls");
    int user_option;
    do{
        cout << "[1] Register" << endl;
        cout << "[2] Delete" << endl;
        cout << "[0] Back" << endl << endl;
        cout << "-> ";
        cin >> user_option;
        cin.ignore();

        switch(user_option){
        case 1:
            system("cls");
            ur_controller->RegisterAccommodation(user_id);
            break;

        case 2:
            system("cls");
            ue_controller->DeleteAccommodation(user_id);

            break;

        case 0:
            system("cls");
            break;

        default:
            system("cls");
            cout << "Type one of the options above" << endl;
            break;
        }
    }while(user_option != 0);
}

void UserOptionsController::ShowAvailabilitiesMenu(const Identifier &user_id){
}

void UserOptionsController::ShowReservationMenu(const Identifier &user_id){
}

void UserOptionsController::ShowAccountSettingsMenu(const Identifier &user_id){


}
