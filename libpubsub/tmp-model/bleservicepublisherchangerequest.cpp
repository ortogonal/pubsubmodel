#include "bleservicepublisherchangerequest.h"

#include "ibleservice.h"

namespace smartpower {

namespace bleservice::publisher {

BLEServicePublisherChangeRequest &BLEServicePublisherChangeRequest::setPower(const float &power)
{
    m_propertiesSet.insert(Property::Power);
    m_power = power;
    return *this;
}

BLEServicePublisherChangeRequest &BLEServicePublisherChangeRequest::setCadence(const float &cadence)
{
    m_propertiesSet.insert(Property::Cadence);
    m_cadence = cadence;
    return *this;
}

BLEServicePublisherChangeRequest &BLEServicePublisherChangeRequest::setTargetPower(
    const float &targetPower)
{
    m_propertiesSet.insert(Property::TargetPower);
    m_targetPower = targetPower;
    return *this;
}

BLEServicePublisherChangeRequest &BLEServicePublisherChangeRequest::setTargetIncline(
    const float &targetIncline)
{
    m_propertiesSet.insert(Property::TargetIncline);
    m_targetIncline = targetIncline;
    return *this;
}

bool BLEServicePublisherChangeRequest::valid()
{
    // TODO!
    return true;
}

std::set<std::pair<Property, Variant>> BLEServicePublisherChangeRequest::changes() const
{
    std::set<std::pair<Property, Variant>> changeSet;

    if (m_propertiesSet.find(Property::Power) != m_propertiesSet.end()) {
        changeSet.insert(std::make_pair<Property, Variant>(Property::Power, m_power));
    }

    if (m_propertiesSet.find(Property::Cadence) != m_propertiesSet.end()) {
        changeSet.insert(std::make_pair<Property, Variant>(Property::Cadence, m_cadence));
    }

    if (m_propertiesSet.find(Property::TargetPower) != m_propertiesSet.end()) {
        changeSet.insert(std::make_pair<Property, Variant>(Property::TargetPower, m_targetPower));
    }

    if (m_propertiesSet.find(Property::TargetIncline) != m_propertiesSet.end()) {
        changeSet.insert(
            std::make_pair<Property, Variant>(Property::TargetIncline, m_targetIncline));
    }

    return changeSet;
}

} // namespace bleservice::publisher

} // namespace smartpower
