#include "registration.h"
#include "authentication.h"

class UserOptionsController{
public:
    void ShowLogin();
    UserOptionsController();
    ~UserOptionsController();

private:
    UserRegistrationInterface *ur_controller;
    ServiceRegistrationInterface *sr_controller;
    UserAuthenticationInterface *ua_controller;
    ServiceAuthenticationInterface *sa_controller;
    void ShowMainMenu(const Identifier&);

};
