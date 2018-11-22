#include "exclusion.h"

void UserExclusionController::SetController(ServiceExclusionInterface *se_controller){
    this->se_controller = se_controller;
}

bool UserExclusionController::DeleteAccommodation() throw(runtime_error){
    Identifier accommodation_id;
    string user_entry;
    bool valid_exclusion, valid_data = false;

    while(!valid_data){
        try{
            cout << "Type the accommodation identifier to be deleted: ";
            getline(cin, user_entry);
            accommodation_id.SetCode(user_entry);
            valid_data = true;
        }catch (const invalid_argument &exp){
            cout << "Wrong Format" << endl << endl;
        }
    }

    valid_exclusion = se_controller->DeleteAccommodation(accommodation_id);
    return valid_exclusion;
}

bool UserExclusionController::DeleteAvailability() throw(runtime_error){
    Identifier accommodation_id;
    Date initial_date, end_date;
    string user_entry;
    bool valid_exclusion, valid_data = false;

    while(!valid_data){
        try{
            cout << "Type the accommodation identifier to be deleted: ";
            getline(cin, user_entry);
            accommodation_id.SetCode(user_entry);
            cout << "Type the inital date: ";
            getline(cin, user_entry);
            initial_date.SetValue(user_entry);
            cout << "Type the end date: ";
            getline(cin, user_entry);
            end_date.SetValue(user_entry);
            valid_data = true;
        }catch (const invalid_argument &exp){
            cout << "Wrong Format" << endl << endl;
        }
    }

    valid_exclusion = se_controller->DeleteAvailability(initial_date, end_date, accommodation_id);
    return valid_exclusion;
}

bool ServiceExeclusionController::DeleteAccommodation(const Identifier &accommodation_id) throw(runtime_error){
    DeleteMyAccommodation sql_command(accommodation_id);

    try{
        sql_command.execute();
        return true;
    }
    catch (DBError exp){
        cout << exp.what();
        return false;
    }
}

bool ServiceExeclusionController::DeleteAvailability(const Date &initial_date, const Date &end_date, const Identifier &accommodation_id) throw(runtime_error){
    DeleteAccommodationAvailability sql_command(accommodation_id, initial_date, end_date);
    try{
        sql_command.execute();
        return true;
    }catch (DBError exp){
        cout << exp.what();
        return false;
    }
}
