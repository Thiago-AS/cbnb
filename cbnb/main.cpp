#include <iostream>
#include "domain.h"
#include "tests_domain.h"

int main() {
    UtAgency test_agency;
    UtBank test_bank;
    UtAccommodationCapacity test_accommodation_capacity;
    UtDailyFee test_daily_fee;
    UtDate test_date;
    UtExpirationDate test_expiration_date;
    UtState test_state;
    UtIdentifier test_identifier;
    UtName test_name;
    UtCreditCardNumber test_credit_card;
    UtCheckingAccount test_checking_account;
    UtPassword test_password;
    UtAccommodationType test_accommodation_type;

    test_agency.Run();
    test_bank.Run();
    test_accommodation_capacity.Run();
    test_daily_fee.Run();
    test_date.Run();
    test_expiration_date.Run();
    test_state.Run();
    test_identifier.Run();
    test_name.Run();
    test_credit_card.Run();
    test_checking_account.Run();
    test_password.Run();
    test_accommodation_type.Run();

    return 0;
}
