cmake_minimum_required(VERSION 3.16)

project(tmp-play LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(PROJECT_SOURCES
    main.cpp
)

set(SRC_LIST
    model/bleservicepublisherchangerequest.cpp
    model/bleservice-publisher.cpp
    main.cpp
)

set(HEADER_LIST
    model/bleservicepublisherchangerequest.h
    model/bleservice-publisher.h
    model/ibleservice.h
    model/ibleservicechangerequest.h
    model/ibleservice-subscriber.h
    model/ibleservice-publisher.h
)

add_executable(${PROJECT_NAME}
    ${SRC_LIST}
    ${HEADER_LIST}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE pubsub
)
