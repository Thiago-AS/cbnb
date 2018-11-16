#ifndef REGISTRATION_H_INCLUDED
#define REGISTRATION_H_INCLUDED

#include "interfaces.h"

// TODO
class ServiceRegistrationController:public ServiceRegistrationInterface{
public:
    bool RegisterUser(const Name&, const Identifier&, const Password&) throw(runtime_error);
};

class UserRegistrationController:public UserRegistrationInterface{
private:
    ServiceRegistrationInterface * sr_controller;
public:
    bool Register() throw(runtime_error);
    void SetController(ServiceRegistrationInterface *);
};

#endif // REGISTRATION_H_INCLUDED
