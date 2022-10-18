#pragma once

#include "ibleservicechangerequest.h"

#include <libpubsub/ichangerequest.h>

namespace smartpower {

namespace bleservice::publisher {

class BLEServicePublisherChangeRequest : public pubsub::IChangeRequest<Property, Variant>/*: public IBLEServiceChangeRequest*/
{
public:
    BLEServicePublisherChangeRequest &setPower(const float &power);
    BLEServicePublisherChangeRequest &setCadence(const float &cadence);
    BLEServicePublisherChangeRequest &setTargetPower(const float &targetPower);
    BLEServicePublisherChangeRequest &setTargetIncline(const float &targetIncline);

    bool valid() final override;
    std::set<std::pair<Property, Variant>> changes() const final override;

private:
    std::set<Property> m_propertiesSet;

    float m_power = 0.f;
    float m_cadence = 0.f;
    float m_targetPower = 0.f;
    float m_targetIncline = 0.f;
};

} // namespace bleservice::publisher

} // namespace smartpower
