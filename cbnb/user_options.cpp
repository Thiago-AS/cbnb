#include "user_options.h"

UserOptionsController::UserOptionsController(){
    ur_controller = new UserRegistrationController();
    sr_controller = new ServiceRegistrationController();
    ua_controller = new UserAuthenticationController();
    sa_controller = new ServiceAuthenticationController();
    ue_controller = new UserExclusionController();
    se_controller = new ServiceExeclusionController();
    us_controller = new UserSeekController();
    ss_controller = new ServiceSeekController();

    ur_controller->SetController(sr_controller);
    ua_controller->SetController(sa_controller);
    ue_controller->SetController(se_controller);
    us_controller->SetController(ss_controller);
}

UserOptionsController::~UserOptionsController(){
    delete ur_controller;
    delete sr_controller;
    delete ua_controller;
    delete sa_controller;
    delete ue_controller;
    delete se_controller;
    delete us_controller;
    delete ss_controller;
    ur_controller = NULL;
    sr_controller = NULL;
    ua_controller = NULL;
    sa_controller = NULL;
    ue_controller = NULL;
    se_controller = NULL;
    us_controller = NULL;
    ss_controller = NULL;
}

void UserOptionsController::ShowLogin(){
    system("cls");
    int user_option;
    Identifier user_id;
    do{
        cout << "Aircnc" << endl << endl;
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
                cout << endl <<  exp.what() << endl << endl;
                cout << "Press enter to continue..." << endl;
                getchar();
                system("cls");
            }
            break;

        case 2:
            if(ur_controller->RegisterUser())
                cout << endl << "Registered successfully" << endl;
            else
                cout << endl << "Registration failed" << endl;

            cout << endl << "Press enter to continue..." << endl;
            getchar();
            system("cls");
            break;

        case 0:
            break;

        default:
            system("cls");
            cout << "Type one of the options above" << endl << endl;
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
            if(ur_controller->RegisterAccommodation(user_id))
                cout << endl << "Registered successfully" << endl;
            else
                cout << endl << "Registration failed" << endl;

            cout << endl << "Press enter to continue..." << endl;
            getchar();
            system("cls");
            break;

        case 2:
            system("cls");
            if(us_controller->SearchMyAccommodation(user_id)){
                if(ue_controller->DeleteAccommodation())
                    cout << endl << "Deleted successfully" << endl;
                else
                    cout << endl << "Deleted failed" << endl;
            }
            cout << endl << "Press enter to continue..." << endl;
            getchar();
            system("cls");
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
            if(us_controller->SearchMyAccommodation(user_id)){
                if(ur_controller->RegisterAvailability())
                    cout << endl << "Registered successfully" << endl;
                else
                    cout << endl << "Registration failed" << endl;
            }
            cout << endl << "Press enter to continue..." << endl;
            getchar();
            system("cls");
            break;
        case 2:
            system("cls");
            if(us_controller->SearchMyAvailabilities(user_id)){
                if(ue_controller->DeleteAvailability())
                    cout << endl << "Deleted successfully" << endl;
                else
                    cout << endl << "Deleted failed" << endl;
            }
            cout << endl << "Press enter to continue..." << endl;
            getchar();
            system("cls");
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

void UserOptionsController::ShowReservationMenu(const Identifier &user_id){
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
            if(us_controller->SearchAllAvailabilities()){
                if(ur_controller->RegisterReservation(user_id))
                    cout << endl << "Reservation made successfully" << endl;
                else
                    cout << endl << "Reservation not made" << endl;
            }
            cout << endl << "Press enter to continue..." << endl;
            getchar();
            system("cls");
            break;
        case 2:
            system("cls");
            if(us_controller->SearchMyReservation(user_id)){
                if(true)
                    cout << endl << "Deleted successfully" << endl;
                else
                    cout << endl << "Deleted failed" << endl;
            }
            cout << endl << "Press enter to continue..." << endl;
            getchar();
            system("cls");
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


void UserOptionsController::ShowAccountSettingsMenu(const Identifier &user_id){


}
