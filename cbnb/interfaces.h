#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "entity.h"
#include "domain.h"

class UserAuthenticationInterface{
public:
    virtual bool Authenticate() throw(runtime_error) = 0;
    virtual void SetController(ServiceAuthenticationInterface *) = 0;
    virtual ~UserAuthenticationInterface(){}
};

class ServiceAuthenticationInterface {
public:
    virtual bool Authenticate(const Identifier&, const Password&) throw(runtime_error)= 0;
    virtual ~ServiceAuthenticationInterface(){}
};

#endif // INTERFACES_H_INCLUDED
