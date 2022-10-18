cmake_minimum_required(VERSION 3.16)

project(pubsub)

set(CMAKE_CXX_STANDARD 17)
set(LIBPUBSUB_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(tmp-play)

