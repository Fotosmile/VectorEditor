//
// Created by Vlad on 09/10/18.
//

#include <stdexcept>

#include "GUIState.h"

void GUIState::select(int, int)
{
    throw std::runtime_error("Operation \"select\" is not allowed in this state");
}

void GUIState::unselect(int, int)
{
    throw std::runtime_error("Operation \"unselect\" is not allowed in this state");
}

void GUIState::move(int, int)
{
    throw std::runtime_error("Operation \"move\" is not allowed in this state");
}

void GUIState::changeSize(int, int)
{
    throw std::runtime_error("Operation \"change size\" is not allowed in this state");
}

void GUIState::group()
{
    throw std::runtime_error("Operation \"group\" is not allowed in this state");
}

void GUIState::changeColor(const Color&)
{
    throw std::runtime_error("Operation \"change color\" is not allowed in this state");
}

void GUIState::deleteSelected()
{
    throw std::runtime_error("Operation \"delete\" is not allowed in this state");
}

void GUIState::create(const std::string&)
{
    throw std::runtime_error("Operation \"createPrimitive\" is not allowed in this state");
}

void GUIState::copy()
{
    throw std::runtime_error("Operation \"copy\" is not allowed in this state");
}