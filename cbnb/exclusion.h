#ifndef EXCLUSION_H_INCLUDED
#define EXCLUSION_H_INCLUDED

#include "interfaces.h"
#include "db.h"

class ServiceExeclusionController:public ServiceExclusionInterface{
public:
    bool DeleteAccommodation(const Identifier &) throw(runtime_error);
};

class UserExclusionController:public UserExclusionInterface{
private:
    ServiceExclusionInterface * se_controller;
public:
    bool DeleteAccommodation(const Identifier &) throw(runtime_error);
    void SetController(ServiceExclusionInterface *);
};
#endif
