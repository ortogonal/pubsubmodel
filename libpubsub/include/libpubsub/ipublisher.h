#pragma once

#include <string>
#include <unordered_map>

namespace pubsub::publisher {

class IPublisher
{
public:
    using PublishSet = std::unordered_map<std::string, std::string>;

    virtual ~IPublisher() = default;

    virtual void setGuid(std::string &guid) = 0;
    virtual bool publishSet(const PublishSet &set) = 0;
};

} // namespace pubsub::publisher
