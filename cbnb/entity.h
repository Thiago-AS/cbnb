#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "domain.h"

class User {
 private:
    Name name;
    Identifier identifier;
    Password password;

 public:
    void SetName(const Name &name){
        this->name = name;
    }

    Name GetName() const {
        return name;
    }

    void SetIdentifier(const Identifier &identifier){
        this->identifier = identifier;
    }

    Identifier GetIdentifier() const {
        return identifier;
    }

    void SetPassword(const Password &password){
        this->password = password;
    }

    Password GetPassword() const {
        return password;
    }
};

class Accommodation {
 private:
    Identifier identifier;
    AccommodationType type;
    AccommodationCapacity capacity;
    Date initial_date;
    Date end_date;
    Name city;
    State state;
    DailyFee daily_fee;

 public:
    void SetIdentifier(const Identifier &identifier) {
        this->identifier = identifier;
    }

    Identifier GetIdentifier() const {
        return identifier;
    }

    void SetType(const AccommodationType &type) {
        this->type = type;
    }

    AccommodationType GetType() const {
        return type;
    }

    void SetCapacity(const AccommodationCapacity &capacity) {
        this->capacity = capacity;
    }

    AccommodationCapacity GetType() const {
        return capacity;
    }

    void SetInitialDate(const Date &initial_date) {
        this->initial_date = initial_date;
    }

    Date GetInitialDate() const {
        return initial_date;
    }

    void SetEndDate(const Date &end_date) {
        this->end_date = end_date;
    }

    Date GetEndDate() const {
        return end_date;
    }

    void SetCity(const Name &city) {
        this->city = city;
    }

    Name GetCity() const {
        return city;
    }

    void SetState(const State &state) {
        this->state = state;
    }

    State GetState() const {
        return state;
    }

    void SetDailyFee(const DailyFee &daily_fee) {
        this->daily_fee = daily_fee;
    }

    State GetDailyFee() const {
        return daily_fee;
    }
};

class CreditCard {
 private:
    CreditCardNumber number;
    ExpirationDate expiration_date;

 public:
    void SetNumber(const CreditCardNumber &number){
        this->number = number;
    }

    CreditCardNumber GetNumber() const {
        return number;
    }

    void SetExpirationDate(const ExpirationDate &expiration_date){
        this->expiration_date = expiration_date;
    }

    ExpirationDate GetExpirationDate() const {
        return expiration_date;
    }
};

class CheckingAccount {
 private:
    CheckingAccountNumber number;
    Agency agency;
    Bank bank;

 public:
    void SetNumber(const CheckingAccountNumber &number){
        this->number = number;
    }

    CheckingAccountNumber GetNumber() const {
        return number;
    }

    void SetAgency(const Agency &agency){
        this->agency = agency;
    }

    Agency GetAgency() const {
        return agency;
    }

    void SetBank(const Bank &bank){
        this->bank = bank;
    }

    Bank GetBank() const {
        return bank;
    }
};

#endif  // ENTITY_H_INCLUDED
