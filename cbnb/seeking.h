#ifndef SEEKING_H_INCLUDED
#define SEEKING_H_INCLUDED

#include "interfaces.h"
#include "db.h"

class ServiceSeekController:public ServiceSeekInterface{
public:
    vector<pair<string, string>> SearchMyAccommodation(const Identifier &) throw(runtime_error);
};

class UserSeekController:public UserSeekInterface{
private:
    ServiceSeekInterface * ss_controller;
public:
    bool SearchMyAccommodation(const Identifier&) throw(runtime_error);
    void SetController(ServiceSeekInterface *);
};

#endif // SEEKING_H_INCLUDED
