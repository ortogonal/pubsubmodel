#pragma once

#include <set>

namespace pubsub {

template<class Property, class Variant>
class IChangeRequest
{
public:
    virtual ~IChangeRequest() = default;

    virtual bool valid() = 0;
    virtual std::set<std::pair<Property, Variant>> changes() const = 0;
};

} // namespace pubsub::publisher
