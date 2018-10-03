/** @file domain.h
 *  @brief Defines the basic types to be used by other modules.
 *
 *  This file defines all the domains explained in the requirements, these being the basic types of data to be used by the other modules.
 */
#ifndef DOMAIN_H_INCLUDED
#define DOMAIN_H_INCLUDED

#include <stdexcept>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

/**
 *  @brief This class defines the domain agency, which has its format restricted according to the requirements.
 */
class Agency {
 private:
    /** Attribute that holds the value from the agency. */
    string code;

    /** @brief Validates the data to be inserted into the class.
     *  @param  string Agency code to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string Agency code to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the agency code from the class attribute.
     *  @return String Agency code stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

/**
 *  @brief This class defines the domain bank, which has its format restricted according to the requirements.
 */
class Bank {
 private:
    /** Attribute that holds the value from the bank.*/
    string code;

    /** @brief Validates the data to be inserted into the class.
     *  @param  string Bank code to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string Bank code to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the bank code from the class attribute.
     *  @return string Bank code stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

/**
 *  @brief This class defines the domain Accommodation capacity, which has its format restricted according to the requirements.
 */
class AccommodationCapacity {
 private:
    /** Attribute that holds the capacity from the accommodation.*/
    int amount;

    /** @brief Validates the data to be inserted into the class.
     *  @param  int Capacity to be inserted into the amount attribute.
     *  @throws invalid_argument.
     */
    void Validate(int) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  int Capacity to be inserted into the amount attribute.
     *  @throws invalid_argument.
     */
    void SetAmount(int) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return int Capacity from the accommodation stored in the class.
     */
    int GetAmount() const {
        return amount;
    }
};

/**
 *  @brief This class defines the domain Daily Fee, which has its format restricted according to the requirements.
 */
class DailyFee {
 private:
    /** Attribute that holds the capacity from the accommodation.*/
    int value;

    /** @brief Validates the data to be inserted into the class.
     *  @param  int Value of the fee to be inserted into the value attribute.
     *  @throws invalid_argument.
     */
    void Validate(int) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  int Value of the fee to be inserted into the value attribute.
     *  @throws invalid_argument.
     */
    void SetValue(int) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return int Value of the fee stored in the class.
     */
    int GetValue() const {
        return value;
    }
};

/**
 *  @brief This class defines the domain Date, which has its format restricted according to the requirements.
 */
class Date {
 private:
    /** Attribute that holds the date.*/
    string value;
    /** Attribute that holds all the valid months according to the requirements.*/
    vector<string> valid_months = {"jan", "fev", "mar", "abr", "mai", "jun",
    "jul", "ago", "set", "out", "nov", "dez"};

    /** @brief Validates the data to be inserted into the class.
     *  @param  string Date to be inserted into the value attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  int Date to be inserted into the value attribute.
     *  @throws invalid_argument.
     */
    void SetValue(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return int Date stored in the class.
     */
    string GetValue() const {
        return value;
    }
};

/**
 *  @brief This class defines the domain Expiration Date, which has its format restricted according to the requirements.
 */
class ExpirationDate {
 private:
    /** Attribute that holds the expiration date.*/
    string value;

    /** @brief Validates the data to be inserted into the class.
     *  @param  string Expiration Date to be inserted into the value attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  int Expiration Date to be inserted into the value attribute.
     *  @throws invalid_argument.
     */
    void SetValue(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return int Expiration date stored in the class.
     */
    string GetValue() const {
        return value;
    }
};

/**
 *  @brief This class defines the domain State, which has its format restricted according to the requirements.
 */
class State {
 private:
    /** Attribute that holds the state code.*/
    string code;
    /** Attribute that holds all the valid state codes according to the requirements.*/
    vector<string> valid_states = {"AC", "AL", "AP", "AM", "BA", "CE", "DF",
    "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ",
    "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};

    /** @brief Validates the data to be inserted into the class.
     *  @param  string State code to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string State code to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return string State code stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

/**
 *  @brief This class defines the domain Identifier, which has its format restricted according to the requirements.
 */
class Identifier {
 private:
    /** Attribute that holds the Identifier code.*/
    string code;
    /** @brief Validates the data to be inserted into the class.
     *  @param  string Identifier code to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string Identifier code to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return string Identifier code stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

/**
 *  @brief This class defines the domain Name, which has its format restricted according to the requirements.
 */
class Name {
 private:
    /** Attribute that holds the Name.*/
    string code;

    /** @brief Validates the data to be inserted into the class.
     *  @param  string Name to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string Name to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return string Name stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

/**
 *  @brief This class defines the domain Credit Card Number, which has its format restricted according to the requirements.
 */
class CreditCardNumber {
 private:
    /** Attribute that holds the credit card code.*/
    string code;

    /** @brief Used to validate and verify if the credit card number is valid according to Luhn algorithm.
     *  @param  string Credit card number.
     *  @return bool Returns true if the credit card is valid according to Luhn.
     */
    bool CheckLuhn(string);
    /** @brief Validates the data to be inserted into the class.
     *  @param  string Credit card number to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string Credit card number to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return string Credit card number stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

/**
 *  @brief This class defines the domain Checking account number, which has its format restricted according to the requirements.
 */
class CheckingAccountNumber {
 private:
    /** Attribute that holds account number.*/
    string code;
    /** @brief Validates the data to be inserted into the class.
     *  @param  string Account number to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string Account number to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return string Checking account number stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

/**
 *  @brief This class defines the domain Password, which has its format restricted according to the requirements.
 */
class Password {
 private:
    /** Attribute that holds the password.*/
    string code;

    /** @brief Validates the data to be inserted into the class.
     *  @param  string Password to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string Password to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return string Password stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

/**
 *  @brief This class defines the domain Accommodation Type, which has its format restricted according to the requirements.
 */
class AccommodationType {
 private:
    /** Attribute that holds the type.*/
    string code;
    /** Attribute that holds all the valid accommodation types according to the requirements.*/
    vector<string> valid_accomodations = {"Apartamento", "Casa", "Flat"};

    /** @brief Validates the data to be inserted into the class.
     *  @param  string Type to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void Validate(string) throw(invalid_argument);

 public:
    /** @brief Calls validate, and copies the data to the class attribute.
     *  @param  string Type to be inserted into the code attribute.
     *  @throws invalid_argument.
     */
    void SetCode(string) throw(invalid_argument);

    /** @brief Returns the data from the class attribute.
     *  @return string Accommodation Type stored in the class.
     */
    string GetCode() const {
        return code;
    }
};

#endif  // DOMAIN_H_INCLUDED
