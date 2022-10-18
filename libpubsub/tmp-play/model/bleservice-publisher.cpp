#include "bleservice-publisher.h"

#include "bleservicepublisherchangerequest.h"

#include <string>

namespace smartpower {

namespace bleservice::publisher {

template<class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

BLEServicePublisher::BLEServicePublisher(
    std::unique_ptr<pubsub::publisher::IPublisherFactory> pubFactory, const std::string &guid)
    : pubsub::publisher::AbstractServicePublisher<Property, Variant>(std::move(pubFactory), guid)
{}

float BLEServicePublisher::power() const
{
    return m_power;
}

float BLEServicePublisher::cadence() const
{
    return m_cadence;
}

float BLEServicePublisher::targetPower() const
{
    return m_targetPower;
}

float BLEServicePublisher::targetIncline() const
{
    return m_targetIncline;
}

void BLEServicePublisher::setPower(const float &power)
{
    setChanges(BLEServicePublisherChangeRequest().setPower(power));
}

void BLEServicePublisher::setCadence(const float &cadence)
{
    setChanges(BLEServicePublisherChangeRequest().setCadence(cadence));
}

void BLEServicePublisher::setTargetPower(const float &targetPower)
{
    setChanges(BLEServicePublisherChangeRequest().setTargetPower(targetPower));
}

void BLEServicePublisher::setTragetIncline(const float &targetIncline)
{
    setChanges(BLEServicePublisherChangeRequest().setTargetIncline(targetIncline));
}

void BLEServicePublisher::setChanges(const pubsub::IChangeRequest<Property, Variant> &changeRequest)
{
    publishChanges(changeRequest);
}

std::string BLEServicePublisher::propertyName(const Property &property) const
{
    switch (property) {
    case Property::Cadence:
        return "cadence";
    case Property::Power:
        return "power";
    case Property::TargetPower:
        return "targetpower";
    case Property::TargetIncline:
        return "targetincline";
    }

    return "";
}

std::string BLEServicePublisher::variantStringValue(const Variant &variant) const
{
    std::string str;

    // TODO: How do we know if all types are generatable? Also how can we handle more
    //       complex types?
    std::visit(overloaded{
                   [&](float arg) { str = std::to_string(arg); },
                   [&](bool arg) { str = arg ? "true" : "false"; },
                   [&](auto arg) { std::cerr << " Hmm" << std::endl; },
               },
               variant);

    return str;
}

} // namespace bleservice::publisher

} // namespace smartpower
