#include <iostream>
#include "domain.h"
#include "tests_domain.h"
#include "entity.h"
#include "registration.h"
#include "authentication.h"

int main() {
    UserRegistrationInterface *test = new UserRegistrationController();
    ServiceRegistrationInterface *service_test = new ServiceRegistrationController();

    test->SetController(service_test);

    cout << test->RegisterUser();


    return 0;
}
