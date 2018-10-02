#include "tests_domain.h"

void UtAgency::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting agency unit test" << endl;
    agency = nullptr;
    agency = new Agency();
    if (agency != nullptr)
        cout << "Agency unit test successfully started: Object agency created successfully" << endl;
    else
        cout << "Failed to setup agency unit test" << endl;
}

void UtAgency::TearDown() {
    delete agency;
    cout << "\nEnd of agency unit test" << endl;
}

void UtAgency::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        agency->SetCode(valid_value);
        if (agency->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtAgency::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            agency->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }

}

void UtAgency::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtBank::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting bank unit test" << endl;
    bank = nullptr;
    bank = new Bank();
    if (bank != nullptr)
        cout << "Bank unit test successfully started: Object bank created successfully" << endl;
    else
        cout << "Failed to setup bank unit test" << endl;
}

void UtBank::TearDown() {
    delete bank;
    cout << "\nEnd of bank unit test" << endl;
}

void UtBank::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        bank->SetCode(valid_value);
        if (bank->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtBank::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            bank->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtBank::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtAccommodationCapacity::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting accommodation_capacity unit test" << endl;
    accommodation_capacity = nullptr;
    accommodation_capacity = new AccommodationCapacity();
    if (accommodation_capacity != nullptr)
        cout << "AccommodationCapacity unit test successfully started: Object accommodation_capacity created successfully" << endl;
    else
        cout << "Failed to setup accommodation_capacity unit test" << endl;
}

void UtAccommodationCapacity::TearDown() {
    delete accommodation_capacity;
    cout << "\nEnd of accommodation_capacity unit test" << endl;
}

