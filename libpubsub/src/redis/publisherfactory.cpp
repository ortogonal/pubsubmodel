#include <libpubsub/redis/publisherfactory.h>

#include "publisher.h"

namespace pubsub::publisher::redis {

std::unique_ptr<IPublisher> PublisherFactory::create()
{
    return std::make_unique<Publisher>();
}

} // namespace pubsub::publisher::redis
