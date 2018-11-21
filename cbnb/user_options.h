#include "registration.h"
#include "authentication.h"
#include "exclusion.h"

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
    UserExclusionInterface *ue_controller;
    ServiceExclusionInterface *se_controller;

    void ShowMainMenu(const Identifier&);
    void ShowAccommodationMenu(const Identifier&);
    void ShowAvailabilitiesMenu(const Identifier&);
    void ShowReservationMenu(const Identifier&);
    void ShowAccountSettingsMenu(const Identifier&);
};