void UtAccommodationCapacity::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        accommodation_capacity->SetAmount(valid_value);
        if (accommodation_capacity->GetAmount() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtAccommodationCapacity::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            accommodation_capacity->SetAmount(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtAccommodationCapacity::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtDailyFee::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting daily_fee unit test" << endl;
    daily_fee = nullptr;
    daily_fee = new DailyFee();
    if (daily_fee != nullptr)
        cout << "DailyFee unit test successfully started: Object daily_fee created successfully" << endl;
    else
        cout << "Failed to setup daily_fee unit test" << endl;
}

void UtDailyFee::TearDown() {
    delete daily_fee;
    cout << "\nEnd of daily_fee unit test" << endl;
}

void UtDailyFee::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        daily_fee->SetValue(valid_value);
        if (daily_fee->GetValue() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtDailyFee::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            daily_fee->SetValue(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtDailyFee::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtDate::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting date unit test" << endl;
    date = nullptr;
    date = new Date();
    if (date != nullptr)
        cout << "Date unit test successfully started: Object date created successfully" << endl;
    else
        cout << "Failed to setup date unit test" << endl;
}

void UtDate::TearDown() {
    delete date;
    cout << "\nEnd of date unit test" << endl;
}

void UtDate::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        date->SetValue(valid_value);
        if (date->GetValue() != valid_value)
            cout << "ERROR:Successfully set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtDate::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            date->SetValue(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtDate::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtExpirationDate::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting expiration_date unit test" << endl;
    expiration_date = nullptr;
    expiration_date = new ExpirationDate();
    if (expiration_date != nullptr)
        cout << "ExpirationDate unit test successfully started: Object expiration_date created successfully" << endl;
    else
        cout << "Failed to setup expiration_date unit test" << endl;
}

void UtExpirationDate::TearDown() {
    delete expiration_date;
    cout << "\nEnd of expiration_date unit test" << endl;
}

void UtExpirationDate::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        expiration_date->SetValue(valid_value);
        if (expiration_date->GetValue() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtExpirationDate::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            expiration_date->SetValue(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtExpirationDate::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtState::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting state unit test" << endl;
    state = nullptr;
    state = new State();
    if (state != nullptr)
        cout << "State unit test successfully started: Object state created successfully" << endl;
    else
        cout << "Failed to setup state unit test" << endl;
}

void UtState::TearDown() {
    delete state;
    cout << "\nEnd of state unit test" << endl;
}

void UtState::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        state->SetCode(valid_value);
        if (state->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtState::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            state->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtState::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtIdentifier::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting identifier unit test" << endl;
    identifier = nullptr;
    identifier = new Identifier();
    if (identifier != nullptr)
        cout << "Identifier unit test successfully started: Object identifier created successfully" << endl;
    else
        cout << "Failed to setup identifier unit test" << endl;
}

void UtIdentifier::TearDown() {
    delete identifier;
    cout << "\nEnd of identifier unit test" << endl;
}

void UtIdentifier::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        identifier->SetCode(valid_value);
        if (identifier->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtIdentifier::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            identifier->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtIdentifier::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtName::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting name unit test" << endl;
    name = nullptr;
    name = new Name();
    if (name != nullptr)
        cout << "Name unit test successfully started: Object name created successfully" << endl;
    else
        cout << "Failed to setup name unit test" << endl;
}

void UtName::TearDown() {
    delete name;
    cout << "\nEnd of name unit test" << endl;
}

void UtName::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        name->SetCode(valid_value);
        if (name->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtName::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            name->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtName::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtCreditCardNumber::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting credit_card_number unit test" << endl;
    credit_card_number = nullptr;
    credit_card_number = new CreditCardNumber();
    if (credit_card_number != nullptr)
        cout << "CreditCardNumber unit test successfully started: Object credit_card_number created successfully" << endl;
    else
        cout << "Failed to setup credit_card_number unit test" << endl;
}

void UtCreditCardNumber::TearDown() {
    delete credit_card_number;
    cout << "\nEnd of credit_card_number unit test" << endl;
}

void UtCreditCardNumber::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        credit_card_number->SetCode(valid_value);
        if (credit_card_number->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtCreditCardNumber::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            credit_card_number->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtCreditCardNumber::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtCheckingAccount::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting checking_account unit test" << endl;
    checking_account = nullptr;
    checking_account = new CheckingAccountNumber();
    if (checking_account != nullptr)
        cout << "CheckingAccount unit test successfully started: Object checking_account created successfully" << endl;
    else
        cout << "Failed to setup checking_account unit test" << endl;
}

void UtCheckingAccount::TearDown() {
    delete checking_account;
    cout << "\nEnd of checking_account unit test" << endl;
}

void UtCheckingAccount::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        checking_account->SetCode(valid_value);
        if (checking_account->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtCheckingAccount::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            checking_account->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtCheckingAccount::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtPassword::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting password unit test" << endl;
    password = nullptr;
    password = new Password();
    if (password != nullptr)
        cout << "Password unit test successfully started: Object password created successfully" << endl;
    else
        cout << "Failed to setup password unit test" << endl;
}

void UtPassword::TearDown() {
    delete password;
    cout << "\nEnd of password unit test" << endl;
}

void UtPassword::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        password->SetCode(valid_value);
        if (password->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtPassword::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            password->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtPassword::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}

void UtAccommodationType::SetUp() {
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << "Starting accommodation_type unit test" << endl;
    accommodation_type = nullptr;
    accommodation_type = new AccommodationType();
    if (accommodation_type != nullptr)
        cout << "AccommodationType unit test successfully started: Object accommodation_type created successfully" << endl;
    else
        cout << "Failed to setup accommodation_type unit test" << endl;
}

void UtAccommodationType::TearDown() {
    delete accommodation_type;
    cout << "\nEnd of accommodation_type unit test" << endl;
}

void UtAccommodationType::TestSuccessCase() {
    try {
        cout << "\nSetting valid value " << valid_value << " to object attribute..." << endl;
        accommodation_type->SetCode(valid_value);
        if (accommodation_type->GetCode() != valid_value)
            cout << "ERROR: Failed to set valid value -> Different value from inserted" << endl;
        else
            cout << "SUCCESS: Valid value was set successfully" << endl;
    }
    catch(invalid_argument thrown_exception) {
        cout << "ERROR: Failed to set valid value -> Unexpected exception thrown" << endl;
    }
}

void UtAccommodationType::TestFailureCase() {
    for(int i = 0; i < invalid_values.size(); i++){
        try{
            cout << "\nSetting invalid value " << invalid_values.at(i) << " to object attribute..." << endl;
            accommodation_type->SetCode(invalid_values.at(i));
            cout << "ERROR: Successfully set invalid value -> No expected exception was thrown" << endl;
        }
        catch(invalid_argument thrown_exception) {
            cout << "SUCCESS: Invalid value wasn't set" << endl;
        }
    }
}

void UtAccommodationType::Run(){
    SetUp();
    TestSuccessCase();
    TestFailureCase();
    TearDown();
}
