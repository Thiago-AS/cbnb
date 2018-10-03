/** @file tests_domain.h
 *  @brief Defines the tests of the domain classes implemented.
 *
 *  This file defines all the tests to run on every single one of the domain classes.
 */
#ifndef TESTES_DOMAIN_H_INCLUDED
#define TESTES_DOMAIN_H_INCLUDED

#include "domain.h"

/**
 *  @brief This class defines the unit test of the agency class.
 */
class UtAgency {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "12345";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"123av", "123", "134567"};
    /** Class to be tested. */
    Agency *agency;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the bank class.
 */
class UtBank {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "123";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"12a", "12", "1347"};
    /** Class to be tested. */
    Bank *bank;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Accommodation Capacity class.
 */
class UtAccommodationCapacity {
 private:
    /** Valid data to be inserted in the class. */
    const int valid_value   = 2;
    /** Set of invalid data to cover all the failure cases. */
    const vector<int> invalid_values = {-2, 12};
    /** Class to be tested. */
    AccommodationCapacity *accommodation_capacity;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Daily Fee class.
 */
class UtDailyFee {
 private:
    /** Valid data to be inserted in the class. */
    const int valid_value   = 3000;
    /** Set of invalid data to cover all the failure cases. */
    const vector<int> invalid_values = {-2, 12000};
    /** Class to be tested. */
    DailyFee *daily_fee;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Date class.
 */
class UtDate {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "22/fev/2018";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"31/nov/2018", "22/fev/3012", "22/02/2012", "22/2/2012", "2202//3012"};
    /** Class to be tested. */
    Date *date;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the ExpirationDate class.
 */
class UtExpirationDate {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "02/18";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"00/18", "02/100", "02/1/", "02/1a", "15/18"};
    /** Class to be tested. */
    ExpirationDate *expiration_date;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the State class.
 */
class UtState {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "DF";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"DFF", "df", "d", "12"};
    /** Class to be tested. */
    State *state;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Identifier class.
 */
class UtIdentifier {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "nobre";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"Nobre", "nobr", "nobree", "nob2e"};
    /** Class to be tested. */
    Identifier *identifier;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Name class.
 */
class UtName {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "Thiago A. Silva";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"Thiago12", "Thiago . Silva", "Thiago  Silva", ". ", "asdfg casder a. as"};
    /** Class to be tested. */
    Name *name;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Credit Card Number class.
 */
class UtCreditCardNumber {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "7992739871330021";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"79927398713", "79927398713234512", "7992739871a23451", "7992739871330020"};
    /** Class to be tested. */
    CreditCardNumber *credit_card_number;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Checking Account class.
 */
class UtCheckingAccount {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "123456";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"1234", "1234567", "123a56"};
    /** Class to be tested. */
    CheckingAccountNumber *checking_account;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Password class.
 */
class UtPassword {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "Th1ago%";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"thiago", "Th1ago%23", "Th1ago%g", "Th1ago%@"};
    /** Class to be tested. */
    Password *password;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the unit test of the Accommodation Type class.
 */
class UtAccommodationType {
 private:
    /** Valid data to be inserted in the class. */
    const string valid_value   = "Apartamento";
    /** Set of invalid data to cover all the failure cases. */
    const vector<string> invalid_values = {"1234", "flat"};
    /** Class to be tested. */
    AccommodationType *accommodation_type;

    /** @brief Set the test up, creating all the dependencies.*/
    void SetUp();
    /** @brief Destroy the dependencies so the test could be running.*/
    void TearDown();
    /** @brief Test the valid data in the class.*/
    void TestSuccessCase();
    /** @brief Test the invalid data in the class.*/
    void TestFailureCase();

 public:
    void Run();
};

/**
 *  @brief This class defines the module that call all the tests.
 */
class TestMainFrame {
 private:
    UtAgency *test_agency;
    UtBank *test_bank;
    UtAccommodationCapacity *test_accommodation_capacity;
    UtDailyFee *test_daily_fee;
    UtDate *test_date;
    UtExpirationDate *test_expiration_date;
    UtState *test_state;
    UtIdentifier *test_identifier;
    UtName *test_name;
    UtCreditCardNumber *test_credit_card;
    UtCheckingAccount *test_checking_account;
    UtPassword *test_password;
    UtAccommodationType *test_accommodation_type;

 public:
    void RunTests();
};
#endif // TESTES_DOMAIN_H_INCLUDED
