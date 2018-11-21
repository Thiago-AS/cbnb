#include "exclusion.h"

void UserExclusionController::SetController(ServiceExclusionInterface *se_controller){
    this->se_controller = se_controller;
}

bool UserExclusionController::DeleteAccommodation(const Identifier &user_id) throw(runtime_error){
    Identifier accommodation_id;
    string user_entry;
    bool valid_exclusion, valid_data = false;

    while(!valid_data){
        try{
            cout << endl << "Type the accommodation identifier to be deleted: ";
            getline(cin, user_entry);
            accommodation_id.SetCode(user_entry);
            valid_data = true;
        } catch (const invalid_argument &exp) {
            cout << endl << "Wrong Format" << endl;
        }
    }

    valid_exclusion = se_controller->DeleteAccommodation(accommodation_id);
    return valid_exclusion;

}

bool ServiceExeclusionController::DeleteAccommodation(const Identifier &accommodation_id) throw(runtime_error){
    DeleteMyAccommodation sql_command(accommodation_id);

    try {
        sql_command.execute();
        return true;
    }
    catch (DBError exp) {
        cout << exp.what();
        return false;
    }
}