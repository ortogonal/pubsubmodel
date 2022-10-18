#pragma once

#include <memory>

#include "ipublisher.h"

namespace pubsub::publisher {

class IPublisherFactory
{
public:
    virtual ~IPublisherFactory() = default;

    virtual std::unique_ptr<IPublisher> create() = 0;
};

} // namespace pubsub::publisher
