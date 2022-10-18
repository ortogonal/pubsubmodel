#pragma once

#include <set>
#include <variant>

namespace smartpower {

namespace bleservice {

enum class Property { Power, Cadence, TargetPower,  TargetIncline };

using Variant = std::variant<float, bool>;

using BLEServiceChangeSet = std::set<std::pair<Property, Variant>>;

class IBLEService
{
public:
    virtual ~IBLEService() = default;

    // Read only
    virtual float power() const = 0;
    virtual float cadence() const = 0;

    // Read/Write
    virtual float targetPower() const = 0;
    virtual float targetIncline() const = 0;
};

} // namespace bleservice

} // namespace smartpower
