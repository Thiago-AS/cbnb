#include "seeking.h"

void UserSeekController::SetController(ServiceSeekInterface* ss_controller){
    this->ss_controller = ss_controller;
}

vector<pair<string, string>> ServiceSeekController::SearchMyAccommodation(const Identifier &user_id) throw(runtime_error){
    SearchMyAccommodations sql_command(user_id);
    vector<pair<string, string>> my_accommodations;

    try {
        sql_command.execute();
        my_accommodations = sql_command.GetMyAccommodations();
    }
    catch (DBError exp) {
        throw runtime_error(exp.what());
    }
    return my_accommodations;
}



bool UserSeekController::SearchMyAccommodation(const Identifier &user_id) throw(runtime_error){
    vector<pair<string, string>> my_accommodations;
    cout << "My accommodations" << endl << endl;
    try{
        ss_controller->SearchMyAccommodation(user_id);
        for(int i = my_accommodations.size()-1; i >= 0; i--){
            cout << my_accommodations.at(i).first << ": " << my_accommodations.at(i).second << endl;
        }
        return true;
    } catch (const runtime_error &exp) {
        cout << exp.what() << endl;
        return false;
    }
}
