cmake_minimum_required(VERSION 3.16)

project(pubsub)

find_path(HIREDIS_HEADER hiredis)
find_path(REDIS_PLUS_PLUS_HEADER sw)
find_library(HIREDIS_LIB hiredis)
find_library(REDIS_PLUS_PLUS_LIB redis++)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SRC_LIST
    abstractservice-publisher.cpp

    redis/publisher.cpp
    redis/publisherfactory.cpp
)

set(HEADER_LIST
    redis/publisher.h

    ${LIBPUBSUB_HEADERS_DIR}/libpubsub/abstractservice-publisher.h
    ${LIBPUBSUB_HEADERS_DIR}/libpubsub/ichangerequest.h
    ${LIBPUBSUB_HEADERS_DIR}/libpubsub/ipublisher.h
    ${LIBPUBSUB_HEADERS_DIR}/libpubsub/ipublisherfactory.h
    ${LIBPUBSUB_HEADERS_DIR}/libpubsub/redis/publisherfactory.h
)

add_library(${PROJECT_NAME} SHARED ${SRC_LIST} ${HEADER_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${HIREDIS_HEADER})
target_include_directories(${PROJECT_NAME} PUBLIC ${REDIS_PLUS_PLUS_HEADER})
target_include_directories(${PROJECT_NAME} PUBLIC ../include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE ${HIREDIS_LIB}
    PRIVATE ${REDIS_PLUS_PLUS_LIB}
    PRIVATE Threads::Threads
)
