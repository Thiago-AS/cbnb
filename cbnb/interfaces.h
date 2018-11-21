#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "entity.h"
#include "domain.h"

class ServiceRegistrationInterface{
public:
    virtual bool RegisterUser(const Name&, const Identifier&, const Password&) throw(runtime_error) = 0;
    virtual bool RegisterCreditCard(const CreditCardNumber&, const ExpirationDate&, const Identifier &) throw(runtime_error) = 0;
    virtual bool RegisterCheckingAccount(const CheckingAccountNumber&, const Agency&, const Bank&, const Identifier &) throw(runtime_error) = 0;
    virtual bool RegisterAccommodation(const Accommodation&, const Identifier&) throw(runtime_error) = 0;
    virtual bool RegisterAvailability(const Date&, const Date&, const Identifier&) throw(runtime_error) = 0;
    virtual ~ServiceRegistrationInterface(){}
};

class UserRegistrationInterface{
public:
    virtual bool RegisterUser() throw(runtime_error) = 0;
    virtual bool RegisterAccommodation(const Identifier&) throw(runtime_error) = 0;
    virtual bool RegisterAvailability(const Identifier&) throw(runtime_error) = 0;
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
    virtual string Authenticate() throw(runtime_error) = 0;
    virtual void SetController(ServiceAuthenticationInterface *) = 0;
    virtual ~UserAuthenticationInterface(){}
};

class ServiceExclusionInterface{
public:
    virtual bool DeleteAccommodation(const Identifier &) throw(runtime_error) = 0;
    virtual ~ServiceExclusionInterface(){}
};

class UserExclusionInterface{
public:
    virtual bool DeleteAccommodation(const Identifier&) throw(runtime_error) = 0;
    virtual void SetController(ServiceExclusionInterface *) = 0;
    virtual ~UserExclusionInterface(){}
};

class ServiceSeekInterface{
public:
    virtual vector<pair<string, string>> SearchMyAccommodation(const Identifier &) throw(runtime_error) = 0;
    virtual ~ServiceSeekInterface(){}
};

class UserSeekInterface{
public:
    virtual bool SearchMyAccommodation(const Identifier&) throw(runtime_error) = 0;
    virtual void SetController(ServiceSeekInterface *) = 0;
    virtual ~UserSeekInterface(){}
};

#endif // INTERFACES_H_INCLUDED
