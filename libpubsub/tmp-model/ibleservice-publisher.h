#pragma once

#include "ibleservice.h"
#include "ibleservicechangerequest.h"

#include <libpubsub/ichangerequest.h>

#include <functional>

namespace smartpower {

namespace bleservice::publisher {

class IBLEServicePublisher : public IBLEService
{
public:
    virtual ~IBLEServicePublisher() = default;

    virtual void setPower(const float &power) = 0;
    virtual void setCadence(const float &power) = 0;
    virtual void setTargetPower(const float &power) = 0;
    virtual void setTragetIncline(const float &incline) = 0;
    virtual void setChanges(const pubsub::IChangeRequest<Property, Variant> &changeRequest) = 0;

    // TODO
    //virtual void onTargetPowerChanged(std::function<void>(const float &targetPower)) = 0;
    //virtual void onTargetInclineChanged(std::function<void>(const float &targetIncline)) = 0;
};

} // namespace bleservice::publisher

} // namespace smartpower
