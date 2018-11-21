#include "exclusion.h"

void UserExclusionController::SetController(ServiceExclusionInterface *se_controller){
    this->se_controller = se_controller;
}

bool UserExclusionController::DeleteAccommodation(const Identifier &user_id) throw(runtime_error){
    Identifier accommodation_id;
    vector<pair<string, string>> my_accommodations;
    string user_entry;
    bool valid_exclusion, valid_data = false;

    cout << "My accommodations" << endl << endl;

    SearchMyAccommodations sql_command(user_id);
    try {
        sql_command.execute();
        my_accommodations = sql_command.GetMyAccommodations();
        for(int i = my_accommodations.size()-1; i >= 0; i--){
            cout << my_accommodations.at(i).first << ": " << my_accommodations.at(i).second << endl;
        }
    }
    catch (DBError exp) {
        cout << exp.what();
    }

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
