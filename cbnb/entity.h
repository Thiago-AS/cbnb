/** @file tests_domain.h
 *  @brief Defines the all the entities to be used.
 *
 *  This file defines all the the entities proposed in the requirements, where its just consists of an amount of domains together.
 */
#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "domain.h"

class User {
 private:
    /** User name. */
    Name name;
    /** User identification. */
    Identifier identifier;
    /** User password. */
    Password password;

 public:
    User(){}
    User(Name name, Identifier identifier, Password password):name(name), identifier(identifier), password(password){};
    /** @brief Set the domain name to the class user.
     *  @param  name Class name.
     */
    void SetName(const Name &name){
        this->name = name;
    }
    /** @brief Returns the domain name from the class so it can be changed.
     *  @return  Name Returns the domain name from the class.
     */
    Name GetName() const {
        return name;
    }
    /** @brief Set the domain identifier to the class user.
     *  @param  identifier Class identifier.
     */
    void SetIdentifier(const Identifier &identifier){
        this->identifier = identifier;
    }
    /** @brief Returns the domain Identifier from the class so it can be changed.
     *  @return  Identifier Returns the domain Identifier from the class.
     */
    Identifier GetIdentifier() const {
        return identifier;
    }
    /** @brief Set the domain password to the class user.
     *  @param  password Class password.
     */
    void SetPassword(const Password &password){
        this->password = password;
    }
    /** @brief Returns the domain Password from the class so it can be changed.
     *  @return  Password Returns the domain Password from the class.
     */
    Password GetPassword() const {
        return password;
    }
};

class Accommodation {
 private:
    /** Accommodation identification. */
    Identifier identifier;
    /** Accommodation type. */
    AccommodationType type;
    /** Accommodation capacity. */
    AccommodationCapacity capacity;
    /** Initial date to use the accommodation. */
    Date initial_date;
    /** End date to use the accommodation. */
    Date end_date;
    /** City where its located. */
    Name city;
    /** State where its located. */
    State state;
    /** The daily rent fee. */
    DailyFee daily_fee;

 public:
    Accommodation(){}
    Accommodation(Identifier identifier, AccommodationType type, AccommodationCapacity capacity, Date initial_date, Date end_date, Name city, State state, DailyFee daily_fee);
    /** @brief Set the domain identifier to the class user.
     *  @param  identifier Class identifier.
     */
    void SetIdentifier(const Identifier &identifier) {
        this->identifier = identifier;
    }
    /** @brief Returns the domain Identifier from the class so it can be changed.
     *  @return  Identifier Returns the domain Identifier from the class.
     */
    Identifier GetIdentifier() const {
        return identifier;
    }
    /** @brief Set the domain AccommodationType to the class user.
     *  @param  type Class AccommodationType.
     */
    void SetType(const AccommodationType &type) {
        this->type = type;
    }
    /** @brief Returns the domain AccommodationType from the class so it can be changed.
     *  @return  AccommodationType Returns the domain AccommodationType from the class.
     */
    AccommodationType GetType() const {
        return type;
    }
    /** @brief Set the domain AccommodationCapacity to the class user.
     *  @param  capacity Class AccommodationCapacity.
     */
    void SetCapacity(const AccommodationCapacity &capacity) {
        this->capacity = capacity;
    }
    /** @brief Returns the domain AccommodationCapacity from the class so it can be changed.
     *  @return  AccommodationCapacity Returns the domain AccommodationCapacity from the class.
     */
    AccommodationCapacity GetCapacity() const {
        return capacity;
    }
    /** @brief Set the domain Date to the class user.
     *  @param  initial_date Class Date.
     */
    void SetInitialDate(const Date &initial_date) {
        this->initial_date = initial_date;
    }
    /** @brief Returns the domain Date from the class so it can be changed.
     *  @return  Date Returns the domain Date from the class.
     */
    Date GetInitialDate() const {
        return initial_date;
    }
    /** @brief Set the domain Date to the class user.
     *  @param  end_date Class Date.
     */
    void SetEndDate(const Date &end_date) {
        this->end_date = end_date;
    }
    /** @brief Returns the domain Date from the class so it can be changed.
     *  @return  Date Returns the domain Date from the class.
     */
    Date GetEndDate() const {
        return end_date;
    }
    /** @brief Set the domain Name to the class user.
     *  @param  city Class Name.
     */
    void SetCity(const Name &city) {
        this->city = city;
    }
    /** @brief Returns the domain Name from the class so it can be changed.
     *  @return  Name Returns the domain Name from the class.
     */
    Name GetCity() const {
        return city;
    }
    /** @brief Set the domain State to the class user.
     *  @param  state Class State.
     */
    void SetState(const State &state) {
        this->state = state;
    }
    /** @brief Returns the domain State from the class so it can be changed.
     *  @return  State Returns the domain State from the class.
     */
    State GetState() const {
        return state;
    }
    /** @brief Set the domain DailyFee to the class user.
     *  @param  daily_fee Class DailyFee.
     */
    void SetDailyFee(const DailyFee &daily_fee) {
        this->daily_fee = daily_fee;
    }
    /** @brief Returns the domain DailyFee from the class so it can be changed.
     *  @return  DailyFee Returns the domain DailyFee from the class.
     */
    DailyFee GetDailyFee() const {
        return daily_fee;
    }
};

