#pragma once

#include "ibleservice.h"
#include "ibleservicechangerequest.h"

#include <functional>

namespace smartpower {

namespace bleservice::subscriber {

class IBLEServiceSubscriber : public IBLEService
{
public:
    virtual ~IBLEServiceSubscriber() = default;

    virtual void onPowerChanged(std::function<void>(const float &power)) = 0;
    virtual void onCadenceChanged(std::function<void>(const float &cadence)) = 0;
    virtual void onTargetPowerChanged(std::function<void>(const float &targetPower)) = 0;
    virtual void onTargetInclineChanged(std::function<void>(const float &targetIncline)) = 0;

    virtual void setTargetPower(const float &power) = 0;
    virtual void setTragetIncline(const float &incline) = 0;
    virtual void setChanges(const IBLEServiceChangeRequest &changeRequest) = 0;
};

} // namespace bleservice::subscriber

} // namespace smartpower
