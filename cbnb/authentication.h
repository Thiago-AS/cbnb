#ifndef AUTHENTICATION_H_INCLUDED
#define AUTHENTICATION_H_INCLUDED

#include "interfaces.h"

class ServiceAuthenticationController:public ServiceAuthenticationInterface{
public:
    bool Authenticate(const Identifier&, const Password&) throw(runtime_error);
};

class UserAuthenticationController:public UserAuthenticationInterface{
private:
    ServiceAuthenticationInterface * sa_controller;
public:
    bool Authenticate() throw(runtime_error);
    void SetController(ServiceAuthenticationInterface *);
};
#endif // AUTHENTICATION_H_INCLUDED
