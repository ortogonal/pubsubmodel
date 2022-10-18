#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

#include "ichangerequest.h"
#include "ipublisherfactory.h"

namespace pubsub::publisher {

template<class Property, class Variant>
class AbstractServicePublisher
{
    using ChangeSet = std::set<std::pair<Property, Variant>>;

public:
    AbstractServicePublisher(std::unique_ptr<IPublisherFactory> pubFactory, const std::string &guid)
        : m_publisherFactory(std::move(pubFactory)), m_guid(guid)
    {}

    std::string guid() const { return m_guid; };

protected:
    void publishChanges(const IChangeRequest<Property, Variant> &changeRequest)
    {
        auto changes = changeRequest.changes();

        std::unordered_map<std::string, std::string>  pubSet;

        for (auto it = changes.begin(); it != changes.end(); ++it) {
            auto propName = propertyName((*it).first);
            auto valueStr = variantStringValue((*it).second);

            // TODO: How can we keep the original typs of the value here instead
            //       of converting it to a string?
            //       For redis it's okay, but for other aleternatives it might pose
            //       a problem.
            const auto p = std::make_pair<std::string, std::string>(std::string(propName),
                                                                    std::string(valueStr));
            pubSet.insert(p);

            std::cout << "C: " << propName << " " << valueStr << std::endl;
        }

        if (m_publisherFactory != nullptr) {
            auto publisher = m_publisherFactory->create();
            if (publisher) {
                publisher->setGuid(m_guid);
                publisher->publishSet(pubSet);
            }
        }
    }

    virtual std::string propertyName(const Property &property) const = 0;
    virtual std::string variantStringValue(const Variant &variant) const = 0;

private:
    const std::unique_ptr<IPublisherFactory> m_publisherFactory;

    std::string m_guid;
};

} // namespace pubsub::publisher
