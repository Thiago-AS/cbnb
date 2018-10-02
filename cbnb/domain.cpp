/* Copyright 2018: Thiago Araujo da Siva 15/0149832*/
#include "domain.h"

void Agency::Validate(string code) throw(invalid_argument) {
    if (code.size() != 5)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < code.size(); i++) {
        if (!isdigit(code.at(i)))
            throw invalid_argument("Invalid argument.");
    }
}

void Agency::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

void Bank::Validate(string code) throw(invalid_argument) {
    if (code.size() != 3)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < code.size(); i++) {
        if (!isdigit(code.at(i)))
            throw invalid_argument("Invalid argument.");
    }
}

void Bank::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

void AccommodationCapacity::Validate(int amount) throw(invalid_argument) {
    if ((amount < 1) || (amount > 9))
        throw invalid_argument("Invalid argument.");
}

void AccommodationCapacity::SetAmount(int amount) throw(invalid_argument) {
    Validate(amount);
    this->amount = amount;
}

void DailyFee::Validate(int value) throw(invalid_argument) {
    if ((value < 1) || (value > 10000))
        throw invalid_argument("Invalid argument.");
}

void DailyFee::SetValue(int value) throw(invalid_argument) {
    Validate(value);
    this->value = value;
}

void Date::Validate(string value) throw(invalid_argument) {
    int slash_counter = 0, int_day, int_year;
    bool valid_month = false;
    string sub_string, day, month, year;
    vector <string> tokens;
    std::istringstream iss(value);

    if (value.size() != 11)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < value.size(); i++) {
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

    if (day.size() != 2 || month.size() != 3 ||year.size() != 3)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < day.size(); i++) {
        if (!isdigit(day.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    for (int i = 0; i < month.size(); i++) {
        if (isdigit(month.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    for (int i = 0; i < year.size(); i++) {
        if (!isdigit(year.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    for (int i = 0; i < valid_months.size(); i++) {
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

    // TODO(myself) VERIFY DAY BASED ON MONTH
}

void Date::SetValue(string value) throw(invalid_argument) {
    Validate(value);
    this->value = value;
}

void ExpirationDate::Validate(string value) throw(invalid_argument) {
    int slash_counter = 0, int_month, int_year;
    string sub_string, month, year;
    vector <string> tokens;
    std::istringstream iss(value);

    if (value.size() != 5)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < value.size(); i++) {
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

    for (int i = 0; i < month.size(); i++) {
        if (!isdigit(month.at(i)))
            throw invalid_argument("Invalid argument.");
    }

    for (int i = 0; i < year.size(); i++) {
        if (isdigit(year.at(i)))
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

void State::Validate(string code) throw(invalid_argument) {
    bool valid_state = false;
    if (code.size() != 2)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < valid_states.size(); i++) {
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

void Identifier::Validate(string code) throw(invalid_argument) {
    bool invalid_indentifier = false;
    if (code.size() != 5)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < code.size(); i++) {
        if (!islower(code.at(i)))
            invalid_indentifier = true;
    }

    for (int i = 0; i < code.size(); i++) {
        if (!isalpha(code.at(i)))
            invalid_indentifier = true;
    }

    if (invalid_indentifier)
        throw invalid_argument("Invalid argument.");
}

void Identifier::SetCode(string code) throw(invalid_argument) {
    Validate(code);
    this->code = code;
}

// TODO(myself) NOME - CHECK IF RIGHT
void Name::Validate(string code) throw(invalid_argument) {
  if (code.size() > 15)
      throw invalid_argument("Invalid argument.");

  for (int i = 1; i <= code.size(); i++) {
      if (!isalpha(code.at(i-1)) && code.at(i-1) != ' ' && code.at(i-1) != '.')
          throw invalid_argument("Invalid argument.");

      if (code.at(i) == ' ' && code.at(i-1) == ' ')
          throw invalid_argument("Invalid argument.");

      if (code.at(i) == '.' && !isalpha(code.at(i-1)))
          throw invalid_argument("Invalid argument.");
  }
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

void CreditCardNumber::Validate(string code) throw(invalid_argument) {
    if (code.size() != 16)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < code.size(); i++) {
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

void CheckingAccount::Validate(string code) throw(invalid_argument) {
    if (code.size() != 6)
        throw invalid_argument("Invalid argument.");

    for (int i = 0; i < code.size(); i++) {
        if (!isdigit(code.at(i)))
            throw invalid_argument("Invalid argument.");
    }
}

void CheckingAccount::SetCode(string code) throw(invalid_argument) {
  Validate(code);
  this->code = code;
}

// TODO(myself) Password
void Password::Validate(string code) throw(invalid_argument) {
  if (code.size() > 6 || code.size() < 4)
      throw invalid_argument("Invalid argument.");

  for (int i = 0; i < code.size(); i++) {
      if (!isdigit(code.at(i)) || !isalpha(code.at(i)) || code.at(i) != '!'
          || code.at(i) != '#' || code.at(i) != '$' || code.at(i) != '%'
          || code.at(i) != '&')
          throw invalid_argument("Invalid argument.");
  }

}

void Password::SetCode(string) throw(invalid_argument) {
  Validate(code);
  this->code = code;
}


void AccommodationType::Validate(string code) throw(invalid_argument) {
  bool valid_accomodation = false;
  for (int i = 0; i < valid_accomodations.size(); i++) {
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
