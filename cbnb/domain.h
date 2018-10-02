/* Copyright 2018: Thiago Araujo da Siva 15/0149832*/
#ifndef DOMAIN_H_INCLUDED
#define DOMAIN_H_INCLUDED

#include <stdexcept>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

class Agency{
 private:
    string code;

    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

class Bank{
 private:
    string code;

    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

class AccommodationCapacity{
 private:
    int amount;

    void Validate(int) throw(invalid_argument);

 public:
    void SetAmount(int) throw(invalid_argument);

    int GetAmount() const {
        return amount;
    }
};


class DailyFee{
 private:
    int value;

    void Validate(int) throw(invalid_argument);

 public:
    void SetValue(int) throw(invalid_argument);

    int GetValue() const {
        return value;
    }
};

class Date{
 private:
    string value;
    vector<string> valid_months = {"jan", "fev", "mar", "abr", "mai", "jun",
    "jul", "ago", "set", "out", "nov", "dez"};

    void Validate(string) throw(invalid_argument);

 public:
    void SetValue(string) throw(invalid_argument);

    string GetValue() const {
        return value;
    }
};

class ExpirationDate{
 private:
    string value;

    void Validate(string) throw(invalid_argument);

 public:
    void SetValue(string) throw(invalid_argument);

    string GetValue() const {
        return value;
    }
};

class State{
 private:
    string code;
    vector<string> valid_states = {"AC", "AL", "AP", "AM", "BA", "CE", "DF",
    "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ",
    "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

class Identifier{
 private:
    string code;

    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

class Name{
 private:
    string code;

    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

class CreditCardNumber{
 private:
    string code;

    bool CheckLuhn(string);
    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

class CheckingAccount{
 private:
    string code;

    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

class Password{
 private:
    string code;

    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

class AccommodationType{
 private:
    string code;
    vector<string> valid_accomodations = {"Apartamento", "Casa", "Flat"};

    void Validate(string) throw(invalid_argument);

 public:
    void SetCode(string) throw(invalid_argument);

    string GetCode() const {
        return code;
    }
};

#endif  // DOMAIN_H_INCLUDED
