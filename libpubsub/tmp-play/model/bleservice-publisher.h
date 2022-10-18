#pragma once

#include <libpubsub/abstractservice-publisher.h>

#include "ibleservice-publisher.h"

namespace smartpower {

namespace bleservice::publisher {

class BLEServicePublisher : public IBLEServicePublisher,
                            public pubsub::publisher::AbstractServicePublisher<Property, Variant>
{
public:
    BLEServicePublisher(std::unique_ptr<pubsub::publisher::IPublisherFactory> pubFactory,
                        const std::string &guid);
    float power() const override;
    float cadence() const override;
    float targetPower() const override;
    float targetIncline() const override;

    void setPower(const float &power) override;
    void setCadence(const float &cadence) override;
    void setTargetPower(const float &targetPower) override;
    void setTragetIncline(const float &targetIncline) override;
    void setChanges(const pubsub::IChangeRequest<Property, Variant> &changeRequest) override;

protected:
    std::string propertyName(const Property &property) const override;
    std::string variantStringValue(const Variant &variant) const override;

private:
    float m_power = 0.f;
    float m_cadence = 0.f;
    float m_targetPower = 0.f;
    float m_targetIncline = 0.f;
};

} // namespace bleservice::publisher

} // namespace smartpower
