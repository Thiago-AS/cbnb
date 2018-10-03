#include "domain.h"

/**
 *  Validates the agency code, where it must be 5 digits long, and must contain only numeric values.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void Agency::Validate(string code) throw(invalid_argument) {
    if (code.size() != 5)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < code.size(); i++) {
        if (!isdigit(code.at(i)))
            throw invalid_argument("Invalid argument.");
    }
}

void Agency::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

/**
 *  Validates the bank code, where it must be 3 digits long, and must contain only numeric values.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void Bank::Validate(string code) throw(invalid_argument) {
    if (code.size() != 3)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < code.size(); i++) {
        if (!isdigit(code.at(i)))
            throw invalid_argument("Invalid argument.");
    }
}

void Bank::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

/**
 *  Validates the accommodation capacity, where it must be a number between 1 and 9.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void AccommodationCapacity::Validate(int amount) throw(invalid_argument) {
    if ((amount < 1) || (amount > 9))
        throw invalid_argument("Invalid argument.");
}

void AccommodationCapacity::SetAmount(int amount) throw(invalid_argument) {
    Validate(amount);
    this->amount = amount;
}

/**
 *  Validates the daily fee value, where it must be a number between 1 and 10000.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void DailyFee::Validate(int value) throw(invalid_argument) {
    if ((value < 1) || (value > 10000))
        throw invalid_argument("Invalid argument.");
}

void DailyFee::SetValue(int value) throw(invalid_argument) {
    Validate(value);
    this->value = value;
}

/**
 *  Validates the date, where it must be in the usual format (DD/MMM/AAAA),
 *  where DD, represents the day and must be in range of 1 and 31, MMM
 *  represents the month, and it must be in the valid_months vector defined
 *  and the AAAA represents the year, being a number between 2000 and 2099.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void Date::Validate(string value) throw(invalid_argument) {
    int slash_counter = 0, int_day, int_year;
    bool valid_month = false, is_leap_year = false;
    string sub_string, day, month, year;
    vector <string> tokens;
    std::istringstream iss(value);

    if (value.size() != 11)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < value.size(); i++) {
        if (value.at(i) == '/')
            slash_counter++;
    }

    if (slash_counter != 2)
        throw invalid_argument("Invalid argument.");

    while (getline(iss, sub_string, '/')) {
        tokens.push_back(sub_string);
    }

    day = tokens.at(0);
    month = tokens.at(1);
    year = tokens.at(2);

    if (day.size() != 2 || month.size() != 3 ||year.size() != 4)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < day.size(); i++) {
        if (!isdigit(day.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    for (unsigned int i = 0; i < month.size(); i++) {
        if (isdigit(month.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    for (unsigned int i = 0; i < year.size(); i++) {
        if (!isdigit(year.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    for (unsigned int i = 0; i < valid_months.size(); i++) {
        if (month == valid_months.at(i))
            valid_month = true;
    }

    if (!valid_month)
        throw invalid_argument("Invalid argument.");

    int_day = stoi(day, nullptr);
    int_year = stoi(year, nullptr);

    if (int_year < 2000 || int_year > 2099)
        throw invalid_argument("Invalid argument.");

    if (int_day < 1 || int_day > 31)
        throw invalid_argument("Invalid argument.");

    if ((month == "abr" || month == "jun" || month == "set" || month == "nov") && int_day > 30)
        throw invalid_argument("Invalid argument.");

    if (((int_year % 4 == 0) && (int_year % 100 != 0)) || (int_year % 400 == 0))
        is_leap_year = true;

    if ((month == "fev") && (!is_leap_year) && (int_day > 28))
        throw invalid_argument("Invalid argument.");

    if ((month == "fev") && (is_leap_year) && (int_day > 29)){
        throw invalid_argument("Invalid argument.");
    }

}

void Date::SetValue(string value) throw(invalid_argument) {
    Validate(value);
    this->value = value;
}

/**
 *  Validates the expiration date, where it must be in the format MM/AA. Where
 *  MM is the month, and must be between 01 and 12, and AA is the year, and must
 *  be between 00 and 99.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void ExpirationDate::Validate(string value) throw(invalid_argument) {
    int slash_counter = 0, int_month, int_year;
    string sub_string, month, year;
    vector <string> tokens;
    std::istringstream iss(value);

    if (value.size() != 5)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < value.size(); i++) {
        if (value.at(i) == '/')
            slash_counter++;
    }

    if (slash_counter != 1)
        throw invalid_argument("Invalid argument.");

    while (getline(iss, sub_string, '/')) {
        tokens.push_back(sub_string);
    }

    month = tokens.at(0);
    year = tokens.at(1);

    if (month.size() != 2 || year.size() != 2)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < month.size(); i++) {
        if (!isdigit(month.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    for (unsigned int i = 0; i < year.size(); i++) {
        if (!isdigit(year.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    int_month = stoi(month, nullptr);
    int_year = stoi(year, nullptr);

    if (int_month < 1 || int_month > 12)
        throw invalid_argument("Invalid argument.");

    if (int_year < 0 || int_year > 99)
        throw invalid_argument("Invalid argument.");
}

void ExpirationDate::SetValue(string value) throw(invalid_argument) {
    Validate(value);
    this->value = value;
}

/**
 *  Validates the state code, where it must be a code with 2 characters and must
 *  be in the valid_states vector defined.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void State::Validate(string code) throw(invalid_argument) {
    bool valid_state = false;
    if (code.size() != 2)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < valid_states.size(); i++) {
        if (code == valid_states.at(i))
            valid_state = true;
    }

    if (!valid_state)
        throw invalid_argument("Invalid argument.");
}

void State::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

/**
 *  Validates the Identifier code, where it must be a code with 5 characters,
 *  all being alpha and lower case.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void Identifier::Validate(string code) throw(invalid_argument) {
    if (code.size() != 5)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < code.size(); i++) {
        if (!islower(code.at(i)) || !isalpha(code.at(i)))
            throw invalid_argument("Invalid argument.");
    }
}

void Identifier::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

/**
 *  Validates the Name, where it must be a code with max 15 characters,
 *  all being alpha or space and dot. Cant have two spaces in a row and all
 *  dots must be preceded by a letter.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void Name::Validate(string code) throw(invalid_argument) {
    bool char_is_letter = false;
    if (code.size() > 15)
      throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < code.size(); i++){
        if (!isalpha(code.at(i)) && code.at(i) != ' ' && code.at(i) != '.')
          throw invalid_argument("Invalid argument.");

        if (isalpha(code.at(i)))
            char_is_letter = true;
    }

    if(!char_is_letter)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 1; i < code.size(); i++) {
        if (code.at(i-1) == ' ' && code.at(i) == ' ')
            throw invalid_argument("Invalid argument.");

        if (!isalpha(code.at(i-1)) && code.at(i) == '.' )
            throw invalid_argument("Invalid argument.");
    }
}

void Name::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

bool CreditCardNumber::CheckLuhn(string card_number) {
    int num_digits = card_number.length();

    int num_sum = 0, is_second = false;
    for (int i = num_digits - 1; i >= 0; i--) {
        int d = card_number[i] - 'a';

        if (is_second == true)
            d = d * 2;

        num_sum += d / 10;
        num_sum += d % 10;

        is_second = !is_second;
    }
    return (num_sum % 10 == 0);
}

/**
 *  Validates the Credit Card Number, where it must be a code with 16 digits,
 *  all being numeric. The number must pass the Luhn algorithm.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void CreditCardNumber::Validate(string code) throw(invalid_argument) {
    if (code.size() != 16)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < code.size(); i++) {
        if (!isdigit(code.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    if (!CheckLuhn(code))
        throw invalid_argument("Invalid argument.");
}

void CreditCardNumber::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

/**
 *  Validates the Checking Account Number, where it must be a code with 6 digits,
 *  all being numeric.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void CheckingAccountNumber::Validate(string code) throw(invalid_argument) {
    if (code.size() != 6)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < code.size(); i++) {
        if (!isdigit(code.at(i)))
            throw invalid_argument("Invalid argument.");
    }
}

void CheckingAccountNumber::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

/**
 *  Validates the Password, where it must be a code with max 8 characters,
 *  where the character can be a symbol (! # $% &), A letter (A - Z to - z) or
 *  a digit (0 to 9). There is at least 1 uppercase, 1 lowercase, 1 digit,
 *  and 1 symbol.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void Password::Validate(string code) throw(invalid_argument) {
    bool char_is_upper = false, char_is_lower = false, char_is_digit = false, char_is_symbol = false;
    int char_count[256] = {0};

    if (code.size() > 8 || code.size() < 4)
        throw invalid_argument("Invalid argument.");

    for (unsigned int i = 0; i < code.size(); i++) {
        if (!isdigit(code.at(i)) && !isalpha(code.at(i)) && code.at(i) != '!'
            && code.at(i) != '#' && code.at(i) != '$' && code.at(i) != '%'
            && code.at(i) != '&')
            throw invalid_argument("Invalid argument.");

        if (isupper(code.at(i)))
            char_is_upper = true;
        if (islower(code.at(i)))
            char_is_lower = true;
        if (isdigit(code.at(i)))
            char_is_digit = true;
        if (code.at(i) == '!' || code.at(i) == '#' || code.at(i) == '$' || code.at(i) == '%' || code.at(i) == '&')
            char_is_symbol = true;

        char_count[int(code.at(i))]++;
    }

    if (!(char_is_upper & char_is_lower & char_is_symbol & char_is_digit))
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < 256; i++) {
        if (char_count[i] > 1)
            throw invalid_argument("Invalid argument.");
    }
}

void Password::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

/**
 *  Validates the Accommodation Type, the type must be in the valid_types vector
 *  defined.
 *  If the parameter does not pass validation, throws invalid argument exception.
 */
void AccommodationType::Validate(string code) throw(invalid_argument) {
    bool valid_accomodation = false;
    for (unsigned int i = 0; i < valid_accomodations.size(); i++) {
    if (code == valid_accomodations.at(i))
      valid_accomodation = true;
    }

    if (!valid_accomodation)
    throw invalid_argument("Invalid argument.");
}

void AccommodationType::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}
