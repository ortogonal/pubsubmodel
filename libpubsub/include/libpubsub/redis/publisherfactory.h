#pragma once

#include "../ipublisherfactory.h"

namespace pubsub::publisher::redis {

class PublisherFactory : public IPublisherFactory
{
public:
    std::unique_ptr<IPublisher> create() override;
};

} // namespace pubsub::publisher::redis
