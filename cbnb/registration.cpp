#include "registration.h"
#include "db.h"

void UserRegistrationController::SetController(ServiceRegistrationInterface *sr_controller){
    this->sr_controller = sr_controller;
}

bool UserRegistrationController::RegisterUser() throw(runtime_error){
    Name user_name;
    Identifier user_identifier;
    Password user_password;
    bool valid_registration, valid_data = false;
    string user_entry;

    while(!valid_data){
        try{
            cout << "Type your name: ";
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
            system("cls");
            cout << "Wrong Format" << endl;
        }
    }
    valid_registration = sr_controller->RegisterUser(user_name, user_identifier, user_password);
    if(!valid_registration){
        cout << endl << "Registration failed" << endl;
        return valid_registration;
    }

    CreditCardNumber card_number;
    ExpirationDate card_exp;
    valid_data = false;
    while(!valid_data){
        try{
            cout << "Type your credit card number: ";
            getline(cin, user_entry);
            card_number.SetCode(user_entry);
            cout << "Type the card expiration date: ";
            getline(cin, user_entry);
            card_exp.SetValue(user_entry);
            valid_data = true;
        } catch (const invalid_argument &exp) {
            system("cls");
            cout << "Wrong Format" << endl;
        }
    }
    valid_registration = sr_controller->RegisterCreditCard(card_number, card_exp, user_identifier);
    if(!valid_registration){
        cout << endl << "Registration failed" << endl;
        return valid_registration;
    }

    CheckingAccountNumber ca_number;
    Agency agency;
    Bank bank;
    valid_data = false;
    while(!valid_data){
        try{
            cout << "Type your checking account number: ";
            getline(cin, user_entry);
            ca_number.SetCode(user_entry);
            cout << "Type your agency number: ";
            getline(cin, user_entry);
            agency.SetCode(user_entry);
            cout << "Type your bank number: ";
            getline(cin, user_entry);
            bank.SetCode(user_entry);
            valid_data = true;
        } catch (const invalid_argument &exp) {
            system("cls");
            cout << "Wrong Format" << endl;
        }
    }
    valid_registration = sr_controller->RegisterCheckingAccount(ca_number, agency, bank, user_identifier);
    if(!valid_registration){
        cout << endl << "Registration failed" << endl;
    }

    return valid_registration;
}

bool UserRegistrationController::RegisterAccommodation(const Identifier& user_id) throw(runtime_error){
    Identifier accommodation_identifier;
    AccommodationCapacity capacity;
    AccommodationType type;
    Name city;
    State state;
    DailyFee fee;
    bool valid_registration, valid_data = false;
    string user_entry;

    while(!valid_data){
        try{
            cout << "Type the accommodation identifier: ";
            getline(cin, user_entry);
            accommodation_identifier.SetCode(user_entry);
            cout << "Type the accommodation type: ";
            getline(cin, user_entry);
            type.SetCode(user_entry);
            cout << "Type the accommodation capacity: ";
            getline(cin, user_entry);
            capacity.SetAmount(stoi(user_entry));
            cout << "Type the city: ";
            getline(cin, user_entry);
            city.SetCode(user_entry);
            cout << "Type the state: ";
            getline(cin, user_entry);
            state.SetCode(user_entry);
            cout << "Type the daily fee : ";
            getline(cin, user_entry);
            fee.SetValue(stoi(user_entry));
            valid_data = true;
        } catch (const invalid_argument &exp) {
            system("cls");
            cout << "Wrong Format" << endl;
        }
    }
    Accommodation new_accommodation(accommodation_identifier, type, capacity, city, state, fee);
    valid_registration = sr_controller->RegisterAccommodation(new_accommodation, user_id);
    if(!valid_registration){
        cout << endl << "Registration failed" << endl;
    }
    return valid_registration;
}

bool UserRegistrationController::RegisterAvailability() throw(runtime_error) {
    Date initial_date, end_date;
    Identifier accommodation_id;
    string user_entry;
    bool valid_registration, valid_data = false;

    while(!valid_data){
        try{
            cout << "Type the accommodation identifier to add the dates: ";
            getline(cin, user_entry);
            accommodation_id.SetCode(user_entry);
            cout << "Type the initial date: ";
            getline(cin, user_entry);
            initial_date.SetValue(user_entry);
            cout << "Type the end date: ";
            getline(cin, user_entry);
            end_date.SetValue(user_entry);
            valid_data = true;
        } catch (const invalid_argument &exp) {
            system("cls");
            cout << "Wrong Format" << endl;
        }
    }
    valid_registration = sr_controller->RegisterAvailability(initial_date, end_date, accommodation_id);
    if(!valid_registration){
        cout << endl << "Registration failed" << endl;
    }
    return valid_registration;
}


bool ServiceRegistrationController::RegisterUser(const Name &user_name, const Identifier &user_identifier, const Password &user_password) throw(runtime_error){
    User new_user(user_name, user_identifier, user_password);
    InsertNewUser sql_command(new_user);

    try {
        sql_command.execute();
        return true;
    }
    catch (DBError exp) {
        cout << exp.what();
        return false;
    }
}

bool ServiceRegistrationController::RegisterCreditCard(const CreditCardNumber &card_num, const ExpirationDate &card_exp, const Identifier &user_identifier) throw(runtime_error){
    CreditCard new_card(card_num, card_exp);
    InsertNewCreditCard sql_command(user_identifier, new_card);

    try {
        sql_command.execute();
        return true;
    }
    catch (DBError exp) {
        cout << exp.what();
        return false;
    }
}

bool ServiceRegistrationController::RegisterCheckingAccount(const CheckingAccountNumber &ca_number, const Agency &agency, const Bank &bank, const Identifier &user_identifier) throw(runtime_error){
    CheckingAccount new_checking_account(ca_number, agency, bank);
    InsertNewCheckingAccount sql_command(user_identifier, new_checking_account);

    try {
        sql_command.execute();
        return true;
    }
    catch (DBError exp) {
        cout << exp.what();
        return false;
    }
}

bool ServiceRegistrationController::RegisterAccommodation(const Accommodation &accommodation, const Identifier &user_identifier) throw(runtime_error){
    InsertNewAccommodation sql_command(user_identifier, accommodation);

    try {
        sql_command.execute();
        return true;
    }
    catch (DBError exp) {
        cout << exp.what();
        return false;
    }
}

bool ServiceRegistrationController::RegisterAvailability(const Date &initial_date, const Date&end_date, const Identifier &accommodation_id) throw(runtime_error){
    InsertNewAvailability sql_command(accommodation_id, initial_date, end_date);

    try {
        sql_command.execute();
        return true;
    }
    catch (DBError exp) {
        cout << exp.what();
        return false;
    }
}
