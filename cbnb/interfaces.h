#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "entity.h"
#include "domain.h"

class AuthenticationUserInterface{
public:
    virtual bool Authenticate() throw(runtime_error) = 0;
    virtual void SetController(AuthenticationServiceInterface *) = 0;
    virtual ~AuthenticationUserInterface(){}
};

class AuthenticationServiceInterface {
public:
    virtual bool Authenticate(const Identifier&, const Password&) throw(runtime_error)= 0;
    virtual ~ILNAutenticacao(){}
};

#endif // INTERFACES_H_INCLUDED
