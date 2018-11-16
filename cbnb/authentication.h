#ifndef AUTHENTICATION_H_INCLUDED
#define AUTHENTICATION_H_INCLUDED

#include "interfaces.h"

class UserAuthenticationController:public UserAuthenticationInterface{
private:
    ServiceAuthenticationController *;
public:
    void Authenticate() throw(runtime_error);
    void SetController(ServiceAuthenticationInterface *);
};

class ServiceAuthenticationController:public ServiceAuthenticationInterface{
public:
    bool Authenticate(const Identifier&, const Password&);
};
#endif // AUTHENTICATION_H_INCLUDED
