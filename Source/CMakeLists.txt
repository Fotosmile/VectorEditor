cmake_minimum_required(VERSION 3.12)
project(Architecture)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
        Abstraction
        Abstraction/ControlsFactories/
        Realization
        Common)

file(GLOB ABSTRACTION
        Abstraction/*.h
        Abstraction/ControlsFactories/*.h
        Abstraction/ControlsFactories/*.cpp
        Abstraction/ControlsFactories/Controls/*.hpp
        Abstraction/ControlsFactories/Controls/Linux/*.h
        Abstraction/ControlsFactories/Controls/Linux/*.cpp
        Abstraction/ControlsFactories/Controls/Windows/*.h
        Abstraction/ControlsFactories/Controls/Windows/*.cpp
        Abstraction/GUIMediator/*.h
        Abstraction/GUIMediator/*.cpp
        Abstraction/GUIObserver/*.h
        Abstraction/GUIObserver/*.cpp
        Abstraction/GUIObserver/Subscribers/*.h
        Abstraction/GUIObserver/Subscribers/*.cpp
        Abstraction/GUIState/*.h
        Abstraction/GUIState/*.cpp)

file(GLOB REALIZATION
        Realization/*.h
        Realization/*.cpp
        Realization/Commands/*.h
        Realization/Commands/*.cpp
        Realization/ImageFilters/*.h
        Realization/ImageFilters/*.hpp
        Realization/ImageFilters/*.cpp
        Realization/Primitive/*.h
        Realization/Primitive/*.hpp
        Realization/Primitive/*.cpp
        Realization/Primitive/Painter/*.h
        Realization/Primitive/Painter/*.cpp
        Realization/Primitive/Primitives/*.h
        Realization/Primitive/Primitives/*.cpp)

file(GLOB MOCK
        Mock/*.h
        Mock/*.cpp)

file(GLOB COMMON
        Common/*.h
        Common/*.cpp)

set(SOURCE_FILES
        ${ABSTRACTION}
        ${REALIZATION}
        ${MOCK}
        ${COMMON}
        main.cpp)

add_executable(Architecture ${SOURCE_FILES})
