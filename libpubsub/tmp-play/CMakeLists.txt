cmake_minimum_required(VERSION 3.16)

project(tmp-play LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SRC_LIST
    ../tmp-model/bleservicepublisherchangerequest.cpp
    ../tmp-model/bleservice-publisher.cpp
    main.cpp
)

set(HEADER_LIST
    ../tmp-model/bleservicepublisherchangerequest.h
    ../tmp-model/bleservice-publisher.h
    ../tmp-model/ibleservice.h
    ../tmp-model/ibleservicechangerequest.h
    ../tmp-model/ibleservice-subscriber.h
    ../tmp-model/ibleservice-publisher.h
)

add_executable(${PROJECT_NAME}
    ${SRC_LIST}
    ${HEADER_LIST}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE pubsub
)
