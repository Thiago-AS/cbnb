#ifndef REGISTRATION_H_INCLUDED
#define REGISTRATION_H_INCLUDED

#include "interfaces.h"

// TODO
class ServiceRegistrationController:public ServiceRegistrationInterface{
public:
    bool RegisterUser(const Name&, const Identifier&, const Password&) throw(runtime_error);
    bool RegisterCreditCard(const CreditCardNumber&, const ExpirationDate&, const Identifier &) throw(runtime_error);
    bool RegisterCheckingAccount(const CheckingAccountNumber&, const Agency&, const Bank&, const Identifier &) throw(runtime_error);
};

class UserRegistrationController:public UserRegistrationInterface{
private:
    ServiceRegistrationInterface * sr_controller;
public:
    bool Register() throw(runtime_error);
    void SetController(ServiceRegistrationInterface *);
};

#endif // REGISTRATION_H_INCLUDED
