#include "publisher.h"

#include <iostream>
#include <sw/redis++/redis++.h>

namespace pubsub::publisher::redis {

Publisher::Publisher() {}

void Publisher::setGuid(std::string &guid)
{
    m_guid = guid;
}

bool Publisher::publishSet(const PublishSet &set)
{
    auto map = set;
    std::string fieldChanges;

    for (auto it = set.cbegin(); it != set.cend(); ++it) {
        if (!fieldChanges.empty()) {
            fieldChanges += ",";
        }
        fieldChanges += (*it).first;
    }

    map.insert({"lastFieldChanges", fieldChanges});
    map.insert({"lastChanger", m_guid});

    try {
        auto redis = sw::redis::Redis("tcp://127.0.0.1:6379");

        redis.hmset("bleservice", map.begin(), map.end());
    } catch (const sw::redis::Error &error) {

    }

    for (auto it = map.cbegin(); it != map.cend(); ++it) {
        std::cout << "P: " << (*it).first << " : " << (*it).second << std::endl;
    }

    return false;
}

} // namespace pubsub::publisher::redis
