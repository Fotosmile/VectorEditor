//
// Created by Vlad on 09/10/18.
//

#include <stdexcept>

#include "AbstractionState.h"

void AbstractionState::select(int, int)
{
    throw std::runtime_error("Operation \"select\" is not allowed in this state");
}

void AbstractionState::unselect(int, int)
{
    throw std::runtime_error("Operation \"unselect\" is not allowed in this state");
}

void AbstractionState::move(int, int)
{
    throw std::runtime_error("Operation \"move\" is not allowed in this state");
}

void AbstractionState::changeSize(int, int)
{
    throw std::runtime_error("Operation \"change size\" is not allowed in this state");
}

void AbstractionState::group()
{
    throw std::runtime_error("Operation \"group\" is not allowed in this state");
}

void AbstractionState::changeColor(const Color&)
{
    throw std::runtime_error("Operation \"change color\" is not allowed in this state");
}

void AbstractionState::deleteSelected()
{
    throw std::runtime_error("Operation \"delete\" is not allowed in this state");
}

void AbstractionState::create(const std::string&)
{
    throw std::runtime_error("Operation \"createPrimitive\" is not allowed in this state");
}

void AbstractionState::copy()
{
    throw std::runtime_error("Operation \"copy\" is not allowed in this state");
}