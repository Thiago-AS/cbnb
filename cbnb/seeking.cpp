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

vector<pair<string, string>> ServiceSeekController::SearchMyAvailabilities(const Identifier &user_id) throw(runtime_error){
    SearchMyAvailability sql_command(user_id);
    vector<pair<string, string>> my_availabilities;

    try {
        sql_command.execute();
        my_availabilities = sql_command.GetMyAvailabilities();
    }
    catch (DBError exp) {
        throw runtime_error(exp.what());
    }
    return my_availabilities;
}

vector<pair<string, string>> ServiceSeekController::SearchAllAvailabilities() throw(runtime_error){
    SearchAllAvaibleAvailabilities sql_command;
    vector<pair<string, string>> all_availabilities;

    try {
        sql_command.execute();
        all_availabilities = sql_command.GetAllAvaibleAvailabilities();
    }
    catch (DBError exp) {
        throw runtime_error(exp.what());
    }
    return all_availabilities;
}


bool UserSeekController::SearchMyAccommodation(const Identifier &user_id) throw(runtime_error){
    vector<pair<string, string>> my_accommodations;
    cout << "My accommodations" << endl << endl;
    try{
        my_accommodations = ss_controller->SearchMyAccommodation(user_id);
        for( int i = my_accommodations.size()-1, line = 1; i >= 0; line++, i--){
            if(line%6 == 0)
                cout << my_accommodations.at(i).first << ": " << my_accommodations.at(i).second << endl << endl;
            else
                cout << my_accommodations.at(i).first << ": " << my_accommodations.at(i).second << endl;
        }
        return true;
    } catch (const runtime_error &exp) {
        cout << exp.what() << endl;
        return false;
    }
}

bool UserSeekController::SearchMyAvailabilities(const Identifier &user_id) throw(runtime_error){
    vector<pair<string, string>> my_availabilities;
    cout << "My availabilities" << endl << endl;
    try{
        my_availabilities = ss_controller->SearchMyAvailabilities(user_id);
        for( int i = my_availabilities.size()-1, line = 1; i >= 0; line++, i--){
            if(line%3 == 0)
                cout << my_availabilities.at(i).first << ": " << my_availabilities.at(i).second << endl << endl;
            else
                cout << my_availabilities.at(i).first << ": " << my_availabilities.at(i).second << endl;
        }
        return true;
    } catch (const runtime_error &exp) {
        cout << exp.what() << endl;
        return false;
    }
}

bool UserSeekController::SearchAllAvailabilities() throw(runtime_error){
    vector<pair<string, string>> all_availabilities;
    cout << "Non-reserved availabilities" << endl << endl;
    try{
        all_availabilities = ss_controller->SearchAllAvailabilities();
        for( int i = all_availabilities.size()-1, line = 1; i >= 0; line++, i--){
            if(line%9 == 0)
                cout << all_availabilities.at(i).first << ": " << all_availabilities.at(i).second << endl << endl;
            else
                cout << all_availabilities.at(i).first << ": " << all_availabilities.at(i).second << endl;
        }
        return true;
    } catch (const runtime_error &exp) {
        cout << exp.what() << endl;
        return false;
    }
}