class CreditCard {
 private:
    /** Credit card number. */
    CreditCardNumber number;
    /** Credit card expiration date. */
    ExpirationDate expiration_date;

 public:
    CreditCard(){}
    CreditCard(CreditCardNumber number, ExpirationDate expiration_date):
    number(number), expiration_date(expiration_date){};
    /** @brief Set the domain CreditCardNumber to the class user.
     *  @param  number Class CreditCardNumber.
     */
    void SetNumber(const CreditCardNumber &number){
        this->number = number;
    }
    /** @brief Returns the domain CreditCardNumber from the class so it can be changed.
     *  @return  CreditCardNumber Returns the domain CreditCardNumber from the class.
     */
    CreditCardNumber GetNumber() const {
        return number;
    }
    /** @brief Set the domain ExpirationDate to the class user.
     *  @param  expiration_date Class ExpirationDate.
     */
    void SetExpirationDate(const ExpirationDate &expiration_date){
        this->expiration_date = expiration_date;
    }
    /** @brief Returns the domain ExpirationDate from the class so it can be changed.
     *  @return  ExpirationDate Returns the domain ExpirationDate from the class.
     */
    ExpirationDate GetExpirationDate() const {
        return expiration_date;
    }
};

class CheckingAccount {
 private:
    /** Checking account number. */
    CheckingAccountNumber number;
    /** Checking account agency. */
    Agency agency;
    /** Checking account bank. */
    Bank bank;

 public:
    /** @brief Set the domain CheckingAccountNumber to the class user.
     *  @param  number Class CheckingAccountNumber.
     */
    void SetNumber(const CheckingAccountNumber &number){
        this->number = number;
    }
    /** @brief Returns the domain CheckingAccountNumber from the class so it can be changed.
     *  @return  CheckingAccountNumber Returns the domain CheckingAccountNumber from the class.
     */
    CheckingAccountNumber GetNumber() const {
        return number;
    }
    /** @brief Set the domain Agency to the class user.
     *  @param  agency Class Agency.
     */
    void SetAgency(const Agency &agency){
        this->agency = agency;
    }
    /** @brief Returns the domain Agency from the class so it can be changed.
     *  @return  Agency Returns the domain Agency from the class.
     */
    Agency GetAgency() const {
        return agency;
    }
    /** @brief Set the domain Bank to the class user.
     *  @param  bank Class Bank.
     */
    void SetBank(const Bank &bank){
        this->bank = bank;
    }
    /** @brief Returns the domain Bank from the class so it can be changed.
     *  @return  Bank Returns the domain Bank from the class.
     */
    Bank GetBank() const {
        return bank;
    }
};
#endif  // ENTITY_H_INCLUDED
