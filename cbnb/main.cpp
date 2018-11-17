#include <iostream>
#include "domain.h"
#include "tests_domain.h"
#include "entity.h"
#include "registration.h"
#include "authentication.h"

int main() {
    UserAuthenticationInterface *test = new UserAuthenticationController();
    ServiceAuthenticationInterface *service_test = new ServiceAuthenticationController();

    test->SetController(service_test);

    cout << test->Authenticate();


    return 0;
}
