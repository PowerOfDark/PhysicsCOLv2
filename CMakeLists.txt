cmake_minimum_required(VERSION 3.7)
project(PhysicsCOLv2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Physics/Gravity/Gravity.cpp Physics/Gravity/Gravity.h Physics/Collisions/Collisions.cpp Physics/Collisions/Collisions.h Physics/Move/Move.cpp Physics/Move/Move.h Physics/Entity/Circle.h Physics/Entity/Circle.cpp Physics/Entity/Circle.h Math/Math.cpp Math/Math.h)
add_executable(PhysicsCOLv2 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PhysicsCOLv2 ${SFML_LIBRARIES})
endif()
