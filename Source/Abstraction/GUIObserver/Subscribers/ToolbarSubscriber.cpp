//
// Created by Vlad on 09/10/18.
//

#include <iostream>

#include "ToolbarSubscriber.h"
#include "GUIState/GUIState.h"

void ToolbarSubscriber::update(GUIState::StateType stateType)
{
    if (stateType == GUIState::StateType::Creating)
    {
        std::cout << "Now your toolbar is in creating state" << std::endl;
    }
    else if (stateType == GUIState::StateType::Editing)
    {
        std::cout << "Now your toolbar is in editing state" << std::endl;
    }
}