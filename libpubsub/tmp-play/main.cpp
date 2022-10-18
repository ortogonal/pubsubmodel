#include <iostream>

#include <libpubsub/redis/publisherfactory.h>

#include "../tmp-model/bleservice-publisher.h"
#include "../tmp-model/bleservicepublisherchangerequest.h"

using namespace smartpower;

constexpr const auto guid = "90953d9e-ccae-4a02-b98a-6d671d780012";

int main(int argc, char *argv[])
{
    auto publisherFactory = std::make_unique<pubsub::publisher::redis::PublisherFactory>();
    bleservice::publisher::BLEServicePublisher publisher(std::move(publisherFactory), guid);

    publisher.setChanges(bleservice::publisher::BLEServicePublisherChangeRequest()
                             .setPower(250.f)
                             .setCadence(123.f));
}
