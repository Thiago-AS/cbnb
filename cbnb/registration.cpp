#include "registration.h"
#include "db.h"

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
            cout << endl << "Wrong Format" << endl;
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
            cout << endl << "Wrong Format" << endl;
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
            cout << endl << "Wrong Format" << endl;
        }
    }
    valid_registration = sr_controller->RegisterCheckingAccount(ca_number, agency, bank, user_identifier);
    if(!valid_registration){
        cout << endl << "Registration failed" << endl;
        return valid_registration;
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
