#pragma once

#include <string>

#include <libpubsub/ipublisher.h>

namespace pubsub::publisher::redis {

class Publisher : public IPublisher
{
public:
    Publisher();

    void setGuid(std::string &guid) override;
    bool publishSet(const PublishSet &set) override;

private:
    std::string m_guid;
};

} // namespace pubsub::publisher::redis
