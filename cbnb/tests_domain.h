#ifndef TESTES_DOMAIN_H_INCLUDED
#define TESTES_DOMAIN_H_INCLUDED

#include "domain.h"

class UtAgency {
 private:
    const string valid_value   = "12345";
    const vector<string> invalid_values = {"123av", "123", "134567"};

    Agency *agency;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtBank {
 private:
    const string valid_value   = "123";
    const vector<string> invalid_values = {"12a", "12", "1347"};

    Bank *bank;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtAccommodationCapacity {
 private:
    const int valid_value   = 2;
    const vector<int> invalid_values = {-2, 12};

    AccommodationCapacity *accommodation_capacity;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtDailyFee {
 private:
    const int valid_value   = 3000;
    const vector<int> invalid_values = {-2, 12000};

    DailyFee *daily_fee;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtDate {
 private:
    const string valid_value   = "22/fev/2018";
    const vector<string> invalid_values = {"31/nov/2018", "22/fev/3012", "22/02/2012", "22/2/2012", "2202//3012"};

    Date *date;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtExpirationDate {
 private:
    const string valid_value   = "02/18";
    const vector<string> invalid_values = {"00/18", "02/100", "02/1/", "02/1a", "15/18"};

    ExpirationDate *expiration_date;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtState {
 private:
    const string valid_value   = "DF";
    const vector<string> invalid_values = {"DFF", "df", "d", "12"};

    State *state;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtIdentifier {
 private:
    const string valid_value   = "nobre";
    const vector<string> invalid_values = {"Nobre", "nobr", "nobree", "nob2e"};

    Identifier *identifier;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtName {
 private:
    const string valid_value   = "Thiago A. Silva";
    const vector<string> invalid_values = {"Thiago12", "Thiago . Silva", "Thiago  Silva", ". ", "asdfg casder a. as"};

    Name *name;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtCreditCardNumber {
 private:
    const string valid_value   = "7992739871330021";
    const vector<string> invalid_values = {"79927398713", "79927398713234512", "7992739871a23451", "7992739871330020"};

    CreditCardNumber *credit_card_number;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtCheckingAccount {
 private:
    const string valid_value   = "123456";
    const vector<string> invalid_values = {"1234", "1234567", "123a56"};

    CheckingAccountNumber *checking_account;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtPassword {
 private:
    const string valid_value   = "Th1ago%";
    const vector<string> invalid_values = {"thiago", "Th1ago%23", "Th1ago%g", "Th1ago%@"};

    Password *password;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};

class UtAccommodationType {
 private:
    const string valid_value   = "Apartamento";
    const vector<string> invalid_values = {"1234", "flat"};

    AccommodationType *accommodation_type;

    void SetUp();
    void TearDown();
    void TestSuccessCase();
    void TestFailureCase();

 public:
    void Run();
};
#endif // TESTES_DOMAIN_H_INCLUDED
