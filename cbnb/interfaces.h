#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "entity.h"
#include "domain.h"

class ServiceRegistrationInterface{
public:
    virtual bool Register(const Name&, const Identifier&, const Password&) throw(runtime_error) = 0;
    virtual ~ServiceRegistrationInterface(){}
};

class UserRegistrationInterface{
public:
    virtual bool Register() throw(runtime_error) = 0;
    virtual void SetController(ServiceRegistrationInterface *) = 0;
    virtual ~UserRegistrationInterface(){}
};

class ServiceAuthenticationInterface {
public:
    virtual bool Authenticate(const Identifier&, const Password&) throw(runtime_error)= 0;
    virtual ~ServiceAuthenticationInterface(){}
};

class UserAuthenticationInterface{
public:
    virtual bool Authenticate() throw(runtime_error) = 0;
    virtual void SetController(ServiceAuthenticationInterface *) = 0;
    virtual ~UserAuthenticationInterface(){}
};

#endif // INTERFACES_H_INCLUDED
