cmake_minimum_required(VERSION 3.12)
project(Architecture)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
        AbstractionComponents
        AbstractionComponents/ControlsFactories/
        ImplementorComponents
        Common)

file(GLOB ABSTRACTION
        AbstractionComponents/*.h
        AbstractionComponents/ControlsFactories/*.h
        AbstractionComponents/ControlsFactories/*.cpp
        AbstractionComponents/ControlsFactories/Controls/*.hpp
        AbstractionComponents/ControlsFactories/Controls/Linux/*.h
        AbstractionComponents/ControlsFactories/Controls/Linux/*.cpp
        AbstractionComponents/ControlsFactories/Controls/Windows/*.h
        AbstractionComponents/ControlsFactories/Controls/Windows/*.cpp
        AbstractionComponents/Abstraction/*.h
        AbstractionComponents/Abstraction/*.cpp
        AbstractionComponents/AbstractionObserver/*.h
        AbstractionComponents/AbstractionObserver/*.cpp
        AbstractionComponents/AbstractionObserver/Subscribers/*.h
        AbstractionComponents/AbstractionObserver/Subscribers/*.cpp
        AbstractionComponents/AbstractionState/*.h
        AbstractionComponents/AbstractionState/*.cpp)

file(GLOB REALIZATION
        ImplementorComponents/*.h
        ImplementorComponents/*.cpp
        ImplementorComponents/Implementor/*.h
        ImplementorComponents/Implementor/*.cpp
        ImplementorComponents/Commands/*.h
        ImplementorComponents/Commands/*.cpp
        ImplementorComponents/ImageFilters/*.h
        ImplementorComponents/ImageFilters/*.hpp
        ImplementorComponents/ImageFilters/*.cpp
        ImplementorComponents/Primitive/*.h
        ImplementorComponents/Primitive/*.hpp
        ImplementorComponents/Primitive/*.cpp
        ImplementorComponents/Primitive/Painter/*.h
        ImplementorComponents/Primitive/Painter/*.cpp
        ImplementorComponents/Primitive/Primitives/*.h
        ImplementorComponents/Primitive/Primitives/*.cpp)

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
