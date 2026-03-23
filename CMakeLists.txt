project(CMemoryMatchingGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(MemoryMatchingGame ${SOURCES})

find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(MemoryMatchingGame Qt5::Widgets)